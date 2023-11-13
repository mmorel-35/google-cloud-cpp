// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "generator/internal/stub_generator.h"
#include "generator/internal/codegen_utils.h"
#include "generator/internal/descriptor_utils.h"
#include "generator/internal/longrunning.h"
#include "generator/internal/predicate_utils.h"
#include "generator/internal/printer.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "absl/strings/str_split.h"
#include <google/protobuf/descriptor.h>

namespace google {
namespace cloud {
namespace generator_internal {

StubGenerator::StubGenerator(
    google::protobuf::ServiceDescriptor const* service_descriptor,
    VarsDictionary service_vars,
    std::map<std::string, VarsDictionary> service_method_vars,
    google::protobuf::compiler::GeneratorContext* context)
    : ServiceCodeGenerator("stub_header_path", "stub_cc_path",
                           service_descriptor, std::move(service_vars),
                           std::move(service_method_vars), context) {}

Status StubGenerator::GenerateHeader() {
  HeaderPrint(CopyrightLicenseFileHeader());
  HeaderPrint(  // clang-format off
    "\n"
    "// Generated by the Codegen C++ plugin.\n"
    "// If you make any local changes, they will be lost.\n"
    "// source: $proto_file_name$\n"
    "\n"
    "#ifndef $header_include_guard$\n"
    "#define $header_include_guard$\n");
  // clang-format on

  // includes
  HeaderPrint("\n");
  auto const needs_completion_queue =
      HasAsyncMethod() || HasBidirStreamingMethod();
  auto const needs_options = HasLongrunningMethod() || HasStreamingReadMethod();
  HeaderLocalIncludes(
      {HasBidirStreamingMethod()
           ? "google/cloud/async_streaming_read_write_rpc.h"
           : "",
       needs_completion_queue ? "google/cloud/completion_queue.h" : "",
       HasAsyncMethod() ? "google/cloud/future.h" : "",
       HasAsynchronousStreamingReadMethod()
           ? "google/cloud/internal/async_streaming_read_rpc.h"
           : "",
       HasAsynchronousStreamingWriteMethod()
           ? "google/cloud/internal/async_streaming_write_rpc.h"
           : "",
       HasStreamingReadMethod() ? "google/cloud/internal/streaming_read_rpc.h"
                                : "",
       HasStreamingWriteMethod() ? "google/cloud/internal/streaming_write_rpc.h"
                                 : "",
       needs_options ? "google/cloud/options.h" : "",
       "google/cloud/status_or.h", "google/cloud/version.h"});
  std::vector<std::string> additional_pb_header_paths =
      absl::StrSplit(vars("additional_pb_header_paths"), absl::ByChar(','));
  HeaderSystemIncludes(additional_pb_header_paths);
  HeaderSystemIncludes(
      {vars("proto_grpc_header_path"),
       HasLongrunningMethod() ? "google/longrunning/operations.grpc.pb.h" : "",
       "memory"});

  auto result = HeaderOpenNamespaces(NamespaceType::kInternal);
  if (!result.ok()) return result;

  // Abstract interface Stub base class
  HeaderPrint(  // clang-format off
    "\n"
    "class $stub_class_name$ {\n"
    " public:\n"
    "  virtual ~$stub_class_name$() = 0;\n");
  // clang-format on

  for (auto const& method : methods()) {
    if (IsStreamingWrite(method)) {
      HeaderPrintMethod(method, __FILE__, __LINE__,
                        R"""(
  virtual std::unique_ptr<::google::cloud::internal::StreamingWriteRpc<
      $request_type$,
      $response_type$>>
  $method_name$(
      std::shared_ptr<grpc::ClientContext> context) = 0;
)""");
      continue;
    }
    if (IsBidirStreaming(method)) {
      HeaderPrintMethod(method, __FILE__, __LINE__,
                        R"""(
  virtual std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
      $request_type$,
      $response_type$>>
  Async$method_name$(
      google::cloud::CompletionQueue const& cq,
      std::shared_ptr<grpc::ClientContext> context) = 0;
)""");
      continue;
    }
    if (IsLongrunningOperation(method)) {
      HeaderPrintMethod(method, __FILE__, __LINE__, R"""(
  virtual future<StatusOr<google::longrunning::Operation>> Async$method_name$(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      Options const& options,
      $request_type$ const& request) = 0;
)""");
      continue;
    }
    if (IsStreamingRead(method)) {
      HeaderPrintMethod(method, __FILE__, __LINE__, R"""(
  virtual std::unique_ptr<google::cloud::internal::StreamingReadRpc<$response_type$>>
  $method_name$(
    std::shared_ptr<grpc::ClientContext> context,
    Options const& options,
    $request_type$ const& request) = 0;
)""");
      continue;
    }
    HeaderPrintMethod(
        method,
        {MethodPattern(
            {{IsResponseTypeEmpty,
              // clang-format off
    "\n  virtual Status $method_name$(\n",
    "\n  virtual StatusOr<$response_type$> $method_name$(\n"},
   {"    grpc::ClientContext& context,\n"
    "    $request_type$ const& request) = 0;\n"
                 // clang-format on
             }},
            And(IsNonStreaming, Not(IsLongrunningOperation)))},
        __FILE__, __LINE__);
  }

  for (auto const& method : async_methods()) {
    if (IsStreamingRead(method)) {
      auto constexpr kDeclaration = R"""(
  virtual std::unique_ptr<::google::cloud::internal::AsyncStreamingReadRpc<
      $response_type$>>
  Async$method_name$(
      google::cloud::CompletionQueue const& cq,
      std::shared_ptr<grpc::ClientContext> context,
      $request_type$ const& request) = 0;
)""";
      HeaderPrintMethod(method, __FILE__, __LINE__, kDeclaration);
      continue;
    }
    if (IsStreamingWrite(method)) {
      auto constexpr kDeclaration = R"""(
  virtual std::unique_ptr<::google::cloud::internal::AsyncStreamingWriteRpc<
      $request_type$, $response_type$>>
  Async$method_name$(
      google::cloud::CompletionQueue const& cq,
      std::shared_ptr<grpc::ClientContext> context) = 0;
)""";
      HeaderPrintMethod(method, __FILE__, __LINE__, kDeclaration);
      continue;
    }
    HeaderPrintMethod(
        method,
        {
            MethodPattern({{IsResponseTypeEmpty,
                            // clang-format off
    "\n  virtual future<Status>",
    "\n  virtual future<StatusOr<$response_type$>>"},
                           // clang-format on
                           {R"""(
  Async$method_name$(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    $request_type$ const& request) = 0;
)"""}},
                          And(IsNonStreaming, Not(IsLongrunningOperation))),
        },
        __FILE__, __LINE__);
  }

  // long running operation support methods
  if (HasLongrunningMethod()) {
    HeaderPrint(
        R"""(
  virtual future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      Options const& options,
      google::longrunning::GetOperationRequest const& request) = 0;

  virtual future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      Options const& options,
      google::longrunning::CancelOperationRequest const& request) = 0;
)""");
  }
  // close abstract interface Stub base class
  HeaderPrint("};\n");

  // default stub class
  HeaderPrint(  // clang-format off
    "\n"
    "class Default$stub_class_name$ : public $stub_class_name$ {\n"
    " public:");
  if (HasLongrunningMethod()) {
    HeaderPrint(  // clang-format off
    "\n"
    "  Default$stub_class_name$(\n"
    "      std::unique_ptr<$grpc_stub_fqn$::StubInterface> grpc_stub,\n"
    "      std::unique_ptr<google::longrunning::Operations::StubInterface> "
    "operations)\n"
    "      : grpc_stub_(std::move(grpc_stub)),\n"
    "        operations_(std::move(operations)) {}\n");
    // clang-format on
  } else {
    HeaderPrint(  // clang-format off
    "\n"
    "  explicit Default$stub_class_name$(\n"
    "      std::unique_ptr<$grpc_stub_fqn$::StubInterface> grpc_stub)\n"
    "      : grpc_stub_(std::move(grpc_stub)) {}\n");
    // clang-format on
  }

  for (auto const& method : methods()) {
    // emit methods
    if (IsStreamingWrite(method)) {
      HeaderPrintMethod(method, __FILE__, __LINE__,
                        R"""(
  std::unique_ptr<::google::cloud::internal::StreamingWriteRpc<
      $request_type$,
      $response_type$>>
  $method_name$(
      std::shared_ptr<grpc::ClientContext> context) override;
)""");
      continue;
    }
    if (IsBidirStreaming(method)) {
      HeaderPrintMethod(method, __FILE__, __LINE__,
                        R"""(
  std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
      $request_type$,
      $response_type$>>
  Async$method_name$(
      google::cloud::CompletionQueue const& cq,
      std::shared_ptr<grpc::ClientContext> context) override;
)""");
      continue;
    }
    if (IsLongrunningOperation(method)) {
      HeaderPrintMethod(method, __FILE__, __LINE__, R"""(
  future<StatusOr<google::longrunning::Operation>> Async$method_name$(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      Options const& options,
      $request_type$ const& request) override;
)""");
      continue;
    }
    if (IsStreamingRead(method)) {
      HeaderPrintMethod(method, __FILE__, __LINE__, R"""(
  std::unique_ptr<google::cloud::internal::StreamingReadRpc<$response_type$>>
  $method_name$(
    std::shared_ptr<grpc::ClientContext> client_context,
    Options const& options,
    $request_type$ const& request) override;
)""");
      continue;
    }
    HeaderPrintMethod(
        method,
        {MethodPattern({{IsResponseTypeEmpty,
                         // clang-format off
    "\n  Status\n",
    "\n  StatusOr<$response_type$>\n"},
    {"  $method_name$(\n"
    "    grpc::ClientContext& client_context,\n"
    "    $request_type$ const& request) override;\n"}},
                       // clang-format on
                       And(IsNonStreaming, Not(IsLongrunningOperation)))},
        __FILE__, __LINE__);
  }

  for (auto const& method : async_methods()) {
    if (IsStreamingRead(method)) {
      auto constexpr kDeclaration = R"""(
  std::unique_ptr<::google::cloud::internal::AsyncStreamingReadRpc<
      $response_type$>>
  Async$method_name$(
      google::cloud::CompletionQueue const& cq,
      std::shared_ptr<grpc::ClientContext> context,
      $request_type$ const& request) override;
)""";
      HeaderPrintMethod(method, __FILE__, __LINE__, kDeclaration);
      continue;
    }
    if (IsStreamingWrite(method)) {
      auto constexpr kDeclaration = R"""(
  std::unique_ptr<::google::cloud::internal::AsyncStreamingWriteRpc<
      $request_type$, $response_type$>>
  Async$method_name$(
      google::cloud::CompletionQueue const& cq,
      std::shared_ptr<grpc::ClientContext> context) override;
)""";
      HeaderPrintMethod(method, __FILE__, __LINE__, kDeclaration);
      continue;
    }
    HeaderPrintMethod(
        method,
        {
            MethodPattern(
                {{IsResponseTypeEmpty,
                  // clang-format off
    "\n  future<Status>\n",
    "\n  future<StatusOr<$response_type$>>\n"},
   {"  Async$method_name$(\n"
    "    google::cloud::CompletionQueue& cq,\n"
    "    std::shared_ptr<grpc::ClientContext> context,\n"
    "    $request_type$ const& request) override;\n"
                     // clang-format on
                 }},
                And(IsNonStreaming, Not(IsLongrunningOperation))),
        },
        __FILE__, __LINE__);
  }

  if (HasLongrunningMethod()) {
    // long running operation support methods
    HeaderPrint(
        R"""(
  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      Options const& options,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      Options const& options,
      google::longrunning::CancelOperationRequest const& request) override;
)""");
  }

  // private members and close default stub class definition
  HeaderPrint(  // clang-format off
    "\n"
    " private:\n"
    "  std::unique_ptr<$grpc_stub_fqn$::StubInterface> grpc_stub_;\n"
  );
  if (HasLongrunningMethod()) {
    HeaderPrint(  // clang-format off
    "  std::unique_ptr<google::longrunning::Operations::StubInterface> operations_;\n");
    // clang-format on
  }
  HeaderPrint("};\n");

  HeaderCloseNamespaces();
  // close header guard
  HeaderPrint("\n#endif  // $header_include_guard$\n");
  return {};
}

Status StubGenerator::GenerateCc() {
  CcPrint(CopyrightLicenseFileHeader());
  CcPrint(  // clang-format off
    "\n"
    "// Generated by the Codegen C++ plugin.\n"
    "// If you make any local changes, they will be lost.\n"
    "// source: $proto_file_name$\n");
  // clang-format on

  // includes
  CcPrint("\n");
  CcLocalIncludes(
      {vars("stub_header_path"),
       HasBidirStreamingMethod()
           ? "google/cloud/internal/async_read_write_stream_impl.h"
           : "",
       HasAsynchronousStreamingReadMethod()
           ? "google/cloud/internal/async_streaming_read_rpc_impl.h"
           : "",
       HasAsynchronousStreamingWriteMethod()
           ? "google/cloud/internal/async_streaming_write_rpc_impl.h"
           : "",
       HasStreamingWriteMethod()
           ? "google/cloud/internal/streaming_write_rpc_impl.h"
           : "",
       "google/cloud/grpc_error_delegate.h", "google/cloud/status_or.h"});
  CcSystemIncludes(
      {vars("proto_grpc_header_path"),
       HasLongrunningMethod() ? "google/longrunning/operations.grpc.pb.h" : "",
       "memory"});

  auto result = CcOpenNamespaces(NamespaceType::kInternal);
  if (!result.ok()) return result;

  CcPrint(  // clang-format off
    "\n"
    "$stub_class_name$::~$stub_class_name$() = default;\n");
  // clang-format on

  // default stub class member methods
  for (auto const& method : methods()) {
    if (IsStreamingWrite(method)) {
      CcPrintMethod(method, __FILE__, __LINE__,
                    R"""(
std::unique_ptr<::google::cloud::internal::StreamingWriteRpc<
    $request_type$,
    $response_type$>>
Default$stub_class_name$::$method_name$(
    std::shared_ptr<grpc::ClientContext> context) {
  auto response = std::make_unique<$response_type$>();
  auto stream = grpc_stub_->$method_name$(context.get(), response.get());
  return std::make_unique<::google::cloud::internal::StreamingWriteRpcImpl<
      $request_type$, $response_type$>>(
    std::move(context), std::move(response), std::move(stream));
}
)""");
      continue;
    }
    if (IsBidirStreaming(method)) {
      CcPrintMethod(method, __FILE__, __LINE__,
                    R"""(
std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    $request_type$,
    $response_type$>>
Default$stub_class_name$::Async$method_name$(
    google::cloud::CompletionQueue const& cq,
    std::shared_ptr<grpc::ClientContext> context) {
  return google::cloud::internal::MakeStreamingReadWriteRpc<$request_type$, $response_type$>(
      cq, std::move(context),
      [this](grpc::ClientContext* context, grpc::CompletionQueue* cq) {
        return grpc_stub_->PrepareAsync$method_name$(context, cq);
      });
}
)""");
      continue;
    }
    if (IsLongrunningOperation(method)) {
      CcPrintMethod(method, __FILE__, __LINE__, R"""(
future<StatusOr<google::longrunning::Operation>>
Default$stub_class_name$::Async$method_name$(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      Options const&,
      $request_type$ const& request) {
  return internal::MakeUnaryRpcImpl<$request_type$,
                                    google::longrunning::Operation>(
      cq,
      [this](grpc::ClientContext* context,
             $request_type$ const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->Async$method_name$(context, request, cq);
      },
      request, std::move(context));
}
)""");
      continue;
    }
    if (IsStreamingRead(method)) {
      CcPrintMethod(method, __FILE__, __LINE__, R"""(
std::unique_ptr<google::cloud::internal::StreamingReadRpc<$response_type$>>
Default$stub_class_name$::$method_name$(
    std::shared_ptr<grpc::ClientContext> client_context,
    Options const&,
    $request_type$ const& request) {
  auto stream = grpc_stub_->$method_name$(client_context.get(), request);
  return std::make_unique<google::cloud::internal::StreamingReadRpcImpl<
      $response_type$>>(
      std::move(client_context), std::move(stream));
}
)""");
      continue;
    }
    CcPrintMethod(
        method,
        {MethodPattern(
            {{IsResponseTypeEmpty,
              // clang-format off
    "\nStatus\n",
    "\nStatusOr<$response_type$>\n"},
    {"Default$stub_class_name$::$method_name$(\n"
    "  grpc::ClientContext& client_context,\n"
    "  $request_type$ const& request) {\n"
    "    $response_type$ response;\n"
    "    auto status =\n"
    "        grpc_stub_->$method_name$(&client_context, request, &response);\n"
    "    if (!status.ok()) {\n"
    "      return google::cloud::MakeStatusFromRpcError(status);\n"
    "    }\n"},
   {IsResponseTypeEmpty,
    "    return google::cloud::Status();\n",
    "    return response;\n"},
   {"}\n"}},
            // clang-format on
            And(IsNonStreaming, Not(IsLongrunningOperation)))},
        __FILE__, __LINE__);
  }

  for (auto const& method : async_methods()) {
    if (IsStreamingRead(method)) {
      auto constexpr kDefinition = R"""(
std::unique_ptr<::google::cloud::internal::AsyncStreamingReadRpc<
    $response_type$>>
Default$stub_class_name$::Async$method_name$(
    google::cloud::CompletionQueue const& cq,
    std::shared_ptr<grpc::ClientContext> context,
    $request_type$ const& request) {
  return google::cloud::internal::MakeStreamingReadRpc<$request_type$, $response_type$>(
    cq, std::move(context), request,
    [this](grpc::ClientContext* context, $request_type$ const& request, grpc::CompletionQueue* cq) {
      return grpc_stub_->PrepareAsync$method_name$(context, request, cq);
    });
}
)""";
      CcPrintMethod(method, __FILE__, __LINE__, kDefinition);
      continue;
    }
    if (IsStreamingWrite(method)) {
      auto constexpr kDefinition = R"""(
std::unique_ptr<::google::cloud::internal::AsyncStreamingWriteRpc<
    $request_type$, $response_type$>>
Default$stub_class_name$::Async$method_name$(
    google::cloud::CompletionQueue const& cq,
    std::shared_ptr<grpc::ClientContext> context) {
  return google::cloud::internal::MakeStreamingWriteRpc<$request_type$, $response_type$>(
    cq, std::move(context),
    [this](grpc::ClientContext* context, $response_type$* response, grpc::CompletionQueue* cq) {
      return grpc_stub_->PrepareAsync$method_name$(context, response, cq);
    });
}
)""";
      CcPrintMethod(method, __FILE__, __LINE__, kDefinition);
      continue;
    }
    CcPrintMethod(
        method,
        {MethodPattern(
            {{IsResponseTypeEmpty,
              // clang-format off
                      "\nfuture<Status>",
                      "\nfuture<StatusOr<$response_type$>>"},
             // clang-format on
             {
                 R"""(
Default$stub_class_name$::Async$method_name$(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    $request_type$ const& request) {
  return internal::MakeUnaryRpcImpl<$request_type$,
                                    $response_type$>(
      cq,
      [this](grpc::ClientContext* context,
             $request_type$ const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->Async$method_name$(context, request, cq);
      },
      request, std::move(context)))"""},
             {IsResponseTypeEmpty, R"""(
      .then([](future<StatusOr<google::protobuf::Empty>> f) {
        return f.get().status();
      }))""",
              ""},
             {";\n}\n"}},
            And(IsNonStreaming, Not(IsLongrunningOperation)))},
        __FILE__, __LINE__);
  }

  if (HasLongrunningMethod()) {
    CcPrint(R"""(
future<StatusOr<google::longrunning::Operation>>
Default$stub_class_name$::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    Options const&,
    google::longrunning::GetOperationRequest const& request) {
  return internal::MakeUnaryRpcImpl<google::longrunning::GetOperationRequest,
                                    google::longrunning::Operation>(
      cq,
      [this](grpc::ClientContext* context,
             google::longrunning::GetOperationRequest const& request,
             grpc::CompletionQueue* cq) {
        return operations_->AsyncGetOperation(context, request, cq);
      },
      request, std::move(context));
}

future<Status> Default$stub_class_name$::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    Options const&,
    google::longrunning::CancelOperationRequest const& request) {
  return internal::MakeUnaryRpcImpl<google::longrunning::CancelOperationRequest,
                                    google::protobuf::Empty>(
      cq,
      [this](grpc::ClientContext* context,
             google::longrunning::CancelOperationRequest const& request,
             grpc::CompletionQueue* cq) {
        return operations_->AsyncCancelOperation(context, request, cq);
      },
      request, std::move(context))
      .then([](future<StatusOr<google::protobuf::Empty>> f) {
        return f.get().status();
      });
}
)""");
  }

  CcCloseNamespaces();
  return {};
}

}  // namespace generator_internal
}  // namespace cloud
}  // namespace google

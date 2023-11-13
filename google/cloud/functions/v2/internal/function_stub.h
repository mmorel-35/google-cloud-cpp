// Copyright 2023 Google LLC
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

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/functions/v2/functions.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_FUNCTIONS_V2_INTERNAL_FUNCTION_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_FUNCTIONS_V2_INTERNAL_FUNCTION_STUB_H

#include "google/cloud/completion_queue.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/functions/v2/functions.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace functions_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class FunctionServiceStub {
 public:
  virtual ~FunctionServiceStub() = 0;

  virtual StatusOr<google::cloud::functions::v2::Function> GetFunction(
      grpc::ClientContext& context,
      google::cloud::functions::v2::GetFunctionRequest const& request) = 0;

  virtual StatusOr<google::cloud::functions::v2::ListFunctionsResponse>
  ListFunctions(
      grpc::ClientContext& context,
      google::cloud::functions::v2::ListFunctionsRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncCreateFunction(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::functions::v2::CreateFunctionRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncUpdateFunction(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::functions::v2::UpdateFunctionRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncDeleteFunction(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::functions::v2::DeleteFunctionRequest const& request) = 0;

  virtual StatusOr<google::cloud::functions::v2::GenerateUploadUrlResponse>
  GenerateUploadUrl(
      grpc::ClientContext& context,
      google::cloud::functions::v2::GenerateUploadUrlRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::functions::v2::GenerateDownloadUrlResponse>
  GenerateDownloadUrl(
      grpc::ClientContext& context,
      google::cloud::functions::v2::GenerateDownloadUrlRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::functions::v2::ListRuntimesResponse>
  ListRuntimes(
      grpc::ClientContext& context,
      google::cloud::functions::v2::ListRuntimesRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::GetOperationRequest const& request) = 0;

  virtual future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::CancelOperationRequest const& request) = 0;
};

class DefaultFunctionServiceStub : public FunctionServiceStub {
 public:
  DefaultFunctionServiceStub(
      std::unique_ptr<
          google::cloud::functions::v2::FunctionService::StubInterface>
          grpc_stub,
      std::unique_ptr<google::longrunning::Operations::StubInterface>
          operations)
      : grpc_stub_(std::move(grpc_stub)), operations_(std::move(operations)) {}

  StatusOr<google::cloud::functions::v2::Function> GetFunction(
      grpc::ClientContext& client_context,
      google::cloud::functions::v2::GetFunctionRequest const& request) override;

  StatusOr<google::cloud::functions::v2::ListFunctionsResponse> ListFunctions(
      grpc::ClientContext& client_context,
      google::cloud::functions::v2::ListFunctionsRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateFunction(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::functions::v2::CreateFunctionRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateFunction(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::functions::v2::UpdateFunctionRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteFunction(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::functions::v2::DeleteFunctionRequest const& request)
      override;

  StatusOr<google::cloud::functions::v2::GenerateUploadUrlResponse>
  GenerateUploadUrl(
      grpc::ClientContext& client_context,
      google::cloud::functions::v2::GenerateUploadUrlRequest const& request)
      override;

  StatusOr<google::cloud::functions::v2::GenerateDownloadUrlResponse>
  GenerateDownloadUrl(
      grpc::ClientContext& client_context,
      google::cloud::functions::v2::GenerateDownloadUrlRequest const& request)
      override;

  StatusOr<google::cloud::functions::v2::ListRuntimesResponse> ListRuntimes(
      grpc::ClientContext& client_context,
      google::cloud::functions::v2::ListRuntimesRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::unique_ptr<google::cloud::functions::v2::FunctionService::StubInterface>
      grpc_stub_;
  std::unique_ptr<google::longrunning::Operations::StubInterface> operations_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace functions_v2_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_FUNCTIONS_V2_INTERNAL_FUNCTION_STUB_H

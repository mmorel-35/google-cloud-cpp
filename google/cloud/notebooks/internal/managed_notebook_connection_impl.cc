// Copyright 2022 Google LLC
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
// source: google/cloud/notebooks/v1/managed_service.proto

#include "google/cloud/notebooks/internal/managed_notebook_connection_impl.h"
#include "google/cloud/notebooks/internal/managed_notebook_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace notebooks_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ManagedNotebookServiceConnectionImpl::ManagedNotebookServiceConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<notebooks_internal::ManagedNotebookServiceStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options),
          notebooks_internal::ManagedNotebookServiceDefaultOptions(
              ManagedNotebookServiceConnection::options()))) {}

StreamRange<google::cloud::notebooks::v1::Runtime>
ManagedNotebookServiceConnectionImpl::ListRuntimes(
    google::cloud::notebooks::v1::ListRuntimesRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry =
      std::shared_ptr<notebooks::ManagedNotebookServiceRetryPolicy const>(
          retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListRuntimes(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::notebooks::v1::Runtime>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::notebooks::v1::ListRuntimesRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::notebooks::v1::ListRuntimesRequest const&
                       request) {
              return stub->ListRuntimes(context, request);
            },
            r, function_name);
      },
      [](google::cloud::notebooks::v1::ListRuntimesResponse r) {
        std::vector<google::cloud::notebooks::v1::Runtime> result(
            r.runtimes().size());
        auto& messages = *r.mutable_runtimes();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::notebooks::v1::Runtime>
ManagedNotebookServiceConnectionImpl::GetRuntime(
    google::cloud::notebooks::v1::GetRuntimeRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetRuntime(request),
      [this](grpc::ClientContext& context,
             google::cloud::notebooks::v1::GetRuntimeRequest const& request) {
        return stub_->GetRuntime(context, request);
      },
      request, __func__);
}

future<StatusOr<google::cloud::notebooks::v1::Runtime>>
ManagedNotebookServiceConnectionImpl::CreateRuntime(
    google::cloud::notebooks::v1::CreateRuntimeRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::notebooks::v1::Runtime>(
      background_->cq(), request,
      [stub](
          google::cloud::CompletionQueue& cq,
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::notebooks::v1::CreateRuntimeRequest const& request) {
        return stub->AsyncCreateRuntime(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::notebooks::v1::Runtime>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateRuntime(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::notebooks::v1::OperationMetadata>>
ManagedNotebookServiceConnectionImpl::DeleteRuntime(
    google::cloud::notebooks::v1::DeleteRuntimeRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::notebooks::v1::OperationMetadata>(
      background_->cq(), request,
      [stub](
          google::cloud::CompletionQueue& cq,
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::notebooks::v1::DeleteRuntimeRequest const& request) {
        return stub->AsyncDeleteRuntime(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultMetadata<
          google::cloud::notebooks::v1::OperationMetadata>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteRuntime(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::notebooks::v1::Runtime>>
ManagedNotebookServiceConnectionImpl::StartRuntime(
    google::cloud::notebooks::v1::StartRuntimeRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::notebooks::v1::Runtime>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::notebooks::v1::StartRuntimeRequest const& request) {
        return stub->AsyncStartRuntime(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::notebooks::v1::Runtime>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->StartRuntime(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::notebooks::v1::Runtime>>
ManagedNotebookServiceConnectionImpl::StopRuntime(
    google::cloud::notebooks::v1::StopRuntimeRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::notebooks::v1::Runtime>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::notebooks::v1::StopRuntimeRequest const& request) {
        return stub->AsyncStopRuntime(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::notebooks::v1::Runtime>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->StopRuntime(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::notebooks::v1::Runtime>>
ManagedNotebookServiceConnectionImpl::SwitchRuntime(
    google::cloud::notebooks::v1::SwitchRuntimeRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::notebooks::v1::Runtime>(
      background_->cq(), request,
      [stub](
          google::cloud::CompletionQueue& cq,
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::notebooks::v1::SwitchRuntimeRequest const& request) {
        return stub->AsyncSwitchRuntime(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::notebooks::v1::Runtime>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->SwitchRuntime(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::notebooks::v1::Runtime>>
ManagedNotebookServiceConnectionImpl::ResetRuntime(
    google::cloud::notebooks::v1::ResetRuntimeRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::notebooks::v1::Runtime>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::notebooks::v1::ResetRuntimeRequest const& request) {
        return stub->AsyncResetRuntime(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::notebooks::v1::Runtime>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->ResetRuntime(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::notebooks::v1::Runtime>>
ManagedNotebookServiceConnectionImpl::ReportRuntimeEvent(
    google::cloud::notebooks::v1::ReportRuntimeEventRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::notebooks::v1::Runtime>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::notebooks::v1::ReportRuntimeEventRequest const&
                 request) {
        return stub->AsyncReportRuntimeEvent(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::notebooks::v1::Runtime>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->ReportRuntimeEvent(request), polling_policy(),
      __func__);
}

StatusOr<google::cloud::notebooks::v1::RefreshRuntimeTokenInternalResponse>
ManagedNotebookServiceConnectionImpl::RefreshRuntimeTokenInternal(
    google::cloud::notebooks::v1::RefreshRuntimeTokenInternalRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->RefreshRuntimeTokenInternal(request),
      [this](grpc::ClientContext& context,
             google::cloud::notebooks::v1::
                 RefreshRuntimeTokenInternalRequest const& request) {
        return stub_->RefreshRuntimeTokenInternal(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace notebooks_internal
}  // namespace cloud
}  // namespace google

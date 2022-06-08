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
// source: google/cloud/accessapproval/v1/accessapproval.proto

#include "google/cloud/accessapproval/internal/access_approval_connection_impl.h"
#include "google/cloud/accessapproval/internal/access_approval_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace accessapproval_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

AccessApprovalConnectionImpl::AccessApprovalConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<accessapproval_internal::AccessApprovalStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options),
          accessapproval_internal::AccessApprovalDefaultOptions(
              AccessApprovalConnection::options()))) {}

StreamRange<google::cloud::accessapproval::v1::ApprovalRequest>
AccessApprovalConnectionImpl::ListApprovalRequests(
    google::cloud::accessapproval::v1::ListApprovalRequestsMessage request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry = std::shared_ptr<accessapproval::AccessApprovalRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListApprovalRequests(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::accessapproval::v1::ApprovalRequest>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::accessapproval::v1::ListApprovalRequestsMessage const&
              r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::accessapproval::v1::
                       ListApprovalRequestsMessage const& request) {
              return stub->ListApprovalRequests(context, request);
            },
            r, function_name);
      },
      [](google::cloud::accessapproval::v1::ListApprovalRequestsResponse r) {
        std::vector<google::cloud::accessapproval::v1::ApprovalRequest> result(
            r.approval_requests().size());
        auto& messages = *r.mutable_approval_requests();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::accessapproval::v1::ApprovalRequest>
AccessApprovalConnectionImpl::GetApprovalRequest(
    google::cloud::accessapproval::v1::GetApprovalRequestMessage const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetApprovalRequest(request),
      [this](grpc::ClientContext& context,
             google::cloud::accessapproval::v1::GetApprovalRequestMessage const&
                 request) {
        return stub_->GetApprovalRequest(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::accessapproval::v1::ApprovalRequest>
AccessApprovalConnectionImpl::ApproveApprovalRequest(
    google::cloud::accessapproval::v1::ApproveApprovalRequestMessage const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->ApproveApprovalRequest(request),
      [this](grpc::ClientContext& context,
             google::cloud::accessapproval::v1::
                 ApproveApprovalRequestMessage const& request) {
        return stub_->ApproveApprovalRequest(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::accessapproval::v1::ApprovalRequest>
AccessApprovalConnectionImpl::DismissApprovalRequest(
    google::cloud::accessapproval::v1::DismissApprovalRequestMessage const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DismissApprovalRequest(request),
      [this](grpc::ClientContext& context,
             google::cloud::accessapproval::v1::
                 DismissApprovalRequestMessage const& request) {
        return stub_->DismissApprovalRequest(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::accessapproval::v1::ApprovalRequest>
AccessApprovalConnectionImpl::InvalidateApprovalRequest(
    google::cloud::accessapproval::v1::InvalidateApprovalRequestMessage const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->InvalidateApprovalRequest(request),
      [this](grpc::ClientContext& context,
             google::cloud::accessapproval::v1::
                 InvalidateApprovalRequestMessage const& request) {
        return stub_->InvalidateApprovalRequest(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::accessapproval::v1::AccessApprovalSettings>
AccessApprovalConnectionImpl::GetAccessApprovalSettings(
    google::cloud::accessapproval::v1::GetAccessApprovalSettingsMessage const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetAccessApprovalSettings(request),
      [this](grpc::ClientContext& context,
             google::cloud::accessapproval::v1::
                 GetAccessApprovalSettingsMessage const& request) {
        return stub_->GetAccessApprovalSettings(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::accessapproval::v1::AccessApprovalSettings>
AccessApprovalConnectionImpl::UpdateAccessApprovalSettings(
    google::cloud::accessapproval::v1::
        UpdateAccessApprovalSettingsMessage const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateAccessApprovalSettings(request),
      [this](grpc::ClientContext& context,
             google::cloud::accessapproval::v1::
                 UpdateAccessApprovalSettingsMessage const& request) {
        return stub_->UpdateAccessApprovalSettings(context, request);
      },
      request, __func__);
}

Status AccessApprovalConnectionImpl::DeleteAccessApprovalSettings(
    google::cloud::accessapproval::v1::
        DeleteAccessApprovalSettingsMessage const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteAccessApprovalSettings(request),
      [this](grpc::ClientContext& context,
             google::cloud::accessapproval::v1::
                 DeleteAccessApprovalSettingsMessage const& request) {
        return stub_->DeleteAccessApprovalSettings(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::accessapproval::v1::AccessApprovalServiceAccount>
AccessApprovalConnectionImpl::GetAccessApprovalServiceAccount(
    google::cloud::accessapproval::v1::
        GetAccessApprovalServiceAccountMessage const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetAccessApprovalServiceAccount(request),
      [this](grpc::ClientContext& context,
             google::cloud::accessapproval::v1::
                 GetAccessApprovalServiceAccountMessage const& request) {
        return stub_->GetAccessApprovalServiceAccount(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace accessapproval_internal
}  // namespace cloud
}  // namespace google

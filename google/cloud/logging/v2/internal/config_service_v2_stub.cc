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
// source: google/logging/v2/logging_config.proto

#include "google/cloud/logging/v2/internal/config_service_v2_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/logging/v2/logging_config.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace logging_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ConfigServiceV2Stub::~ConfigServiceV2Stub() = default;

StatusOr<google::logging::v2::ListBucketsResponse>
DefaultConfigServiceV2Stub::ListBuckets(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::ListBucketsRequest const& request) {
  google::logging::v2::ListBucketsResponse response;
  auto status = grpc_stub_->ListBuckets(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::LogBucket> DefaultConfigServiceV2Stub::GetBucket(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::GetBucketRequest const& request) {
  google::logging::v2::LogBucket response;
  auto status = grpc_stub_->GetBucket(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultConfigServiceV2Stub::AsyncCreateBucketAsync(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions,
    google::logging::v2::CreateBucketRequest const& request) {
  return internal::MakeUnaryRpcImpl<google::logging::v2::CreateBucketRequest,
                                    google::longrunning::Operation>(
      cq,
      [this](grpc::ClientContext* context,
             google::logging::v2::CreateBucketRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCreateBucketAsync(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultConfigServiceV2Stub::AsyncUpdateBucketAsync(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions,
    google::logging::v2::UpdateBucketRequest const& request) {
  return internal::MakeUnaryRpcImpl<google::logging::v2::UpdateBucketRequest,
                                    google::longrunning::Operation>(
      cq,
      [this](grpc::ClientContext* context,
             google::logging::v2::UpdateBucketRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncUpdateBucketAsync(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::logging::v2::LogBucket>
DefaultConfigServiceV2Stub::CreateBucket(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::CreateBucketRequest const& request) {
  google::logging::v2::LogBucket response;
  auto status = grpc_stub_->CreateBucket(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::LogBucket>
DefaultConfigServiceV2Stub::UpdateBucket(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::UpdateBucketRequest const& request) {
  google::logging::v2::LogBucket response;
  auto status = grpc_stub_->UpdateBucket(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

Status DefaultConfigServiceV2Stub::DeleteBucket(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::DeleteBucketRequest const& request) {
  google::protobuf::Empty response;
  auto status = grpc_stub_->DeleteBucket(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

Status DefaultConfigServiceV2Stub::UndeleteBucket(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::UndeleteBucketRequest const& request) {
  google::protobuf::Empty response;
  auto status = grpc_stub_->UndeleteBucket(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

StatusOr<google::logging::v2::ListViewsResponse>
DefaultConfigServiceV2Stub::ListViews(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::ListViewsRequest const& request) {
  google::logging::v2::ListViewsResponse response;
  auto status = grpc_stub_->ListViews(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::LogView> DefaultConfigServiceV2Stub::GetView(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::GetViewRequest const& request) {
  google::logging::v2::LogView response;
  auto status = grpc_stub_->GetView(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::LogView> DefaultConfigServiceV2Stub::CreateView(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::CreateViewRequest const& request) {
  google::logging::v2::LogView response;
  auto status = grpc_stub_->CreateView(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::LogView> DefaultConfigServiceV2Stub::UpdateView(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::UpdateViewRequest const& request) {
  google::logging::v2::LogView response;
  auto status = grpc_stub_->UpdateView(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

Status DefaultConfigServiceV2Stub::DeleteView(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::DeleteViewRequest const& request) {
  google::protobuf::Empty response;
  auto status = grpc_stub_->DeleteView(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

StatusOr<google::logging::v2::ListSinksResponse>
DefaultConfigServiceV2Stub::ListSinks(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::ListSinksRequest const& request) {
  google::logging::v2::ListSinksResponse response;
  auto status = grpc_stub_->ListSinks(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::LogSink> DefaultConfigServiceV2Stub::GetSink(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::GetSinkRequest const& request) {
  google::logging::v2::LogSink response;
  auto status = grpc_stub_->GetSink(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::LogSink> DefaultConfigServiceV2Stub::CreateSink(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::CreateSinkRequest const& request) {
  google::logging::v2::LogSink response;
  auto status = grpc_stub_->CreateSink(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::LogSink> DefaultConfigServiceV2Stub::UpdateSink(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::UpdateSinkRequest const& request) {
  google::logging::v2::LogSink response;
  auto status = grpc_stub_->UpdateSink(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

Status DefaultConfigServiceV2Stub::DeleteSink(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::DeleteSinkRequest const& request) {
  google::protobuf::Empty response;
  auto status = grpc_stub_->DeleteSink(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

future<StatusOr<google::longrunning::Operation>>
DefaultConfigServiceV2Stub::AsyncCreateLink(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions,
    google::logging::v2::CreateLinkRequest const& request) {
  return internal::MakeUnaryRpcImpl<google::logging::v2::CreateLinkRequest,
                                    google::longrunning::Operation>(
      cq,
      [this](grpc::ClientContext* context,
             google::logging::v2::CreateLinkRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCreateLink(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultConfigServiceV2Stub::AsyncDeleteLink(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions,
    google::logging::v2::DeleteLinkRequest const& request) {
  return internal::MakeUnaryRpcImpl<google::logging::v2::DeleteLinkRequest,
                                    google::longrunning::Operation>(
      cq,
      [this](grpc::ClientContext* context,
             google::logging::v2::DeleteLinkRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncDeleteLink(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::logging::v2::ListLinksResponse>
DefaultConfigServiceV2Stub::ListLinks(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::ListLinksRequest const& request) {
  google::logging::v2::ListLinksResponse response;
  auto status = grpc_stub_->ListLinks(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::Link> DefaultConfigServiceV2Stub::GetLink(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::GetLinkRequest const& request) {
  google::logging::v2::Link response;
  auto status = grpc_stub_->GetLink(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::ListExclusionsResponse>
DefaultConfigServiceV2Stub::ListExclusions(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::ListExclusionsRequest const& request) {
  google::logging::v2::ListExclusionsResponse response;
  auto status = grpc_stub_->ListExclusions(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::LogExclusion>
DefaultConfigServiceV2Stub::GetExclusion(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::GetExclusionRequest const& request) {
  google::logging::v2::LogExclusion response;
  auto status = grpc_stub_->GetExclusion(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::LogExclusion>
DefaultConfigServiceV2Stub::CreateExclusion(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::CreateExclusionRequest const& request) {
  google::logging::v2::LogExclusion response;
  auto status = grpc_stub_->CreateExclusion(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::LogExclusion>
DefaultConfigServiceV2Stub::UpdateExclusion(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::UpdateExclusionRequest const& request) {
  google::logging::v2::LogExclusion response;
  auto status = grpc_stub_->UpdateExclusion(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

Status DefaultConfigServiceV2Stub::DeleteExclusion(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::DeleteExclusionRequest const& request) {
  google::protobuf::Empty response;
  auto status = grpc_stub_->DeleteExclusion(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

StatusOr<google::logging::v2::CmekSettings>
DefaultConfigServiceV2Stub::GetCmekSettings(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::GetCmekSettingsRequest const& request) {
  google::logging::v2::CmekSettings response;
  auto status = grpc_stub_->GetCmekSettings(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::CmekSettings>
DefaultConfigServiceV2Stub::UpdateCmekSettings(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::UpdateCmekSettingsRequest const& request) {
  google::logging::v2::CmekSettings response;
  auto status = grpc_stub_->UpdateCmekSettings(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::Settings> DefaultConfigServiceV2Stub::GetSettings(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::GetSettingsRequest const& request) {
  google::logging::v2::Settings response;
  auto status = grpc_stub_->GetSettings(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::logging::v2::Settings>
DefaultConfigServiceV2Stub::UpdateSettings(
    grpc::ClientContext& context, Options const&,
    google::logging::v2::UpdateSettingsRequest const& request) {
  google::logging::v2::Settings response;
  auto status = grpc_stub_->UpdateSettings(&context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultConfigServiceV2Stub::AsyncCopyLogEntries(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions,
    google::logging::v2::CopyLogEntriesRequest const& request) {
  return internal::MakeUnaryRpcImpl<google::logging::v2::CopyLogEntriesRequest,
                                    google::longrunning::Operation>(
      cq,
      [this](grpc::ClientContext* context,
             google::logging::v2::CopyLogEntriesRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCopyLogEntries(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultConfigServiceV2Stub::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    // NOLINTNEXTLINE(performance-unnecessary-value-param)
    google::cloud::internal::ImmutableOptions,
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

future<Status> DefaultConfigServiceV2Stub::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    // NOLINTNEXTLINE(performance-unnecessary-value-param)
    google::cloud::internal::ImmutableOptions,
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

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace logging_v2_internal
}  // namespace cloud
}  // namespace google

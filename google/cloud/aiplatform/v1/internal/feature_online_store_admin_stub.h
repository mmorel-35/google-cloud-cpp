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
// source: google/cloud/aiplatform/v1/feature_online_store_admin_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AIPLATFORM_V1_INTERNAL_FEATURE_ONLINE_STORE_ADMIN_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AIPLATFORM_V1_INTERNAL_FEATURE_ONLINE_STORE_ADMIN_STUB_H

#include "google/cloud/completion_queue.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/aiplatform/v1/feature_online_store_admin_service.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace aiplatform_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class FeatureOnlineStoreAdminServiceStub {
 public:
  virtual ~FeatureOnlineStoreAdminServiceStub() = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncCreateFeatureOnlineStore(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::CreateFeatureOnlineStoreRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::aiplatform::v1::FeatureOnlineStore>
  GetFeatureOnlineStore(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::GetFeatureOnlineStoreRequest const&
          request) = 0;

  virtual StatusOr<
      google::cloud::aiplatform::v1::ListFeatureOnlineStoresResponse>
  ListFeatureOnlineStores(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::ListFeatureOnlineStoresRequest const&
          request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncUpdateFeatureOnlineStore(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::UpdateFeatureOnlineStoreRequest const&
          request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncDeleteFeatureOnlineStore(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::DeleteFeatureOnlineStoreRequest const&
          request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncCreateFeatureView(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::CreateFeatureViewRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::aiplatform::v1::FeatureView> GetFeatureView(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::GetFeatureViewRequest const& request) = 0;

  virtual StatusOr<google::cloud::aiplatform::v1::ListFeatureViewsResponse>
  ListFeatureViews(grpc::ClientContext& context, Options const& options,
                   google::cloud::aiplatform::v1::ListFeatureViewsRequest const&
                       request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncUpdateFeatureView(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::UpdateFeatureViewRequest const&
          request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncDeleteFeatureView(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::DeleteFeatureViewRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::aiplatform::v1::SyncFeatureViewResponse>
  SyncFeatureView(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::SyncFeatureViewRequest const& request) = 0;

  virtual StatusOr<google::cloud::aiplatform::v1::FeatureViewSync>
  GetFeatureViewSync(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::GetFeatureViewSyncRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::aiplatform::v1::ListFeatureViewSyncsResponse>
  ListFeatureViewSyncs(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::ListFeatureViewSyncsRequest const&
          request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::longrunning::GetOperationRequest const& request) = 0;

  virtual future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::longrunning::CancelOperationRequest const& request) = 0;
};

class DefaultFeatureOnlineStoreAdminServiceStub
    : public FeatureOnlineStoreAdminServiceStub {
 public:
  DefaultFeatureOnlineStoreAdminServiceStub(
      std::unique_ptr<google::cloud::aiplatform::v1::
                          FeatureOnlineStoreAdminService::StubInterface>
          grpc_stub,
      std::unique_ptr<google::longrunning::Operations::StubInterface>
          operations)
      : grpc_stub_(std::move(grpc_stub)), operations_(std::move(operations)) {}

  future<StatusOr<google::longrunning::Operation>>
  AsyncCreateFeatureOnlineStore(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::CreateFeatureOnlineStoreRequest const&
          request) override;

  StatusOr<google::cloud::aiplatform::v1::FeatureOnlineStore>
  GetFeatureOnlineStore(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::GetFeatureOnlineStoreRequest const&
          request) override;

  StatusOr<google::cloud::aiplatform::v1::ListFeatureOnlineStoresResponse>
  ListFeatureOnlineStores(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::ListFeatureOnlineStoresRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncUpdateFeatureOnlineStore(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::UpdateFeatureOnlineStoreRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncDeleteFeatureOnlineStore(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::DeleteFeatureOnlineStoreRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateFeatureView(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::CreateFeatureViewRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::FeatureView> GetFeatureView(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::GetFeatureViewRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::ListFeatureViewsResponse>
  ListFeatureViews(grpc::ClientContext& context, Options const& options,
                   google::cloud::aiplatform::v1::ListFeatureViewsRequest const&
                       request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateFeatureView(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::UpdateFeatureViewRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteFeatureView(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::aiplatform::v1::DeleteFeatureViewRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::SyncFeatureViewResponse>
  SyncFeatureView(grpc::ClientContext& context, Options const& options,
                  google::cloud::aiplatform::v1::SyncFeatureViewRequest const&
                      request) override;

  StatusOr<google::cloud::aiplatform::v1::FeatureViewSync> GetFeatureViewSync(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::GetFeatureViewSyncRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::ListFeatureViewSyncsResponse>
  ListFeatureViewSyncs(
      grpc::ClientContext& context, Options const& options,
      google::cloud::aiplatform::v1::ListFeatureViewSyncsRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::unique_ptr<google::cloud::aiplatform::v1::
                      FeatureOnlineStoreAdminService::StubInterface>
      grpc_stub_;
  std::unique_ptr<google::longrunning::Operations::StubInterface> operations_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AIPLATFORM_V1_INTERNAL_FEATURE_ONLINE_STORE_ADMIN_STUB_H

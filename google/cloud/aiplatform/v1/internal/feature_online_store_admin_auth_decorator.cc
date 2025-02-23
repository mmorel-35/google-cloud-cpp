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

#include "google/cloud/aiplatform/v1/internal/feature_online_store_admin_auth_decorator.h"
#include <google/cloud/aiplatform/v1/feature_online_store_admin_service.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace aiplatform_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

FeatureOnlineStoreAdminServiceAuth::FeatureOnlineStoreAdminServiceAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<FeatureOnlineStoreAdminServiceStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

future<StatusOr<google::longrunning::Operation>>
FeatureOnlineStoreAdminServiceAuth::AsyncCreateFeatureOnlineStore(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::CreateFeatureOnlineStoreRequest const&
        request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child = child_, options = std::move(options),
             request](future<StatusOr<std::shared_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateFeatureOnlineStore(
            cq, *std::move(context), std::move(options), request);
      });
}

StatusOr<google::cloud::aiplatform::v1::FeatureOnlineStore>
FeatureOnlineStoreAdminServiceAuth::GetFeatureOnlineStore(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetFeatureOnlineStoreRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetFeatureOnlineStore(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::ListFeatureOnlineStoresResponse>
FeatureOnlineStoreAdminServiceAuth::ListFeatureOnlineStores(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListFeatureOnlineStoresRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListFeatureOnlineStores(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeatureOnlineStoreAdminServiceAuth::AsyncUpdateFeatureOnlineStore(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::UpdateFeatureOnlineStoreRequest const&
        request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child = child_, options = std::move(options),
             request](future<StatusOr<std::shared_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncUpdateFeatureOnlineStore(
            cq, *std::move(context), std::move(options), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
FeatureOnlineStoreAdminServiceAuth::AsyncDeleteFeatureOnlineStore(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::DeleteFeatureOnlineStoreRequest const&
        request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child = child_, options = std::move(options),
             request](future<StatusOr<std::shared_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncDeleteFeatureOnlineStore(
            cq, *std::move(context), std::move(options), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
FeatureOnlineStoreAdminServiceAuth::AsyncCreateFeatureView(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::CreateFeatureViewRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child = child_, options = std::move(options),
             request](future<StatusOr<std::shared_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateFeatureView(cq, *std::move(context),
                                             std::move(options), request);
      });
}

StatusOr<google::cloud::aiplatform::v1::FeatureView>
FeatureOnlineStoreAdminServiceAuth::GetFeatureView(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetFeatureViewRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetFeatureView(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::ListFeatureViewsResponse>
FeatureOnlineStoreAdminServiceAuth::ListFeatureViews(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListFeatureViewsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListFeatureViews(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeatureOnlineStoreAdminServiceAuth::AsyncUpdateFeatureView(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::UpdateFeatureViewRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child = child_, options = std::move(options),
             request](future<StatusOr<std::shared_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncUpdateFeatureView(cq, *std::move(context),
                                             std::move(options), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
FeatureOnlineStoreAdminServiceAuth::AsyncDeleteFeatureView(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::DeleteFeatureViewRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child = child_, options = std::move(options),
             request](future<StatusOr<std::shared_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncDeleteFeatureView(cq, *std::move(context),
                                             std::move(options), request);
      });
}

StatusOr<google::cloud::aiplatform::v1::SyncFeatureViewResponse>
FeatureOnlineStoreAdminServiceAuth::SyncFeatureView(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::SyncFeatureViewRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->SyncFeatureView(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::FeatureViewSync>
FeatureOnlineStoreAdminServiceAuth::GetFeatureViewSync(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetFeatureViewSyncRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetFeatureViewSync(context, options, request);
}

StatusOr<google::cloud::aiplatform::v1::ListFeatureViewSyncsResponse>
FeatureOnlineStoreAdminServiceAuth::ListFeatureViewSyncs(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListFeatureViewSyncsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListFeatureViewSyncs(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
FeatureOnlineStoreAdminServiceAuth::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::GetOperationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child = child_, options = std::move(options),
             request](future<StatusOr<std::shared_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncGetOperation(cq, *std::move(context),
                                        std::move(options), request);
      });
}

future<Status> FeatureOnlineStoreAdminServiceAuth::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::CancelOperationRequest const& request) {
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child = child_, options = std::move(options),
             request](future<StatusOr<std::shared_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) return make_ready_future(std::move(context).status());
        return child->AsyncCancelOperation(cq, *std::move(context),
                                           std::move(options), request);
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1_internal
}  // namespace cloud
}  // namespace google

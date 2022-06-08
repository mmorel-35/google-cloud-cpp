// Copyright 2021 Google LLC
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
// source: google/cloud/pubsublite/v1/admin.proto

#include "google/cloud/pubsublite/internal/admin_auth_decorator.h"
#include <google/cloud/pubsublite/v1/admin.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace pubsublite_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

AdminServiceAuth::AdminServiceAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<AdminServiceStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::pubsublite::v1::Topic> AdminServiceAuth::CreateTopic(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::CreateTopicRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateTopic(context, request);
}

StatusOr<google::cloud::pubsublite::v1::Topic> AdminServiceAuth::GetTopic(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::GetTopicRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetTopic(context, request);
}

StatusOr<google::cloud::pubsublite::v1::TopicPartitions>
AdminServiceAuth::GetTopicPartitions(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::GetTopicPartitionsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetTopicPartitions(context, request);
}

StatusOr<google::cloud::pubsublite::v1::ListTopicsResponse>
AdminServiceAuth::ListTopics(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::ListTopicsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListTopics(context, request);
}

StatusOr<google::cloud::pubsublite::v1::Topic> AdminServiceAuth::UpdateTopic(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::UpdateTopicRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateTopic(context, request);
}

Status AdminServiceAuth::DeleteTopic(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::DeleteTopicRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteTopic(context, request);
}

StatusOr<google::cloud::pubsublite::v1::ListTopicSubscriptionsResponse>
AdminServiceAuth::ListTopicSubscriptions(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::ListTopicSubscriptionsRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListTopicSubscriptions(context, request);
}

StatusOr<google::cloud::pubsublite::v1::Subscription>
AdminServiceAuth::CreateSubscription(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::CreateSubscriptionRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateSubscription(context, request);
}

StatusOr<google::cloud::pubsublite::v1::Subscription>
AdminServiceAuth::GetSubscription(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::GetSubscriptionRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetSubscription(context, request);
}

StatusOr<google::cloud::pubsublite::v1::ListSubscriptionsResponse>
AdminServiceAuth::ListSubscriptions(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::ListSubscriptionsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListSubscriptions(context, request);
}

StatusOr<google::cloud::pubsublite::v1::Subscription>
AdminServiceAuth::UpdateSubscription(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::UpdateSubscriptionRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateSubscription(context, request);
}

Status AdminServiceAuth::DeleteSubscription(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::DeleteSubscriptionRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteSubscription(context, request);
}

future<StatusOr<google::longrunning::Operation>>
AdminServiceAuth::AsyncSeekSubscription(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::pubsublite::v1::SeekSubscriptionRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncSeekSubscription(cq, *std::move(context), request);
      });
}

StatusOr<google::cloud::pubsublite::v1::Reservation>
AdminServiceAuth::CreateReservation(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::CreateReservationRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateReservation(context, request);
}

StatusOr<google::cloud::pubsublite::v1::Reservation>
AdminServiceAuth::GetReservation(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::GetReservationRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetReservation(context, request);
}

StatusOr<google::cloud::pubsublite::v1::ListReservationsResponse>
AdminServiceAuth::ListReservations(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::ListReservationsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListReservations(context, request);
}

StatusOr<google::cloud::pubsublite::v1::Reservation>
AdminServiceAuth::UpdateReservation(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::UpdateReservationRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateReservation(context, request);
}

Status AdminServiceAuth::DeleteReservation(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::DeleteReservationRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteReservation(context, request);
}

StatusOr<google::cloud::pubsublite::v1::ListReservationTopicsResponse>
AdminServiceAuth::ListReservationTopics(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::ListReservationTopicsRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListReservationTopics(context, request);
}

future<StatusOr<google::cloud::pubsublite::v1::TopicPartitions>>
AdminServiceAuth::AsyncGetTopicPartitions(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::pubsublite::v1::GetTopicPartitionsRequest const& request) {
  using ReturnType = StatusOr<google::cloud::pubsublite::v1::TopicPartitions>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncGetTopicPartitions(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
AdminServiceAuth::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncGetOperation(cq, *std::move(context), request);
      });
}

future<Status> AdminServiceAuth::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) return make_ready_future(std::move(context).status());
        return child->AsyncCancelOperation(cq, *std::move(context), request);
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsublite_internal
}  // namespace cloud
}  // namespace google

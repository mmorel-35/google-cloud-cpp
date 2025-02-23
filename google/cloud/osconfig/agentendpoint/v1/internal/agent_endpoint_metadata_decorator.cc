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
// source: google/cloud/osconfig/agentendpoint/v1/agentendpoint.proto

#include "google/cloud/osconfig/agentendpoint/v1/internal/agent_endpoint_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/osconfig/agentendpoint/v1/agentendpoint.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace osconfig_agentendpoint_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

AgentEndpointServiceMetadata::AgentEndpointServiceMetadata(
    std::shared_ptr<AgentEndpointServiceStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<
    google::cloud::osconfig::agentendpoint::v1::
        ReceiveTaskNotificationResponse>>
AgentEndpointServiceMetadata::ReceiveTaskNotification(
    std::shared_ptr<grpc::ClientContext> context, Options const& options,
    google::cloud::osconfig::agentendpoint::v1::
        ReceiveTaskNotificationRequest const& request) {
  SetMetadata(*context, options);
  return child_->ReceiveTaskNotification(std::move(context), options, request);
}

StatusOr<google::cloud::osconfig::agentendpoint::v1::StartNextTaskResponse>
AgentEndpointServiceMetadata::StartNextTask(
    grpc::ClientContext& context, Options const& options,
    google::cloud::osconfig::agentendpoint::v1::StartNextTaskRequest const&
        request) {
  SetMetadata(context, options);
  return child_->StartNextTask(context, options, request);
}

StatusOr<google::cloud::osconfig::agentendpoint::v1::ReportTaskProgressResponse>
AgentEndpointServiceMetadata::ReportTaskProgress(
    grpc::ClientContext& context, Options const& options,
    google::cloud::osconfig::agentendpoint::v1::ReportTaskProgressRequest const&
        request) {
  SetMetadata(context, options);
  return child_->ReportTaskProgress(context, options, request);
}

StatusOr<google::cloud::osconfig::agentendpoint::v1::ReportTaskCompleteResponse>
AgentEndpointServiceMetadata::ReportTaskComplete(
    grpc::ClientContext& context, Options const& options,
    google::cloud::osconfig::agentendpoint::v1::ReportTaskCompleteRequest const&
        request) {
  SetMetadata(context, options);
  return child_->ReportTaskComplete(context, options, request);
}

StatusOr<google::cloud::osconfig::agentendpoint::v1::RegisterAgentResponse>
AgentEndpointServiceMetadata::RegisterAgent(
    grpc::ClientContext& context, Options const& options,
    google::cloud::osconfig::agentendpoint::v1::RegisterAgentRequest const&
        request) {
  SetMetadata(context, options);
  return child_->RegisterAgent(context, options, request);
}

StatusOr<google::cloud::osconfig::agentendpoint::v1::ReportInventoryResponse>
AgentEndpointServiceMetadata::ReportInventory(
    grpc::ClientContext& context, Options const& options,
    google::cloud::osconfig::agentendpoint::v1::ReportInventoryRequest const&
        request) {
  SetMetadata(context, options);
  return child_->ReportInventory(context, options, request);
}

void AgentEndpointServiceMetadata::SetMetadata(
    grpc::ClientContext& context, Options const& options,
    std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void AgentEndpointServiceMetadata::SetMetadata(grpc::ClientContext& context,
                                               Options const& options) {
  for (auto const& kv : fixed_metadata_) {
    context.AddMetadata(kv.first, kv.second);
  }
  context.AddMetadata("x-goog-api-client", api_client_header_);
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace osconfig_agentendpoint_v1_internal
}  // namespace cloud
}  // namespace google

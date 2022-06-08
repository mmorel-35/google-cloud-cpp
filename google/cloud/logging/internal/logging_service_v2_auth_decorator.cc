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
// source: google/logging/v2/logging.proto

#include "google/cloud/logging/internal/logging_service_v2_auth_decorator.h"
#include "google/cloud/internal/async_read_write_stream_auth.h"
#include <google/logging/v2/logging.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace logging_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

LoggingServiceV2Auth::LoggingServiceV2Auth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<LoggingServiceV2Stub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

Status LoggingServiceV2Auth::DeleteLog(
    grpc::ClientContext& context,
    google::logging::v2::DeleteLogRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteLog(context, request);
}

StatusOr<google::logging::v2::WriteLogEntriesResponse>
LoggingServiceV2Auth::WriteLogEntries(
    grpc::ClientContext& context,
    google::logging::v2::WriteLogEntriesRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->WriteLogEntries(context, request);
}

StatusOr<google::logging::v2::ListLogEntriesResponse>
LoggingServiceV2Auth::ListLogEntries(
    grpc::ClientContext& context,
    google::logging::v2::ListLogEntriesRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListLogEntries(context, request);
}

StatusOr<google::logging::v2::ListMonitoredResourceDescriptorsResponse>
LoggingServiceV2Auth::ListMonitoredResourceDescriptors(
    grpc::ClientContext& context,
    google::logging::v2::ListMonitoredResourceDescriptorsRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListMonitoredResourceDescriptors(context, request);
}

StatusOr<google::logging::v2::ListLogsResponse> LoggingServiceV2Auth::ListLogs(
    grpc::ClientContext& context,
    google::logging::v2::ListLogsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListLogs(context, request);
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::logging::v2::TailLogEntriesRequest,
    google::logging::v2::TailLogEntriesResponse>>
LoggingServiceV2Auth::AsyncTailLogEntries(
    google::cloud::CompletionQueue const& cq,
    std::unique_ptr<grpc::ClientContext> context) {
  using StreamAuth = google::cloud::internal::AsyncStreamingReadWriteRpcAuth<
      google::logging::v2::TailLogEntriesRequest,
      google::logging::v2::TailLogEntriesResponse>;

  auto& child = child_;
  auto call = [child, cq](std::unique_ptr<grpc::ClientContext> ctx) {
    return child->AsyncTailLogEntries(cq, std::move(ctx));
  };
  return absl::make_unique<StreamAuth>(
      std::move(context), auth_, StreamAuth::StreamFactory(std::move(call)));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace logging_internal
}  // namespace cloud
}  // namespace google

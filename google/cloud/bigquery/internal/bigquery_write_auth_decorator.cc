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
// source: google/cloud/bigquery/storage/v1/storage.proto

#include "google/cloud/bigquery/internal/bigquery_write_auth_decorator.h"
#include "google/cloud/internal/async_read_write_stream_auth.h"
#include <google/cloud/bigquery/storage/v1/storage.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

BigQueryWriteAuth::BigQueryWriteAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<BigQueryWriteStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::bigquery::storage::v1::WriteStream>
BigQueryWriteAuth::CreateWriteStream(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::CreateWriteStreamRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateWriteStream(context, request);
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::cloud::bigquery::storage::v1::AppendRowsRequest,
    google::cloud::bigquery::storage::v1::AppendRowsResponse>>
BigQueryWriteAuth::AsyncAppendRows(
    google::cloud::CompletionQueue const& cq,
    std::unique_ptr<grpc::ClientContext> context) {
  using StreamAuth = google::cloud::internal::AsyncStreamingReadWriteRpcAuth<
      google::cloud::bigquery::storage::v1::AppendRowsRequest,
      google::cloud::bigquery::storage::v1::AppendRowsResponse>;

  auto& child = child_;
  auto call = [child, cq](std::unique_ptr<grpc::ClientContext> ctx) {
    return child->AsyncAppendRows(cq, std::move(ctx));
  };
  return absl::make_unique<StreamAuth>(
      std::move(context), auth_, StreamAuth::StreamFactory(std::move(call)));
}

StatusOr<google::cloud::bigquery::storage::v1::WriteStream>
BigQueryWriteAuth::GetWriteStream(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::GetWriteStreamRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetWriteStream(context, request);
}

StatusOr<google::cloud::bigquery::storage::v1::FinalizeWriteStreamResponse>
BigQueryWriteAuth::FinalizeWriteStream(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::FinalizeWriteStreamRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->FinalizeWriteStream(context, request);
}

StatusOr<google::cloud::bigquery::storage::v1::BatchCommitWriteStreamsResponse>
BigQueryWriteAuth::BatchCommitWriteStreams(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::BatchCommitWriteStreamsRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->BatchCommitWriteStreams(context, request);
}

StatusOr<google::cloud::bigquery::storage::v1::FlushRowsResponse>
BigQueryWriteAuth::FlushRows(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::FlushRowsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->FlushRows(context, request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_internal
}  // namespace cloud
}  // namespace google

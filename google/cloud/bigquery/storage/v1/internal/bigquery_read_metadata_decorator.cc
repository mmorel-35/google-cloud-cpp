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
// source: google/cloud/bigquery/storage/v1/storage.proto

#include "google/cloud/bigquery/storage/v1/internal/bigquery_read_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/bigquery/storage/v1/storage.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace bigquery_storage_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

BigQueryReadMetadata::BigQueryReadMetadata(
    std::shared_ptr<BigQueryReadStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::bigquery::storage::v1::ReadSession>
BigQueryReadMetadata::CreateReadSession(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::CreateReadSessionRequest const&
        request) {
  SetMetadata(
      context, internal::CurrentOptions(),
      absl::StrCat("read_session.table=",
                   internal::UrlEncode(request.read_session().table())));
  return child_->CreateReadSession(context, request);
}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<
    google::cloud::bigquery::storage::v1::ReadRowsResponse>>
BigQueryReadMetadata::ReadRows(
    std::shared_ptr<grpc::ClientContext> context, Options const& options,
    google::cloud::bigquery::storage::v1::ReadRowsRequest const& request) {
  SetMetadata(
      *context, options,
      absl::StrCat("read_stream=", internal::UrlEncode(request.read_stream())));
  return child_->ReadRows(std::move(context), options, request);
}

StatusOr<google::cloud::bigquery::storage::v1::SplitReadStreamResponse>
BigQueryReadMetadata::SplitReadStream(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::SplitReadStreamRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->SplitReadStream(context, request);
}

void BigQueryReadMetadata::SetMetadata(grpc::ClientContext& context,
                                       Options const& options,
                                       std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void BigQueryReadMetadata::SetMetadata(grpc::ClientContext& context,
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
}  // namespace bigquery_storage_v1_internal
}  // namespace cloud
}  // namespace google

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
// source: google/cloud/retail/v2/catalog_service.proto

#include "google/cloud/retail/v2/internal/catalog_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/retail/v2/catalog_service.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace retail_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CatalogServiceMetadata::CatalogServiceMetadata(
    std::shared_ptr<CatalogServiceStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::retail::v2::ListCatalogsResponse>
CatalogServiceMetadata::ListCatalogs(
    grpc::ClientContext& context, Options const& options,
    google::cloud::retail::v2::ListCatalogsRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListCatalogs(context, options, request);
}

StatusOr<google::cloud::retail::v2::Catalog>
CatalogServiceMetadata::UpdateCatalog(
    grpc::ClientContext& context, Options const& options,
    google::cloud::retail::v2::UpdateCatalogRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("catalog.name=",
                           internal::UrlEncode(request.catalog().name())));
  return child_->UpdateCatalog(context, options, request);
}

Status CatalogServiceMetadata::SetDefaultBranch(
    grpc::ClientContext& context, Options const& options,
    google::cloud::retail::v2::SetDefaultBranchRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("catalog=", internal::UrlEncode(request.catalog())));
  return child_->SetDefaultBranch(context, options, request);
}

StatusOr<google::cloud::retail::v2::GetDefaultBranchResponse>
CatalogServiceMetadata::GetDefaultBranch(
    grpc::ClientContext& context, Options const& options,
    google::cloud::retail::v2::GetDefaultBranchRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("catalog=", internal::UrlEncode(request.catalog())));
  return child_->GetDefaultBranch(context, options, request);
}

StatusOr<google::cloud::retail::v2::CompletionConfig>
CatalogServiceMetadata::GetCompletionConfig(
    grpc::ClientContext& context, Options const& options,
    google::cloud::retail::v2::GetCompletionConfigRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetCompletionConfig(context, options, request);
}

StatusOr<google::cloud::retail::v2::CompletionConfig>
CatalogServiceMetadata::UpdateCompletionConfig(
    grpc::ClientContext& context, Options const& options,
    google::cloud::retail::v2::UpdateCompletionConfigRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("completion_config.name=",
                   internal::UrlEncode(request.completion_config().name())));
  return child_->UpdateCompletionConfig(context, options, request);
}

StatusOr<google::cloud::retail::v2::AttributesConfig>
CatalogServiceMetadata::GetAttributesConfig(
    grpc::ClientContext& context, Options const& options,
    google::cloud::retail::v2::GetAttributesConfigRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetAttributesConfig(context, options, request);
}

StatusOr<google::cloud::retail::v2::AttributesConfig>
CatalogServiceMetadata::UpdateAttributesConfig(
    grpc::ClientContext& context, Options const& options,
    google::cloud::retail::v2::UpdateAttributesConfigRequest const& request) {
  SetMetadata(
      context, options,
      absl::StrCat("attributes_config.name=",
                   internal::UrlEncode(request.attributes_config().name())));
  return child_->UpdateAttributesConfig(context, options, request);
}

StatusOr<google::cloud::retail::v2::AttributesConfig>
CatalogServiceMetadata::AddCatalogAttribute(
    grpc::ClientContext& context, Options const& options,
    google::cloud::retail::v2::AddCatalogAttributeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("attributes_config=",
                           internal::UrlEncode(request.attributes_config())));
  return child_->AddCatalogAttribute(context, options, request);
}

StatusOr<google::cloud::retail::v2::AttributesConfig>
CatalogServiceMetadata::RemoveCatalogAttribute(
    grpc::ClientContext& context, Options const& options,
    google::cloud::retail::v2::RemoveCatalogAttributeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("attributes_config=",
                           internal::UrlEncode(request.attributes_config())));
  return child_->RemoveCatalogAttribute(context, options, request);
}

StatusOr<google::cloud::retail::v2::AttributesConfig>
CatalogServiceMetadata::ReplaceCatalogAttribute(
    grpc::ClientContext& context, Options const& options,
    google::cloud::retail::v2::ReplaceCatalogAttributeRequest const& request) {
  SetMetadata(context, options,
              absl::StrCat("attributes_config=",
                           internal::UrlEncode(request.attributes_config())));
  return child_->ReplaceCatalogAttribute(context, options, request);
}

void CatalogServiceMetadata::SetMetadata(grpc::ClientContext& context,
                                         Options const& options,
                                         std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void CatalogServiceMetadata::SetMetadata(grpc::ClientContext& context,
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
}  // namespace retail_v2_internal
}  // namespace cloud
}  // namespace google

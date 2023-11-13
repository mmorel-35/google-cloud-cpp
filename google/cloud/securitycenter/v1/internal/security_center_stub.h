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
// source: google/cloud/securitycenter/v1/securitycenter_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SECURITYCENTER_V1_INTERNAL_SECURITY_CENTER_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SECURITYCENTER_V1_INTERNAL_SECURITY_CENTER_STUB_H

#include "google/cloud/completion_queue.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/securitycenter/v1/securitycenter_service.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace securitycenter_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class SecurityCenterStub {
 public:
  virtual ~SecurityCenterStub() = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncBulkMuteFindings(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::securitycenter::v1::BulkMuteFindingsRequest const&
          request) = 0;

  virtual StatusOr<
      google::cloud::securitycenter::v1::SecurityHealthAnalyticsCustomModule>
  CreateSecurityHealthAnalyticsCustomModule(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::
          CreateSecurityHealthAnalyticsCustomModuleRequest const& request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::Source> CreateSource(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::CreateSourceRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::Finding> CreateFinding(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::CreateFindingRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::MuteConfig>
  CreateMuteConfig(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::CreateMuteConfigRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::NotificationConfig>
  CreateNotificationConfig(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::CreateNotificationConfigRequest const&
          request) = 0;

  virtual Status DeleteMuteConfig(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::DeleteMuteConfigRequest const&
          request) = 0;

  virtual Status DeleteNotificationConfig(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::DeleteNotificationConfigRequest const&
          request) = 0;

  virtual Status DeleteSecurityHealthAnalyticsCustomModule(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::
          DeleteSecurityHealthAnalyticsCustomModuleRequest const& request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::BigQueryExport>
  GetBigQueryExport(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::GetBigQueryExportRequest const&
          request) = 0;

  virtual StatusOr<google::iam::v1::Policy> GetIamPolicy(
      grpc::ClientContext& context,
      google::iam::v1::GetIamPolicyRequest const& request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::MuteConfig> GetMuteConfig(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::GetMuteConfigRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::NotificationConfig>
  GetNotificationConfig(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::GetNotificationConfigRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::OrganizationSettings>
  GetOrganizationSettings(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::GetOrganizationSettingsRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::
                       EffectiveSecurityHealthAnalyticsCustomModule>
  GetEffectiveSecurityHealthAnalyticsCustomModule(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::
          GetEffectiveSecurityHealthAnalyticsCustomModuleRequest const&
              request) = 0;

  virtual StatusOr<
      google::cloud::securitycenter::v1::SecurityHealthAnalyticsCustomModule>
  GetSecurityHealthAnalyticsCustomModule(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::
          GetSecurityHealthAnalyticsCustomModuleRequest const& request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::Source> GetSource(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::GetSourceRequest const& request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::GroupAssetsResponse>
  GroupAssets(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::GroupAssetsRequest const& request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::GroupFindingsResponse>
  GroupFindings(grpc::ClientContext& context,
                google::cloud::securitycenter::v1::GroupFindingsRequest const&
                    request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::ListAssetsResponse>
  ListAssets(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::ListAssetsRequest const& request) = 0;

  virtual StatusOr<
      google::cloud::securitycenter::v1::
          ListDescendantSecurityHealthAnalyticsCustomModulesResponse>
  ListDescendantSecurityHealthAnalyticsCustomModules(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::
          ListDescendantSecurityHealthAnalyticsCustomModulesRequest const&
              request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::ListFindingsResponse>
  ListFindings(grpc::ClientContext& context,
               google::cloud::securitycenter::v1::ListFindingsRequest const&
                   request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::ListMuteConfigsResponse>
  ListMuteConfigs(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::ListMuteConfigsRequest const&
          request) = 0;

  virtual StatusOr<
      google::cloud::securitycenter::v1::ListNotificationConfigsResponse>
  ListNotificationConfigs(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::ListNotificationConfigsRequest const&
          request) = 0;

  virtual StatusOr<
      google::cloud::securitycenter::v1::
          ListEffectiveSecurityHealthAnalyticsCustomModulesResponse>
  ListEffectiveSecurityHealthAnalyticsCustomModules(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::
          ListEffectiveSecurityHealthAnalyticsCustomModulesRequest const&
              request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::
                       ListSecurityHealthAnalyticsCustomModulesResponse>
  ListSecurityHealthAnalyticsCustomModules(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::
          ListSecurityHealthAnalyticsCustomModulesRequest const& request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::ListSourcesResponse>
  ListSources(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::ListSourcesRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncRunAssetDiscovery(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::securitycenter::v1::RunAssetDiscoveryRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::Finding> SetFindingState(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::SetFindingStateRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::Finding> SetMute(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::SetMuteRequest const& request) = 0;

  virtual StatusOr<google::iam::v1::Policy> SetIamPolicy(
      grpc::ClientContext& context,
      google::iam::v1::SetIamPolicyRequest const& request) = 0;

  virtual StatusOr<google::iam::v1::TestIamPermissionsResponse>
  TestIamPermissions(
      grpc::ClientContext& context,
      google::iam::v1::TestIamPermissionsRequest const& request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::
                       SimulateSecurityHealthAnalyticsCustomModuleResponse>
  SimulateSecurityHealthAnalyticsCustomModule(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::
          SimulateSecurityHealthAnalyticsCustomModuleRequest const&
              request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::ExternalSystem>
  UpdateExternalSystem(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::UpdateExternalSystemRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::Finding> UpdateFinding(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::UpdateFindingRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::MuteConfig>
  UpdateMuteConfig(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::UpdateMuteConfigRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::NotificationConfig>
  UpdateNotificationConfig(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::UpdateNotificationConfigRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::OrganizationSettings>
  UpdateOrganizationSettings(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::
          UpdateOrganizationSettingsRequest const& request) = 0;

  virtual StatusOr<
      google::cloud::securitycenter::v1::SecurityHealthAnalyticsCustomModule>
  UpdateSecurityHealthAnalyticsCustomModule(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::
          UpdateSecurityHealthAnalyticsCustomModuleRequest const& request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::Source> UpdateSource(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::UpdateSourceRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::SecurityMarks>
  UpdateSecurityMarks(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::UpdateSecurityMarksRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::BigQueryExport>
  CreateBigQueryExport(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::CreateBigQueryExportRequest const&
          request) = 0;

  virtual Status DeleteBigQueryExport(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::DeleteBigQueryExportRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::securitycenter::v1::BigQueryExport>
  UpdateBigQueryExport(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::UpdateBigQueryExportRequest const&
          request) = 0;

  virtual StatusOr<
      google::cloud::securitycenter::v1::ListBigQueryExportsResponse>
  ListBigQueryExports(
      grpc::ClientContext& context,
      google::cloud::securitycenter::v1::ListBigQueryExportsRequest const&
          request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::GetOperationRequest const& request) = 0;

  virtual future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::CancelOperationRequest const& request) = 0;
};

class DefaultSecurityCenterStub : public SecurityCenterStub {
 public:
  DefaultSecurityCenterStub(
      std::unique_ptr<
          google::cloud::securitycenter::v1::SecurityCenter::StubInterface>
          grpc_stub,
      std::unique_ptr<google::longrunning::Operations::StubInterface>
          operations)
      : grpc_stub_(std::move(grpc_stub)), operations_(std::move(operations)) {}

  future<StatusOr<google::longrunning::Operation>> AsyncBulkMuteFindings(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::securitycenter::v1::BulkMuteFindingsRequest const& request)
      override;

  StatusOr<
      google::cloud::securitycenter::v1::SecurityHealthAnalyticsCustomModule>
  CreateSecurityHealthAnalyticsCustomModule(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::
          CreateSecurityHealthAnalyticsCustomModuleRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::Source> CreateSource(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::CreateSourceRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::Finding> CreateFinding(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::CreateFindingRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::MuteConfig> CreateMuteConfig(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::CreateMuteConfigRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::NotificationConfig>
  CreateNotificationConfig(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::CreateNotificationConfigRequest const&
          request) override;

  Status DeleteMuteConfig(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::DeleteMuteConfigRequest const& request)
      override;

  Status DeleteNotificationConfig(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::DeleteNotificationConfigRequest const&
          request) override;

  Status DeleteSecurityHealthAnalyticsCustomModule(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::
          DeleteSecurityHealthAnalyticsCustomModuleRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::BigQueryExport> GetBigQueryExport(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::GetBigQueryExportRequest const&
          request) override;

  StatusOr<google::iam::v1::Policy> GetIamPolicy(
      grpc::ClientContext& client_context,
      google::iam::v1::GetIamPolicyRequest const& request) override;

  StatusOr<google::cloud::securitycenter::v1::MuteConfig> GetMuteConfig(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::GetMuteConfigRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::NotificationConfig>
  GetNotificationConfig(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::GetNotificationConfigRequest const&
          request) override;

  StatusOr<google::cloud::securitycenter::v1::OrganizationSettings>
  GetOrganizationSettings(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::GetOrganizationSettingsRequest const&
          request) override;

  StatusOr<google::cloud::securitycenter::v1::
               EffectiveSecurityHealthAnalyticsCustomModule>
  GetEffectiveSecurityHealthAnalyticsCustomModule(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::
          GetEffectiveSecurityHealthAnalyticsCustomModuleRequest const& request)
      override;

  StatusOr<
      google::cloud::securitycenter::v1::SecurityHealthAnalyticsCustomModule>
  GetSecurityHealthAnalyticsCustomModule(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::
          GetSecurityHealthAnalyticsCustomModuleRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::Source> GetSource(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::GetSourceRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::GroupAssetsResponse> GroupAssets(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::GroupAssetsRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::GroupFindingsResponse>
  GroupFindings(grpc::ClientContext& client_context,
                google::cloud::securitycenter::v1::GroupFindingsRequest const&
                    request) override;

  StatusOr<google::cloud::securitycenter::v1::ListAssetsResponse> ListAssets(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::ListAssetsRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::
               ListDescendantSecurityHealthAnalyticsCustomModulesResponse>
  ListDescendantSecurityHealthAnalyticsCustomModules(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::
          ListDescendantSecurityHealthAnalyticsCustomModulesRequest const&
              request) override;

  StatusOr<google::cloud::securitycenter::v1::ListFindingsResponse>
  ListFindings(grpc::ClientContext& client_context,
               google::cloud::securitycenter::v1::ListFindingsRequest const&
                   request) override;

  StatusOr<google::cloud::securitycenter::v1::ListMuteConfigsResponse>
  ListMuteConfigs(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::ListMuteConfigsRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::ListNotificationConfigsResponse>
  ListNotificationConfigs(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::ListNotificationConfigsRequest const&
          request) override;

  StatusOr<google::cloud::securitycenter::v1::
               ListEffectiveSecurityHealthAnalyticsCustomModulesResponse>
  ListEffectiveSecurityHealthAnalyticsCustomModules(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::
          ListEffectiveSecurityHealthAnalyticsCustomModulesRequest const&
              request) override;

  StatusOr<google::cloud::securitycenter::v1::
               ListSecurityHealthAnalyticsCustomModulesResponse>
  ListSecurityHealthAnalyticsCustomModules(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::
          ListSecurityHealthAnalyticsCustomModulesRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::ListSourcesResponse> ListSources(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::ListSourcesRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncRunAssetDiscovery(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::securitycenter::v1::RunAssetDiscoveryRequest const&
          request) override;

  StatusOr<google::cloud::securitycenter::v1::Finding> SetFindingState(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::SetFindingStateRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::Finding> SetMute(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::SetMuteRequest const& request)
      override;

  StatusOr<google::iam::v1::Policy> SetIamPolicy(
      grpc::ClientContext& client_context,
      google::iam::v1::SetIamPolicyRequest const& request) override;

  StatusOr<google::iam::v1::TestIamPermissionsResponse> TestIamPermissions(
      grpc::ClientContext& client_context,
      google::iam::v1::TestIamPermissionsRequest const& request) override;

  StatusOr<google::cloud::securitycenter::v1::
               SimulateSecurityHealthAnalyticsCustomModuleResponse>
  SimulateSecurityHealthAnalyticsCustomModule(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::
          SimulateSecurityHealthAnalyticsCustomModuleRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::ExternalSystem>
  UpdateExternalSystem(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::UpdateExternalSystemRequest const&
          request) override;

  StatusOr<google::cloud::securitycenter::v1::Finding> UpdateFinding(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::UpdateFindingRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::MuteConfig> UpdateMuteConfig(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::UpdateMuteConfigRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::NotificationConfig>
  UpdateNotificationConfig(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::UpdateNotificationConfigRequest const&
          request) override;

  StatusOr<google::cloud::securitycenter::v1::OrganizationSettings>
  UpdateOrganizationSettings(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::
          UpdateOrganizationSettingsRequest const& request) override;

  StatusOr<
      google::cloud::securitycenter::v1::SecurityHealthAnalyticsCustomModule>
  UpdateSecurityHealthAnalyticsCustomModule(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::
          UpdateSecurityHealthAnalyticsCustomModuleRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::Source> UpdateSource(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::UpdateSourceRequest const& request)
      override;

  StatusOr<google::cloud::securitycenter::v1::SecurityMarks>
  UpdateSecurityMarks(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::UpdateSecurityMarksRequest const&
          request) override;

  StatusOr<google::cloud::securitycenter::v1::BigQueryExport>
  CreateBigQueryExport(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::CreateBigQueryExportRequest const&
          request) override;

  Status DeleteBigQueryExport(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::DeleteBigQueryExportRequest const&
          request) override;

  StatusOr<google::cloud::securitycenter::v1::BigQueryExport>
  UpdateBigQueryExport(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::UpdateBigQueryExportRequest const&
          request) override;

  StatusOr<google::cloud::securitycenter::v1::ListBigQueryExportsResponse>
  ListBigQueryExports(
      grpc::ClientContext& client_context,
      google::cloud::securitycenter::v1::ListBigQueryExportsRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::unique_ptr<
      google::cloud::securitycenter::v1::SecurityCenter::StubInterface>
      grpc_stub_;
  std::unique_ptr<google::longrunning::Operations::StubInterface> operations_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace securitycenter_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SECURITYCENTER_V1_INTERNAL_SECURITY_CENTER_STUB_H

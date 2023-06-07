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
// source: google/cloud/vmwareengine/v1/vmwareengine.proto

#include "google/cloud/vmwareengine/v1/vmware_engine_connection_idempotency_policy.h"
#include <memory>

namespace google {
namespace cloud {
namespace vmwareengine_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

VmwareEngineConnectionIdempotencyPolicy::
    ~VmwareEngineConnectionIdempotencyPolicy() = default;

std::unique_ptr<VmwareEngineConnectionIdempotencyPolicy>
VmwareEngineConnectionIdempotencyPolicy::clone() const {
  return std::make_unique<VmwareEngineConnectionIdempotencyPolicy>(*this);
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::ListPrivateClouds(
    google::cloud::vmwareengine::v1::ListPrivateCloudsRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::GetPrivateCloud(
    google::cloud::vmwareengine::v1::GetPrivateCloudRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::CreatePrivateCloud(
    google::cloud::vmwareengine::v1::CreatePrivateCloudRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::UpdatePrivateCloud(
    google::cloud::vmwareengine::v1::UpdatePrivateCloudRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::DeletePrivateCloud(
    google::cloud::vmwareengine::v1::DeletePrivateCloudRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::UndeletePrivateCloud(
    google::cloud::vmwareengine::v1::UndeletePrivateCloudRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::ListClusters(
    google::cloud::vmwareengine::v1::ListClustersRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::GetCluster(
    google::cloud::vmwareengine::v1::GetClusterRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::CreateCluster(
    google::cloud::vmwareengine::v1::CreateClusterRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::UpdateCluster(
    google::cloud::vmwareengine::v1::UpdateClusterRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::DeleteCluster(
    google::cloud::vmwareengine::v1::DeleteClusterRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::ListSubnets(
    google::cloud::vmwareengine::v1::ListSubnetsRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::GetSubnet(
    google::cloud::vmwareengine::v1::GetSubnetRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::UpdateSubnet(
    google::cloud::vmwareengine::v1::UpdateSubnetRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::ListNodeTypes(
    google::cloud::vmwareengine::v1::ListNodeTypesRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::GetNodeType(
    google::cloud::vmwareengine::v1::GetNodeTypeRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::ShowNsxCredentials(
    google::cloud::vmwareengine::v1::ShowNsxCredentialsRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::ShowVcenterCredentials(
    google::cloud::vmwareengine::v1::ShowVcenterCredentialsRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::ResetNsxCredentials(
    google::cloud::vmwareengine::v1::ResetNsxCredentialsRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::ResetVcenterCredentials(
    google::cloud::vmwareengine::v1::ResetVcenterCredentialsRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::CreateHcxActivationKey(
    google::cloud::vmwareengine::v1::CreateHcxActivationKeyRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::ListHcxActivationKeys(
    google::cloud::vmwareengine::v1::ListHcxActivationKeysRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::GetHcxActivationKey(
    google::cloud::vmwareengine::v1::GetHcxActivationKeyRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::GetNetworkPolicy(
    google::cloud::vmwareengine::v1::GetNetworkPolicyRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::ListNetworkPolicies(
    google::cloud::vmwareengine::v1::ListNetworkPoliciesRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::CreateNetworkPolicy(
    google::cloud::vmwareengine::v1::CreateNetworkPolicyRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::UpdateNetworkPolicy(
    google::cloud::vmwareengine::v1::UpdateNetworkPolicyRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::DeleteNetworkPolicy(
    google::cloud::vmwareengine::v1::DeleteNetworkPolicyRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::CreateVmwareEngineNetwork(
    google::cloud::vmwareengine::v1::CreateVmwareEngineNetworkRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::UpdateVmwareEngineNetwork(
    google::cloud::vmwareengine::v1::UpdateVmwareEngineNetworkRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::DeleteVmwareEngineNetwork(
    google::cloud::vmwareengine::v1::DeleteVmwareEngineNetworkRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::GetVmwareEngineNetwork(
    google::cloud::vmwareengine::v1::GetVmwareEngineNetworkRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::ListVmwareEngineNetworks(
    google::cloud::vmwareengine::v1::
        ListVmwareEngineNetworksRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::CreatePrivateConnection(
    google::cloud::vmwareengine::v1::CreatePrivateConnectionRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::GetPrivateConnection(
    google::cloud::vmwareengine::v1::GetPrivateConnectionRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::ListPrivateConnections(
    google::cloud::vmwareengine::v1::ListPrivateConnectionsRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::UpdatePrivateConnection(
    google::cloud::vmwareengine::v1::UpdatePrivateConnectionRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency VmwareEngineConnectionIdempotencyPolicy::DeletePrivateConnection(
    google::cloud::vmwareengine::v1::DeletePrivateConnectionRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency
VmwareEngineConnectionIdempotencyPolicy::ListPrivateConnectionPeeringRoutes(
    google::cloud::vmwareengine::v1::
        ListPrivateConnectionPeeringRoutesRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

std::unique_ptr<VmwareEngineConnectionIdempotencyPolicy>
MakeDefaultVmwareEngineConnectionIdempotencyPolicy() {
  return std::make_unique<VmwareEngineConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace vmwareengine_v1
}  // namespace cloud
}  // namespace google

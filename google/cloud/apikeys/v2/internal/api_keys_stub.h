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
// source: google/api/apikeys/v2/apikeys.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_APIKEYS_V2_INTERNAL_API_KEYS_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_APIKEYS_V2_INTERNAL_API_KEYS_STUB_H

#include "google/cloud/completion_queue.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/api/apikeys/v2/apikeys.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace apikeys_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ApiKeysStub {
 public:
  virtual ~ApiKeysStub() = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncCreateKey(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::api::apikeys::v2::CreateKeyRequest const& request) = 0;

  virtual StatusOr<google::api::apikeys::v2::ListKeysResponse> ListKeys(
      grpc::ClientContext& context,
      google::api::apikeys::v2::ListKeysRequest const& request) = 0;

  virtual StatusOr<google::api::apikeys::v2::Key> GetKey(
      grpc::ClientContext& context,
      google::api::apikeys::v2::GetKeyRequest const& request) = 0;

  virtual StatusOr<google::api::apikeys::v2::GetKeyStringResponse> GetKeyString(
      grpc::ClientContext& context,
      google::api::apikeys::v2::GetKeyStringRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncUpdateKey(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::api::apikeys::v2::UpdateKeyRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncDeleteKey(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::api::apikeys::v2::DeleteKeyRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncUndeleteKey(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::api::apikeys::v2::UndeleteKeyRequest const& request) = 0;

  virtual StatusOr<google::api::apikeys::v2::LookupKeyResponse> LookupKey(
      grpc::ClientContext& context,
      google::api::apikeys::v2::LookupKeyRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::GetOperationRequest const& request) = 0;

  virtual future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::CancelOperationRequest const& request) = 0;
};

class DefaultApiKeysStub : public ApiKeysStub {
 public:
  DefaultApiKeysStub(
      std::unique_ptr<google::api::apikeys::v2::ApiKeys::StubInterface>
          grpc_stub,
      std::unique_ptr<google::longrunning::Operations::StubInterface>
          operations)
      : grpc_stub_(std::move(grpc_stub)), operations_(std::move(operations)) {}

  future<StatusOr<google::longrunning::Operation>> AsyncCreateKey(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::api::apikeys::v2::CreateKeyRequest const& request) override;

  StatusOr<google::api::apikeys::v2::ListKeysResponse> ListKeys(
      grpc::ClientContext& client_context,
      google::api::apikeys::v2::ListKeysRequest const& request) override;

  StatusOr<google::api::apikeys::v2::Key> GetKey(
      grpc::ClientContext& client_context,
      google::api::apikeys::v2::GetKeyRequest const& request) override;

  StatusOr<google::api::apikeys::v2::GetKeyStringResponse> GetKeyString(
      grpc::ClientContext& client_context,
      google::api::apikeys::v2::GetKeyStringRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateKey(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::api::apikeys::v2::UpdateKeyRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteKey(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::api::apikeys::v2::DeleteKeyRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncUndeleteKey(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::api::apikeys::v2::UndeleteKeyRequest const& request) override;

  StatusOr<google::api::apikeys::v2::LookupKeyResponse> LookupKey(
      grpc::ClientContext& client_context,
      google::api::apikeys::v2::LookupKeyRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::unique_ptr<google::api::apikeys::v2::ApiKeys::StubInterface> grpc_stub_;
  std::unique_ptr<google::longrunning::Operations::StubInterface> operations_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace apikeys_v2_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_APIKEYS_V2_INTERNAL_API_KEYS_STUB_H

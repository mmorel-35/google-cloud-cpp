// Copyright 2020 Google LLC
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
// source: generator/integration_tests/test.proto

#include "generator/integration_tests/golden/iam_credentials_connection.gcpcxx.pb.h"
#include "generator/integration_tests/golden/internal/iam_credentials_stub_factory.gcpcxx.pb.h"
#include "google/cloud/internal/retry_loop.h"
#include "google/cloud/internal/user_agent_prefix.h"
#include <memory>

namespace google {
namespace cloud {
namespace golden {
inline namespace GOOGLE_CLOUD_CPP_NS {

std::string IAMCredentialsConnectionOptionsTraits::default_endpoint() {
  return "iamcredentials.googleapis.com";
}

std::string IAMCredentialsConnectionOptionsTraits::user_agent_prefix() {
  return google::cloud::internal::UserAgentPrefix();
}

int IAMCredentialsConnectionOptionsTraits::default_num_channels() { return 4; }

IAMCredentialsConnection::~IAMCredentialsConnection() = default;

StatusOr<::google::test::admin::database::v1::GenerateAccessTokenResponse>
IAMCredentialsConnection::GenerateAccessToken(
    ::google::test::admin::database::v1::GenerateAccessTokenRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<::google::test::admin::database::v1::GenerateIdTokenResponse>
IAMCredentialsConnection::GenerateIdToken(
    ::google::test::admin::database::v1::GenerateIdTokenRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

namespace {
std::unique_ptr<IAMCredentialsRetryPolicy> DefaultRetryPolicy() {
  return IAMCredentialsLimitedTimeRetryPolicy(std::chrono::minutes(30)).clone();
}

std::unique_ptr<BackoffPolicy> DefaultBackoffPolicy() {
  auto constexpr kBackoffScaling = 2.0;
  return ExponentialBackoffPolicy(std::chrono::seconds(1),
                                  std::chrono::minutes(5), kBackoffScaling)
      .clone();
}

class IAMCredentialsConnectionImpl : public IAMCredentialsConnection {
 public:
  explicit IAMCredentialsConnectionImpl(
      std::shared_ptr<golden_internal::IAMCredentialsStub> stub,
      std::unique_ptr<IAMCredentialsRetryPolicy> retry_policy,
      std::unique_ptr<BackoffPolicy> backoff_policy,
      std::unique_ptr<IAMCredentialsConnectionIdempotencyPolicy> idempotency_policy)
      : stub_(std::move(stub)),
        retry_policy_prototype_(std::move(retry_policy)),
        backoff_policy_prototype_(std::move(backoff_policy)),
        idempotency_policy_(std::move(idempotency_policy)) {}

  explicit IAMCredentialsConnectionImpl(
      std::shared_ptr<golden_internal::IAMCredentialsStub> stub)
      : IAMCredentialsConnectionImpl(
          std::move(stub),
          DefaultRetryPolicy(),
          DefaultBackoffPolicy(),
          MakeDefaultIAMCredentialsConnectionIdempotencyPolicy()) {}

  ~IAMCredentialsConnectionImpl() override = default;

  StatusOr<::google::test::admin::database::v1::GenerateAccessTokenResponse>
  GenerateAccessToken(
      ::google::test::admin::database::v1::GenerateAccessTokenRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->GenerateAccessToken(request),
        [this](grpc::ClientContext& context,
            ::google::test::admin::database::v1::GenerateAccessTokenRequest const& request) {
          return stub_->GenerateAccessToken(context, request);
        },
        request, __func__);
}

  StatusOr<::google::test::admin::database::v1::GenerateIdTokenResponse>
  GenerateIdToken(
      ::google::test::admin::database::v1::GenerateIdTokenRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->GenerateIdToken(request),
        [this](grpc::ClientContext& context,
            ::google::test::admin::database::v1::GenerateIdTokenRequest const& request) {
          return stub_->GenerateIdToken(context, request);
        },
        request, __func__);
}

 private:
  std::shared_ptr<golden_internal::IAMCredentialsStub> stub_;
  std::unique_ptr<IAMCredentialsRetryPolicy const> retry_policy_prototype_;
  std::unique_ptr<BackoffPolicy const> backoff_policy_prototype_;
  std::unique_ptr<IAMCredentialsConnectionIdempotencyPolicy> idempotency_policy_;
};
}  // namespace

std::shared_ptr<IAMCredentialsConnection> MakeIAMCredentialsConnection(
    IAMCredentialsConnectionOptions const& options) {
  return std::make_shared<IAMCredentialsConnectionImpl>(
      golden_internal::CreateDefaultIAMCredentialsStub(options));
}

std::shared_ptr<IAMCredentialsConnection> MakeIAMCredentialsConnection(
    IAMCredentialsConnectionOptions const& options,
    std::unique_ptr<IAMCredentialsRetryPolicy> retry_policy,
    std::unique_ptr<BackoffPolicy> backoff_policy,
    std::unique_ptr<IAMCredentialsConnectionIdempotencyPolicy> idempotency_policy) {
  return std::make_shared<IAMCredentialsConnectionImpl>(
      golden_internal::CreateDefaultIAMCredentialsStub(options),
      std::move(retry_policy), std::move(backoff_policy),
      std::move(idempotency_policy));
}

std::shared_ptr<IAMCredentialsConnection> MakeIAMCredentialsConnection(
    std::shared_ptr<golden_internal::IAMCredentialsStub> stub,
    std::unique_ptr<IAMCredentialsRetryPolicy> retry_policy,
    std::unique_ptr<BackoffPolicy> backoff_policy,
    std::unique_ptr<IAMCredentialsConnectionIdempotencyPolicy> idempotency_policy) {
  return std::make_shared<IAMCredentialsConnectionImpl>(
      std::move(stub), std::move(retry_policy), std::move(backoff_policy),
      std::move(idempotency_policy));
}

}  // namespace GOOGLE_CLOUD_CPP_NS
}  // namespace golden
}  // namespace cloud
}  // namespace google


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
// source: google/iam/admin/v1/iam.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_ADMIN_V1_IAM_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_ADMIN_V1_IAM_CONNECTION_H

#include "google/cloud/iam/admin/v1/iam_connection_idempotency_policy.h"
#include "google/cloud/iam/admin/v1/internal/iam_retry_traits.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/internal/retry_policy_impl.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/iam/admin/v1/iam.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace iam_admin_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/// The retry policy for `IAMConnection`.
class IAMRetryPolicy : public ::google::cloud::RetryPolicy {
 public:
  /// Creates a new instance of the policy, reset to the initial state.
  virtual std::unique_ptr<IAMRetryPolicy> clone() const = 0;
};

/**
 * A retry policy for `IAMConnection` based on counting errors.
 *
 * This policy stops retrying if:
 * - An RPC returns a non-transient error.
 * - More than a prescribed number of transient failures is detected.
 *
 * In this class the following status codes are treated as transient errors:
 * - [`kUnavailable`](@ref google::cloud::StatusCode)
 */
class IAMLimitedErrorCountRetryPolicy : public IAMRetryPolicy {
 public:
  /**
   * Create an instance that tolerates up to @p maximum_failures transient
   * errors.
   *
   * @note Disable the retry loop by providing an instance of this policy with
   *     @p maximum_failures == 0.
   */
  explicit IAMLimitedErrorCountRetryPolicy(int maximum_failures)
      : impl_(maximum_failures) {}

  IAMLimitedErrorCountRetryPolicy(
      IAMLimitedErrorCountRetryPolicy&& rhs) noexcept
      : IAMLimitedErrorCountRetryPolicy(rhs.maximum_failures()) {}
  IAMLimitedErrorCountRetryPolicy(
      IAMLimitedErrorCountRetryPolicy const& rhs) noexcept
      : IAMLimitedErrorCountRetryPolicy(rhs.maximum_failures()) {}

  int maximum_failures() const { return impl_.maximum_failures(); }

  bool OnFailure(Status const& status) override {
    return impl_.OnFailure(status);
  }
  bool IsExhausted() const override { return impl_.IsExhausted(); }
  bool IsPermanentFailure(Status const& status) const override {
    return impl_.IsPermanentFailure(status);
  }
  std::unique_ptr<IAMRetryPolicy> clone() const override {
    return std::make_unique<IAMLimitedErrorCountRetryPolicy>(
        maximum_failures());
  }

  // This is provided only for backwards compatibility.
  using BaseType = IAMRetryPolicy;

 private:
  google::cloud::internal::LimitedErrorCountRetryPolicy<
      iam_admin_v1_internal::IAMRetryTraits>
      impl_;
};

/**
 * A retry policy for `IAMConnection` based on elapsed time.
 *
 * This policy stops retrying if:
 * - An RPC returns a non-transient error.
 * - The elapsed time in the retry loop exceeds a prescribed duration.
 *
 * In this class the following status codes are treated as transient errors:
 * - [`kUnavailable`](@ref google::cloud::StatusCode)
 */
class IAMLimitedTimeRetryPolicy : public IAMRetryPolicy {
 public:
  /**
   * Constructor given a `std::chrono::duration<>` object.
   *
   * @tparam DurationRep a placeholder to match the `Rep` tparam for @p
   *     duration's type. The semantics of this template parameter are
   *     documented in `std::chrono::duration<>`. In brief, the underlying
   *     arithmetic type used to store the number of ticks. For our purposes it
   *     is simply a formal parameter.
   * @tparam DurationPeriod a placeholder to match the `Period` tparam for @p
   *     duration's type. The semantics of this template parameter are
   *     documented in `std::chrono::duration<>`. In brief, the length of the
   *     tick in seconds, expressed as a `std::ratio<>`. For our purposes it is
   *     simply a formal parameter.
   * @param maximum_duration the maximum time allowed before the policy expires.
   *     While the application can express this time in any units they desire,
   *     the class truncates to milliseconds.
   *
   * @see https://en.cppreference.com/w/cpp/chrono/duration for more information
   *     about `std::chrono::duration`.
   */
  template <typename DurationRep, typename DurationPeriod>
  explicit IAMLimitedTimeRetryPolicy(
      std::chrono::duration<DurationRep, DurationPeriod> maximum_duration)
      : impl_(maximum_duration) {}

  IAMLimitedTimeRetryPolicy(IAMLimitedTimeRetryPolicy&& rhs) noexcept
      : IAMLimitedTimeRetryPolicy(rhs.maximum_duration()) {}
  IAMLimitedTimeRetryPolicy(IAMLimitedTimeRetryPolicy const& rhs) noexcept
      : IAMLimitedTimeRetryPolicy(rhs.maximum_duration()) {}

  std::chrono::milliseconds maximum_duration() const {
    return impl_.maximum_duration();
  }

  bool OnFailure(Status const& status) override {
    return impl_.OnFailure(status);
  }
  bool IsExhausted() const override { return impl_.IsExhausted(); }
  bool IsPermanentFailure(Status const& status) const override {
    return impl_.IsPermanentFailure(status);
  }
  std::unique_ptr<IAMRetryPolicy> clone() const override {
    return std::make_unique<IAMLimitedTimeRetryPolicy>(maximum_duration());
  }

  // This is provided only for backwards compatibility.
  using BaseType = IAMRetryPolicy;

 private:
  google::cloud::internal::LimitedTimeRetryPolicy<
      iam_admin_v1_internal::IAMRetryTraits>
      impl_;
};

/**
 * The `IAMConnection` object for `IAMClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `IAMClient`. This allows users to inject custom behavior
 * (e.g., with a Google Mock object) when writing tests that use objects of type
 * `IAMClient`.
 *
 * To create a concrete instance, see `MakeIAMConnection()`.
 *
 * For mocking, see `iam_admin_v1_mocks::MockIAMConnection`.
 */
class IAMConnection {
 public:
  virtual ~IAMConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StreamRange<google::iam::admin::v1::ServiceAccount>
  ListServiceAccounts(
      google::iam::admin::v1::ListServiceAccountsRequest request);

  virtual StatusOr<google::iam::admin::v1::ServiceAccount> GetServiceAccount(
      google::iam::admin::v1::GetServiceAccountRequest const& request);

  virtual StatusOr<google::iam::admin::v1::ServiceAccount> CreateServiceAccount(
      google::iam::admin::v1::CreateServiceAccountRequest const& request);

  virtual StatusOr<google::iam::admin::v1::ServiceAccount> PatchServiceAccount(
      google::iam::admin::v1::PatchServiceAccountRequest const& request);

  virtual Status DeleteServiceAccount(
      google::iam::admin::v1::DeleteServiceAccountRequest const& request);

  virtual StatusOr<google::iam::admin::v1::UndeleteServiceAccountResponse>
  UndeleteServiceAccount(
      google::iam::admin::v1::UndeleteServiceAccountRequest const& request);

  virtual Status EnableServiceAccount(
      google::iam::admin::v1::EnableServiceAccountRequest const& request);

  virtual Status DisableServiceAccount(
      google::iam::admin::v1::DisableServiceAccountRequest const& request);

  virtual StatusOr<google::iam::admin::v1::ListServiceAccountKeysResponse>
  ListServiceAccountKeys(
      google::iam::admin::v1::ListServiceAccountKeysRequest const& request);

  virtual StatusOr<google::iam::admin::v1::ServiceAccountKey>
  GetServiceAccountKey(
      google::iam::admin::v1::GetServiceAccountKeyRequest const& request);

  virtual StatusOr<google::iam::admin::v1::ServiceAccountKey>
  CreateServiceAccountKey(
      google::iam::admin::v1::CreateServiceAccountKeyRequest const& request);

  virtual StatusOr<google::iam::admin::v1::ServiceAccountKey>
  UploadServiceAccountKey(
      google::iam::admin::v1::UploadServiceAccountKeyRequest const& request);

  virtual Status DeleteServiceAccountKey(
      google::iam::admin::v1::DeleteServiceAccountKeyRequest const& request);

  virtual Status DisableServiceAccountKey(
      google::iam::admin::v1::DisableServiceAccountKeyRequest const& request);

  virtual Status EnableServiceAccountKey(
      google::iam::admin::v1::EnableServiceAccountKeyRequest const& request);

  virtual StatusOr<google::iam::v1::Policy> GetIamPolicy(
      google::iam::v1::GetIamPolicyRequest const& request);

  virtual StatusOr<google::iam::v1::Policy> SetIamPolicy(
      google::iam::v1::SetIamPolicyRequest const& request);

  virtual StatusOr<google::iam::v1::TestIamPermissionsResponse>
  TestIamPermissions(google::iam::v1::TestIamPermissionsRequest const& request);

  virtual StreamRange<google::iam::admin::v1::Role> QueryGrantableRoles(
      google::iam::admin::v1::QueryGrantableRolesRequest request);

  virtual StreamRange<google::iam::admin::v1::Role> ListRoles(
      google::iam::admin::v1::ListRolesRequest request);

  virtual StatusOr<google::iam::admin::v1::Role> GetRole(
      google::iam::admin::v1::GetRoleRequest const& request);

  virtual StatusOr<google::iam::admin::v1::Role> CreateRole(
      google::iam::admin::v1::CreateRoleRequest const& request);

  virtual StatusOr<google::iam::admin::v1::Role> UpdateRole(
      google::iam::admin::v1::UpdateRoleRequest const& request);

  virtual StatusOr<google::iam::admin::v1::Role> DeleteRole(
      google::iam::admin::v1::DeleteRoleRequest const& request);

  virtual StatusOr<google::iam::admin::v1::Role> UndeleteRole(
      google::iam::admin::v1::UndeleteRoleRequest const& request);

  virtual StreamRange<google::iam::admin::v1::Permission>
  QueryTestablePermissions(
      google::iam::admin::v1::QueryTestablePermissionsRequest request);

  virtual StatusOr<google::iam::admin::v1::QueryAuditableServicesResponse>
  QueryAuditableServices(
      google::iam::admin::v1::QueryAuditableServicesRequest const& request);

  virtual StatusOr<google::iam::admin::v1::LintPolicyResponse> LintPolicy(
      google::iam::admin::v1::LintPolicyRequest const& request);
};

/**
 * A factory function to construct an object of type `IAMConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of IAMClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `IAMConnection`. Expected options are any of the types in
 * the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::iam_admin_v1::IAMPolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `IAMConnection` created by
 * this function.
 */
std::shared_ptr<IAMConnection> MakeIAMConnection(Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
namespace gcpcxxV1 = GOOGLE_CLOUD_CPP_NS;  // NOLINT(misc-unused-alias-decls)
}  // namespace iam_admin_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_ADMIN_V1_IAM_CONNECTION_H

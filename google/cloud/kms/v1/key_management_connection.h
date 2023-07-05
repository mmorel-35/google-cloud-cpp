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
// source: google/cloud/kms/v1/service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_KMS_V1_KEY_MANAGEMENT_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_KMS_V1_KEY_MANAGEMENT_CONNECTION_H

#include "google/cloud/kms/v1/internal/key_management_retry_traits.h"
#include "google/cloud/kms/v1/key_management_connection_idempotency_policy.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/internal/retry_policy_impl.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/cloud/kms/v1/service.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace kms_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/// The retry policy for `KeyManagementServiceConnection`.
class KeyManagementServiceRetryPolicy : public ::google::cloud::RetryPolicy {
 public:
  /// Creates a new instance of the policy, reset to the initial state.
  virtual std::unique_ptr<KeyManagementServiceRetryPolicy> clone() const = 0;
};

/**
 * A retry policy for `KeyManagementServiceConnection` based on counting errors.
 *
 * This policy stops retrying if:
 * - An RPC returns a non-transient error.
 * - More than a prescribed number of transient failures is detected.
 *
 * In this class the following status codes are treated as transient errors:
 * - [`kUnavailable`](@ref google::cloud::StatusCode)
 */
class KeyManagementServiceLimitedErrorCountRetryPolicy
    : public KeyManagementServiceRetryPolicy {
 public:
  /**
   * Create an instance that tolerates up to @p maximum_failures transient
   * errors.
   *
   * @note Disable the retry loop by providing an instance of this policy with
   *     @p maximum_failures == 0.
   */
  explicit KeyManagementServiceLimitedErrorCountRetryPolicy(
      int maximum_failures)
      : impl_(maximum_failures) {}

  KeyManagementServiceLimitedErrorCountRetryPolicy(
      KeyManagementServiceLimitedErrorCountRetryPolicy&& rhs) noexcept
      : KeyManagementServiceLimitedErrorCountRetryPolicy(
            rhs.maximum_failures()) {}
  KeyManagementServiceLimitedErrorCountRetryPolicy(
      KeyManagementServiceLimitedErrorCountRetryPolicy const& rhs) noexcept
      : KeyManagementServiceLimitedErrorCountRetryPolicy(
            rhs.maximum_failures()) {}

  int maximum_failures() const { return impl_.maximum_failures(); }

  bool OnFailure(Status const& status) override {
    return impl_.OnFailure(status);
  }
  bool IsExhausted() const override { return impl_.IsExhausted(); }
  bool IsPermanentFailure(Status const& status) const override {
    return impl_.IsPermanentFailure(status);
  }
  std::unique_ptr<KeyManagementServiceRetryPolicy> clone() const override {
    return std::make_unique<KeyManagementServiceLimitedErrorCountRetryPolicy>(
        maximum_failures());
  }

  // This is provided only for backwards compatibility.
  using BaseType = KeyManagementServiceRetryPolicy;

 private:
  google::cloud::internal::LimitedErrorCountRetryPolicy<
      kms_v1_internal::KeyManagementServiceRetryTraits>
      impl_;
};

/**
 * A retry policy for `KeyManagementServiceConnection` based on elapsed time.
 *
 * This policy stops retrying if:
 * - An RPC returns a non-transient error.
 * - The elapsed time in the retry loop exceeds a prescribed duration.
 *
 * In this class the following status codes are treated as transient errors:
 * - [`kUnavailable`](@ref google::cloud::StatusCode)
 */
class KeyManagementServiceLimitedTimeRetryPolicy
    : public KeyManagementServiceRetryPolicy {
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
  explicit KeyManagementServiceLimitedTimeRetryPolicy(
      std::chrono::duration<DurationRep, DurationPeriod> maximum_duration)
      : impl_(maximum_duration) {}

  KeyManagementServiceLimitedTimeRetryPolicy(
      KeyManagementServiceLimitedTimeRetryPolicy&& rhs) noexcept
      : KeyManagementServiceLimitedTimeRetryPolicy(rhs.maximum_duration()) {}
  KeyManagementServiceLimitedTimeRetryPolicy(
      KeyManagementServiceLimitedTimeRetryPolicy const& rhs) noexcept
      : KeyManagementServiceLimitedTimeRetryPolicy(rhs.maximum_duration()) {}

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
  std::unique_ptr<KeyManagementServiceRetryPolicy> clone() const override {
    return std::make_unique<KeyManagementServiceLimitedTimeRetryPolicy>(
        maximum_duration());
  }

  // This is provided only for backwards compatibility.
  using BaseType = KeyManagementServiceRetryPolicy;

 private:
  google::cloud::internal::LimitedTimeRetryPolicy<
      kms_v1_internal::KeyManagementServiceRetryTraits>
      impl_;
};

/**
 * The `KeyManagementServiceConnection` object for `KeyManagementServiceClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `KeyManagementServiceClient`. This allows users to inject custom
 * behavior (e.g., with a Google Mock object) when writing tests that use
 * objects of type `KeyManagementServiceClient`.
 *
 * To create a concrete instance, see `MakeKeyManagementServiceConnection()`.
 *
 * For mocking, see `kms_v1_mocks::MockKeyManagementServiceConnection`.
 */
class KeyManagementServiceConnection {
 public:
  virtual ~KeyManagementServiceConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StreamRange<google::cloud::kms::v1::KeyRing> ListKeyRings(
      google::cloud::kms::v1::ListKeyRingsRequest request);

  virtual StreamRange<google::cloud::kms::v1::CryptoKey> ListCryptoKeys(
      google::cloud::kms::v1::ListCryptoKeysRequest request);

  virtual StreamRange<google::cloud::kms::v1::CryptoKeyVersion>
  ListCryptoKeyVersions(
      google::cloud::kms::v1::ListCryptoKeyVersionsRequest request);

  virtual StreamRange<google::cloud::kms::v1::ImportJob> ListImportJobs(
      google::cloud::kms::v1::ListImportJobsRequest request);

  virtual StatusOr<google::cloud::kms::v1::KeyRing> GetKeyRing(
      google::cloud::kms::v1::GetKeyRingRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::CryptoKey> GetCryptoKey(
      google::cloud::kms::v1::GetCryptoKeyRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::CryptoKeyVersion>
  GetCryptoKeyVersion(
      google::cloud::kms::v1::GetCryptoKeyVersionRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::PublicKey> GetPublicKey(
      google::cloud::kms::v1::GetPublicKeyRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::ImportJob> GetImportJob(
      google::cloud::kms::v1::GetImportJobRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::KeyRing> CreateKeyRing(
      google::cloud::kms::v1::CreateKeyRingRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::CryptoKey> CreateCryptoKey(
      google::cloud::kms::v1::CreateCryptoKeyRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::CryptoKeyVersion>
  CreateCryptoKeyVersion(
      google::cloud::kms::v1::CreateCryptoKeyVersionRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::CryptoKeyVersion>
  ImportCryptoKeyVersion(
      google::cloud::kms::v1::ImportCryptoKeyVersionRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::ImportJob> CreateImportJob(
      google::cloud::kms::v1::CreateImportJobRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::CryptoKey> UpdateCryptoKey(
      google::cloud::kms::v1::UpdateCryptoKeyRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::CryptoKeyVersion>
  UpdateCryptoKeyVersion(
      google::cloud::kms::v1::UpdateCryptoKeyVersionRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::CryptoKey>
  UpdateCryptoKeyPrimaryVersion(
      google::cloud::kms::v1::UpdateCryptoKeyPrimaryVersionRequest const&
          request);

  virtual StatusOr<google::cloud::kms::v1::CryptoKeyVersion>
  DestroyCryptoKeyVersion(
      google::cloud::kms::v1::DestroyCryptoKeyVersionRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::CryptoKeyVersion>
  RestoreCryptoKeyVersion(
      google::cloud::kms::v1::RestoreCryptoKeyVersionRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::EncryptResponse> Encrypt(
      google::cloud::kms::v1::EncryptRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::DecryptResponse> Decrypt(
      google::cloud::kms::v1::DecryptRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::AsymmetricSignResponse>
  AsymmetricSign(google::cloud::kms::v1::AsymmetricSignRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::AsymmetricDecryptResponse>
  AsymmetricDecrypt(
      google::cloud::kms::v1::AsymmetricDecryptRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::MacSignResponse> MacSign(
      google::cloud::kms::v1::MacSignRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::MacVerifyResponse> MacVerify(
      google::cloud::kms::v1::MacVerifyRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::GenerateRandomBytesResponse>
  GenerateRandomBytes(
      google::cloud::kms::v1::GenerateRandomBytesRequest const& request);
};

/**
 * A factory function to construct an object of type
 * `KeyManagementServiceConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of
 * KeyManagementServiceClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `KeyManagementServiceConnection`. Expected options are any of the
 * types in the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::kms_v1::KeyManagementServicePolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `KeyManagementServiceConnection`
 * created by this function.
 */
std::shared_ptr<KeyManagementServiceConnection>
MakeKeyManagementServiceConnection(Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace kms_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_KMS_V1_KEY_MANAGEMENT_CONNECTION_H

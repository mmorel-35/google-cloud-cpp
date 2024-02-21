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
// source: google/appengine/v1/appengine.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_APPENGINE_V1_AUTHORIZED_CERTIFICATES_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_APPENGINE_V1_AUTHORIZED_CERTIFICATES_CLIENT_H

#include "google/cloud/appengine/v1/authorized_certificates_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace appengine_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Manages SSL certificates a user is authorized to administer. A user can
/// administer any SSL certificates applicable to their authorized domains.
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class AuthorizedCertificatesClient {
 public:
  explicit AuthorizedCertificatesClient(
      std::shared_ptr<AuthorizedCertificatesConnection> connection,
      Options opts = {});
  ~AuthorizedCertificatesClient();

  ///@{
  /// @name Copy and move support
  AuthorizedCertificatesClient(AuthorizedCertificatesClient const&) = default;
  AuthorizedCertificatesClient& operator=(AuthorizedCertificatesClient const&) =
      default;
  AuthorizedCertificatesClient(AuthorizedCertificatesClient&&) = default;
  AuthorizedCertificatesClient& operator=(AuthorizedCertificatesClient&&) =
      default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(AuthorizedCertificatesClient const& a,
                         AuthorizedCertificatesClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(AuthorizedCertificatesClient const& a,
                         AuthorizedCertificatesClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Lists all SSL certificates the user is authorized to administer.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.appengine.v1.ListAuthorizedCertificatesRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [StreamRange](@ref google::cloud::StreamRange)
  ///     to iterate of the results. See the documentation of this type for
  ///     details. In brief, this class has `begin()` and `end()` member
  ///     functions returning a iterator class meeting the
  ///     [input iterator requirements]. The value type for this iterator is a
  ///     [`StatusOr`] as the iteration may fail even after some values are
  ///     retrieved successfully, for example, if there is a network disconnect.
  ///     An empty set of results does not indicate an error, it indicates
  ///     that there are no resources meeting the request criteria.
  ///     On a successful iteration the `StatusOr<T>` contains elements of type
  ///     [google.appengine.v1.AuthorizedCertificate], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.appengine.v1.AuthorizedCertificate]: @googleapis_reference_link{google/appengine/v1/certificate.proto#L32}
  /// [google.appengine.v1.ListAuthorizedCertificatesRequest]: @googleapis_reference_link{google/appengine/v1/appengine.proto#L790}
  ///
  // clang-format on
  StreamRange<google::appengine::v1::AuthorizedCertificate>
  ListAuthorizedCertificates(
      google::appengine::v1::ListAuthorizedCertificatesRequest request,
      Options opts = {});

  // clang-format off
  ///
  /// Gets the specified SSL certificate.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.appengine.v1.GetAuthorizedCertificateRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.appengine.v1.AuthorizedCertificate])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.appengine.v1.AuthorizedCertificate]: @googleapis_reference_link{google/appengine/v1/certificate.proto#L32}
  /// [google.appengine.v1.GetAuthorizedCertificateRequest]: @googleapis_reference_link{google/appengine/v1/appengine.proto#L814}
  ///
  // clang-format on
  StatusOr<google::appengine::v1::AuthorizedCertificate>
  GetAuthorizedCertificate(
      google::appengine::v1::GetAuthorizedCertificateRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Uploads the specified SSL certificate.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.appengine.v1.CreateAuthorizedCertificateRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.appengine.v1.AuthorizedCertificate])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.appengine.v1.AuthorizedCertificate]: @googleapis_reference_link{google/appengine/v1/certificate.proto#L32}
  /// [google.appengine.v1.CreateAuthorizedCertificateRequest]: @googleapis_reference_link{google/appengine/v1/appengine.proto#L836}
  ///
  // clang-format on
  StatusOr<google::appengine::v1::AuthorizedCertificate>
  CreateAuthorizedCertificate(
      google::appengine::v1::CreateAuthorizedCertificateRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Updates the specified SSL certificate. To renew a certificate and maintain
  /// its existing domain mappings, update `certificate_data` with a new
  /// certificate. The new certificate must be applicable to the same domains as
  /// the original certificate. The certificate `display_name` may also be
  /// updated.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.appengine.v1.UpdateAuthorizedCertificateRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.appengine.v1.AuthorizedCertificate])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.appengine.v1.AuthorizedCertificate]: @googleapis_reference_link{google/appengine/v1/certificate.proto#L32}
  /// [google.appengine.v1.UpdateAuthorizedCertificateRequest]: @googleapis_reference_link{google/appengine/v1/appengine.proto#L845}
  ///
  // clang-format on
  StatusOr<google::appengine::v1::AuthorizedCertificate>
  UpdateAuthorizedCertificate(
      google::appengine::v1::UpdateAuthorizedCertificateRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Deletes the specified SSL certificate.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.appengine.v1.DeleteAuthorizedCertificateRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [`Status`] object. If the request failed, the
  ///     status contains the details of the failure.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.appengine.v1.DeleteAuthorizedCertificateRequest]: @googleapis_reference_link{google/appengine/v1/appengine.proto#L860}
  ///
  // clang-format on
  Status DeleteAuthorizedCertificate(
      google::appengine::v1::DeleteAuthorizedCertificateRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<AuthorizedCertificatesConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace appengine_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_APPENGINE_V1_AUTHORIZED_CERTIFICATES_CLIENT_H

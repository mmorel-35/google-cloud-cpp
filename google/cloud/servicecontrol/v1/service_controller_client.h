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
// source: google/api/servicecontrol/v1/service_controller.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SERVICECONTROL_V1_SERVICE_CONTROLLER_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SERVICECONTROL_V1_SERVICE_CONTROLLER_CLIENT_H

#include "google/cloud/servicecontrol/v1/service_controller_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace servicecontrol_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// [Google Service Control API](/service-control/overview)
///
/// Lets clients check and report operations against a [managed
/// service](https://cloud.google.com/service-management/reference/rpc/google.api/servicemanagement.v1#google.api.servicemanagement.v1.ManagedService).
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
class ServiceControllerClient {
 public:
  explicit ServiceControllerClient(
      std::shared_ptr<ServiceControllerConnection> connection,
      Options opts = {});
  ~ServiceControllerClient();

  ///@{
  /// @name Copy and move support
  ServiceControllerClient(ServiceControllerClient const&) = default;
  ServiceControllerClient& operator=(ServiceControllerClient const&) = default;
  ServiceControllerClient(ServiceControllerClient&&) = default;
  ServiceControllerClient& operator=(ServiceControllerClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(ServiceControllerClient const& a,
                         ServiceControllerClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(ServiceControllerClient const& a,
                         ServiceControllerClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Checks whether an operation on a service should be allowed to proceed
  /// based on the configuration of the service and related policies. It must be
  /// called before the operation is executed.
  ///
  /// If feasible, the client should cache the check results and reuse them for
  /// 60 seconds. In case of any server errors, the client should rely on the
  /// cached results for much longer time to avoid outage.
  /// WARNING: There is general 60s delay for the configuration and policy
  /// propagation, therefore callers MUST NOT depend on the `Check` method having
  /// the latest policy information.
  ///
  /// NOTE: the [CheckRequest][google.api.servicecontrol.v1.CheckRequest] has
  /// the size limit (wire-format byte size) of 1MB.
  ///
  /// This method requires the `servicemanagement.services.check` permission
  /// on the specified service. For more information, see
  /// [Cloud IAM](https://cloud.google.com/iam).
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.api.servicecontrol.v1.CheckRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.api.servicecontrol.v1.CheckResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.api.servicecontrol.v1.CheckRequest]: @googleapis_reference_link{google/api/servicecontrol/v1/service_controller.proto#L93}
  /// [google.api.servicecontrol.v1.CheckResponse]: @googleapis_reference_link{google/api/servicecontrol/v1/service_controller.proto#L114}
  ///
  // clang-format on
  StatusOr<google::api::servicecontrol::v1::CheckResponse> Check(
      google::api::servicecontrol::v1::CheckRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Reports operation results to Google Service Control, such as logs and
  /// metrics. It should be called after an operation is completed.
  ///
  /// If feasible, the client should aggregate reporting data for up to 5
  /// seconds to reduce API traffic. Limiting aggregation to 5 seconds is to
  /// reduce data loss during client crashes. Clients should carefully choose
  /// the aggregation time window to avoid data loss risk more than 0.01%
  /// for business and compliance reasons.
  ///
  /// NOTE: the [ReportRequest][google.api.servicecontrol.v1.ReportRequest] has
  /// the size limit (wire-format byte size) of 1MB.
  ///
  /// This method requires the `servicemanagement.services.report` permission
  /// on the specified service. For more information, see
  /// [Google Cloud IAM](https://cloud.google.com/iam).
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.api.servicecontrol.v1.ReportRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.api.servicecontrol.v1.ReportResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.api.servicecontrol.v1.ReportRequest]: @googleapis_reference_link{google/api/servicecontrol/v1/service_controller.proto#L189}
  /// [google.api.servicecontrol.v1.ReportResponse]: @googleapis_reference_link{google/api/servicecontrol/v1/service_controller.proto#L220}
  ///
  // clang-format on
  StatusOr<google::api::servicecontrol::v1::ReportResponse> Report(
      google::api::servicecontrol::v1::ReportRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<ServiceControllerConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace servicecontrol_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SERVICECONTROL_V1_SERVICE_CONTROLLER_CLIENT_H

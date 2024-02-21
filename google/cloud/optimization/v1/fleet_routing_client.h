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
// source: google/cloud/optimization/v1/fleet_routing.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_OPTIMIZATION_V1_FLEET_ROUTING_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_OPTIMIZATION_V1_FLEET_ROUTING_CLIENT_H

#include "google/cloud/optimization/v1/fleet_routing_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace optimization_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// A service for optimizing vehicle tours.
///
/// Validity of certain types of fields:
///
///   * `google.protobuf.Timestamp`
///     * Times are in Unix time: seconds since 1970-01-01T00:00:00+00:00.
///     * seconds must be in [0, 253402300799],
///       i.e. in [1970-01-01T00:00:00+00:00, 9999-12-31T23:59:59+00:00].
///     * nanos must be unset or set to 0.
///   * `google.protobuf.Duration`
///     * seconds must be in [0, 253402300799],
///       i.e. in [1970-01-01T00:00:00+00:00, 9999-12-31T23:59:59+00:00].
///     * nanos must be unset or set to 0.
///   * `google.type.LatLng`
///     * latitude must be in [-90.0, 90.0].
///     * longitude must be in [-180.0, 180.0].
///     * at least one of latitude and longitude must be non-zero.
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
class FleetRoutingClient {
 public:
  explicit FleetRoutingClient(
      std::shared_ptr<FleetRoutingConnection> connection, Options opts = {});
  ~FleetRoutingClient();

  ///@{
  /// @name Copy and move support
  FleetRoutingClient(FleetRoutingClient const&) = default;
  FleetRoutingClient& operator=(FleetRoutingClient const&) = default;
  FleetRoutingClient(FleetRoutingClient&&) = default;
  FleetRoutingClient& operator=(FleetRoutingClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(FleetRoutingClient const& a,
                         FleetRoutingClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(FleetRoutingClient const& a,
                         FleetRoutingClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Sends an `OptimizeToursRequest` containing a `ShipmentModel` and returns an
  /// `OptimizeToursResponse` containing `ShipmentRoute`s, which are a set of
  /// routes to be performed by vehicles minimizing the overall cost.
  ///
  /// A `ShipmentModel` model consists mainly of `Shipment`s that need to be
  /// carried out and `Vehicle`s that can be used to transport the `Shipment`s.
  /// The `ShipmentRoute`s assign `Shipment`s to `Vehicle`s. More specifically,
  /// they assign a series of `Visit`s to each vehicle, where a `Visit`
  /// corresponds to a `VisitRequest`, which is a pickup or delivery for a
  /// `Shipment`.
  ///
  /// The goal is to provide an assignment of `ShipmentRoute`s to `Vehicle`s that
  /// minimizes the total cost where cost has many components defined in the
  /// `ShipmentModel`.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.optimization.v1.OptimizeToursRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.optimization.v1.OptimizeToursResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.optimization.v1.OptimizeToursRequest]: @googleapis_reference_link{google/cloud/optimization/v1/fleet_routing.proto#L109}
  /// [google.cloud.optimization.v1.OptimizeToursResponse]: @googleapis_reference_link{google/cloud/optimization/v1/fleet_routing.proto#L366}
  ///
  // clang-format on
  StatusOr<google::cloud::optimization::v1::OptimizeToursResponse>
  OptimizeTours(
      google::cloud::optimization::v1::OptimizeToursRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Optimizes vehicle tours for one or more `OptimizeToursRequest`
  /// messages as a batch.
  ///
  /// This method is a Long Running Operation (LRO). The inputs for optimization
  /// (`OptimizeToursRequest` messages) and outputs (`OptimizeToursResponse`
  /// messages) are read/written from/to Cloud Storage in user-specified
  /// format. Like the `OptimizeTours` method, each `OptimizeToursRequest`
  /// contains a `ShipmentModel` and returns an `OptimizeToursResponse`
  /// containing `ShipmentRoute`s, which are a set of routes to be performed by
  /// vehicles minimizing the overall cost.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.optimization.v1.BatchOptimizeToursRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return A [`future`] that becomes satisfied when the LRO
  ///     ([Long Running Operation]) completes or the polling policy in effect
  ///     for this call is exhausted. The future is satisfied with an error if
  ///     the LRO completes with an error or the polling policy is exhausted.
  ///     In this case the [`StatusOr`] returned by the future contains the
  ///     error. If the LRO completes successfully the value of the future
  ///     contains the LRO's result. For this RPC the result is a
  ///     [google.cloud.optimization.v1.BatchOptimizeToursResponse] proto message.
  ///     The C++ class representing this message is created by Protobuf, using
  ///     the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.optimization.v1.BatchOptimizeToursRequest]: @googleapis_reference_link{google/cloud/optimization/v1/fleet_routing.proto#L442}
  /// [google.cloud.optimization.v1.BatchOptimizeToursResponse]: @googleapis_reference_link{google/cloud/optimization/v1/fleet_routing.proto#L481}
  ///
  // clang-format on
  future<StatusOr<google::cloud::optimization::v1::BatchOptimizeToursResponse>>
  BatchOptimizeTours(
      google::cloud::optimization::v1::BatchOptimizeToursRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<FleetRoutingConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace optimization_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_OPTIMIZATION_V1_FLEET_ROUTING_CLIENT_H

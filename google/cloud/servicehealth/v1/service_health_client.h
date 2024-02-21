// Copyright 2024 Google LLC
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
// source: google/cloud/servicehealth/v1/event_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SERVICEHEALTH_V1_SERVICE_HEALTH_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SERVICEHEALTH_V1_SERVICE_HEALTH_CLIENT_H

#include "google/cloud/servicehealth/v1/service_health_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace servicehealth_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Request service health events relevant to your Google Cloud project.
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
class ServiceHealthClient {
 public:
  explicit ServiceHealthClient(
      std::shared_ptr<ServiceHealthConnection> connection, Options opts = {});
  ~ServiceHealthClient();

  ///@{
  /// @name Copy and move support
  ServiceHealthClient(ServiceHealthClient const&) = default;
  ServiceHealthClient& operator=(ServiceHealthClient const&) = default;
  ServiceHealthClient(ServiceHealthClient&&) = default;
  ServiceHealthClient& operator=(ServiceHealthClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(ServiceHealthClient const& a,
                         ServiceHealthClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(ServiceHealthClient const& a,
                         ServiceHealthClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Lists events under a given project and location.
  ///
  /// @param parent  Required. Parent value using the form
  ///  `projects/{project_id}/locations/{location}/events`.
  ///  @n
  ///  `project_id` - ID of the project for which to list service health
  ///  events.
  ///  `location` - The location to get the service health events from.
  ///  To retrieve service health events of category = INCIDENT, use `location` =
  ///  `global`.
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
  ///     [google.cloud.servicehealth.v1.Event], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.servicehealth.v1.Event]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L38}
  /// [google.cloud.servicehealth.v1.ListEventsRequest]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L454}
  ///
  // clang-format on
  StreamRange<google::cloud::servicehealth::v1::Event> ListEvents(
      std::string const& parent, Options opts = {});

  // clang-format off
  ///
  /// Lists events under a given project and location.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.servicehealth.v1.ListEventsRequest].
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
  ///     [google.cloud.servicehealth.v1.Event], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.servicehealth.v1.Event]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L38}
  /// [google.cloud.servicehealth.v1.ListEventsRequest]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L454}
  ///
  // clang-format on
  StreamRange<google::cloud::servicehealth::v1::Event> ListEvents(
      google::cloud::servicehealth::v1::ListEventsRequest request,
      Options opts = {});

  // clang-format off
  ///
  /// Retrieves a resource containing information about an event.
  ///
  /// @param name  Required. Unique name of the event in this scope including project
  ///  and location using the form
  ///  `projects/{project_id}/locations/{location}/events/{event_id}`.
  ///  @n
  ///  `project_id` - Project ID of the project that contains the event. <br>
  ///  `location` - The location to get the service health events from. <br>
  ///  `event_id` - Event ID to retrieve.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.servicehealth.v1.Event])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.servicehealth.v1.Event]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L38}
  /// [google.cloud.servicehealth.v1.GetEventRequest]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L520}
  ///
  // clang-format on
  StatusOr<google::cloud::servicehealth::v1::Event> GetEvent(
      std::string const& name, Options opts = {});

  // clang-format off
  ///
  /// Retrieves a resource containing information about an event.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.servicehealth.v1.GetEventRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.servicehealth.v1.Event])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.servicehealth.v1.Event]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L38}
  /// [google.cloud.servicehealth.v1.GetEventRequest]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L520}
  ///
  // clang-format on
  StatusOr<google::cloud::servicehealth::v1::Event> GetEvent(
      google::cloud::servicehealth::v1::GetEventRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Lists organization events under a given organization and location.
  ///
  /// @param parent  Required. Parent value using the form
  ///  `organizations/{organization_id}/locations/{location}/organizationEvents`.
  ///  @n
  ///  `organization_id` - ID (number) of the project that contains the event. To
  ///  get your `organization_id`, see
  ///  [Getting your organization resource
  ///  ID](https://cloud.google.com/resource-manager/docs/creating-managing-organization#retrieving_your_organization_id).<br>
  ///  `location` - The location to get the service health events from. To
  ///  retrieve service health events of category = INCIDENT, use `location` =
  ///  `global`.
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
  ///     [google.cloud.servicehealth.v1.OrganizationEvent], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.servicehealth.v1.ListOrganizationEventsRequest]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L536}
  /// [google.cloud.servicehealth.v1.OrganizationEvent]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L211}
  ///
  // clang-format on
  StreamRange<google::cloud::servicehealth::v1::OrganizationEvent>
  ListOrganizationEvents(std::string const& parent, Options opts = {});

  // clang-format off
  ///
  /// Lists organization events under a given organization and location.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.servicehealth.v1.ListOrganizationEventsRequest].
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
  ///     [google.cloud.servicehealth.v1.OrganizationEvent], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.servicehealth.v1.ListOrganizationEventsRequest]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L536}
  /// [google.cloud.servicehealth.v1.OrganizationEvent]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L211}
  ///
  // clang-format on
  StreamRange<google::cloud::servicehealth::v1::OrganizationEvent>
  ListOrganizationEvents(
      google::cloud::servicehealth::v1::ListOrganizationEventsRequest request,
      Options opts = {});

  // clang-format off
  ///
  /// Retrieves a resource containing information about an event affecting an
  /// organization .
  ///
  /// @param name  Required. Unique name of the event in this scope including organization and
  ///  event ID using the form
  ///  `organizations/{organization_id}/locations/locations/global/organizationEvents/{event_id}`.
  ///  @n
  ///  `organization_id` - ID (number) of the project that contains the event. To
  ///  get your `organization_id`, see
  ///  [Getting your organization resource
  ///  ID](https://cloud.google.com/resource-manager/docs/creating-managing-organization#retrieving_your_organization_id).<br>
  ///  `event_id` - Organization event ID to retrieve.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.servicehealth.v1.OrganizationEvent])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.servicehealth.v1.GetOrganizationEventRequest]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L608}
  /// [google.cloud.servicehealth.v1.OrganizationEvent]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L211}
  ///
  // clang-format on
  StatusOr<google::cloud::servicehealth::v1::OrganizationEvent>
  GetOrganizationEvent(std::string const& name, Options opts = {});

  // clang-format off
  ///
  /// Retrieves a resource containing information about an event affecting an
  /// organization .
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.servicehealth.v1.GetOrganizationEventRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.servicehealth.v1.OrganizationEvent])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.servicehealth.v1.GetOrganizationEventRequest]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L608}
  /// [google.cloud.servicehealth.v1.OrganizationEvent]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L211}
  ///
  // clang-format on
  StatusOr<google::cloud::servicehealth::v1::OrganizationEvent>
  GetOrganizationEvent(
      google::cloud::servicehealth::v1::GetOrganizationEventRequest const&
          request,
      Options opts = {});

  // clang-format off
  ///
  /// Lists assets impacted by organization events under a given organization and
  /// location.
  ///
  /// @param parent  Required. Parent value using the form
  ///  `organizations/{organization_id}/locations/{location}/organizationImpacts`.
  ///  @n
  ///  `organization_id` - ID (number) of the project that contains the event. To
  ///  get your `organization_id`, see
  ///  [Getting your organization resource
  ///  ID](https://cloud.google.com/resource-manager/docs/creating-managing-organization#retrieving_your_organization_id).
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
  ///     [google.cloud.servicehealth.v1.OrganizationImpact], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.servicehealth.v1.ListOrganizationImpactsRequest]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L627}
  /// [google.cloud.servicehealth.v1.OrganizationImpact]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L403}
  ///
  // clang-format on
  StreamRange<google::cloud::servicehealth::v1::OrganizationImpact>
  ListOrganizationImpacts(std::string const& parent, Options opts = {});

  // clang-format off
  ///
  /// Lists assets impacted by organization events under a given organization and
  /// location.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.servicehealth.v1.ListOrganizationImpactsRequest].
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
  ///     [google.cloud.servicehealth.v1.OrganizationImpact], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.servicehealth.v1.ListOrganizationImpactsRequest]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L627}
  /// [google.cloud.servicehealth.v1.OrganizationImpact]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L403}
  ///
  // clang-format on
  StreamRange<google::cloud::servicehealth::v1::OrganizationImpact>
  ListOrganizationImpacts(
      google::cloud::servicehealth::v1::ListOrganizationImpactsRequest request,
      Options opts = {});

  // clang-format off
  ///
  /// Retrieves a resource containing information about impact to an asset under
  /// an organization affected by a service health event.
  ///
  /// @param name  Required. Name of the resource using the form
  ///  `organizations/{organization_id}/locations/global/organizationImpacts/{organization_impact_id}`.
  ///  @n
  ///  `organization_id` - ID (number) of the organization that contains the
  ///  event. To get your `organization_id`, see
  ///  [Getting your organization resource
  ///  ID](https://cloud.google.com/resource-manager/docs/creating-managing-organization#retrieving_your_organization_id).<br>
  ///  `organization_impact_id` - ID of the [OrganizationImpact
  ///  resource](/service-health/docs/reference/rest/v1beta/organizations.locations.organizationImpacts#OrganizationImpact).
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.servicehealth.v1.OrganizationImpact])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.servicehealth.v1.GetOrganizationImpactRequest]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L698}
  /// [google.cloud.servicehealth.v1.OrganizationImpact]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L403}
  ///
  // clang-format on
  StatusOr<google::cloud::servicehealth::v1::OrganizationImpact>
  GetOrganizationImpact(std::string const& name, Options opts = {});

  // clang-format off
  ///
  /// Retrieves a resource containing information about impact to an asset under
  /// an organization affected by a service health event.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.servicehealth.v1.GetOrganizationImpactRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.servicehealth.v1.OrganizationImpact])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.servicehealth.v1.GetOrganizationImpactRequest]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L698}
  /// [google.cloud.servicehealth.v1.OrganizationImpact]: @googleapis_reference_link{google/cloud/servicehealth/v1/event_resources.proto#L403}
  ///
  // clang-format on
  StatusOr<google::cloud::servicehealth::v1::OrganizationImpact>
  GetOrganizationImpact(
      google::cloud::servicehealth::v1::GetOrganizationImpactRequest const&
          request,
      Options opts = {});

 private:
  std::shared_ptr<ServiceHealthConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace servicehealth_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SERVICEHEALTH_V1_SERVICE_HEALTH_CLIENT_H

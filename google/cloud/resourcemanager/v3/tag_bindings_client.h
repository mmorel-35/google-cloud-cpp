// Copyright 2023 Google LLC
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
// source: google/cloud/resourcemanager/v3/tag_bindings.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RESOURCEMANAGER_V3_TAG_BINDINGS_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RESOURCEMANAGER_V3_TAG_BINDINGS_CLIENT_H

#include "google/cloud/resourcemanager/v3/tag_bindings_connection.h"
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
namespace resourcemanager_v3 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Allow users to create and manage TagBindings between TagValues and
/// different Google Cloud resources throughout the GCP resource hierarchy.
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
class TagBindingsClient {
 public:
  explicit TagBindingsClient(std::shared_ptr<TagBindingsConnection> connection,
                             Options opts = {});
  ~TagBindingsClient();

  ///@{
  /// @name Copy and move support
  TagBindingsClient(TagBindingsClient const&) = default;
  TagBindingsClient& operator=(TagBindingsClient const&) = default;
  TagBindingsClient(TagBindingsClient&&) = default;
  TagBindingsClient& operator=(TagBindingsClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(TagBindingsClient const& a,
                         TagBindingsClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(TagBindingsClient const& a,
                         TagBindingsClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Lists the TagBindings for the given Google Cloud resource, as specified
  /// with `parent`.
  ///
  /// NOTE: The `parent` field is expected to be a full resource name:
  /// https://cloud.google.com/apis/design/resource_names#full_resource_name
  ///
  /// @param parent  Required. The full resource name of a resource for which you want to list
  ///  existing TagBindings. E.g.
  ///  "//cloudresourcemanager.googleapis.com/projects/123"
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
  ///     [google.cloud.resourcemanager.v3.TagBinding], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.resourcemanager.v3.ListTagBindingsRequest]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L155}
  /// [google.cloud.resourcemanager.v3.TagBinding]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L96}
  ///
  // clang-format on
  StreamRange<google::cloud::resourcemanager::v3::TagBinding> ListTagBindings(
      std::string const& parent, Options opts = {});

  // clang-format off
  ///
  /// Lists the TagBindings for the given Google Cloud resource, as specified
  /// with `parent`.
  ///
  /// NOTE: The `parent` field is expected to be a full resource name:
  /// https://cloud.google.com/apis/design/resource_names#full_resource_name
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.resourcemanager.v3.ListTagBindingsRequest].
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
  ///     [google.cloud.resourcemanager.v3.TagBinding], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.resourcemanager.v3.ListTagBindingsRequest]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L155}
  /// [google.cloud.resourcemanager.v3.TagBinding]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L96}
  ///
  // clang-format on
  StreamRange<google::cloud::resourcemanager::v3::TagBinding> ListTagBindings(
      google::cloud::resourcemanager::v3::ListTagBindingsRequest request,
      Options opts = {});

  // clang-format off
  ///
  /// Creates a TagBinding between a TagValue and a Google Cloud resource.
  ///
  /// @param tag_binding  Required. The TagBinding to be created.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return A [`future`] that becomes satisfied when the LRO
  ///     ([Long Running Operation]) completes or the polling policy in effect
  ///     for this call is exhausted. The future is satisfied with an error if
  ///     the LRO completes with an error or the polling policy is exhausted.
  ///     In this case the [`StatusOr`] returned by the future contains the
  ///     error. If the LRO completes successfully the value of the future
  ///     contains the LRO's result. For this RPC the result is a
  ///     [google.cloud.resourcemanager.v3.TagBinding] proto message.
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
  /// [google.cloud.resourcemanager.v3.CreateTagBindingRequest]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L129}
  /// [google.cloud.resourcemanager.v3.TagBinding]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L96}
  ///
  // clang-format on
  future<StatusOr<google::cloud::resourcemanager::v3::TagBinding>>
  CreateTagBinding(
      google::cloud::resourcemanager::v3::TagBinding const& tag_binding,
      Options opts = {});

  // clang-format off
  ///
  /// Creates a TagBinding between a TagValue and a Google Cloud resource.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.resourcemanager.v3.CreateTagBindingRequest].
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
  ///     [google.cloud.resourcemanager.v3.TagBinding] proto message.
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
  /// [google.cloud.resourcemanager.v3.CreateTagBindingRequest]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L129}
  /// [google.cloud.resourcemanager.v3.TagBinding]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L96}
  ///
  // clang-format on
  future<StatusOr<google::cloud::resourcemanager::v3::TagBinding>>
  CreateTagBinding(
      google::cloud::resourcemanager::v3::CreateTagBindingRequest const&
          request,
      Options opts = {});

  // clang-format off
  ///
  /// Deletes a TagBinding.
  ///
  /// @param name  Required. The name of the TagBinding. This is a String of the form:
  ///  `tagBindings/{id}` (e.g.
  ///  `tagBindings/%2F%2Fcloudresourcemanager.googleapis.com%2Fprojects%2F123/tagValues/456`).
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return A [`future`] that becomes satisfied when the LRO
  ///     ([Long Running Operation]) completes or the polling policy in effect
  ///     for this call is exhausted. The future is satisfied with an error if
  ///     the LRO completes with an error or the polling policy is exhausted.
  ///     In this case the [`StatusOr`] returned by the future contains the
  ///     error. If the LRO completes successfully the value of the future
  ///     contains the LRO's result. For this RPC the result is a
  ///     [google.cloud.resourcemanager.v3.DeleteTagBindingMetadata] proto message.
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
  /// [google.cloud.resourcemanager.v3.DeleteTagBindingMetadata]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L139}
  /// [google.cloud.resourcemanager.v3.DeleteTagBindingRequest]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L142}
  ///
  // clang-format on
  future<StatusOr<google::cloud::resourcemanager::v3::DeleteTagBindingMetadata>>
  DeleteTagBinding(std::string const& name, Options opts = {});

  // clang-format off
  ///
  /// Deletes a TagBinding.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.resourcemanager.v3.DeleteTagBindingRequest].
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
  ///     [google.cloud.resourcemanager.v3.DeleteTagBindingMetadata] proto message.
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
  /// [google.cloud.resourcemanager.v3.DeleteTagBindingMetadata]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L139}
  /// [google.cloud.resourcemanager.v3.DeleteTagBindingRequest]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L142}
  ///
  // clang-format on
  future<StatusOr<google::cloud::resourcemanager::v3::DeleteTagBindingMetadata>>
  DeleteTagBinding(
      google::cloud::resourcemanager::v3::DeleteTagBindingRequest const&
          request,
      Options opts = {});

  // clang-format off
  ///
  /// Return a list of effective tags for the given Google Cloud resource, as
  /// specified in `parent`.
  ///
  /// @param parent  Required. The full resource name of a resource for which you want to list
  ///  the effective tags. E.g.
  ///  "//cloudresourcemanager.googleapis.com/projects/123"
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
  ///     [google.cloud.resourcemanager.v3.EffectiveTag], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.resourcemanager.v3.EffectiveTag]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L234}
  /// [google.cloud.resourcemanager.v3.ListEffectiveTagsRequest]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L194}
  ///
  // clang-format on
  StreamRange<google::cloud::resourcemanager::v3::EffectiveTag>
  ListEffectiveTags(std::string const& parent, Options opts = {});

  // clang-format off
  ///
  /// Return a list of effective tags for the given Google Cloud resource, as
  /// specified in `parent`.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.resourcemanager.v3.ListEffectiveTagsRequest].
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
  ///     [google.cloud.resourcemanager.v3.EffectiveTag], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.resourcemanager.v3.EffectiveTag]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L234}
  /// [google.cloud.resourcemanager.v3.ListEffectiveTagsRequest]: @googleapis_reference_link{google/cloud/resourcemanager/v3/tag_bindings.proto#L194}
  ///
  // clang-format on
  StreamRange<google::cloud::resourcemanager::v3::EffectiveTag>
  ListEffectiveTags(
      google::cloud::resourcemanager::v3::ListEffectiveTagsRequest request,
      Options opts = {});

 private:
  std::shared_ptr<TagBindingsConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace resourcemanager_v3
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RESOURCEMANAGER_V3_TAG_BINDINGS_CLIENT_H

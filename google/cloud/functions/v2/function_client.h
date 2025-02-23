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
// source: google/cloud/functions/v2/functions.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_FUNCTIONS_V2_FUNCTION_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_FUNCTIONS_V2_FUNCTION_CLIENT_H

#include "google/cloud/functions/v2/function_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <map>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace functions_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Google Cloud Functions is used to deploy functions that are executed by
/// Google in response to various events. Data connected with that event is
/// passed to a function as the input data.
///
/// A **function** is a resource which describes a function that should be
/// executed and how it is triggered.
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
class FunctionServiceClient {
 public:
  explicit FunctionServiceClient(
      std::shared_ptr<FunctionServiceConnection> connection, Options opts = {});
  ~FunctionServiceClient();

  ///@{
  /// @name Copy and move support
  FunctionServiceClient(FunctionServiceClient const&) = default;
  FunctionServiceClient& operator=(FunctionServiceClient const&) = default;
  FunctionServiceClient(FunctionServiceClient&&) = default;
  FunctionServiceClient& operator=(FunctionServiceClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(FunctionServiceClient const& a,
                         FunctionServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(FunctionServiceClient const& a,
                         FunctionServiceClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Returns a function with the given name from the requested project.
  ///
  /// @param name  Required. The name of the function which details should be obtained.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.functions.v2.Function])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.functions.v2.Function]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L210}
  /// [google.cloud.functions.v2.GetFunctionRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L811}
  ///
  // clang-format on
  StatusOr<google::cloud::functions::v2::Function> GetFunction(
      std::string const& name, Options opts = {});

  // clang-format off
  ///
  /// Returns a function with the given name from the requested project.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.functions.v2.GetFunctionRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.functions.v2.Function])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.functions.v2.Function]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L210}
  /// [google.cloud.functions.v2.GetFunctionRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L811}
  ///
  // clang-format on
  StatusOr<google::cloud::functions::v2::Function> GetFunction(
      google::cloud::functions::v2::GetFunctionRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Returns a list of functions that belong to the requested project.
  ///
  /// @param parent  Required. The project and location from which the function should be
  ///  listed, specified in the format `projects/*/locations/*` If you want to
  ///  list functions in all locations, use "-" in place of a location. When
  ///  listing functions in all locations, if one or more location(s) are
  ///  unreachable, the response will contain functions from all reachable
  ///  locations along with the names of any unreachable locations.
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
  ///     [google.cloud.functions.v2.Function], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.functions.v2.Function]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L210}
  /// [google.cloud.functions.v2.ListFunctionsRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L822}
  ///
  // clang-format on
  StreamRange<google::cloud::functions::v2::Function> ListFunctions(
      std::string const& parent, Options opts = {});

  // clang-format off
  ///
  /// Returns a list of functions that belong to the requested project.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.functions.v2.ListFunctionsRequest].
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
  ///     [google.cloud.functions.v2.Function], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.functions.v2.Function]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L210}
  /// [google.cloud.functions.v2.ListFunctionsRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L822}
  ///
  // clang-format on
  StreamRange<google::cloud::functions::v2::Function> ListFunctions(
      google::cloud::functions::v2::ListFunctionsRequest request,
      Options opts = {});

  // clang-format off
  ///
  /// Creates a new function. If a function with the given name already exists in
  /// the specified project, the long running operation will return
  /// `ALREADY_EXISTS` error.
  ///
  /// @param parent  Required. The project and location in which the function should be created,
  ///  specified in the format `projects/*/locations/*`
  /// @param function  Required. Function to be created.
  /// @param function_id  The ID to use for the function, which will become the final component of
  ///  the function's resource name.
  ///  @n
  ///  This value should be 4-63 characters, and valid characters
  ///  are /[a-z][0-9]-/.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return A [`future`] that becomes satisfied when the LRO
  ///     ([Long Running Operation]) completes or the polling policy in effect
  ///     for this call is exhausted. The future is satisfied with an error if
  ///     the LRO completes with an error or the polling policy is exhausted.
  ///     In this case the [`StatusOr`] returned by the future contains the
  ///     error. If the LRO completes successfully the value of the future
  ///     contains the LRO's result. For this RPC the result is a
  ///     [google.cloud.functions.v2.Function] proto message.
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
  /// [google.cloud.functions.v2.CreateFunctionRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L873}
  /// [google.cloud.functions.v2.Function]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L210}
  ///
  // clang-format on
  future<StatusOr<google::cloud::functions::v2::Function>> CreateFunction(
      std::string const& parent,
      google::cloud::functions::v2::Function const& function,
      std::string const& function_id, Options opts = {});

  // clang-format off
  ///
  /// Creates a new function. If a function with the given name already exists in
  /// the specified project, the long running operation will return
  /// `ALREADY_EXISTS` error.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.functions.v2.CreateFunctionRequest].
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
  ///     [google.cloud.functions.v2.Function] proto message.
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
  /// [google.cloud.functions.v2.CreateFunctionRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L873}
  /// [google.cloud.functions.v2.Function]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L210}
  ///
  // clang-format on
  future<StatusOr<google::cloud::functions::v2::Function>> CreateFunction(
      google::cloud::functions::v2::CreateFunctionRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Updates existing function.
  ///
  /// @param function  Required. New version of the function.
  /// @param update_mask  The list of fields to be updated.
  ///  If no field mask is provided, all provided fields in the request will be
  ///  updated.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return A [`future`] that becomes satisfied when the LRO
  ///     ([Long Running Operation]) completes or the polling policy in effect
  ///     for this call is exhausted. The future is satisfied with an error if
  ///     the LRO completes with an error or the polling policy is exhausted.
  ///     In this case the [`StatusOr`] returned by the future contains the
  ///     error. If the LRO completes successfully the value of the future
  ///     contains the LRO's result. For this RPC the result is a
  ///     [google.cloud.functions.v2.Function] proto message.
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
  /// [google.cloud.functions.v2.Function]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L210}
  /// [google.cloud.functions.v2.UpdateFunctionRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L895}
  ///
  // clang-format on
  future<StatusOr<google::cloud::functions::v2::Function>> UpdateFunction(
      google::cloud::functions::v2::Function const& function,
      google::protobuf::FieldMask const& update_mask, Options opts = {});

  // clang-format off
  ///
  /// Updates existing function.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.functions.v2.UpdateFunctionRequest].
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
  ///     [google.cloud.functions.v2.Function] proto message.
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
  /// [google.cloud.functions.v2.Function]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L210}
  /// [google.cloud.functions.v2.UpdateFunctionRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L895}
  ///
  // clang-format on
  future<StatusOr<google::cloud::functions::v2::Function>> UpdateFunction(
      google::cloud::functions::v2::UpdateFunctionRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Deletes a function with the given name from the specified project. If the
  /// given function is used by some trigger, the trigger will be updated to
  /// remove this function.
  ///
  /// @param name  Required. The name of the function which should be deleted.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return A [`future`] that becomes satisfied when the LRO
  ///     ([Long Running Operation]) completes or the polling policy in effect
  ///     for this call is exhausted. The future is satisfied with an error if
  ///     the LRO completes with an error or the polling policy is exhausted.
  ///     In this case the [`StatusOr`] returned by the future contains the
  ///     error. If the LRO completes successfully the value of the future
  ///     contains the LRO's result. For this RPC the result is a
  ///     [google.cloud.functions.v2.OperationMetadata] proto message.
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
  /// [google.cloud.functions.v2.DeleteFunctionRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L906}
  /// [google.cloud.functions.v2.OperationMetadata]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L1050}
  ///
  // clang-format on
  future<StatusOr<google::cloud::functions::v2::OperationMetadata>>
  DeleteFunction(std::string const& name, Options opts = {});

  // clang-format off
  ///
  /// Deletes a function with the given name from the specified project. If the
  /// given function is used by some trigger, the trigger will be updated to
  /// remove this function.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.functions.v2.DeleteFunctionRequest].
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
  ///     [google.cloud.functions.v2.OperationMetadata] proto message.
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
  /// [google.cloud.functions.v2.DeleteFunctionRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L906}
  /// [google.cloud.functions.v2.OperationMetadata]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L1050}
  ///
  // clang-format on
  future<StatusOr<google::cloud::functions::v2::OperationMetadata>>
  DeleteFunction(
      google::cloud::functions::v2::DeleteFunctionRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Returns a signed URL for uploading a function source code.
  /// For more information about the signed URL usage see:
  /// https://cloud.google.com/storage/docs/access-control/signed-urls.
  /// Once the function source code upload is complete, the used signed
  /// URL should be provided in CreateFunction or UpdateFunction request
  /// as a reference to the function source code.
  ///
  /// When uploading source code to the generated signed URL, please follow
  /// these restrictions:
  ///
  /// * Source file type should be a zip file.
  /// * No credentials should be attached - the signed URLs provide access to the
  ///   target bucket using internal service identity; if credentials were
  ///   attached, the identity from the credentials would be used, but that
  ///   identity does not have permissions to upload files to the URL.
  ///
  /// When making a HTTP PUT request, these two headers need to be specified:
  ///
  /// * `content-type: application/zip`
  ///
  /// And this header SHOULD NOT be specified:
  ///
  /// * `Authorization: Bearer YOUR_TOKEN`
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.functions.v2.GenerateUploadUrlRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.functions.v2.GenerateUploadUrlResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.functions.v2.GenerateUploadUrlRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L917}
  /// [google.cloud.functions.v2.GenerateUploadUrlResponse]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L948}
  ///
  // clang-format on
  StatusOr<google::cloud::functions::v2::GenerateUploadUrlResponse>
  GenerateUploadUrl(
      google::cloud::functions::v2::GenerateUploadUrlRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Returns a signed URL for downloading deployed function source code.
  /// The URL is only valid for a limited period and should be used within
  /// 30 minutes of generation.
  /// For more information about the signed URL usage see:
  /// https://cloud.google.com/storage/docs/access-control/signed-urls
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.functions.v2.GenerateDownloadUrlRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.functions.v2.GenerateDownloadUrlResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.functions.v2.GenerateDownloadUrlRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L966}
  /// [google.cloud.functions.v2.GenerateDownloadUrlResponse]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L978}
  ///
  // clang-format on
  StatusOr<google::cloud::functions::v2::GenerateDownloadUrlResponse>
  GenerateDownloadUrl(
      google::cloud::functions::v2::GenerateDownloadUrlRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Returns a list of runtimes that are supported for the requested project.
  ///
  /// @param parent  Required. The project and location from which the runtimes should be
  ///  listed, specified in the format `projects/*/locations/*`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.functions.v2.ListRuntimesResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.functions.v2.ListRuntimesRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L985}
  /// [google.cloud.functions.v2.ListRuntimesResponse]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L1001}
  ///
  // clang-format on
  StatusOr<google::cloud::functions::v2::ListRuntimesResponse> ListRuntimes(
      std::string const& parent, Options opts = {});

  // clang-format off
  ///
  /// Returns a list of runtimes that are supported for the requested project.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.functions.v2.ListRuntimesRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.functions.v2.ListRuntimesResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.functions.v2.ListRuntimesRequest]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L985}
  /// [google.cloud.functions.v2.ListRuntimesResponse]: @googleapis_reference_link{google/cloud/functions/v2/functions.proto#L1001}
  ///
  // clang-format on
  StatusOr<google::cloud::functions::v2::ListRuntimesResponse> ListRuntimes(
      google::cloud::functions::v2::ListRuntimesRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<FunctionServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace functions_v2
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_FUNCTIONS_V2_FUNCTION_CLIENT_H

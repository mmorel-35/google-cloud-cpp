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
// source: google/cloud/beyondcorp/appconnectors/v1/app_connectors_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_APPCONNECTORS_V1_INTERNAL_APP_CONNECTORS_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_APPCONNECTORS_V1_INTERNAL_APP_CONNECTORS_STUB_H

#include "google/cloud/completion_queue.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/beyondcorp/appconnectors/v1/app_connectors_service.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace beyondcorp_appconnectors_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class AppConnectorsServiceStub {
 public:
  virtual ~AppConnectorsServiceStub() = 0;

  virtual StatusOr<
      google::cloud::beyondcorp::appconnectors::v1::ListAppConnectorsResponse>
  ListAppConnectors(grpc::ClientContext& context,
                    google::cloud::beyondcorp::appconnectors::v1::
                        ListAppConnectorsRequest const& request) = 0;

  virtual StatusOr<google::cloud::beyondcorp::appconnectors::v1::AppConnector>
  GetAppConnector(grpc::ClientContext& context,
                  google::cloud::beyondcorp::appconnectors::v1::
                      GetAppConnectorRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncCreateAppConnector(google::cloud::CompletionQueue& cq,
                          std::shared_ptr<grpc::ClientContext> context,
                          Options const& options,
                          google::cloud::beyondcorp::appconnectors::v1::
                              CreateAppConnectorRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncUpdateAppConnector(google::cloud::CompletionQueue& cq,
                          std::shared_ptr<grpc::ClientContext> context,
                          Options const& options,
                          google::cloud::beyondcorp::appconnectors::v1::
                              UpdateAppConnectorRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncDeleteAppConnector(google::cloud::CompletionQueue& cq,
                          std::shared_ptr<grpc::ClientContext> context,
                          Options const& options,
                          google::cloud::beyondcorp::appconnectors::v1::
                              DeleteAppConnectorRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncReportStatus(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::beyondcorp::appconnectors::v1::ReportStatusRequest const&
          request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::GetOperationRequest const& request) = 0;

  virtual future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::CancelOperationRequest const& request) = 0;
};

class DefaultAppConnectorsServiceStub : public AppConnectorsServiceStub {
 public:
  DefaultAppConnectorsServiceStub(
      std::unique_ptr<google::cloud::beyondcorp::appconnectors::v1::
                          AppConnectorsService::StubInterface>
          grpc_stub,
      std::unique_ptr<google::longrunning::Operations::StubInterface>
          operations)
      : grpc_stub_(std::move(grpc_stub)), operations_(std::move(operations)) {}

  StatusOr<
      google::cloud::beyondcorp::appconnectors::v1::ListAppConnectorsResponse>
  ListAppConnectors(grpc::ClientContext& client_context,
                    google::cloud::beyondcorp::appconnectors::v1::
                        ListAppConnectorsRequest const& request) override;

  StatusOr<google::cloud::beyondcorp::appconnectors::v1::AppConnector>
  GetAppConnector(grpc::ClientContext& client_context,
                  google::cloud::beyondcorp::appconnectors::v1::
                      GetAppConnectorRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateAppConnector(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::beyondcorp::appconnectors::v1::
          CreateAppConnectorRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateAppConnector(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::beyondcorp::appconnectors::v1::
          UpdateAppConnectorRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteAppConnector(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::beyondcorp::appconnectors::v1::
          DeleteAppConnectorRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncReportStatus(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::beyondcorp::appconnectors::v1::ReportStatusRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::unique_ptr<google::cloud::beyondcorp::appconnectors::v1::
                      AppConnectorsService::StubInterface>
      grpc_stub_;
  std::unique_ptr<google::longrunning::Operations::StubInterface> operations_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace beyondcorp_appconnectors_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_APPCONNECTORS_V1_INTERNAL_APP_CONNECTORS_STUB_H

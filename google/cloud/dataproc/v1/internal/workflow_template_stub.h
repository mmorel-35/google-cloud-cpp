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
// source: google/cloud/dataproc/v1/workflow_templates.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPROC_V1_INTERNAL_WORKFLOW_TEMPLATE_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPROC_V1_INTERNAL_WORKFLOW_TEMPLATE_STUB_H

#include "google/cloud/completion_queue.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/dataproc/v1/workflow_templates.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dataproc_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class WorkflowTemplateServiceStub {
 public:
  virtual ~WorkflowTemplateServiceStub() = 0;

  virtual StatusOr<google::cloud::dataproc::v1::WorkflowTemplate>
  CreateWorkflowTemplate(
      grpc::ClientContext& context,
      google::cloud::dataproc::v1::CreateWorkflowTemplateRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::dataproc::v1::WorkflowTemplate>
  GetWorkflowTemplate(
      grpc::ClientContext& context,
      google::cloud::dataproc::v1::GetWorkflowTemplateRequest const&
          request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncInstantiateWorkflowTemplate(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::dataproc::v1::InstantiateWorkflowTemplateRequest const&
          request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>>
  AsyncInstantiateInlineWorkflowTemplate(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::dataproc::v1::
          InstantiateInlineWorkflowTemplateRequest const& request) = 0;

  virtual StatusOr<google::cloud::dataproc::v1::WorkflowTemplate>
  UpdateWorkflowTemplate(
      grpc::ClientContext& context,
      google::cloud::dataproc::v1::UpdateWorkflowTemplateRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::dataproc::v1::ListWorkflowTemplatesResponse>
  ListWorkflowTemplates(
      grpc::ClientContext& context,
      google::cloud::dataproc::v1::ListWorkflowTemplatesRequest const&
          request) = 0;

  virtual Status DeleteWorkflowTemplate(
      grpc::ClientContext& context,
      google::cloud::dataproc::v1::DeleteWorkflowTemplateRequest const&
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

class DefaultWorkflowTemplateServiceStub : public WorkflowTemplateServiceStub {
 public:
  DefaultWorkflowTemplateServiceStub(
      std::unique_ptr<
          google::cloud::dataproc::v1::WorkflowTemplateService::StubInterface>
          grpc_stub,
      std::unique_ptr<google::longrunning::Operations::StubInterface>
          operations)
      : grpc_stub_(std::move(grpc_stub)), operations_(std::move(operations)) {}

  StatusOr<google::cloud::dataproc::v1::WorkflowTemplate>
  CreateWorkflowTemplate(
      grpc::ClientContext& client_context,
      google::cloud::dataproc::v1::CreateWorkflowTemplateRequest const& request)
      override;

  StatusOr<google::cloud::dataproc::v1::WorkflowTemplate> GetWorkflowTemplate(
      grpc::ClientContext& client_context,
      google::cloud::dataproc::v1::GetWorkflowTemplateRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncInstantiateWorkflowTemplate(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::dataproc::v1::InstantiateWorkflowTemplateRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncInstantiateInlineWorkflowTemplate(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::cloud::dataproc::v1::
          InstantiateInlineWorkflowTemplateRequest const& request) override;

  StatusOr<google::cloud::dataproc::v1::WorkflowTemplate>
  UpdateWorkflowTemplate(
      grpc::ClientContext& client_context,
      google::cloud::dataproc::v1::UpdateWorkflowTemplateRequest const& request)
      override;

  StatusOr<google::cloud::dataproc::v1::ListWorkflowTemplatesResponse>
  ListWorkflowTemplates(
      grpc::ClientContext& client_context,
      google::cloud::dataproc::v1::ListWorkflowTemplatesRequest const& request)
      override;

  Status DeleteWorkflowTemplate(
      grpc::ClientContext& client_context,
      google::cloud::dataproc::v1::DeleteWorkflowTemplateRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context, Options const& options,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::unique_ptr<
      google::cloud::dataproc::v1::WorkflowTemplateService::StubInterface>
      grpc_stub_;
  std::unique_ptr<google::longrunning::Operations::StubInterface> operations_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataproc_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPROC_V1_INTERNAL_WORKFLOW_TEMPLATE_STUB_H

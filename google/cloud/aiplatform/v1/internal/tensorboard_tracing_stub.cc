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
// source: google/cloud/aiplatform/v1/tensorboard_service.proto

#include "google/cloud/aiplatform/v1/internal/tensorboard_tracing_stub.h"
#include "google/cloud/internal/grpc_opentelemetry.h"
#include "google/cloud/internal/streaming_read_rpc_tracing.h"
#include <utility>

namespace google {
namespace cloud {
namespace aiplatform_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

TensorboardServiceTracingStub::TensorboardServiceTracingStub(
    std::shared_ptr<TensorboardServiceStub> child)
    : child_(std::move(child)), propagator_(internal::MakePropagator()) {}

future<StatusOr<google::longrunning::Operation>>
TensorboardServiceTracingStub::AsyncCreateTensorboard(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::CreateTensorboardRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.TensorboardService", "CreateTensorboard");
  internal::OTelScope scope(span);
  internal::InjectTraceContext(*context, *propagator_);
  auto f =
      child_->AsyncCreateTensorboard(cq, context, std::move(options), request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

StatusOr<google::cloud::aiplatform::v1::Tensorboard>
TensorboardServiceTracingStub::GetTensorboard(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetTensorboardRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.TensorboardService", "GetTensorboard");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(context, *span,
                           child_->GetTensorboard(context, options, request));
}

future<StatusOr<google::longrunning::Operation>>
TensorboardServiceTracingStub::AsyncUpdateTensorboard(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::UpdateTensorboardRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.TensorboardService", "UpdateTensorboard");
  internal::OTelScope scope(span);
  internal::InjectTraceContext(*context, *propagator_);
  auto f =
      child_->AsyncUpdateTensorboard(cq, context, std::move(options), request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

StatusOr<google::cloud::aiplatform::v1::ListTensorboardsResponse>
TensorboardServiceTracingStub::ListTensorboards(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListTensorboardsRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.TensorboardService", "ListTensorboards");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(context, *span,
                           child_->ListTensorboards(context, options, request));
}

future<StatusOr<google::longrunning::Operation>>
TensorboardServiceTracingStub::AsyncDeleteTensorboard(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::DeleteTensorboardRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.TensorboardService", "DeleteTensorboard");
  internal::OTelScope scope(span);
  internal::InjectTraceContext(*context, *propagator_);
  auto f =
      child_->AsyncDeleteTensorboard(cq, context, std::move(options), request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

StatusOr<google::cloud::aiplatform::v1::ReadTensorboardUsageResponse>
TensorboardServiceTracingStub::ReadTensorboardUsage(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ReadTensorboardUsageRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.TensorboardService", "ReadTensorboardUsage");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span, child_->ReadTensorboardUsage(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::ReadTensorboardSizeResponse>
TensorboardServiceTracingStub::ReadTensorboardSize(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ReadTensorboardSizeRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.TensorboardService", "ReadTensorboardSize");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span, child_->ReadTensorboardSize(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::TensorboardExperiment>
TensorboardServiceTracingStub::CreateTensorboardExperiment(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::CreateTensorboardExperimentRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "CreateTensorboardExperiment");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->CreateTensorboardExperiment(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::TensorboardExperiment>
TensorboardServiceTracingStub::GetTensorboardExperiment(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetTensorboardExperimentRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "GetTensorboardExperiment");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->GetTensorboardExperiment(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::TensorboardExperiment>
TensorboardServiceTracingStub::UpdateTensorboardExperiment(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::UpdateTensorboardExperimentRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "UpdateTensorboardExperiment");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->UpdateTensorboardExperiment(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::ListTensorboardExperimentsResponse>
TensorboardServiceTracingStub::ListTensorboardExperiments(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListTensorboardExperimentsRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "ListTensorboardExperiments");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->ListTensorboardExperiments(context, options, request));
}

future<StatusOr<google::longrunning::Operation>>
TensorboardServiceTracingStub::AsyncDeleteTensorboardExperiment(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::DeleteTensorboardExperimentRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "DeleteTensorboardExperiment");
  internal::OTelScope scope(span);
  internal::InjectTraceContext(*context, *propagator_);
  auto f = child_->AsyncDeleteTensorboardExperiment(
      cq, context, std::move(options), request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

StatusOr<google::cloud::aiplatform::v1::TensorboardRun>
TensorboardServiceTracingStub::CreateTensorboardRun(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::CreateTensorboardRunRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.TensorboardService", "CreateTensorboardRun");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span, child_->CreateTensorboardRun(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::BatchCreateTensorboardRunsResponse>
TensorboardServiceTracingStub::BatchCreateTensorboardRuns(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::BatchCreateTensorboardRunsRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "BatchCreateTensorboardRuns");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->BatchCreateTensorboardRuns(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::TensorboardRun>
TensorboardServiceTracingStub::GetTensorboardRun(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetTensorboardRunRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.TensorboardService", "GetTensorboardRun");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span, child_->GetTensorboardRun(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::TensorboardRun>
TensorboardServiceTracingStub::UpdateTensorboardRun(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::UpdateTensorboardRunRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.TensorboardService", "UpdateTensorboardRun");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span, child_->UpdateTensorboardRun(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::ListTensorboardRunsResponse>
TensorboardServiceTracingStub::ListTensorboardRuns(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListTensorboardRunsRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.TensorboardService", "ListTensorboardRuns");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span, child_->ListTensorboardRuns(context, options, request));
}

future<StatusOr<google::longrunning::Operation>>
TensorboardServiceTracingStub::AsyncDeleteTensorboardRun(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::DeleteTensorboardRunRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.TensorboardService", "DeleteTensorboardRun");
  internal::OTelScope scope(span);
  internal::InjectTraceContext(*context, *propagator_);
  auto f = child_->AsyncDeleteTensorboardRun(cq, context, std::move(options),
                                             request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

StatusOr<
    google::cloud::aiplatform::v1::BatchCreateTensorboardTimeSeriesResponse>
TensorboardServiceTracingStub::BatchCreateTensorboardTimeSeries(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::
        BatchCreateTensorboardTimeSeriesRequest const& request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "BatchCreateTensorboardTimeSeries");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->BatchCreateTensorboardTimeSeries(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::TensorboardTimeSeries>
TensorboardServiceTracingStub::CreateTensorboardTimeSeries(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::CreateTensorboardTimeSeriesRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "CreateTensorboardTimeSeries");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->CreateTensorboardTimeSeries(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::TensorboardTimeSeries>
TensorboardServiceTracingStub::GetTensorboardTimeSeries(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::GetTensorboardTimeSeriesRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "GetTensorboardTimeSeries");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->GetTensorboardTimeSeries(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::TensorboardTimeSeries>
TensorboardServiceTracingStub::UpdateTensorboardTimeSeries(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::UpdateTensorboardTimeSeriesRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "UpdateTensorboardTimeSeries");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->UpdateTensorboardTimeSeries(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::ListTensorboardTimeSeriesResponse>
TensorboardServiceTracingStub::ListTensorboardTimeSeries(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ListTensorboardTimeSeriesRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "ListTensorboardTimeSeries");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->ListTensorboardTimeSeries(context, options, request));
}

future<StatusOr<google::longrunning::Operation>>
TensorboardServiceTracingStub::AsyncDeleteTensorboardTimeSeries(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::aiplatform::v1::DeleteTensorboardTimeSeriesRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "DeleteTensorboardTimeSeries");
  internal::OTelScope scope(span);
  internal::InjectTraceContext(*context, *propagator_);
  auto f = child_->AsyncDeleteTensorboardTimeSeries(
      cq, context, std::move(options), request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

StatusOr<
    google::cloud::aiplatform::v1::BatchReadTensorboardTimeSeriesDataResponse>
TensorboardServiceTracingStub::BatchReadTensorboardTimeSeriesData(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::
        BatchReadTensorboardTimeSeriesDataRequest const& request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "BatchReadTensorboardTimeSeriesData");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->BatchReadTensorboardTimeSeriesData(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::ReadTensorboardTimeSeriesDataResponse>
TensorboardServiceTracingStub::ReadTensorboardTimeSeriesData(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ReadTensorboardTimeSeriesDataRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "ReadTensorboardTimeSeriesData");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->ReadTensorboardTimeSeriesData(context, options, request));
}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<
    google::cloud::aiplatform::v1::ReadTensorboardBlobDataResponse>>
TensorboardServiceTracingStub::ReadTensorboardBlobData(
    std::shared_ptr<grpc::ClientContext> context, Options const& options,
    google::cloud::aiplatform::v1::ReadTensorboardBlobDataRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "ReadTensorboardBlobData");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(*context, *propagator_);
  auto stream = child_->ReadTensorboardBlobData(context, options, request);
  return std::make_unique<internal::StreamingReadRpcTracing<
      google::cloud::aiplatform::v1::ReadTensorboardBlobDataResponse>>(
      std::move(context), std::move(stream), std::move(span));
}

StatusOr<google::cloud::aiplatform::v1::WriteTensorboardExperimentDataResponse>
TensorboardServiceTracingStub::WriteTensorboardExperimentData(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::WriteTensorboardExperimentDataRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "WriteTensorboardExperimentData");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->WriteTensorboardExperimentData(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::WriteTensorboardRunDataResponse>
TensorboardServiceTracingStub::WriteTensorboardRunData(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::WriteTensorboardRunDataRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "WriteTensorboardRunData");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->WriteTensorboardRunData(context, options, request));
}

StatusOr<google::cloud::aiplatform::v1::ExportTensorboardTimeSeriesDataResponse>
TensorboardServiceTracingStub::ExportTensorboardTimeSeriesData(
    grpc::ClientContext& context, Options const& options,
    google::cloud::aiplatform::v1::ExportTensorboardTimeSeriesDataRequest const&
        request) {
  auto span =
      internal::MakeSpanGrpc("google.cloud.aiplatform.v1.TensorboardService",
                             "ExportTensorboardTimeSeriesData");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(
      context, *span,
      child_->ExportTensorboardTimeSeriesData(context, options, request));
}

future<StatusOr<google::longrunning::Operation>>
TensorboardServiceTracingStub::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::GetOperationRequest const& request) {
  auto span =
      internal::MakeSpanGrpc("google.longrunning.Operations", "GetOperation");
  internal::OTelScope scope(span);
  internal::InjectTraceContext(*context, *propagator_);
  auto f = child_->AsyncGetOperation(cq, context, std::move(options), request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

future<Status> TensorboardServiceTracingStub::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::CancelOperationRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.longrunning.Operations",
                                     "CancelOperation");
  internal::OTelScope scope(span);
  internal::InjectTraceContext(*context, *propagator_);
  auto f =
      child_->AsyncCancelOperation(cq, context, std::move(options), request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<TensorboardServiceStub> MakeTensorboardServiceTracingStub(
    std::shared_ptr<TensorboardServiceStub> stub) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return std::make_shared<TensorboardServiceTracingStub>(std::move(stub));
#else
  return stub;
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1_internal
}  // namespace cloud
}  // namespace google

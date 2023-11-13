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
// source: google/cloud/aiplatform/v1/prediction_service.proto

#include "google/cloud/aiplatform/v1/internal/prediction_tracing_stub.h"
#include "google/cloud/internal/grpc_opentelemetry.h"
#include "google/cloud/internal/streaming_read_rpc_tracing.h"

namespace google {
namespace cloud {
namespace aiplatform_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

PredictionServiceTracingStub::PredictionServiceTracingStub(
    std::shared_ptr<PredictionServiceStub> child)
    : child_(std::move(child)), propagator_(internal::MakePropagator()) {}

StatusOr<google::cloud::aiplatform::v1::PredictResponse>
PredictionServiceTracingStub::Predict(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::PredictRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.PredictionService", "Predict");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(context, *span, child_->Predict(context, request));
}

StatusOr<google::api::HttpBody> PredictionServiceTracingStub::RawPredict(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::RawPredictRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.PredictionService", "RawPredict");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(context, *span,
                           child_->RawPredict(context, request));
}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<
    google::cloud::aiplatform::v1::StreamingPredictResponse>>
PredictionServiceTracingStub::ServerStreamingPredict(
    std::shared_ptr<grpc::ClientContext> context, Options const& options,
    google::cloud::aiplatform::v1::StreamingPredictRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.PredictionService", "ServerStreamingPredict");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(*context, *propagator_);
  auto stream = child_->ServerStreamingPredict(context, options, request);
  return std::make_unique<internal::StreamingReadRpcTracing<
      google::cloud::aiplatform::v1::StreamingPredictResponse>>(
      std::move(context), std::move(stream), std::move(span));
}

StatusOr<google::cloud::aiplatform::v1::ExplainResponse>
PredictionServiceTracingStub::Explain(
    grpc::ClientContext& context,
    google::cloud::aiplatform::v1::ExplainRequest const& request) {
  auto span = internal::MakeSpanGrpc(
      "google.cloud.aiplatform.v1.PredictionService", "Explain");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, *propagator_);
  return internal::EndSpan(context, *span, child_->Explain(context, request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<PredictionServiceStub> MakePredictionServiceTracingStub(
    std::shared_ptr<PredictionServiceStub> stub) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return std::make_shared<PredictionServiceTracingStub>(std::move(stub));
#else
  return stub;
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1_internal
}  // namespace cloud
}  // namespace google

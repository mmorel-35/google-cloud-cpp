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
// source: google/cloud/dialogflow/cx/v3/test_case.proto

#include "google/cloud/dialogflow_cx/internal/test_cases_connection_impl.h"
#include "google/cloud/dialogflow_cx/internal/test_cases_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

TestCasesConnectionImpl::TestCasesConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<dialogflow_cx_internal::TestCasesStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options), dialogflow_cx_internal::TestCasesDefaultOptions(
                                  TestCasesConnection::options()))) {}

StreamRange<google::cloud::dialogflow::cx::v3::TestCase>
TestCasesConnectionImpl::ListTestCases(
    google::cloud::dialogflow::cx::v3::ListTestCasesRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry = std::shared_ptr<dialogflow_cx::TestCasesRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListTestCases(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::dialogflow::cx::v3::TestCase>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::dialogflow::cx::v3::ListTestCasesRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](
                grpc::ClientContext& context,
                google::cloud::dialogflow::cx::v3::ListTestCasesRequest const&
                    request) { return stub->ListTestCases(context, request); },
            r, function_name);
      },
      [](google::cloud::dialogflow::cx::v3::ListTestCasesResponse r) {
        std::vector<google::cloud::dialogflow::cx::v3::TestCase> result(
            r.test_cases().size());
        auto& messages = *r.mutable_test_cases();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

Status TestCasesConnectionImpl::BatchDeleteTestCases(
    google::cloud::dialogflow::cx::v3::BatchDeleteTestCasesRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->BatchDeleteTestCases(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::dialogflow::cx::v3::BatchDeleteTestCasesRequest const&
              request) {
        return stub_->BatchDeleteTestCases(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::dialogflow::cx::v3::TestCase>
TestCasesConnectionImpl::GetTestCase(
    google::cloud::dialogflow::cx::v3::GetTestCaseRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetTestCase(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::GetTestCaseRequest const&
                 request) { return stub_->GetTestCase(context, request); },
      request, __func__);
}

StatusOr<google::cloud::dialogflow::cx::v3::TestCase>
TestCasesConnectionImpl::CreateTestCase(
    google::cloud::dialogflow::cx::v3::CreateTestCaseRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateTestCase(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::CreateTestCaseRequest const&
                 request) { return stub_->CreateTestCase(context, request); },
      request, __func__);
}

StatusOr<google::cloud::dialogflow::cx::v3::TestCase>
TestCasesConnectionImpl::UpdateTestCase(
    google::cloud::dialogflow::cx::v3::UpdateTestCaseRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateTestCase(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::UpdateTestCaseRequest const&
                 request) { return stub_->UpdateTestCase(context, request); },
      request, __func__);
}

future<StatusOr<google::cloud::dialogflow::cx::v3::RunTestCaseResponse>>
TestCasesConnectionImpl::RunTestCase(
    google::cloud::dialogflow::cx::v3::RunTestCaseRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::dialogflow::cx::v3::RunTestCaseResponse>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::dialogflow::cx::v3::RunTestCaseRequest const&
                 request) {
        return stub->AsyncRunTestCase(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::dialogflow::cx::v3::RunTestCaseResponse>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->RunTestCase(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::dialogflow::cx::v3::BatchRunTestCasesResponse>>
TestCasesConnectionImpl::BatchRunTestCases(
    google::cloud::dialogflow::cx::v3::BatchRunTestCasesRequest const&
        request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::dialogflow::cx::v3::BatchRunTestCasesResponse>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::dialogflow::cx::v3::BatchRunTestCasesRequest const&
                 request) {
        return stub->AsyncBatchRunTestCases(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::dialogflow::cx::v3::BatchRunTestCasesResponse>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->BatchRunTestCases(request), polling_policy(),
      __func__);
}

StatusOr<google::cloud::dialogflow::cx::v3::CalculateCoverageResponse>
TestCasesConnectionImpl::CalculateCoverage(
    google::cloud::dialogflow::cx::v3::CalculateCoverageRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CalculateCoverage(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::CalculateCoverageRequest const&
                 request) {
        return stub_->CalculateCoverage(context, request);
      },
      request, __func__);
}

future<StatusOr<google::cloud::dialogflow::cx::v3::ImportTestCasesResponse>>
TestCasesConnectionImpl::ImportTestCases(
    google::cloud::dialogflow::cx::v3::ImportTestCasesRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::dialogflow::cx::v3::ImportTestCasesResponse>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::dialogflow::cx::v3::ImportTestCasesRequest const&
                 request) {
        return stub->AsyncImportTestCases(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::dialogflow::cx::v3::ImportTestCasesResponse>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->ImportTestCases(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::dialogflow::cx::v3::ExportTestCasesResponse>>
TestCasesConnectionImpl::ExportTestCases(
    google::cloud::dialogflow::cx::v3::ExportTestCasesRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::dialogflow::cx::v3::ExportTestCasesResponse>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::dialogflow::cx::v3::ExportTestCasesRequest const&
                 request) {
        return stub->AsyncExportTestCases(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::dialogflow::cx::v3::ExportTestCasesResponse>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->ExportTestCases(request), polling_policy(),
      __func__);
}

StreamRange<google::cloud::dialogflow::cx::v3::TestCaseResult>
TestCasesConnectionImpl::ListTestCaseResults(
    google::cloud::dialogflow::cx::v3::ListTestCaseResultsRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry = std::shared_ptr<dialogflow_cx::TestCasesRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListTestCaseResults(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::dialogflow::cx::v3::TestCaseResult>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::dialogflow::cx::v3::ListTestCaseResultsRequest const&
              r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::dialogflow::cx::v3::
                       ListTestCaseResultsRequest const& request) {
              return stub->ListTestCaseResults(context, request);
            },
            r, function_name);
      },
      [](google::cloud::dialogflow::cx::v3::ListTestCaseResultsResponse r) {
        std::vector<google::cloud::dialogflow::cx::v3::TestCaseResult> result(
            r.test_case_results().size());
        auto& messages = *r.mutable_test_case_results();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::dialogflow::cx::v3::TestCaseResult>
TestCasesConnectionImpl::GetTestCaseResult(
    google::cloud::dialogflow::cx::v3::GetTestCaseResultRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetTestCaseResult(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::GetTestCaseResultRequest const&
                 request) {
        return stub_->GetTestCaseResult(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google

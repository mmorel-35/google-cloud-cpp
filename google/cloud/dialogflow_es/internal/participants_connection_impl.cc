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
// source: google/cloud/dialogflow/v2/participant.proto

#include "google/cloud/dialogflow_es/internal/participants_connection_impl.h"
#include "google/cloud/dialogflow_es/internal/participants_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ParticipantsConnectionImpl::ParticipantsConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<dialogflow_es_internal::ParticipantsStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options),
          dialogflow_es_internal::ParticipantsDefaultOptions(
              ParticipantsConnection::options()))) {}

StatusOr<google::cloud::dialogflow::v2::Participant>
ParticipantsConnectionImpl::CreateParticipant(
    google::cloud::dialogflow::v2::CreateParticipantRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateParticipant(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::v2::CreateParticipantRequest const&
                 request) {
        return stub_->CreateParticipant(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::dialogflow::v2::Participant>
ParticipantsConnectionImpl::GetParticipant(
    google::cloud::dialogflow::v2::GetParticipantRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetParticipant(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::dialogflow::v2::GetParticipantRequest const& request) {
        return stub_->GetParticipant(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::dialogflow::v2::Participant>
ParticipantsConnectionImpl::ListParticipants(
    google::cloud::dialogflow::v2::ListParticipantsRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry = std::shared_ptr<dialogflow_es::ParticipantsRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListParticipants(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::dialogflow::v2::Participant>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::dialogflow::v2::ListParticipantsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::dialogflow::v2::ListParticipantsRequest const&
                       request) {
              return stub->ListParticipants(context, request);
            },
            r, function_name);
      },
      [](google::cloud::dialogflow::v2::ListParticipantsResponse r) {
        std::vector<google::cloud::dialogflow::v2::Participant> result(
            r.participants().size());
        auto& messages = *r.mutable_participants();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::dialogflow::v2::Participant>
ParticipantsConnectionImpl::UpdateParticipant(
    google::cloud::dialogflow::v2::UpdateParticipantRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateParticipant(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::v2::UpdateParticipantRequest const&
                 request) {
        return stub_->UpdateParticipant(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::dialogflow::v2::AnalyzeContentResponse>
ParticipantsConnectionImpl::AnalyzeContent(
    google::cloud::dialogflow::v2::AnalyzeContentRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->AnalyzeContent(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::dialogflow::v2::AnalyzeContentRequest const& request) {
        return stub_->AnalyzeContent(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::dialogflow::v2::SuggestArticlesResponse>
ParticipantsConnectionImpl::SuggestArticles(
    google::cloud::dialogflow::v2::SuggestArticlesRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->SuggestArticles(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::v2::SuggestArticlesRequest const&
                 request) { return stub_->SuggestArticles(context, request); },
      request, __func__);
}

StatusOr<google::cloud::dialogflow::v2::SuggestFaqAnswersResponse>
ParticipantsConnectionImpl::SuggestFaqAnswers(
    google::cloud::dialogflow::v2::SuggestFaqAnswersRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->SuggestFaqAnswers(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::v2::SuggestFaqAnswersRequest const&
                 request) {
        return stub_->SuggestFaqAnswers(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::dialogflow::v2::SuggestSmartRepliesResponse>
ParticipantsConnectionImpl::SuggestSmartReplies(
    google::cloud::dialogflow::v2::SuggestSmartRepliesRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->SuggestSmartReplies(request),
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::v2::SuggestSmartRepliesRequest const&
                 request) {
        return stub_->SuggestSmartReplies(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google

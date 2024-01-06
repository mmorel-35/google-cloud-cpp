// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/pubsub/admin/topic_admin_client.h"
#include "google/cloud/pubsub/blocking_publisher.h"
#include "google/cloud/pubsub/testing/random_names.h"
#include "google/cloud/pubsub/testing/test_retry_policies.h"
#include "google/cloud/pubsub/version.h"
#include "google/cloud/credentials.h"
#include "google/cloud/internal/getenv.h"
#include "google/cloud/internal/random.h"
#include "google/cloud/testing_util/integration_test.h"
#include "google/cloud/testing_util/opentelemetry_matchers.h"
#include "google/cloud/testing_util/status_matchers.h"
#include <gmock/gmock.h>
#include <algorithm>

namespace google {
namespace cloud {
namespace pubsub {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace {

using ::google::cloud::testing_util::IsOk;
using ::google::cloud::testing_util::StatusIs;
using ::testing::AnyOf;

class BlockingPublisherIntegrationTest
    : public ::google::cloud::testing_util::IntegrationTest {
 protected:
  void SetUp() override {
    auto project_id =
        google::cloud::internal::GetEnv("GOOGLE_CLOUD_PROJECT").value_or("");
    ASSERT_FALSE(project_id.empty());
    generator_ = google::cloud::internal::DefaultPRNG(std::random_device{}());
    topic_ = Topic(project_id, pubsub_testing::RandomTopicId(generator_));

    auto topic_admin = pubsub_admin::TopicAdminClient(
        pubsub_admin::MakeTopicAdminConnection());
    auto topic_metadata = topic_admin.CreateTopic(topic_.FullName());
    ASSERT_THAT(topic_metadata,
                AnyOf(IsOk(), StatusIs(StatusCode::kAlreadyExists)));
  }

  void TearDown() override {
    auto topic_admin = pubsub_admin::TopicAdminClient(
        pubsub_admin::MakeTopicAdminConnection());
    auto delete_topic = topic_admin.DeleteTopic(topic_.FullName());
    EXPECT_THAT(delete_topic, AnyOf(IsOk(), StatusIs(StatusCode::kNotFound)));
  }

  google::cloud::internal::DefaultPRNG generator_;
  Topic topic_ = Topic("unused", "unused");
};

TEST_F(BlockingPublisherIntegrationTest, Basic) {
  auto publisher = BlockingPublisher(MakeBlockingPublisherConnection());
  auto publish =
      publisher.Publish(topic_, MessageBuilder().SetData("test data").Build());
  ASSERT_STATUS_OK(publish);
}

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
using ::google::cloud::testing_util::DisableTracing;
using ::google::cloud::testing_util::EnableTracing;

TEST_F(BlockingPublisherIntegrationTest, TracingEnabled) {
  auto publisher = BlockingPublisher(
      MakeBlockingPublisherConnection(EnableTracing(Options{})));
  auto publish =
      publisher.Publish(topic_, MessageBuilder().SetData("test data").Build());
  ASSERT_STATUS_OK(publish);
}

TEST_F(BlockingPublisherIntegrationTest, TracingDisabled) {
  auto publisher = BlockingPublisher(
      MakeBlockingPublisherConnection(DisableTracing(Options{})));
  auto publish =
      publisher.Publish(topic_, MessageBuilder().SetData("test data").Build());
  ASSERT_STATUS_OK(publish);
}
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

}  // namespace
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub
}  // namespace cloud
}  // namespace google

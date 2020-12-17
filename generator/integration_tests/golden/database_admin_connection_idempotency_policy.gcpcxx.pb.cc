// Copyright 2020 Google LLC
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
// source: generator/integration_tests/test.proto
#include "generator/integration_tests/golden/database_admin_connection_idempotency_policy.gcpcxx.pb.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace golden {
inline namespace GOOGLE_CLOUD_CPP_NS {

using google::cloud::internal::Idempotency;

DatabaseAdminConnectionIdempotencyPolicy::~DatabaseAdminConnectionIdempotencyPolicy() = default;

namespace {
class DefaultDatabaseAdminConnectionIdempotencyPolicy : public DatabaseAdminConnectionIdempotencyPolicy {
 public:
  ~DefaultDatabaseAdminConnectionIdempotencyPolicy() override = default;

  /// Create a new copy of this object.
  std::unique_ptr<DatabaseAdminConnectionIdempotencyPolicy> clone() const override {
    return absl::make_unique<DefaultDatabaseAdminConnectionIdempotencyPolicy>(*this);
  }

  Idempotency
  ListDatabases(::google::test::admin::database::v1::ListDatabasesRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency
  CreateDatabase(::google::test::admin::database::v1::CreateDatabaseRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency
  GetDatabase(::google::test::admin::database::v1::GetDatabaseRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency
  UpdateDatabaseDdl(::google::test::admin::database::v1::UpdateDatabaseDdlRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency
  DropDatabase(::google::test::admin::database::v1::DropDatabaseRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency
  GetDatabaseDdl(::google::test::admin::database::v1::GetDatabaseDdlRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency
  SetIamPolicy(::google::iam::v1::SetIamPolicyRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency
  GetIamPolicy(::google::iam::v1::GetIamPolicyRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency
  TestIamPermissions(::google::iam::v1::TestIamPermissionsRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency
  CreateBackup(::google::test::admin::database::v1::CreateBackupRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency
  GetBackup(::google::test::admin::database::v1::GetBackupRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency
  UpdateBackup(::google::test::admin::database::v1::UpdateBackupRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency
  DeleteBackup(::google::test::admin::database::v1::DeleteBackupRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency
  ListBackups(::google::test::admin::database::v1::ListBackupsRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency
  RestoreDatabase(::google::test::admin::database::v1::RestoreDatabaseRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency
  ListDatabaseOperations(::google::test::admin::database::v1::ListDatabaseOperationsRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency
  ListBackupOperations(::google::test::admin::database::v1::ListBackupOperationsRequest) override {
    return Idempotency::kIdempotent;
  }

};
}  // namespace

std::unique_ptr<DatabaseAdminConnectionIdempotencyPolicy>
    MakeDefaultDatabaseAdminConnectionIdempotencyPolicy() {
  return absl::make_unique<DefaultDatabaseAdminConnectionIdempotencyPolicy>();
}

}  // namespace GOOGLE_CLOUD_CPP_NS
}  // namespace golden
}  // namespace cloud
}  // namespace google


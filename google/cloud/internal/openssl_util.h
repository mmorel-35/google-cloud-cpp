// Copyright 2018 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_OPENSSL_UTIL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_OPENSSL_UTIL_H

#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <cstdint>
#include <string>
#include <vector>

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {

/**
 * Signs a string with the private key from a PEM container.
 *
 * @return Returns the signature as an *unencoded* byte array. The caller
 *   might want to use `Base64Encode()` or `HexEncode()` to convert this byte
 *   array to a format more suitable for transmission over HTTP.
 */
StatusOr<std::vector<std::uint8_t>> SignUsingSha256(
    std::string const& str, std::string const& pem_contents);

}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_OPENSSL_UTIL_H

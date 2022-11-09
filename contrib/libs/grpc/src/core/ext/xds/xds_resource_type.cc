//
// Copyright 2021 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <grpc/support/port_platform.h>

#include "src/core/ext/xds/xds_resource_type.h"

namespace grpc_core {

bool XdsResourceType::IsType(y_absl::string_view resource_type,
                             bool* is_v2) const {
  if (resource_type == type_url()) return true;
  if (resource_type == v2_type_url()) {
    if (is_v2 != nullptr) *is_v2 = true;
    return true;
  }
  return false;
}

}  // namespace grpc_core
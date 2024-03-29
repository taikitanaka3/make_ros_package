// Copyright 2023 Tier IV, Inc. All rights reserved.
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

#include "package_name/package_name.hpp"
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(test, package_name_test) {
    auto node = std::make_shared<PackageName>();
    rclcpp::WallRate loop_rate(10);
    auto end_time = node->now() + rclcpp::Duration(10, 0);
    size_t i = 0;
    while (node->now() < end_time) {
        RCLCPP_WARN_THROTTLE(
          node->get_logger(), *(node->get_clock()), 1000, " (i: %ld).", i+1);
        rclcpp::spin_some(node);
        loop_rate.sleep();
        i++;
    }
}

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


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

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std_msgs::msg::String;

class PackageName : public rclcpp::Node {
public:
  PackageName();

private:
  void timerCallback();
  void topicCallback(const String::SharedPtr msg) const;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<String>::SharedPtr publisher_;
  rclcpp::Subscription<String>::SharedPtr subscriber_;
};

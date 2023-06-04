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

#include "example/example.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

Example::Example() : Node("example_node") {
  publisher_ = this->create_publisher<String>("topic", 10);
  subscriber_ = this->create_subscription<String>(
      "topic", 10, std::bind(&Example::topicCallback, this, _1));
  timer_ = this->create_wall_timer(
      1000ms, std::bind(&Example::timerCallback, this));
}

void Example::timerCallback() {
  auto message = std_msgs::msg::String();
  message.data = "Hello, world! ";
  publisher_->publish(message);
  RCLCPP_INFO(this->get_logger(), "I say: '%s'", message.data.c_str());
}

void Example::topicCallback(const String::SharedPtr msg) const {
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Example>());
  rclcpp::shutdown();
  return 0;
}

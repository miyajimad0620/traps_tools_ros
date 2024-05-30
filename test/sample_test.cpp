// Copyright 2024 TRAPS
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

#include "gtest/gtest.h"
#include "rclcpp/rclcpp.hpp"
#include "traps_tools_ros/dynamic_qos.hpp"
#include "traps_tools_ros/msg/sample_string.hpp"
#include "traps_tools_ros/sample/node.hpp"

TEST(sample, string_republish)
{
  auto test_node = std::make_shared<rclcpp::Node>("test");
  traps_tools_ros::msg::SampleString::ConstSharedPtr republish_msg;
  auto sample_string_subscription =
    test_node->create_subscription<traps_tools_ros::msg::SampleString>(
    "sample/republish_string", traps_tools_ros::dynamic_qos(),
    [&republish_msg,
    &test_node](traps_tools_ros::msg::SampleString::ConstSharedPtr republish_msg_arg) {
      republish_msg = std::move(republish_msg_arg);
    });
  auto sample_string_publisher = test_node->create_publisher<traps_tools_ros::msg::SampleString>(
    "sample/string", traps_tools_ros::dynamic_qos());

  auto sample_node = std::make_shared<traps_tools_ros::sample::Node>();

  traps_tools_ros::msg::SampleString sample_string_msg;
  sample_string_msg.data = "sample_test";
  sample_string_publisher->publish(sample_string_msg);

  rclcpp::spin_some(test_node);    // publish "sample/string"
  rclcpp::spin_some(sample_node);  // subscribe "sample/string" & publish "sample/string"
  rclcpp::spin_some(test_node);    // subscribe "sample/string"

  ASSERT_TRUE(republish_msg) << "Couldn't subscribe \"sample/republish_string\"";
  if (!republish_msg) {
    return;
  }
  EXPECT_EQ(republish_msg->data, "sample_test")
    << "The value that subscribed to \"sample/republish_string\" was " << republish_msg->data
    << ", but it is actually " << sample_string_msg.data;
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  rclcpp::init(argc, argv);
  auto result = RUN_ALL_TESTS();
  rclcpp::shutdown();
  return result;
}

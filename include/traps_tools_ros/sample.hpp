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

#ifndef TRAPS_TOOLS_ROS__SAMPLE_HPP_
#define TRAPS_TOOLS_ROS__SAMPLE_HPP_

#include "traps_tools_ros/msg/sample_string.hpp"

namespace traps_tools_ros
{

class Sample
{
public:
  static traps_tools_ros::msg::SampleString sample_string_msg_from_ptr(
    traps_tools_ros::msg::SampleString::ConstSharedPtr sample_string_msg);
};

}  // namespace traps_tools_ros

#endif  // TRAPS_TOOLS_ROS__SAMPLE_HPP_

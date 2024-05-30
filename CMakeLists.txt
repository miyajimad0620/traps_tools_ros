# Copyright 2024 TRAPS

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

#     http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.8)
project(traps_tools_ros)

add_compile_options(-O2)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

file(GLOB interface_files
  LIST_DIRECTORIES false
  RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
  "msg/*")
rosidl_generate_interfaces("${PROJECT_NAME}"
  "${interface_files}"
  DEPENDENCIES "${${PROJECT_NAME}_FOUND_BUILD_DEPENDS}")
rosidl_get_typesupport_target(cpp_typesupport_target "${PROJECT_NAME}" "rosidl_typesupport_cpp")

file(GLOB_RECURSE "${PROJECT_NAME}_lib_files"
  LIST_DIRECTORIES false
  RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
  "src/*/*")
ament_auto_add_library("${PROJECT_NAME}_lib" SHARED "${${PROJECT_NAME}_lib_files}")
target_compile_features("${PROJECT_NAME}_lib" PUBLIC c_std_99 cxx_std_17)
target_link_libraries("${PROJECT_NAME}_lib" "${cpp_typesupport_target}")

set(execs sample;${TRAPS_TOOLS_EXECS})
foreach(exec IN LISTS execs)
  rclcpp_components_register_node("${PROJECT_NAME}_lib"
    PLUGIN "${PROJECT_NAME}::${exec}::Node"
    EXECUTABLE ${exec})
endforeach()

install(DIRECTORY
  config
  launch
  DESTINATION share/${PROJECT_NAME}/)

if(BUILD_TESTING)
  ament_auto_find_test_dependencies()
  ament_lint_auto_find_test_dependencies()
  ament_auto_add_gtest(sample_test test/sample_test.cpp)
endif()

ament_auto_package()

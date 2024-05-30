<!-- Copyright 2024 TRAPS

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. -->

# [traps_tools_ros](./README.md)

## 使用方法

### ドッカーを使用する
```bash
docker run --rm --net=host --ipc=host --hostname=traps -it ghcr.io/TRAPS-RoboCup/traps_tools_ros
```

### ソースからビルドする

#### サポートOS
- ubuntu 22.04

#### 必須パッケージ
- git
- ros-humble-ros-base
- colcon

#### 1. クローン
```bash
mkdir -p ~/ros2_ws/src && \
cd ~/ros2_ws/src && \
git clone https://github.com/TRAPS-RoboCup/traps_tools_ros.git \
cd ..
```
#### 2. ビルド
```bash
. /opt/ros/humble/setup.sh && colcon build
```

## [ドキュメント](doc/index.md)
- [component](doc/component/index.md)
- [executor](doc/executor/index.md)
- [launch](doc/launch/index.md)
- [msg](doc/msg/index.md)
- [srv](doc/srv/index.md)
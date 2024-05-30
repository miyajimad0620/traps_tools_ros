# [traps_tools_ros](../../README.md)/[launch](index.md)/[sample_launch.xml](sample_launch.xml.md)

自分でlaunchを作成するときに参考にするためのサンプル。

## 引数
| 引数 | 型 | 説明 | デフォルト値 |
| - | - | - | - |
| namespace | string | 名前空間 | "$(env HOSTNAME)" |
| use_sim_time | bool | sim_timeを使うかどうかを決める | false |
| params_file | string | params_fileのパス | "$(find-pkg-share traps_tools_ros)/config/sample_params.yaml" |
| use_composition | bool | ノードを全て同じプロセスで実行するか決める | true |
| respawn | bool | プロセスが終了したときに再起動するか | true |
| log_level | string | 出力するログレベル | "info" |

# 含まれるexecutor
- [sample](../executor/sample.md) (if use_composition=false)
- rclcpp_components::component_container (if use_composition=true)

# 含まれるコンポーネント (if use_composition=true)
- [traps_tools::sample::Node](../component/traps_tools__sample__node.md)

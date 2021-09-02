#! /usr/bin/env sh
echo "Logging started..."
rostopic echo /scan > ~/radar_ws/ros_logs/lidar_log.txt
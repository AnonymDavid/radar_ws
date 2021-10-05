#!/bin/bash

roscore &
P1=$!
sleep 5s
rosrun radar_conti radar_conti &
P2=$!
rosrun rviz_markers egolf &
P3=$!
roslaunch rplidar_ros rplidar_and_radar.launch
P4=$!

wait $P1 $P2 $P3 $P4
#!/bin/bash

roscore &
P1=$!
sleep 5s
roslaunch rplidar_ros rplidar_and_radar.launch
P2=$!

wait $P1 $P2
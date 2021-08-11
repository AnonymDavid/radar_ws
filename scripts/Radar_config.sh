#!/bin/bash

cd ~/radar_ws
catkin build socketcan_bridge

roscore &
P1=$!
sleep 5s
rosrun socketcan_bridge socketcan_to_topic_node _can_device:="can1" &
P2=$!
rosrun socketcan_bridge topic_to_socketcan_node _can_device:="can1" &
sleep 1s
P3=$!
rosrun socketcan_bridge configuration_node
P4=$!

kill $P2
kill $P3
kill $P1
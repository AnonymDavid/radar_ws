#!/bin/bash

if [ $1 != "" ] && [ -d `dirname "$1"` ]
then
	~/radar_ws/scripts/runRaL.sh &
	P4=$!
	sleep 10s
	rosbag record -O $1 /scan /radar_objects_marker
	P5=$!
	
	wait $P4 $P5
else
	echo "Path doesn't exists"
fi
#!/bin/bash

if [ $1 != "" ] && [ -d `dirname "$1"` ]
then
	~/radar_ws/scripts/runRaL.sh &
	P6=$!
	sleep 10s
	rosbag record -O $1 -a
	P7=$!
	
	wait $P6 $P7
else
	echo "Path doesn't exists"
fi
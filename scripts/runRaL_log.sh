#!/bin/bash

if [ $1 != "" ] && [ -d `dirname "$1"` ]
then
	~/radar_ws/scripts/runRaL.sh &
	P100=$!
	sleep 10s
	rosbag record -O $1 -a
	P101=$!
	
	wait $P100 $P101
else
	echo "Path doesn't exists"
fi
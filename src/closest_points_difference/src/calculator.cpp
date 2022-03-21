#include <ros/ros.h>
#include "std_msgs/String.h"
#include <fstream>

ros::Publisher pub_difference;
double radarDistance;
double lidarDistance;

void radarDataCallback(const std_msgs::String::ConstPtr& msg)
{
    radarDistance = std:stod(msg->data);
    calculateDifference();
}

void lidarDataCallback(const std_msgs::String::ConstPtr& msg)
{
    lidarDistance = std:stod(msg->data);
    calculateDifference();
}

void calculateDifference()
{
    if(radarDistance != -1 && lidarDistance != -1) {
        ROS_INFO("R - L closest: %lf - %lf", radarDistance, lidarDistance);

        //TODO: make marker -> publish to topic

        radarDistance = -1;
        lidarDistance = -1;
    }
}

int main( int argc, char** argv )
{
    ros::init(argc, argv, "difference_calculator");
    ros::NodeHandle nh;

    radarDistance = -1;
    lidarDistance = -1;

    ros::Publisher radar_closest = nh.subscribe("/radar_closest_marker", 100, radarDataCallback);
    ros::Publisher lidar_closest = nh.subscribe("/lidar_closest_distance", 100, lidarDataCallback);
    
    ROS_INFO("Difference calculator - ROS OK");
    
    ros::spin();

    return 0;
}
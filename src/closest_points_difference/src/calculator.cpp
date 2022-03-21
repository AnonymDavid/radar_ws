#include <ros/ros.h>
#include "std_msgs/String.h"
#include <fstream>

ros::Publisher pub_difference;
double radarDistance;
double lidarDistance;


void calculateDifference()
{
        ROS_INFO("R - L closest: %lf - %lf", radarDistance, lidarDistance);

    if(radarDistance != -1 && lidarDistance != -1) {
        ROS_INFO("R - L closest: %lf - %lf", radarDistance, lidarDistance);

        //TODO: make marker -> publish to topic

        radarDistance = -1;
        lidarDistance = -1;
    }
}


void radarDataCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("RADAR DATA: %s", msg->data.c_str());
    //radarDistance = std::stod(msg->data.c_str());
    //calculateDifference();
}

void lidarDataCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("LIDAR: %s", msg->data.c_str());
    //lidarDistance = std::stod(msg->data.c_str());
    //calculateDifference();
}

int main( int argc, char** argv )
{
    ros::init(argc, argv, "difference_calculator");
    ros::NodeHandle nh;

    radarDistance = -1;
    lidarDistance = -1;

    ros::Subscriber radar_closest = nh.subscribe("radar_closest_distance", 100, radarDataCallback);
    ros::Subscriber lidar_closest = nh.subscribe("lidar_closest_distance", 100, lidarDataCallback);
    
    ROS_INFO("Difference calculator - ROS OK");
    
    ros::spin();

    return 0;
}
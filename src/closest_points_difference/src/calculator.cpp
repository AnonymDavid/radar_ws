#include <ros/ros.h>
#include <std_msgs/String.h>
#include <visualization_msgs/Marker.h>
#include <tf2/LinearMath/Quaternion.h>

#include <iostream>
#include <string>
#include <stdlib.h>


ros::Publisher pub_difference;
double radarDistance;
double lidarDistance;

void setToDefault() {
    radarDistance = -1;
    lidarDistance = -1;
}

void differencePublisher()
{
    if(radarDistance != -1 && lidarDistance != -1) {
        //ROS_INFO("R - L closest: %lf - %lf", radarDistance, lidarDistance);
        visualization_msgs::Marker marker;
        tf2::Quaternion myQuaternion;

        marker.header.stamp = ros::Time::now();
        marker.header.frame_id = "/radar_lidar_closest_difference";
        marker.ns = "text";
        marker.id = 999;
        marker.type = 9;
        marker.action = 0;
        marker.pose.position.x = -5;
        marker.pose.position.y =  0;
        marker.pose.position.z = -3;

        myQuaternion.setRPY(0, 0, 0);
        marker.pose.orientation.w = myQuaternion.getW();
        marker.pose.orientation.x = myQuaternion.getX();
        marker.pose.orientation.y = myQuaternion.getY();
        marker.pose.orientation.z = myQuaternion.getZ();
        marker.scale.z = 1.0;
        marker.color.r = 1.0;
        marker.color.g = 1.0;
        marker.color.b = 1.0;
        marker.color.a = 1.0;
        marker.lifetime = ros::Duration(0.25);
        marker.frame_locked = false;

        double difference = abs(radarDistance - lidarDistance);
        
        std::stringstream ss;
        ss.precision(2);
        ss << std::fixed << "Radar-LIDAR closest point difference: " << difference << " m";
        marker.text = ss.str();

        pub_difference.publish(marker);

        setToDefault();
    }
}


void radarDataCallback(const std_msgs::String::ConstPtr& msg)
{
    //ROS_INFO("RADAR DATA: %s", msg->data.c_str());
    radarDistance = std::atof(msg->data.c_str());
    differencePublisher();
}

void lidarDataCallback(const std_msgs::String::ConstPtr& msg)
{
    //ROS_INFO("LIDAR: %s", msg->data.c_str());
    lidarDistance = std::atof(msg->data.c_str());
    differencePublisher();
}

int main( int argc, char** argv )
{
    ros::init(argc, argv, "difference_calculator");
    ros::NodeHandle nh;

    radarDistance = -1;
    lidarDistance = -1;

    pub_difference = nh.advertise<visualization_msgs::Marker>("radar_lidar_closest_difference",0);
    ros::Subscriber radar_closest = nh.subscribe("radar_closest_distance", 100, radarDataCallback);
    ros::Subscriber lidar_closest = nh.subscribe("lidar_closest_distance", 100, lidarDataCallback);
    
    ROS_INFO("Difference calculator - ROS OK");
    
    ros::spin();

    return 0;
}
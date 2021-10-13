#ifndef COMPOSITION__RADAR_CONTI_ARS408_COMPONENT_HPP_
#define COMPOSITION__RADAR_CONTI_ARS408_COMPONENT_HPP_

#include <iostream>
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include "ars_408_can_defines.h"
#include <socketcan_interface/socketcan.h>
#include <socketcan_interface/threading.h>
#include <socketcan_interface/string.h>
#include <can_msgs/Frame.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf/transform_broadcaster.h>

#include <radar_conti/ObjectList.h>
#include <radar_conti/ClusterList.h>
#include <radar_conti/RadarState.h>
#include <radar_conti/ClusterStatus.h>
#include <radar_conti/Frame.h>
#include <radar_conti/CollisonObj.h>
#include <radar_conti/CollisonList.h>

#include <data.h>

#include <chrono>
#include <iostream>
#include <memory>
#include <utility>
#include <math.h>
#include <cstddef>
#include <set>
#include <stdlib.h>



typedef unsigned char ubyte;
typedef unsigned short int uword;

class Radar_Conti
{
public:
    Radar_Conti(const ros::NodeHandle &nh);
    ~Radar_Conti() = default;
    //create can_receive_callback
    void can_frame_callback(const can::Frame &msg);
    void init(can::DriverInterfaceSharedPtr &driver_);

private:
    //Speed threshold
    unsigned short speed_threshold = 3;
    bool is_speed_in_threshold(double object_speed);
    

    // GPS Speed
    ros::NodeHandle n_; 
    ros::Publisher pub_;
    bool is_integer(float dec);
    void send_GPS_speed();
    void send_GPS_yaw();
    bool is_gps_speed_sending = true;
    int send_gps_speed = 2;

    ros::NodeHandle nh;
    //create CAN channel object
    can::DriverInterfaceSharedPtr driver_;
    can::FrameListenerConstSharedPtr frame_listener_;
    //can::DriverInterfaceSharedPtr radar_can_output;
    //create Publisher
    ros::Publisher pub_marker;
    ros::Publisher pub_objects;
    ros::Publisher pub_cluster;
    ros::Publisher pub_cluster_list;
    ros::Publisher pub_marker_with_all_data;
    ros::Publisher pub_gps_data;
    ros::Publisher pub_closest_marker;
    ros::Publisher collison_obj_pub;
    std::string pub_marker_array_topic_name = "/ars408/marker_array";
    // std::string pub_object_list_topic_name = "/ars408/objectlist";
    // std::string pub_tf_topic_name = "/tf";
    std::string frame_id_ = "/radar";
    
    void handle_cluster_list(const can::Frame &msg);

    //create handle_object_list
    void handle_object_list(const can::Frame &msg);

    //create publish_object_map
    void publish_object_map();
    double prob_of_exist_data(int data);

    void publish_cluster_map();
    //create map container for object list
    std::map<int,radar_conti::Object> object_map_;

    double gps_speed = 0;
    double gps_altitude = 0;
    double gps_true_course = 0;
    double gps_satelites = 0;
    double gps_valid = 0;

    double gps_yaw_x = 0;
    double gps_yaw_y = 0;
    double gps_yaw_z = 0;

    std::map<int, radar_conti::Cluster> cluster_map_;

    std::set<int> collison_objects;
    

    //create data structures for radar object list
    radar_conti::CollisonList coll_list;
    radar_conti::ObjectList object_list_;
    radar_conti::ClusterList cluster_list;

    //additional variables
    int operation_mode_;

    //Object Classes in strings
    const std::string object_classes[8] = {"Point","Car","Truck","Pedestrian","Motorcycle","Bicycle","Wide","Reserved"};
};

#endif  // COMPOSITION__RADAR_CONTI_ARS408_COMPONENT_HPP_
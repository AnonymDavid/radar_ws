/*
 *  RPLIDAR ROS NODE
 *
 *  Copyright (c) 2009 - 2014 RoboPeak Team
 *  http://www.robopeak.com
 *  Copyright (c) 2014 - 2016 Shanghai Slamtec Co., Ltd.
 *  http://www.slamtec.com
 *
 */
/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "std_srvs/Empty.h"
#include "rplidar.h"
#include <visualization_msgs/MarkerArray.h>
#include <visualization_msgs/Marker.h>
#include <tf2/LinearMath/Quaternion.h>
#include <math.h> 

#ifndef _countof
#define _countof(_Array) (int)(sizeof(_Array) / sizeof(_Array[0]))
#endif

#define DEG2RAD(x) ((x)*M_PI/180.)

//Lidar important data
#define DEGREE_THRESHOLD DEG2RAD(20.0)

using namespace rp::standalone::rplidar;

RPlidarDriver * drv = NULL;

static int closest_id = 0;
ros::Publisher scan_pub;
ros::Publisher scan_important_pub;
ros::Publisher closest_point_pub;

sensor_msgs::LaserScan create_msg_header(size_t node_count, ros::Time start,
                  double scan_time, float angle_min, float angle_max,
                  float max_distance, std::string frame_id)
{
    sensor_msgs::LaserScan scan_msg;

    scan_msg.header.stamp = start;
    scan_msg.header.frame_id = frame_id;

    bool reversed = (angle_max > angle_min);
    if ( reversed ) {
        scan_msg.angle_min =  M_PI - angle_max;
        scan_msg.angle_max =  M_PI - angle_min;
    } else {
        scan_msg.angle_min =  M_PI - angle_min;
        scan_msg.angle_max =  M_PI - angle_max;
    }
    scan_msg.angle_increment =
        (scan_msg.angle_max - scan_msg.angle_min) / (double)(node_count-1);

    scan_msg.scan_time = scan_time;
    scan_msg.time_increment = scan_time / (double)(node_count-1);
    scan_msg.range_min = 0.15;
    scan_msg.range_max = max_distance;//8.0;

    scan_msg.intensities.resize(node_count);
    scan_msg.ranges.resize(node_count);

    return scan_msg;
}

void publish_closest_point(double pos_x, double pos_y, double distance)
{
        visualization_msgs::MarkerArray marker_array;
        visualization_msgs::Marker closest_text;
        visualization_msgs::Marker closest_point;

        tf2::Quaternion myQuaternion;
        myQuaternion.setRPY(0, 0, 0);

        closest_point.header.stamp = ros::Time::now();
        closest_point.header.frame_id = "/lidar_closest_point";
        closest_point.ns = "objects";
        closest_point.id = 998;
        closest_point.type = 1; //Cube
        closest_point.action = 0; // add/modify

        closest_point.pose.position.x = pos_x;
        closest_point.pose.position.y = pos_y;
        closest_point.pose.position.z = 0.0;
        closest_point.pose.orientation.w = myQuaternion.getW();
        closest_point.pose.orientation.x = myQuaternion.getX();
        closest_point.pose.orientation.y = myQuaternion.getY();
        closest_point.pose.orientation.z = myQuaternion.getZ();
        closest_point.scale.x = 0.3;
        closest_point.scale.y = 0.3;
        closest_point.scale.z = 0.3;

        closest_point.color.r = 0;
        closest_point.color.g = 255;
        closest_point.color.b = 0;
        closest_point.color.a = 0.6;
        closest_point.lifetime = ros::Duration(0.25);
        closest_point.frame_locked = false;

        closest_text.header.stamp = ros::Time::now();
        closest_text.header.frame_id = "/lidar_closest_point";
        closest_text.ns = "text";
        closest_text.id = 998;
        closest_text.type = 9; // Text
        closest_text.action = 0; // add/modify

        closest_text.pose.position.x = -4;
        closest_text.pose.position.y = 0;
        closest_text.pose.position.z = -3; //4.0
        closest_text.pose.orientation.w = myQuaternion.getW();
        closest_text.pose.orientation.x = myQuaternion.getX();
        closest_text.pose.orientation.y = myQuaternion.getY();
        closest_text.pose.orientation.z = myQuaternion.getZ();
        closest_text.scale.z = 1.0;

        closest_text.color.r = 1.0;
        closest_text.color.g = 1.0;
        closest_text.color.b = 1.0;
        closest_text.color.a = 1.0;
        closest_text.lifetime = ros::Duration(0.25);
        closest_text.frame_locked = false;
        
        std::stringstream ss2;
        ss2.precision(2);
        ss2 << std::fixed << "Lidar closest point: " << distance << " m";
        closest_text.text = ss2.str();


        marker_array.markers.push_back(closest_point);
        marker_array.markers.push_back(closest_text);
        closest_point_pub.publish(marker_array);
}

void publish_scan(rplidar_response_measurement_node_hq_t *nodes, size_t node_count,
                    ros::Time start,double scan_time, bool inverted,
                    float angle_min, float angle_max,
                    float max_distance, std::string frame_id)
{
    sensor_msgs::LaserScan scan_msg = create_msg_header(node_count, start, scan_time, 
                                                    angle_min, angle_max, max_distance, frame_id);

    sensor_msgs::LaserScan scan_msg_important = create_msg_header(node_count, start, scan_time, 
                                                    angle_min, angle_max, max_distance, frame_id);

    short closest_point_id = -1;

    bool reversed = (angle_max > angle_min);
    bool reverse_data = (!inverted && reversed) || (inverted && !reversed);
    if (!reverse_data) {
        for (size_t i = 0; i < node_count; i++) {
            float degree = i * scan_msg.angle_increment;
            float read_value = (float) nodes[i].dist_mm_q2/4.0f/1000;
            if (read_value == 0.0) {
                scan_msg.ranges[i] = std::numeric_limits<float>::infinity();
                scan_msg_important.ranges[i] = std::numeric_limits<float>::infinity();

                scan_msg.intensities[i] = (float) (nodes[i].quality >> 2);
                scan_msg_important.intensities[i] = (float) (nodes[i].quality >> 2);
            }
            else {
                if (degree < 0 + DEGREE_THRESHOLD || degree > DEG2RAD(360.0f) - DEGREE_THRESHOLD) {
                    scan_msg.ranges[i] = std::numeric_limits<float>::infinity();
                    scan_msg_important.ranges[i] = read_value;

                    scan_msg.intensities[i] = 0.0;
                    scan_msg_important.intensities[i] = (float) (nodes[i].quality >> 2);

                    if (closest_point_id == -1 || read_value < scan_msg_important.ranges[closest_point_id])
                        closest_point_id = i;
                }
                else {
                    scan_msg.ranges[i] = read_value;
                    scan_msg_important.ranges[i] = std::numeric_limits<float>::infinity();

                    scan_msg.intensities[i] = (float) (nodes[i].quality >> 2);
                    scan_msg_important.intensities[i] = 0.0;
                }
            }
        }
    } else {
        for (size_t i = 0; i < node_count; i++) {
            float degree = i * scan_msg.angle_increment;
            float read_value = (float)nodes[i].dist_mm_q2/4.0f/1000;

            if (read_value == 0.0) {
                scan_msg.ranges[node_count-1-i] = std::numeric_limits<float>::infinity();
                scan_msg_important.ranges[node_count-1-i] = std::numeric_limits<float>::infinity();

                scan_msg.intensities[node_count-1-i] = (float) (nodes[i].quality >> 2);
                scan_msg_important.intensities[node_count-1-i] = (float) (nodes[i].quality >> 2);
            }
            else {
                if (degree < 0 + DEGREE_THRESHOLD || degree > DEG2RAD(360) - DEGREE_THRESHOLD) {
                    scan_msg.ranges[node_count-1-i] = std::numeric_limits<float>::infinity();
                    scan_msg_important.ranges[node_count-1-i] = read_value;

                    scan_msg.intensities[node_count-1-i] = 0.0;
                    scan_msg_important.intensities[node_count-1-i] = (float) (nodes[i].quality >> 2);

                    if (closest_point_id == -1 || read_value < scan_msg_important.ranges[closest_point_id])
                        closest_point_id = node_count-1-i;
                }
                else {
                    scan_msg.ranges[node_count-1-i] = read_value;
                    scan_msg_important.ranges[node_count-1-i] = std::numeric_limits<float>::infinity();

                    scan_msg.intensities[node_count-1-i] = (float) (nodes[i].quality >> 2);
                    scan_msg_important.intensities[node_count-1-i] = 0.0;
                }

                
            }

        }
    }

    if (closest_point_id != -1) {
        float distance = scan_msg_important.ranges[closest_point_id];
        float pos_x, pos_y;
        if(closest_point_id == 0) {
            pos_x = scan_msg_important.ranges[closest_point_id];
            pos_y = 0;
        }
        else {
            float degree = closest_point_id * scan_msg_important.angle_increment;
            pos_y = sin(degree) * distance;
            pos_x = cos(degree) * distance;
        }
        publish_closest_point(pos_x, pos_y, distance);
    }

    scan_pub.publish(scan_msg);
    scan_important_pub.publish(scan_msg_important);
}

bool getRPLIDARDeviceInfo(RPlidarDriver * drv)
{
    u_result     op_result;
    rplidar_response_device_info_t devinfo;

    op_result = drv->getDeviceInfo(devinfo);
    if (IS_FAIL(op_result)) {
        if (op_result == RESULT_OPERATION_TIMEOUT) {
            ROS_ERROR("Error, operation time out. RESULT_OPERATION_TIMEOUT! ");
        } else {
            ROS_ERROR("Error, unexpected error, code: %x",op_result);
        }
        return false;
    }

    // print out the device serial number, firmware and hardware version number..
    printf("RPLIDAR S/N: ");
    for (int pos = 0; pos < 16 ;++pos) {
        printf("%02X", devinfo.serialnum[pos]);
    }
    printf("\n");
    ROS_INFO("Firmware Ver: %d.%02d",devinfo.firmware_version>>8, devinfo.firmware_version & 0xFF);
    ROS_INFO("Hardware Rev: %d",(int)devinfo.hardware_version);
    return true;
}

bool checkRPLIDARHealth(RPlidarDriver * drv)
{
    u_result     op_result;
    rplidar_response_device_health_t healthinfo;
    op_result = drv->getHealth(healthinfo);
    if (IS_OK(op_result)) { 
        ROS_INFO("RPLidar health status : %d", healthinfo.status);
        if (healthinfo.status == RPLIDAR_STATUS_ERROR) {
            ROS_ERROR("Error, rplidar internal error detected. Please reboot the device to retry.");
            return false;
        } else {
            return true;
        }

    } else {
        ROS_ERROR("Error, cannot retrieve rplidar health code: %x", op_result);
        return false;
    }
}

bool stop_motor(std_srvs::Empty::Request &req,
                               std_srvs::Empty::Response &res)
{
  if(!drv)
       return false;

  ROS_DEBUG("Stop motor");
  drv->stopMotor();
  return true;
}

bool start_motor(std_srvs::Empty::Request &req,
                               std_srvs::Empty::Response &res)
{
  if(!drv)
       return false;
  if(drv->isConnected())
  {
      ROS_DEBUG("Start motor");
      u_result ans=drv->startMotor();
  
      ans=drv->startScan(0,1);
   }
   else ROS_INFO("lost connection");
  return true;
}

static float getAngle(const rplidar_response_measurement_node_hq_t& node)
{
    return node.angle_z_q14 * 90.f / 16384.f;
}

int main(int argc, char * argv[]) {
    ros::init(argc, argv, "rplidar_node");
    ros::NodeHandle nh;

    scan_pub = nh.advertise<sensor_msgs::LaserScan>("scan", 1000);
    scan_important_pub = nh.advertise<sensor_msgs::LaserScan>("scan_important", 1000); //Lidar important data
    closest_point_pub = nh.advertise<visualization_msgs::MarkerArray>("closest_point", 1000);
    

    std::string channel_type;
    std::string tcp_ip;
    std::string serial_port;
    int tcp_port = 20108;
    int serial_baudrate = 115200;
    std::string frame_id;
    bool inverted = false;
    bool angle_compensate = true;
    float max_distance = 8.0;
    int angle_compensate_multiple = 1;//it stand of angle compensate at per 1 degree
    std::string scan_mode;
    
    ros::NodeHandle nh_private("~");
    nh_private.param<std::string>("channel_type", channel_type, "serial");
    nh_private.param<std::string>("tcp_ip", tcp_ip, "192.168.0.7"); 
    nh_private.param<int>("tcp_port", tcp_port, 20108);
    nh_private.param<std::string>("serial_port", serial_port, "/dev/ttyUSB0"); 
    nh_private.param<int>("serial_baudrate", serial_baudrate, 115200/*256000*/);//ros run for A1 A2, change to 256000 if A3
    nh_private.param<std::string>("frame_id", frame_id, "laser_frame");
    nh_private.param<bool>("inverted", inverted, false);
    nh_private.param<bool>("angle_compensate", angle_compensate, false);
    nh_private.param<std::string>("scan_mode", scan_mode, std::string());

    ROS_INFO("RPLIDAR running on ROS package rplidar_ros. SDK Version:"RPLIDAR_SDK_VERSION"");

    u_result     op_result;

    // create the driver instance
    if(channel_type == "tcp"){
        drv = RPlidarDriver::CreateDriver(rp::standalone::rplidar::DRIVER_TYPE_TCP);
    }
    else{
        drv = RPlidarDriver::CreateDriver(rp::standalone::rplidar::DRIVER_TYPE_SERIALPORT);
    }

    
    if (!drv) {
        ROS_ERROR("Create Driver fail, exit");
        return -2;
    }

    if(channel_type == "tcp"){
        // make connection...
        if (IS_FAIL(drv->connect(tcp_ip.c_str(), (_u32)tcp_port))) {
            ROS_ERROR("Error, cannot bind to the specified serial port %s.",serial_port.c_str());
            RPlidarDriver::DisposeDriver(drv);
            return -1;
        }

    }
    else{
       // make connection...
        if (IS_FAIL(drv->connect(serial_port.c_str(), (_u32)serial_baudrate))) {
            ROS_ERROR("Error, cannot bind to the specified serial port %s.",serial_port.c_str());
            RPlidarDriver::DisposeDriver(drv);
            return -1;
        }

    }
    
    // get rplidar device info
    if (!getRPLIDARDeviceInfo(drv)) {
        return -1;
    }

    // check health...
    if (!checkRPLIDARHealth(drv)) {
        RPlidarDriver::DisposeDriver(drv);
        return -1;
    }

    ros::ServiceServer stop_motor_service = nh.advertiseService("stop_motor", stop_motor);
    ros::ServiceServer start_motor_service = nh.advertiseService("start_motor", start_motor);

    drv->startMotor();

    RplidarScanMode current_scan_mode;
    if (scan_mode.empty()) {
        op_result = drv->startScan(false /* not force scan */, true /* use typical scan mode */, 0, &current_scan_mode);
    } else {
        std::vector<RplidarScanMode> allSupportedScanModes;
        op_result = drv->getAllSupportedScanModes(allSupportedScanModes);

        if (IS_OK(op_result)) {
            _u16 selectedScanMode = _u16(-1);
            for (std::vector<RplidarScanMode>::iterator iter = allSupportedScanModes.begin(); iter != allSupportedScanModes.end(); iter++) {
                if (iter->scan_mode == scan_mode) {
                    selectedScanMode = iter->id;
                    break;
                }
            }

            if (selectedScanMode == _u16(-1)) {
                ROS_ERROR("scan mode `%s' is not supported by lidar, supported modes:", scan_mode.c_str());
                for (std::vector<RplidarScanMode>::iterator iter = allSupportedScanModes.begin(); iter != allSupportedScanModes.end(); iter++) {
                    ROS_ERROR("\t%s: max_distance: %.1f m, Point number: %.1fK",  iter->scan_mode,
                            iter->max_distance, (1000/iter->us_per_sample));
                }
                op_result = RESULT_OPERATION_FAIL;
            } else {
                op_result = drv->startScanExpress(false /* not force scan */, selectedScanMode, 0, &current_scan_mode);
            }
        }
    }

    if(IS_OK(op_result))
    {
        //default frequent is 10 hz (by motor pwm value),  current_scan_mode.us_per_sample is the number of scan point per us
        angle_compensate_multiple = (int)(1000*1000/current_scan_mode.us_per_sample/10.0/360.0);
        if(angle_compensate_multiple < 1) 
          angle_compensate_multiple = 1;
        max_distance = current_scan_mode.max_distance;
        ROS_INFO("current scan mode: %s, max_distance: %.1f m, Point number: %.1fK , angle_compensate: %d",  current_scan_mode.scan_mode,
                 current_scan_mode.max_distance, (1000/current_scan_mode.us_per_sample), angle_compensate_multiple);
    }
    else
    {
        ROS_ERROR("Can not start scan: %08x!", op_result);
    }

    ros::Time start_scan_time;
    ros::Time end_scan_time;
    double scan_duration;
    while (ros::ok()) {
        rplidar_response_measurement_node_hq_t nodes[360*8];
        size_t   count = _countof(nodes);

        start_scan_time = ros::Time::now();
        op_result = drv->grabScanDataHq(nodes, count);
        end_scan_time = ros::Time::now();
        scan_duration = (end_scan_time - start_scan_time).toSec();

        if (op_result == RESULT_OK) {
            op_result = drv->ascendScanData(nodes, count);
            float angle_min = DEG2RAD(0.0f);
            float angle_max = DEG2RAD(359.0f);
            if (op_result == RESULT_OK) {
                if (angle_compensate) {
                    //const int angle_compensate_multiple = 1;
                    const int angle_compensate_nodes_count = 360*angle_compensate_multiple;
                    int angle_compensate_offset = 0;
                    rplidar_response_measurement_node_hq_t angle_compensate_nodes[angle_compensate_nodes_count];
                    memset(angle_compensate_nodes, 0, angle_compensate_nodes_count*sizeof(rplidar_response_measurement_node_hq_t));

                    int i = 0, j = 0;
                    for( ; i < count; i++ ) {
                        if (nodes[i].dist_mm_q2 != 0) {
                            float angle = getAngle(nodes[i]);
                            int angle_value = (int)(angle * angle_compensate_multiple);
                            if ((angle_value - angle_compensate_offset) < 0) angle_compensate_offset = angle_value;
                            for (j = 0; j < angle_compensate_multiple; j++) {

                                int angle_compensate_nodes_index = angle_value-angle_compensate_offset+j;
                                if(angle_compensate_nodes_index >= angle_compensate_nodes_count)
                                    angle_compensate_nodes_index = angle_compensate_nodes_count-1;
                                angle_compensate_nodes[angle_compensate_nodes_index] = nodes[i];
                            }
                        }
                    }
  
                    publish_scan(angle_compensate_nodes, angle_compensate_nodes_count,start_scan_time, scan_duration, inverted,
                             angle_min, angle_max, max_distance,
                             frame_id);
                } else {
                    int start_node = 0, end_node = 0;
                    int i = 0;
                    // find the first valid node and last valid node
                    while (nodes[i++].dist_mm_q2 == 0);
                    start_node = i-1;
                    i = count -1;
                    while (nodes[i--].dist_mm_q2 == 0);
                    end_node = i+1;

                    angle_min = DEG2RAD(getAngle(nodes[start_node]));
                    angle_max = DEG2RAD(getAngle(nodes[end_node]));

                    publish_scan(&nodes[start_node], end_node-start_node +1, start_scan_time, scan_duration, inverted,
                             angle_min, angle_max, max_distance,
                             frame_id);
               }
            } else if (op_result == RESULT_OPERATION_FAIL) {
                // All the data is invalid, just publish them
                float angle_min = DEG2RAD(0.0f);
                float angle_max = DEG2RAD(359.0f);
                publish_scan(nodes, count, start_scan_time, scan_duration, inverted,
                             angle_min, angle_max, max_distance,
                             frame_id);
            }
        }

        ros::spinOnce();
    }

    // done!
    drv->stopMotor();
    drv->stop();
    RPlidarDriver::DisposeDriver(drv);
    return 0;
}

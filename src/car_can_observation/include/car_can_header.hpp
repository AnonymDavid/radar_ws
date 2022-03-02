#ifndef COMPOSITION__CAR_CAN_HEADER_HPP_
#define COMPOSITION__CAR_CAN_HEADER_HPP_

#include <iostream>
#include <ros/ros.h>
#include <socketcan_interface/socketcan.h>
#include <socketcan_interface/threading.h>
#include <socketcan_interface/string.h>

#include "e-golf_can_defines.h"

#include <chrono>
#include <iostream>
#include <memory>
#include <utility>
#include <math.h>
#include <cstddef>
#include <set>
#include <stdlib.h>
#include <string>


typedef unsigned char ubyte;
typedef unsigned short int uword;

class CarCanObservation
{
public:
    CarCanObservation(const ros::NodeHandle &nh);
    ~CarCanObservation() = default;

    //create can_receive_callback
    void can_frame_callback(const can::Frame &msg);
    void init(can::DriverInterfaceSharedPtr &driver_);

private:

    ros::NodeHandle nh;

    //create CAN channel object
    can::DriverInterfaceSharedPtr driver_;
    can::FrameListenerConstSharedPtr frame_listener_;
    //can::DriverInterfaceSharedPtr radar_can_output;

    void handle_can_msg(const can::Frame &msg);
    std::map<int,radar_conti::Object> object_map_;
};

#endif  // COMPOSITION__CAR_CAN_HEADER_HPP_
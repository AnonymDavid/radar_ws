#include "car_can_header.hpp"

CarCanObservation::CarCanObservation(const ros::NodeHandle &nh) : nh(nh) {};

CarCanObservation::init(can::DriverInterfaceSharedPtr &driver_)
{
    this->driver_ = driver_;
    this->frame_listener_ = driver_->createMsgListenerM(this,&Radar_Conti::can_frame_callback);
}

void CarCanObservation::can_frame_callback(const can::Frame &msg)
{
    handle_can_msg(msg);
}

void CarCanObservation::handle_can_msg(const can::Frame &msg)
{
    if (msg.id == ID_BRAKE_PEDAL) {
            for (int i = 0; i < 8; i++)
             ROS_INFO("data: %d",msg.data[i]);
        ROS_INFO("break pedal:  %.2lf",, CALC_BRAKE_PEDAL(GET_BRAKE_PEDAL(msg.data), 1.0));
    }

}
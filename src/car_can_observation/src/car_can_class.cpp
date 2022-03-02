#include "car_can_header.hpp"

CarCanObservation::CarCanObservation(const ros::NodeHandle &nh) : nh(nh) {};

void CarCanObservation::init(can::DriverInterfaceSharedPtr &driver_)
{
    this->driver_ = driver_;
    this->frame_listener_ = driver_->createMsgListenerM(this, &CarCanObservation::can_frame_callback);
}

void CarCanObservation::can_frame_callback(const can::Frame &msg)
{
    handle_can_msg(msg);
}

void CarCanObservation::handle_can_msg(const can::Frame &msg)
{
    if (msg.id == ID_BRAKE_PEDAL) {
        ROS_INFO("break pedal:  %.2lf", CALC_BRAKE_PEDAL(GET_BRAKE_PEDAL(msg.data), 1.0));
    }

}
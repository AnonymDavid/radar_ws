#include "car_can_header.hpp"
#include <string>


int main(int argc, char** argv)
{
    ros::init(argc, argv, "car_can_observation");
    ros::NodeHandle nh;

    can::DriverInterfaceSharedPtr driver = std::make_shared<can::ThreadedSocketCANInterface> ();

    const std::string can_device = "can0";
    if(!driver->init(can_device, 0)) 
    {
        ROS_FATAL("Failed to initialize can_device at %s",can_device.c_str());
        return 1;
    }
    else ROS_INFO("Successfully connected to %s.", can_device.c_str());
    CarCanObservation node(nh);
    node.init(driver);

    ros::spin();

    driver->shutdown();
    driver.reset();

    ros::waitForShutdown();

    return 0;
}
cmake_minimum_required(VERSION 3.0.2)
project(car_can_observation)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  nav_msgs
  socketcan_interface
  socketcan_bridge
  roscpp
  rospy
  std_msgs
  message_generation
)
#
#add_message_files(
#  FILES
#  Frame.msg
#)

generate_messages(
   DEPENDENCIES
   std_msgs  # Or other packages containing msgs
)

catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES car_can_observation
  CATKIN_DEPENDS roscpp socketcan_interface std_msgs message_runtime
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  include/
)


#add_executable(radar_info src/radar_info.cpp)
#add_dependencies(radar_info ${radar_info_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
#target_link_libraries(radar_info ${catkin_LIBRARIES})


add_executable(car_can_observation src/car_can_class.cpp src/car_can_init.cpp)
add_dependencies(car_can_observation ${car_can_observation_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(car_can_observation ${catkin_LIBRARIES})
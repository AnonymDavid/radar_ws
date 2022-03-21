cmake_minimum_required(VERSION 3.0.2)
project(closest_points_difference)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  message_generation
  visualization_msgs
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS 
    roscpp 
    message_runtime
    visualization_msgs
)


###########
## Build ##
###########
include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

add_executable(diffcalc src/calculator.cpp)

target_link_libraries(diffcalc ${catkin_LIBRARIES})

add_dependencies(diffcalc ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
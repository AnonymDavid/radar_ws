# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "/home/nvidia/radar_ws/src/ros_canopen/socketcan_bridge/include".split(';') if "/home/nvidia/radar_ws/src/ros_canopen/socketcan_bridge/include" != "" else []
PROJECT_CATKIN_DEPENDS = "can_msgs;rosconsole_bridge;roscpp;socketcan_interface".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lsocketcan_to_topic;-ltopic_to_socketcan;-lconfiguration".split(';') if "-lsocketcan_to_topic;-ltopic_to_socketcan;-lconfiguration" != "" else []
PROJECT_NAME = "socketcan_bridge"
PROJECT_SPACE_DIR = "/home/nvidia/radar_ws/devel/.private/socketcan_bridge"
PROJECT_VERSION = "0.8.5"

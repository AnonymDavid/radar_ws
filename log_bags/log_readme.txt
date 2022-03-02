./runRaL_log.sh ~/radar_ws/log_bags/[bag_name].bag
rostopic echo -b [bag_name].bag -p /radar_closest_marker > [log_radar_closest_marker_file_name].csv
rostopic echo -b [bag_name].bag -p /closest_point > [log_lidar_closest_marker_file_name].csv


Másik topicokra is ugyanúgy működik, csak /radar_closest_marker helyett kell másik topic nevét beírni.
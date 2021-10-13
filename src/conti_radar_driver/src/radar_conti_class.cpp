#include "radar_conti_ars408_component.hpp"
#include <iostream>
#include <math.h>

#include <ros/ros.h>
#include "std_msgs/String.h"
#include <can_msgs/Frame.h>
#include <data.h>

Radar_Conti::Radar_Conti(const ros::NodeHandle &nh) : nh(nh) {};

void Radar_Conti::init(can::DriverInterfaceSharedPtr &driver_)
{
    pub_marker = nh.advertise<visualization_msgs::MarkerArray>("radar_objects_marker",0);
    pub_objects = nh.advertise<radar_conti::ObjectList>("radar_object_list",0);
    collison_obj_pub = nh.advertise<radar_conti::CollisonList>("radar_obj_collison",0);
    pub_cluster = nh.advertise<visualization_msgs::MarkerArray>("radar_cluster_markers",0);
    pub_cluster_list = nh.advertise<radar_conti::ClusterList>("radar_cluster_list",0);
    pub_marker_with_all_data = nh.advertise<visualization_msgs::MarkerArray>("radar_marker_with_all_data",0);
    pub_gps_data = nh.advertise<visualization_msgs::Marker>("gps_data",0);
    pub_closest_marker = nh.advertise<visualization_msgs::MarkerArray>("radar_closest_marker",0);

    // GPS Speed to radar
    //Topic you want to publish
    pub_ = n_.advertise<can_msgs::Frame>("/sent_messages", 1);

    this->driver_ = driver_;
    this->frame_listener_ = driver_->createMsgListenerM(this,&Radar_Conti::can_frame_callback);
}

void Radar_Conti::can_frame_callback(const can::Frame &msg)
{
    if (msg.id == ID_RadarState) {
        operation_mode_ =CALC_RadarState_RadarState_OutputTypeCfg(GET_RadarState_RadarState_OutputTypeCfg(msg.data),1.0);
    }
    if (operation_mode_ == 0x00)
        return;

    else if(operation_mode_ == 0x01)
        handle_object_list(msg);

    else if(operation_mode_ == 0x02)
        handle_cluster_list(msg);
}
// GPS speed
bool Radar_Conti::is_integer(float dec)
{
        return std::floor(dec) == dec;
}

void Radar_Conti::send_GPS_speed(){
        // Sending GPS speed
        can_msgs::Frame output;
         //.... do something with the input and generate the output...

         output.header.stamp = ros::Time::now();
         output.id = 768; //Decimal value of id 300
         output.dlc = 2;

         Byte b1, b2;
         int bits1[8], bits2[8];
         int i = 1;

         double gps_speed_to_send = std::round((gps_speed) / 3.6 / 0.02);

         while (i <= 8)
         {
            gps_speed_to_send /= 2;

            if (is_integer(gps_speed_to_send) == 0)
            {
               gps_speed_to_send -= 0.5;
               bits2[i] = 1;
               i++;
            }
            else
            {
               bits2[i] = 0;
               i++;
            }
         }

         i=1;

         while (i <= 5)
         {
            gps_speed_to_send /= 2;

            if (is_integer(gps_speed_to_send) == 0)
            {
               gps_speed_to_send -= 0.5;
               bits1[i] = 1;
               i++;
            }
            else
            {
               bits1[i] = 0;
               i++;
            }
         }

         b1.bit1 = bits1[1];
         b1.bit2 = bits1[2];
         b1.bit3 = bits1[3];
         b1.bit4 = bits1[4];
         b1.bit5 = bits1[5];
         b1.bit6 = 0;
         b1.bit7 = 1;
         b1.bit8 = 0;

         b2.bit1 = bits2[1];
         b2.bit2 = bits2[2];
         b2.bit3 = bits2[3];
         b2.bit4 = bits2[4];
         b2.bit5 = bits2[5];
         b2.bit6 = bits2[6];
         b2.bit7 = bits2[7];
         b2.bit8 = bits2[8];

         output.data[0]= b1.byte;
         output.data[1]= b2.byte;

         //ROS_INFO_STREAM(output);

         pub_.publish(output);
}

void Radar_Conti::send_GPS_yaw(){
        // Sending GPS speed
        can_msgs::Frame output;
         //.... do something with the input and generate the output...

         output.header.stamp = ros::Time::now();
         output.id = 769; //Decimal value of id 300
         output.dlc = 2;

         Byte b1, b2;
         int bits1[8], bits2[8];
         int i = 1;

         double gps_yaw_to_send = /*std::round((0 + 327.68) / 0.01)*/std::round((gps_yaw_z + 327.68) / 0.01);

         while (i <= 8)
         {
            gps_yaw_to_send /= 2;

            if (is_integer(gps_yaw_to_send) == 0)
            {
               gps_yaw_to_send -= 0.5;
               bits2[i] = 1;
               i++;
            }
            else
            {
               bits2[i] = 0;
               i++;
            }
         }

         i=1;

         while (i <= 8)
         {
            gps_yaw_to_send /= 2;

            if (is_integer(gps_yaw_to_send) == 0)
            {
               gps_yaw_to_send -= 0.5;
               bits1[i] = 1;
               i++;
            }
            else
            {
               bits1[i] = 0;
               i++;
            }
         }

         b1.bit1 = bits1[1];
         b1.bit2 = bits1[2];
         b1.bit3 = bits1[3];
         b1.bit4 = bits1[4];
         b1.bit5 = bits1[5];
         b1.bit6 = bits1[6];
         b1.bit7 = bits1[7];
         b1.bit8 = bits1[8];

         b2.bit1 = bits2[1];
         b2.bit2 = bits2[2];
         b2.bit3 = bits2[3];
         b2.bit4 = bits2[4];
         b2.bit5 = bits2[5];
         b2.bit6 = bits2[6];
         b2.bit7 = bits2[7];
         b2.bit8 = bits2[8];

         output.data[0]= b1.byte;
         output.data[1]= b2.byte;

         //ROS_INFO_STREAM(output);

         pub_.publish(output);
}

void Radar_Conti::handle_object_list(const can::Frame &msg)
{
    if (msg.id == ID_Obj_0_Status) {
        publish_object_map();

        object_list_.header.stamp = ros::Time::now();
        object_list_.object_count.data = GET_Obj_0_Status_Obj_NofObjects(msg.data);

        object_map_.clear();
        collison_objects.clear();
    }
    else if (msg.id == ID_Obj_1_General) {

        radar_conti::Object o;
        //object ID
        int id = GET_Obj_1_General_Obj_ID(msg.data);
        o.obj_id.data = GET_Obj_1_General_Obj_ID(msg.data);

        // //RCLCPP_INFO(this->get_logger(), "Object_ID: 0x%04x", o.obj_id.data);

        //longitudinal distance
        o.object_general.obj_distlong.data =
                CALC_Obj_1_General_Obj_DistLong(GET_Obj_1_General_Obj_DistLong(msg.data), 1.0);

        //lateral distance
        o.object_general.obj_distlat.data =
                CALC_Obj_1_General_Obj_DistLat(GET_Obj_1_General_Obj_DistLat(msg.data), 1.0);

        //relative longitudinal velocity
        o.object_general.obj_vrellong.data =
                CALC_Obj_1_General_Obj_VrelLong(GET_Obj_1_General_Obj_VrelLong(msg.data), 1.0);

        //relative lateral velocity
        o.object_general.obj_vrellat.data =
                CALC_Obj_1_General_Obj_VrelLat(GET_Obj_1_General_Obj_VrelLat(msg.data), 1.0);

        o.object_general.obj_dynprop.data =
                CALC_Obj_1_General_Obj_DynProp(GET_Obj_1_General_Obj_DynProp(msg.data), 1.0);

        o.object_general.obj_rcs.data = 
                CALC_Obj_1_General_Obj_RCS(GET_Obj_1_General_Obj_RCS(msg.data), 1.0);

        //insert object into map
        
        object_map_.insert(std::pair<int, radar_conti::Object>(id, o));
    }
    else if (msg.id == ID_Obj_2_Quality) {

        int id = GET_Obj_2_Quality_Obj_ID(msg.data);

        object_map_[id].object_quality.obj_distlong_rms.data =
                CALC_Obj_2_Quality_Obj_DistLong_rms(GET_Obj_2_Quality_Obj_DistLong_rms(msg.data), 1.0);

        object_map_[id].object_quality.obj_distlat_rms.data =
                CALC_Obj_2_Quality_Obj_DistLat_rms(GET_Obj_2_Quality_Obj_DistLat_rms(msg.data), 1.0);

        object_map_[id].object_quality.obj_vrellong_rms.data =
                CALC_Obj_2_Quality_Obj_VrelLong_rms(GET_Obj_2_Quality_Obj_VrelLong_rms(msg.data), 1.0);

        object_map_[id].object_quality.obj_vrellat_rms.data =
                CALC_Obj_2_Quality_Obj_VrelLat_rms(GET_Obj_2_Quality_Obj_VrelLat_rms(msg.data), 1.0);

        object_map_[id].object_quality.obj_probofexist.data =
                CALC_Obj_2_Quality_Obj_ProbOfExist(GET_Obj_2_Quality_Obj_ProbOfExist(msg.data), 1.0);

    }
    else if (msg.id == ID_Obj_3_Extended) {
        int id = GET_Obj_3_Extended_Obj_ID(msg.data);


        object_map_[id].object_extended.obj_arellong.data =
                CALC_Obj_3_Extended_Obj_ArelLong(GET_Obj_3_Extended_Obj_ArelLong(msg.data), 1.0);

        object_map_[id].object_extended.obj_arellat.data =
                CALC_Obj_3_Extended_Obj_ArelLat(GET_Obj_3_Extended_Obj_ArelLat(msg.data), 1.0);

        object_map_[id].object_extended.obj_class.data =
                CALC_Obj_3_Extended_Obj_Class(GET_Obj_3_Extended_Obj_Class(msg.data), 1.0);

        int obj_class = CALC_Obj_3_Extended_Obj_Class(GET_Obj_3_Extended_Obj_Class(msg.data), 1.0);

        object_map_[id].object_extended.obj_orientationangle.data =
                CALC_Obj_3_Extended_Obj_OrientationAngle(GET_Obj_3_Extended_Obj_OrientationAngle(msg.data),
                                                            1.0);
        
        object_map_[id].object_extended.obj_length.data =
            CALC_Obj_3_Extended_Obj_Length(GET_Obj_3_Extended_Obj_Length(msg.data), 1.0);

        object_map_[id].object_extended.obj_width.data =
                CALC_Obj_3_Extended_Obj_Width(GET_Obj_3_Extended_Obj_Width(msg.data), 1.0);
    }
    else if(msg.id == ID_Obj_4_Warning)
    {
        const int obj_war = CALC_Obj_4_Warning_Obj_ID(GET_Obj_4_Warning_Obj_ID(msg.data),1.0);
        collison_objects.insert(obj_war); 
    }
    else if (msg.id == ID_GPS_SPEED) {
        gps_speed = CALC_GPS_SPEED_SPEED_KPH(GET_GPS_SPEED_SPEED_MPH(msg.data), 1.0);
        
        gps_altitude = CALC_GPS_SPEED_ALTITUDE(GET_GPS_SPEED_ALTITUDE(msg.data), 1.0);
        
        gps_true_course = CALC_GPS_SPEED_TRUE_COURSE(GET_GPS_SPEED_TRUE_COURSE(msg.data), 1.0);
        
        gps_satelites = CALC_GPS_SPEED_SATELITES(GET_GPS_SPEED_SATELITES(msg.data), 1.0);
        
        gps_valid = CALC_GPS_SPEED_VALID(GET_GPS_SPEED_VALID(msg.data), 1.0);
    }
    else if (msg.id == ID_GPS_YAW) {
        gps_yaw_x = CALC_GPS_YAW_X_YAW(GET_GPS_YAW_X_YAW(msg.data), 1.0);
        
        gps_yaw_y = CALC_GPS_YAW_Y_YAW(GET_GPS_YAW_Y_YAW(msg.data), 1.0);
        
        gps_yaw_z = CALC_GPS_YAW_Z_YAW(GET_GPS_YAW_Z_YAW(msg.data), 1.0);
    }

        if (send_gps_speed > 0){
                send_gps_speed--;
        }
        else{
                if (is_gps_speed_sending){
                        send_GPS_speed();
                }
                else{
                        send_GPS_yaw();
                }
                is_gps_speed_sending = !is_gps_speed_sending;

                send_gps_speed = 2;
        }
    //publish_object_map();
}
void Radar_Conti::handle_cluster_list(const can::Frame &msg)
{
    if(msg.id == ID_Cluster_0_Status)
    {
        publish_cluster_map();

        cluster_list.header.stamp = ros::Time::now();
        cluster_list.cluster_count.data = GET_Cluster_0_Status_Cluster_NofClustersNear(msg.data);

        cluster_map_.clear();
    }
    if(msg.id == ID_Cluster_1_General)
    {
        radar_conti::Cluster c;

        int id = GET_Cluster_1_General_Cluster_ID(msg.data);
        c.cluster_id.data = id;

        c.cluster_general.cluster_distlong.data = 
                CALC_Cluster_1_General_Cluster_DistLong(GET_Cluster_1_General_Cluster_DistLong(msg.data),1.0);
        
        c.cluster_general.cluster_distlat.data = 
                CALC_Cluster_1_General_Cluster_DistLat(GET_Cluster_1_General_Cluster_DistLat(msg.data),1.0);

        c.cluster_general.cluster_vrellong.data = 
                CALC_Cluster_1_General_Cluster_VrelLong(GET_Cluster_1_General_Cluster_VrelLong(msg.data),1.0);

        c.cluster_general.cluster_vrellat.data = 
                CALC_Cluster_1_General_Cluster_VrelLat(GET_Cluster_1_General_Cluster_VrelLat(msg.data),1.0);

        c.cluster_general.cluster_dynprop.data = 
                CALC_Cluster_1_General_Cluster_DynProp(GET_Cluster_1_General_Cluster_DynProp(msg.data),1.0);

        c.cluster_general.cluster_rcs.data = 
                CALC_Cluster_1_General_Cluster_RCS(GET_Cluster_1_General_Cluster_RCS(msg.data),1.0);

        cluster_map_.insert(std::pair<int, radar_conti::Cluster>(id, c));
    }
    if(msg.id == ID_Cluster_2_Quality)
    {
        int id = GET_Cluster_2_Quality_Cluster_ID(msg.data);

        cluster_map_[id].cluster_quality.cluster_distlat_rms.data = 
                CALC_Cluster_2_Quality_Cluster_DistLat_rms(GET_Cluster_2_Quality_Cluster_DistLat_rms(msg.data),1.0);
        cluster_map_[id].cluster_quality.cluster_distlong_rms.data =
                CALC_Cluster_2_Quality_Cluster_DistLong_rms(GET_Cluster_2_Quality_Cluster_DistLong_rms(msg.data),1.0);
        cluster_map_[id].cluster_quality.cluster_vrellong_rms.data =
                CALC_Cluster_1_General_Cluster_VrelLong(GET_Cluster_1_General_Cluster_VrelLong(msg.data),1.0);
        cluster_map_[id].cluster_quality.cluster_vrellat_rms.data = 
                CALC_Cluster_2_Quality_Cluster_VrelLat_rms(GET_Cluster_2_Quality_Cluster_VrelLat_rms(msg.data),1.0);
        cluster_map_[id].cluster_quality.cluster_pdh0.data = 
                CALC_Cluster_2_Quality_Cluster_PdH0(GET_Cluster_2_Quality_Cluster_PdH0(msg.data),1.0);
        cluster_map_[id].cluster_quality.cluster_ambigstate.data = 
                CALC_Cluster_2_Quality_Cluster_AmbigState(GET_Cluster_2_Quality_Cluster_AmbigState(msg.data),1.0);
        cluster_map_[id].cluster_quality.cluster_invalidstate.data = 
                CALC_Cluster_2_Quality_Cluster_InvalidState(GET_Cluster_2_Quality_Cluster_InvalidState(msg.data),1.0);
    }



}

bool Radar_Conti::is_speed_in_threshold(double object_speed) {
        return (gps_speed + object_speed) < speed_threshold &&
                (gps_speed + object_speed) > -speed_threshold;
}

double Radar_Conti::prob_of_exist_data(int data)
{
        switch (data) {
                case 7:
                        return 100.0;
                case 6:
                        return  99.9;
                case 5:
                        return  99.0;
                case 4:
                        return  90.0;
                case 3:
                        return  75.0;
                case 2:
                        return  50.0;
                case 1:
                        return  25.0;
                default:
                        return   0.0;
        }
        return 0.0;
}

void Radar_Conti::publish_object_map() {
        std::map<int, radar_conti::Object>::iterator itr;
        std::map<int, radar_conti::Object>::iterator closest_itr = object_map_.begin();

        visualization_msgs::MarkerArray marker_array;
        visualization_msgs::MarkerArray marker_array_all_data;
        visualization_msgs::MarkerArray marker_array_closest_object;
        visualization_msgs::Marker gps_text;

        tf2::Quaternion myQuaternion;
        /*
        //marker for ego car
        visualization_msgs::Marker mEgoCar;

        mEgoCar.header.stamp = ros::Time::now();
        mEgoCar.header.frame_id = frame_id_;
        mEgoCar.ns = "ego";
        mEgoCar.id = 999;

        //if you want to use a cube comment out the next 2 line
        mEgoCar.type = 1; // cube
        mEgoCar.action = 0; // add/modify
        mEgoCar.pose.position.x = 0.0;
        mEgoCar.pose.position.y = 0.0;
        mEgoCar.pose.position.z = 0.0;

        tf2::Quaternion myQuaternion;
        myQuaternion.setRPY(0, 0, M_PI/2);

        mEgoCar.pose.orientation.w = myQuaternion.getW();
        mEgoCar.pose.orientation.x = myQuaternion.getX();
        mEgoCar.pose.orientation.y = myQuaternion.getY();
        mEgoCar.pose.orientation.z = myQuaternion.getZ();
        mEgoCar.scale.x = 0.2;
        mEgoCar.scale.y = 0.2;
        mEgoCar.scale.z = 0.2;
        mEgoCar.color.r = 0.0;
        mEgoCar.color.g = 0.0;
        mEgoCar.color.b = 1.0;
        mEgoCar.color.a = 0.4;
        mEgoCar.lifetime = ros::Duration(0.25);
        mEgoCar.frame_locked = false;

        marker_array.markers.push_back(mEgoCar);
        */
        for (itr = object_map_.begin(); itr != object_map_.end(); ++itr) {
                if (itr->second.object_general.obj_rcs.data != 0 &&
                        itr->second.object_general.obj_distlong.data != 0 &&
                        itr->second.object_general.obj_distlat.data /*&&
                        !is_speed_in_threshold((double)itr->second.object_general.obj_vrellong.data)*/)
                {
                        float itr_distance = sqrt(pow(itr->second.object_general.obj_distlong.data, 2) + pow(itr->second.object_general.obj_distlat.data, 2));
                        float closest_distance = sqrt(pow(closest_itr->second.object_general.obj_distlong.data, 2) + pow(closest_itr->second.object_general.obj_distlat.data, 2));
                        if (itr_distance < closest_distance) {
                                closest_itr = itr;
                        }

                        visualization_msgs::Marker mobject;
                        visualization_msgs::Marker mobject_all;
                        visualization_msgs::Marker mtext;
                        visualization_msgs::Marker mtext_all;

                        mtext.header.stamp = ros::Time::now();
                        mtext.header.frame_id = frame_id_;
                        mtext.ns = "text";
                        mtext.id = (itr->first+100);
                        mtext.type=9;
                        mtext.action = 0; // add/modify
                        mtext.pose.position.x = itr->second.object_general.obj_distlong.data;
                        mtext.pose.position.y = itr->second.object_general.obj_distlat.data;
                        mtext.pose.position.z = 6; //4.0

                        myQuaternion.setRPY(0, 0, 0);
                        mtext.pose.orientation.w = myQuaternion.getW();
                        mtext.pose.orientation.x = myQuaternion.getX();
                        mtext.pose.orientation.y = myQuaternion.getY();
                        mtext.pose.orientation.z = myQuaternion.getZ();
                        mtext.scale.z = 1.0;
                        mtext.color.r = 1.0;
                        mtext.color.g = 1.0;
                        mtext.color.b = 1.0;
                        mtext.color.a = 1.0;
                        mtext.lifetime = ros::Duration(0.25);
                        mtext.frame_locked = false;


                        mtext_all.header.stamp = ros::Time::now();
                        mtext_all.header.frame_id = "/radar_all_data";
                        mtext_all.ns = "text";
                        mtext_all.id = (itr->first+100);
                        mtext_all.type=9;
                        mtext_all.action = 0; // add/modify
                        mtext_all.pose.position.x = itr->second.object_general.obj_distlong.data;
                        mtext_all.pose.position.y = itr->second.object_general.obj_distlat.data;
                        mtext_all.pose.position.z = 6; //4.0

                        myQuaternion.setRPY(0, 0, 0);
                        mtext_all.pose.orientation.w = myQuaternion.getW();
                        mtext_all.pose.orientation.x = myQuaternion.getX();
                        mtext_all.pose.orientation.y = myQuaternion.getY();
                        mtext_all.pose.orientation.z = myQuaternion.getZ();
                        mtext_all.scale.z = 1.0;
                        mtext_all.color.r = 1.0;
                        mtext_all.color.g = 1.0;
                        mtext_all.color.b = 1.0;
                        mtext_all.color.a = 1.0;
                        mtext_all.lifetime = ros::Duration(0.25);
                        mtext_all.frame_locked = false;


                        mobject.header.stamp = ros::Time::now();
                        mobject.header.frame_id = frame_id_;
                        mobject.ns = "objects";
                        mobject.id = itr->first;
                        mobject.type = 1; //Cube
                        mobject.action = 0; // add/modify
                        mobject.pose.position.x = itr->second.object_general.obj_distlong.data;
                        mobject.pose.position.y = itr->second.object_general.obj_distlat.data;
                        mobject.pose.position.z = 0.0;

                        myQuaternion.setRPY(0, 0, itr->second.object_extended.obj_orientationangle.data);
                        mobject.pose.orientation.w = myQuaternion.getW();
                        mobject.pose.orientation.x = myQuaternion.getX();
                        mobject.pose.orientation.y = myQuaternion.getY();
                        mobject.pose.orientation.z = myQuaternion.getZ();
                        mobject.scale.x = itr->second.object_extended.obj_length.data;
                        mobject.scale.y = itr->second.object_extended.obj_width.data;
                        mobject.scale.z = 1.0;
                        

                        mobject_all.header.stamp = ros::Time::now();
                        mobject_all.header.frame_id = "/radar_all_data";
                        mobject_all.ns = "objects";
                        mobject_all.id = itr->first;
                        mobject_all.type = 1; //Cube
                        mobject_all.action = 0; // add/modify
                        mobject_all.pose.position.x = itr->second.object_general.obj_distlong.data;
                        mobject_all.pose.position.y = itr->second.object_general.obj_distlat.data;
                        mobject_all.pose.position.z = 0.0;

                        myQuaternion.setRPY(0, 0, itr->second.object_extended.obj_orientationangle.data);
                        mobject_all.pose.orientation.w = myQuaternion.getW();
                        mobject_all.pose.orientation.x = myQuaternion.getX();
                        mobject_all.pose.orientation.y = myQuaternion.getY();
                        mobject_all.pose.orientation.z = myQuaternion.getZ();
                        mobject_all.scale.x = itr->second.object_extended.obj_length.data;
                        mobject_all.scale.y = itr->second.object_extended.obj_width.data;
                        mobject_all.scale.z = 1.0;
                        

                        if(collison_objects.find(itr->first) != collison_objects.end())
                        {
                                mobject.color.r = 1.0;
                                mobject.color.g = 0.0;
                                mtext.text= "object_" + std::to_string(itr->first) + ": \n"  
                                + " D_long: " +   std::to_string(itr->second.object_general.obj_distlong.data) + "m\n" 
                                + " D_lat: " + std::to_string(itr->second.object_general.obj_distlat.data) + "m\n";
                                radar_conti::CollisonObj collison_item;
                                collison_item.obj_id = itr->second.obj_id;
                                coll_list.objects.push_back(collison_item);
                        }
                        else
                        {
                                double value = prob_of_exist_data((int)itr->second.object_quality.obj_probofexist.data);                                
                                std::stringstream ss, ss_all;

                                ss.precision(2);
                                ss << std::fixed << "object_" << std::fixed << std::setprecision(1) << itr->first << "\n"
                                << " RCS: " << itr->second.object_general.obj_rcs.data << " dBm^2\n"
                                << " Distance: " << itr_distance << " m\n"
                                << " V_long: " << itr->second.object_general.obj_vrellong.data << "m/s" << " \n" 
                                << " V_lat: " << itr->second.object_general.obj_vrellat.data << "m/s" << " \n" 
                                << " Class: " << object_classes[itr->second.object_extended.obj_class.data] << "\n"
                                << "ProbOfExist: " << value << "%";
                                mtext.text = ss.str();


                                ss_all.precision(2);
                                ss_all << std::fixed << "object_" << std::fixed << std::setprecision(1) << itr->first << "\n"
                                << " RCS: " << itr->second.object_general.obj_rcs.data << " dBm^2\n"
                                << " D_long (x): " << itr->second.object_general.obj_distlong.data << " m\n"
                                << " D_lat (y): " << itr->second.object_general.obj_distlat.data << " m\n"
                                << " Distance: " << itr_distance << " m\n"
                                << " Length (x): " << itr->second.object_extended.obj_length.data << " m\n"
                                << " Width (y): " << itr->second.object_extended.obj_width.data << " m\n"
                                << " Orientation: " << itr->second.object_extended.obj_orientationangle.data << "  degree\n"
                                << " V_long: " << itr->second.object_general.obj_vrellong.data << "m/s" << " \n" 
                                << " V_lat: " << itr->second.object_general.obj_vrellat.data << "m/s" << " \n" 
                                << " Class: " << object_classes[itr->second.object_extended.obj_class.data] << "\n"
                                << "ProbOfExist: " << value << "%";
                                mtext_all.text = ss_all.str();
                                
                        }
                        // assign colors to each object ID (deterministic pseudo-random colors)
                        int i = int(itr->first);
                        int j = 100 - int(itr->first);
                        int k = itr->first + 5;
                        double r = double(i % 3) / 2.1;
                        double g = double(j % 21) / 21;
                        double b = double(k % 30) / 30;
                        mobject.color.r = r;
                        mobject.color.g = g;
                        mobject.color.b = b;
                        mobject.color.a = 0.6;
                        mobject.lifetime = ros::Duration(0.25);
                        mobject.frame_locked = false;

                        mobject_all.color.r = r;
                        mobject_all.color.g = g;
                        mobject_all.color.b = b;
                        mobject_all.color.a = 0.6;
                        mobject_all.lifetime = ros::Duration(0.25);
                        mobject_all.frame_locked = false;

                        //if (TODO){
                        if (itr->second.object_extended.obj_class.data != 0){ // if class is not point
                                object_list_.objects.push_back(itr->second);
                                marker_array.markers.push_back(mobject);
                                marker_array.markers.push_back(mtext);

                                marker_array_all_data.markers.push_back(mobject_all);
                                marker_array_all_data.markers.push_back(mtext_all);
                        }
                        //}
                }

        }

        //********************************************************************
        //******************************        ******************************
        //*******************  C L O S E S T  O B J E C T  *******************
        //******************************        ******************************
        //********************************************************************

        if (closest_itr != object_map_.end()) {
                visualization_msgs::Marker mobject_closest;
                visualization_msgs::Marker mtext_closest;

                mtext_closest.header.stamp = ros::Time::now();
                mtext_closest.header.frame_id = "/radar_closest";
                mtext_closest.ns = "text";
                mtext_closest.id = (closest_itr->first+100);
                mtext_closest.type = 1; //Cube
                mtext_closest.action = 0; // add/modify
                mtext_closest.pose.position.x = closest_itr->second.object_general.obj_distlong.data;
                mtext_closest.pose.position.y = closest_itr->second.object_general.obj_distlat.data;
                mtext_closest.pose.position.z = 6; //4.0

                myQuaternion.setRPY(0, 0, 0);
                mtext_closest.pose.orientation.w = myQuaternion.getW();
                mtext_closest.pose.orientation.x = myQuaternion.getX();
                mtext_closest.pose.orientation.y = myQuaternion.getY();
                mtext_closest.pose.orientation.z = myQuaternion.getZ();
                mtext_closest.scale.z = 1.0;
                mtext_closest.color.r = 1.0;
                mtext_closest.color.g = 1.0;
                mtext_closest.color.b = 1.0;
                mtext_closest.color.a = 1.0;
                mtext_closest.lifetime = ros::Duration(0.15);
                mtext_closest.frame_locked = false;
                mtext_closest.type=9;

                mobject_closest.header.stamp = ros::Time::now();
                mobject_closest.header.frame_id = "/radar_closest";
                mobject_closest.ns = "objects";
                mobject_closest.id = closest_itr->first;
                mobject_closest.type = 1; //Cube
                mobject_closest.action = 0; // add/modify
                mobject_closest.pose.position.x = closest_itr->second.object_general.obj_distlong.data;
                mobject_closest.pose.position.y = closest_itr->second.object_general.obj_distlat.data;
                mobject_closest.pose.position.z = 0.0;

                myQuaternion.setRPY(0, 0, closest_itr->second.object_extended.obj_orientationangle.data);
                mobject_closest.pose.orientation.w = myQuaternion.getW();
                mobject_closest.pose.orientation.x = myQuaternion.getX();
                mobject_closest.pose.orientation.y = myQuaternion.getY();
                mobject_closest.pose.orientation.z = myQuaternion.getZ();
                mobject_closest.scale.x = closest_itr->second.object_extended.obj_length.data;
                mobject_closest.scale.y = closest_itr->second.object_extended.obj_width.data;
                mobject_closest.scale.z = 1.0;
                
                double value = prob_of_exist_data((int)closest_itr->second.object_quality.obj_probofexist.data);
                
                std::stringstream ss_closest;
                ss_closest.precision(2);

                ss_closest << std::fixed << "object_" << std::fixed << std::setprecision(1) << closest_itr->first << "\n"
                << " RCS: " << closest_itr->second.object_general.obj_rcs.data << " dBm^2\n"
                << " D_long (x): " << closest_itr->second.object_general.obj_distlong.data << " m\n"
                << " D_lat (y): " << closest_itr->second.object_general.obj_distlat.data << " m\n"
                << " Distance: " << sqrt(pow(closest_itr->second.object_general.obj_distlong.data, 2) + pow(closest_itr->second.object_general.obj_distlat.data, 2)) << " m\n"
                << " Length (x): " << closest_itr->second.object_extended.obj_length.data << " m\n"
                << " Width (y): " << closest_itr->second.object_extended.obj_width.data << " m\n"
                << " Orientation: " << closest_itr->second.object_extended.obj_orientationangle.data << "  degree\n"
                << " V_long: " << closest_itr->second.object_general.obj_vrellong.data << "m/s" << " \n" 
                << " V_lat: " << closest_itr->second.object_general.obj_vrellat.data << "m/s" << " \n" 
                << " Class: " << object_classes[closest_itr->second.object_extended.obj_class.data] << "\n"
                << "ProbOfExist: " << value << "%";
                mtext_closest.text = ss_closest.str();
                
                int i = int(closest_itr->first);
                int j = 100 - int(closest_itr->first);
                int k = closest_itr->first + 5;
                double r = double(i % 3) / 2.1;
                double g = double(j % 21) / 21;
                double b = double(k % 30) / 30;

                mobject_closest.color.r = r;
                mobject_closest.color.g = g;
                mobject_closest.color.b = b;
                mobject_closest.color.a = 0.6;
                mobject_closest.lifetime = ros::Duration(0.15);
                mobject_closest.frame_locked = false;

                if (closest_itr->second.object_extended.obj_class.data != 0){ // if class is not point
                        marker_array_closest_object.markers.push_back(mobject_closest);
                        marker_array_closest_object.markers.push_back(mtext_closest);
                }
        }
        //********************************************************************
        //******************************        ******************************
        //*************************  G P S  T E X T  *************************
        //******************************        ******************************
        //********************************************************************

        gps_text.header.stamp = ros::Time::now();
        gps_text.header.frame_id = "/gps_data";
        gps_text.ns = "text";
        gps_text.id = 998;
        gps_text.type = 1; //Cube
        gps_text.action = 0; // add/modify
        gps_text.pose.position.x = -10;
        gps_text.pose.position.y = -2;
        gps_text.pose.position.z = -5; //4.0

        myQuaternion.setRPY(0, 0, 0);
        gps_text.pose.orientation.w = myQuaternion.getW();
        gps_text.pose.orientation.x = myQuaternion.getX();
        gps_text.pose.orientation.y = myQuaternion.getY();
        gps_text.pose.orientation.z = myQuaternion.getZ();

        gps_text.scale.z = 1.0;
        gps_text.color.r = 1.0;
        gps_text.color.g = 1.0;
        gps_text.color.b = 1.0;
        gps_text.color.a = 1.0;
        gps_text.lifetime = ros::Duration(0.25);
        gps_text.frame_locked = false;
        gps_text.type=9;

        
        std::stringstream ss2;
        ss2.precision(2);

        ss2 << std::fixed << "GPS DATA:\n"
        << " GPS speed: " << gps_speed << " Km/h\n"
        << " GPS altitude: " << gps_altitude << " m\n"
        << " GPS true course: " << gps_true_course << "°\n"
        << " GPS satelites: " << gps_satelites << "\n"
        << " GPS valid: " << gps_valid << "\n"
        << " GPS yaw x: " << gps_yaw_x << "\n"
        << " GPS yaw y: " << gps_yaw_y << "\n"
        << " GPS yaw z: " << gps_yaw_z << "\n";
        gps_text.text = ss2.str();


        //********************************************************************
        //******************************        ******************************
        //******************  P U B L I S H  T O  R V I Z  *******************
        //******************************        ******************************
        //********************************************************************


        //collison_obj_pub.publish(coll_list);
        //pub_objects.publish(object_list_);
        pub_marker.publish(marker_array);
        pub_marker_with_all_data.publish(marker_array_all_data);
        pub_closest_marker.publish(marker_array_closest_object);
        pub_gps_data.publish(gps_text);
}

void Radar_Conti::publish_cluster_map()
{
        std::map<int, radar_conti::Cluster>::iterator itr;

        
        visualization_msgs::MarkerArray marker_array;

        //marker for ego car
        visualization_msgs::Marker mEgoCar;

        mEgoCar.header.stamp = ros::Time::now();
        mEgoCar.header.frame_id = frame_id_;
        mEgoCar.ns = "ego";
        mEgoCar.id = 999;

        //if you want to use a cube comment out the next 2 line
        mEgoCar.type = 1; // cube
        mEgoCar.action = 0; // add/modify
        mEgoCar.pose.position.x = 0.0;
        mEgoCar.pose.position.y = 0.0;
        mEgoCar.pose.position.z = 0.0;

        tf2::Quaternion myQuaternion;
        myQuaternion.setRPY(0, 0, M_PI/2);

        mEgoCar.pose.orientation.w = myQuaternion.getW();
        mEgoCar.pose.orientation.x = myQuaternion.getX();
        mEgoCar.pose.orientation.y = myQuaternion.getY();
        mEgoCar.pose.orientation.z = myQuaternion.getZ();
        mEgoCar.scale.x = 0.2;
        mEgoCar.scale.y = 0.2;
        mEgoCar.scale.z = 0.2;
        mEgoCar.color.r = 0.0;
        mEgoCar.color.g = 0.0;
        mEgoCar.color.b = 1.0;
        mEgoCar.color.a = 1.0;
        mEgoCar.lifetime = ros::Duration(0.2);
        mEgoCar.frame_locked = false;

        marker_array.markers.push_back(mEgoCar);

        for (itr = cluster_map_.begin(); itr != cluster_map_.end(); ++itr) {

                visualization_msgs::Marker mobject;
                visualization_msgs::Marker mtext;

                mtext.header.stamp = ros::Time::now();
                mtext.header.frame_id = frame_id_;
                mtext.ns = "text";
                mtext.id = (itr->first+100);
                mtext.type = 1; //Cube
                mtext.action = 0; // add/modify
                mtext.pose.position.x = itr->second.cluster_general.cluster_distlong.data;
                mtext.pose.position.y = itr->second.cluster_general.cluster_distlat.data;
                mtext.pose.position.z = 4.0;

        
                //myQuaternion.setRPY(M_PI / 2, 0, 0);
                myQuaternion.setRPY(0, 0, 0);

                mtext.pose.orientation.w = myQuaternion.getW();
                mtext.pose.orientation.x = myQuaternion.getX();
                mtext.pose.orientation.y = myQuaternion.getY();
                mtext.pose.orientation.z = myQuaternion.getZ();
                // mtext.scale.x = 1.0;
                // mtext.scale.y = 1.0;
                mtext.scale.z = 2.0;
                mtext.color.r = 1.0;
                mtext.color.g = 1.0;
                mtext.color.b = 1.0;
                mtext.color.a = 1.0;
                mtext.lifetime = ros::Duration(0.2);
                mtext.frame_locked = false;
                mtext.type=9;
                mtext.text= "Cluster" + std::to_string(itr->first) + ": \n" 
                + " RCS: " + std::to_string(itr->second.cluster_general.cluster_rcs.data) + "dBm^2"; // + " \n" 
                //+ " V_long: " +   std::to_string(itr->second.cluster_general.cluster_vrellong.data) + "m/s" + " \n" 
                //+ " V_lat: " + std::to_string(itr->second.cluster_general.cluster_vrellat.data) + "m/s" + " \n";
                //+ " Orientation: " + std::to_string(itr->second.cluster_general.cluster_vrellon);


                marker_array.markers.push_back(mtext);



                mobject.header.stamp = ros::Time::now();
                mobject.header.frame_id = frame_id_;
                mobject.ns = "objects";
                mobject.id = itr->first;
                mobject.type = 1; //Cube
                mobject.action = 0; // add/modify
                mobject.pose.position.x = itr->second.cluster_general.cluster_distlong.data;
                mobject.pose.position.y = itr->second.cluster_general.cluster_distlat.data;
                mobject.pose.position.z = 1.0;

                myQuaternion.setRPY(0, 0, 0);

                mobject.pose.orientation.w = myQuaternion.getW();
                mobject.pose.orientation.x = myQuaternion.getX();
                mobject.pose.orientation.y = myQuaternion.getY();
                mobject.pose.orientation.z = myQuaternion.getZ();
                mobject.scale.x = 2.0;
                mobject.scale.y = 2.0;
                mobject.scale.z = 1.0;
                mobject.color.r = 0.0;
                mobject.color.g = 1.0;
                mobject.color.b = 0.0;
                mobject.color.a = 1.0;
                mobject.lifetime = ros::Duration(0.2);
                mobject.frame_locked = false;

                cluster_list.clusters.push_back(itr->second);

                marker_array.markers.push_back(mobject);


        }
        pub_cluster_list.publish(cluster_list);
        pub_cluster.publish(marker_array);

}


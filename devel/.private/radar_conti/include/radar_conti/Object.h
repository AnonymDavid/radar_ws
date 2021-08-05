// Generated by gencpp from file radar_conti/Object.msg
// DO NOT EDIT!


#ifndef RADAR_CONTI_MESSAGE_OBJECT_H
#define RADAR_CONTI_MESSAGE_OBJECT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Int32.h>
#include <radar_conti/ObjectGeneral.h>
#include <radar_conti/ObjectExtended.h>
#include <radar_conti/ObjectQuality.h>

namespace radar_conti
{
template <class ContainerAllocator>
struct Object_
{
  typedef Object_<ContainerAllocator> Type;

  Object_()
    : obj_id()
    , object_general()
    , object_extended()
    , object_quality()  {
    }
  Object_(const ContainerAllocator& _alloc)
    : obj_id(_alloc)
    , object_general(_alloc)
    , object_extended(_alloc)
    , object_quality(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Int32_<ContainerAllocator>  _obj_id_type;
  _obj_id_type obj_id;

   typedef  ::radar_conti::ObjectGeneral_<ContainerAllocator>  _object_general_type;
  _object_general_type object_general;

   typedef  ::radar_conti::ObjectExtended_<ContainerAllocator>  _object_extended_type;
  _object_extended_type object_extended;

   typedef  ::radar_conti::ObjectQuality_<ContainerAllocator>  _object_quality_type;
  _object_quality_type object_quality;





  typedef boost::shared_ptr< ::radar_conti::Object_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::radar_conti::Object_<ContainerAllocator> const> ConstPtr;

}; // struct Object_

typedef ::radar_conti::Object_<std::allocator<void> > Object;

typedef boost::shared_ptr< ::radar_conti::Object > ObjectPtr;
typedef boost::shared_ptr< ::radar_conti::Object const> ObjectConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::radar_conti::Object_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::radar_conti::Object_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::radar_conti::Object_<ContainerAllocator1> & lhs, const ::radar_conti::Object_<ContainerAllocator2> & rhs)
{
  return lhs.obj_id == rhs.obj_id &&
    lhs.object_general == rhs.object_general &&
    lhs.object_extended == rhs.object_extended &&
    lhs.object_quality == rhs.object_quality;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::radar_conti::Object_<ContainerAllocator1> & lhs, const ::radar_conti::Object_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace radar_conti

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::radar_conti::Object_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::radar_conti::Object_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::radar_conti::Object_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::radar_conti::Object_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::radar_conti::Object_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::radar_conti::Object_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::radar_conti::Object_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a7779c5b6537b3dc9690537349901eeb";
  }

  static const char* value(const ::radar_conti::Object_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa7779c5b6537b3dcULL;
  static const uint64_t static_value2 = 0x9690537349901eebULL;
};

template<class ContainerAllocator>
struct DataType< ::radar_conti::Object_<ContainerAllocator> >
{
  static const char* value()
  {
    return "radar_conti/Object";
  }

  static const char* value(const ::radar_conti::Object_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::radar_conti::Object_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Int32 obj_id\n"
"ObjectGeneral object_general\n"
"ObjectExtended object_extended\n"
"ObjectQuality object_quality\n"
"================================================================================\n"
"MSG: std_msgs/Int32\n"
"int32 data\n"
"================================================================================\n"
"MSG: radar_conti/ObjectGeneral\n"
"#  ------------------------------------------------------------------------\n"
"#\n"
"#  Name:       Obj_1_General\n"
"#  Id:         0x60b\n"
"#  Length:     8 bytes\n"
"#  Cycle time: 0 ms\n"
"#  Senders:    ARS_ISF\n"
"#  Layout:\n"
"#\n"
"#                          Bit\n"
"#\n"
"#             7   6   5   4   3   2   1   0\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         0 |<-----------------------------x|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                                         +-- Obj_ID\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         1 |<------------------------------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         2 |------------------x|<----------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                             +-- Obj_DistLong\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         3 |------------------------------x|\n"
"#     B     +---+---+---+---+---+---+---+---+\n"
"#     y                                   +-- Obj_DistLat\n"
"#     t     +---+---+---+---+---+---+---+---+\n"
"#     e   4 |<------------------------------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         5 |------x|<----------------------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                 +-- Obj_VrelLong\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         6 |----------x|   |   |<---------x|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                     |                   +-- Obj_DynProp\n"
"#                     +-- Obj_VrelLat\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         7 |<-----------------------------x|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                                         +-- Obj_RCS\n"
"#\n"
"#  Signal tree:\n"
"#\n"
"#    -- {root}\n"
"#       +-- Obj_ID\n"
"#       +-- Obj_DistLong\n"
"#       +-- Obj_DistLat\n"
"#       +-- Obj_VrelLong\n"
"#       +-- Obj_VrelLat\n"
"#       +-- Obj_DynProp\n"
"#       +-- Obj_RCS\n"
"#\n"
"#  ------------------------------------------------------------------------\n"
"#\n"
"std_msgs/Float64 obj_distlong\n"
"std_msgs/Float64 obj_distlat\n"
"std_msgs/Float64 obj_vrellong\n"
"std_msgs/Float64 obj_vrellat\n"
"std_msgs/String obj_dynprop\n"
"std_msgs/Float64 obj_rcs\n"
"================================================================================\n"
"MSG: std_msgs/Float64\n"
"float64 data\n"
"================================================================================\n"
"MSG: std_msgs/String\n"
"string data\n"
"\n"
"================================================================================\n"
"MSG: radar_conti/ObjectExtended\n"
"#  ------------------------------------------------------------------------\n"
"#\n"
"#  Name:       Obj_3_Extended\n"
"#  Id:         0x60d\n"
"#  Length:     8 bytes\n"
"#  Cycle time: 0 ms\n"
"#  Senders:    ARS_ISF\n"
"#  Layout:\n"
"#\n"
"#                          Bit\n"
"#\n"
"#             7   6   5   4   3   2   1   0\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         0 |<-----------------------------x|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                                         +-- Obj_ID\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         1 |<------------------------------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         2 |----------x|<------------------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                     +-- Obj_ArelLong\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         3 |--------------x|   |<---------x|\n"
"#     B     +---+---+---+---+---+---+---+---+\n"
"#     y                   |               +-- Obj_Class\n"
"#     t                   +-- Obj_ArelLat\n"
"#     e     +---+---+---+---+---+---+---+---+\n"
"#         4 |<------------------------------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         5 |------x|   |   |   |   |   |   |\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                 +-- Obj_OrientationAngle\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         6 |<-----------------------------x|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                                         +-- Obj_Length\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         7 |<-----------------------------x|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                                         +-- Obj_Width\n"
"#\n"
"#  Signal tree:\n"
"#\n"
"#    -- {root}\n"
"#       +-- Obj_ID\n"
"#       +-- Obj_ArelLong\n"
"#       +-- Obj_ArelLat\n"
"#       +-- Obj_Class\n"
"#       +-- Obj_OrientationAngle\n"
"#       +-- Obj_Length\n"
"#       +-- Obj_Width\n"
"#\n"
"#  ------------------------------------------------------------------------\n"
"#\n"
"std_msgs/Float64 obj_arellong\n"
"std_msgs/Float64 obj_arellat\n"
"std_msgs/Int32 obj_class\n"
"std_msgs/Float64 obj_orientationangle\n"
"std_msgs/Float64 obj_length\n"
"std_msgs/Float64 obj_width\n"
"================================================================================\n"
"MSG: radar_conti/ObjectQuality\n"
"#  ------------------------------------------------------------------------\n"
"#\n"
"#  Name:       Obj_2_Quality\n"
"#  Id:         0x60c\n"
"#  Length:     7 bytes\n"
"#  Cycle time: 0 ms\n"
"#  Senders:    ARS_ISF\n"
"#  Layout:\n"
"#\n"
"#                          Bit\n"
"#\n"
"#             7   6   5   4   3   2   1   0\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         0 |<-----------------------------x|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                                         +-- Obj_ID\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         1 |<-----------------x|<----------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                             +-- Obj_DistLong_rms\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         2 |------x|<-----------------x|<--|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                 |                   +-- Obj_VrelLong_rms\n"
"#                 +-- Obj_DistLat_rms\n"
"#     B     +---+---+---+---+---+---+---+---+\n"
"#     y   3 |--------------x|<--------------|\n"
"#     t     +---+---+---+---+---+---+---+---+\n"
"#     e                   +-- Obj_VrelLat_rms\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         4 |--x|<-----------------x|<------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#             |                   +-- Obj_ArelLat_rms\n"
"#             +-- Obj_ArelLong_rms\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         5 |----------x|   |   |   |   |   |\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                     +-- Obj_Orientation_rms\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         6 |<---------x|<---------x|   |   |\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                     |           +-- Obj_MeasState\n"
"#                     +-- Obj_ProbOfExist\n"
"#\n"
"#  Signal tree:\n"
"#\n"
"#    -- {root}\n"
"#       +-- Obj_ID\n"
"#       +-- Obj_DistLong_rms\n"
"#       +-- Obj_DistLat_rms\n"
"#       +-- Obj_VrelLong_rms\n"
"#       +-- Obj_VrelLat_rms\n"
"#       +-- Obj_ArelLong_rms\n"
"#       +-- Obj_ArelLat_rms\n"
"#       +-- Obj_Orientation_rms\n"
"#       +-- Obj_ProbOfExist\n"
"#       +-- Obj_MeasState\n"
"#\n"
"#  ------------------------------------------------------------------------\n"
"std_msgs/Float64 obj_distlong_rms\n"
"std_msgs/Float64 obj_distlat_rms\n"
"std_msgs/Float64 obj_vrellong_rms\n"
"std_msgs/Float64 obj_vrellat_rms\n"
"std_msgs/Float64 obj_arellong_rms\n"
"std_msgs/Float64 obj_arellat_rms\n"
"std_msgs/Float64 obj_orientation_rms\n"
"std_msgs/Float64 obj_probofexist\n"
"std_msgs/String  obj_measstate\n"
;
  }

  static const char* value(const ::radar_conti::Object_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::radar_conti::Object_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.obj_id);
      stream.next(m.object_general);
      stream.next(m.object_extended);
      stream.next(m.object_quality);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Object_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::radar_conti::Object_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::radar_conti::Object_<ContainerAllocator>& v)
  {
    s << indent << "obj_id: ";
    s << std::endl;
    Printer< ::std_msgs::Int32_<ContainerAllocator> >::stream(s, indent + "  ", v.obj_id);
    s << indent << "object_general: ";
    s << std::endl;
    Printer< ::radar_conti::ObjectGeneral_<ContainerAllocator> >::stream(s, indent + "  ", v.object_general);
    s << indent << "object_extended: ";
    s << std::endl;
    Printer< ::radar_conti::ObjectExtended_<ContainerAllocator> >::stream(s, indent + "  ", v.object_extended);
    s << indent << "object_quality: ";
    s << std::endl;
    Printer< ::radar_conti::ObjectQuality_<ContainerAllocator> >::stream(s, indent + "  ", v.object_quality);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RADAR_CONTI_MESSAGE_OBJECT_H

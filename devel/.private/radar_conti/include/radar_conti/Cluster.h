// Generated by gencpp from file radar_conti/Cluster.msg
// DO NOT EDIT!


#ifndef RADAR_CONTI_MESSAGE_CLUSTER_H
#define RADAR_CONTI_MESSAGE_CLUSTER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Int32.h>
#include <radar_conti/ClusterGeneral.h>
#include <radar_conti/ClusterQuality.h>

namespace radar_conti
{
template <class ContainerAllocator>
struct Cluster_
{
  typedef Cluster_<ContainerAllocator> Type;

  Cluster_()
    : cluster_id()
    , cluster_general()
    , cluster_quality()  {
    }
  Cluster_(const ContainerAllocator& _alloc)
    : cluster_id(_alloc)
    , cluster_general(_alloc)
    , cluster_quality(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Int32_<ContainerAllocator>  _cluster_id_type;
  _cluster_id_type cluster_id;

   typedef  ::radar_conti::ClusterGeneral_<ContainerAllocator>  _cluster_general_type;
  _cluster_general_type cluster_general;

   typedef  ::radar_conti::ClusterQuality_<ContainerAllocator>  _cluster_quality_type;
  _cluster_quality_type cluster_quality;





  typedef boost::shared_ptr< ::radar_conti::Cluster_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::radar_conti::Cluster_<ContainerAllocator> const> ConstPtr;

}; // struct Cluster_

typedef ::radar_conti::Cluster_<std::allocator<void> > Cluster;

typedef boost::shared_ptr< ::radar_conti::Cluster > ClusterPtr;
typedef boost::shared_ptr< ::radar_conti::Cluster const> ClusterConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::radar_conti::Cluster_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::radar_conti::Cluster_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::radar_conti::Cluster_<ContainerAllocator1> & lhs, const ::radar_conti::Cluster_<ContainerAllocator2> & rhs)
{
  return lhs.cluster_id == rhs.cluster_id &&
    lhs.cluster_general == rhs.cluster_general &&
    lhs.cluster_quality == rhs.cluster_quality;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::radar_conti::Cluster_<ContainerAllocator1> & lhs, const ::radar_conti::Cluster_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace radar_conti

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::radar_conti::Cluster_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::radar_conti::Cluster_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::radar_conti::Cluster_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::radar_conti::Cluster_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::radar_conti::Cluster_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::radar_conti::Cluster_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::radar_conti::Cluster_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2811095d8cefca700603904d21f118c9";
  }

  static const char* value(const ::radar_conti::Cluster_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2811095d8cefca70ULL;
  static const uint64_t static_value2 = 0x0603904d21f118c9ULL;
};

template<class ContainerAllocator>
struct DataType< ::radar_conti::Cluster_<ContainerAllocator> >
{
  static const char* value()
  {
    return "radar_conti/Cluster";
  }

  static const char* value(const ::radar_conti::Cluster_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::radar_conti::Cluster_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Int32 cluster_id\n"
"ClusterGeneral cluster_general\n"
"ClusterQuality cluster_quality\n"
"================================================================================\n"
"MSG: std_msgs/Int32\n"
"int32 data\n"
"================================================================================\n"
"MSG: radar_conti/ClusterGeneral\n"
"#  ------------------------------------------------------------------------\n"
"#\n"
"#  Name:       Cluster_1_General\n"
"#  Id:         0x701\n"
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
"#                                         +-- Cluster_ID\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         1 |<------------------------------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         2 |------------------x|   |<------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                             +-- Cluster_DistLong\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         3 |------------------------------x|\n"
"#     B     +---+---+---+---+---+---+---+---+\n"
"#     y                                   +-- Cluster_DistLat\n"
"#     t     +---+---+---+---+---+---+---+---+\n"
"#     e   4 |<------------------------------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         5 |------x|<----------------------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                 +-- Cluster_VrelLong\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         6 |----------x|   |   |<---------x|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                     |                   +-- Cluster_DynProp\n"
"#                     +-- Cluster_VrelLat\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         7 |<-----------------------------x|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                                         +-- Cluster_RCS\n"
"#\n"
"#  Signal tree:\n"
"#\n"
"#    -- {root}\n"
"#       +-- Cluster_ID\n"
"#       +-- Cluster_DistLong\n"
"#       +-- Cluster_DistLat\n"
"#       +-- Cluster_VrelLong\n"
"#       +-- Cluster_VrelLat\n"
"#       +-- Cluster_DynProp\n"
"#       +-- Cluster_RCS\n"
"#\n"
"#  ------------------------------------------------------------------------\n"
"std_msgs/Float64 cluster_distlong\n"
"std_msgs/Float64 cluster_distlat\n"
"std_msgs/Float64 cluster_vrellong\n"
"std_msgs/Float64 cluster_vrellat\n"
"std_msgs/Int32   cluster_dynprop\n"
"std_msgs/Float64 cluster_rcs\n"
"================================================================================\n"
"MSG: std_msgs/Float64\n"
"float64 data\n"
"================================================================================\n"
"MSG: radar_conti/ClusterQuality\n"
"#  ------------------------------------------------------------------------\n"
"#\n"
"#  Name:       Cluster_2_Quality\n"
"#  Id:         0x702\n"
"#  Length:     5 bytes\n"
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
"#                                         +-- Cluster_ID\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         1 |<-----------------x|<----------|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                             +-- Cluster_DistLong_rms\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#     B   2 |------x|<-----------------x|<--|\n"
"#     y     +---+---+---+---+---+---+---+---+\n"
"#     t           |                   +-- Cluster_VrelLong_rms\n"
"#     e           +-- Cluster_DistLat_rms\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         3 |--------------x|   |<---------x|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                         |               +-- Cluster_PdH0\n"
"#                         +-- Cluster_VrelLat_rms\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         4 |<-----------------x|<---------x|\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                             |           +-- Cluster_AmbigState\n"
"#                             +-- Cluster_InvalidState\n"
"#\n"
"#  Signal tree:\n"
"#\n"
"#    -- {root}\n"
"#       +-- Cluster_ID\n"
"#       +-- Cluster_DistLong_rms\n"
"#       +-- Cluster_DistLat_rms\n"
"#       +-- Cluster_VrelLong_rms\n"
"#       +-- Cluster_VrelLat_rms\n"
"#       +-- Cluster_PdH0\n"
"#       +-- Cluster_InvalidState\n"
"#       +-- Cluster_AmbigState\n"
"#\n"
"#  ------------------------------------------------------------------------\n"
"#\n"
"std_msgs/Float64 cluster_distlong_rms\n"
"std_msgs/Float64 cluster_distlat_rms\n"
"std_msgs/Float64 cluster_vrellong_rms\n"
"std_msgs/Float64 cluster_vrellat_rms\n"
"std_msgs/String cluster_pdh0\n"
"std_msgs/String cluster_invalidstate\n"
"std_msgs/String cluster_ambigstate\n"
"================================================================================\n"
"MSG: std_msgs/String\n"
"string data\n"
;
  }

  static const char* value(const ::radar_conti::Cluster_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::radar_conti::Cluster_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cluster_id);
      stream.next(m.cluster_general);
      stream.next(m.cluster_quality);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Cluster_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::radar_conti::Cluster_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::radar_conti::Cluster_<ContainerAllocator>& v)
  {
    s << indent << "cluster_id: ";
    s << std::endl;
    Printer< ::std_msgs::Int32_<ContainerAllocator> >::stream(s, indent + "  ", v.cluster_id);
    s << indent << "cluster_general: ";
    s << std::endl;
    Printer< ::radar_conti::ClusterGeneral_<ContainerAllocator> >::stream(s, indent + "  ", v.cluster_general);
    s << indent << "cluster_quality: ";
    s << std::endl;
    Printer< ::radar_conti::ClusterQuality_<ContainerAllocator> >::stream(s, indent + "  ", v.cluster_quality);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RADAR_CONTI_MESSAGE_CLUSTER_H

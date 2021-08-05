// Generated by gencpp from file radar_conti/ObjectStatus.msg
// DO NOT EDIT!


#ifndef RADAR_CONTI_MESSAGE_OBJECTSTATUS_H
#define RADAR_CONTI_MESSAGE_OBJECTSTATUS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Int32.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int32.h>

namespace radar_conti
{
template <class ContainerAllocator>
struct ObjectStatus_
{
  typedef ObjectStatus_<ContainerAllocator> Type;

  ObjectStatus_()
    : obj_nofobjects()
    , obj_meascounter()
    , obj_interfaceversion()  {
    }
  ObjectStatus_(const ContainerAllocator& _alloc)
    : obj_nofobjects(_alloc)
    , obj_meascounter(_alloc)
    , obj_interfaceversion(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Int32_<ContainerAllocator>  _obj_nofobjects_type;
  _obj_nofobjects_type obj_nofobjects;

   typedef  ::std_msgs::Int32_<ContainerAllocator>  _obj_meascounter_type;
  _obj_meascounter_type obj_meascounter;

   typedef  ::std_msgs::Int32_<ContainerAllocator>  _obj_interfaceversion_type;
  _obj_interfaceversion_type obj_interfaceversion;





  typedef boost::shared_ptr< ::radar_conti::ObjectStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::radar_conti::ObjectStatus_<ContainerAllocator> const> ConstPtr;

}; // struct ObjectStatus_

typedef ::radar_conti::ObjectStatus_<std::allocator<void> > ObjectStatus;

typedef boost::shared_ptr< ::radar_conti::ObjectStatus > ObjectStatusPtr;
typedef boost::shared_ptr< ::radar_conti::ObjectStatus const> ObjectStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::radar_conti::ObjectStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::radar_conti::ObjectStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::radar_conti::ObjectStatus_<ContainerAllocator1> & lhs, const ::radar_conti::ObjectStatus_<ContainerAllocator2> & rhs)
{
  return lhs.obj_nofobjects == rhs.obj_nofobjects &&
    lhs.obj_meascounter == rhs.obj_meascounter &&
    lhs.obj_interfaceversion == rhs.obj_interfaceversion;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::radar_conti::ObjectStatus_<ContainerAllocator1> & lhs, const ::radar_conti::ObjectStatus_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace radar_conti

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::radar_conti::ObjectStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::radar_conti::ObjectStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::radar_conti::ObjectStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::radar_conti::ObjectStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::radar_conti::ObjectStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::radar_conti::ObjectStatus_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::radar_conti::ObjectStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9bce59d00818d64eb8f4cd2b557dee63";
  }

  static const char* value(const ::radar_conti::ObjectStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9bce59d00818d64eULL;
  static const uint64_t static_value2 = 0xb8f4cd2b557dee63ULL;
};

template<class ContainerAllocator>
struct DataType< ::radar_conti::ObjectStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "radar_conti/ObjectStatus";
  }

  static const char* value(const ::radar_conti::ObjectStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::radar_conti::ObjectStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#  ------------------------------------------------------------------------\n"
"#\n"
"#  Name:       Obj_0_Status\n"
"#  Id:         0x60a\n"
"#  Length:     4 bytes\n"
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
"#                                         +-- Obj_NofObjects\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#     B   1 |<------------------------------|\n"
"#     y     +---+---+---+---+---+---+---+---+\n"
"#     t   2 |------------------------------x|\n"
"#     e     +---+---+---+---+---+---+---+---+\n"
"#                                         +-- Obj_MeasCounter\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#         3 |<-------------x|   |   |   |   |\n"
"#           +---+---+---+---+---+---+---+---+\n"
"#                         +-- Obj_InterfaceVersion\n"
"#\n"
"#  Signal tree:\n"
"#\n"
"#    -- {root}\n"
"#       +-- Obj_NofObjects\n"
"#       +-- Obj_MeasCounter\n"
"#       +-- Obj_InterfaceVersion\n"
"#\n"
"#  ------------------------------------------------------------------------\n"
"#\n"
"std_msgs/Int32 obj_nofobjects\n"
"std_msgs/Int32 obj_meascounter\n"
"std_msgs/Int32 obj_interfaceversion\n"
"================================================================================\n"
"MSG: std_msgs/Int32\n"
"int32 data\n"
;
  }

  static const char* value(const ::radar_conti::ObjectStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::radar_conti::ObjectStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.obj_nofobjects);
      stream.next(m.obj_meascounter);
      stream.next(m.obj_interfaceversion);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ObjectStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::radar_conti::ObjectStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::radar_conti::ObjectStatus_<ContainerAllocator>& v)
  {
    s << indent << "obj_nofobjects: ";
    s << std::endl;
    Printer< ::std_msgs::Int32_<ContainerAllocator> >::stream(s, indent + "  ", v.obj_nofobjects);
    s << indent << "obj_meascounter: ";
    s << std::endl;
    Printer< ::std_msgs::Int32_<ContainerAllocator> >::stream(s, indent + "  ", v.obj_meascounter);
    s << indent << "obj_interfaceversion: ";
    s << std::endl;
    Printer< ::std_msgs::Int32_<ContainerAllocator> >::stream(s, indent + "  ", v.obj_interfaceversion);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RADAR_CONTI_MESSAGE_OBJECTSTATUS_H

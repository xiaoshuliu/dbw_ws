// Generated by gencpp from file aruco_msgs/MarkerArray.msg
// DO NOT EDIT!


#ifndef ARUCO_MSGS_MESSAGE_MARKERARRAY_H
#define ARUCO_MSGS_MESSAGE_MARKERARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <aruco_msgs/Marker.h>

namespace aruco_msgs
{
template <class ContainerAllocator>
struct MarkerArray_
{
  typedef MarkerArray_<ContainerAllocator> Type;

  MarkerArray_()
    : header()
    , markers()  {
    }
  MarkerArray_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , markers(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::aruco_msgs::Marker_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::aruco_msgs::Marker_<ContainerAllocator> >::other >  _markers_type;
  _markers_type markers;




  typedef boost::shared_ptr< ::aruco_msgs::MarkerArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::aruco_msgs::MarkerArray_<ContainerAllocator> const> ConstPtr;

}; // struct MarkerArray_

typedef ::aruco_msgs::MarkerArray_<std::allocator<void> > MarkerArray;

typedef boost::shared_ptr< ::aruco_msgs::MarkerArray > MarkerArrayPtr;
typedef boost::shared_ptr< ::aruco_msgs::MarkerArray const> MarkerArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::aruco_msgs::MarkerArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::aruco_msgs::MarkerArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace aruco_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'aruco_msgs': ['/home/liu/dbw_ws/src/aruco_ros/aruco_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::aruco_msgs::MarkerArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::aruco_msgs::MarkerArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::aruco_msgs::MarkerArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::aruco_msgs::MarkerArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::aruco_msgs::MarkerArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::aruco_msgs::MarkerArray_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::aruco_msgs::MarkerArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9d486b76ee1f72a8b0d33e8c66a97306";
  }

  static const char* value(const ::aruco_msgs::MarkerArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9d486b76ee1f72a8ULL;
  static const uint64_t static_value2 = 0xb0d33e8c66a97306ULL;
};

template<class ContainerAllocator>
struct DataType< ::aruco_msgs::MarkerArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "aruco_msgs/MarkerArray";
  }

  static const char* value(const ::aruco_msgs::MarkerArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::aruco_msgs::MarkerArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
aruco_msgs/Marker[] markers\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: aruco_msgs/Marker\n\
Header header\n\
uint32 id\n\
geometry_msgs/PoseWithCovariance pose\n\
float64 confidence\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseWithCovariance\n\
# This represents a pose in free space with uncertainty.\n\
\n\
Pose pose\n\
\n\
# Row-major representation of the 6x6 covariance matrix\n\
# The orientation parameters use a fixed-axis representation.\n\
# In order, the parameters are:\n\
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n\
float64[36] covariance\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::aruco_msgs::MarkerArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::aruco_msgs::MarkerArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.markers);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MarkerArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::aruco_msgs::MarkerArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::aruco_msgs::MarkerArray_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "markers[]" << std::endl;
    for (size_t i = 0; i < v.markers.size(); ++i)
    {
      s << indent << "  markers[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::aruco_msgs::Marker_<ContainerAllocator> >::stream(s, indent + "    ", v.markers[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARUCO_MSGS_MESSAGE_MARKERARRAY_H

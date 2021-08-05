# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from radar_conti/ObjectList.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import radar_conti.msg
import std_msgs.msg

class ObjectList(genpy.Message):
  _md5sum = "c7dbccc0809b5bdaa59e6da1bf9289de"
  _type = "radar_conti/ObjectList"
  _has_header = True  # flag to mark the presence of a Header object
  _full_text = """std_msgs/Header header
std_msgs/Int32 object_count
Object[] objects
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: std_msgs/Int32
int32 data
================================================================================
MSG: radar_conti/Object
std_msgs/Int32 obj_id
ObjectGeneral object_general
ObjectExtended object_extended
ObjectQuality object_quality
================================================================================
MSG: radar_conti/ObjectGeneral
#  ------------------------------------------------------------------------
#
#  Name:       Obj_1_General
#  Id:         0x60b
#  Length:     8 bytes
#  Cycle time: 0 ms
#  Senders:    ARS_ISF
#  Layout:
#
#                          Bit
#
#             7   6   5   4   3   2   1   0
#           +---+---+---+---+---+---+---+---+
#         0 |<-----------------------------x|
#           +---+---+---+---+---+---+---+---+
#                                         +-- Obj_ID
#           +---+---+---+---+---+---+---+---+
#         1 |<------------------------------|
#           +---+---+---+---+---+---+---+---+
#         2 |------------------x|<----------|
#           +---+---+---+---+---+---+---+---+
#                             +-- Obj_DistLong
#           +---+---+---+---+---+---+---+---+
#         3 |------------------------------x|
#     B     +---+---+---+---+---+---+---+---+
#     y                                   +-- Obj_DistLat
#     t     +---+---+---+---+---+---+---+---+
#     e   4 |<------------------------------|
#           +---+---+---+---+---+---+---+---+
#         5 |------x|<----------------------|
#           +---+---+---+---+---+---+---+---+
#                 +-- Obj_VrelLong
#           +---+---+---+---+---+---+---+---+
#         6 |----------x|   |   |<---------x|
#           +---+---+---+---+---+---+---+---+
#                     |                   +-- Obj_DynProp
#                     +-- Obj_VrelLat
#           +---+---+---+---+---+---+---+---+
#         7 |<-----------------------------x|
#           +---+---+---+---+---+---+---+---+
#                                         +-- Obj_RCS
#
#  Signal tree:
#
#    -- {root}
#       +-- Obj_ID
#       +-- Obj_DistLong
#       +-- Obj_DistLat
#       +-- Obj_VrelLong
#       +-- Obj_VrelLat
#       +-- Obj_DynProp
#       +-- Obj_RCS
#
#  ------------------------------------------------------------------------
#
std_msgs/Float64 obj_distlong
std_msgs/Float64 obj_distlat
std_msgs/Float64 obj_vrellong
std_msgs/Float64 obj_vrellat
std_msgs/String obj_dynprop
std_msgs/Float64 obj_rcs
================================================================================
MSG: std_msgs/Float64
float64 data
================================================================================
MSG: std_msgs/String
string data

================================================================================
MSG: radar_conti/ObjectExtended
#  ------------------------------------------------------------------------
#
#  Name:       Obj_3_Extended
#  Id:         0x60d
#  Length:     8 bytes
#  Cycle time: 0 ms
#  Senders:    ARS_ISF
#  Layout:
#
#                          Bit
#
#             7   6   5   4   3   2   1   0
#           +---+---+---+---+---+---+---+---+
#         0 |<-----------------------------x|
#           +---+---+---+---+---+---+---+---+
#                                         +-- Obj_ID
#           +---+---+---+---+---+---+---+---+
#         1 |<------------------------------|
#           +---+---+---+---+---+---+---+---+
#         2 |----------x|<------------------|
#           +---+---+---+---+---+---+---+---+
#                     +-- Obj_ArelLong
#           +---+---+---+---+---+---+---+---+
#         3 |--------------x|   |<---------x|
#     B     +---+---+---+---+---+---+---+---+
#     y                   |               +-- Obj_Class
#     t                   +-- Obj_ArelLat
#     e     +---+---+---+---+---+---+---+---+
#         4 |<------------------------------|
#           +---+---+---+---+---+---+---+---+
#         5 |------x|   |   |   |   |   |   |
#           +---+---+---+---+---+---+---+---+
#                 +-- Obj_OrientationAngle
#           +---+---+---+---+---+---+---+---+
#         6 |<-----------------------------x|
#           +---+---+---+---+---+---+---+---+
#                                         +-- Obj_Length
#           +---+---+---+---+---+---+---+---+
#         7 |<-----------------------------x|
#           +---+---+---+---+---+---+---+---+
#                                         +-- Obj_Width
#
#  Signal tree:
#
#    -- {root}
#       +-- Obj_ID
#       +-- Obj_ArelLong
#       +-- Obj_ArelLat
#       +-- Obj_Class
#       +-- Obj_OrientationAngle
#       +-- Obj_Length
#       +-- Obj_Width
#
#  ------------------------------------------------------------------------
#
std_msgs/Float64 obj_arellong
std_msgs/Float64 obj_arellat
std_msgs/Int32 obj_class
std_msgs/Float64 obj_orientationangle
std_msgs/Float64 obj_length
std_msgs/Float64 obj_width
================================================================================
MSG: radar_conti/ObjectQuality
#  ------------------------------------------------------------------------
#
#  Name:       Obj_2_Quality
#  Id:         0x60c
#  Length:     7 bytes
#  Cycle time: 0 ms
#  Senders:    ARS_ISF
#  Layout:
#
#                          Bit
#
#             7   6   5   4   3   2   1   0
#           +---+---+---+---+---+---+---+---+
#         0 |<-----------------------------x|
#           +---+---+---+---+---+---+---+---+
#                                         +-- Obj_ID
#           +---+---+---+---+---+---+---+---+
#         1 |<-----------------x|<----------|
#           +---+---+---+---+---+---+---+---+
#                             +-- Obj_DistLong_rms
#           +---+---+---+---+---+---+---+---+
#         2 |------x|<-----------------x|<--|
#           +---+---+---+---+---+---+---+---+
#                 |                   +-- Obj_VrelLong_rms
#                 +-- Obj_DistLat_rms
#     B     +---+---+---+---+---+---+---+---+
#     y   3 |--------------x|<--------------|
#     t     +---+---+---+---+---+---+---+---+
#     e                   +-- Obj_VrelLat_rms
#           +---+---+---+---+---+---+---+---+
#         4 |--x|<-----------------x|<------|
#           +---+---+---+---+---+---+---+---+
#             |                   +-- Obj_ArelLat_rms
#             +-- Obj_ArelLong_rms
#           +---+---+---+---+---+---+---+---+
#         5 |----------x|   |   |   |   |   |
#           +---+---+---+---+---+---+---+---+
#                     +-- Obj_Orientation_rms
#           +---+---+---+---+---+---+---+---+
#         6 |<---------x|<---------x|   |   |
#           +---+---+---+---+---+---+---+---+
#                     |           +-- Obj_MeasState
#                     +-- Obj_ProbOfExist
#
#  Signal tree:
#
#    -- {root}
#       +-- Obj_ID
#       +-- Obj_DistLong_rms
#       +-- Obj_DistLat_rms
#       +-- Obj_VrelLong_rms
#       +-- Obj_VrelLat_rms
#       +-- Obj_ArelLong_rms
#       +-- Obj_ArelLat_rms
#       +-- Obj_Orientation_rms
#       +-- Obj_ProbOfExist
#       +-- Obj_MeasState
#
#  ------------------------------------------------------------------------
std_msgs/Float64 obj_distlong_rms
std_msgs/Float64 obj_distlat_rms
std_msgs/Float64 obj_vrellong_rms
std_msgs/Float64 obj_vrellat_rms
std_msgs/Float64 obj_arellong_rms
std_msgs/Float64 obj_arellat_rms
std_msgs/Float64 obj_orientation_rms
std_msgs/Float64 obj_probofexist
std_msgs/String  obj_measstate"""
  __slots__ = ['header','object_count','objects']
  _slot_types = ['std_msgs/Header','std_msgs/Int32','radar_conti/Object[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,object_count,objects

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ObjectList, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.object_count is None:
        self.object_count = std_msgs.msg.Int32()
      if self.objects is None:
        self.objects = []
    else:
      self.header = std_msgs.msg.Header()
      self.object_count = std_msgs.msg.Int32()
      self.objects = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.object_count.data
      buff.write(_get_struct_i().pack(_x))
      length = len(self.objects)
      buff.write(_struct_I.pack(length))
      for val1 in self.objects:
        _v1 = val1.obj_id
        _x = _v1.data
        buff.write(_get_struct_i().pack(_x))
        _v2 = val1.object_general
        _v3 = _v2.obj_distlong
        _x = _v3.data
        buff.write(_get_struct_d().pack(_x))
        _v4 = _v2.obj_distlat
        _x = _v4.data
        buff.write(_get_struct_d().pack(_x))
        _v5 = _v2.obj_vrellong
        _x = _v5.data
        buff.write(_get_struct_d().pack(_x))
        _v6 = _v2.obj_vrellat
        _x = _v6.data
        buff.write(_get_struct_d().pack(_x))
        _v7 = _v2.obj_dynprop
        _x = _v7.data
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _v8 = _v2.obj_rcs
        _x = _v8.data
        buff.write(_get_struct_d().pack(_x))
        _v9 = val1.object_extended
        _v10 = _v9.obj_arellong
        _x = _v10.data
        buff.write(_get_struct_d().pack(_x))
        _v11 = _v9.obj_arellat
        _x = _v11.data
        buff.write(_get_struct_d().pack(_x))
        _v12 = _v9.obj_class
        _x = _v12.data
        buff.write(_get_struct_i().pack(_x))
        _v13 = _v9.obj_orientationangle
        _x = _v13.data
        buff.write(_get_struct_d().pack(_x))
        _v14 = _v9.obj_length
        _x = _v14.data
        buff.write(_get_struct_d().pack(_x))
        _v15 = _v9.obj_width
        _x = _v15.data
        buff.write(_get_struct_d().pack(_x))
        _v16 = val1.object_quality
        _v17 = _v16.obj_distlong_rms
        _x = _v17.data
        buff.write(_get_struct_d().pack(_x))
        _v18 = _v16.obj_distlat_rms
        _x = _v18.data
        buff.write(_get_struct_d().pack(_x))
        _v19 = _v16.obj_vrellong_rms
        _x = _v19.data
        buff.write(_get_struct_d().pack(_x))
        _v20 = _v16.obj_vrellat_rms
        _x = _v20.data
        buff.write(_get_struct_d().pack(_x))
        _v21 = _v16.obj_arellong_rms
        _x = _v21.data
        buff.write(_get_struct_d().pack(_x))
        _v22 = _v16.obj_arellat_rms
        _x = _v22.data
        buff.write(_get_struct_d().pack(_x))
        _v23 = _v16.obj_orientation_rms
        _x = _v23.data
        buff.write(_get_struct_d().pack(_x))
        _v24 = _v16.obj_probofexist
        _x = _v24.data
        buff.write(_get_struct_d().pack(_x))
        _v25 = _v16.obj_measstate
        _x = _v25.data
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.object_count is None:
        self.object_count = std_msgs.msg.Int32()
      if self.objects is None:
        self.objects = None
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.header.frame_id = str[start:end]
      start = end
      end += 4
      (self.object_count.data,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.objects = []
      for i in range(0, length):
        val1 = radar_conti.msg.Object()
        _v26 = val1.obj_id
        start = end
        end += 4
        (_v26.data,) = _get_struct_i().unpack(str[start:end])
        _v27 = val1.object_general
        _v28 = _v27.obj_distlong
        start = end
        end += 8
        (_v28.data,) = _get_struct_d().unpack(str[start:end])
        _v29 = _v27.obj_distlat
        start = end
        end += 8
        (_v29.data,) = _get_struct_d().unpack(str[start:end])
        _v30 = _v27.obj_vrellong
        start = end
        end += 8
        (_v30.data,) = _get_struct_d().unpack(str[start:end])
        _v31 = _v27.obj_vrellat
        start = end
        end += 8
        (_v31.data,) = _get_struct_d().unpack(str[start:end])
        _v32 = _v27.obj_dynprop
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v32.data = str[start:end].decode('utf-8', 'rosmsg')
        else:
          _v32.data = str[start:end]
        _v33 = _v27.obj_rcs
        start = end
        end += 8
        (_v33.data,) = _get_struct_d().unpack(str[start:end])
        _v34 = val1.object_extended
        _v35 = _v34.obj_arellong
        start = end
        end += 8
        (_v35.data,) = _get_struct_d().unpack(str[start:end])
        _v36 = _v34.obj_arellat
        start = end
        end += 8
        (_v36.data,) = _get_struct_d().unpack(str[start:end])
        _v37 = _v34.obj_class
        start = end
        end += 4
        (_v37.data,) = _get_struct_i().unpack(str[start:end])
        _v38 = _v34.obj_orientationangle
        start = end
        end += 8
        (_v38.data,) = _get_struct_d().unpack(str[start:end])
        _v39 = _v34.obj_length
        start = end
        end += 8
        (_v39.data,) = _get_struct_d().unpack(str[start:end])
        _v40 = _v34.obj_width
        start = end
        end += 8
        (_v40.data,) = _get_struct_d().unpack(str[start:end])
        _v41 = val1.object_quality
        _v42 = _v41.obj_distlong_rms
        start = end
        end += 8
        (_v42.data,) = _get_struct_d().unpack(str[start:end])
        _v43 = _v41.obj_distlat_rms
        start = end
        end += 8
        (_v43.data,) = _get_struct_d().unpack(str[start:end])
        _v44 = _v41.obj_vrellong_rms
        start = end
        end += 8
        (_v44.data,) = _get_struct_d().unpack(str[start:end])
        _v45 = _v41.obj_vrellat_rms
        start = end
        end += 8
        (_v45.data,) = _get_struct_d().unpack(str[start:end])
        _v46 = _v41.obj_arellong_rms
        start = end
        end += 8
        (_v46.data,) = _get_struct_d().unpack(str[start:end])
        _v47 = _v41.obj_arellat_rms
        start = end
        end += 8
        (_v47.data,) = _get_struct_d().unpack(str[start:end])
        _v48 = _v41.obj_orientation_rms
        start = end
        end += 8
        (_v48.data,) = _get_struct_d().unpack(str[start:end])
        _v49 = _v41.obj_probofexist
        start = end
        end += 8
        (_v49.data,) = _get_struct_d().unpack(str[start:end])
        _v50 = _v41.obj_measstate
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v50.data = str[start:end].decode('utf-8', 'rosmsg')
        else:
          _v50.data = str[start:end]
        self.objects.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.object_count.data
      buff.write(_get_struct_i().pack(_x))
      length = len(self.objects)
      buff.write(_struct_I.pack(length))
      for val1 in self.objects:
        _v51 = val1.obj_id
        _x = _v51.data
        buff.write(_get_struct_i().pack(_x))
        _v52 = val1.object_general
        _v53 = _v52.obj_distlong
        _x = _v53.data
        buff.write(_get_struct_d().pack(_x))
        _v54 = _v52.obj_distlat
        _x = _v54.data
        buff.write(_get_struct_d().pack(_x))
        _v55 = _v52.obj_vrellong
        _x = _v55.data
        buff.write(_get_struct_d().pack(_x))
        _v56 = _v52.obj_vrellat
        _x = _v56.data
        buff.write(_get_struct_d().pack(_x))
        _v57 = _v52.obj_dynprop
        _x = _v57.data
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _v58 = _v52.obj_rcs
        _x = _v58.data
        buff.write(_get_struct_d().pack(_x))
        _v59 = val1.object_extended
        _v60 = _v59.obj_arellong
        _x = _v60.data
        buff.write(_get_struct_d().pack(_x))
        _v61 = _v59.obj_arellat
        _x = _v61.data
        buff.write(_get_struct_d().pack(_x))
        _v62 = _v59.obj_class
        _x = _v62.data
        buff.write(_get_struct_i().pack(_x))
        _v63 = _v59.obj_orientationangle
        _x = _v63.data
        buff.write(_get_struct_d().pack(_x))
        _v64 = _v59.obj_length
        _x = _v64.data
        buff.write(_get_struct_d().pack(_x))
        _v65 = _v59.obj_width
        _x = _v65.data
        buff.write(_get_struct_d().pack(_x))
        _v66 = val1.object_quality
        _v67 = _v66.obj_distlong_rms
        _x = _v67.data
        buff.write(_get_struct_d().pack(_x))
        _v68 = _v66.obj_distlat_rms
        _x = _v68.data
        buff.write(_get_struct_d().pack(_x))
        _v69 = _v66.obj_vrellong_rms
        _x = _v69.data
        buff.write(_get_struct_d().pack(_x))
        _v70 = _v66.obj_vrellat_rms
        _x = _v70.data
        buff.write(_get_struct_d().pack(_x))
        _v71 = _v66.obj_arellong_rms
        _x = _v71.data
        buff.write(_get_struct_d().pack(_x))
        _v72 = _v66.obj_arellat_rms
        _x = _v72.data
        buff.write(_get_struct_d().pack(_x))
        _v73 = _v66.obj_orientation_rms
        _x = _v73.data
        buff.write(_get_struct_d().pack(_x))
        _v74 = _v66.obj_probofexist
        _x = _v74.data
        buff.write(_get_struct_d().pack(_x))
        _v75 = _v66.obj_measstate
        _x = _v75.data
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.object_count is None:
        self.object_count = std_msgs.msg.Int32()
      if self.objects is None:
        self.objects = None
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.header.frame_id = str[start:end]
      start = end
      end += 4
      (self.object_count.data,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.objects = []
      for i in range(0, length):
        val1 = radar_conti.msg.Object()
        _v76 = val1.obj_id
        start = end
        end += 4
        (_v76.data,) = _get_struct_i().unpack(str[start:end])
        _v77 = val1.object_general
        _v78 = _v77.obj_distlong
        start = end
        end += 8
        (_v78.data,) = _get_struct_d().unpack(str[start:end])
        _v79 = _v77.obj_distlat
        start = end
        end += 8
        (_v79.data,) = _get_struct_d().unpack(str[start:end])
        _v80 = _v77.obj_vrellong
        start = end
        end += 8
        (_v80.data,) = _get_struct_d().unpack(str[start:end])
        _v81 = _v77.obj_vrellat
        start = end
        end += 8
        (_v81.data,) = _get_struct_d().unpack(str[start:end])
        _v82 = _v77.obj_dynprop
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v82.data = str[start:end].decode('utf-8', 'rosmsg')
        else:
          _v82.data = str[start:end]
        _v83 = _v77.obj_rcs
        start = end
        end += 8
        (_v83.data,) = _get_struct_d().unpack(str[start:end])
        _v84 = val1.object_extended
        _v85 = _v84.obj_arellong
        start = end
        end += 8
        (_v85.data,) = _get_struct_d().unpack(str[start:end])
        _v86 = _v84.obj_arellat
        start = end
        end += 8
        (_v86.data,) = _get_struct_d().unpack(str[start:end])
        _v87 = _v84.obj_class
        start = end
        end += 4
        (_v87.data,) = _get_struct_i().unpack(str[start:end])
        _v88 = _v84.obj_orientationangle
        start = end
        end += 8
        (_v88.data,) = _get_struct_d().unpack(str[start:end])
        _v89 = _v84.obj_length
        start = end
        end += 8
        (_v89.data,) = _get_struct_d().unpack(str[start:end])
        _v90 = _v84.obj_width
        start = end
        end += 8
        (_v90.data,) = _get_struct_d().unpack(str[start:end])
        _v91 = val1.object_quality
        _v92 = _v91.obj_distlong_rms
        start = end
        end += 8
        (_v92.data,) = _get_struct_d().unpack(str[start:end])
        _v93 = _v91.obj_distlat_rms
        start = end
        end += 8
        (_v93.data,) = _get_struct_d().unpack(str[start:end])
        _v94 = _v91.obj_vrellong_rms
        start = end
        end += 8
        (_v94.data,) = _get_struct_d().unpack(str[start:end])
        _v95 = _v91.obj_vrellat_rms
        start = end
        end += 8
        (_v95.data,) = _get_struct_d().unpack(str[start:end])
        _v96 = _v91.obj_arellong_rms
        start = end
        end += 8
        (_v96.data,) = _get_struct_d().unpack(str[start:end])
        _v97 = _v91.obj_arellat_rms
        start = end
        end += 8
        (_v97.data,) = _get_struct_d().unpack(str[start:end])
        _v98 = _v91.obj_orientation_rms
        start = end
        end += 8
        (_v98.data,) = _get_struct_d().unpack(str[start:end])
        _v99 = _v91.obj_probofexist
        start = end
        end += 8
        (_v99.data,) = _get_struct_d().unpack(str[start:end])
        _v100 = _v91.obj_measstate
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v100.data = str[start:end].decode('utf-8', 'rosmsg')
        else:
          _v100.data = str[start:end]
        self.objects.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_d = None
def _get_struct_d():
    global _struct_d
    if _struct_d is None:
        _struct_d = struct.Struct("<d")
    return _struct_d
_struct_i = None
def _get_struct_i():
    global _struct_i
    if _struct_i is None:
        _struct_i = struct.Struct("<i")
    return _struct_i
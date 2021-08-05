# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from radar_conti/Object.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import radar_conti.msg
import std_msgs.msg

class Object(genpy.Message):
  _md5sum = "a7779c5b6537b3dc9690537349901eeb"
  _type = "radar_conti/Object"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """std_msgs/Int32 obj_id
ObjectGeneral object_general
ObjectExtended object_extended
ObjectQuality object_quality
================================================================================
MSG: std_msgs/Int32
int32 data
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
  __slots__ = ['obj_id','object_general','object_extended','object_quality']
  _slot_types = ['std_msgs/Int32','radar_conti/ObjectGeneral','radar_conti/ObjectExtended','radar_conti/ObjectQuality']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       obj_id,object_general,object_extended,object_quality

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Object, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.obj_id is None:
        self.obj_id = std_msgs.msg.Int32()
      if self.object_general is None:
        self.object_general = radar_conti.msg.ObjectGeneral()
      if self.object_extended is None:
        self.object_extended = radar_conti.msg.ObjectExtended()
      if self.object_quality is None:
        self.object_quality = radar_conti.msg.ObjectQuality()
    else:
      self.obj_id = std_msgs.msg.Int32()
      self.object_general = radar_conti.msg.ObjectGeneral()
      self.object_extended = radar_conti.msg.ObjectExtended()
      self.object_quality = radar_conti.msg.ObjectQuality()

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
      buff.write(_get_struct_i4d().pack(_x.obj_id.data, _x.object_general.obj_distlong.data, _x.object_general.obj_distlat.data, _x.object_general.obj_vrellong.data, _x.object_general.obj_vrellat.data))
      _x = self.object_general.obj_dynprop.data
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_3di11d().pack(_x.object_general.obj_rcs.data, _x.object_extended.obj_arellong.data, _x.object_extended.obj_arellat.data, _x.object_extended.obj_class.data, _x.object_extended.obj_orientationangle.data, _x.object_extended.obj_length.data, _x.object_extended.obj_width.data, _x.object_quality.obj_distlong_rms.data, _x.object_quality.obj_distlat_rms.data, _x.object_quality.obj_vrellong_rms.data, _x.object_quality.obj_vrellat_rms.data, _x.object_quality.obj_arellong_rms.data, _x.object_quality.obj_arellat_rms.data, _x.object_quality.obj_orientation_rms.data, _x.object_quality.obj_probofexist.data))
      _x = self.object_quality.obj_measstate.data
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
      if self.obj_id is None:
        self.obj_id = std_msgs.msg.Int32()
      if self.object_general is None:
        self.object_general = radar_conti.msg.ObjectGeneral()
      if self.object_extended is None:
        self.object_extended = radar_conti.msg.ObjectExtended()
      if self.object_quality is None:
        self.object_quality = radar_conti.msg.ObjectQuality()
      end = 0
      _x = self
      start = end
      end += 36
      (_x.obj_id.data, _x.object_general.obj_distlong.data, _x.object_general.obj_distlat.data, _x.object_general.obj_vrellong.data, _x.object_general.obj_vrellat.data,) = _get_struct_i4d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.object_general.obj_dynprop.data = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.object_general.obj_dynprop.data = str[start:end]
      _x = self
      start = end
      end += 116
      (_x.object_general.obj_rcs.data, _x.object_extended.obj_arellong.data, _x.object_extended.obj_arellat.data, _x.object_extended.obj_class.data, _x.object_extended.obj_orientationangle.data, _x.object_extended.obj_length.data, _x.object_extended.obj_width.data, _x.object_quality.obj_distlong_rms.data, _x.object_quality.obj_distlat_rms.data, _x.object_quality.obj_vrellong_rms.data, _x.object_quality.obj_vrellat_rms.data, _x.object_quality.obj_arellong_rms.data, _x.object_quality.obj_arellat_rms.data, _x.object_quality.obj_orientation_rms.data, _x.object_quality.obj_probofexist.data,) = _get_struct_3di11d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.object_quality.obj_measstate.data = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.object_quality.obj_measstate.data = str[start:end]
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
      buff.write(_get_struct_i4d().pack(_x.obj_id.data, _x.object_general.obj_distlong.data, _x.object_general.obj_distlat.data, _x.object_general.obj_vrellong.data, _x.object_general.obj_vrellat.data))
      _x = self.object_general.obj_dynprop.data
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_3di11d().pack(_x.object_general.obj_rcs.data, _x.object_extended.obj_arellong.data, _x.object_extended.obj_arellat.data, _x.object_extended.obj_class.data, _x.object_extended.obj_orientationangle.data, _x.object_extended.obj_length.data, _x.object_extended.obj_width.data, _x.object_quality.obj_distlong_rms.data, _x.object_quality.obj_distlat_rms.data, _x.object_quality.obj_vrellong_rms.data, _x.object_quality.obj_vrellat_rms.data, _x.object_quality.obj_arellong_rms.data, _x.object_quality.obj_arellat_rms.data, _x.object_quality.obj_orientation_rms.data, _x.object_quality.obj_probofexist.data))
      _x = self.object_quality.obj_measstate.data
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
      if self.obj_id is None:
        self.obj_id = std_msgs.msg.Int32()
      if self.object_general is None:
        self.object_general = radar_conti.msg.ObjectGeneral()
      if self.object_extended is None:
        self.object_extended = radar_conti.msg.ObjectExtended()
      if self.object_quality is None:
        self.object_quality = radar_conti.msg.ObjectQuality()
      end = 0
      _x = self
      start = end
      end += 36
      (_x.obj_id.data, _x.object_general.obj_distlong.data, _x.object_general.obj_distlat.data, _x.object_general.obj_vrellong.data, _x.object_general.obj_vrellat.data,) = _get_struct_i4d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.object_general.obj_dynprop.data = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.object_general.obj_dynprop.data = str[start:end]
      _x = self
      start = end
      end += 116
      (_x.object_general.obj_rcs.data, _x.object_extended.obj_arellong.data, _x.object_extended.obj_arellat.data, _x.object_extended.obj_class.data, _x.object_extended.obj_orientationangle.data, _x.object_extended.obj_length.data, _x.object_extended.obj_width.data, _x.object_quality.obj_distlong_rms.data, _x.object_quality.obj_distlat_rms.data, _x.object_quality.obj_vrellong_rms.data, _x.object_quality.obj_vrellat_rms.data, _x.object_quality.obj_arellong_rms.data, _x.object_quality.obj_arellat_rms.data, _x.object_quality.obj_orientation_rms.data, _x.object_quality.obj_probofexist.data,) = _get_struct_3di11d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.object_quality.obj_measstate.data = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.object_quality.obj_measstate.data = str[start:end]
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3di11d = None
def _get_struct_3di11d():
    global _struct_3di11d
    if _struct_3di11d is None:
        _struct_3di11d = struct.Struct("<3di11d")
    return _struct_3di11d
_struct_i4d = None
def _get_struct_i4d():
    global _struct_i4d
    if _struct_i4d is None:
        _struct_i4d = struct.Struct("<i4d")
    return _struct_i4d
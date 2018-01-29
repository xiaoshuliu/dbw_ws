; Auto-generated. Do not edit!


(cl:in-package dbw_demo-msg)


;//! \htmlinclude control.msg.html

(cl:defclass <control> (roslisp-msg-protocol:ros-message)
  ((brake
    :reader brake
    :initarg :brake
    :type cl:float
    :initform 0.0)
   (throttle
    :reader throttle
    :initarg :throttle
    :type cl:float
    :initform 0.0)
   (steering
    :reader steering
    :initarg :steering
    :type cl:float
    :initform 0.0)
   (steering_mult
    :reader steering_mult
    :initarg :steering_mult
    :type cl:boolean
    :initform cl:nil)
   (gear_cmd
    :reader gear_cmd
    :initarg :gear_cmd
    :type cl:fixnum
    :initform 0)
   (turn_signal_cmd
    :reader turn_signal_cmd
    :initarg :turn_signal_cmd
    :type cl:fixnum
    :initform 0))
)

(cl:defclass control (<control>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <control>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'control)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dbw_demo-msg:<control> is deprecated: use dbw_demo-msg:control instead.")))

(cl:ensure-generic-function 'brake-val :lambda-list '(m))
(cl:defmethod brake-val ((m <control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dbw_demo-msg:brake-val is deprecated.  Use dbw_demo-msg:brake instead.")
  (brake m))

(cl:ensure-generic-function 'throttle-val :lambda-list '(m))
(cl:defmethod throttle-val ((m <control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dbw_demo-msg:throttle-val is deprecated.  Use dbw_demo-msg:throttle instead.")
  (throttle m))

(cl:ensure-generic-function 'steering-val :lambda-list '(m))
(cl:defmethod steering-val ((m <control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dbw_demo-msg:steering-val is deprecated.  Use dbw_demo-msg:steering instead.")
  (steering m))

(cl:ensure-generic-function 'steering_mult-val :lambda-list '(m))
(cl:defmethod steering_mult-val ((m <control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dbw_demo-msg:steering_mult-val is deprecated.  Use dbw_demo-msg:steering_mult instead.")
  (steering_mult m))

(cl:ensure-generic-function 'gear_cmd-val :lambda-list '(m))
(cl:defmethod gear_cmd-val ((m <control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dbw_demo-msg:gear_cmd-val is deprecated.  Use dbw_demo-msg:gear_cmd instead.")
  (gear_cmd m))

(cl:ensure-generic-function 'turn_signal_cmd-val :lambda-list '(m))
(cl:defmethod turn_signal_cmd-val ((m <control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dbw_demo-msg:turn_signal_cmd-val is deprecated.  Use dbw_demo-msg:turn_signal_cmd instead.")
  (turn_signal_cmd m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <control>) ostream)
  "Serializes a message object of type '<control>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'brake))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'throttle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'steering))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'steering_mult) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'gear_cmd)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'turn_signal_cmd)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <control>) istream)
  "Deserializes a message object of type '<control>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'brake) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'throttle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'steering) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'steering_mult) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gear_cmd) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'turn_signal_cmd) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<control>)))
  "Returns string type for a message object of type '<control>"
  "dbw_demo/control")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'control)))
  "Returns string type for a message object of type 'control"
  "dbw_demo/control")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<control>)))
  "Returns md5sum for a message object of type '<control>"
  "9198f2552165ab2d06332d076b42111d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'control)))
  "Returns md5sum for a message object of type 'control"
  "9198f2552165ab2d06332d076b42111d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<control>)))
  "Returns full string definition for message of type '<control>"
  (cl:format cl:nil "~%  float32 brake~%  float32 throttle~%  float32 steering~%  bool steering_mult~%  int16 gear_cmd~%  int16 turn_signal_cmd~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'control)))
  "Returns full string definition for message of type 'control"
  (cl:format cl:nil "~%  float32 brake~%  float32 throttle~%  float32 steering~%  bool steering_mult~%  int16 gear_cmd~%  int16 turn_signal_cmd~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <control>))
  (cl:+ 0
     4
     4
     4
     1
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <control>))
  "Converts a ROS message object to a list"
  (cl:list 'control
    (cl:cons ':brake (brake msg))
    (cl:cons ':throttle (throttle msg))
    (cl:cons ':steering (steering msg))
    (cl:cons ':steering_mult (steering_mult msg))
    (cl:cons ':gear_cmd (gear_cmd msg))
    (cl:cons ':turn_signal_cmd (turn_signal_cmd msg))
))

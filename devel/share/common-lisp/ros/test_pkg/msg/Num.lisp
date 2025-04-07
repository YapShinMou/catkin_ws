; Auto-generated. Do not edit!


(cl:in-package test_pkg-msg)


;//! \htmlinclude Num.msg.html

(cl:defclass <Num> (roslisp-msg-protocol:ros-message)
  ((num
    :reader num
    :initarg :num
    :type cl:fixnum
    :initform 0)
   (bigger_num
    :reader bigger_num
    :initarg :bigger_num
    :type cl:fixnum
    :initform 0)
   (NumNumNum
    :reader NumNumNum
    :initarg :NumNumNum
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Num (<Num>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Num>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Num)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test_pkg-msg:<Num> is deprecated: use test_pkg-msg:Num instead.")))

(cl:ensure-generic-function 'num-val :lambda-list '(m))
(cl:defmethod num-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test_pkg-msg:num-val is deprecated.  Use test_pkg-msg:num instead.")
  (num m))

(cl:ensure-generic-function 'bigger_num-val :lambda-list '(m))
(cl:defmethod bigger_num-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test_pkg-msg:bigger_num-val is deprecated.  Use test_pkg-msg:bigger_num instead.")
  (bigger_num m))

(cl:ensure-generic-function 'NumNumNum-val :lambda-list '(m))
(cl:defmethod NumNumNum-val ((m <Num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test_pkg-msg:NumNumNum-val is deprecated.  Use test_pkg-msg:NumNumNum instead.")
  (NumNumNum m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Num>) ostream)
  "Serializes a message object of type '<Num>"
  (cl:let* ((signed (cl:slot-value msg 'num)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'bigger_num)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'NumNumNum)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Num>) istream)
  "Deserializes a message object of type '<Num>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'bigger_num) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'NumNumNum) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Num>)))
  "Returns string type for a message object of type '<Num>"
  "test_pkg/Num")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Num)))
  "Returns string type for a message object of type 'Num"
  "test_pkg/Num")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Num>)))
  "Returns md5sum for a message object of type '<Num>"
  "6984b6b29b1a95096bc45ddb5f33ba67")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Num)))
  "Returns md5sum for a message object of type 'Num"
  "6984b6b29b1a95096bc45ddb5f33ba67")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Num>)))
  "Returns full string definition for message of type '<Num>"
  (cl:format cl:nil "int8 num~%int16 bigger_num~%int8 NumNumNum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Num)))
  "Returns full string definition for message of type 'Num"
  (cl:format cl:nil "int8 num~%int16 bigger_num~%int8 NumNumNum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Num>))
  (cl:+ 0
     1
     2
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Num>))
  "Converts a ROS message object to a list"
  (cl:list 'Num
    (cl:cons ':num (num msg))
    (cl:cons ':bigger_num (bigger_num msg))
    (cl:cons ':NumNumNum (NumNumNum msg))
))

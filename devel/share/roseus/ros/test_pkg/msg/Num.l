;; Auto-generated. Do not edit!


(when (boundp 'test_pkg::Num)
  (if (not (find-package "TEST_PKG"))
    (make-package "TEST_PKG"))
  (shadow 'Num (find-package "TEST_PKG")))
(unless (find-package "TEST_PKG::NUM")
  (make-package "TEST_PKG::NUM"))

(in-package "ROS")
;;//! \htmlinclude Num.msg.html


(defclass test_pkg::Num
  :super ros::object
  :slots (_num _bigger_num _NumNumNum ))

(defmethod test_pkg::Num
  (:init
   (&key
    ((:num __num) 0)
    ((:bigger_num __bigger_num) 0)
    ((:NumNumNum __NumNumNum) 0)
    )
   (send-super :init)
   (setq _num (round __num))
   (setq _bigger_num (round __bigger_num))
   (setq _NumNumNum (round __NumNumNum))
   self)
  (:num
   (&optional __num)
   (if __num (setq _num __num)) _num)
  (:bigger_num
   (&optional __bigger_num)
   (if __bigger_num (setq _bigger_num __bigger_num)) _bigger_num)
  (:NumNumNum
   (&optional __NumNumNum)
   (if __NumNumNum (setq _NumNumNum __NumNumNum)) _NumNumNum)
  (:serialization-length
   ()
   (+
    ;; int8 _num
    1
    ;; int16 _bigger_num
    2
    ;; int8 _NumNumNum
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _num
       (write-byte _num s)
     ;; int16 _bigger_num
       (write-word _bigger_num s)
     ;; int8 _NumNumNum
       (write-byte _NumNumNum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _num
     (setq _num (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _num 127) (setq _num (- _num 256)))
   ;; int16 _bigger_num
     (setq _bigger_num (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int8 _NumNumNum
     (setq _NumNumNum (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _NumNumNum 127) (setq _NumNumNum (- _NumNumNum 256)))
   ;;
   self)
  )

(setf (get test_pkg::Num :md5sum-) "6984b6b29b1a95096bc45ddb5f33ba67")
(setf (get test_pkg::Num :datatype-) "test_pkg/Num")
(setf (get test_pkg::Num :definition-)
      "int8 num
int16 bigger_num
int8 NumNumNum

")



(provide :test_pkg/Num "6984b6b29b1a95096bc45ddb5f33ba67")



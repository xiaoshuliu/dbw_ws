;; Auto-generated. Do not edit!


(when (boundp 'dbw_demo::control)
  (if (not (find-package "DBW_DEMO"))
    (make-package "DBW_DEMO"))
  (shadow 'control (find-package "DBW_DEMO")))
(unless (find-package "DBW_DEMO::CONTROL")
  (make-package "DBW_DEMO::CONTROL"))

(in-package "ROS")
;;//! \htmlinclude control.msg.html


(defclass dbw_demo::control
  :super ros::object
  :slots (_brake _throttle _steering _steering_mult _gear_cmd _turn_signal_cmd ))

(defmethod dbw_demo::control
  (:init
   (&key
    ((:brake __brake) 0.0)
    ((:throttle __throttle) 0.0)
    ((:steering __steering) 0.0)
    ((:steering_mult __steering_mult) nil)
    ((:gear_cmd __gear_cmd) 0)
    ((:turn_signal_cmd __turn_signal_cmd) 0)
    )
   (send-super :init)
   (setq _brake (float __brake))
   (setq _throttle (float __throttle))
   (setq _steering (float __steering))
   (setq _steering_mult __steering_mult)
   (setq _gear_cmd (round __gear_cmd))
   (setq _turn_signal_cmd (round __turn_signal_cmd))
   self)
  (:brake
   (&optional __brake)
   (if __brake (setq _brake __brake)) _brake)
  (:throttle
   (&optional __throttle)
   (if __throttle (setq _throttle __throttle)) _throttle)
  (:steering
   (&optional __steering)
   (if __steering (setq _steering __steering)) _steering)
  (:steering_mult
   (&optional __steering_mult)
   (if __steering_mult (setq _steering_mult __steering_mult)) _steering_mult)
  (:gear_cmd
   (&optional __gear_cmd)
   (if __gear_cmd (setq _gear_cmd __gear_cmd)) _gear_cmd)
  (:turn_signal_cmd
   (&optional __turn_signal_cmd)
   (if __turn_signal_cmd (setq _turn_signal_cmd __turn_signal_cmd)) _turn_signal_cmd)
  (:serialization-length
   ()
   (+
    ;; float32 _brake
    4
    ;; float32 _throttle
    4
    ;; float32 _steering
    4
    ;; bool _steering_mult
    1
    ;; int16 _gear_cmd
    2
    ;; int16 _turn_signal_cmd
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _brake
       (sys::poke _brake (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _throttle
       (sys::poke _throttle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _steering
       (sys::poke _steering (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _steering_mult
       (if _steering_mult (write-byte -1 s) (write-byte 0 s))
     ;; int16 _gear_cmd
       (write-word _gear_cmd s)
     ;; int16 _turn_signal_cmd
       (write-word _turn_signal_cmd s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _brake
     (setq _brake (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _throttle
     (setq _throttle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _steering
     (setq _steering (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _steering_mult
     (setq _steering_mult (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int16 _gear_cmd
     (setq _gear_cmd (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _turn_signal_cmd
     (setq _turn_signal_cmd (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get dbw_demo::control :md5sum-) "9198f2552165ab2d06332d076b42111d")
(setf (get dbw_demo::control :datatype-) "dbw_demo/control")
(setf (get dbw_demo::control :definition-)
      "
  float32 brake
  float32 throttle
  float32 steering
  bool steering_mult
  int16 gear_cmd
  int16 turn_signal_cmd

")



(provide :dbw_demo/control "9198f2552165ab2d06332d076b42111d")



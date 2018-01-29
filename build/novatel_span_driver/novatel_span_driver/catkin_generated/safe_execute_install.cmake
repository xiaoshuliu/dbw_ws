execute_process(COMMAND "/home/liu/dbw_ws/build/novatel_span_driver/novatel_span_driver/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/liu/dbw_ws/build/novatel_span_driver/novatel_span_driver/catkin_generated/python_distutils_install.sh) returned error code ")
endif()

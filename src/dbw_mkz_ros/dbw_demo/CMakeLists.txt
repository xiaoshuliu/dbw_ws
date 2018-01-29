cmake_minimum_required(VERSION 2.8.3)
project(dbw_demo)


find_package(catkin REQUIRED COMPONENTS   
roscpp
  dbw_mkz_msgs
  std_msgs
 message_generation
 )

add_message_files(
  FILES
  control.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)



catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/main_demo.cpp src/Demo.cpp)
add_dependencies(${PROJECT_NAME} dbw_mkz_msgs_gencpp)
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

cmake_minimum_required(VERSION 3.5)
project(my_robot_package)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(robot_publisher src/robot_publisher.cpp)
ament_target_dependencies(robot_publisher rclcpp geometry_msgs)

add_executable(robot_subscriber src/robot_subscriber.cpp)
ament_target_dependencies(robot_subscriber rclcpp geometry_msgs)

install(TARGETS
  robot_publisher
  robot_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
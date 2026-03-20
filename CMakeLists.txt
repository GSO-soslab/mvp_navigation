cmake_minimum_required(VERSION 3.10)
project(mvp_navigation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -fPIC)
endif()

find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(mvp_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

find_package(Eigen3 REQUIRED)

add_definitions(${EIGEN_DEFINITIONS})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/share/cmake/geographiclib/")
find_package(GeographicLib REQUIRED)

set(dependencies
  rclcpp
  std_msgs
  sensor_msgs
  nav_msgs
  mvp_msgs
  tf2_ros
)

include_directories(
  include
  ${EIGEN3_INCLUDE_DIR}
)

set(library_name ${PROJECT_NAME})

#Add library
add_library(${library_name} SHARED 
  src/mvp_navigation_ros_node.cpp
  src/mvp_navigation/mvp_navigation_ros.cpp
)

target_link_libraries( 
  ${library_name}
  ${GeographicLib_LIBRARIES}
)

ament_target_dependencies(
  ${library_name} 
  ${dependencies} 
  )

add_executable(mvp_navigation_ros_node src/mvp_navigation_ros_node.cpp)


target_link_libraries(mvp_navigation_ros_node 
  ${library_name}
  ${GeographicLib_LIBRARIES}
)

ament_target_dependencies(mvp_navigation_ros_node ${dependencies})

install(TARGETS mvp_navigation_ros_node ${library_name}
ARCHIVE DESTINATION lib
LIBRARY DESTINATION lib
RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
DESTINATION include/
)

ament_export_include_directories(include)
ament_export_libraries(${library_name})
ament_export_dependencies(${dependencies})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
cmake_minimum_required(VERSION 3.5)
project(turtle_controller_cpp_py)

# set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/../../env/lib")

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(PythonLibs REQUIRED)


# # Include Cpp "include" directory
# include_directories(include)

# Create Cpp executable
add_executable(draw_circle src/draw_circle.cpp)
ament_target_dependencies(draw_circle rclcpp geometry_msgs)
target_link_libraries(draw_circle ${PYTHON_LIBRARIES})


# Install Cpp executables
install(TARGETS
draw_circle
  DESTINATION lib/${PROJECT_NAME}
)

# # Install Python executables
install(PROGRAMS
    script/draw_square
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
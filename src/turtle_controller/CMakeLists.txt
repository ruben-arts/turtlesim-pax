cmake_minimum_required(VERSION 3.5)
project(turtle_controller)

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
add_executable(draw_square src/draw_square.cpp)
ament_target_dependencies(draw_square rclcpp geometry_msgs)
target_link_libraries(draw_square ${PYTHON_LIBRARIES})


# Install Cpp executables
install(TARGETS
draw_square
  DESTINATION lib/${PROJECT_NAME}
)

# # Install Python executables
install(PROGRAMS
    script/controller.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
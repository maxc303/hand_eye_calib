# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
project (hand_eye_calib)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package (Eigen3 REQUIRED)

add_executable(main src/main.cpp)

target_link_libraries (main Eigen3::Eigen)

find_package(Catch2 REQUIRED)

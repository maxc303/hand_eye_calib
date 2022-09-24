# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
project (axxb_solver)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package (Eigen3 REQUIRED)

add_library(axxb_solver src/solver.cpp src/utils.cpp)
target_include_directories(axxb_solver PUBLIC src)
target_link_libraries(axxb_solver Eigen3::Eigen)

add_executable(main src/main.cpp)

target_link_libraries (main Eigen3::Eigen axxb_solver)


set(BUILD_TESTING ON)
find_package(Catch2)
if (BUILD_TESTING AND Catch2_FOUND)
    find_package(Catch2 REQUIRED)
    add_executable(utils_test src/utils.test.cpp)
    target_link_libraries(utils_test PRIVATE Catch2::Catch2WithMain axxb_solver)
    add_test (NAME utils_test COMMAND utils_test)
endif()

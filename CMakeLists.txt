cmake_minimum_required(VERSION 3.10)
project(CPD_FINAL)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPD_FINAL main.cpp HashMap.cpp)
target_link_libraries(CPD_FINAL tensorflow)
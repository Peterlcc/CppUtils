cmake_minimum_required(VERSION 3.10)

project(CMAKE_TEST)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(cmake_test main.cpp src/person.cpp src/HttpClient.cpp)
target_link_libraries(cmake_test curl)

cmake_minimum_required(VERSION 3.16)
project(untitled)

add_compile_options(-g)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeFiles")
find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDEDIR})

add_executable(untitled main.cpp view.h)

target_link_libraries(untitled ${SFML_LIBRARIES})

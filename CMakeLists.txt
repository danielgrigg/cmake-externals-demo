cmake_minimum_required(VERSION 2.8)
project(exdemo)
include(ExternalProject)

ExternalProject_Add(exru-1.0.0
  GIT_REPOSITORY https://github.com/danielgrigg/exru.git
  GIT_TAG "v1.0.0")

include_directories(${CMAKE_INSTALL_PREFIX}/include)
set(SOURCES)
set(SOURCES ${SOURCES} "src/exdemo.cpp")

link_directories(${CMAKE_INSTALL_PREFIX}/lib)
add_executable(exdemo ${SOURCES})
add_dependencies(exdemo exru-1.0.0)
target_link_libraries(exdemo exru)
install (TARGETS exdemo DESTINATION bin)

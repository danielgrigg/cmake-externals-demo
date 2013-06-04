cmake_minimum_required(VERSION 2.8)
project(exdemo)
include(ExternalProject)

set(EXTERNALS_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/externals")
set(EXTERNALS_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/local")
set(EXTERNALS_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${local_INSTALL_DIR})

set_property(DIRECTORY PROPERTY EP_BASE ${EXTERNALS_PREFIX)
ExternalProject_Add(exru-0.3
  GIT_REPOSITORY https://github.com/danielgrigg/exru.git
  GIT_TAG "v0.3"
  CMAKE_ARGS ${local_CMAKE_ARGS}
  )

include_directories(${EXTERNALS_INSTALL_DIR}/include)
set(SOURCES)
set(SOURCES ${SOURCES} "src/exdemo.cpp")

set(CMAKE_INSTALL_PREFIX ${EXTERNALS_INSTALL_DIR})
link_directories(${CMAKE_INSTALL_PREFIX}/lib)
add_executable(exdemo ${SOURCES})
add_dependencies(exdemo exru-0.3)
target_link_libraries(exdemo exru)
install (TARGETS exdemo DESTINATION bin)


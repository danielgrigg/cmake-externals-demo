cmake_minimum_required(VERSION 2.8)
set(PROJ exdemo)
project($PROJ)
include(ExternalProject)

set(local_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/local")
set(local_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/local")
set(local_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${local_INSTALL_DIR})

ExternalProject_Add(exru-0.3
  PREFIX ${local_PREFIX}
  GIT_REPOSITORY https://github.com/danielgrigg/exru.git
  GIT_TAG "v0.3"
  # Uncomment for a local build
  #  INSTALL_DIR ${local_INSTALL_DIR}
  #  CMAKE_ARGS ${local_CMAKE_ARGS}
  )

set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
include_directories("local/include")
set(SOURCES)
set(SOURCES ${SOURCES} "src/${PROJ}.cpp")

# Uncomment for a local build
#link_directories(${CMAKE_BINARY_DIR}/local/lib)
add_executable(${PROJ} ${SOURCES})
add_dependencies(${PROJ} exru-0.3)
# Note link_directories is apparently deprecated and
# users are encouraged to use target_link_libraries directly.
target_link_libraries(${PROJ} exru)
install (TARGETS ${PROJ} DESTINATION bin)


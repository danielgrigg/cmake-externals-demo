cmake_minimum_required(VERSION 2.8)
project(exdemo)
include(ExternalProject)

set(exdemo_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/local")
set(exdemo_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/local")
set(exdemo_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${exdemo_INSTALL_DIR})

ExternalProject_Add(exru-0.3
  PREFIX ${exdemo_PREFIX}
  GIT_REPOSITORY https://github.com/danielgrigg/exru.git
  INSTALL_DIR ${exdemo_INSTALL_DIR}
  CMAKE_ARGS ${exdemo_CMAKE_ARGS}
  )


cmake_minimum_required(VERSION 2.8)
project(exdemo)
include(ExternalProject)

ExternalProject_Add(
  CMake-2-8-10
  CVS_REPOSITORY :pserver:anonymous:cmake@
  www.cmake.org:/cvsroot/CMake
  CVS_MODULE CMake
  CVS_TAG -r CMake-2-6-4
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:
  PATH=<INSTALL_DIR>
  UPDATE_COMMAND “”
  )

ExternalProject_Add(
  Gtest-1.6.0
  URL http://googletest.googlecode.com/files/gtest-1.6.0.zip
  URL_MD5 4577b49f2973c90bf9ba69aa8166b786
  DOWNLOAD_DIR Downloads
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=bin
  )

set(exdemo_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/exdemo")
set(exdemo_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/exdemo")
set(exdemo_CMAKE_ARGS -CMAKE_INSTALL_PREFIX=${exdemo_INSTALL_DIR})

message("exdemo_PREFIX='${exdemo_PREFIX}'")
message("exdemo_INSTALL_DIR='${exdemo_INSTALL_DIR}'")
message("exdemo_CMAKE_ARGS='${exdemo_CMAKE_ARGS}'")
message("GIT_EXECUTABLE='${GIT_EXECUTABLE}'")

ExternalProject_Add(exru-0.2
  PREFIX ${exdemo_PREFIX}
  GIT_REPOSITORY https://github.com/danielgrigg/exru.git
  INSTALL_DIR ${exdemo_INSTALL_DIR}
  CMAKE_ARGS ${exdemo_CMAKE_ARGS}
  )


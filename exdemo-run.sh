#!/bin/sh

OS=$(uname -s)
if [[ $OS = "Darwin" ]]; then
  DYLD_LIBRARY_PATH=build/local/lib ./build/local/bin/exdemo
else
  LD_LIBRARY_PATH=build/local/lib ./build/local/bin/exdemo
fi

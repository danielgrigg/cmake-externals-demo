# cmake-externals-demo

Demo of using the CMake ExternalProject\_Add module.

# Installing & Running

Ensure openexr and cmake are installed:

+ Ubuntu 

  sudo apt-get install cmake openexr

+ Mac OS X

  Install (homebrew)[http://mxcl.github.io/homebrew/]
  brew install cmake openexr

+ Windows

  Err..pull request?


./install.sh

# Running 

./exdemo-run.sh

The exdemo-run.sh script ensures libexru is correctly loaded and should
work on most unixes.

The test file is written to /tmp/externals.exr. On Mac OS X:

open /tmp/externals.exr


Copyright &copy; 2013 Daniel C Grigg

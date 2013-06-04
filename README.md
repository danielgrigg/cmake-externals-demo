# cmake-externals-demo

Demo of using the CMake ExternalProject\_Add module.

# Installing & Running

Ensure openexr and cmake are installed:

+ Ubuntu 

  sudo apt-get install cmake libopenexr-dev

+ Mac OS X

  Install (homebrew)[http://mxcl.github.io/homebrew/]
  brew install cmake openexr

+ Windows

  Err..pull request?


  ./install.sh

  Note that the install process without changing permissions on /usr/local (unix),
  requires elevation of make.  See install.sh for details. The alternative,
  local external-installs, can be seen in the *relocatable* branch.

# Running 

+ Mac OS X

  exdemo && open /tmp/externals.exr


Copyright &copy; 2013 Daniel C Grigg

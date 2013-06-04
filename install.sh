#!/bin/bash

# Yes this ugly, but also the type of problem you run into
# when relying on externals installing to system dirs like /usr/local.
# The dilemma is that externals are configured, built and installed
# as part of the 'make' step. If extra permissions are required
# for the install-prefix, you either need to 
# a) change the permissions of the prefix, ie, /usr/local.  Homebrew does this.
# b) raise make's priveleges, ie, sudo make
# c) toss the idea of installing to a system dir
# Option A. is good if you have that control, since you'll never 
# run into this problem again.  B, used here, is quite ugly, since running make
# as root means you'll need to be root again to remove the externals!
# Option C. also works - see the relocatable branch.
sudo rm -rf build
mkdir build
cd build
cmake .. && sudo make install

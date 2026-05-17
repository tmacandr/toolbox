#!/bin/bash
#=============================================================================
# FILE: create_virt_env.sh
#
# DESCRIPTION:
#=============================================================================

OK=`command -v python3`

if test -z "$OK"; then
   echo "***> ERROR - python3 not found"
   exit 1
fi

OK=`command -v pip3`

if test -z "$OK"; then
   echo "***> ERROR - Python 'pip3' tool not found"
   exit 2
fi

mkdir py_virt_dir

cd py_virt_dir

python3 -m venv ./

source ./bin/activate

#
#  ‘wheel’ package of python binaries (and source?) that implements
# some sort of service, processing mechanism.
#
# It’s similar to a .zip and/or .tar and/or .so and/or .a package, but specific
# to the Python environment.
#
# A ‘wheel’ package could be installed into the ‘base’ Python installation,
# but on a shared system, one would need ‘root’ privilege to do so.  This
# is the crux of a ‘virtual environment’.  It allows the user to create a
# Python build, run-time environment that it tailored for a specific
# product … and then passes ‘up’ to the base (root) installation … without
# touching (i.e. corrupting the root installation).
#
# I think the term “wheel” is a sardonic term from the ‘original’ Python
# community for ‘reinventing the wheel’ in terms of how to install support
# packages to a system.  Instead of following the .zip and/or .tar mechanics,
# they decided to ‘do it themselves’.
#
# Again, a ‘wheel’ package can go into a base Python installation, but one
# needs ‘root’ privilege to do so.
#

#
# For example, to install the Python serial port interface ‘wheel’:
#
# pip3 install –trusted-host jupiter2.planets.local --index-url $REPO pyserial


REPO=https://www.pythonWheels.org

HOST_NAME=jupiter2.planets.local

WHEEL_PKG=pyserial

pip3 install –trusted-host $HOST_NAME --index-url $REPO $WHEEL_PKG

echo “done”

#!/bin/sh
# * *************************************************************************
# * FILE: test.sh
# *
# * DESCRIPTION:
# *    UNIX script to run the "enigma" Tcl scripts.
# *
# *    Expect 'tclsh' shell to be in user's $PATH.  Nominally located in
# *                   /usr/bin/tclsh
# * *************************************************************************

HERE=`pwd`

KEY1=3
KEY2=9
KEY3=32

SEED=321

tclsh make_wheels.tcl wheels.txt  $SEED

tclsh encrypt_doc.tcl plain.txt cipher.txt wheels.txt $KEY1 $KEY2 $KEY3 

tclsh decrypt_doc.tcl cipher.txt result.txt wheels.txt $KEY1 $KEY2 $KEY3

echo "---> Done"

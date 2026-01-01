#!/bin/sh
# * *************************************************************************
# * FILE: test.sh
# *
# * DESCRIPTION:
# *    UNIX script to run the 'encrypt_doc.tcl' and then the 'decrypt_doc.tcl'
# *    tools.
# *
# *    Expect 'tclsh' shell to be in user's $PATH.  Nominally located in
# *                   /usr/bin/tclsh
# * *************************************************************************

HERE=`pwd`

TCLSH=/usr/bin/tclsh

tclsh encrypt.tcl plain.txt cipher.txt 3

tclsh decrypt_doc.tcl cipher.txt result.txt 3

echo "---> Done"

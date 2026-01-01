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

KEY=3

tclsh encrypt_doc.tcl plain.txt cipher.txt $KEY

tclsh decrypt_doc.tcl cipher.txt result.txt $KEY

echo "---> Done"

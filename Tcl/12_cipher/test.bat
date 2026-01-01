@echo off
rem * *************************************************************************
rem * FILE: run_decrypt.bat
rem *
rem * DESCRIPTION:
rem *    DOS batch program to run the "decrypt_doc" Tcl script
rem *
rem *    Tcl shell is installed in:
rem *
rem *        C:\Tcl\bin
rem * *************************************************************************

set HERE=%cd%

tclsh85 encrypt_doc.tcl plain.txt cipher.txt 4

tclsh85 decrypt_doc.tcl cipher.txt result.txt 4

echo Done

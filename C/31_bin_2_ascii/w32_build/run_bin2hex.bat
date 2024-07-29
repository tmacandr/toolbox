@echo off

set HERE=%cd%

cd ..

set ROOT=%cd%

set FILE=%ROOT%\test.bin

cd %HERE%

cd Debug

bin_2_ascii.exe %FILE%

cd %HERE%

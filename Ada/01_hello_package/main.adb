--**************************************************************
-- FILE: main.adb
--
-- DESCRIPTION:
--    Main routine to call functions of a "demo" package.
--**************************************************************


with Text_Io;
with hello_package;


--*************************************
-- PROCEDURE: main
--
-- DESCRIPTION:
--    Main entry point of Ada program.
--*************************************
procedure main is

   answer : Integer;

begin

   Text_Io.Put_Line("---> Begin - hello package");

   hello_package.do_something (5);

   answer := hello_package.calculate_something (10);

   Text_Io.Put_Line("---> The answer is " & Integer'image(answer) );

   Text_Io.Put_Line("---> End - hello package");

end main;


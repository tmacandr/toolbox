--**************************************************************
-- FILE: main.adb
--
-- DESCRIPTION:
--    Main routine to call functions of a "demo" package.
--**************************************************************


with Text_Io;
with hello_task_pkg;


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

   hello_task_pkg.start_task;

   Text_Io.Put_Line("---> Get values ...");

   for I in 1 .. 10 loop

      Delay (1.0);

      answer := hello_task_pkg.get_value;

      Text_Io.Put_Line("---> The answer is " & Integer'image(answer) );

   end loop;

   hello_task_pkg.end_task;

   Text_Io.Put_Line("---> End - hello package");

end main;


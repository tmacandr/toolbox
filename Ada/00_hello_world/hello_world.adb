--**************************************************************
-- FILE: hello_world.ada
--
-- DESCRIPTION:
--    Hello world in Ada.  The "gcc" compiler notes say it
--    can handle Ada ... is that true?
--
--    Worked ... use these commands to compile, bind, and
--    link:
--
--       cc  -c hello_world.adb
--       gnatbind -x hello_world.ali
--       gnatlink hello_world.ali -L/lib/w32api
--
--    Not sure what the 'gnatbind' is for ... never seen
--    that before.
--
--    Looks like the Linux community got together with the
--    GNAT folks ... interesting.
--**************************************************************


with Text_Io;


--*************************************
-- PROCEDURE: hello_world
--
-- DESCRIPTION:
--    Main entry point of Ada program.
--*************************************
procedure hello_world is

begin

   Text_Io.Put_Line("Hello world");

end hello_world;


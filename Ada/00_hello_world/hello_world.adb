--**************************************************************
-- FILE: hello_world.ada
--
-- DESCRIPTION:
--    Hello world in Ada.
--
--    Used the GNU "gnat" toolset for Ada compiler and
--    linker.
--
--    For Ubuntu:
--
--       sudo apt install gnat
--
--    Tried the 'gcc' compiler that says it has an Ada option,
--    but that didn't work.  Go with "gnat".
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


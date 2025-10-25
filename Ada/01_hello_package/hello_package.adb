--**************************************************************
-- FILE: hello_pacakge.adb
--
-- DESCRIPTION:
--    Implements the pacakge "hello_package"
--**************************************************************
with Text_Io;

package body hello_package is

   package Int_IO is new Text_Io.Integer_Io (Integer);

   --*************************************
   -- PROCEDURE: do_something
   --
   -- DESCRIPTION:
   --    An example procedure.
   --*************************************
   procedure do_something (some_var : in Integer) is

      temp_var : Integer := 0;

   begin

      Text_Io.Put_Line("---> do_something - begin");

      Int_IO.Put (some_var);
      Text_Io.New_Line;

      temp_var := some_var + 1;

      Int_IO.Put (temp_var);
      Text_Io.New_Line;

      Text_Io.Put_Line("---> do_something - end");

   end do_something;


   --*************************************
   -- FUNCTION: calculate_something
   --
   -- DESCRIPTION:
   --    An example function.
   --*************************************
   function calculate_something (some_var : in Integer)
      return Integer is

      temp_var : Integer := 0;

   begin

      Text_Io.Put_Line("---> do_something - begin");

      temp_var := some_var + 15;

      Text_Io.Put_Line("---> do_something - end");

      return temp_var;

   end calculate_something;

end hello_package;

--**************************************************************
-- FILE: hello_package.ads
--
-- DESCRIPTION:
--    Specification of the pacakge "hello_package"
--**************************************************************
package hello_package is

   --*************************************
   -- PROCEDURE: do_something
   --
   -- DESCRIPTION:
   --    An example procedure.
   --*************************************
   procedure do_something (some_var : in Integer);


   --*************************************
   -- FUNCTION: calculate_something
   --
   -- DESCRIPTION:
   --    An example function.
   --*************************************
   function calculate_something (some_var : in Integer)
      return Integer;


end hello_package;

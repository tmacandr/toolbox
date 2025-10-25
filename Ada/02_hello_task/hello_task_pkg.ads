--**************************************************************
-- FILE: hello_task_pkg.ads
--
-- DESCRIPTION:
--    Specification of the pacakge "hello_task_pkg"
--**************************************************************
package hello_task_pkg is

   --*************************************
   -- PROCEDURE: start_task
   --
   -- DESCRIPTION:
   --    Procedure starts the task
   --*************************************
   procedure start_task;


   --*************************************
   -- PROCEDURE: end_task
   --
   -- DESCRIPTION:
   --    Procedure ends the task
   --*************************************
   procedure end_task;


   --*************************************
   -- FUNCTION: get_value
   --
   -- DESCRIPTION:
   --    Gets a value from the task.
   --*************************************
   function get_value return Integer;

end hello_task_pkg;

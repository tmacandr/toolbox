--**************************************************************
-- FILE: hello_pacakge.adb
--
-- DESCRIPTION:
--    Implements the pacakge "hello_task_pkg"
--**************************************************************
with Text_Io;

package body hello_task_pkg is

   --*************************************
   -- Task: Some_Task
   --
   -- DESCRIPTION:
   --    Declare the interface of the task.
   --*************************************
   task Some_Task is

      entry begin_task;

      entry get_num (val : in out Integer);

      entry end_task;

   end Some_Task;


   --*************************************
   -- PROCEDURE: start_task
   --
   -- DESCRIPTION:
   --    Rendezvous to start the task
   --*************************************
   procedure start_task is

   begin

      Text_Io.Put_Line("---> start_task - begin");

      Some_Task.begin_task;

      Text_Io.Put_Line("---> start_task - end");

   end start_task;


   --*************************************
   -- PROCEDURE: end_task
   --
   -- DESCRIPTION:
   --    Rendezvous to end the task
   --*************************************
   procedure end_task is

   begin

      Text_Io.Put_Line("---> end_task - begin");

      Some_Task.end_task;

      Text_Io.Put_Line("---> end_task - end");

   end end_task;

   --*************************************
   -- FUNCTION: get_value
   --
   -- DESCRIPTION:
   --    An example function.
   --*************************************
   function get_value return Integer is

      temp_var : Integer := 0;

   begin

      Text_Io.Put_Line("---> get_value - begin");

      Some_Task.get_num (temp_var);

      Text_Io.Put_Line("---> get_value - end");

      return temp_var;

   end get_value;


   --*************************************
   -- PROCEDURE: Some_Task
   --
   -- DESCRIPTION:
   --    The body of the task.
   --*************************************
   task body Some_Task is

      the_num    : Integer := 0;

      is_stopped : boolean := false;

   begin

      accept begin_task do

         Text_Io.Put_Line ("   ---> task is now started");

      end begin_task;

      loop -- forever

         select

            accept get_num (val : in out Integer) do

               val := the_num;

            end get_num;

         or

            accept end_task do

               is_stopped := true;

            end end_task;

         else

            Delay 1.0;

         end select;

         the_num := the_num + 1;

         if (is_stopped) then
            exit; -- out of loop
         end if;

      end loop;

      Text_Io.Put_Line ("   ---> task is now stopped");

   end Some_Task;

end hello_task_pkg;

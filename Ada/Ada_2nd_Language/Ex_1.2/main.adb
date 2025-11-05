--**************************************************************
-- FILE: exercise_1_2.ada
--
-- DESCRIPTION:
--    Exercise 1.2 from "Ada as a Second Language", by
--    N. Cohen.
--**************************************************************

with Text_IO;
with Problems;

--*************************************
-- PROCEDURE: main
--
-- DESCRIPTION:
--    Main entry point of Ada program.
--*************************************
procedure main is

begin

   Text_IO.Put_Line("Begin - Exercise 1.2");

   Problems.Sum_3_Inputs;

   Problems.Compute_Difference_Of_Products;

   Problems.Echo;

end main;


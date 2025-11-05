--**************************************************************
-- FILE: exercise_1_2.ada
--
-- DESCRIPTION:
--    Exercise 1.2 from "Ada as a Second Language", by
--    N. Cohen.
--**************************************************************


with Text_IO;


--*************************************
-- PACKAGE: Problems
--
-- DESCRIPTION:
--    Implements Exercise 1.2 (a) and (b)
--    and (c).
--*************************************
package body Problems is

   package Int_IO is new Text_IO.Integer_IO(Integer);

   --*************************************
   -- PROCEDURE: Sum_3_Inputs 
   --
   -- DESCRIPTION:
   --    Implements Exercise 1.2 (a)
   --
   --    This program reads in three numbers
   --    and prints out their sums.     <-- This was the bug, invalid comment
   --*************************************
   procedure Sum_3_Inputs is

      A, B, C: Integer;

      Sum : Integer;

   begin

      Text_IO.Put_Line("Enter 3 integers consectutively:");
      Int_IO.Get(A);
      Int_IO.Get(B);
      Int_IO.Get(C);

      Sum := A + B + C;

      Text_IO.Put("Sum is: ");
      Int_IO.Put(Sum);
      Text_IO.New_Line;

   end Sum_3_Inputs;


   --*************************************
   -- PROCEDURE: Compute_Difference_Of_Products
   --
   -- DESCRIPTION:
   --    Exercise 1.2(b).  Find where the comment form
   --    disrupts the statement.
   --*************************************
   procedure Compute_Difference_Of_Products is

      A, B, C, D : Integer;

   begin

      Text_Io.Put_Line("Enter 4 integers consecutively");
      Int_IO.Get(A);
      Int_IO.Get(B);
      Int_IO.Get(C);
      Int_IO.Get(D);-----------------------------------------------
      Int_IO.Put(A *-- Multiply first number                     --
                 B - --by second number and subtract             --
                 C *-- product of third number and               --
                 D  -- fourth number.                            --
                );
      Text_IO.New_Line;

   end Compute_Difference_Of_Products;


   --*************************************
   -- PROCEDURE: Echo
   --
   -- DESCRIPTION:
   --    Exercise 1.2 (c).
   --*************************************
   procedure Echo is

      X : Integer;

   begin
      Text_IO.Put_Line("---> Enter integer:");
      Int_IO.Get(X);
      Text_IO.Put_Line("---> You entered: ");
      Int_IO.Put(X);
      Text_IO.New_Line;
   end Echo;

end Problems;


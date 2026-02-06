/*----------------------------------------------------------------------------
 * MODULE NAME: class_demo.java
 *
 * PURPOSE:
 *    Implements the "hello world" program in Java
 *
 *    Notes:
 *       1) The 'main()' function is inside a class
 *       2) The name of the class must match the name
 *          of the file ... case sensitive.
 *****************************************************************************/
import java.io.*;

public class class_demo 
{
   /*---------------------------------------------
    * METHOD: say_hello
    *
    * DESCRIPTION:
    *    Just a simple function that writes
    *    message to console.  Invoked from the
    *    'main' method
    *---------------------------------------------*/
   static void say_hello ()

   {
       System.out.println("---> Hello class demo");
   }


   /*---------------------------------------------
    * METHOD: main
    *
    * DESCRIPTION:
    *    Corresponds to the main entry point of
    *    the program.
    *---------------------------------------------*/
   public static void main(String[] args)

   {
       System.out.println("_______Begin - class demo__________");

       say_hello ();

       System.out.println("_______End - class demo ____________");
   }
}


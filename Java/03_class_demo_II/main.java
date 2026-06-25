/*----------------------------------------------------------------------------
 * FILE: main.java
 *
 * DESCRIPTION:
 *    Exercise the 'something' object.
 *--------------------------------------------------------------------------*/
package src;

import src.something;

class main
{
    public static void main(String []args)
    {
        System.out.println("---> Begin - something demo");

        something thing = new something(5);

        thing.do_something();

        System.out.println("---> End - something demo");
    }
};


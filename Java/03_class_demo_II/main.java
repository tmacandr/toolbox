/*----------------------------------------------------------------------------
 * FILE: main.java
 *
 * DESCRIPTION:
 *    Exercise the 'something' object.
 *
 *    The 'something' class is in the sub-directory 'src'.  Therefore the
 *    'package' is called 'src' and the syntax to access it is:
 *
 *            import <dir>.<class-name>;
 *
 *    which is:
 *
 *            import src.something;
 *--------------------------------------------------------------------------*/
import src.something;

class main
{
    public static void main(String []args)
    {
        System.out.println("---> Begin - something demo");

        int start_value = 5;

        something thing = new something(start_value);

        thing.do_something();

        int num = thing.do_another_thing(10);

        System.out.println("---> num: " + num);

        num = thing.get_value();

        System.out.println("---> Value: " + num);

        if (num != start_value)
        {
            System.out.println("***> ERROR - values don't match\n" +
                               "***>    start val: " + start_value + "\n" +
                               "***>    ret val..: " + num);

            System.exit(99);
        }
 
        System.out.println("---> End - something demo");
    }
};

/* EOF */


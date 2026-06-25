/*----------------------------------------------------------------------------
 * FILE: something.java
 *
 * DESCRIPTION:
 *    Defines an class for an object "something" ... for demo purpose
 *    only.
 *
 *    This file is in a sub-directory "src", so the 'package' name is
 *    'src'.
 *--------------------------------------------------------------------------*/
package src;

class something 
{
    /* private parameter */
    private int some_value = 0;

    /*-------------------------------------------
     * METHOD: something
     *
     * DESCRIPTION:
     *    Class constructor.  Destructors aren't
     *    needed in Java.
     *-------------------------------------------*/
    public something(int val)
    {
        System.out.println("---> something - constructor");

        some_value = val;
    }


    /*-------------------------------------------
     * METHOD: do_one_thing
     *
     * DESCRIPTION:
     *    A class 'private' function.
     *-------------------------------------------*/
    private void do_one_thing()
    {
        System.out.println("---> something - do_one_thing");
    }


    /*-------------------------------------------
     * METHOD: do_add
     *
     * DESCRIPTION:
     *    Another class 'private' function.
     *-------------------------------------------*/
    private int do_add(int num)
    {
        System.out.println("---> something - do_add");

        int result = num + 5;

        return result;
    }


    /*-------------------------------------------
     * METHOD: do_one_thing
     *
     * DESCRIPTION:
     *    A class 'public' function.
     *-------------------------------------------*/
    public void do_something()
    {
        System.out.println("---> something - do_something");

        do_one_thing(); 
    }


    /*-------------------------------------------
     * METHOD: do_another_thing
     *
     * DESCRIPTION:
     *    Another class 'public' function.
     *-------------------------------------------*/
    public int do_another_thing(int num)
    {
        System.out.println("---> something - do_something");

        int answer;

        answer = do_add(num);

        return answer;
    }


    /*-------------------------------------------
     * METHOD: get_value
     *
     * DESCRIPTION:
     *    Public method to return private
     *    'some_value'.
     *-------------------------------------------*/
    public int get_value()
    {
        System.out.println("---> something - get_value");

        return some_value;
    }

};

/* EOF */


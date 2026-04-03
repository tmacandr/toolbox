//============================================================================
// FILE: count_down.cpp
//
// DESCRIPTION:
//    Simple count down clock starting from user input.
//
//    The C++ mechanics for 'sleep' seem clunky.  Need <thread> and <chrono>.
//============================================================================

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "***> ERROR - invalid arg\n";
        std::cout << "***> USAGE:\n";
        std::cout << "***>    count_down <sec>\n";
        std::cout << "***> EXAMPLE:\n";
        std::cout << "***>    count_down 25\n";

        return -1;
    }

    std::cout << "Count down from: " << argv[1] << "\n";

    unsigned int count = (unsigned int) std::stoul(argv[1]);
 
    for (unsigned int i = count; i > 0; i--)
    {
        std::cout << "   " << i << "\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}

// EOF


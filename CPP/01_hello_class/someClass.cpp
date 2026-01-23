//******************************************************
// File : someClass.cpp
//
// Description:
//    Simple class demo
//******************************************************
#include <iostream>
#include "someClass.h"

someClass::someClass
             (int   someInt,
              float someFloat)
{
   attribute_1 = someInt;
   attribute_2 = someFloat;
}

someClass::~someClass()
{
    std::cout << "---> Destructor" << std::endl;
}


void someClass::setAttribute_1 (int someInt)
{
    attribute_1 = someInt;
}

void someClass::setAttribute_2 (float someFloat)
{
    attribute_2 = someFloat;
}

int someClass::getAttribute_1 (void)
{
    return attribute_1;
}

float someClass::getAttribute_2 (void)
{
    return attribute_2;
}

void someClass::print(void)
{
   std::cout << "Attribute 1...: " << attribute_1 << std::endl;
   std::cout << "Attribute 2...: " << attribute_2 << std::endl;
}

/* EOF */


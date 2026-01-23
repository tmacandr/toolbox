//----------------------------------------------------------------------------
// File : list_test.cpp
// Date : 30-May-00 : initial defintion
//
// Description:
//    This is a console application that uses the "list" class from the
//    C++ Library.
//
//----------------------------------------------------------------------------

#include <stdio.h>

#include <list>


typedef std::list<int,
                  std::allocator<int> > integerListType;


//-----------------------------------------------
// main
//
// Description:
//    main function.
//-----------------------------------------------
int main
       (int  argc,
        char **argv)

{
         integerListType           theIntList;
         integerListType::iterator theIterator;

   theIntList.insert (theIntList.begin (), 1);
   theIntList.insert (theIntList.end(), 2);
   theIntList.insert (theIntList.begin (), 3);
   theIntList.insert (theIntList.end(), 4);

   theIterator = theIntList.begin ();

   while (theIterator != theIntList.end () )
      {
       printf("Item : %d\n", *theIterator);

       theIterator++;
      }

   //
   // Using a pointer to a 'list' object
   //
         integerListType  *ptrToIntList; 

   ptrToIntList = new integerListType();

   ptrToIntList->push_front(1);
   ptrToIntList->push_front(2);
   ptrToIntList->push_front(3);
   ptrToIntList->push_front(4);

   theIterator = ptrToIntList->begin ();

   while (theIterator != ptrToIntList->end () )
      {
       printf("Item : %d\n", *theIterator);

       theIterator++;
      }

   delete ptrToIntList;

   return 0;
}

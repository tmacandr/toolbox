//----------------------------------------------------------------------------
// File : map_test.cpp
// Date : 31-May-00 : initial defintion
//
// Description:
//    This is a console application that uses the "map" class from the
//    "C++ Standard Template Library (STL)".
//
//    The methods defined for the "map" template are:
//
//          allocator_type
//          begin
//          clear
//          const_iterator
//          const_reference
//          const_reverse_iterator
//          count
//          difference_type
//          empty
//          end
//          equal_range
//          erase
//          find
//          get_allocator
//          insert
//          iterator
//          key_comp
//          key_compare
//          key_type
//          lower_bound
//          map
//          max_size
//          operator[]
//          rbegin
//          reference
//          referent_type
//          rend
//          reverse_iterator
//          size
//          size_type
//          swap
//          upper_bound
//          value_comp
//          value_compare
//          value_type 
//
//----------------------------------------------------------------------------

#ifdef WIN32
   #pragma warning(disable:4786)
#endif

#include <stdio.h>
#include <map>


typedef struct
   {
    int   degrees;
    int   minutes;
    float seconds;
   } myRecType;


typedef std::map<int,
                 myRecType,
                 std::less<int>,
                 std::allocator<myRecType> > myMapType;


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
            myMapType              theMap;
            myRecType              tempRecord;
            unsigned int           i;
            myMapType::value_type  *pairPtr;

   //
   // one way to insert items into the map
   //
   for (i = 0; i < 5; i++)
     {
      tempRecord.degrees = 2 * i;
      tempRecord.minutes = 3 * i;
      tempRecord.seconds = 3.0f * i;

      pairPtr = new myMapType::value_type(i, tempRecord);

      theMap.insert ( *pairPtr );

      delete pairPtr;
     }

   printf("Size of queue = %lu\n", theMap.size() );

   for (i = 0; i < theMap.size(); i++)
   {
       tempRecord = theMap[i];

       printf("%d) dd:mm:ss.ss = %2d : %2d : %f\n",
              i,
              tempRecord.degrees,
              tempRecord.minutes,
              tempRecord.seconds);
   }

   theMap.clear();

   //
   // ... another way to insert items into the map
   //
   for (i = 0; i < 5; i++)
   {
      tempRecord.degrees = 2 * i;
      tempRecord.minutes = 3 * i;
      tempRecord.seconds = 3.0f * i;

      theMap[i] = tempRecord;
   }

   printf("Size of queue = %lu\n", theMap.size() );

   return 0;
}

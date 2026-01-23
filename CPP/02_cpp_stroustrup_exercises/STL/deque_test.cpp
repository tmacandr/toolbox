//----------------------------------------------------------------------------
// File : deque_test.cpp
// Date : 06-Apr-00 : initial defintion
//
// Description:
//    This is a console application that uses the "deque" class from the
//    "C++ Standard Template Library (STL)".
//
//    The "deque" item is a C++ template that can be instantiated to be
//    a dynamic queue.  All the typical operations you would expect to find
//    on a queue are available ... plus some others.  As mentioned, a "deque"
//    object is a "dynamic" queue.  This means that a client can add and remove
//    items from the queue, from any position in the queue, without having to
//    perform memory allocation, nor memory deallocation, nor re-order operations
//    on the queue.  All of that is hidden from the client and implemented by
//    the internals of the "deque" template.
//    
//    The methods on a "deque" object are:
//           allocator_type : 
//           assign         : 
//           at             :
//           back
//           begin
//           clear
//           const_iterator
//           const_reference
//           const_reverse_iterator
//           deque
//           difference_type
//           empty
//           end
//           erase
//           front
//           get_allocator
//           insert
//           iterator
//           max_size
//           operator[]
//           pop_back
//           pop_front
//           push_back
//           push_front
//           rbegin
//           reference
//           rend
//           resize
//           reverse_iterator
//           size
//           size_type
//           swap
//           value_type 
//
//----------------------------------------------------------------------------

#include <stdio.h>
#include <deque>


typedef struct
   {
    int   degrees;
    int   minutes;
    float seconds;
   } myRecType;


typedef std::deque<myRecType, std::allocator<myRecType> > myQueueType;


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
            myQueueType theQueue;
            myRecType   tempRecord;
            int         i;

   //
   // Demonstrate a FIFO queue
   //
   for (i = 0; i < 5; i++)
     {
      tempRecord.degrees = 2 * i;
      tempRecord.minutes = 3 * i;
      tempRecord.seconds = 3.0f * i;

      theQueue.push_back(tempRecord);
     }

   printf("Size of queue = %d\n", theQueue.size() );

   for (i = 0; i < theQueue.size(); i++)
      {
       tempRecord = theQueue[i];

       printf("%d) dd:mm:ss.ss = %2d : %2d : %f\n",
              i,
              tempRecord.degrees,
              tempRecord.minutes,
              tempRecord.seconds);
      }

   theQueue.clear();

   //
   // Demonstrate a FILO queue
   //
   for (i = 0; i < 5; i++)
     {
      tempRecord.degrees = 2 * i;
      tempRecord.minutes = 3 * i;
      tempRecord.seconds = 3.0f * i;

      theQueue.push_front(tempRecord);
     }

   printf("Size of queue = %d\n", theQueue.size() );

   for (i = 0; i < theQueue.size(); i++)
      {
       tempRecord = theQueue[i];

       printf("%d) dd:mm:ss.ss = %2d : %2d : %f\n",
              i,
              tempRecord.degrees,
              tempRecord.minutes,
              tempRecord.seconds);
      }

   return 0;
}

//******************************************************
// File : someClass.h
//
// Description:
//    Simple class demo
//******************************************************
#ifndef SOME_CLASS

   #define SOME_ClASS

   class someClass
   {
     public:
        // Constructor //
        someClass
             (int   someInt,
              float someFloat);

        // Destructor
        ~someClass();

        // Some 'methods' //
        void setAttribute_1 (int someInt);

        void setAttribute_2 (float someFloat);

        int getAttribute_1 (void);

        float getAttribute_2 (void);

        void print(void);

     private:
        int   attribute_1 = 0;
        float attribute_2 = 0;
    };

#endif

/* EOF */

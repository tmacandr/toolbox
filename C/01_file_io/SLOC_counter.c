/*-------------------------------------------------------------------
 * File: SLOC_counter.c
 * Date: 11-Jun-04
 *
 * Description:
 *    Counts semi-colons in a file of source code ... typically C.
 *-------------------------------------------------------------------*/

#include <stdio.h>



/*------------------------------
 * main
 *
 * Description:
 *    Main function.
 *------------------------------*/
int main (int argc, char **argv)

{
         FILE         *fd;
         unsigned int slocs = 0;
         char         item;

   if (argc != 2)
   {
       printf("\n\nUsage\n");
       printf("    SLOC_counter <full-path-to-file>\n\n");

       return 0;
   }

   printf("________________\n");

   printf("File Name...: %s\n", argv[1]);

   fd = fopen (argv[1], "r");

   if (fd == NULL)
   {
       printf("***> File '%s' not found\n", argv[1]);

       goto DONE;
   }

   for (;;)
   {
       if (feof(fd)) break;
       
       item = (char) fgetc (fd);

       if (item == ';') slocs++;
   }

   fclose (fd);

   printf("SLOCs.......: %u\n", slocs);

DONE:

   printf("________________\n");

   return 0;
}

/*******************************************************************************
* FILE: hello_thread.c
*
* DESCRIPTION:
*    Hello world that demonstrates assigning a process (heavy-weight thread)
*    to a particular CPU.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef __USE_GNU
   /*
    * This is annoying ... it's done
    * to get access to the 'affinity'
    * macros in "sched.h"
    */
   #define __USE_GNU
#endif

#include <sched.h>


static void show_CPU_affinity (const unsigned int Num_CPUs);

static void set_CPU_affinity (const unsigned int which_CPU);

static void do_some_work (const unsigned int which_CPU);


/************************************************
* FUNCTION: main
*
* DESCRIPTION:
*    Main entry point of program.
*************************************************/
int main (int argc, char **argv)

{
         pid_t        process_ID;
         unsigned int assigned_CPU = 0;
         unsigned int Num_CPUs     = 0;

   printf("______________________\n");
   printf("Begin - hello threads\n");

   if (argc != 3)
   {
       printf("***> Invalid arguments\n"
              "***> Usage:\n"
              "        hello_threads.exe <assigned-cpu> <max-num-CPUs>\n"
              "***> Example:\n"
              "        hello_threads.exe 2 4\n");

       return 0;
   }

   sscanf (argv[1], "%u", &assigned_CPU);
   sscanf (argv[2], "%u", &Num_CPUs);

   printf("---> assigned CPU..: %u (of %u CPUs)\n",
          assigned_CPU,
          Num_CPUs);

   process_ID = getpid ();

   printf("---> process ID....: %u\n", (unsigned int) process_ID);

   show_CPU_affinity (Num_CPUs);

   set_CPU_affinity (assigned_CPU);

   show_CPU_affinity (Num_CPUs);

   do_some_work (assigned_CPU);

   printf("______________________\n");

   return 0;
}



/***********************************************
* FUNCTION: show_CPU_affinity
*
* DESCRIPTION:
*    Uses the system function 'sched_getaffinity'
*    to show what CPUs this program is runnin on.
************************************************/
static void show_CPU_affinity (const unsigned int Num_CPUs)

{
         pid_t        process_ID;
         cpu_set_t    cpu_affinity_mask;
         int          status;
         unsigned int i;
         int          is_set;

   CPU_ZERO(&cpu_affinity_mask);

   process_ID = getpid();

   status = sched_getaffinity
               (process_ID,
                sizeof(cpu_set_t),
                &cpu_affinity_mask);

   if (status == -1)
   {
       printf("***> ERROR - sched_getaffinity failed\n");

       return;
   }

   for (i = 0; i < Num_CPUs; i++)
   {
       is_set = CPU_ISSET (i, &cpu_affinity_mask);

       printf("CPU %u set....: %s\n",
              i,
              is_set ? "Yes" : "No");
   }
}


/***********************************************
* FUNCTION: set_CPU_affinity
*
* DESCRIPTION:
*    Uses the system function 'sched_setaffinity'
*    to assign the calling thread to the specified
*    CPU.  The calling thread will then execute
*    only on the specified CPU.
************************************************/
static void set_CPU_affinity (const unsigned int which_CPU)

{
         pid_t     process_ID;
         cpu_set_t cpu_affinity_mask;
         int       status;

   process_ID = getpid ();

   printf("---> assigning process %u to CPU %u\n",
          (unsigned int) process_ID,
          which_CPU);

   CPU_ZERO(&cpu_affinity_mask);

   CPU_SET(which_CPU, &cpu_affinity_mask);

   status = sched_setaffinity
               (process_ID,
                sizeof(cpu_set_t),
                &cpu_affinity_mask);

   if (status == -1)
   {
       printf("***> ERROR - sched_setaffinity failed\n");
   }
}


/***********************************************
* FUNCTION: do_some_work 
*
* DESCRIPTION:
*    This function does busy work ... just to
*    make it look good.
************************************************/
static void do_some_work (const unsigned int which_CPU)

{
        pid_t        proc_ID;
        unsigned int i;

   proc_ID = getpid();

   for (i = 0; i < 4; i++)
   {
       printf("---> I'm process %u on CPU %u\n",
              proc_ID,
              which_CPU);

       sleep (1.0);
   }
}

/* EOF */


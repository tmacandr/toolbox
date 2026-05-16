#=============================================================================
# FILE: hello_world.py
#
# DESCRIPTION:
#    Python hello world demo
#=============================================================================

"""
   To run: python3 hello_world.py
"""

import os
import sys
import time

def main():
   """
   METHOD: main

   DESCRIPTION:
      Sort of 'main' entry point called by 'python3' runtime system per
      commands at the bottom.

      Note - there's some sort of 'committee' out there that defines
             a style guide.  They have some 'gravitas' because the
             original author of Python (who has since quit) and other
             significant contributors have defined this so-called
             'style guied'.  It's out there on the Web.

             And I hate it.  Function (or rather 'method') prologs
             are 'under' the method declaration ... and comment blocks
             begin with double quotes (").
   """
   print("---> hello python world")

   some_number = input("---> Enter a number: ")

   print("---> You entered: " + some_number)

   #
   # Convert 'string' to 'int'
   #
   num_as_int = int(some_number)

   if num_as_int > 10:
      print("===> The number " + some_number + " is greater than 10")

   for i in range(0, num_as_int, 1):
      print("---> Count up: " + str(i))
      time.sleep(1)
      print("---------")

   print("---> End hello world")

#
# This is how the Python run-time system (shell) will invoke this program. 
# 
if __name__ == "__main__":
   main()

# EOF


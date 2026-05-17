#=============================================================================
# FILE: class_demo.py
#
# DESCRIPTION:
#    Demo of Python 'object oriented' mechanics.
#
#    NOTE - even though the name of the 'class' is the same as the file
#           Python does not require that ... i.e. they can be different.
#=============================================================================

import os
import sys
import time

class class_demo():
   """
   class : class_demo 

   DESCRIPTION:
      Demonstrate class syntax in Python.
   """

   def __init__(self):
      print("---> Demo Class constructor")

   def __del__(self):
      print("---> Demo Class destructor");

   def do_something(self):
      some_number = input("---> Enter a number: ")

      print("---> You entered: " + some_number)
      print("---> End do_something")

# EOF


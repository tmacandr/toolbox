#=============================================================================
# FILE: demo_main.py
#
# DESCRIPTION:
#    Demo of how to instantiate and use an object from a Python 'class'.
#
# Run:
#    python3 demo_main.py 
#=============================================================================

import class_demo as class_demo

#
# Instantiate and use
# 
if __name__ == "__main__":

   print("---> Begin 'main'");

   CD = class_demo.class_demo()

   CD.do_something()

   print("---> End 'main'");

# EOF


#=============================================================================
# FILE: json_reader.py
#
# DESCRIPTION:
#    Python demo on how to parse a JSON file.
#
#    JSON := JavaScript Object Notation
#
# Run:
#    python3 json_reader.py <json-file>
#=============================================================================

import os
import sys
import time
import json

def main():
   """
   METHOD: main

   DESCRIPTION:
      Opens specified JSON file and parses the contents.
   """
   print("---> Begin - JSON reader: " + sys.argv[0])

   argc = len(sys.argv)

   if argc != 2:
      print("***> ERROR - invalid arg")
      print("***> USAGE:")
      print("***>    python3 json_reader.py <json-file>")
      print("***> EXAMPLE:")
      print("***>    python3 json_reader.py data.json")
      sys.exit(99)

   try: 
      fd = open(sys.argv[1], 'r')
 
      contents = json.load(fd)

      fd.close()

      data = contents["DATA"]

      name = data["Name"]

      print("---> Name: " + name);

   except json.JSONDecodeError as e:
      print("Exception: ", e)

   print("---> End - JSON reader")

#
# Invoke 'main()'
# 
if __name__ == "__main__":
   main()

# EOF


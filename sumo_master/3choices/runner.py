"""
@file   runner.py
@author Quentin Goss
@date   6/26/18
"""
#from __future__ import absolute_import
#from __future__ import print_function

#import os
import sys
#import optparse
#import subprocess
#import random

# Constants
SUMO_TOOLS_DIR = "/home/veins/src/sumo-0.30.0/tools"

# we need to import python modules from the $SUMO_HOME/tools directory
try:
  sys.path.append(SUMO_TOOLS_DIR) # Path to SUMO python modules
  from sumolib import checkBinary  
except:  
  sys.exit("Could not locate sumolib in " + SUMO_TOOLS_DIR + ".")

import traci

import imp
import os
import sys
from ctypes import *
terminal_size = os.get_terminal_size()
#print(terminal_size.columns)
columns = c_int(terminal_size.columns)
rows = c_int(terminal_size.lines)
file = open("terminalDimensions","wb")
if(not(file.closed)):
	file.write(columns)
	file.write(rows);
	file.close()
else:
	print("Error")


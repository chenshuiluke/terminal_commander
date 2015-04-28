terminal_commander: src/main.c src/getTerminalDimensions.py src/terminal_info.c include/terminal_info.h
	 gcc  src/main.c src/terminal_info.c -g -o bin/terminal_commander -Iinclude 
	 echo "Compiled C Source " 
	 cxfreeze src/getTerminalDimensions.py --target-name=getTerminalDimensions --target-dir=bin 
	 cp src/getTerminalDimensions.py bin
	 echo "'Compiled' Python Executable"

windows: src/main.c src/getTerminalDimensions.py src/terminal_info.c include/terminal_info.h
	 gcc  src/main.c src/terminal_info.c -g -o bin/terminal_commander.exe -Iinclude 
	 echo "Compiled C Source " 
	 C:\Python34\python.exe C:\Python34\Scripts\cxfreeze src/getTerminalDimensions.py --target-name=getTerminalDimensions.exe --target-dir=bin 
	 echo "'Compiled' Python Executable"
	 -robocopy  src/ bin/ getTerminalDimensions.py 

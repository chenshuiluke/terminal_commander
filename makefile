terminal_commander: src/main.c src/getTerminalDimensions.py src/terminal_info.c src/interface.c include/terminal_info.h include/interface.h
	reset
	git submodule init
	git submodule update	
	gcc  src/main.c src/terminal_info.c src/interface.c xml.c/src/xml.c -g -o bin/terminal_commander -Iinclude -Ixml.c/src/
	echo "Compiled C Source " 
	cxfreeze src/getTerminalDimensions.py --target-name=getTerminalDimensions --target-dir=bin 
	cp src/getTerminalDimensions.py bin
	echo "'Compiled' Python Executable"

windows: src/main.c src/getTerminalDimensions.py src/terminal_info.c src/interface.c include/terminal_info.h
	cls
	git submodule init
	git submodule update	
	gcc  src/main.c src/terminal_info.c xml.c/src/xml.c -g -o bin/terminal_commander.exe -Iinclude -Ixml.c/src/
	echo "Compiled C Source " 
	C:\Python34\python.exe C:\Python34\Scripts\cxfreeze src/getTerminalDimensions.py --target-name=getTerminalDimensions.exe --target-dir=bin 
	echo "'Compiled' Python Executable"
	-robocopy  src/ bin/ getTerminalDimensions.py 

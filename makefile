terminal_commander: src/main.c src/terminal_info.c src/interface.c include/terminal_info.h include/interface.h
	reset
	gcc  src/main.c src/terminal_info.c src/interface.c xml.c/src/xml.c -g -o bin/terminal_commander -lncurses -lSDL -Iinclude -Ixml.c/src/ 
	echo "Compiled C Source " 
#	cxfreeze src/getTerminalDimensions.py --target-name=getTerminalDimensions --target-dir=bin 
#	cp src/getTerminalDimensions.py bin
#	echo "'Compiled' Python Executable"

windows: src/main.c src/terminal_info.c src/interface.c include/terminal_info.h
	cls
	gcc  src/main.c src/terminal_info.c src/interface.c xml.c/src/xml.c -g -o bin/terminal_commander.exe -lpdcurses -Iinclude -Ixml.c/src/ 
	echo "Compiled C Source " 
	echo "'Compiled' Python Executable"

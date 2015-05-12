terminal_commander: src/main.c src/terminal_info.c src/interface.c   include/terminal_info.h include/interface.h include/utilities.h
	reset
	git submodule init
	git submodule update	
	gcc  src/main.c src/terminal_info.c src/interface.c  xml.c/src/xml.c -g -o bin/terminal_commander -lncurses -lSDL -Iinclude -Ixml.c/src/ 
	echo "Compiled C Source " 

windows: src/main.c src/terminal_info.c src/interface.c  include/terminal_info.h include/utilities.h
	cls
	git submodule init
	git submodule update	
	gcc  src/main.c src/terminal_info.c src/interface.c  xml.c/src/xml.c -g -o bin/terminal_commander.exe -lpdcurses -Iinclude -Ixml.c/src/ 
	echo "Compiled C Source " 

linux_lib: src/main.c src/terminal_info.c src/interface.c include/terminal_info.h include/interface.h
	reset
	gcc -c -fPIC src/terminal_info.c src/interface.c xml.c/src/xml.c -g -lncurses -lSDL -Iinclude -Ixml.c/src/ 
	gcc -shared terminal_info.o interface.o xml.o -o libterminal_commander.so
	rm *.o
	mv *.so bin/linux
	cp bin/ui.xml bin/linux/ui.xml
	echo "Compiled C Source " 
	
linux_test: src/main.c src/terminal_info.c src/interface.c include/terminal_info.h include/interface.h
	reset
	gcc src/main.c -Lbin/linux -lterminal_commander -Iinclude -Ixml.c/src/ -lncurses -lSDL -o bin/linux/test
	reset
	echo "Compiled C Source " 
install: bin/linux/libterminal_commander.so
	sudo cp bin/linux/libterminal_commander.so /usr/lib
windows_lib: src/main.c src/terminal_info.c src/interface.c include/terminal_info.h include/interface.h
	cls
	gcc -c -fPIC src/terminal_info.c src/interface.c xml.c/src/xml.c -g -Iinclude -Ixml.c/src/
	gcc -shared terminal_info.o interface.o xml.o -o bin/win/libterminal_commander.dll -lpdcurses
	del *.o
	copy "bin//ui.xml" ui.xml
	echo "Compiled C Source " 

windows: src/main.c src/terminal_info.c src/interface.c include/terminal_info.h
	cls
	gcc  src/main.c src/terminal_info.c src/interface.c xml.c/src/xml.c -g -o bin/terminal_commander.exe -lpdcurses -Iinclude -Ixml.c/src/ 
	echo "Compiled C Source " 

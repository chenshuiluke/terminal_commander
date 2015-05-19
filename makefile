linux_lib: src/main.c src/terminal_info.c src/interface.c src/draw.c include/terminal_info.h include/interface.h include/terminal_commander.h include/draw.h
	
	gcc -Wall -c -fPIC src/terminal_info.c src/interface.c src/draw.c -g -lncurses -lSDL -Iinclude -I/src/ `xml2-config --cflags`
	gcc -Wall -shared terminal_info.o draw.o interface.o  -o libterminal_commander.so `xml2-config --cflags --libs`
	rm *.o
	mv *.so bin/linux
	cp bin/ui.xml bin/linux/ui.xml
	echo "Compiled C Source " 
	
linux_test: src/main.c src/terminal_info.c src/interface.c src/draw.c include/terminal_info.h include/interface.h include/terminal_commander.h include/draw.h
	
	gcc -Wall src/main.c -Lbin/linux -lterminal_commander -Iinclude -I/src/ -g -lncurses -lSDL -o bin/linux/test `xml2-config --cflags --libs`
	
	echo "Compiled C Source " 

install: bin/linux/libterminal_commander.so
	sudo cp bin/linux/libterminal_commander.so /usr/lib
win_lib: src/main.c src/terminal_info.c src/interface.c src/draw.c include/terminal_info.h include/interface.h include/terminal_commander.h include/draw.h
	
	gcc -Wall -c -fPIC src/terminal_info.c src/interface.c src/draw.c /src/ -g -Iinclude -I/src/
	gcc -Wall -shared terminal_info.o interface.o  draw.o -o bin/win/libterminal_commander.dll -lpdcurses
	del *.o
	-robocopy "bin/" "bin/win/" "ui.xml"
	
	echo "Compiled C Source " 

win_test: src/main.c src/terminal_info.c src/interface.c src/draw.c include/terminal_info.h include/interface.h include/terminal_commander.h include/draw.h
	
	gcc -Wall src/main.c -Lbin/win -lterminal_commander -Iinclude -I/src/ -g -lpdcurses -o bin/win/test.exe
	
	echo "Compiled C Source " 

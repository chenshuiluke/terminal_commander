linux_lib: src/main.c src/terminal_info.c src/interface.c src/draw.c include/terminal_info.h include/interface.h include/terminal_commander.h include/draw.h
	
	gcc -w -c -fPIC src/terminal_info.c src/interface.c src/draw.c -g -lncurses -lSDL -Iinclude -I/src/ `xml2-config --cflags`
	gcc -w -shared terminal_info.o draw.o interface.o -g -o libterminal_commander.so `xml2-config --cflags --libs`
	rm *.o
	mv *.so bin/linux
	cp bin/ui.xml bin/linux/ui.xml
	echo "Compiled C Source " 
	
linux_test: src/main.c src/terminal_info.c src/interface.c src/draw.c include/terminal_info.h include/interface.h include/terminal_commander.h include/draw.h
	
	gcc -w -Wl,-rpath=. src/main.c -Lbin/linux -lterminal_commander -Iinclude -I/src/ -g -lncurses -lSDL -o bin/linux/test `xml2-config --cflags --libs`
	
	echo "Compiled C Source " 

install: bin/linux/libterminal_commander.so
	sudo cp bin/linux/libterminal_commander.so /usr/lib
win_lib: src/main.c src/terminal_info.c src/interface.c src/draw.c include/terminal_info.h include/interface.h include/terminal_commander.h include/draw.h
	
	gcc -w -c -fPIC src/terminal_info.c src/interface.c src/draw.c -g -Iinclude -I/src/ -Iother
	gcc -w -shared terminal_info.o interface.o  draw.o -g -o bin/win/libterminal_commander.dll -lpdcurses -lxml2 -Lother -Iother -Iother/
	del *.o
	-robocopy "bin/" "bin/win/" "ui.xml"
	-robocopy "other" "bin/win/"
	
	echo "Compiled C Source " 

win_test: src/main.c src/terminal_info.c src/interface.c src/draw.c include/terminal_info.h include/interface.h include/terminal_commander.h include/draw.h
	
	gcc -w -Wl,-rpath=. src/main.c -Lbin/win -lterminal_commander -Iinclude -I/src/ -g -lpdcurses -o bin/win/test.exe -Iother -lxml2 -Lother
	
	echo "Compiled C Source " 

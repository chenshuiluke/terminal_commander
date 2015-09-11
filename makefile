unit_test: unit_test.c src/*.c include/*.h
	gcc unit_test.c src/terminal_commander.c src/terminal_info.c -o unit_test -g -Iinclude -Lsrc -lncurses -pthread `xml2-config --cflags --libs`
win_unit_test: unit_test.c src/*.c include/*.h
	gcc unit_test.c src/terminal_commander.c src/terminal_info.c -o unit_test.exe -Iinclude -Lsrc -lpdcurses -pthread

unit_test: unit_test.c src/*.c include/*.h
	gcc unit_test.c src/terminal_commander.c src/terminal_info.c -o unit_test -Iinclude -Lsrc -lncurses -pthread

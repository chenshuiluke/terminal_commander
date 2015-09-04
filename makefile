unit_test: unit_test.c src/terminal_commander.c
	gcc unit_test.c src/terminal_commander.c -o unit_test -Iinclude -Lsrc -lncurses

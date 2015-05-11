#include <stdio.h>
#include <stdlib.h>
#ifdef __gnu_linux__
	#include <ncurses.h>
#endif
#ifdef _WIN32
	#include <curses.h>
#endif
#include "terminal_info.h"
#include "interface.h"
int main()
{
	initscr();
	testForUI();
	readUIFile();
	continuouslyUpdateInfo();
	refresh();
	printDocument();
	while(1)
	getch();
	endwin();
	return 0;
}

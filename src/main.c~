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
	setvbuf(stdout, NULL, _IONBF, 0);
 	scrollok(stdscr, TRUE);
	if(setUIFile("ui.xml"))
	{
		printw("Specified UI file doesn't exist: %s!\n", attemptedFile);
		refresh();
		abort();
	}
	readUIFile();
	continuouslyUpdateInfo();
	refresh();
	printDocument();
	getch();
	endwin();
	clearAll();
	return 0;
}

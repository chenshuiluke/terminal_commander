#include <stdio.h>
#include <stdlib.h>
#include "terminal_commander.h"
int main()
{
	initscr();
	start_color();
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
//	printDocument();
	square(8,8,5,7,COLOR_WHITE,COLOR_RED);
	getch();
	endwin();
//	clearAll();
	return 0;
}

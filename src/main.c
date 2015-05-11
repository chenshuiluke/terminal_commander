#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
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

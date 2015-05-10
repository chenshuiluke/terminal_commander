#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "terminal_info.h"
#include "interface.h"
int main()
{
	initscr();
	testForUI();
	continuouslyUpdateInfo();
	refresh();
	getch();
	endwin();
	return 0;
}

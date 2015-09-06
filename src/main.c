#include <stdio.h>
#include <stdlib.h>
#include "terminal_commander.h"
int main()
{
    /*Initialize ncurses
     *starts colour support
     *disable line buffering
     *allow scrolling when the cursor reaches the bottom
     */
		 /*
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

	readUIFile(); //Sets the root node of the xml document
	continuouslyUpdateInfo();
	refresh();
	scanUIFile();
    printUI(UI, 1);
//	printDocument();
	//rectangle(8,8,5,7,COLOR_WHITE,COLOR_RED);
	getch();
	endwin();
	clearAll();
	return 0;
	*/
}

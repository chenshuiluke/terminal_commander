#include "terminal_info.h"

void getTerminalDimensions()
{
	terminalRows = getmaxx(stdscr);
	terminalColumns = getmaxy(stdscr);
}
void continuouslyUpdateInfo()
{
	int counter = 0;
	for(counter = 0; counter < 10; counter++)
	{
		#ifdef _WIN32
			memset(terminalDimensionsExecutable,'\0',50);
			strcpy(terminalDimensionsExecutable,"getTerminalDimensions.exe");
		#else
		#ifdef __gnu_linux__
			memset(terminalDimensionsExecutable,'\0',50);
			strcpy(terminalDimensionsExecutable,"./getTerminalDimensions");	
		#endif
		#endif
		getTerminalDimensions();
		printw("Rows: %d Columns: %d\n", terminalRows, terminalColumns);
	}
	refresh();
}

#include "terminal_info.h"
#include "miscellaneous.h"
int terminalColumns = 0;
int terminalRows = 0;
void continuouslyUpdateTerminalInfo()
{
	FILE * terminalInfoWriter = NULL;
	terminalInfoWriter = fopen("terminal_info.log", "w");
	int counter = 0;
	while(1)
	{
		mySleep(1);
		terminalRows = getmaxy(stdscr);
		terminalColumns = getmaxx(stdscr);
		fprintf(terminalInfoWriter, "Rows: %d\tColumns%d\n", terminalRows, terminalColumns);
	}
	fclose(terminalInfoWriter);
}

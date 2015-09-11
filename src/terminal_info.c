#include "terminal_info.h"
#include "miscellaneous.h"
int terminalColumns = 0;
int terminalRows = 0;
int terminateUpdateThread = 0;
void * continuouslyUpdateTerminalInfo()
{
	//http://stackoverflow.com/questions/7961029/how-can-i-kill-a-pthread-that-is-in-an-infinite-loop-from-outside-that-loop
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
	FILE * terminalInfoWriter = NULL;
	terminalInfoWriter = fopen("terminal_info.log", "w");
	int counter = 0;
	while(1 && !terminateUpdateThread)
	{
		mySleep(1);
		terminalRows = getmaxy(stdscr);
		terminalColumns = getmaxx(stdscr);
		fprintf(terminalInfoWriter, "Rows: %d\tColumns%d\n", terminalRows, terminalColumns);
	}
	fclose(terminalInfoWriter);
}

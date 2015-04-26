#include "terminal_info.h"

void getTerminalDimensions()
{
	if(system("python/dist/getTerminalDimensions") == -1)
	{
		puts("Error getting terminal dimensions!");
	}
	else
	{
		FILE * reader;
		if(reader = fopen("terminalDimensions","rb"))
		{
			fread(&terminalColumns,sizeof(int),1,reader);	
			fread(&terminalRows,sizeof(int),1,reader);	
		}
		else
		{
			perror("Error opening : terminalDimensions :");
		}
	}
}
void continuouslyUpdateInfo()
{
	getTerminalDimensions();
	printf("Rows: %d Columns: %d\n", terminalRows, terminalColumns);
}

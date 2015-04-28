#include "terminal_info.h"

void getTerminalDimensions()
{
	
	if(system(terminalDimensionsExecutable) == -1)
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
	#ifdef _WIN32
		memset(terminalDimensionsExecutable,'\0',50);
		strcpy(terminalDimensionsExecutable,"python/dist/getTerminalDimensions.exe");
	#else
	#ifdef __gnu_linux__
		memset(terminalDimensionsExecutable,'\0',50);
		strcpy(terminalDimensionsExecutable,"python/dist/getTerminalDimensions");	
	#endif
	#endif
	getTerminalDimensions();
	printf("Rows: %d Columns: %d\n", terminalRows, terminalColumns);
}

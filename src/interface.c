#include "interface.h"
uint8_t * document = NULL;
int documentSize = 0;
int setUIFile(char file[])
{
	strcpy(attemptedFile,file);
	if(!testUIFile(file))
	{
		strcpy(uiFile,attemptedFile);
		return 0;
	}
	else
	{
		return 1;
	}
}
int getFileSize(char file[])
{
	FILE * reader;
	char temp;
	unsigned int numRead =0;
	if(!(reader = fopen(file,"rb")))
	{
		printw("Error opening file to get its size\n");
		perror("");
		return 0;
	}
	else
	{
		while(!feof(reader))
		{
			fread(&temp,sizeof(unsigned char),1,reader);
			numRead++;
		}
	}
	return numRead;
}
int testUIFile()
{
	FILE * tester = NULL;
	if((tester = fopen(uiFile,"r")) == NULL)
	{
		return 0;
	}
	else 
	{
		fclose(tester);
		return 1;
	}
}
void readUIFile()
{
	document = NULL;
	documentSize = 0;
	FILE * reader = NULL;
	uint8_t * tempPtr = NULL;
	int counter = 0;
	int uiFileSize = 0;
	if((reader = fopen(uiFile,"rb")) == NULL)
	{
		printw("Error opening %s!\n", uiFile);	
		refresh();
	}
	uiFileSize = getFileSize(uiFile);
	if(uiFileSize > 0)
		uiFileSize--;
	printw("%d\n",uiFileSize);
	document = malloc(sizeof(uint8_t)*uiFileSize);
	if(!fread(document,sizeof(uint8_t),uiFileSize,reader))
	{
		printw("Error occurred reading ui.xml\n");
	}
	else
	{
		documentSize=uiFileSize;
		for(counter = 0; counter < documentSize; counter++)
		{
			if(document[counter] == '\r')
			{
				memcpy(document+counter-1,document+counter+1,(documentSize-1-counter) * sizeof(uint8_t));
				documentSize--;
				counter--;
			}
		}
	}
	fclose(reader);
}
void printDocument()
{
	int counter = 0;
	printw("Document Size: %d\n", documentSize);
	for(counter = 0; counter < documentSize; counter++)
	{
		printw("%c",(char)document[counter]);
		fflush(stdout);
	}
	refresh();

}
void clearAll()
{
	free(document);
}

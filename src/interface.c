#include "interface.h"
uint8_t * document = NULL;
int documentSize = 0;
int getFileSize(char file[])
{
	FILE * reader;
	char temp;
	unsigned int numRead =0;
	if(!(reader = fopen(file,"rb")))
	{
		printw("Error opening file to get its size\n");
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
void testForUI()
{
	FILE * tester = NULL;
	if((tester = fopen(UI_FILE,"r")) == NULL)
	{
		printw("Unrecoverable error occurred when trying to read UI file 'ui.xml'\n");
		refresh();
		abort();
	}
}
void readUIFile()
{
	document = NULL;
	documentSize = 0;
	FILE * reader = NULL;
	uint8_t * tempPtr = NULL;
	int uiFileSize = 0;
	if((reader = fopen("ui.xml","rb")) == NULL)
	{
		printw("Error opening ui.xml!\n");	
	}
	uiFileSize = getFileSize(UI_FILE);
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
	}
}
void printDocument()
{
	int counter = 0;
	printw("Document Size: %d\n", documentSize);
	for(counter = 0; counter < documentSize; counter++)
	{
		printw("%c - %d\n",(char)document[counter], document[counter]);
	}
	refresh();

}
void clearAll()
{
	free(document);
}

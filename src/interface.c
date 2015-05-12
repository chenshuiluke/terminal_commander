#include "interface.h"
uint8_t * document = NULL;
int documentSize = 0;
void testForUI()
{
	FILE * tester = NULL;
	if((tester = fopen(UI_FILE,"r")) == NULL)
	{
		perror("Unrecoverable error occurred when trying to read UI file 'ui.xml': ");
		abort();
	}
}
void readUIFile()
{
	document = NULL;
	documentSize = 0;
	FILE * reader = NULL;
	uint8_t * tempPtr = NULL;
	if((reader = fopen("ui.xml","rb")) == NULL)
	{
		perror("Error opening ui.xml! ");	
	}
	document = malloc(sizeof(uint8_t));
	while((fread(&document[documentSize],sizeof(uint8_t),1,reader)) == sizeof(uint8_t))
	{
		tempPtr = realloc(document,sizeof(uint8_t)*(documentSize+1));
		if(!tempPtr)
		{
			perror("Error allocating memory while reading document!");	
		}
		else
		{
			document = tempPtr;
			tempPtr = NULL;
			documentSize++;
		}
	}
	if(ferror(reader))
	{
		perror("Error occurred reading ui.xml: ");
	}
}
void printDocument()
{
	int counter = 0;
	for(counter = 0; counter < documentSize; counter++)
	{
		printw("%c",document[counter]);
	}
	refresh();

}
void clearAll()
{
	free(document);
}

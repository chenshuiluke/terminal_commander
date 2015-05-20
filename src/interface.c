#include "interface.h"
xmlDocPtr document = NULL;
xmlNodePtr current = NULL;

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
	document = xmlParseFile(uiFile);
	if (document == NULL ) 
	{
		fprintf(stderr,"Document not parsed successfully. \n");
		return;
	}
	current = xmlDocGetRootElement(document);
	if(current == NULL)
	{
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(document);
		return;
	}
	/*
	if (xmlStrcmp(current->name, (const xmlChar *) "ui"))
	{
		fprintf(stderr,"document of the wrong type, root node != ui");
		xmlFreeDoc(document);
		return;
	}
	*/
}

void printDocument()
{
	/*
	int counter = 0;
	for(counter = 0; counter < documentSize; counter++)
	{
		printw("%c",(char)document[counter]);
		fflush(stdout);
	}
	refresh();
		
	*/

}

void clearAll()
{
	free(document);
}
void scanUIFile()
{
	current = xmlFirstElementChild(current);
	if(!current)
	{
		printw("Error processing file!");
		refresh();
		return;
	}
	
	xmlNodePtr top = current;	
	while(current)
	{
		if(!xmlStrcmp(current->name,(const xmlChar *) "rectangle"))		
		{
			//http://xmlsoft.org/tutorial/ar01s08.html
			xmlChar * height, * width, * x, * y, * foreground, * background, * character;
			height = NULL; width = NULL; x = NULL; y = NULL; foreground = NULL; background = NULL;
			character = NULL;

			height = xmlGetProp(current,"height");	
			width = xmlGetProp(current,"width");
			x = xmlGetProp(current,"x");
			y = xmlGetProp(current,"y");
			foreground = xmlGetProp(current, "foreground");
			background = xmlGetProp(current, "background");
			character = xmlGetProp(current,"character");
			if(height && width && x && y && foreground && background && character)
			{
				rectangle(atoi((char *)height),  atoi((char *)width),  atoi((char *)x),  atoi((char *)y),  atoi((char *)foreground),  atoi((char *)background), ((char *)character)[0]);	
			}
			else
			{
				printw("The rectangle doesn't have enough attributes");
				refresh();
			}
		}
		current = current -> next;
	}
}

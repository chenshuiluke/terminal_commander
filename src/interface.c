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
void getChildren(element * node,const xmlNodePtr current)
{
	int count = 0;
	xmlNodePtr temp = NULL;
	xmlNodePtr tempCpy = NULL;
	(*node).numChildren = xmlChildElementCount(current);
	if((*node).numChildren == 0)
	{
		return;
	}
	else
	{
		temp = xmlFirstElementChild(current);
		(*node).children = calloc((*node).numChildren, sizeof(element));
		(*node).children[0].parent = node;
//		getChildren(&((*node).children[0]), temp);
		while(temp)
		{
			if(!xmlStrcmp(temp->name,"rectangle"))
			{
				(*node).children[count].parent = node;
				(*node).children[count].height = atoi((char *) xmlGetProp(temp, "height"));		
				(*node).children[count].width = atoi((char *) xmlGetProp(temp, "width"));		
				(*node).children[count].x = atoi((char *) xmlGetProp(temp, "x"));		
				(*node).children[count].y = atoi((char *) xmlGetProp(temp, "y"));		
				(*node).children[count].foreground = atoi((char *) xmlGetProp(temp, "foreground"));		
				(*node).children[count].background = atoi((char *) xmlGetProp(temp, "background"));		
				(*node).children[count].character = ((char *) xmlGetProp(temp, "character"))[0];		
				strcpy((*node).children[count].type,temp->name);		
				tempCpy = temp;
				getChildren(&((*node).children[count]), temp);
				count++;
			}
			temp = temp->next;
		}
	}
}
void printUI(element node)
{
	int count = 0;
	if(node.numChildren == 0)
	{
		return;
	}
	for(count = 0; count < node.numChildren; count++)
	{
		if(!(xmlStrcmp(node.children[count].type,(const xmlChar *) "rectangle")))	
		{
			mySleep(1000);
			rectangle(node.children[count].height,	
			node.children[count].width,	
			node.children[count].x,	
			node.children[count].y,	
			node.children[count].foreground,	
			node.children[count].background,	
			node.children[count].character);
			refresh();
			printUI(node.children[count]);
		}
	}
}
void scanUIFile()
{
//	current = xmlFirstElementChild(current);
	if(!current)
	{
		printw("Error processing file!");
		refresh();
		return;
	}
	getChildren(&UI, current);	
	printUI(UI);
	int y;
	/*
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
	*/
}

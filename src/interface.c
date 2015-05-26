#include "interface.h"
xmlDocPtr document = NULL;
xmlNodePtr current = NULL;
void * cleaner = NULL;

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
	if(document)
		xmlFreeDoc(document);
	clearElements(UI);
	
}
void clearElements(element node)
{
	int count = 0;
	if(node.numChildren == 0)
	{
		return;
	}
	for(count = 0; count < node.numChildren; count++)
	{
		clearElements(node.children[count]);
	}
	free(node.children);
	
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

				cleaner = (char *) xmlGetProp(temp, "height");		
				(*node).children[count].height = atoi(cleaner);		
				free(cleaner);

				cleaner = (char *) xmlGetProp(temp, "width");		
				(*node).children[count].width = atoi(cleaner);		
				free(cleaner);


				cleaner = (char *) xmlGetProp(temp, "x");		
				(*node).children[count].x = atoi(cleaner);		
				free(cleaner);


				cleaner = (char *) xmlGetProp(temp, "y");		
				(*node).children[count].y = atoi(cleaner);		
				free(cleaner);


				cleaner = (char *) xmlGetProp(temp, "foreground");		
				(*node).children[count].foreground = atoi(cleaner);		
				free(cleaner);


				cleaner = (char *) xmlGetProp(temp, "background");		
				(*node).children[count].background = atoi(cleaner);		
				free(cleaner);


				cleaner = (char *) xmlGetProp(temp, "character");		
				(*node).children[count].character = ((char *)cleaner)[0];		
				free(cleaner);

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
			addToNumOccupied(node.children[count].height, node.children[count].width, node.children[count].x, node.children[count].y);
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
void addToNumOccupied(int row, int col, int xPos, int yPos)
{
	int * temp = NULL;	
	int additionalSize = row*col;
	int height = 0;
	int width = 0;
	int counter = numOccupied;
	int newSize = numOccupied+additionalSize+2;
	temp = realloc(occupiedPositions, newSize*sizeof(int));
	if(!temp)
	{
		perror("Error adding to number of occupied spaces array: ");
		exit(1);
	}
	occupiedPositions = temp;
	for(height = 0; height < row && counter < newSize; height++)
	{
		occupiedPositions[counter] = yPos+height;
		counter++;
		for(width = 0; width < col && counter < newSize; width++)
		{
			occupiedPositions[counter] = xPos+width;
			numOccupied++;
			counter++;
		}
	}

}

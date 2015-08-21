#include "interface.h"
xmlDocPtr document = NULL;
xmlNodePtr current = NULL;
void * cleaner = NULL;

void useTempPtr(void * value, int * destination)//Value is temporarily assigned
{
    cleaner = value;    
    *destination = atoi(cleaner);
    free(cleaner);
}

int setUIFile(char file[])
{
    attemptedFile[0] = '\0';
    uiFile[0] = '\0';
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
	if(occupiedXPositions)
		free(occupiedXPositions);
	if(occupiedYPositions)
		free(occupiedYPositions);
	
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
            element * elementPtr = NULL;
			if(!xmlStrcmp(temp->name,"rectangle"))
			{
                int attributeCounter = 0; //Current position in below loop
                //An array containing all the attributes of a rectangle
                char rectangleAttributes[7][15] =  
                {{"height"}, {"width"}, {"x"}, {"y"}, {"foreground"}, {"background"}, {"character"}};

				(*node).children[count].parent = node;
                elementPtr = &((*node).children[count]);

                useTempPtr((char *) xmlGetProp(temp, "height"), &(*elementPtr).height);
                useTempPtr((char *) xmlGetProp(temp, "width"), &(*elementPtr).width);
                useTempPtr((char *) xmlGetProp(temp, "x"), &(*elementPtr).x);
                useTempPtr((char *) xmlGetProp(temp, "y"), &(*elementPtr).y);
                useTempPtr((char *) xmlGetProp(temp, "foreground"), &(*elementPtr).foreground);
                useTempPtr((char *) xmlGetProp(temp, "background"), &(*elementPtr).background);

                cleaner = (char *) xmlGetProp(temp, "character");       
                (*elementPtr).character = ((char *)cleaner)[0];       
                free(cleaner);

				strcpy(&(*elementPtr).type, temp->name);		
				tempCpy = temp;
				getChildren(&((*node).children[count]), temp);
				count++;
			}
			temp = temp->next;
		}
	}
}
int checkOccupied(int x, int y)
{
	int count = 0;
	for(count = 0; count < numOccupied; count++)
	{
		if(occupiedXPositions[count] == x && occupiedYPositions[count] == y) 
		{
			//printw("%d x %d:%d x %d\n", x, y, occupiedXPositions[count], occupiedYPositions[count]);
			return 1;
		}
	}
	return 0;
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
			if(!checkOccupied(node.children[count].x, node.children[count].y))
			{
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
	temp = realloc(occupiedXPositions, newSize*sizeof(int));
	if(!temp)
	{
		perror("Error adding to number of occupied spaces array: ");
		exit(1);
	}
	occupiedXPositions = temp;
	temp = realloc(occupiedYPositions, newSize*sizeof(int));
	if(!temp)
	{
		perror("Error adding to number of occupied spaces array: ");
		exit(1);
	}
	occupiedYPositions = temp;
	for(height = 0; height < row && counter < newSize; height++)
	{
		for(width = 0; width < col && counter < newSize; width++)
		{
			occupiedXPositions[counter] = xPos+width;
			occupiedYPositions[counter] = yPos+height;

			numOccupied++;
			counter++;
		}
	}

}

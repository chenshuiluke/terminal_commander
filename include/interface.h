#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <libxml/parser.h>
#include <libxml/xmlmemory.h>

#define UI_FILE_SIZE 50
extern char uiFile[UI_FILE_SIZE]={'\0'};
extern char attemptedFile[UI_FILE_SIZE]={'\0'}; //Name of the file that is tested...uiFile will be set to this if successful

extern xmlDocPtr document;
extern xmlNodePtr current;
typedef struct el
{
	int numChildren;
	int height;
	int width;
	int x;
	int y;
	int foreground;
	int background;
	struct el * parent;
	struct el * children;
	char character;
	char type[50];
}element;
element UI={0,0,0,0,0,0,0,NULL,NULL};
int * occupiedXPositions = NULL;
int * occupiedYPositions = NULL;
int numOccupied = 0;
int setUIFile();
int testUIFile();
void readUIFile();
void printDocument();
void clearAll();
void scanUIFile();
void printUI(element node);
void getChildren(element * node,const xmlNodePtr current);
void addToNumOccupied(int height, int width, int xPos, int yPos);
int checkOccupied(int x, int y);
void useTempPtr(void * value, int * destination); //Used in getChildren. The value pointer is assigned to destination and the memory is freed
#ifdef LINUX
#include <unistd.h>
#endif
#ifdef WINDOWS
#include <windows.h>
#endif

void mySleep(int sleepMs)
{
#ifdef __gnu_linux__
    usleep(sleepMs * 1000);   // usleep takes sleep time in us (1 millionth of a second)
    #endif
    #ifdef _WIN32S
        Sleep(sleepMs);
#endif
	}
#endif

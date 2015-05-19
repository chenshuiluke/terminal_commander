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

int setUIFile();
int testUIFile();
void readUIFile();
void printDocument();
void clearAll();

#endif

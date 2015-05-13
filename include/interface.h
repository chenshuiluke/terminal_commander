#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "xml.h"

#define UI_FILE_SIZE 50
extern char uiFile[UI_FILE_SIZE]={'\0'};
extern char attemptedFile[UI_FILE_SIZE]={'\0'}; //Name of the file that is tested...uiFile will be set to this if successful

extern uint8_t * document;
extern int documentSize;

int setUIFile();
int testUIFile();
void readUIFile();
void printDocument();
void clearAll();

#endif

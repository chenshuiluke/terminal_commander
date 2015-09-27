#ifndef TERMINAL_COMMANDER
	#define TERMINAL_COMMANDER
	#include <string>
	#include "tinyxml2.h"

int openDoc(char * fileName);
int testWriteDoc(char * fileName);
void printText(char * text, int colour, int x, int y);
#endif

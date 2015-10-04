#ifndef TERMINAL_COMMANDER
	#define TERMINAL_COMMANDER
	#include <string>
	#include "tinyxml2.h"
	#include <vector>
	using namespace std;

int openDoc(string fileName);
int testWriteDoc(string fileName);
void printText(char * text, int colour, int x, int y);
void start(string fileName);
#endif

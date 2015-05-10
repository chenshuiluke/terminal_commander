#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

int terminalColumns;
int terminalRows;
char terminalDimensionsExecutable[50];

void getTerminalDimensions();

void continuouslyUpdateInfo();

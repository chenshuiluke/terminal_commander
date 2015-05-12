#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "xml.h"

#define UI_FILE "ui.xml"

extern uint8_t * document;
extern int documentSize;

void testForUI();
void readUIFile();
void printDocument();
void clearAll();

#endif

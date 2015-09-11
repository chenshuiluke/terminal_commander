#ifndef TERMINAL_COMMANDER_H
	#ifdef __gnu_linux__
		#include <ncurses.h>
	#endif
	#ifdef _WIN32
		#include <curses.h>
	#endif
	#include <pthread.h>
	#include <signal.h>
	#include <stdlib.h>
	#include "default_element_attributes.h"
	#include "terminal_info.h"
	#include <libxml/parser.h>
	#include <libxml/xmlmemory.h>
	void tc_start();
	int tc_end();
	void parseXMLtoStruct(xmlNodePtr node, int layerNum);
	void initializeDefaults();
	typedef struct tumlElement
	{
		char type[20];
		char id[20];
		char class[20];

		int x;
		int y;
		int height;
		int width;

		char foreground[10];
		char background[10];
		char text[10000];

		struct tumlElement * parent;
		struct tumlElement * children;
	}tumlElement;
	extern tumlElement ** layers;
	int * layersSize;
	void addToLayer(int layerNum, tumlElement element);
#endif

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
	void tc_start();
	int tc_end();
	void initializeDefaults();
#endif

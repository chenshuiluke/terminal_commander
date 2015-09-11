#ifndef TERMINAL_INFO_H
	#define TERMINAL_INFO_H
	#ifdef __gnu_linux__
		#include <ncurses.h>
	#endif
	#ifdef _WIN32
		#include <curses.h>
	#endif
	#include <pthread.h>
	extern int terminalRows;
	extern int terminalColumns;
	extern int terminateUpdateThread;
	void * continuouslyUpdateTerminalInfo();
#endif

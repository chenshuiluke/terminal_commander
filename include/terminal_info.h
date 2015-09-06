#ifndef TERMINAL_INFO_H
	#define TERMINAL_INFO_H
	#ifdef __gnu_linux__
		#include <ncurses.h>
	#endif
	#ifdef _WIN32
		#include <curses.h>
	#endif
	extern int terminalRows;
	extern int terminalColumns;
	void continuouslyUpdateTerminalInfo();
#endif

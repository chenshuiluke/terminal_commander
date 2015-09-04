#ifndef TERMINAL_INFO_H
	#define TERMINAL_INFO_H
	#ifdef __gnu_linux__
		#include <ncurses.h>
	#endif
	#ifdef _WIN32
		#include <curses.h>
	#endif
	extern int terminal_rows;
	extern int terminal_columns;
	void continuouslyUpdateTerminalInfo();
#endif

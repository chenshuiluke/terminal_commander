#include <stdio.h>
#include <stdlib.h>
#ifdef __gnu_linux__
	#include <ncurses.h>
#endif
#ifdef _WIN32
	#include <curses.h>
#endif
#include "interface.h"
#include "terminal_info.h"

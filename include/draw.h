#ifdef __gnu_linux__
	#include <ncurses.h>
#else
#ifdef _WIN32
	#include <curses.h>
#endif
#endif
void square(int row, int col, int xPos, int yPos, int foreground, int background);
void setColorForShape(int foreground, int background);

#ifdef __gnu_linux__
	#include <ncurses.h>
#else
#ifdef _WIN32
	#include <curses.h>
#endif
#endif
void rectangle(int height, int width, int xPos, int yPos, int foreground, int background, char character);
void text(int height, int width, int xPos, int yPos, int foreground, int background, char text[]);
void setColorForShape(int foreground, int background);

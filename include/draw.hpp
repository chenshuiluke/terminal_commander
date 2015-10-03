#include "terminal_commander.h"
#include <stdio.h>
#include "TuiXMLElement.h"

#ifdef __gnu_linux__
	#include <ncurses.h>
#else
#ifdef _WIN32
	#include <curses.h>
#endif
#endif

inline void changeStringToColour(string foregroundColour, string backgroundColour)
{
			int foreground = -1;
			int background = -1;
			static int lastColourPair = 1;

			static int set = 0;

			if(!set)
			{
				if(foregroundColour == "black")
					foreground = COLOR_BLACK;
				if(foregroundColour == "red")
					foreground = COLOR_RED;
				if(foregroundColour == "green")
					foreground = COLOR_GREEN;
				if(foregroundColour == "yellow")
					foreground = COLOR_YELLOW;
				if(foregroundColour == "blue")
					foreground = COLOR_BLUE;
				if(foregroundColour == "magenta")
					foreground = COLOR_MAGENTA;
				if(foregroundColour == "cyan")
					foreground = COLOR_CYAN;
				if(foregroundColour == "white")
					foreground = COLOR_WHITE;

				if(backgroundColour == "black")
					background = COLOR_BLACK;
				if(backgroundColour == "red")
					background = COLOR_RED;
				if(backgroundColour == "green")
					background = COLOR_GREEN;
				if(backgroundColour == "yellow")
					background = COLOR_YELLOW;
				if(backgroundColour == "blue")
					background = COLOR_BLUE;
				if(backgroundColour == "magenta")
					background = COLOR_MAGENTA;
				if(backgroundColour == "cyan")
					background = COLOR_CYAN;
				if(backgroundColour == "white")
					background = COLOR_WHITE;

				if(foreground >= 0 && background >= 0)
				{
					init_pair(lastColourPair, foreground, background);
					attron(COLOR_PAIR(lastColourPair));
					set = !set;
					lastColourPair++;
				}
			}
			else
			{
				attroff(COLOR_PAIR(1));
				set = !set;
			}
}
void drawRectangle(TuiXMLElement element)
{
	int width = element.width+1;
	int height = element.height;
	int x = element.x;
	int y = element.y;
	changeStringToColour(element.foreground, element.background);
	//cout << element.foreground << '\t' << element.background << endl;
	//locate(x, y);
	move(y, x);
	for(int counter = 0; counter < width; counter++)
	{
		for(int counter1 = 0; counter1 < height; counter1++)
		{
			printw(" ");
		}
		move(y+counter, x);
	}
	refresh();
	changeStringToColour(element.foreground, element.background);
}
void draw(TuiXMLElement element)
{
		if(element.name == "rectangle")
			drawRectangle(element);
		return;
}

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
//				attroff(COLOR_PAIR(1));
				set = !set;
			}
}
void drawRectangle(TuiXMLElement element)
{
	int width = element.width;
	int height = element.height;
	int x = element.x;
	int y = element.y;
	changeStringToColour(element.foreground, element.background);
	//cout << element.foreground << '\t' << element.background << endl;
	//locate(x, y);
	move(y, x);
	for(int counter = 0; counter < height; counter++)
	{
		for(int counter1 = 0; counter1 < width; counter1++)
		{
			printw(" ");
		}
		move(y+counter, x);
	}
	refresh();
	changeStringToColour(element.foreground, element.background);
}
void drawText(TuiXMLElement element)
{
	int width = element.width;
	int height = element.height;
	int x = element.x;
	int y = element.y;
	int stringPos = 0;
	changeStringToColour(element.foreground, element.background);
	move(y,x);
	for(int counter = 0; counter < height; counter++)
	{
		for(int counter1 = 0; counter1 < width; counter1++)
		{
			if(stringPos < element.text.length())
			{
				if(stringPos > 1)
				{
					/*
					to prevent segfaulting from dividing by zero
					and anything % 1 = 0, so we make sure that never happens
					also, width % stringPos == 0 would have produced 0.xx if the
					stringPos > width, which would've rounded down to 0.
					Therefor, we only check to see if
					*/

					if(width % stringPos < 1 && stringPos >= width)
					{
						if(counter <1)
						move(y+1, x);
						else
						move(y+counter, x);
					}
				}
				printw("%c", element.text[stringPos]);
				stringPos++;
				refresh();
			}
		}
	}
	changeStringToColour(element.foreground, element.background);
}
void draw(TuiXMLElement element)
{
		if(element.name == "rectangle")
			drawRectangle(element);
		else if(element.name == "text")
			drawText(element);
		return;
}

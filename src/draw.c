#include "draw.h"

void rectangle(int row, int col,int xPos, int yPos,int foreground, int background, char character)
{
	static int count = 0;
	int height = 0;
	int width = 0;
	setColorForShape(foreground, background);
	//printw("%d x %d %d , %d\n", row,col,xPos,yPos); 
	for(height = 0; height < row; height++)
	{
		for(width = 0; width < col; width++)
		{
			move(yPos+height, xPos+width);
			printw("%c", character);
		}
		printw("\n");
	}
	count++;
	setColorForShape(foreground, background);
}
//http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/color.html
void setColorForShape(int foreground, int background)
{
	static int used = 0;
	static int lastColourPair = 1;
	if(!((foreground >= 0 && foreground <= 7) && (background >= 0 && background <= 7)))
	{
		printw("Foreground and background colours can only be a value from 0 up to 7\n");
		refresh();
		return;
	}
	if((has_colors() == TRUE)) //If terminal supports colors...
	{
		if(!used)
		{
			init_pair(lastColourPair,foreground,background);
			attron(COLOR_PAIR(lastColourPair));
			used = 1;
			lastColourPair++;
		}
		else
		{
			attroff(COLOR_PAIR(1));
			used = 0;
		}
	}
	else
	{
		printw("Your terminal doesn't support colors\n");
	}
}

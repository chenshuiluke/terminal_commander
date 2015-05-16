#include "draw.h"

void square(int row, int col,int xPos, int yPos,int foreground, int background)
{
	int height = 0;
	int width = 0;
	setColorForShape(foreground, background);
	for(height = 0; height < row; height++)
	{
		for(width = 0; width < col; width++)
		{
			move(yPos+height, xPos+width);
			printw("*");
		}
	}
	setColorForShape(foreground, background);
}
//http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/color.html
void setColorForShape(int foreground, int background)
{
	static int used = 0;
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
			init_pair(1,foreground,background);
			attron(COLOR_PAIR(1));
			used = 1;
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

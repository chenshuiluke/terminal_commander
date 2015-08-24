#include "draw.h"
#include "terminal_info.h"

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
            int xPrintPosition = xPos + width;
            int yPrintPosition = yPos + width;
            if(yPrintPosition < terminalRows
                    && xPrintPosition < terminalRows)
            {
                move(yPos+height, xPos+width);
                printw("%c", character);
            }
		}
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
void stripOutBadChars(char * text[])
{
    char result[strlen(*text)];
    char previousChar = ' ';
    int position = 0;
    int resultPosition = 0;
    int foundFirstNonWhiteSpaceCharacter = 0;
    int duplicateSpace = 0;
    memset(result, '\0', strlen(*text));
    for(position = 0; position < strlen(*text); position++)
    {
       if(previousChar == ' ' && (*text)[position] == ' ')
       {
            duplicateSpace = 1;
       }
       else 
       {
            duplicateSpace = 0;
       }
       if((*text)[position] != ' ' && (*text)[position] != '\n' && 
       (*text)[position] != '\t' && (*text)[position] != '\r')
       {
            foundFirstNonWhiteSpaceCharacter = 1;
       }
       if((*text)[position] != '\n' && (*text)[position] != '\t' && 
       (*text)[position] != '\r' && foundFirstNonWhiteSpaceCharacter && !duplicateSpace)
       {
            result[resultPosition] = (*text)[position];
            resultPosition++;
       }
       previousChar = (*text)[position];
    }
    result[strlen(result)-1] = result[strlen(result)-1] == ' ' ? '\0' : result[strlen(result)-1];
    memset(*text, '\0', strlen(*text));
    strcpy(*text, result);
}
void text(int height, int width, int xPos, int yPos,int foreground, int background, char text[])
{
	static int count = 0;
	int position = 0;
    stripOutBadChars(&text);
    while(xPos + width > terminalRows || (yPos > terminalColumns))
    {
        if((xPos + width) > terminalRows)
        {
            xPos--;
        }
        if(yPos > terminalColumns)
        {
            yPos--;
        }
    }
    setColorForShape(foreground, background);
    for(position = 0; position < strlen(text); position++)
    {
        move(yPos, xPos);
        printw("%c", text[position]);
        if(((position+1) % width) == 0 && position > 0)
        {
            if(yPos > terminalColumns)
            {
                break;
            }
            else
            {
                yPos++;
                xPos-=width;
            }
        }
        xPos++;
    }
	count++;
	setColorForShape(foreground, background);
}

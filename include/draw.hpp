#include "terminal_commander.h"
#include "rlutil.h"
#include "termcolor.hpp"
#include "TuiXMLElement.h"

void drawRectangle(TuiXMLElement element)
{
	int width = element.width;
	int height = element.height;
	int x = element.x;
	int y = element.y;
}
void draw(TuiXMLElement element)
{
		if(element.name == "rectangle")
			draw(element);
		return;
}

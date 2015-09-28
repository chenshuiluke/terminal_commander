#include "terminal_commander.h"
#include "rlutil.h"
#include "termcolor.hpp"
#include "TuiXMLElement.h"

using namespace rlutil;

inline void changeStringToColour(string color)
{
			if(color == "grey")
			cout << termcolor::grey;
			if(color == "red")
			cout << termcolor::red;
			if(color == "green")
			cout << termcolor::green;
			if(color == "yellow")
			cout << termcolor::yellow;
			if(color == "blue")
			cout << termcolor::blue;
			if(color == "magenta")
			cout << termcolor::magenta;
			if(color == "cyan")
			cout << termcolor::cyan;
			if(color == "white")
			cout << termcolor::white;
}
inline void changeStringToBackgroundColour(string color)
{
			if(color == "grey")
			cout << termcolor::on_grey;
			if(color == "red")
			cout << termcolor::on_red;
			if(color == "green")
			cout << termcolor::on_green;
			if(color == "yellow")
			cout << termcolor::on_yellow;
			if(color == "blue")
			cout << termcolor::on_blue;
			if(color == "magenta")
			cout << termcolor::on_magenta;
			if(color == "cyan")
			cout << termcolor::on_cyan;
			if(color == "white")
			cout << termcolor::on_white;
}
void drawRectangle(TuiXMLElement element)
{
	int width = element.width+1;
	int height = element.height;
	int x = element.x;
	int y = element.y;
	changeStringToColour(element.foreground);
	changeStringToBackgroundColour(element.background);
	locate(x, y);
	for(int counter = 0; counter <= width; counter++)
	{
		for(int counter1 = 0; counter1 <= height; counter1++)
		{
			cout << " ";
			std::flush(cout);
			locate(x+counter, y+counter1);
			usleep(10000);
		}
	}
	cout << " ";
	cout << termcolor::reset;
}
void draw(TuiXMLElement element)
{
		if(element.name == "rectangle")
			drawRectangle(element);
		return;
}

#include "terminal_commander.h"
#include "rlutil.h"
#include "termcolor.hpp"
using namespace std;
using namespace tinyxml2;
using namespace rlutil;
tinyxml2::XMLDocument doc;
inline void changeIntToColor(int color)
{
	switch(color)
	{
		case 0:
			cout << termcolor::grey;
		break;
		case 1:
			cout << termcolor::red;
		break;
		case 2:
			cout << termcolor::green;
		break;
		case 3:
			cout << termcolor::yellow;
		break;
		case 4:
			cout << termcolor::blue;
		break;
		case 5:
			cout << termcolor::magenta;
		break;
		case 6:
			cout << termcolor::cyan;
		break;
		case 7:
			cout << termcolor::white;
		break;
		default:
			cout << termcolor::white;
	}
}

int openDoc(char * fileName)
{
	if(doc.LoadFile(fileName) == XML_NO_ERROR)
		return 1;
	else
		return 0;
}

int testWriteDoc(char * fileName)
{
	//https://shilohjames.wordpress.com/2014/04/27/tinyxml2-tutorial/#XML-CreateXMLDocument

	tinyxml2::XMLDocument temp;
	XMLNode * root = temp.NewElement("Root");
	temp.InsertFirstChild(root);
	XMLElement * element = temp.NewElement("tuml");
	element->SetAttribute("background", "black");
	for(int counter = 0, y = 0; counter < 5; counter++, y+=10)
	{
		char yString[5] = {'\0'};
		sprintf(yString,"%d", y);
		XMLElement * rectangle = temp.NewElement("rectangle");
		rectangle->SetAttribute("text", "");
		rectangle->SetAttribute("x", "0");
		rectangle->SetAttribute("y", yString);
		rectangle->SetAttribute("width", "5");
		rectangle->SetAttribute("height", "5");
		rectangle->SetAttribute("foreground", "cyan");
		rectangle->SetAttribute("background", "white");
		element->InsertEndChild(rectangle);
	}
	for(int counter = 0, y = 0; counter < 5; counter++, y+=10)
	{
		char textString[5][20] = {"Hello!", " Welcome", " to ", "terminal_", "commander!"};
		char yString[5] = {'\0'};
		sprintf(yString,"%d", y);
		XMLElement * text = temp.NewElement("text");
		text->SetAttribute("text", textString[counter]);
		text->SetAttribute("x", "0");
		text->SetAttribute("y", yString);
		text->SetAttribute("width", "5");
		text->SetAttribute("height", "5");
		text->SetAttribute("foreground", "blue");
		text->SetAttribute("background", "white");
		element->InsertEndChild(text);
	}
	root->InsertEndChild(element);


	return temp.SaveFile(fileName);

}
void printText(char * text, int colour, int x, int y)
{
	locate(x,y);
	changeIntToColor(colour);
	cout << text << termcolor::reset;


}

void start()
{
	cls();
}

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
	XMLElement * element = temp.NewElement("hi");
	element->SetText(10);
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

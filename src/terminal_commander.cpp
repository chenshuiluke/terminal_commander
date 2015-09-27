#include "terminal_commander.h"
#include "rlutil.h"
#include "termcolor.hpp"
using namespace std;
using namespace tinyxml2;
using namespace rlutil;
tinyxml2::XMLDocument doc;
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
	int previousColour = BLACK;
	setColor(colour);
	cout << text;
}

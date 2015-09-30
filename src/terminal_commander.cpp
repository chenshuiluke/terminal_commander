#include "terminal_commander.h"
#include "termcolor.hpp"
#include "TuiXMLElement.h"
#include "draw.hpp"
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace tinyxml2;

tinyxml2::XMLDocument doc;
vector<TuiXMLElement> layer;
vector<vector<TuiXMLElement>> layers;
int layerNum = 0;

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

int openDoc(string fileName)
{
	if(doc.LoadFile(fileName.c_str()) == XML_NO_ERROR)
		return 1;
	else
		return 0;
}

int testWriteDoc(string fileName)
{
	//https://shilohjames.wordpress.com/2014/04/27/tinyxml2-tutorial/#XML-CreateXMLDocument

	tinyxml2::XMLDocument temp;
	XMLNode * root = temp.NewElement("Root");
	temp.InsertFirstChild(root);
	XMLElement * element = temp.NewElement("tuixml");
	element->SetAttribute("background", "black");
	for(int counter = 0, y = 0; counter < 4; counter++, y+=9)
	{
		srand (time(NULL));
		for(int counter1 = 0, x = 0; counter1 < 9; x+=15, counter1++ )
		{
			string colours[] = {"grey", "red", "green", "blue", "magenta", "cyan", "white"};
			int background = rand() % 7;
			int foreground = rand() % 7;
			char yString[5] = {'\0'};
			char xString[5] = {'\0'};
			sprintf(yString,"%d", y);
			sprintf(xString,"%d", x);
			XMLElement * rectangle = temp.NewElement("rectangle");
			rectangle->SetAttribute("text", "");
			rectangle->SetAttribute("x", xString);
			rectangle->SetAttribute("y", yString);
			rectangle->SetAttribute("width", "5");
			rectangle->SetAttribute("height", "5");
			rectangle->SetAttribute("foreground", colours[foreground].c_str());
			rectangle->SetAttribute("background", colours[background].c_str());
			XMLElement * text = temp.NewElement("text");
			XMLElement * text2 = temp.NewElement("text2");
			text2->SetAttribute("blah", "Hi");
			text->InsertEndChild(text2);
			rectangle->InsertEndChild(text);
			element->InsertEndChild(rectangle);
		}
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


	return temp.SaveFile(fileName.c_str());

}
void printText(char * text, int colour, int x, int y)
{
	//locate(x,y);
	changeIntToColor(colour);
	cout << text << termcolor::reset;
}
void createElementLayers(XMLElement * element)
{
	layerNum++;
	while(element)
	{
		TuiXMLElement TuiElement(element);
	//	TuiElement.display();
//		cout << layerNum << endl;
		XMLElement * temp = element->FirstChildElement();
		if(layers.size() - 1 < layerNum)
			layers.push_back(layer);
		layers[layerNum-1].push_back(TuiElement);
		while(temp)
		{
			XMLElement * tempCpy = temp;

			createElementLayers(temp);
			temp = tempCpy->NextSiblingElement();
		}
		element = element->NextSiblingElement();
	}
	layerNum = layerNum > 0 ? layerNum - 1 : 0;
}

int parseDoc()
{
	XMLNode * root = doc.FirstChild();
	if(root == nullptr)
	{
		return XML_ERROR_FILE_READ_ERROR;
	}
	XMLElement * tuixml = root->FirstChildElement("tuixml");
	if(tuixml == nullptr)
	{
		return XML_ERROR_PARSING_ELEMENT;
	}
	XMLElement * temp = tuixml->FirstChildElement();
	layers.push_back(layer);
	createElementLayers(temp);
}

void start()
{
//	cls();
	openDoc("ui.tuixml");
	switch(parseDoc())
	{
		case XML_ERROR_FILE_READ_ERROR:
			cout << "There was an error reading ui.tuixml" << endl;
		break;
		case XML_ERROR_PARSING_ELEMENT:
			cout << "There was an error parsing ui.tuixml" << endl;
		break;
	}
	for(int counter = 0; counter < layers.size() - 1; counter++)
	{
		for(int counter1 = 0; counter1 < layers[counter].size(); counter1++)
		{
			draw(layers[counter][counter1]);
			//layers[counter][counter1].display();
		}
	}
}

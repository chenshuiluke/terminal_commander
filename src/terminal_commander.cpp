#include "terminal_commander.h"
#include "TuiXMLElement.h"
#include "draw.hpp"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;
using namespace tinyxml2;

#ifdef __gnu_linux__
	#include <ncurses.h>
#else
#ifdef _WIN32
	#include <curses.h>
#endif
#endif

tinyxml2::XMLDocument doc;
vector<TuiXMLElement> layer;
vector<vector<TuiXMLElement>> layers;
int layerNum = 0;


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
	{
			XMLElement * rectangle = temp.NewElement("rectangle");
			rectangle->SetAttribute("text", "");
			rectangle->SetAttribute("x", 0);
			rectangle->SetAttribute("y", 0);
			rectangle->SetAttribute("width", "30");
			rectangle->SetAttribute("height", "35");
			rectangle->SetAttribute("foreground", "yellow");
			rectangle->SetAttribute("background", "red");
			XMLElement * text = temp.NewElement("text");
			rectangle->InsertEndChild(text);
			element->InsertEndChild(rectangle);
	}
	for(int counter = 0, y = 0; counter < 6; counter++, y+=6)
	{
		srand (time(NULL));
		for(int counter1 = 0, x = 31; counter1 < 9; x+=6, counter1++ )
		{
			string colours[] = {"black", "red", "green", "blue", "magenta", "cyan", "white"};
			int background = rand() % 6 + 1;
			int foreground = rand() % 6 + 1;
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
			rectangle->InsertEndChild(text);
			element->InsertEndChild(rectangle);
		}
	}
	for(int counter = 0, y = 0; counter < 6; counter++, y+=6)
	{
		srand (time(NULL));
		for(int counter1 = 0, x = 85; counter1 < 9; x+=6, counter1++ )
		{
			string colours[] = {"black", "red", "green", "blue", "magenta", "cyan", "white"};
			int background = rand() % 5 + 1;
			int foreground = rand() % 5 + 1;
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
			rectangle->InsertEndChild(text);
			element->InsertEndChild(rectangle);
		}
	}
	for(int counter = 0, y = 0; counter < 6; counter++, y+=6)
	{
		char textString[10][100] = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth"};
		char yString[5] = {'\0'};
		sprintf(yString,"%d", y);
		XMLElement * text = temp.NewElement("text");
		text->SetAttribute("text", textString[counter]);
		text->SetAttribute("x", "100");
		text->SetAttribute("y", yString);
		text->SetAttribute("width", "10");
		text->SetAttribute("height", "5");
		text->SetAttribute("foreground", "blue");
		text->SetAttribute("background", "white");
		element->InsertEndChild(text);
	}
	root->InsertEndChild(element);


	return temp.SaveFile(fileName.c_str());

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

void start(string fileName = "ui.tuixml") //Make this accept a string parameter
{
//	cls();
	initscr();
	start_color();
	setvbuf(stdout, NULL, _IONBF, 0);
 	scrollok(stdscr, TRUE);
	openDoc(fileName);
	switch(parseDoc())
	{
		case XML_ERROR_FILE_READ_ERROR:
			cout << "There was an error reading " << fileName << endl;
		break;
		case XML_ERROR_PARSING_ELEMENT:
			cout << "There was an error parsing " << fileName << endl;
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
	getch();
	endwin();
}

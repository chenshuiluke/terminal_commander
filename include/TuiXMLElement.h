#ifndef TUIXML_ELEMENT_H
	#define TUIXML_ELEMENT_H
	#include <string>
	#include <iostream>
	#include "tinyxml2.h"
	using namespace tinyxml2;
	using namespace std;

class TuiXMLElement
{
public:

	int x;
	int y;
	int width;
	int height;

	string background;
	string foreground;
	string text;
	TuiXMLElement(XMLElement * element)
	{
		int temp = 0;
		x = element->QueryIntAttribute("x", &temp) != XML_NO_ATTRIBUTE ? temp : 0;
		y = element->QueryIntAttribute("y", &temp) != XML_NO_ATTRIBUTE ? temp : 0;

		width = element->QueryIntAttribute("width", &temp) != XML_NO_ATTRIBUTE ? temp : 0;
		height = element->QueryIntAttribute("height", &temp) != XML_NO_ATTRIBUTE ? temp : 0;

		foreground = element->Attribute("foreground") != 0 ? element->Attribute("foreground") : "";
		background = element->Attribute("background") != 0 ? element->Attribute("background") : "";
		text = element->Attribute("text") != 0 ? element->Attribute("text") : "";
	}
	void display()
	{
		std::cout << x << ' ' << y << ' ' << foreground << ' ' << background << ' ' << width << ' ' << height << " " <<text << endl;
	}
};
#endif

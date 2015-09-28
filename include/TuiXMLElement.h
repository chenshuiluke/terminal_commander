#ifndef TUIXML_ELEMENT_H
	#define TUIXML_ELEMENT_H
	#include <string>
	#include "tinyxml2.h"
	using namespace tinyxml2;
	using namespace std;

class TuiXMLElement
{
private:
	int x;
	int y;
	int width;
	int height;
	string background;
	string foreground;
	string text;

public:
	TuiXMLElement(XMLElement * element)
	{
		int temp = 0;
		x = element->QueryIntAttribute("x", &temp) != XML_NO_ATTRIBUTE ? temp : 0;
		y = element->QueryIntAttribute("y", &temp) != XML_NO_ATTRIBUTE ? temp : 0;

		width = element->QueryIntAttribute("width", &temp) != XML_NO_ATTRIBUTE ? temp : 0;
		height = element->QueryIntAttribute("height", &temp) != XML_NO_ATTRIBUTE ? temp : 0;

		foreground = element->Attribute("foreground") != 0 ? element->Attribute("foreground") : "";
		background = element->Attribute("background") != 0 ? element->Attribute("background") : "";
		text = element->Attribute("background") != 0 ? element->Attribute("background") : "";
	}
};
#endif

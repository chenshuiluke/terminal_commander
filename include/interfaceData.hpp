#include "pugixml.hpp"
#include <iostream>
using namespace pugi;
xml_document doc;

string initInterfaceData()
{
	xml_parse_result result = doc.load_file("ui.tuml");
	return result.description();
}

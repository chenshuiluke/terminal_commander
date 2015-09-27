#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "terminal_commander.h"

string testFile = "temp";
TEST_CASE("writeDoc", "writedoc")
{
	//https://shilohjames.wordpress.com/2014/04/27/tinyxml2-tutorial/#XML-CreateXMLDocument

	XMLDocument temp;
	XMLNode * root = temp.NewElement("Root");
	temp.InsertFirstChild(root);
	XMLElement * element = temp.NewElement("hi");
	element->SetText(10);
	root->InsertEndChild(element);

	REQUIRE(temp.SaveFile(testFile.c_str()) == XML_NO_ERROR);
}
TEST_CASE("openDoc", "opendoc")
{
	REQUIRE(openDoc(testFile) != 0);
}

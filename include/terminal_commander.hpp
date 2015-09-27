#ifndef TERMINAL_COMMANDER
	#define TERMINAL_COMMANDER
	#include <string>
	#include "pugixml.hpp"
	using namespace pugi;
	using namespace std;
	xml_document doc;
	int openDoc(string fileName)
	{
		xml_parse_result result = doc.load_file(fileName.c_str());
		if(result)
			return 1;
		else
			return 0;
	}
#endif

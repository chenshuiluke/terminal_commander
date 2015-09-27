#include "terminal_commander.h"
int openDoc(string fileName)
{
	xml_parse_result result = doc.load_file(fileName.c_str());
	if(result)
		return 1;
	else
		return 0;
}

#include "terminal_commander.h"
int openDoc(string fileName)
{
	if(doc.LoadFile(fileName.c_str()) == XML_NO_ERROR)
		return 1;
	else
		return 0;
}

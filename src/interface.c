#include "interface.h"

void testForUI()
{
	FILE * tester = NULL;
	if((tester = fopen(UI_FILE,"r")) == NULL)
	{
		perror("Unrecoverable error occurred when trying to read UI file 'ui.xml': ");
		abort();
	}
}

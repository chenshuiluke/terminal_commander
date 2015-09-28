//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
#include "terminal_commander.h"
#include "rlutil.h"

char testFile[] = "ui.tuixml";
int main()
{
	testWriteDoc(testFile);
	start();
}

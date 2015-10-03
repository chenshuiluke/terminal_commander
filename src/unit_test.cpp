//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
#include "terminal_commander.h"
#include "rlutil.h"
#include <stdio.h>
#include <iostream>

char testFile[] = "ui.tuixml";
int main()
{
	int temp = testWriteDoc(testFile);
	start();
}

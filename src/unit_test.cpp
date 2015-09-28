#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "terminal_commander.h"
#include "rlutil.h"

char testFile[] = "ui.tuixml";
TEST_CASE("writeDoc", "writedoc")
{
	start();
	REQUIRE(testWriteDoc(testFile) == 0);
}
TEST_CASE("openDoc", "opendoc")
{
	printText("Hi, welcome to terminal_commander!\n", 6, 1, 2);
}

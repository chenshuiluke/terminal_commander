#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "terminal_commander.h"
#include "rlutil.h"

char testFile[] = "temp";
TEST_CASE("writeDoc", "writedoc")
{
	REQUIRE(testWriteDoc(testFile) == 0);
}
TEST_CASE("openDoc", "opendoc")
{
	printText("hi", rlutil::WHITE, 1, 2);
}

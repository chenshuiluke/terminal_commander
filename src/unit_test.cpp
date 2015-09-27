#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "terminal_commander.h"

char testFile[] = "temp";
TEST_CASE("writeDoc", "writedoc")
{
	REQUIRE(testWriteDoc(testFile) == 0);
}
TEST_CASE("openDoc", "opendoc")
{
	REQUIRE(openDoc(testFile) != 0);
}

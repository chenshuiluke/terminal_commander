#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "terminal_commander.hpp"

TEST_CASE("Test TumlElement class consistency")
{
  tumlElement test = tumlElement();
  REQUIRE(test.getYPos() == 0);
  REQUIRE(test.getXPos() == 0);
  REQUIRE(test.getType() == "text");
  REQUIRE(test.getBackground() == "white");
  REQUIRE(test.getForeground() == "black");
  REQUIRE(test.getText() == "");
}

#include "minunit/minunit.h"
#include <string.h>
#include "terminal_commander.h"

MU_TEST(test_element_defaults)
{
    int count = 0;
    int notEqual = 0;

    char testRectangleDefaultAttributes[NUM_REC_ATTR][15] = {{"height"}, {"width"},
      {"x"}, {"y"}, {"background"}, {"foreground"}, {"character"} };

    mu_assert(NUM_REC_ATTR == 7, "The number of rectangle attributes should be 7");
    for(count = 0; count < NUM_REC_ATTR; count++)
    {
      if(strcmp(rectangleDefaultAttributes[count],testRectangleDefaultAttributes[count]))
        notEqual = 1;
    }
    mu_assert(!notEqual, "The test rectangle default attributes don't match the real rectangle default attributes");

}
MU_TEST(test_init_and_exit)
{
  mu_assert(tc_start(), "tc_start() returned a NULL pointer");
  mu_assert(tc_end() == OK, "tc_end() returned an error");
}
MU_TEST_SUITE(settings)
{
  MU_RUN_TEST(test_element_defaults);
}
MU_TEST_SUITE(test_curses)
{
    MU_RUN_TEST(test_init_and_exit);
}
int main()
{
  MU_RUN_SUITE(settings);
  MU_RUN_SUITE(test_curses);
  MU_REPORT();
}

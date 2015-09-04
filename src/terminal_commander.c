#include "terminal_commander.h"
#include <string.h>
char rectangleDefaultAttributes[NUM_REC_ATTR][15] = {{"height"}, {"width"},
  {"x"}, {"y"}, {"background"}, {"foreground"}, {"character"} };
char rectangleDefaultValues[NUM_REC_ATTR] = {10, 10, 0, 0, 1, 2, ' '};
WINDOW * tc_start()
{
  WINDOW * returnVar = 0;
  returnVar = initscr();
  setvbuf(stdout, NULL, _IONBF, 0);
  scrollok(stdscr, TRUE);
  return returnVar;
}
int tc_end()
{
  return endwin();
}

#include "terminal_commander.h"
#include <string.h>
char rectangleDefaultAttributes[NUM_REC_ATTR][15] = {{"height"}, {"width"},
  {"x"}, {"y"}, {"background"}, {"foreground"}, {"character"} };
char rectangleDefaultValues[NUM_REC_ATTR] = {10, 10, 0, 0, 1, 2, ' '};
void tc_start()
{
  initscr();
  setvbuf(stdout, NULL, _IONBF, 0);
  scrollok(stdscr, TRUE);
	signal(SIGWINCH, continuouslyUpdateTerminalInfo);
	pthread_t test; //Just to check if pthreads is working properly.
}
int tc_end()
{
  return endwin();
}

	/*
	#pragma omp parallel sections
	{
			#pragma omp section
			{
				continuouslyUpdateTerminalInfo();
			}
			#pragma omp section
			{
				printf("1\n");
			}
	}
	*/

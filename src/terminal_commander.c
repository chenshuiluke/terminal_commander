#include "terminal_commander.h"
#include <string.h>
char rectangleDefaultAttributes[NUM_REC_ATTR][15] = {{"height"}, {"width"},
  {"x"}, {"y"}, {"background"}, {"foreground"}, {"character"} };
char rectangleDefaultValues[NUM_REC_ATTR] = {10, 10, 0, 0, 1, 2, ' '};
void * testThread()
{
  puts("1");
  return 0;
}
int initThreads(pthread_t * thread1, pthread_t * thread2)
{
  int iret1, iret2;
  iret1 = pthread_create(thread1, NULL, continuouslyUpdateTerminalInfo, NULL);
  iret2 = pthread_create(thread2, NULL, NULL, NULL);
  if(iret1 || iret2)
    return 1;
  else
    return 0;
}
void tc_start()
{
  initscr();
  setvbuf(stdout, NULL, _IONBF, 0);
  scrollok(stdscr, TRUE);
	//signal(SIGWINCH, continuouslyUpdateTerminalInfo);
	pthread_t thread1, thread2;
  if(initThreads(&thread1, &thread2))
  {
    exit(1);
  }
  else
  {
    //pthread_cancel(thread1);
  }
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

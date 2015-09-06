#ifndef MISCELLANEOUS_H
	#define MISCELLANEOUS_H
void mySleep(int sleepMs)
{
	#ifdef __gnu_linux__
	    usleep(sleepMs * 1000);   // usleep takes sleep time in us (1 millionth of a second)
  #endif
  #ifdef _WIN32S
    Sleep(sleepMs);
	#endif
}
#endif

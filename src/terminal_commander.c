#include "../include/terminal_commander.h"
#include <string.h>
int elementCounter = 0;
tumlElement ** layers;
int * layersSizes;

void initLayers()
{
	layersSizes = malloc(sizeof(int) * 1);
	layers = malloc(sizeof(tumlElement) * 1);
}



char rectangleDefaultAttributes[NUM_REC_ATTR][15] = {{"height"}, {"width"},
  {"x"}, {"y"}, {"background"}, {"foreground"}, {"character"} };
char rectangleDefaultValues[NUM_REC_ATTR] = {10, 10, 0, 0, 1, 2, ' '};

void * testThread()
{
	int counter = 0;
	for(counter = 0; counter < 100; counter++)
	{
	  puts("1");
	}
  return 0;
}
int initThreads(pthread_t * thread1, pthread_t * thread2)
{
  int iret1, iret2;
  iret1 = pthread_create(thread1, NULL, continuouslyUpdateTerminalInfo, NULL);
  iret2 = pthread_create(thread2, NULL, testThread, NULL);
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
	initLayers();
	xmlNodePtr cur = NULL;
	xmlDocPtr doc = xmlParseFile("ui.tuml");
	if(doc)
	{
		cur = xmlDocGetRootElement(doc);
		if(cur)
		{
			parseXMLtoStruct(cur, 0);
		}

	}
	pthread_t thread1, thread2;
  if(initThreads(&thread1, &thread2))
  {
    exit(1);
  }
  else
  {
    //pthread_cancel(thread1);
  }
	terminateUpdateThread = 1;
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	xmlFreeDoc(doc);
	tc_end();
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

void parseXMLtoStruct(xmlNodePtr node, int layerNum)
{
	if(node->xmlChildrenNode)
	{
		parseXMLtoStruct(node->xmlChildrenNode, 0);
	}
	xmlNodePtr next = node->next;
	while(next)
	{
		char * genericTempString = NULL;
		char tempForeground[20] = {'\0'};
		char tempBackground[20] = {'\0'};
		char tempText[1000] = {'\0'};
		char tempChar = '\0';

		int genericTempNum = xmlGetProp(next, (const xmlChar *)'x');
		int tempX =  genericTempNum != NULL ? atoi(genericTempNum) : NULL;

		genericTempNum = xmlGetProp(next, (const xmlChar *)'y');
		int tempY =  genericTempNum != NULL ? atoi(genericTempNum) : NULL;

		genericTempNum = xmlGetProp(next, (const xmlChar *)'height');
		int tempHeight =  genericTempNum != NULL ? atoi(genericTempNum) : NULL;

		genericTempNum = xmlGetProp(next, (const xmlChar *)'width');
		int tempWidth =  genericTempNum != NULL ? atoi(genericTempNum) : NULL;

		genericTempString = xmlGetProp(next, (const xmlChar *)'foreground');
		if(genericTempString)
			strncpy(tempForeground, genericTempString, sizeof(char) * 20);
		else
			memset(tempForeground, '\0', sizeof(char) * 20);

		genericTempString = xmlGetProp(next, (const xmlChar *)'background');
		if(genericTempString)
			strncpy(tempBackground, genericTempString, sizeof(char) * 20);
		else
			memset(tempBackground, '\0', sizeof(char) * 20);

		genericTempString = xmlGetProp(next, (const xmlChar *)'text');
		if(genericTempString)
			strncpy(tempText, genericTempString, sizeof(char) * 1000);
		else
			memset(tempText, '\0', sizeof(char) * 1000);
		next = next->next;
		tumlElement element;
		element.x = tempX;
		element.y = tempY;
		element.height = tempHeight;
		element.width = tempWidth;
		strcpy(element.foreground, tempForeground);
		strcpy(element.background, tempBackground);
		elementCounter++;
	}
}

void addToLayer(int layerNum, tumlElement element)
{

}

#include "minunit/minunit.h"
#include <string.h>
#include "terminal_commander.h"

void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}
MU_TEST(test_pthreads)
{
     pthread_t thread1, thread2;
     const char *message1 = "Thread 1";
     const char *message2 = "Thread 2";
     int  iret1, iret2;

    /* Create independent threads each of which will execute function */

     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
		 mu_assert(!iret1, "iret1 pthread_create() error");
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);
		 mu_assert(!iret2, "iret2 pthread_create() error");


     printf("pthread_create() for thread 1 returns: %d\n",iret1);
     printf("pthread_create() for thread 2 returns: %d\n",iret2);

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL);

}

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
	tc_start();
  mu_assert(tc_end() == OK, "tc_end() returned an error");
}
MU_TEST_SUITE(settings)
{
  MU_RUN_TEST(test_element_defaults);
}
MU_TEST_SUITE(test_external_libraries)
{
    MU_RUN_TEST(test_init_and_exit);
    MU_RUN_TEST(test_pthreads);
}
int main()
{
  MU_RUN_SUITE(settings);
  MU_RUN_SUITE(test_external_libraries);
  MU_REPORT();
}

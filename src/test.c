#include <stdio.h>
#include "terminal_commander.h"
#include "../minunit/minunit.h"


MU_TEST(test_set_ui_file_variable)
{
    mu_check(setUIFile("ui.xml") == 0); 
}

MU_TEST(check_ui_file_existence)
{
    mu_check(testUIFile("ui.xml") == 1); 
}
MU_TEST(check_parse_ui_file)
{
    mu_check(xmlParseFile(uiFile) != NULL); 
}
MU_TEST(check_for_empty_ui_file)
{
    mu_check(xmlDocGetRootElement(uiFile) != NULL);
}


MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_set_ui_file_variable);
    MU_RUN_TEST(check_ui_file_existence);
    MU_RUN_TEST(check_parse_ui_file);
    MU_RUN_TEST(check_for_empty_ui_file);
}

int main()
{
   MU_RUN_SUITE(test_suite);
   MU_REPORT(); 
   return 0;
}

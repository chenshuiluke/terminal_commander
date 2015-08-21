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
    document = xmlParseFile(uiFile); 
    mu_check(document != NULL); 
}
MU_TEST(check_for_empty_ui_file)
{
    current = xmlDocGetRootElement(document);
    mu_check(current != NULL);
}
MU_TEST(check_xml_scanning_capabilities)
{
    char test_xml_variable[500] = "<ui>\n\t<rectangle height=\"5\" width = \"5\" x = \"0\" y = \"3\" foreground = \"0\" background = \"6\" character = \"+\">\n\t\t<rectangle height=\"5\" width = \"5\" x = \"50\" y = \"20\" foreground = \"0\" background = \"1\" character = \"-\">\n\t\t</rectangle>\n\t</rectangle>\n</ui>";
    FILE * fileWriter = fopen("test_ui.xml", "w");
    mu_check(fileWriter);
    if(fileWriter)
    {
       mu_check(fprintf(fileWriter, "%s", test_xml_variable) == 246); 
       fclose(fileWriter);
    }
    else
    {
        return;
    }
    mu_check(setUIFile("test_ui.xml") == 0);
    mu_check(testUIFile("test_ui.xml") == 1);
    document = xmlParseFile(uiFile); 
    current = xmlDocGetRootElement(document);
	getChildren(&UI, current);	
    mu_check(UI.numChildren == 1);
    mu_check(UI.children[0].numChildren == 1);
    mu_check(UI.children[0].x == 0 && UI.children[0].y == 3 && UI.children[0].height == 5 && UI.children[0].width == 5);
    mu_check(UI.children[0].background == 6 && UI.children[0].foreground == 0 && UI.children[0].character == '+');

    mu_check(UI.children[0].children[0].x == 50 && UI.children[0].children[0].y == 20 && UI.children[0].children[0].height == 5 && UI.children[0].children[0].width == 5);
    mu_check(UI.children[0].children[0].background == 1 && UI.children[0].children[0].foreground == 0 && UI.children[0].children[0].character == '-');
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_set_ui_file_variable);
    MU_RUN_TEST(check_ui_file_existence);
    MU_RUN_TEST(check_parse_ui_file);
    MU_RUN_TEST(check_for_empty_ui_file);
    MU_RUN_TEST(check_xml_scanning_capabilities);
}

int main()
{
   MU_RUN_SUITE(test_suite);
   MU_REPORT(); 
   return 0;
}

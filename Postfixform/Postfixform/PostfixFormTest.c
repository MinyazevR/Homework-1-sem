#include "PostfixFormTest.h"
#include "Postfix.h"
#include <stdlib.h>

bool postfixFormTest()
{
    char firstPostfixEntry[250] = "32-45*+29-*";
    char secondPostfixEntry[250] = "26---";
    char thirdPostfixEntry[250] = "34*23-+72-*";
    char fourthPostfixEntry[250] = "34=+12";
    return convertFromThePostfixForm(firstPostfixEntry) == -147
        && convertFromThePostfixForm(secondPostfixEntry) == INT_MAX
        && convertFromThePostfixForm(thirdPostfixEntry) == 55
        && convertFromThePostfixForm(fourthPostfixEntry) == INT_MAX;
}
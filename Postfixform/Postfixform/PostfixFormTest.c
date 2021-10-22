#include "PostfixFormTest.h"
#include "Postfix.h"
#include <stdlib.h>

bool postfixFormTest()
{
    char firstPostfixEntry[250] = "32-45*+29-*";
    char secondPostfixEntry[250] = "26---";
    char thirdPostfixEntry[250] = "34*23-+72-*";
    char fourthPostfixEntry[250] = "34=+12";
    bool firstCheck = true;
    bool secondCheck = true;
    bool thirdCheck = true;
    bool fourthcheck = true;
    return convertFromThePostfixForm(firstPostfixEntry, &firstCheck) == -147 && firstCheck
        && convertFromThePostfixForm(secondPostfixEntry, &secondCheck)  == 0 && !secondCheck
        && convertFromThePostfixForm(thirdPostfixEntry, &thirdCheck) == 55 && thirdCheck
        && convertFromThePostfixForm(fourthPostfixEntry, &fourthcheck) == 0 && !fourthcheck;
}
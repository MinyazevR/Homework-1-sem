#include "PostfixFormTest.h"
#include "Postfix.h"
#include <stdlib.h>

bool postfixFormTest()
{
    char firstPostfixEntry[250] = "32-45*+29-*";
    char secondPostfixEntry[250] = "26---";
    char thirdPostfixEntry[250] = "9 6 - 1 2 + *";
    char fourthPostfixEntry[250] = "34=+12";
    bool firstCheck = true;
    bool secondCheck = true;
    bool thirdCheck = true;
    bool fourthcheck = true;
    return countTheExpression(firstPostfixEntry, &firstCheck) == -147 && firstCheck
        && countTheExpression(secondPostfixEntry, &secondCheck)  == 0 && !secondCheck
        && countTheExpression(thirdPostfixEntry, &thirdCheck) == 9 && thirdCheck
        && countTheExpression(fourthPostfixEntry, &fourthcheck) == 0 && !fourthcheck;
}
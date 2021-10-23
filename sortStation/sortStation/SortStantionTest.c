#include "SortStantionTest.h"
#include "SortStantion.h"
#include <errno.h>
#include <string.h>

bool translationIntoPostfixFormAreTestPassing()
{
    char firstCorrectExpression[250] = "( 7 - 6 ) * ( 7 - ( 6 - 4 ) * 2 )";
    char secondCorrectExpression[250] = "6 * ( 8 - 4 ) / 2 + 4";
    char thirdCorrectExpression[250] = " 3 - 4 * ( 5 + 5 ) / 2 + ( 7 - ( 4 - 6 ))";
    char fourthCorrectExpression[250] = "( 5 + 7 ) / ( 4 - 2 ) - 6";
    char fifthCorrectExpression[250] = "6 - 4 * ( 5 + 4 )";
    return strcmp("76-764-2*-*", translationIntoPostfixForm(firstCorrectExpression)) == 0
        && strcmp("684-*2/4+", translationIntoPostfixForm(secondCorrectExpression)) == 0
        && strcmp("3455+*2/746--+-", translationIntoPostfixForm(thirdCorrectExpression)) == 0
        && strcmp("57+42-/6-", translationIntoPostfixForm(fourthCorrectExpression)) == 0
        && strcmp("6454+*-", translationIntoPostfixForm(fifthCorrectExpression)) == 0;
}
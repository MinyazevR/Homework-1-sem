#include "SortStantionTest.h"
#include "SortStantion.h"
#include <string.h>

bool translationIntoPostfixFormAreTestPassing()
{
    const char firstIncorrectExpression[250] = "( 7 - 6a )";
    const char secondIncorrectExpression[250] = "  7-6";
    const char thirdIncorrectExpression[250] = "(7 - 3) * 4 - 5)";
    const char fourthIncorrectExpression[250] = "4 * ( 3 + 4)";
    const char fifthIncorrectExpression[250] = "12 - 8 / a ";

    int errors[10] = {0};

    return strcmp("7 6 - 7 6 4 - 2 * - *", translationIntoPostfixForm("(7 - 6) * (7 - (6 - 4) * 2)", &errors[0])) == 0
        && strcmp("6 8 4 - * 2 / 4 +", translationIntoPostfixForm("6 * (8 - 4) / 2 + 4", &errors[1])) == 0
        && strcmp("3 4 5 5 + * 2 / - 7 4 6 - - +", translationIntoPostfixForm("3 - 4 * (5 + 5) / 2 + (7 - (4 - 6))", &errors[2])) == 0
        && strcmp("1 8 - 9 + 4 1 3 + * -", translationIntoPostfixForm("1 - 8 + 9 - 4 * (1 + 3)", &errors[3])) == 0 
        && strcmp("1 2 - 3 +", translationIntoPostfixForm("1 - 2 + 3", &errors[4])) == 0
        && translationIntoPostfixForm("( 7 - 6a )", &errors[5]) == NULL
        && translationIntoPostfixForm("7--", &errors[6]) == NULL
        && translationIntoPostfixForm("(7 - 3) * 4 - 5)", &errors[7]) == NULL
        && translationIntoPostfixForm("2 + 2)", &errors[8]) == NULL
        && translationIntoPostfixForm("12 - 8 / a", &errors[9]) == NULL;
        
}
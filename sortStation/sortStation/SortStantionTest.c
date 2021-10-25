#include "SortStantionTest.h"
#include "SortStantion.h"
#include <string.h>

bool translationIntoPostfixFormAreTestPassing()
{
    const char firstCorrectExpression[250] = "(7 - 6) * (7 - (6 - 4) * 2)";
    const char secondCorrectExpression[250] = "6 * (8 - 4) / 2 + 4";
    const char thirdCorrectExpression[250] = "3 - 4 * (5 + 5) / 2 + (7 - (4 - 6))";
    const char fourthCorrectExpression[250] = "2834 - 123 * (12 + 45 - (12 * (34 - 12) + 7))";
    const char fifthCorrectExpression[250] = "76 - 45 * (34 + 27)";

    const char firstIncorrectExpression[250] = "( 7 - 6 )";
    const char secondIncorrectExpression[250] = "  7-6";
    const char thirdIncorrectExpression[250] = "(7 - 3) * 4 - 5)";
    const char fourthIncorrectExpression[250] = "4 * ( 3 + 4)";
    const char fifthIncorrectExpression[250] = "12 - 8 / a ";

    int errors[10] = {0};

    return strcmp("7 6 - 7 6 4 - 2 * - *", translationIntoPostfixForm(firstCorrectExpression, &errors[0])) == 0 && errors[0] == 0
        && strcmp("6 8 4 - * 2 / 4 +", translationIntoPostfixForm(secondCorrectExpression, &errors[1])) == 0 && errors[1] == 0
        && strcmp("3 4 5 5 + * 2 / 7 4 6 - - + -", translationIntoPostfixForm(thirdCorrectExpression, &errors[2])) == 0 && errors[2] == 0
        && strcmp("2834 123 12 45 12 34 12 - * 7 + - + * -", translationIntoPostfixForm(fourthCorrectExpression, &errors[3])) == 0 && errors[3] == 0
        && strcmp("76 45 34 27 + * -", translationIntoPostfixForm(fifthCorrectExpression, &errors[4])) == 0 && errors[4] == 0

        && translationIntoPostfixForm(firstIncorrectExpression, &errors[5]) == NULL && errors[5] == 4
        && translationIntoPostfixForm(secondIncorrectExpression, &errors[6]) == NULL && errors[6] == 4
        && translationIntoPostfixForm(thirdIncorrectExpression, &errors[7]) == NULL && errors[7] == 3
        && translationIntoPostfixForm(fourthIncorrectExpression, &errors[8]) == NULL && errors[8] == 4
        && translationIntoPostfixForm(fifthIncorrectExpression, &errors[9]) == NULL && errors[9] == 3;
        
}
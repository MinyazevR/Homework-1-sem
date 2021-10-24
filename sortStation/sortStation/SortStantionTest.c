#include "SortStantionTest.h"
#include "SortStantion.h"
#include <errno.h>
#include <string.h>

bool translationIntoPostfixFormAreTestPassing()
{
    char firstCorrectExpression[250] = "(7 - 6) * (7 - (6 - 4) * 2)";
    char secondCorrectExpression[250] = "6 * (8 - 4) / 2 + 4";
    char thirdCorrectExpression[250] = "3 - 4 * (5 + 5) / 2 + (7 - (4 - 6))";
    char fourthCorrectExpression[250] = "(5 + 7) / (4 - 2) - 6";
    char fifthCorrectExpression[250] = "6 - 4 * (5 + 4)";

    char firstIncorrectExpression[250] = "( 7 - 6 )";
    char secondIncorrectExpression[250] = "  7-6";
    char thirdIncorrectExpression[250] = "(7 - 3)*(4 - 5)";
    char fourthIncorrectExpression[250] = "4 * ( 3 + 4)";
    char fifthIncorrectExpression[250] = "12 - 8 *";

    return strcmp("7 6 - 7 6 4 - 2 * - *", translationIntoPostfixForm(firstCorrectExpression)) == 0
        && strcmp("6 8 4 - * 2 / 4 +", translationIntoPostfixForm(secondCorrectExpression)) == 0
        && strcmp("3 4 5 5 + * 2 / 7 4 6 - - + -", translationIntoPostfixForm(thirdCorrectExpression)) == 0
        && strcmp("5 7 + 4 2 - / 6 -", translationIntoPostfixForm(fourthCorrectExpression)) == 0
        && strcmp("6 4 5 4 + * -", translationIntoPostfixForm(fifthCorrectExpression)) == 0

        && translationIntoPostfixForm(firstIncorrectExpression) == NULL
        && translationIntoPostfixForm(secondIncorrectExpression) == NULL
        && translationIntoPostfixForm(thirdIncorrectExpression) == NULL
        && translationIntoPostfixForm(fourthIncorrectExpression) == NULL
        && translationIntoPostfixForm(fifthIncorrectExpression) == NULL;
        
}
#include "SortStantionTest.h"
#include "SortStantion.h"
#include <errno.h>
#include <string.h>

bool translationIntoPostfixFormAreTestPassing()
{
    char firstCorrectExpression[250] = "(7 - 6) * (7 - (6 - 4) * 2)";
    char secondCorrectExpression[250] = "6 * (8 - 4) / 2 + 4";
    char thirdCorrectExpression[250] = "3 - 4 * (5 + 5) / 2 + (7 - (4 - 6))";
    char fourthCorrectExpression[250] = "2834 - 123 * (12 + 45 - (12 * (34 - 12) + 7))";
    char fifthCorrectExpression[250] = "76 - 45 * (34 + 27)";

    char firstIncorrectExpression[250] = "( 7 - 6 )";
    char secondIncorrectExpression[250] = "  7-6";
    char thirdIncorrectExpression[250] = "(7 - 3)*(4 - 5)";
    char fourthIncorrectExpression[250] = "4 * ( 3 + 4)";
    char fifthIncorrectExpression[250] = "12 - 8 *";

    return strcmp("7 6 - 7 6 4 - 2 * - *", translationIntoPostfixForm(firstCorrectExpression)) == 0
        && strcmp("6 8 4 - * 2 / 4 +", translationIntoPostfixForm(secondCorrectExpression)) == 0
        && strcmp("3 4 5 5 + * 2 / 7 4 6 - - + -", translationIntoPostfixForm(thirdCorrectExpression)) == 0
        && strcmp("2834 123 12 45 12 34 12 - * 7 + - + * -", translationIntoPostfixForm(fourthCorrectExpression)) == 0
        && strcmp("76 45 34 27 + * -", translationIntoPostfixForm(fifthCorrectExpression)) == 0

        && translationIntoPostfixForm(firstIncorrectExpression) == NULL
        && translationIntoPostfixForm(secondIncorrectExpression) == NULL
        && translationIntoPostfixForm(thirdIncorrectExpression) == NULL
        && translationIntoPostfixForm(fourthIncorrectExpression) == NULL
        && translationIntoPostfixForm(fifthIncorrectExpression) == NULL;
        
}
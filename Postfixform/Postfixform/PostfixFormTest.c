#include "PostfixFormTest.h"
#include "Postfix.h"

bool areTestPassingPostfixForm()
{
    char firstCorrectPostfixEntry[250] = "3 2 - 4 5 * + 2 9 - *";
    char secondCorrectPostfixEntry[250] = "2 3 - 4 5 * +";
    char thirdCorrectPostfixEntry[250] = "9 6 - 1 2 + *";
    char fourthCorrectPostfixEntry[250] = "9 6 - 3 4 * + 5 6 - +";
    char fifthCorrectPostfixEntry[250] = "9 6 - 3 -";

    char firstIncorrectPostfixEntry[250] = "--35 a-";
    char secondIncorrectPostfixEntry[250] = "456 26";
    char thirdIncorrectPostfixEntry[250] = "34 - 345";
    char fourthIncorrectPostfixEntry[250] = "12 - 34 + 4";
    char fifthIncorrectPostfixEntry[250] = "1234 - 12";

    return countTheExpression(firstCorrectPostfixEntry) == -147
        && countTheExpression(secondCorrectPostfixEntry)  == 19
        && countTheExpression(thirdCorrectPostfixEntry) == 9
        && countTheExpression(fourthCorrectPostfixEntry) == 14
        && countTheExpression(fifthCorrectPostfixEntry) == 0

        && countTheExpression(firstIncorrectPostfixEntry) == 0 
        && countTheExpression(secondIncorrectPostfixEntry) == 0
        && countTheExpression(thirdIncorrectPostfixEntry) == 0
        && countTheExpression(fourthIncorrectPostfixEntry) == 0
        && countTheExpression(fifthIncorrectPostfixEntry) == 0;
}
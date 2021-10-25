#include "PostfixFormTest.h"
#include "Postfix.h"

bool areTestPassingPostfixForm()
{
    const char firstCorrectPostfixEntry[250] = "3 2 - 4 5 * + 2 9 - *";
    const char secondCorrectPostfixEntry[250] = "2 3 - 4 5 * +";
    const char thirdCorrectPostfixEntry[250] = "9 6 - 1 2 + *";
    const char fourthCorrectPostfixEntry[250] = "9 6 - 5 2 / +";
    const char fifthCorrectPostfixEntry[250] = "9 6 - 3 -";

    const char firstIncorrectPostfixEntry[250] = "3 5 a";
    const char secondIncorrectPostfixEntry[250] = "4 0 /";
    const char thirdIncorrectPostfixEntry[250] = "34 - 345";
    const char fourthIncorrectPostfixEntry[250] = "12 - 34 + 4";
    const char fifthIncorrectPostfixEntry[250] = "1234 - 12";

    int errorCode[10] = {0};
    
    return countTheExpression(firstCorrectPostfixEntry, &errorCode[0]) == -147 && errorCode[0] == 0
        && countTheExpression(secondCorrectPostfixEntry, &errorCode[1])  == 19 && errorCode[1] == 0
        && countTheExpression(thirdCorrectPostfixEntry, &errorCode[2]) == 9 && errorCode[2] == 0
        && countTheExpression(fourthCorrectPostfixEntry, &errorCode[3]) == 5.5 && errorCode[3] == 0
        && countTheExpression(fifthCorrectPostfixEntry, &errorCode[4]) == 0 && errorCode[4] == 0

        && countTheExpression(firstIncorrectPostfixEntry, &errorCode[5]) == 0 && errorCode[5] == 2
        && countTheExpression(secondIncorrectPostfixEntry, &errorCode[6]) == 0 && errorCode[6] == 3
        && countTheExpression(thirdIncorrectPostfixEntry, &errorCode[7]) == 0 && errorCode[7] == 1
        && countTheExpression(fourthIncorrectPostfixEntry, &errorCode[8]) == 0 && errorCode[8] == 1
        && countTheExpression(fifthIncorrectPostfixEntry, &errorCode[9]) == 0 && errorCode[9] == 1;
}
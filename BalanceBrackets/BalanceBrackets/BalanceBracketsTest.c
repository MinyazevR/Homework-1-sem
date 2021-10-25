#include "BalanceBracketsTest.h"
#include "BalanceBrackets.h"

bool balanceBracketsTest()
{
    const char firstCorrectExpressionFromParentheses[250] = "((15 - x) - (13 + 45) * ( 1 0 - 1 6))";
    const char secondCorrectExpressionFromParentheses[250] = "(([(){()}][]{}{}{()}))";
    const char thirdCorrectExpressionFromParentheses[250] = "([[]({})]({}(())))";
    const char fourthCorrectExpressionFromParentheses[250] = "(x * x) * ( c - a)";
    const char fifthCorrectExpressionFromParentheses[250] = "[[]]{{}}(())";
    const char sixthCorrectExpressionFromParentheses[250] = "(({{{}[]}[]}[]))";
    const char seventhCorrectExpressionFromParentheses[250] = "{}()[]";

    const char firstIncorrectExpressionFromParentheses[250] = "{{";
    const char secondIncorrectExpressionFromParentheses[250] = "{())[][]}";
    const char thirdIncorrectExpressionFromParentheses[250] = "(x-a)*(c+a))";
    const char fourthIncorrectExpressionFromParentheses[250] = "(]])()()[][]{}{{}}";
    const char fifthIncorrectExpressionFromParentheses[250] = "{()[]{}{{))))))(}";
    const char sixthIncorrectExpressionFromParentheses[250] = "{{}}(((";
    const char seventhIncorrectExpressionFromParentheses[250] = "(";

    return checkCorrectOrderBrackets(firstCorrectExpressionFromParentheses)
        && checkCorrectOrderBrackets(secondCorrectExpressionFromParentheses)
        && checkCorrectOrderBrackets(thirdCorrectExpressionFromParentheses)
        && checkCorrectOrderBrackets(fourthCorrectExpressionFromParentheses)
        && checkCorrectOrderBrackets(fifthCorrectExpressionFromParentheses)
        && checkCorrectOrderBrackets(sixthCorrectExpressionFromParentheses)
        && checkCorrectOrderBrackets(seventhCorrectExpressionFromParentheses)

        && !checkCorrectOrderBrackets(firstIncorrectExpressionFromParentheses)
        && !checkCorrectOrderBrackets(secondIncorrectExpressionFromParentheses)
        && !checkCorrectOrderBrackets(thirdIncorrectExpressionFromParentheses)
        && !checkCorrectOrderBrackets(fourthIncorrectExpressionFromParentheses)
        && !checkCorrectOrderBrackets(fifthIncorrectExpressionFromParentheses)
        && !checkCorrectOrderBrackets(sixthIncorrectExpressionFromParentheses)
        && !checkCorrectOrderBrackets(seventhIncorrectExpressionFromParentheses);   
}
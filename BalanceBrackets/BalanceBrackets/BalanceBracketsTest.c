#include "BalanceBracketsTest.h"
#include "BalanceBrackets.h"

bool balanceBracketsTest()
{
    char firstCorrectExpressionFromParentheses[250] = "((15 - x) - (13 + 45) * ( 1 0 - 1 6))";
    char secondCorrectExpressionFromParentheses[250] = "(([(){()}][]{}{}{()}))";
    char thirdCorrectExpressionFromParentheses[250] = "([[]({})]({}(())))";
    char fourthCorrectExpressionFromParentheses[250] = "(x * x) * ( c - a)";
    char fifthCorrectExpressionFromParentheses[250] = "[[]]{{}}(())";
    char sixthCorrectExpressionFromParentheses[250] = "(({{{}[]}[]}[]))";
    char seventhCorrectExpressionFromParentheses[250] = "{}()[]";
    char firstIncorrectExpressionFromParentheses[250] = "{{";
    char secondIncorrectExpressionFromParentheses[250] = "{())[][]}";
    char thirdIncorrectExpressionFromParentheses[250] = "(x-a)*(c+a))";
    char fourthIncorrectExpressionFromParentheses[250] = "(]])()()[][]{}{{}}";
    char fifthIncorrectExpressionFromParentheses[250] = "{()[]{}{{))))))(}";
    char sixthIncorrectExpressionFromParentheses[250] = "{{}}(((";
    char seventhIncorrectExpressionFromParentheses[250] = "(";
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
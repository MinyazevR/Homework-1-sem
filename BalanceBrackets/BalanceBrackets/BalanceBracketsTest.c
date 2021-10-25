#include "BalanceBracketsTest.h"
#include "BalanceBrackets.h"

bool balanceBracketsTest()
{
    int errors[14] = {0};
    return checkCorrectOrderBrackets("((15 - x) - (13 + 45) * ( 1 0 - 1 6))", &errors[0])
    && checkCorrectOrderBrackets("(([(){()}][]{}{}{()}))", &errors[1]) 
    && checkCorrectOrderBrackets("([[]({})]({}(())))", &errors[2])
    && checkCorrectOrderBrackets("(x * x) * ( c - a)", &errors[3])
    && checkCorrectOrderBrackets("[[]]{{}}(())", &errors[4])
    && checkCorrectOrderBrackets("(({{{}[]}[]}[]))", &errors[5])
    && checkCorrectOrderBrackets("{}()[]", &errors[6])
    && !checkCorrectOrderBrackets("{{", &errors[7])
    && !checkCorrectOrderBrackets("{())[][]}", &errors[8])
    && !checkCorrectOrderBrackets("(x-a)*(c+a))", &errors[9])
    && !checkCorrectOrderBrackets("(]])()()[][]{}{{}}", &errors[10])
    && !checkCorrectOrderBrackets("{()[]{}{{))))))(}", &errors[11])
    && !checkCorrectOrderBrackets("{{}}(((", &errors[12])
    && !checkCorrectOrderBrackets("(", &errors[13]);
}
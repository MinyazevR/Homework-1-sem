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
    && !checkCorrectOrderBrackets("(", &errors[13])
    && errors[0] == 0
    && errors[1] == 0
    && errors[2] == 0
    && errors[3] == 0
    && errors[4] == 0
    && errors[5] == 0
    && errors[6] == 0
    && errors[7] == 1
    && errors[8] == 1
    && errors[9] == 1
    && errors[10] == 1
    && errors[11] == 1
    && errors[12] == 1
    && errors[13] == 1;

}
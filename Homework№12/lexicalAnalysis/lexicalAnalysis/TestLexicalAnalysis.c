#include "TestLexicalAnalysis.h"
#include "LexicalAnalysis.h"

bool testCheckTestExpression()
{
    bool firstResult = checkExpression("3");
    bool secondResult = checkExpression("3.734432");
    bool thirdResult = checkExpression("33412.253253");
    bool fourthResult = checkExpression("234.2424E-10");
    bool fifthResult = checkExpression("3.0001E+10");
    bool sixthResult = checkExpression("3.");
    bool seventhResult = checkExpression("3.E");
    bool eighthResult = checkExpression("3324.23455E+");
    bool ninthResult = checkExpression("");
    bool tenthResult = checkExpression("3E-1111.1221");
    return firstResult && secondResult && thirdResult && fourthResult && fifthResult
        && !sixthResult && !seventhResult && !eighthResult && !ninthResult && !tenthResult;
}
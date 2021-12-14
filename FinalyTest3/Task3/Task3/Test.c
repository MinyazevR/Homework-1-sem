#include "Test.h"
#include "Expression.h"

bool testIsTheStringAGroup()
{
    return isTheStringAGroup("21.B10-mm") && !isTheStringAGroup("21.B10mm")
        && isTheStringAGroup("12.M07-mm") && !isTheStringAGroup("12.M007-mu")
        && isTheStringAGroup("45.S12-mm") && !isTheStringAGroup("12.S.12-mM");
}
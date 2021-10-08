#include <stdio.h>
#include"testRecordCounter.h"
#include "srtuct.h"
#include "recordCounter.h"

bool testRecordCounter()
{
    Phonebook arrayForTestFindNameByNumber[4] = { '\0' };
    recordCounter(arrayForTestFindNameByNumber, "test1.txt");
    return recordCounter(arrayForTestFindNameByNumber, "test1.txt") == 4;
}
#include <stdio.h>
#include"testRecordCounter.h"
#include "recordCounter.h"
#include "srtuct.h"

bool testRecordCounter()
{
    Phonebook arrayForTestFindNameByNumber[4] = { '\0' };
    recordCounter(arrayForTestFindNameByNumber, "test1.txt");
    return recordCounter(arrayForTestFindNameByNumber, "test1.txt") == 4;
}
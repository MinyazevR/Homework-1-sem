#include "TestFindSurvivorPosition.h"
#include "CircleOfMurders.h"

bool testFindSurviviorPosition()
{
    int error = 0;
    return findSurvivorPosition(10 , 5, &error) == 3 && findSurvivorPosition(7, 4, &error) == 3
    && findSurvivorPosition(20, 3, &error) == 20 && findSurvivorPosition(15, 7, &error) == 5 && findSurvivorPosition(12, 3, &error) == 10;
}
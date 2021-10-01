#include "tests.h"

bool comparingDigitsInArrays(int* firstArrayOfDigits, int* secondArrayOFDigits)
{
    for(int j = 0; j < sizeof(int)*8; j++)
    { 
        if (firstArrayOfDigits[j] != secondArrayOFDigits[j])
        {
            return false;
        }
    }
    return true;
}
bool testWritingDigitsToArray()
{
    int representationOfNumber31[sizeof(int)*8] = {1, 1, 1, 1, 1 };
    int arrayForWritingTheNumber31[sizeof(int)*8] = {0};
    writingDigitsToArray(arrayForWritingTheNumber31, 31);
    return comparingDigitsInArrays(representationOfNumber31, arrayForWritingTheNumber31);
}
#include "tests.h"
#include "binaryNumberSystem.h"

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
    // check for writing positive numbers
    int representationOfNumber31[sizeof(int)*8] = {1, 1, 1, 1, 1 };
    int arrayForWritingTheNumber31[sizeof(int)*8] = {0};
    writingDigitsToArray(arrayForWritingTheNumber31, 31);
    int representationOfNumber123[sizeof(int) * 8] = { 1, 1, 0, 1, 1, 1, 1 };
    int arrayForWritingTheNumber123[sizeof(int) * 8] = { 0 };
    writingDigitsToArray(arrayForWritingTheNumber123, 123);

    // check for writing negative numbers
    int representationOfNumberMinus12[sizeof(int) * 8] = { 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int arrayForWritingTheNumberMinus12[sizeof(int) * 8] = { 0 };
    writingDigitsToArray(arrayForWritingTheNumberMinus12, -12);
    int representationOfNumberMinus245[sizeof(int) * 8] = { 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int arrayForWritingTheNumberMinus245[sizeof(int) * 8] = { 0 };
    writingDigitsToArray(arrayForWritingTheNumberMinus245, -245);

    return comparingDigitsInArrays(representationOfNumber31, arrayForWritingTheNumber31)
        && comparingDigitsInArrays(representationOfNumber123, arrayForWritingTheNumber123)
        && comparingDigitsInArrays(representationOfNumberMinus12, arrayForWritingTheNumberMinus12)
        && comparingDigitsInArrays(representationOfNumberMinus245, arrayForWritingTheNumberMinus245);
}

bool testAdditionOfDigitsOfTwoNumbers()
{
    int representationOfNumber31[sizeof(int) * 8] = { 1, 1, 1, 1, 1 };
    int representationOfNumberMinus12[sizeof(int) * 8] = { 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int representationOfNumber19[sizeof(int)*8] = { 1, 1, 0, 0, 1 };
    int arrayForWritingTheNumber19[sizeof(int) * 8] = { 0 };
    additionOfDigitsOfTwoNumbers(representationOfNumber31, representationOfNumberMinus12, arrayForWritingTheNumber19);

    int representationOfNumberMinus245[sizeof(int) * 8] = { 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int representationOfNumber123[sizeof(int) * 8] = { 1, 1, 0, 1, 1, 1, 1 };
    int representationOfNumberMinus122[sizeof(int) * 8] = { 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int arrayForWritingTheNumberMinus122[sizeof(int) * 8] = { 0 };
    additionOfDigitsOfTwoNumbers(representationOfNumberMinus245, representationOfNumber123, arrayForWritingTheNumberMinus122);

    return comparingDigitsInArrays(representationOfNumberMinus122, arrayForWritingTheNumberMinus122)
        && comparingDigitsInArrays(representationOfNumber19, arrayForWritingTheNumber19);
}

bool testConvertNumberFromBinaryToDecimal()
{
    int representationOfNumber31[sizeof(int) * 8] = { 1, 1, 1, 1, 1 };
    int representationOfNumberMinus12[sizeof(int) * 8] = { 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int representationOfNumber19[sizeof(int) * 8] = { 1, 1, 0, 0, 1 };
    return convertNumberFromBinaryToDecimal(representationOfNumber19) == 19
        && convertNumberFromBinaryToDecimal(representationOfNumber31) == 31
        && convertNumberFromBinaryToDecimal(representationOfNumberMinus12) == -12;
}
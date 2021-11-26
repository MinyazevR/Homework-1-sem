#include "binaryNumberSystem.h"
#include <stdio.h>

void writeDigitsToArray(int* arrayOfNumber, int numberToWrite)
{
    for (int j = 0; j < sizeof(int) * 8; ++j)
    {
        arrayOfNumber[j] = ((numberToWrite & 1) ? 1 : 0);
        numberToWrite >>= 1;
    }
}

void outputtingNumberInBinaryNotation(int* arrayOfNumber)
{
    for (int j = sizeof(int) * 8 - 1; j >= 0; --j)
    {
        printf("%d", arrayOfNumber[j]);
    }
}

void additionOfDigitsOfTwoNumbers(int* arrayOfDigitsOfTheFirstNumber, int* arrayOfDigitsOfTheSecondNumber,int* arrayForWritingTheSumOfDigits)
{
    int remainder = 0;
    for (int j = 0; j < sizeof(int) * 8; ++j)
    {
        if (j > 0 && arrayOfDigitsOfTheFirstNumber[j - 1] + arrayOfDigitsOfTheSecondNumber[j - 1]
            + remainder == 2 || j > 0 && arrayOfDigitsOfTheFirstNumber[j - 1] + arrayOfDigitsOfTheSecondNumber[j - 1] + remainder == 3)
        {
            remainder = 1;
        }
        else
        {
            remainder = 0;
        }
        arrayForWritingTheSumOfDigits[j] = (arrayOfDigitsOfTheFirstNumber[j] + arrayOfDigitsOfTheSecondNumber[j] + remainder) % 2;
    }
}

int convertNumberFromBinaryToDecimal(int* arrayForWritingTheSumOfDigits)
{
    int decimalNumber = 0;
    int positionMagnifier = 1;
    for (int j = 0; j <= sizeof(int) * 8 - 1; j++)
    {
        decimalNumber = decimalNumber | (arrayForWritingTheSumOfDigits[j] == 0 ? 0 : positionMagnifier);
        positionMagnifier *= 2;
    }
    return decimalNumber;
}
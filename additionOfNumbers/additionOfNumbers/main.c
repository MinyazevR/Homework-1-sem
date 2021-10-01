#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "binaryNumberSystem.h"

int main()
{
    if (!testWritingDigitsToArray())
    {
        printf("Tect провален");
        return -1;
    }
    int firstNumber = 0;
    printf("enter first number");
    const int scanfFirstNumberResult = scanf_s("%d", &firstNumber);
    if (scanfFirstNumberResult == 0)
    {
        return -1;
    }
    printf("%d", firstNumber & 1);
    int secondNumber = 0;
    printf("enter second number");
    scanf_s("%d", &secondNumber);
    const int scanfSecondNumberResult = scanf_s("%d", &firstNumber);
    if (scanfSecondNumberResult == 0)
    {
        return -1;
    }

    int* arrayForWritingTheDigitsOfFirstNumber = (int*)calloc(32, sizeof(int));
    if (arrayForWritingTheDigitsOfFirstNumber == NULL)
    {
        return -1;
    }
    writingDigitsToArray(arrayForWritingTheDigitsOfFirstNumber, firstNumber);
    outputtingNumberInBinaryNotation(arrayForWritingTheDigitsOfFirstNumber);
    printf("\n\n");
    int* arrayForWritingTheDigitsOfSecondNumber = (int*)calloc(32, sizeof(int));
    if (arrayForWritingTheDigitsOfSecondNumber == NULL)
    {
        return -1;
    }
    writingDigitsToArray(arrayForWritingTheDigitsOfSecondNumber, secondNumber);
    outputtingNumberInBinaryNotation(arrayForWritingTheDigitsOfSecondNumber);
    printf("\n\n");
    int* arrayForWritingTheSumOfDigits = (int*)calloc(32, sizeof(int));
    if (arrayForWritingTheSumOfDigits == NULL)
    {
        return -1;
    }
    additionOfDigitsOfTwoNumbers(arrayForWritingTheDigitsOfFirstNumber, arrayForWritingTheDigitsOfSecondNumber, arrayForWritingTheSumOfDigits);
    outputtingNumberInBinaryNotation(arrayForWritingTheSumOfDigits);
    printf("\n\n");
    printf("%d", convertNumberFromBinaryToDecimal(arrayForWritingTheSumOfDigits));
    free(arrayForWritingTheDigitsOfFirstNumber);
    free(arrayForWritingTheDigitsOfSecondNumber);
    free(arrayForWritingTheSumOfDigits);
}


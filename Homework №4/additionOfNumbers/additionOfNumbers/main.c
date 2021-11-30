#include <stdio.h>
#include <locale.h>
#include "binaryNumberSystem.h"
#include "tests.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    if (!testWritingDigitsToArray() || !testAdditionOfDigitsOfTwoNumbers() || !testConvertNumberFromBinaryToDecimal())
    {
        printf("Tecт провален");
        return -1;
    }
    if (argc != 0)
    {
        return 0;
    }
    int firstNumber = 0;
    printf("введите первое число\n");
    const int scanfFirstNumberResult = scanf_s("%d", &firstNumber);
    if (scanfFirstNumberResult == 0)
    {
        return -1;
    }
    int secondNumber = 0;
    printf("введите второе число\n");
    const int scanfSecondNumberResult = scanf_s("%d", &secondNumber);
    if (scanfSecondNumberResult == 0)
    {
        return -1;
    }

    int arrayForWritingTheDigitsOfFirstNumber[8 * sizeof(int)] = { 0 };
    writeDigitsToArray(arrayForWritingTheDigitsOfFirstNumber, firstNumber);
    printf("первое число в 2 системе счисления:    ");
    outputtingNumberInBinaryNotation(arrayForWritingTheDigitsOfFirstNumber);
    printf("\n\n");

    int arrayForWritingTheDigitsOfSecondNumber[8 * sizeof(int)] = { 0 };
    writeDigitsToArray(arrayForWritingTheDigitsOfSecondNumber, secondNumber);
    printf("второе число в 2 системе счисления:    ");
    outputtingNumberInBinaryNotation(arrayForWritingTheDigitsOfSecondNumber);
    printf("\n\n");

    int arrayForWritingTheSumOfDigits[8 * sizeof(int)] = { 0 };
    additionOfDigitsOfTwoNumbers(arrayForWritingTheDigitsOfFirstNumber, arrayForWritingTheDigitsOfSecondNumber, arrayForWritingTheSumOfDigits);
    printf("сумма чисел в 2 системе счисления:     ");
    outputtingNumberInBinaryNotation(arrayForWritingTheSumOfDigits);
    printf("\n\n");
    printf("сумма чисел в 10 системе счисления: %d", convertNumberFromBinaryToDecimal(arrayForWritingTheSumOfDigits));
}


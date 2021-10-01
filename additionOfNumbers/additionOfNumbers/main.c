#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "binaryNumberSystem.h"
#include "tests.h"

int main()
{
    setlocale(LC_ALL, "rus");
    if (!testWritingDigitsToArray() || !testAdditionOfDigitsOfTwoNumbers() || !testConvertNumberFromBinaryToDecimal())
    {
        printf("Tec� ��������");
        return -1;
    }
    int firstNumber = 0;
    printf("������� ������ �����\n");
    const int scanfFirstNumberResult = scanf_s("%d", &firstNumber);
    if (scanfFirstNumberResult == 0)
    {
        return -1;
    }
    int secondNumber = 0;
    printf("������� ������ �����\n");
    const int scanfSecondNumberResult = scanf_s("%d", &secondNumber);
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
    printf("������ ����� � 2 ������� ���������:    ");
    outputtingNumberInBinaryNotation(arrayForWritingTheDigitsOfFirstNumber);
    printf("\n\n");

    int* arrayForWritingTheDigitsOfSecondNumber = (int*)calloc(32, sizeof(int));
    if (arrayForWritingTheDigitsOfSecondNumber == NULL)
    {
        return -1;
    }
    writingDigitsToArray(arrayForWritingTheDigitsOfSecondNumber, secondNumber);
    printf("������ ����� � 2 ������� ���������:    ");
    outputtingNumberInBinaryNotation(arrayForWritingTheDigitsOfSecondNumber);
    printf("\n\n");

    int* arrayForWritingTheSumOfDigits = (int*)calloc(32, sizeof(int));
    if (arrayForWritingTheSumOfDigits == NULL)
    {
        return -1;
    }

    additionOfDigitsOfTwoNumbers(arrayForWritingTheDigitsOfFirstNumber, arrayForWritingTheDigitsOfSecondNumber, arrayForWritingTheSumOfDigits);
    printf("����� ����� � 2 ������� ���������:     ");
    outputtingNumberInBinaryNotation(arrayForWritingTheSumOfDigits);
    printf("\n\n");
    printf("����� ����� � 10 ������� ���������: %d", convertNumberFromBinaryToDecimal(arrayForWritingTheSumOfDigits));
    free(arrayForWritingTheDigitsOfFirstNumber);
    free(arrayForWritingTheDigitsOfSecondNumber);
    free(arrayForWritingTheSumOfDigits);
}


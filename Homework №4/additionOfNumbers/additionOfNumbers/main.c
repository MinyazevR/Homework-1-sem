#include <stdio.h>
#include <locale.h>
#include "binaryNumberSystem.h"
#include "tests.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    if (!testWritingDigitsToArray() || !testAdditionOfDigitsOfTwoNumbers() || !testConvertNumberFromBinaryToDecimal())
    {
        printf("Tec� ��������");
        return -1;
    }
    if (argc != 0)
    {
        return 0;
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

    int arrayForWritingTheDigitsOfFirstNumber[8 * sizeof(int)] = { 0 };
    writeDigitsToArray(arrayForWritingTheDigitsOfFirstNumber, firstNumber);
    printf("������ ����� � 2 ������� ���������:    ");
    outputtingNumberInBinaryNotation(arrayForWritingTheDigitsOfFirstNumber);
    printf("\n\n");

    int arrayForWritingTheDigitsOfSecondNumber[8 * sizeof(int)] = { 0 };
    writeDigitsToArray(arrayForWritingTheDigitsOfSecondNumber, secondNumber);
    printf("������ ����� � 2 ������� ���������:    ");
    outputtingNumberInBinaryNotation(arrayForWritingTheDigitsOfSecondNumber);
    printf("\n\n");

    int arrayForWritingTheSumOfDigits[8 * sizeof(int)] = { 0 };
    additionOfDigitsOfTwoNumbers(arrayForWritingTheDigitsOfFirstNumber, arrayForWritingTheDigitsOfSecondNumber, arrayForWritingTheSumOfDigits);
    printf("����� ����� � 2 ������� ���������:     ");
    outputtingNumberInBinaryNotation(arrayForWritingTheSumOfDigits);
    printf("\n\n");
    printf("����� ����� � 10 ������� ���������: %d", convertNumberFromBinaryToDecimal(arrayForWritingTheSumOfDigits));
}


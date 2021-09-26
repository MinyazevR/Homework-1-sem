#include "Header.h"

// ������� ��� �������� ����������������� �������
bool sorting�heck(int* arrayOfNumber, int numberOfElements)
{
    for (int i = 0; i < numberOfElements - 1; i++)
    {
        if (arrayOfNumber[i] > arrayOfNumber[i + 1])
        {
            return false;
        }
    }
    return true;
}

// ������� ��� ������������ ���������� QSort
bool testCorrectQSort()
{
    // ������ �� ��������� �����
    int arrayOfNumber[10] = { 9, 7, 8, 6, 3, 1, 7, 0, 3, 2 };
    smartQSort(arrayOfNumber, 0, 9);

    // ������ �� ������ �����
    int arrayOfEqualValues[100] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        arrayOfEqualValues[i] = 12;
    }
    smartQSort(arrayOfEqualValues, 0, 99);

    // ��������������� ������
    int sortedArray[100] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        sortedArray[i] = i;
    }
    smartQSort(sortedArray, 0, 99);

    // ������ �� ������ ��������
    int arrayOfOneElement[1] = { 109 };
    smartQSort(arrayOfEqualValues, 0, 0);

    return sorting�heck(arrayOfNumber, 10)
        && sorting�heck(arrayOfEqualValues, 100)
        && sorting�heck(sortedArray, 100)
        && sorting�heck(arrayOfOneElement, 1);
}
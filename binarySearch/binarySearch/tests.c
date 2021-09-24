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

bool testCorrectBinarySearch()
{
    // test for a random set of numbers
    int arrayofNumber[10] = { 0, 1, 4, 7, 8, 9, 10, 123, 132, 134 };

    // test for overflow
    int arrayOfLargeNumbers[10] = { 2147483630, 2147483631, 2147483632, 2147483633, 2147483634, 2147483635, 2147483636, 2147483637, 2147483638, 2147483639 };

    // testForEmptyArray
    int emptyArray[1] = { 0 };

    // search for a nonexistent element
    int arrayOfRandomNumbers[1000] = { 0 };
    for (int i = 0; i < 1000; i++)
    {
        arrayOfRandomNumbers[i] = rand() % 226;
    }

    return binarySearch(arrayofNumber, 10, 134) == 9
        && binarySearch(arrayOfLargeNumbers, 10, 2147483631) == 1
        && binarySearch(emptyArray, 0, 0) == -1
        && binarySearch(arrayOfRandomNumbers, 1000, 227) == -1;
}
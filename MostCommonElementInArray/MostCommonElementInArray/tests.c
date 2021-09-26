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

bool testSearchMostCommonElement()
{
    // Checking for a random set of numbers
    int arrayOfRandonNumbers[15] = {1, 12, 3, 6, 4, 3, 3, 3, 9, 8, 4, 4, 2, 13, 2};
    smartQSort(arrayOfRandonNumbers, 0, 14);
    
    // checking for an array of a single number
    int arrayOfOneElement[1] = {12};
    
    // checking for an array of equal number
    int arrayOfEqualNumbers[8] = {1, 1, 1, 1, 1, 1, 1, 1};

    // check for an array of different number
    int arrayOfDifferentNumbers[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    return searchMostCommonElementInArray(arrayOfRandonNumbers, 15) == 3
        && searchMostCommonElementInArray(arrayOfOneElement, 1) == 12
        && searchMostCommonElementInArray(arrayOfEqualNumbers, 8) == 1
        && searchMostCommonElementInArray(arrayOfDifferentNumbers, 15) == 1;
}
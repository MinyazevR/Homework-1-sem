#include "testQSort.h"
#include "qsort.h"

// function for checking the sorting of an array
bool sortingCheck(int* arrayOfNumber, int numberOfElements)
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

// function for testing sorting QSort
bool testCorrectQSort()
{
    // Array of random numbers
    int arrayOfNumber[10] = { 9, 7, 8, 6, 3, 1, 7, 0, 3, 2 };
    qSort(arrayOfNumber, 10);

    // Array of equal numbers
    int arrayOfEqualValues[100] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        arrayOfEqualValues[i] = 12;
    }
    qSort(arrayOfEqualValues, 100);

    // Sorted array
    int sortedArray[100] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        sortedArray[i] = i;
    }
    qSort(sortedArray, 100);

    // Array of one element
    int arrayOfOneElement[1] = { 109 };
    qSort(arrayOfEqualValues, 1);

    return sortingCheck(arrayOfNumber, 10)
        && sortingCheck(arrayOfEqualValues, 100)
        && sortingCheck(sortedArray, 100)
        && sortingCheck(arrayOfOneElement, 1);
}
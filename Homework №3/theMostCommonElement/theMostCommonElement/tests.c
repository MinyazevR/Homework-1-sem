#include "test.h"
#include "qsort.h"
#include "theMostCommonElement.h"

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
    QSort(arrayOfNumber, 10);

    // Array of equal numbers
    int arrayOfEqualValues[100] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        arrayOfEqualValues[i] = 12;
    }
    QSort(arrayOfEqualValues, 100);

    // Sorted array
    int sortedArray[100] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        sortedArray[i] = i;
    }
    QSort(sortedArray, 100);

    // Array of one element
    int arrayOfOneElement[1] = { 109 };
    QSort(arrayOfEqualValues, 1);

    return sortingCheck(arrayOfNumber, 10)
        && sortingCheck(arrayOfEqualValues, 100)
        && sortingCheck(sortedArray, 100)
        && sortingCheck(arrayOfOneElement, 1);
}

// test for function searchMostCommonElementInArray
bool testSearchMostCommonElement()
{
    // Checking for a random set of numbers
    int arrayOfRandonNumbers[15] = { 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 6, 8, 9, 12, 13 };

    // checking for an array of a single number
    int arrayOfOneElement[1] = { 12 };

    // checking for an array of equal number
    int arrayOfEqualNumbers[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };

    // check for an array of different number
    int arrayOfDifferentNumbers[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

    return searchMostCommonElementInArray(arrayOfRandonNumbers, 15) == 3
        && searchMostCommonElementInArray(arrayOfOneElement, 1) == 12
        && searchMostCommonElementInArray(arrayOfEqualNumbers, 8) == 1
        && searchMostCommonElementInArray(arrayOfDifferentNumbers, 15) == 1;
}
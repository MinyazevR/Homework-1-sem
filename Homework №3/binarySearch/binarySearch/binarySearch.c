#include "binary.h"
#include <stdlib.h>

// binary search function
int binarySearch(int* arrayOfNumber, int numberOfElements, int requiredNumber)
{
    int leftBorderOfTheArray = 0;
    int rightBorderOfTheArray = numberOfElements - 1;
    while (leftBorderOfTheArray <= rightBorderOfTheArray)
    {
        //this form of recording is needed in order to avoid overflow
        const int middleElementIndex = leftBorderOfTheArray + (rightBorderOfTheArray - leftBorderOfTheArray) / 2;
        if (arrayOfNumber[middleElementIndex] < requiredNumber)
        {
            leftBorderOfTheArray = middleElementIndex + 1;
        }
        if (arrayOfNumber[middleElementIndex] > requiredNumber)
        {
            rightBorderOfTheArray = middleElementIndex - 1;
        }
        if (arrayOfNumber[middleElementIndex] == requiredNumber)
        {
            return middleElementIndex;
        }
    }
    return -1;
}

// check if binary search works
bool testCorrectBinarySearch()
{
    // test for a random set of numbers
    int arrayofNumber[10] = { 0, 1, 4, 7, 8, 9, 10, 123, 132, 134 };

    // test for overflow
    int arrayOfLargeNumbers[10] = { 2147483630, 2147483631, 2147483632, 2147483633, 2147483634, 2147483635, 2147483636, 2147483637, 2147483638, 2147483639 };

    // find the first and last element
    int arrayToFindTheFirstAndLastElement[100] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        arrayToFindTheFirstAndLastElement[i] = i;
    }

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
        && binarySearch(arrayToFindTheFirstAndLastElement, 100, 0) == 0
        && binarySearch(arrayToFindTheFirstAndLastElement, 100, 99) == 99
        && binarySearch(arrayOfRandomNumbers, 1000, 227) == -1;
}
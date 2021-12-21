#include "TestCountSort.h"
#include "CountSort.h"
#include <stdlib.h>

bool sorting—heck(int* arrayOfNumber, int numberOfElements)
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

// Function for testing sorting counting
bool correctCountSort()
{
    // Checking the operation of sorts for a random set of numbers
    int arrayOfNumbersForSorting[100] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        arrayOfNumbersForSorting[i] = rand();
    }
    int* array = countSortArray(arrayOfNumbersForSorting, 100);
    free(array);
    // Checking the operation of sorts for an array consisting of equal numbers
    int arrayOfEqualElements[40] = { 0 };
    for (int i = 0; i < 40; i++)
    {
        arrayOfEqualElements[i] = 144;
    }
    array = countSortArray(arrayOfEqualElements, 40);
    free(array);

    // Checking the operation of sorts for a sorted array
    int sortedArray[56] = { 0 };
    for (int i = 0; i < 56; i++)
    {
        sortedArray[i] = i;
    }
    array = countSortArray(sortedArray, 56);
    free(array);

    // Checking the sorting operation for an array consisting of 1 element
    int arrayOfOneElement[1] = { 138 };
    array = countSortArray(arrayOfOneElement, 1);
    free(array);

    // Checking for an array of 0 elements
    int arrayOfZeroElement[1] = { 138 };
    array = countSortArray(arrayOfOneElement, 0);
    return sorting—heck(arrayOfNumbersForSorting, 100)
        && sorting—heck(arrayOfEqualElements, 40)
        && sorting—heck(sortedArray, 56)
        && sorting—heck(arrayOfOneElement, 1)
        && sorting—heck(arrayOfZeroElement, 0);
}

bool checkTheArrayCounter()
{
    int arrayOfNumbers[10] = {1, 4, 1, 1, 6, 8, 9, 12, 123, 78};
    int* arrayCounter = countSortArray(arrayOfNumbers, 10);
    bool firstCheck = arrayCounter[1 - 1] == 3;
    bool secondCheck = arrayCounter[4 - 1] == 1;
    bool thirdCheck = arrayCounter[6 - 1] == 1;
    bool fourthCheck = arrayCounter[8 - 1] == 1;
    bool fifthCheck = arrayCounter[9 - 1] == 1;
    bool sixthCheck = arrayCounter[12 - 1] == 1;
    bool seventhCheck = arrayCounter[123 - 1] == 1;
    free(arrayCounter);
    return firstCheck && secondCheck && thirdCheck && fourthCheck && fifthCheck && sixthCheck && seventhCheck;
}
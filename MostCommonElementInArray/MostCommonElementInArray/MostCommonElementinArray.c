#include "mostCommonElementInArray.h"
#include <stdlib.h>
#include "qsort.h";

// function to find the most frequent element in an array
int searchMostCommonElementInArray(int* arrayOfNumber, int numberOfElements)
{
    int currentElement = arrayOfNumber[0];
    int counterTheCurrentElement = 1;
    int counterThePreviousElement = 1;
    int savingTheCurrentElement = currentElement;
    for (int i = 1; i < numberOfElements; i++)
    {
        if (arrayOfNumber[i] == currentElement)
        {
            counterTheCurrentElement++;
        }
        else
        {
            if (counterTheCurrentElement > counterThePreviousElement)
            {
                counterThePreviousElement = counterTheCurrentElement;
                savingTheCurrentElement = currentElement;
            }
            currentElement = arrayOfNumber[i];
            counterTheCurrentElement = 1;
        }

    }
    // condition for the last element (if the last element was repeated, then else from the for loop will not work for it)
    if (counterThePreviousElement < counterTheCurrentElement)
    {
        savingTheCurrentElement = currentElement;
    }
    return savingTheCurrentElement;
}

// test for function searchMostCommonElementInArray
bool testSearchMostCommonElement()
{
    // Checking for a random set of numbers
    int arrayOfRandonNumbers[15] = { 1, 12, 3, 6, 4, 3, 3, 3, 9, 8, 4, 4, 2, 13, 2 };
    smartQSort(arrayOfRandonNumbers, 0, 14);

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
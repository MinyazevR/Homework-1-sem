#pragma once
#include "testTheMostCommonElement.h"

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
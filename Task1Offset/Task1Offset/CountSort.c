#include "CountSort.h"
#include <stdlib.h>
#include <malloc.h>

// Function for sorting by counting
int* countSortArray(int* arrayOfNumbers, int numberOfElements)
{
    // Finding the minimum element in the array
    int minimumElementInArray = arrayOfNumbers[0];
    for (int i = 1; i <= numberOfElements - 1; i++)
    {
        if (arrayOfNumbers[i] < minimumElementInArray)
        {
            minimumElementInArray = arrayOfNumbers[i];
        }
    }

    // Finding the maximum element in the array
    int maximumElementInArray = arrayOfNumbers[0];
    for (int i = 1; i <= numberOfElements - 1; i++)
    {
        if (arrayOfNumbers[i] > maximumElementInArray)
        {
            maximumElementInArray = arrayOfNumbers[i];
        }
    }

    // Allocation of dynamic memory for a counter array
    int* arrayOfCount = (int*)calloc((maximumElementInArray - minimumElementInArray + 1), sizeof(int));
    if (arrayOfCount == NULL)
    {
        return NULL;
    }
    // For each element, we increase the counter for its value
    for (int i = 0; i <= numberOfElements - 1; i++)
    {
        arrayOfCount[arrayOfNumbers[i] - minimumElementInArray]++;
    }
    int distributionÑounter = 0;
    // For each i from the minimum value to the maximum, we write its value to the array sequentially arrayOfCount times
    for (int i = minimumElementInArray; i <= maximumElementInArray; i++)
    {
        for (int j = 0; j < arrayOfCount[i - minimumElementInArray]; j++)
        {
            arrayOfNumbers[distributionÑounter] = i;
            distributionÑounter++;
        }
    }
    return arrayOfCount;
}
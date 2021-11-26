#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

// Function for sorting bubble
void bubbleSortArray(int* arrayOfNumbers, int numberOfElements)
{
    for (int i = 0; i < numberOfElements - 1; i++)
    {
        for (int j = numberOfElements - 1; j > i; j--)
        {
            if (arrayOfNumbers[j - 1] > arrayOfNumbers[j])
            {
                const int temporary = arrayOfNumbers[j];
                arrayOfNumbers[j] = arrayOfNumbers[j - 1];
                arrayOfNumbers[j - 1] = temporary;
            }
        }
    }
}

// Function for sorting by counting
int countSortArray(int* arrayOfNumbers, int numberOfElements)
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
        return -1;
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
    free(arrayOfCount);
    return 0;
}

bool sortingÑheck(int* arrayOfNumber, int numberOfElements)
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

// Function for testing bubble sorting
bool correctBubbleSort()
{
    // Checking the operation of sorts for a random set of numbers
    int arrayOfNumbersForSorting[100] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        arrayOfNumbersForSorting[i] = rand();
    }
    bubbleSortArray(arrayOfNumbersForSorting, 100);

    // Checking the operation of sorts for an array consisting of equal numbers
    int arrayOfEqualElements[40] = { 0 };
    for (int i = 0; i < 40; i++)
    {
        arrayOfEqualElements[i] = 144;
    }
    bubbleSortArray(arrayOfEqualElements, 40);

    // Checking the operation of sorts for a sorted array
    int sortedArray[56] = { 0 };
    for (int i = 0; i < 56; i++)
    {
        sortedArray[i] = i;
    }
    bubbleSortArray(sortedArray, 56);

    // Checking the sorting operation for an array consisting of 1 element 
    int arrayOfOneElement[1] = { 138 };
    bubbleSortArray(arrayOfOneElement, 1);

    // Checking for an array of 0 elements
    int arrayOfZeroElement[1] = { 138 };
    bubbleSortArray(arrayOfOneElement, 0);

    return sortingÑheck(arrayOfNumbersForSorting, 100) == 1
        && sortingÑheck(arrayOfEqualElements, 40) == 1
        && sortingÑheck(sortedArray, 56) == 1
        && sortingÑheck(arrayOfOneElement, 1) == 1
        && sortingÑheck(arrayOfZeroElement, 0) == 1;

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
    countSortArray(arrayOfNumbersForSorting, 100);

    // Checking the operation of sorts for an array consisting of equal numbers
    int arrayOfEqualElements[40] = { 0 };
    for (int i = 0; i < 40; i++)
    {
        arrayOfEqualElements[i] = 144;
    }
    countSortArray(arrayOfEqualElements, 40);

    // Checking the operation of sorts for a sorted array
    int sortedArray[56] = { 0 };
    for (int i = 0; i < 56; i++)
    {
        sortedArray[i] = i;
    }
    countSortArray(sortedArray, 56);

    // Checking the sorting operation for an array consisting of 1 element
    int arrayOfOneElement[1] = { 138 };
    countSortArray(arrayOfOneElement, 1);

    // Checking for an array of 0 elements
    int arrayOfZeroElement[1] = { 138 };
    countSortArray(arrayOfOneElement, 0);

    return sortingÑheck(arrayOfNumbersForSorting, 100)
        && sortingÑheck(arrayOfEqualElements, 40)
        && sortingÑheck(sortedArray, 56)
        && sortingÑheck(arrayOfOneElement, 1)
        && sortingÑheck(arrayOfZeroElement, 0);
}

int main()
{
    if (!correctBubbleSort() || !correctCountSort())
    {
        printf("Verification failed");
        return 0;
    }
    int numberOfElements = 0;
    printf("Enter the number of elements in the array\n");
    const int scanfResult = scanf_s("%d", &numberOfElements);
    if (scanfResult == 0 || numberOfElements <= 0)
    {
        printf("Input error");
        return 0;
    }
    int* arrayOfNumbersForSortingCount = (int*)calloc(numberOfElements, sizeof(int));
    if (arrayOfNumbersForSortingCount == NULL)
    {
        return -1;
    }

    for (int i = 0; i < numberOfElements; i++)
    {
        arrayOfNumbersForSortingCount[i] = rand();
    }
    int* arrayOfNumbersForSortingBubble = (int*)calloc(numberOfElements, sizeof(int));
    if (arrayOfNumbersForSortingBubble == NULL)
    {
        return -1;
    }
    for (int i = 0; i < numberOfElements; i++)
    {
        arrayOfNumbersForSortingBubble[i] = arrayOfNumbersForSortingCount[i];
    }
    clock_t initialMomentOfTime = clock();
    countSortArray(arrayOfNumbersForSortingCount, numberOfElements);
    clock_t endPointOfTime = clock();
    printf("The number of time cycles that have elapsed since the call of the function that sorts the array by counting = %d \n\n", endPointOfTime - initialMomentOfTime);
    initialMomentOfTime = clock();
    bubbleSortArray(arrayOfNumbersForSortingBubble, numberOfElements);
    endPointOfTime = clock();
    printf("The number of time cycles that have elapsed since the call of the function that sorts the array with a bubble = %d \n\n", endPointOfTime - initialMomentOfTime);
    free(arrayOfNumbersForSortingCount);
    free(arrayOfNumbersForSortingBubble);
}
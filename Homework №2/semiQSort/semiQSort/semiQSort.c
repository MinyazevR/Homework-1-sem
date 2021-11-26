#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

int semiQSort(int* arrayOfNumber, int numberElementsInArray)
{
    int increment = 1;
    int decrement = numberElementsInArray - 1;

    while (increment < decrement)
    {
        /* the second condition of the loop is not to add increment once again, because the array can already be sorted and in the
        case when there are more elements than the reference less than the elements less than the reference increment will increase to countOfElementsLessFirst + 1 and only
        after that, the cycle will stop, i.e. a lot of extra increments will be made*/
        while (arrayOfNumber[increment] < arrayOfNumber[0] && increment < decrement)
        {
            increment++;
        }
        while (arrayOfNumber[decrement] >= arrayOfNumber[0] && decrement > increment)
        {
            decrement--;
        }
        if (increment < decrement)
        {
            const int temporaryVariable = arrayOfNumber[decrement];
            arrayOfNumber[decrement] = arrayOfNumber[increment];
            arrayOfNumber[increment] = temporaryVariable;
        }
        increment++;
        decrement--;
    }
    return decrement;
}

bool sortingÑheck(int* arrayOfNumber, int numberOfElements, int index)
{
    for (int i = 1; i < index + 1; i++)
    {
        if (arrayOfNumber[i] >= arrayOfNumber[0])
        {
            return false;
        }
    }
    for (int i = index + 1; i < numberOfElements; i++)
    {
        if (arrayOfNumber[i] < arrayOfNumber[0])
        {
            return false;
        }
    }
    return true;
}

bool correctSemiQSort()
{
    // Checking the operation of sorting for a random set of numbers
    int arrayOfNumber[8] = {4, 7, 2, 5, 4, 8, 1, 3};

    // Checking the sorting operation for an array consisting of equal elements
    int arrayOfEqualValues[100] = {0};
    for (int i = 0; i < 100; i++)
    {
        arrayOfEqualValues[i] = 5;
    }
    
    // Checking the sorting operation for a sorted array
    int sortedArray[100] = {0};
    for (int i = 0; i < 100; i++)
    {
        sortedArray[i] = i;
    }

    // Checking the sorting operation for an array consisting of a single element
    int arrayOfOneElement[1] = {15};
    
    int arrayOfZeroElement[1] = {0};

    return sortingÑheck(arrayOfNumber, 8, semiQSort(arrayOfNumber, 8))
        && sortingÑheck(arrayOfEqualValues, 100, semiQSort(arrayOfEqualValues, 100))
        && sortingÑheck(sortedArray, 100, semiQSort(sortedArray, 100))
        && sortingÑheck(arrayOfOneElement, 1, semiQSort(arrayOfOneElement, 1))
        && sortingÑheck(arrayOfZeroElement, 0, semiQSort(arrayOfZeroElement, 0));
}

int main()
{
    if (!correctSemiQSort())
    {
        printf("Verification failed");
        return 0;
    }
    printf("Enter the number of elements in the array\n");
    int numberElementsInArray = 0;
    const int scanfNumberElemntInArrayResult = scanf_s("%d", &numberElementsInArray);
    if (scanfNumberElemntInArrayResult == 0 || numberElementsInArray <= 0)
    {
        printf("Input error");
        return 0;
    }
    int* arrayOfNumber = (int*)calloc(numberElementsInArray, sizeof(int));
    if (arrayOfNumber == NULL)
    {
        return -1;
    }
    for (int i = 0; i < numberElementsInArray; i++)
    {
        // to visually verify that it works correctly, you can add rand () % n, because the first number may be the minimum
        arrayOfNumber[i] = rand();
        printf("     %d", arrayOfNumber[i]);
    }
    printf("\n\n");
    semiQSort(arrayOfNumber, numberElementsInArray);
    for (int i = 0; i < numberElementsInArray; i++)
    {
        printf("     %d", arrayOfNumber[i]);
    }
    free(arrayOfNumber);
}
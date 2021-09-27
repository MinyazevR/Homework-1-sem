#include "Header.h"

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

int main()
{
    if (!testCorrectBinarySearch() || !testCorrectQSort())
    {
        printf("error");
        return 0;
    }
    int numberOfElements = 0;
    printf("Enter the number of elements in the array\n");
    scanf_s("%d", &numberOfElements);
    int* arrayOfNumber = (int*)calloc(numberOfElements, sizeof(int));
    if (arrayOfNumber == NULL)
    {
        return -1;
    }
    for (int i = 0; i < numberOfElements; i++)
    {
        arrayOfNumber[i] = rand();
    }
    smartQSort(arrayOfNumber, 0, numberOfElements - 1);
    printf("Enter the number of numbers that you need to enter to search in the array\n");
    int numberOfRequiredNumbers = 0;
    scanf_s("%d", &numberOfRequiredNumbers);
    printf("if (- 1) : then the number is not in the array\n");
    for (int i = 0; i < numberOfRequiredNumbers; i++)
    {
        const int temporary = rand();
        printf("the number %d : % d array number\n", temporary, binarySearch(arrayOfNumber, numberOfElements, temporary));
    }
    free(arrayOfNumber);
}
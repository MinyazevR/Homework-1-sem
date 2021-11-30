#include <stdio.h>
#include <stdlib.h>
#include "binary.h"
#include "qsort.h"

int main(int argc, char* argv[])
{
    if (!testCorrectBinarySearch() || !testCorrectQSort())
    {
        printf("error");
        return -1;
    }
    if (argc != 0)
    {
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
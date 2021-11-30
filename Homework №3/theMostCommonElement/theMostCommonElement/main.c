#include <stdio.h>
#include <stdlib.h>
#include "theMostCommonElement.h"
#include "qsort.h"
#include "test.h"

int main(int argc, char* argv[])
{
    if (!testCorrectQSort() || !testSearchMostCommonElement())
    {
        printf("test failed");
        return -1;
    }
    if (argc != 0)
    {
        return 0;
    }
    int numberOfElements = 0;
    printf("enter the number of elements in the array\n");
    scanf_s("%d", &numberOfElements);
    int* arrayOfNumber = (int*)calloc(numberOfElements, sizeof(int));
    if (arrayOfNumber == NULL)
    {
        return -1;
    }
    for (int i = 0; i < numberOfElements; i++)
    {
        arrayOfNumber[i] = rand() % 11;
    }
    QSort(arrayOfNumber, numberOfElements);
    printf("the most common element in the array : %d\n", searchMostCommonElementInArray(arrayOfNumber, numberOfElements));
}
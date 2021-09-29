#include <stdio.h>
#include <stdlib.h>
#include "MostCommonElementInArray.h"
#include "qsort.h"

int main()
{
    if (!testCorrectQSort() || !testSearchMostCommonElement());
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
        arrayOfNumber[i] = rand();
    }
    smartQSort(arrayOfNumber, 0, numberOfElements - 1);
    printf("the most common element in the array : %d\n", searchMostCommonElementInArray(arrayOfNumber, numberOfElements));
}
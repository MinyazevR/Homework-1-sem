#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CountSort.h"
#include "TestCountSort.h"

int main()
{
    if (!checkTheArrayCounter() || !correctCountSort())
    {
        printf("Test failed");
        return -1;
    }
    int temporary = 1;
    int counter = 0;
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    int array[1000] = { 0 };
    while (temporary != 0)
    {
        printf("enter the %d number\n", counter);
        scanf_s("%d\n", &temporary);
        array[counter] = temporary;
        if (array[counter] < minimum)
        {
            minimum = array[counter];
        }
        if (array[counter] > maximum)
        {
            maximum = array[counter];
        }
        counter++;
    }
    int* count = countSortArray(array, 10);
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        if (i >= 1 && array[i] == array[i - 1])
        {
            continue;
        }
        printf("%d - %d\n", array[i], count[array[i] - minimum]);
    }
    
}
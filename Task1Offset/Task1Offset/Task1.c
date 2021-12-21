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
        scanf_s("%d", &temporary);
        printf("\n");
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
    int* count = countSortArray(array, counter);
    printf("\n");
    printf("element - quanity\n");
    for (int i = 0; i < counter; i++)
    {
        if (i >= 1 && array[i] == array[i - 1])
        {
            continue;
        }
        printf("%d - %d\n", array[i], count[array[i] - minimum]);
    }
    
}
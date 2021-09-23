#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

void smartQSort(int* arrayOfNumber, int initialElement, int endElement)
{
    int increment = initialElement;
    int decrement = endElement;
    int supportElement = 0;
    if (arrayOfNumber[increment] <= arrayOfNumber[increment + 1])
    {
        supportElement = arrayOfNumber[increment + 1];
    }
    else if (arrayOfNumber[increment] > arrayOfNumber[increment + 1])
    {
        supportElement = arrayOfNumber[increment];
    }
    if (endElement - initialElement + 1 >= 10)
    {
        while (increment < decrement)
        {
            while (arrayOfNumber[increment] < supportElement && increment <= decrement)
            {
                increment++;
            }
            while (arrayOfNumber[decrement] > supportElement && decrement >= increment)
            {
                decrement--;
            }
            if (increment <= decrement)
            {
                int temporaryVariable = arrayOfNumber[decrement];
                arrayOfNumber[decrement] = arrayOfNumber[increment];
                arrayOfNumber[increment] = temporaryVariable;
                increment++;
                decrement--;
            }
        }
        if (initialElement < decrement)
        {
            smartQSort(arrayOfNumber, initialElement, decrement);
        }
        if (increment < endElement)
        {
            smartQSort(arrayOfNumber, increment, endElement);
        }
    }
    else
    {
        for (int i = initialElement; i <= decrement; i++)
        {
            int elementToTheLeftOfKey = i - 1;
            const int keyArray = arrayOfNumber[i];
            while (arrayOfNumber[elementToTheLeftOfKey] > keyArray && elementToTheLeftOfKey >= 0)
            {
                arrayOfNumber[elementToTheLeftOfKey + 1] = arrayOfNumber[elementToTheLeftOfKey];
                elementToTheLeftOfKey--;
                arrayOfNumber[elementToTheLeftOfKey + 1] = keyArray;
            }
        }
        for (int i = increment; i <= endElement; i++)
        {
            int elementToTheLeftOfKey = i - 1;
            const int keyArray = arrayOfNumber[i];
            while (arrayOfNumber[elementToTheLeftOfKey] > keyArray && elementToTheLeftOfKey >= 0)
            {
                arrayOfNumber[elementToTheLeftOfKey + 1] = arrayOfNumber[elementToTheLeftOfKey];
                elementToTheLeftOfKey--;
                arrayOfNumber[elementToTheLeftOfKey + 1] = keyArray;
            }
        }
    }
}


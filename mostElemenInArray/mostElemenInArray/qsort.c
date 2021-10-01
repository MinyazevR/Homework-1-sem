#include "qsort.h"

// function for sorting by inserts
void sortByInserts(int* arrayOfNumber, int initialElement, int endElement)
{
    for (int i = initialElement + 1; i <= endElement; i++)
    {
        int elementToTheLeftOfKey = i - 1;
        const int keyArray = arrayOfNumber[i];
        while (arrayOfNumber[elementToTheLeftOfKey] > keyArray && elementToTheLeftOfKey >= initialElement)
        {
            arrayOfNumber[elementToTheLeftOfKey + 1] = arrayOfNumber[elementToTheLeftOfKey];
            elementToTheLeftOfKey--;
        }
        arrayOfNumber[elementToTheLeftOfKey + 1] = keyArray;
    }
}

// function for sorting an array
int smartQSort(int* arrayOfNumber, int initialElement, int endElement)
{
    if (endElement - initialElement + 1 < 10)
    {
        sortByInserts(arrayOfNumber, initialElement, endElement);
        return 0;
    }
    int leftBorderOfSegment = initialElement;
    int rightBorderOfSegment = endElement;
    int supportElement = 0;
    if (arrayOfNumber[leftBorderOfSegment] <= arrayOfNumber[leftBorderOfSegment + 1])
    {
        supportElement = arrayOfNumber[leftBorderOfSegment + 1];
    }
    else
    {
        supportElement = arrayOfNumber[leftBorderOfSegment];
    }
    while (leftBorderOfSegment < rightBorderOfSegment)
    {
        while (arrayOfNumber[leftBorderOfSegment] < supportElement && leftBorderOfSegment <= rightBorderOfSegment)
        {
            leftBorderOfSegment++;
        }
        while (arrayOfNumber[rightBorderOfSegment] > supportElement && rightBorderOfSegment >= leftBorderOfSegment)
        {
            rightBorderOfSegment--;
        }
        if (leftBorderOfSegment < rightBorderOfSegment)
        {
            const int temporaryVariable = arrayOfNumber[rightBorderOfSegment];
            arrayOfNumber[rightBorderOfSegment] = arrayOfNumber[leftBorderOfSegment];
            arrayOfNumber[leftBorderOfSegment] = temporaryVariable;
            leftBorderOfSegment++;
            rightBorderOfSegment--;
        }
    }
    smartQSort(arrayOfNumber, initialElement, rightBorderOfSegment);
    smartQSort(arrayOfNumber, leftBorderOfSegment, endElement);
    return 0;
}

void QSort(int* arrayOfNumber, int numberOfElement)
{
    smartQSort(arrayOfNumber, 0, numberOfElement - 1);
}
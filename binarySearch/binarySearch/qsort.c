#include "Header.h"
void smartQSort(int* arrayOfNumber, int initialElement, int endElement)
{
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
    if (endElement - initialElement + 1 >= 10)
    {
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
    }
    else
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
}
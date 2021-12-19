#include "choiseSort.h"

void sortChoise(int* arrayOfNumber, int numberOfElement)
{
    for (int i = 0; i < numberOfElement - 1; i++)
    {
        int count = 0;
        int temporary = arrayOfNumber[i];
        for (int j = i + 1; j <= numberOfElement - 1; j++)
        {
            if (arrayOfNumber[j] < temporary)
            {
                temporary = arrayOfNumber[j];
                count = j;
            }
        }
        if (temporary != arrayOfNumber[i])
        {
            arrayOfNumber[count] = arrayOfNumber[i];
            arrayOfNumber[i] = temporary;
        }
    }
}
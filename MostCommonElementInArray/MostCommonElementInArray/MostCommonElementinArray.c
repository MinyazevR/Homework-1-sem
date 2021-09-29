#include "mostCommonElementInArray.h"

// function to find the most frequent element in an array
int searchMostCommonElementInArray(int* arrayOfNumber, int numberOfElements)
{
    int currentElement = arrayOfNumber[0];
    int counterTheCurrentElement = 1;
    int counterThePreviousElement = 1;
    int savingTheCurrentElement = currentElement;
    for (int i = 1; i < numberOfElements; i++)
    {
        if (arrayOfNumber[i] == currentElement)
        {
            counterTheCurrentElement++;
        }
        else
        {
            if (counterTheCurrentElement > counterThePreviousElement)
            {
                counterThePreviousElement = counterTheCurrentElement;
                savingTheCurrentElement = currentElement;
            }
            currentElement = arrayOfNumber[i];
            counterTheCurrentElement = 1;
        }
    }
    // condition for the last element (if the last element was repeated, then else from the for loop will not work for it)
    if (counterThePreviousElement < counterTheCurrentElement)
    {
        savingTheCurrentElement = currentElement;
    }
    return savingTheCurrentElement;
}
#include "Header.h"

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
    if (counterThePreviousElement < counterTheCurrentElement)
    {
        savingTheCurrentElement = currentElement;
    }
    return savingTheCurrentElement;
}

int main()
{
    if(!testCorrectQSort() || !testSearchMostCommonElement());
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
    printf("%d", searchMostCommonElementInArray(arrayOfNumber, numberOfElements));
}
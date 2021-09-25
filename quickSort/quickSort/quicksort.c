#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

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
        while(leftBorderOfSegment < rightBorderOfSegment)
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

// Функция для проверки отсортированности массива
bool sortingСheck(int* arrayOfNumber, int numberOfElements)
{
    for (int i = 0; i < numberOfElements - 1; i++)
    {
        if (arrayOfNumber[i] > arrayOfNumber[i + 1])
        {
            return false;
        }
    }
    return true;
}

// Функция для тестирования сортировки QSort
bool testCorrectQSort()
{
    // Массив из случайных чисел
    int arrayOfNumber[10] = { 9, 7, 8, 6, 3, 1, 7, 0, 3, 2 };
    smartQSort(arrayOfNumber, 0, 9);

    // Массив из равных чисел
    int arrayOfEqualValues[100] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        arrayOfEqualValues[i] = 12;
    }
    smartQSort(arrayOfEqualValues, 0, 99);

    // Отсортированный массив
    int sortedArray[100] = { 0 };
    for (int i = 0; i < 100; i++)
    {
        sortedArray[i] = i;
    }
    smartQSort(sortedArray, 0, 99);

    // Массив из одного элемента
    int arrayOfOneElement[1] = { 109 };
    smartQSort(arrayOfEqualValues, 0, 0);

    return sortingСheck(arrayOfNumber, 10)
        && sortingСheck(arrayOfEqualValues, 100)
        && sortingСheck(sortedArray, 100)
        && sortingСheck(arrayOfOneElement, 1);
}

int main()
{
    if (!testCorrectQSort())
    {
        printf(" error");
        return 0;
    }
    int numberOfElements = 0;
    printf("Enter the number of elements in the array\n");
    scanf_s("%d", &numberOfElements);
    int* arrayOfNumber = (int*)calloc(numberOfElements, sizeof(int));
    if (arrayOfNumber == NULL)
    {
        return -1;
    }
    for (int i = 0; i < numberOfElements; i++)
    {
        arrayOfNumber[i] = rand() % 14;
    }
    smartQSort(arrayOfNumber, 0, numberOfElements - 1);
    for (int i = 0; i < numberOfElements; i++)
    {
        printf("  %d", arrayOfNumber[i]);
    }
    free(arrayOfNumber);
}
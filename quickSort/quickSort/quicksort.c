#include <stdio.h>
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
                const int temporaryVariable = arrayOfNumber[decrement];
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
testCorrectQSort()
{
    // Массив из случайных чисел
    int arrayOfNumber[10] = {9, 7, 8, 6, 3, 1, 7, 0, 3, 2};
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

    return sortingСheck(arrayOfNumber, 10) == true
        && sortingСheck(arrayOfEqualValues, 100) == true
        && sortingСheck(sortedArray, 100) == true
        && sortingСheck(arrayOfOneElement, 1) == true;
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
        arrayOfNumber[i] = rand();
    }
    smartQSort(arrayOfNumber, 0, numberOfElements - 1);
    free(arrayOfNumber);
}

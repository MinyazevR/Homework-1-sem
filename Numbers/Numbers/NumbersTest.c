#include "NumbersTest.h"
#include "Numbers.h"
#include <stdio.h>
#include <malloc.h>

bool checkTheReadNumbers(int* data, int* arrayOfCorrectNumbers, int counter)
{
    for (int i = 0; i < counter; i++)
    {
        if (data[i] != arrayOfCorrectNumbers[i])
        {
            return false;
        }
    }
    return true;
}

bool checkTheOutputOfNumbersToFile(int counter, int secondCounter, int* data, int* arrayOfNumbers)
{
    return checkTheReadNumbers(data, arrayOfNumbers, counter) && counter == secondCounter;
}

bool numbersTest()
{
    FILE* file = fopen("g.txt", "r");
    if (file == NULL)
    {
        printf("File not found");
        return false;
    }
    int number = 0;
    int numberToCompare = 0;
    while (!feof(file))
    {
        const int readBytes = fscanf(file, "%d", &number);
        if (readBytes < 0) {
            break;
        }
        numberToCompare = number;
    }
    fclose(file);
    int data[100] = { 0 };
    int arrayOfÑorrectNumbers[12] = { 5, 12, 12, 12, 3, 4, 5, 6, 7, 7, 12, 13 };
    int counter = readNumbersSmallerSelected(data, numberToCompare, "f.txt");
    int arrayOfNumbers[100] = {0};
    file = fopen("h.txt", "r");
    if (file == NULL)
    {
        return false;
    }
    int secondCounter = 0;
    while (!feof(file))
    {
        int* buffer = (int*)malloc(sizeof(int) * 100);
        {
            if (buffer == NULL)
            {
                return false;
            }
        }
        const int readBytes = fscanf(file, "%d", buffer);
        if (readBytes < 0)
        {
            break;
        }
        arrayOfNumbers[secondCounter] = *buffer;
        secondCounter++;
    }
    fclose(file);
    return checkTheReadNumbers(data, arrayOfÑorrectNumbers, counter)
        && checkTheOutputOfNumbersToFile(counter, secondCounter, data, arrayOfNumbers);
}
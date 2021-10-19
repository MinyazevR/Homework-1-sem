#include "Numbers.h"
#include "NumbersTest.h"
#include <stdio.h>

int main()
{
    if (!numbersTest())
    {
        printf("Test failed");
        return -1;
    }
    FILE* file = fopen("g.txt", "r");
    if (file == NULL)
    {
        printf("File not found");
        return 0;
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
    int counter = readNumbersSmallerSelected(data, numberToCompare, "f.txt");
    if (counter == -2)
    {
        printf("file f.txt not found");
        return 0;    
    }
    if (counter == -1)
    {
        printf("memory allocation error");
        return 0;
    }
    int result = outputOfNumbers(data, counter, "h.txt");
    if (result == -2)
    {
        printf("failed to create a file");
    }
    printf("the numbers are written to the file in order h.txt");
}
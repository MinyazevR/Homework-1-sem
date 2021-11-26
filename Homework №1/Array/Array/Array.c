#include <stdio.h>

int main()
{
    int arrayOfNumbers[100] = {0};
    int numberZeroValues = 0;
    for (int i = 0; i < 100; i++)
    {
        // we assign random values from 0 to 9 to the elements of the array
        arrayOfNumbers[i] = rand() % 10;
        // if the value of an array element is 0, we increase the counter of zero elements by 1
        if (arrayOfNumbers[i] == 0)
        {
            numberZeroValues++;
        }
    }
    printf("The number of zero elements in the array = %d", numberZeroValues);
}
#include <stdio.h>
#include <malloc.h>

// A function for inverting array values that depends on the number of the first element in the segment and the number of elements in the array
void flipNumbersArray(int firstElement, int numberOfElements, int* arrayOfNumbers)
{
    for (int i = firstElement; i < numberOfElements / 2; i++)
    {   
        const int temporary = arrayOfNumbers[i];
        arrayOfNumbers[i] = arrayOfNumbers[numberOfElements - 1 - i];
        arrayOfNumbers[numberOfElements - 1 - i] = temporary;
    }
}

void printNumbersArray(int numberOfElements, int* arrayOfNumbers)
{
    for (int i = 0; i < numberOfElements; i++)
    {
        printf("    %d", arrayOfNumbers[i]);
    }
}

int main()
{
    int numberOfElements = 0;
    printf("Enter the number of elements in the array\n");
    scanf_s("%d", &numberOfElements);
    // allocation of dynamic memory for entering the number of elements in the array from the keyboard
    int* arrayOfNumbers = (int*)malloc(numberOfElements * sizeof(int));
    printf("The segment of what length do you want to move to the end?\n");
    int m = 0;
    scanf_s("%d", &m);
   
    for (int i = 0; i < numberOfElements; i++)
    {
        arrayOfNumbers[i] = rand() % 10;
    }

    printNumbersArray(numberOfElements, arrayOfNumbers);
    flipNumbersArray(0, m, arrayOfNumbers);
    flipNumbersArray(m, numberOfElements + m, arrayOfNumbers);
    flipNumbersArray(0, numberOfElements , arrayOfNumbers);
    printf("\n\n\n");
    printNumbersArray(numberOfElements, arrayOfNumbers);
    free(arrayOfNumbers);
}

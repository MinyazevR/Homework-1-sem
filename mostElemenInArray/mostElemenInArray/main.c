#include <malloc.h>
#include "testQSort.h"
#include "testTheMostCommonElement.h"
#include "theMostCommonElement.h"
#include "qsort.h"
#include <stdio.h>

int main()
{
    if (!testCorrectQSort() || !testSearchMostCommonElement())
    {
        printf("test failed");
        return -1;
    }
    FILE* file = NULL;
    errno_t err = fopen_s(&file, "number.txt", "r");
    if (file == NULL || err != 0)
    {
        printf("file not found!");
        return -1;
    }
    int counter = 0;
    int variable = 0;
    while (!feof(file))
    {
        fscanf_s(file, "%d", &variable);
        counter++;
    }
    fclose(file);
    err = fopen_s(&file, "number.txt", "r");
    if (file == NULL || err != 0)
    {
        printf("file not found!");
        return -1;
    }
    int* arrayOfNumber = (int*)calloc(counter, sizeof(int));
    if (arrayOfNumber == NULL)
    {
        printf("memory is not allocated");
        // Can be used return as we are in main()
        fclose(file);
        return -1;
    }
    int readNumber = 0;
    while (fscanf_s(file, "%d", &arrayOfNumber[readNumber]) > 0)
    {
        readNumber++;
    }
    fclose(file);
    qSort(arrayOfNumber, counter);
    for (int i = 0; i < counter; i++)
    {
        printf("%d ", arrayOfNumber[i]);
    }
    printf("\n");
    printf("most common element in an array : %d\n", searchMostCommonElementInArray(arrayOfNumber, counter));
    free(arrayOfNumber);
}
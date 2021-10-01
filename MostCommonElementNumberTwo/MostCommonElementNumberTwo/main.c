#include "dataInput.h"
#include "dataOutput.h"
#include <malloc.h>
#include "qsort.h"
#include "qsortTest.h"
#include "testTheMostCommonElement.h"
#include "theMostCommonElement.h"

int main()
{
    if (!testCorrectQSort() || !testSearchMostCommonElement())
    {
        printf("test failed");
        return -1;
    }
    FILE* file = 0;

    /*in a dataInput function that writes random elements to a text file,
    a random number of elements will be selected (so as not to set an array in advance and not
    send the number of elements to the dataInput function)*/
    const int numberOfElements = dataInput(file);
    int* arrayOfNumber = (int*)calloc(numberOfElements, sizeof(int));
    if (arrayOfNumber == NULL)
    {
        return -1;
    }
    dataOutput(file, arrayOfNumber);
    QSort(arrayOfNumber, numberOfElements);
    printf("most common element in an array : %d", searchMostCommonElementInArray(arrayOfNumber, numberOfElements));
    free(arrayOfNumber);
}
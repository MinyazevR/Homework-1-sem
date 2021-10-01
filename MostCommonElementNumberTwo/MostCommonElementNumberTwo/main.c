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
    int* arrayOfNumber = (int*)calloc(150000, sizeof(int));
    if (arrayOfNumber == NULL)
    {
        return -1;
    }
    FILE* file = 0;
    dataInput(file);
    dataOutput(file, arrayOfNumber);
    QSort(arrayOfNumber, 150000);
    printf("%d", searchMostCommonElementInArray(arrayOfNumber, 150000));

}
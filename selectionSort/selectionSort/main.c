#include <stdio.h>
#include <locale.h>
#include "choiseSort.h"
#include "test.h"

int main()
{
    setlocale(LC_ALL, "rus");
    if (!testSort—hoice())
    {
        return -1;
    }
    setlocale(LC_ALL, "rus");
    int arrayOfNumber[10] = { 0 };
    for (int i = 0; i < 10; i++)
    {
        printf("‚‚Â‰ËÚÂ ˝ÎÂÏÂÌÚ Ò ÌÓÏÂÓÏ %d\n", i);
        scanf_s("%d", &arrayOfNumber[i]);
    }
    sortChoise(arrayOfNumber, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arrayOfNumber[i]);
    }
}
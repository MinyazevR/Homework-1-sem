#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

int semiQSort(int* arrayOfNumber, int numberElementsInArray)
{
    int increment = 1;
    int decrement = numberElementsInArray - 1;

    while (increment < decrement)
    {
        /* второе условие цикла для того, что лишний раз не прибавлять increment, ведь массив уже может быть отсортирован и в
        случае когда элементов больше опорного меньше чем элементов меньше опорного increment будет увеличиваться до countOfElementsLessFirst + 1 и только
        после этого цикл остановится, т.е будет сделано много лишних инкрементов increment*/
        while (arrayOfNumber[increment] < arrayOfNumber[0] && increment < decrement)
        {
            increment++;
        }
        while (arrayOfNumber[decrement] >= arrayOfNumber[0] && decrement > increment)
        {
            decrement--;
        }
        if (increment <= decrement)
        {
            const int temporaryVariable = arrayOfNumber[decrement];
            arrayOfNumber[decrement] = arrayOfNumber[increment];
            arrayOfNumber[increment] = temporaryVariable;
        }
        increment++;
        decrement--;
    }
    return decrement;
}

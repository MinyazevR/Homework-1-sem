#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

bool test()
{
    int arrayOFNumber[10] = {199, 36, 123, 1, 2, 6, 8, 9, 7, 10};
    int sum[10] = {0};
    return largestSun(arrayOFNumber, sum, 10) == 0;
    
}

int largestSun(int *array,int* sum,int numberOfElements)
{
    for (int i = 0; i < numberOfElements; i++)
    {
        while (array[i] > 0)
        {
            sum[i] += array[i] % 10;
            array[i] /= 10;
        }
    }
    int temporary = sum[0];
    int j = 0;
    for (int i = 1; i < numberOfElements; i++)
    {
        if (sum[i] > temporary)
        {
            temporary = sum[i];
            j = i;
        }
    }
    return j;
}
int main()
{
    setlocale(LC_ALL, "rus");
    if (!test())
    {
        return -1;
    }
    setlocale(LC_ALL, "rus");
    int numberOfElements = 0;
    printf("Введите количество элементов");
    scanf_s("%d", &numberOfElements);
    int* array = calloc(numberOfElements, sizeof(int));
    if (array == 0)
    {
        return -1;
    }
    int* sum = calloc(numberOfElements, sizeof(int));
    if (sum == 0)
    {
        return -1;
    }
    for (int i = 0; i < numberOfElements; i++)
    {
        array[i] = rand();
    }
    int k = largestSun(array,sum, numberOfElements);
    printf("число %d сумма цифр%d", k, array[k]);
    free(array);
    free(sum);
}
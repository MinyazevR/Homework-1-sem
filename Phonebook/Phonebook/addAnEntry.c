#include <stdio.h>
#include "addAnEntry.h"

int addAnEntry(Phonebook* array, int numberOfRecords)
{
    if (numberOfRecords > 100)
    {
        return -1;
    }
    printf("Введите имя\n");
    const int firstResultScanf = scanf("%s[^\n]", &array[numberOfRecords].name);
    if (firstResultScanf == 0)
    {
        printf("ошибка ввода\n");
        return -1;
    }
    printf("Введите номер\n");
    int number = 0;
    const int secondResultScanf = scanf("%s[^\n]", &array[numberOfRecords].number);
    if (secondResultScanf == 0)
    {
        printf("ошибка ввода\n");
        return -1;
    }
    printf("Запись добавлена\n");
    return 1;
}

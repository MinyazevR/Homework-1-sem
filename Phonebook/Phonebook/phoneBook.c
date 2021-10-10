#include "phoneBook.h"
#include <stdio.h>
#include <string.h>

int recordsCounter(Phonebook* array, const char *fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return -1;
    }
    int numberOfRecords = 0;
    while (!feof(file))
    {
        if (fscanf(file, "%s", array[numberOfRecords].name) != EOF);
        {
            const int fscanfResult = fscanf(file, "%s", &array[numberOfRecords].number);
            if (fscanfResult == 0)
            {
                break;
            }
            numberOfRecords++;
        }
    }
    fclose(file);
    return numberOfRecords - 1;
}

int addAnEntry(Phonebook* array, int* numberOfRecords)
{
    if (*numberOfRecords >= 100)
    {
        return -1;
    }
    (*numberOfRecords)++;
    printf("Введите имя\n");
    const int firstResultScanf = scanf("%s[^\n]", &array[*numberOfRecords].name);
    if (firstResultScanf == 0)
    {
        printf("ошибка ввода\n");
        return -1;
    }
    printf("Введите номер\n");
    int number = 0;
    const int secondResultScanf = scanf("%s[^\n]", &array[*numberOfRecords].number);
    if (secondResultScanf == 0)
    {
        printf("ошибка ввода\n");
        return -1;
    }
    printf("Запись добавлена\n");
    return 1;
}

char* findNameByNumber(Phonebook* array, char* number, int numberOfRecords)
{
    for (int i = 0; i < numberOfRecords; i++)
    {
        if (strcmp(array[i].number, number) == 0)
        {
            return array[i].name;
        }
    }
    printf("Такого номера нет");
    return NULL;
}

int saveTheChanges(Phonebook* array, int numberOfRecords)
{
    FILE* file = fopen("phoneNumber.txt", "w");
    if (file == NULL)
    {
        return -1;
    }
    for (int i = 0; i <= numberOfRecords; i++)
    {
        if (i > 0)
        {
            fprintf(file, "\n");
        }
        fprintf(file, "%s %s", array[i].name, array[i].number);
    }
    fclose(file);
    return 0;
}

char* findNumberByName(Phonebook* array, char* name, int numberOfRecords)
{
    for (int i = 0; i < numberOfRecords; i++)
    {
        if (strcmp(array[i].name, name) == 0)
        {
            return array[i].number;
        }
    }
    printf("Такого имени нет");
    return NULL;
}

void outputAllEntries(Phonebook* array, int numberOfRecords)
{
    for (int i = 0; i <= numberOfRecords; i++)
    {
        printf("%s %s\n", array[i].name, array[i].number);
    }
}

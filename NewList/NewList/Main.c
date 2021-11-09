#include "List.h"
#include "MergeSort.h"
#include "TestList.h"
#include "TestMergeSort.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>

void readPhonebook(List* list, const char* fileName, int* error)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        *error = 1;
        return;
    }
    while (!feof(file))
    {
        char arrayForName[100] = {'\0'};
        char arrayForNumber[100] = {'\0'};
        if (fscanf(file, "%s", arrayForName) != EOF);
        {
            const int fscanfResult = fscanf(file, "%s", arrayForNumber);
            if (fscanfResult == 0)
            {
                break;
            }
        }
        add(list, arrayForName, arrayForNumber, error);
        if (*error == 3)
        {
            fclose(file);
            return;
        }
    }
    fclose(file);
}

int main()
{
    if (!allTest() || !testMergeSort())
    {
        printf("Тест провален");
        return -1;
    }
    List* newList = createList();
    int error = 0;
    readPhonebook(newList, "Phonebook.txt", &error);
    printf("Вы хотите отсортировать по имени или номеру?\n");
    printf("Нажмите 1 если по имени, другую цифру если по номеру\n");
    int number = 0;
    const int scanResult = scanf("%d", &number);
    if (scanResult == 0)
    {
        printf("Не получилось прочитать число");
        return -1;
    }
    List* answer = mergeSort(newList, number, &error);
    if (error == 1)
    {
        deleteList(answer);
        printf("Файл не найден");
        return -1;
    }
    if (error == 2)
    {
        deleteList(answer);
        printf("Ошибка в работе программы");
        return -1;
    }
    if (error == 3)
    {
        deleteList(answer);
        printf("Недостаточно памяти");
        return -1;
    }
    print(answer);
    printf("\n");
    deleteList(answer);
}
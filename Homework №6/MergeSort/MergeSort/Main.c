#include "MergeSort.h"
#include "TestMergeSort.h"
#include <stdio.h>
#include <locale.h>

int readPhonebook(List* list, const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return -1;
    }
    while (!feof(file))
    {
        // names and numbers in the file are less than 100 characters in size
        char arrayForName[100] = { '\0' };
        char arrayForNumber[100] = { '\0' };
        if (fscanf(file, "%s", arrayForName) != EOF);
        {
            const int fscanfResult = fscanf(file, "%s", arrayForNumber);
            if (fscanfResult == 0)
            {
                break;
            }
        }
        Error error = NOT_ERROR;
        add(list, arrayForName, arrayForNumber, &error);
        if (error == INSUFFICIENT_MEMORY)
        {
            fclose(file);
            return -2;
        }
    }
    fclose(file);
    return 0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    if (!testMergeSort())
    {
        printf("Тест провален");
        return -1;
    }
    List* newList = createList();
    const int readPhonebookresult = readPhonebook(newList, "Phonebook.txt");
    if (readPhonebookresult == -1)
    {
        deleteList(newList);
        printf("Файл не найден");
        return -1;
    }
    if (readPhonebookresult == -2)
    {
        deleteList(newList);
        printf("Недостаточно памяти");
        return -1;
    }
    printf("Вы хотите отсортировать по имени или номеру?\n");
    printf("Нажмите 1 если по имени, другую цифру если по номеру\n");
    int number = 0;
    const int scanfResult = scanf("%d", &number);
    if (scanfResult == 0)
    {
        printf("Не получилось прочитать число");
        return -1;
    }
    Error error = NOT_ERROR;
    List* answer = mergeSort(newList, number, &error);
    const char* checkError = decodingError(error);
    if (checkError != NULL)
    {
        printf("%s", checkError);
    }
    print(answer);
    printf("\n");
    deleteList(answer);
}
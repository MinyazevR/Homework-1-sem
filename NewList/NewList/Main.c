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
        printf("���� ��������");
        return -1;
    }
    List* newList = createList();
    int error = 0;
    readPhonebook(newList, "Phonebook.txt", &error);
    printf("�� ������ ������������� �� ����� ��� ������?\n");
    printf("������� 1 ���� �� �����, ������ ����� ���� �� ������\n");
    int number = 0;
    const int scanResult = scanf("%d", &number);
    if (scanResult == 0)
    {
        printf("�� ���������� ��������� �����");
        return -1;
    }
    List* answer = mergeSort(newList, number, &error);
    if (error == 1)
    {
        deleteList(answer);
        printf("���� �� ������");
        return -1;
    }
    if (error == 2)
    {
        deleteList(answer);
        printf("������ � ������ ���������");
        return -1;
    }
    if (error == 3)
    {
        deleteList(answer);
        printf("������������ ������");
        return -1;
    }
    print(answer);
    printf("\n");
    deleteList(answer);
}
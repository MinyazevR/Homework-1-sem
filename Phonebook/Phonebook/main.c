#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct 
{
    char number[20];
    char name[20];
}Phonebook;

int recordCounter(Phonebook *array)
{
    FILE* file  = fopen("qwerty.txt", "r");
    if (file == NULL)
    {
        return -1;
    }
    int readNumber = 0;
    while (!feof(file))
    {
        if(fscanf(file, "%s", array[readNumber].name) != EOF);
        {
            const int fscanfResult = fscanf(file, "%s", &array[readNumber].number);
            if (fscanfResult == 0)
            {
                break;
            }
            readNumber++;
        }
    }
    fclose(file);
    return readNumber;
}

int addAnEntry(Phonebook* array, int readNumber)
{
    printf("������� ���");
    const int firstResultScanf = scanf("%s[^\n]", array[readNumber].name);
    if (firstResultScanf == 0)
    {
        printf("������");
        return 0;
    }
    printf("������� �����");
    int number = 0;
    const int secondResultScanf = scanf("%s[^\n]", array[readNumber].number);
    if (secondResultScanf == 0)
    {
        printf("������");
        return 0;
    }
    return 1;
}

int saveTheChanges(Phonebook* array, int readNumber)
{
    FILE* file = fopen("qwerty.txt", "w");
    if (file == NULL)
    {
        return -1;
    }
    for (int i = 0; i <= readNumber ; i++)
    {
        fprintf(file, "%s %s\n", array[i].name, array[i].number);
        
    }
    fclose(file);
    return 0;
}

int outputAllEntries(Phonebook* array,int readNumber)
{
    for (int i = 0; i <= readNumber; i++)
    {
        printf("%s %s\n", array[i].name, array[i].number);
    }
    return 0;
}

void findNumberByName(Phonebook *array, char *name, int readNumber)
{
    for (int i = 0; i < readNumber; i++)
    {
        if (strcmp(array[i].name, name) == 0)
        {
            return array[i].number;
        }
        else
        {
            printf("������ ������ ���");
        }
    }
}

void findNameByNumber(Phonebook* array, char* number, int readNumber)
{
    for (int i = 0; i < readNumber; i++)
    {
        if (strcmp(array[i].number, number) == 0)
        {
            return array[i].name;
        }
        else
        {
            printf("������ ����� ���");
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    printf("��� �� ������ �������?\n");
    printf("0 - �����\n");
    printf("1 - �������� ������(��� � �������)\n");
    printf("2 - ����������� ��� ��������� ������\n");
    printf("3 - ����� ������� �� �����\n");
    printf("4 - ����� ��� �� ��������\n");
    printf("5 - ��������� ������� ������ � ����\n");
    Phonebook array[100] = { '\0' };
    int number = 1;
    while(number != 0)
    {
        scanf_s("%d", &number);
        switch (number)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                addAnEntry(array, recordCounter(array));
                break;
            }
            case 2:
            {
                outputAllEntries(array, recordCounter(array));
                break;
            }
            case 3:
            {
                char name[20] = {'\0'};
                gets(name);
                findNumberByName(array, name, recordCounter(array));
                break;
            }
            case 4:
            {
                char number[20] = { '\0' };
                gets(number);
                findNumberByName(array, number, recordCounter(array));
                break;
            }
            case 5:
            {
                saveTheChanges(array, recordCounter(array));
                break;
            }
            default:
            {
                printf("����������, ������� ����� �� 0 �� 5");
                break;
            }
        }
    }
}

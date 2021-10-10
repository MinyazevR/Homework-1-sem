#include "phoneBook.h"
#include "tests.h"
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    if (!testFunctionsWorkingWithFile())
    {
        printf("���� ��������");
        return -1;
    }
    setlocale(LC_ALL, "rus");
    printf("0 - �����\n");
    printf("1 - �������� ������(��� � �������)\n");
    printf("2 - ����������� ��� ��������� ������\n");
    printf("3 - ����� ������� �� �����\n");
    printf("4 - ����� ��� �� ��������\n");
    printf("5 - ��������� ������� ������ � ����\n");
    Phonebook array[100] = {0};
    int number = 1;
    int numberOfRecords = readPhonebook(array, "phoneNumber.txt");
    while (number != 0)
    {
        printf("��� �� ������ �������?\n");
        while (scanf("%d", &number) == 0)
        {
            printf("����������, ������� ����� �� 0 �� 5\n");
            while (getchar() != '\n')
            {
                continue;
            }
        }
        switch (number)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                printf("������� ���\n");
                char name[20] = {'\0'};
                if (scanf("%s", name) == 0)
                {
                    printf("�� ������� ������ ���\n");
                    break;
                }
                printf("������� �����\n");
                char phoneNumber[20] = {'\0'};
                if (scanf("%s", phoneNumber) == 0)
                {
                    printf("�� ������� ������ �����\n");
                    break;
                }
                const int addAnEntryResult = addAnEntry(array, &numberOfRecords, name, phoneNumber);
                break;
            }
            case 2:
            {
                outputAllEntries(array, numberOfRecords);
                break;
            }
            case 3:
            {
                char name[20] = {'\0'};
                printf("������� ���\n");
                if (scanf("%s", name) == 0)
                {
                    printf("�� ������� ������ ���\n");
                    break;
                }
                const char* findNumberByNameResult = findNumberByName(array, name, numberOfRecords);
                if (findNumberByNameResult == NULL)
                {
                    printf("������ ����� ���\n");
                }
                else
                {
                    printf("%s\n", findNumberByNameResult);
                }
                break;
            }
            case 4:
            {
                char phoneNumber[20] = { '\0' };
                printf("������� �����\n");
                if (scanf("%s", phoneNumber) == 0)
                {
                    printf("�� ������� ������ �����\n");
                    break;
                }
                const char *findNameByNumberResult = findNameByNumber(array, phoneNumber, numberOfRecords);
                if (findNameByNumberResult == NULL)
                {
                    printf("������ ������ ���\n");
                }
                else
                {
                    printf("%s\n", findNameByNumberResult);
                }
                break;
            }
            case 5:
            {
                if (saveTheChanges(array, numberOfRecords) == 0)
                { 
                    printf("���������\n");
                }
                else
                {
                    printf("�� ������� ��������� ���������\n");
                }
                break;
            }
            default:
            {
                printf("����������, ������� ����� �� 0 �� 5\n");
                break;
            }
        }
    }
}

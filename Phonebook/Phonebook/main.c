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
    int numberOfRecords = recordsCounter(array, "phoneNumber.txt");
    while (number != 0)
    {
        printf("��� �� ������ �������?\n");
        while(scanf("%d", &number) == 0)
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
                const int addAnEntryResult = addAnEntry(array, &numberOfRecords);
                if (addAnEntryResult == -1)
                {
                    printf("� ���������, �� ���������� �������� ������\n");
                }
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
                    printf("�� ������� ������ ���");
                    break;
                }
                printf("%s\n", findNumberByName(array, name, numberOfRecords));
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
                printf("%s\n", findNameByNumber(array, phoneNumber, numberOfRecords));
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

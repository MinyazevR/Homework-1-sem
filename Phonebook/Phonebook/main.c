#include <stdio.h>
#include <locale.h>
#include "addAnEntry.h"
#include "srtuct.h"
#include "saveTheChanges.h"
#include "readCounter.h"
#include "outputAllEntries.h"
#include "findNameByNumber.h"
#include "findNumberByName.h"
#include "testFindNamebyNumber.h"
int main()
{
    if (!testFindNameByNumber())
    {
        return -1;
    }
    setlocale(LC_ALL, "rus");
    printf("0 - �����\n");
    printf("1 - �������� ������(��� � �������)\n");
    printf("2 - ����������� ��� ��������� ������\n");
    printf("3 - ����� ������� �� �����\n");
    printf("4 - ����� ��� �� ��������\n");
    printf("5 - ��������� ������� ������ � ����\n");
    Phonebook array[100] = {'\0'};
    int number = 1;
    while(number != 0)
    {
        printf("��� �� ������ �������?\n");
        scanf_s("%d", &number);
        switch (number)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                const int addAnEntryResult = addAnEntry(array, recordCounter(array));
                if (addAnEntryResult == -1)
                {
                    printf("� ���������, �� ���������� �������� ������\n");
                }
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
                printf("������� ���\n");
                if (scanf("%s", name) == 0)
                {
                    printf("�� ������� ������ ���");
                    break;
                }
                printf("%s\n", findNumberByName(array, name, recordCounter(array)));
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
                printf("%s\n", findNameByNumber(array, phoneNumber, recordCounter(array)));
                break;
            }
            case 5:
            {
                printf("���������\n");
                saveTheChanges(array, recordCounter(array));
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

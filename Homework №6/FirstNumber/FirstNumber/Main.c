#include "../../List/List/List.h"
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    printf("0 � �����\n");
    printf("1 � �������� �������� � ������������� ������\n");
    printf("2 � ������� �������� �� ������\n");
    printf("3 � ����������� ������\n");
    List* newList = createList();
    int number = 1;
    int error = 0;
    while (number != 0)
    {
        printf("��� �� ������ �������\n");
        while (scanf_s("%d", &number) == 0)
        {
            printf("������� ����� �� 0 �� 3\n");
            while (getchar() != '\n')
            {
                continue;
            }
        }
        switch (number)
        {
        case 0:
        {
            deleteList(newList);
            return 0;
        }
        case 1:
        {
            printf("������� �����, ������� ������ ��������\n");
            int numberForAdd = 0;
            if (scanf_s("%d", &numberForAdd) == 0)
            {
                printf("�� ������� �������� �����\n");
                break;
            }
            add(newList, numberForAdd, &error);
            if (error == 3)
            {
                printf("������������ ������\n");
                deleteList(newList);
                return -1;
            }
            printf("������� ������� �������� � ������\n");
            break;
        }
        case 2:
        {
            int deleteNumber = 0;
            printf("������� �����, ������� ������ ��������� �� ������\n");
            if (scanf_s("%d", &deleteNumber) == 0)
            {
                printf("�� ������� ������� �����\n");
                break;
            }
            removeElement(findPosition(deleteNumber, newList, &error), newList);
            if (error == 6)
            {
                printf("�������� ��� � ������\n");
                break;
            }
            else if (error == 3)
            {
                printf("������������ ������\n");
                deleteList(newList);
                return -1;
            }
            printf("������� ������� ������\n");
            break;
        }
        case 3:
        {
            print(newList);
            printf("\n");
            break;
        }
        default:
        {
            printf("������� ����� �� 0 �� 3\n");
            break;
        }
        }
    }
}

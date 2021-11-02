#include "List.h"
#include "TestList.h"
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    if (!allTest())
    {
        printf("���� ��������");
        return 0;
    }
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
                    printf("�� ������� �������� ������\n");
                    deleteList(newList);
                    return -1;
                }
                printf("������� ������� �������� � ������\n");
                break;
            }
            case 2:
            {
                printf("���� ������ ������� ������ ������� ������ ������� �� 1, ���� ����� ����� �������, �� ������� �� ������ �����\n");
                int result = 0;
                scanf_s("%d", &result);
                switch (result)
                {
                    case 1:
                    {
                        removeFirstElement(first(newList, &error), newList, &error);
                        if (error == 3)
                        {
                            printf("�� ������� ������� ������ �������\n");
                            deleteList(newList);
                            return -1;
                        }
                        else if (error == 2)
                        {
                            printf("������ ����, ������� ������");
                            break;
                        }
                        printf("������ ������� ������\n");
                        break;
                    }
                    default:
                    {
                        int deleteNumber = 0;
                        printf("������� �����, ������� ������ ��������� �� ������\n");
                        if (scanf_s("%d", &deleteNumber) == 0)
                        {
                            printf("�� ������� ������� �����\n");
                            break;
                        }
                        removeElement(findPosition(deleteNumber, newList, &error), newList, &error);
                        if (error == 6 || error == 1)
                        {
                            printf("�������� ��� � ������ ��� �� ����� �� ������ �����\n");
                            break;
                        }
                        else if (error == 3)
                        {
                            printf("������ � ���������� ������\n");
                            deleteList(newList);
                            return -1;
                        }
                        printf("������� ������� ������\n");
                        break;
                    }
                }
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
    deleteList(newList);
    printf("ghhgrhgrgrr");
}
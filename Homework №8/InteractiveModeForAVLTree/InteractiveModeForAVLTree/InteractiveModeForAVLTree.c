#include "../../AVLTree/AVLTree/AVLTree.h"
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    printf("0 � �����\n");
    printf("1 � �������� �������� �� ��������� ����� � �������\n");
    printf("2 � �������� �������� �� ��������� ����� �� �������\n");
    printf("3 � ��������� ������� ��������� �����\n");
    printf("4 � ������� �������� ���� � ��������� � ��� �������� �� �������\n");
    Node* tree = createTree();
    int number = 1;
    int error = 0;
    while (number != 0)
    {
        printf("������� �����\n");
        while (scanf_s("%d", &number) == 0)
        {
            printf("������� ����� �� 0 �� 4\n");
            while (getchar() != '\n')
            {
                continue;
            }
        }
        switch (number)
        {
        case 0:
        {
            deleteTree(&tree);
            return 0;
        }
        case 1:
        {
            printf("������� ���� (�� ����� 100 ��������)\n");
            char key[100] = {'\0'};
            const int firstScanfResult = scanf_s("%s", key, (unsigned)sizeof(key));
            if (firstScanfResult == 0)
            {
                printf("�� ������� ������ ����\n");
                break;
            }
            printf("������� �������� (�� ����� 100 ��������)\n");
            char string[100] = { '\0' };
            const int secondScanfResult = scanf_s("%s", string, (unsigned)sizeof(string));
            if (secondScanfResult == 0)
            {
                printf("�� ������� �������� ��������\n");
                break;
            }
            tree = addNode(tree, key, string, &error);
            if (error == 1)
            {
                deleteTree(&tree);
                printf("������������ ������\n");
                return -1;
            }
            printf("�������� ������� ��������� \n");
            break;
        }
        case 2:
        {
            printf("������� ���� (�� ����� 100 ��������)\n");
            char key[100] = { '\0' };
            const int firstScanfResult = scanf_s("%s", key, (unsigned)sizeof(key));
            if (firstScanfResult == 0)
            {
                printf("�� ������� ������ ����\n");
                break;
            }
            printf("%s\n", getValue(tree, key));
            break;
        }
        case 3:
        {
            printf("������� ���� (�� ����� 100 ��������)\n");
            char key[100] = { '\0' };
            const int firstScanfResult = scanf_s("%s", key, (unsigned)sizeof(key));
            if (firstScanfResult == 0)
            {
                printf("�� ������� ������ ����\n");
                break;
            }
            bool result = inTree(tree, key);
            if (!result)
            {
                printf("����� ���\n");
                break;
            }
            printf("����� ���� ����\n");
            break;
        }
        case 4:
        {
            printf("������� ���� (�� ����� 100 ��������)\n");
            char key[100] = { '\0' };
            const int firstScanfResult = scanf_s("%s", key, (unsigned)sizeof(key));
            if (firstScanfResult == 0)
            {
                printf("�� ������� ������ ����\n");
                break;
            }
            deleteNode(&tree, key, &error);
            if (error == 1)
            {
                printf("������������ ������\n");
                return -1;
            }
            if (error == 2)
            {
                printf("������ ����� ��� \n");
                break;
            }
            printf("������� ������� ������\n");
            break;
        }
        default:
        {
            printf("������� ����� �� 0 �� 4\n");
            break;
        }
        }
    }
}
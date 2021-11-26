#include "../../Tree/Tree/Tree.h"
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    printf("0 – выйти\n");
    printf("1 – Добавить значение по заданному ключу в словарь\n");
    printf("2 – Получить значение по заданному ключу из словаря\n");
    printf("3 – Проверить наличие заданного ключа\n");
    printf("4 – Удалить заданный ключ и связанное с ним значение из словаря\n");
    Node* tree = createTree();
    int number = 1;
    Error error = 0;
    while (number != 0)
    {
        printf("Введите цифру\n");
        while (scanf_s("%d", &number) == 0)
        {
            printf("Введите, пожалуйста, цифру от 0 до 4\n");
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
            printf("Пожалуйста, введите ключ\n");
            int key = 0;
            const int firstScanfResult = scanf_s("%d", &key);
            if (firstScanfResult == 0)
            {
                printf("Не удалось считать число\n");
                break;
            }
            printf("Пожалуйста, введите строку, которую хотите добавить (размером не более 100 символов)\n");
            char string[100] = { '\0' };
            const int secondScanfResult = scanf_s("%s", string, (unsigned)sizeof(string));
            if (secondScanfResult == 0)
            {
                printf("Не удалось считать строку\n");
                break;
            }
            tree = addNode(tree, key, string, &error);
            if (error == INSUFFICIENT_MEMORY)
            {
                deleteTree(&tree);
                printf("Недостаточно памяти\n");
                return -1;
            }
            printf("добавлено новое значение\n");
            break;
        }
        case 2:
        {
            printf("Пожалуйста, введите ключ\n");
            int key = 0;
            const int firstScanfResult = scanf_s("%d", &key);
            if (firstScanfResult == 0)
            {
                printf("Не удалось считать число\n");
                break;
            }
            printf("%s\n", getValue(tree, key));
            break;
        }
        case 3:
        {
            printf("Пожалуйста, введите ключ\n");
            int key = 0;
            const int firstScanfResult = scanf_s("%d", &key);
            if (firstScanfResult == 0)
            {
                printf("Не удалось считать число\n");
                break;
            }
            bool result = inTree(tree, key);
            if (!result)
            {
                printf("Такого ключа нет\n");
                break;
            }
            printf("Такой ключ есть\n");
            break;
        }
        case 4:
        {
            printf("Пожалуйста, введите ключ\n");
            int key = 0;
            const int firstScanfResult = scanf_s("%d", &key);
            if (firstScanfResult == 0)
            {
                printf("Не удалось считать число\n");
                break;
            }
            deleteNode(&tree, key, &error);
            if (error == INSUFFICIENT_MEMORY)
            {
                printf("Недостаточно памяти\n");
                return -1;
            }
            if (error == ROOT_IS_MISSING)
            {
                printf("Такого ключа нет\n");
                break;
            }
            printf("Значение удалено\n");
            break;
        }
        default:
        {
            printf("Введите, пожалуйста, цифру от 0 до 4\n");
            break;
        }
        }
    }
}
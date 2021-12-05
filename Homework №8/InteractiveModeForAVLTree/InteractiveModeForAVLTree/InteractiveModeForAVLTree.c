#include "../../AVLTree/AVLTree/AVLTree.h"
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    printf("0 – Выйти\n");
    printf("1 – Добавить значение по заданному ключу в словарь\n");
    printf("2 – Получить значение по заданному ключу из словаря\n");
    printf("3 – Проверить наличие заданного ключа\n");
    printf("4 – Удалить заданный ключ и связанное с ним значение из словаря\n");
    Node* tree = createTree();
    int number = 1;
    int error = 0;
    while (number != 0)
    {
        printf("Введите число\n");
        while (scanf_s("%d", &number) == 0)
        {
            printf("Введите число от 0 до 4\n");
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
            printf("Введите ключ (не более 100 символов)\n");
            char key[100] = {'\0'};
            const int firstScanfResult = scanf_s("%s", key, (unsigned)sizeof(key));
            if (firstScanfResult == 0)
            {
                printf("не удалось ввести ключ\n");
                break;
            }
            printf("введите значение (не более 100 символов)\n");
            char string[100] = { '\0' };
            const int secondScanfResult = scanf_s("%s", string, (unsigned)sizeof(string));
            if (secondScanfResult == 0)
            {
                printf("не удалось добавить значение\n");
                break;
            }
            tree = addNode(tree, key, string, &error);
            if (error == 1)
            {
                deleteTree(&tree);
                printf("недостаточно памяти\n");
                return -1;
            }
            printf("значение успешно добавлено \n");
            break;
        }
        case 2:
        {
            printf("Введите ключ (не более 100 символов)\n");
            char key[100] = { '\0' };
            const int firstScanfResult = scanf_s("%s", key, (unsigned)sizeof(key));
            if (firstScanfResult == 0)
            {
                printf("не удалось ввести ключ\n");
                break;
            }
            printf("%s\n", getValue(tree, key));
            break;
        }
        case 3:
        {
            printf("Введите ключ (не более 100 символов)\n");
            char key[100] = { '\0' };
            const int firstScanfResult = scanf_s("%s", key, (unsigned)sizeof(key));
            if (firstScanfResult == 0)
            {
                printf("не удалось ввести ключ\n");
                break;
            }
            bool result = inTree(tree, key);
            if (!result)
            {
                printf("Ключа нет\n");
                break;
            }
            printf("Такой ключ есть\n");
            break;
        }
        case 4:
        {
            printf("Введите ключ (не более 100 символов)\n");
            char key[100] = { '\0' };
            const int firstScanfResult = scanf_s("%s", key, (unsigned)sizeof(key));
            if (firstScanfResult == 0)
            {
                printf("не удалось ввести ключ\n");
                break;
            }
            deleteNode(&tree, key, &error);
            if (error == 1)
            {
                printf("Недостаточно памяти\n");
                return -1;
            }
            if (error == 2)
            {
                printf("Такого ключа нет \n");
                break;
            }
            printf("Элемент успешно удален\n");
            break;
        }
        default:
        {
            printf("Введите число от 0 до 4\n");
            break;
        }
        }
    }
}
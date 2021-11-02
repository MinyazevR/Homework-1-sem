#include "List.h"
#include "TestList.h"
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    if (!allTest())
    {
        printf("Тест провален");
        return 0;
    }
    printf("0 – выйти\n");
    printf("1 – добавить значение в сортированный список\n");
    printf("2 – удалить значение из списка\n");
    printf("3 – распечатать список\n");
    List* newList = createList();
    int number = 1;
    int error = 0;
    while (number != 0)
    {
        printf("Что Вы хотите сделать\n");
        while (scanf_s("%d", &number) == 0)
        {
            printf("Введите число от 0 до 3\n");
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
                printf("Введите число, которое хотите добавить\n");
                int numberForAdd = 0;
                if (scanf_s("%d", &numberForAdd) == 0)
                {
                    printf("Не удалось добавить число\n");
                    break;
                }
                add(newList, numberForAdd, &error);
                if (error == 3)
                {
                    printf("Не удалось выделить память\n");
                    deleteList(newList);
                    return -1;
                }
                printf("Элемент успешно добавлен в список\n");
                break;
            }
            case 2:
            {
                printf("Если хотите удалить первый элемент списка нажмите на 1, если любой кроме первого, то нажмите на другую цифру\n");
                int result = 0;
                scanf_s("%d", &result);
                switch (result)
                {
                    case 1:
                    {
                        removeFirstElement(first(newList, &error), newList, &error);
                        if (error == 3)
                        {
                            printf("Не удалось удалить первый элемент\n");
                            deleteList(newList);
                            return -1;
                        }
                        else if (error == 2)
                        {
                            printf("Список пуст, удалять нечего");
                            break;
                        }
                        printf("Первый элемент удален\n");
                        break;
                    }
                    default:
                    {
                        int deleteNumber = 0;
                        printf("Введите число, которое хотите исключить из списка\n");
                        if (scanf_s("%d", &deleteNumber) == 0)
                        {
                            printf("Не удалось удалить число\n");
                            break;
                        }
                        removeElement(findPosition(deleteNumber, newList, &error), newList, &error);
                        if (error == 6 || error == 1)
                        {
                            printf("Элемента нет в списке или он стоит на первом месте\n");
                            break;
                        }
                        else if (error == 3)
                        {
                            printf("Ошибка с выделением памяти\n");
                            deleteList(newList);
                            return -1;
                        }
                        printf("Элемент успешно удален\n");
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
                printf("Введите число от 0 до 3\n");
                break;
            }
        }
    }
    deleteList(newList);
    printf("ghhgrhgrgrr");
}
#include "../../List/List/List.h"
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    printf("0 Ц выйти\n");
    printf("1 Ц добавить значение в сортированный список\n");
    printf("2 Ц удалить значение из списка\n");
    printf("3 Ц распечатать список\n");
    List* newList = createList();
    int number = 1;
    int error = 0;
    while (number != 0)
    {
        printf("„то ¬ы хотите сделать\n");
        while (scanf_s("%d", &number) == 0)
        {
            printf("¬ведите число от 0 до 3\n");
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
            printf("¬ведите число, которое хотите добавить\n");
            int numberForAdd = 0;
            if (scanf_s("%d", &numberForAdd) == 0)
            {
                printf("Ќе удалось добавить число\n");
                break;
            }
            add(newList, numberForAdd, &error);
            if (error == 3)
            {
                printf("Ќедостаточно пам€ти\n");
                deleteList(newList);
                return -1;
            }
            printf("Ёлемент успешно добавлен в список\n");
            break;
        }
        case 2:
        {
            int deleteNumber = 0;
            printf("¬ведите число, которое хотите исключить из списка\n");
            if (scanf_s("%d", &deleteNumber) == 0)
            {
                printf("Ќе удалось удалить число\n");
                break;
            }
            removeElement(findPosition(deleteNumber, newList, &error), newList);
            if (error == 6)
            {
                printf("Ёлемента нет в списке\n");
                break;
            }
            else if (error == 3)
            {
                printf("Ќедостаточно пам€ти\n");
                deleteList(newList);
                return -1;
            }
            printf("Ёлемент успешно удален\n");
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
            printf("¬ведите число от 0 до 3\n");
            break;
        }
        }
    }
}

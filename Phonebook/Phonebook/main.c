#include "phoneBook.h"
#include "tests.h"
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    if (!testFunctionsWorkingWithFile())
    {
        printf("Тест провален");
        return -1;
    }
    setlocale(LC_ALL, "rus");
    printf("0 - выйти\n");
    printf("1 - добавить запись(имя и телефон)\n");
    printf("2 - распечатать все имеющиеся записи\n");
    printf("3 - найти телефон по имени\n");
    printf("4 - найти имя по телефону\n");
    printf("5 - сохранить текущие данные в файл\n");
    Phonebook array[100] = {0};
    int number = 1;
    int numberOfRecords = recordsCounter(array, "phoneNumber.txt");
    while (number != 0)
    {
        printf("Что вы хотите сделать?\n");
        while(scanf("%d", &number) == 0)
        {
            printf("Пожалуйста, введите число от 0 до 5\n");
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
                    printf("К сожалению, не получилось добавить запись\n");
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
                printf("Введите имя\n");
                if (scanf("%s", name) == 0)
                {
                    printf("Не удалось ввести имя");
                    break;
                }
                printf("%s\n", findNumberByName(array, name, numberOfRecords));
                break;
            }
            case 4:
            {
                char phoneNumber[20] = { '\0' };
                printf("Введите номер\n");
                if (scanf("%s", phoneNumber) == 0)
                {
                    printf("Не удалось ввести номер\n");
                    break;
                }
                printf("%s\n", findNameByNumber(array, phoneNumber, numberOfRecords));
                break;
            }
            case 5:
            {
                if (saveTheChanges(array, numberOfRecords) == 0)
                { 
                    printf("Сохранено\n");
                }
                else
                {
                    printf("Не удалось сохранить изменения\n");
                }
                break;
            }
            default:
            {
                printf("Пожалуйста, введите число от 0 до 5\n");
                break;
            }
        }
    }
}

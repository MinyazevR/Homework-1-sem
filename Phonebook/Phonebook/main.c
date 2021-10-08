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
    printf("0 - выйти\n");
    printf("1 - добавить запись(имя и телефон)\n");
    printf("2 - распечатать все имеющиеся записи\n");
    printf("3 - найти телефон по имени\n");
    printf("4 - найти имя по телефону\n");
    printf("5 - сохранить текущие данные в файл\n");
    Phonebook array[100] = {'\0'};
    int number = 1;
    while(number != 0)
    {
        printf("Что вы хотите сделать?\n");
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
                    printf("К сожалению, не получилось добавить запись\n");
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
                printf("Введите имя\n");
                if (scanf("%s", name) == 0)
                {
                    printf("Не удалось ввести имя");
                    break;
                }
                printf("%s\n", findNumberByName(array, name, recordCounter(array)));
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
                printf("%s\n", findNameByNumber(array, phoneNumber, recordCounter(array)));
                break;
            }
            case 5:
            {
                printf("Сохранено\n");
                saveTheChanges(array, recordCounter(array));
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

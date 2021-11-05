#include "CyclicList.h"
#include "TestCyclicList.h"
#include "CircleOfMurders.h"
#include "TestFindSurvivorPosition.h"
#include <locale.h>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "rus");
    if (!allTest())
    {
        printf("Тест провален");
        return -1;
    }
    printf("Введите количество воинов\n");
    int numberOfWarriors = 0;
    scanf_s("%d", &numberOfWarriors);
    printf("Убивают каждого m-ого воина. Введите это число m\n");
    int frequencyOfMurders = 0;
    scanf_s("%d", &frequencyOfMurders);
    int error = 0;
    const int answer = findSurvivorPosition(numberOfWarriors, frequencyOfMurders, &error);
    if (error == 1)
    {
        printf("Ошибка в работе программы");
        return -1;
    }
    if (error == 2)
    {
        printf("Выживут все :)");
        return 0;
    }
    if (error == 3)
    {
        printf("Недостаточно памяти");
        return -1;
    }
    printf("Позиция выжившего воина - %d", answer);
}
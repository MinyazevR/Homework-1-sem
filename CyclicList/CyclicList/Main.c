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
        printf("���� ��������");
        return -1;
    }
    printf("������� ���������� ������\n");
    int numberOfWarriors = 0;
    scanf_s("%d", &numberOfWarriors);
    printf("������� ������� m-��� �����. ������� ��� ����� m\n");
    int frequencyOfMurders = 0;
    scanf_s("%d", &frequencyOfMurders);
    int error = 0;
    const int answer = findSurvivorPosition(numberOfWarriors, frequencyOfMurders, &error);
    if (error == 1)
    {
        printf("������ � ������ ���������");
        return -1;
    }
    if (error == 2)
    {
        printf("������� ��� :)");
        return 0;
    }
    if (error == 3)
    {
        printf("������������ ������");
        return -1;
    }
    printf("������� ��������� ����� - %d", answer);
}
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

int semiQSort(int* arrayOfNumber, int numberElementsInArray)
{
    int increment = 1;
    int decrement = numberElementsInArray - 1;

    while (increment < decrement)
    {
        /* ������ ������� ����� ��� ����, ��� ������ ��� �� ���������� increment, ���� ������ ��� ����� ���� ������������ � �
        ������ ����� ��������� ������ �������� ������ ��� ��������� ������ �������� increment ����� ������������� �� countOfElementsLessFirst + 1 � ������
        ����� ����� ���� �����������, �.� ����� ������� ����� ������ ����������� increment*/
        while (arrayOfNumber[increment] < arrayOfNumber[0] && increment < decrement)
        {
            increment++;
        }
        while (arrayOfNumber[decrement] >= arrayOfNumber[0] && decrement > increment)
        {
            decrement--;
        }
        if (increment <= decrement)
        {
            const int temporaryVariable = arrayOfNumber[decrement];
            arrayOfNumber[decrement] = arrayOfNumber[increment];
            arrayOfNumber[increment] = temporaryVariable;
        }
        increment++;
        decrement--;
    }
    return decrement;
}

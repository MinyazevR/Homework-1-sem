#include "test.h"
#include "choiseSort.h"

bool checkSort(int* arrayOfNumbers, int numberOfElement)
{
    for (int i = 0; i < numberOfElement - 1; i++)
    {
        if (arrayOfNumbers[i] > arrayOfNumbers[i + 1])
        {
            return false;
        }
    }
    return true;
}
bool testSort�hoice()
{
    // �������� ������ ���������� ��� ���������������� �������
    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    sortChoise(array, 10);

    // �������� ������ ���������� ��� ������� �� ���������� ���������
    int arrayOfEqualElements[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    sortChoise(arrayOfEqualElements, 10);

    // �������� ������ ���������� ��� ������� ������� �� ������� ��������
    int arrayOfOneNumber[1] = { 15 };
    sortChoise(arrayOfOneNumber, 1);

    // �������� ������ ���������� ��� ������� ������� �� ���� ��������
    int arrayOfZeroNumber[1] = { 15 };
    sortChoise(arrayOfZeroNumber, 0);

    return checkSort(array, 10)
        && checkSort(arrayOfEqualElements, 10)
        && checkSort(arrayOfOneNumber, 1)
        && checkSort(arrayOfZeroNumber, 0);
}
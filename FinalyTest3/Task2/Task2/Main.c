#include "Matrix.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    int numberOfRows = 0;
    printf("Введите кошичество строк в матрице");
    scanf_s()
    int** matrix = createMatrix(6, 1);
    int** newMatrix = createMatrix(6, 0);
    printMatrix(6, matrix);
    printf("\n");
    printMatrix(6, newMatrix);
}
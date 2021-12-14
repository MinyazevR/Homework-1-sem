#include <stdlib.h>
#include <stdio.h>

int** createMatrix(int number, int choice)
{
    int** matrix = calloc(number, sizeof(int*));
    if (matrix == NULL)
    {
        return matrix;
    }
    for (int i = 0; i < number; i++)
    {
        matrix[i] = calloc(number, sizeof(int));
        if (matrix[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(matrix[j]);
            free(matrix);
            return matrix;
        }
    }
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            if (choice == 0)
            {
                matrix[i][j] = 0;
            }
            else
            {
                matrix[i][j] = rand() % 5;
            }
        }
    }
    return matrix;
}

void martrixElements(int** matrix, int** newMatrix, int number, const char* filename)
{
    int minimum = INT_MAX;
    int index = 0;
    int maximum = INT_MIN;
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            if (matrix[i][j] < minimum)
            {
                minimum = matrix[i][j];
                index = j;
            }
        }
        for (int l = i; l < number; l++)
        {
            if (matrix[l][index] > maximum)
            {
                maximum = matrix[l][index];
            }
        }
        if (maximum == minimum)
        {
            newMatrix[i][index] = matrix[i][index];
        }
    }
}

void printMatrix(int number, int** matrix)
{
    for (int i = 0; i < number; i++)
    {
        printf("\n");
        for (int j = 0; j < number; j++)
        {
            printf("%d ", matrix[i][j]);
        }
    }
}
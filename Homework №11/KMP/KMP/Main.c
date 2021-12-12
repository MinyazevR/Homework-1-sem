#include <stdio.h>
#include "KMP.h"
#include "String.h"
#include "ReadFile.h"
#include <stdlib.h>
#include "TestKMP.h"

int main()
{
    if (!testKMP())
    {
        printf("Test failed");
        return -1;
    }
    printf("enter the substring\n");
    int error = 0;
    char* substring = readString(&error);
    if (error == 1)
    {
        printf("memory not allocated");
        return -1;
    }
    char* string = readFile("Text.txt", &error);
    if (error == 1)
    {
        free(substring);
        printf("memory not allocated");
        return -1;
    }
    if (error == 2)
    {
        free(substring);
        printf("file not found");
        return -1;
    }
    int* prefix = findPrefix(substring, &error);
    if (error == 1)
    {
        free(string);
        free(substring);
        printf("memory not allocated");
        return -1;
    }
    const int result = algorithmKMP(string, substring, prefix);
    free(substring);
    free(string);
    free(prefix);
    printf("the position of the first occurrence of the substring in the string (-1 if there is no occurrence) = %d", result);
}
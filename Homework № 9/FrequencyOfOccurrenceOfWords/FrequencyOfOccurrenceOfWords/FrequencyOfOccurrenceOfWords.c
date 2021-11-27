#include "ReadFile.h"
#include <stdio.h>

int main()
{
    Error error = NOT_ERROR;
    HashTable* table = createTable(&error);
    int result = readFile(table, "Text.txt");
    if (result == -1)
    {
        printf("File not found");
        return -1;
    }
    if (error == INSUFFICIENT_MEMORY)
    {
        printf("Memory not allocated");
        return -1;
    }
    printValue(table);
    deleteHashTable(table);
}
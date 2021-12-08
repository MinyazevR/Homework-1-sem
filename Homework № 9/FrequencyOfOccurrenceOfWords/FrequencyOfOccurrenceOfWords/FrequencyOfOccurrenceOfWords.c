#include "ReadFile.h"
#include "TestReadFileUsingHashTable.h"
#include <stdio.h>

int main()
{
    if (!testReadFileUsingHashTable())
    {
        return -1;
    }
    Error error = NOT_ERROR;
    HashTable* table = createTable(&error, 200);
    int result = readFile(&table, "Text.txt");
    if (result == -1)
    {
        deleteHashTable(table);
        printf("File not found");
        return -1;
    }
    if (error == INSUFFICIENT_MEMORY)
    {
        deleteHashTable(table);
        printf("Memory not allocated");
        return -1;
    }
    printValue(table);
    deleteHashTable(table);
}
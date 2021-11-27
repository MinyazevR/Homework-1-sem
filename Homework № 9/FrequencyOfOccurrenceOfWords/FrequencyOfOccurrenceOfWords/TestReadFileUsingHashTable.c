#include "TestReadFileUsingHashTable.h"
#include "ReadFile.h"

bool testReadFileUsingHashTable()
{
    Error error = NOT_ERROR;
    HashTable* table = createTable(&error);
    int result = readFile(table, "Test.txt");
    if (result == -1)
    {
        return false;
    }
    if (error == INSUFFICIENT_MEMORY)
    {
        return false;
    }
    deleteHashTable(table);
}
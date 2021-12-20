#include "TestHashTable.h"
#include "HashTable.h"

bool testAddElement()
{
    Error error = NOT_ERROR;
    HashTable* table = createTable(&error, 10);
    addElement("Hello", &table, &error);
    addElement("World", &table, &error);
    addElement("Test", &table, &error);
    bool firstResult = inTable(table, "Hello");
    bool secondResult = inTable(table, "World");
    bool thirdResult = inTable(table, "Test");
    deleteHashTable(table);
    return firstResult && secondResult && thirdResult;
}
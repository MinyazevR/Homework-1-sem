#include "TestReadFileUsingHashTable.h"
#include "ReadFile.h"

bool testReadFileUsingHashTable()
{
    Error error = NOT_ERROR;
    HashTable* table = createTable(&error);
    int result = readFile(table, "Test.txt");
    if (result == -1)
    {
        deleteHashTable(table);
        return false;
    }
    if (error == INSUFFICIENT_MEMORY)
    {
        deleteHashTable(table);
        return false;
    }
    const int firstCheck = countNumberOfDuplicateItemsForSpecificList("Hello", table);
    const int secondCheck = countNumberOfDuplicateItemsForSpecificList("World", table);
    const int thirdCheck = countNumberOfDuplicateItemsForSpecificList("Test", table);
    const int fourthCheck = countNumberOfDuplicateItemsForSpecificList("Commit", table);
    const int fifthCheck = countNumberOfDuplicateItemsForSpecificList("A", table);
    const int sixthCheck = countNumberOfDuplicateItemsForSpecificList("S", table);
    deleteHashTable(table);
    return firstCheck == 3 && secondCheck == 2 && thirdCheck == 1 
        && fourthCheck == 1 && fifthCheck == 1 && sixthCheck == 3;
}
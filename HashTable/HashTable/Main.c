#include <stdio.h>
#include "HashTable.h"

int readPhonebook(HashTable* table, const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return -1;
    }
    while (!feof(file))
    {
        // words in the file are less than 100 characters in size
        char array[100] = { '\0' };
        Error error = NOT_ERROR;
        if (fscanf(file, "%s", array) != EOF);
        {
            addElement(array, table, &error);
        }
    }
    fclose(file);
    return 0;
}

int main()
{
    Error error = NOT_ERROR;
    HashTable* table = createTable(&error);
    readPhonebook(table, "Text.txt");
    printValue(table);
    deleteHashTable(table);
}
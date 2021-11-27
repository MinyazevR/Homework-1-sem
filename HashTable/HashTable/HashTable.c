#include "HashTable.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct HashTable
{
    int numberOfElements;
    int numberOfSegment;
    struct List** array;
} HashTable;

HashTable* createTable(Error* error)
{
    if (*error != NOT_ERROR)
    {
        return NULL;
    }
    HashTable* table = calloc(1, sizeof(HashTable));
    if (table == NULL)
    {
        *error = INSUFFICIENT_MEMORY;
        return NULL;
    }
    table->numberOfSegment = 100;
    table->array = calloc(100, sizeof(List*));
    if (table->array == NULL)
    {
        free(table);
        *error = INSUFFICIENT_MEMORY;
        return NULL;
    }
    for (int i = 0; i < table->numberOfSegment; i++)
    {
        table->array[i] = createList(error);
        if (*error != NOT_ERROR)
        {
            break;
        }
    }
    return table;
}

void deleteHashTable(HashTable* table)
{
    for (int i = 0; i < table->numberOfSegment; i++)
    {
        deleteList(table->array[i]);
    }
    free(table->array);
    free(table);
}

int hashFunction(const char* string, HashTable* table)
{
    int result = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        result = (result + string[i]) % table->numberOfSegment;
    }
    return result;
}

HashTable* resize(HashTable* table, Error* error)
{
    if (*error != NOT_ERROR)
    {
        return table;
    }
    HashTable* newTable = calloc(1, sizeof(HashTable));
    if (newTable == NULL)
    {
        *error = INSUFFICIENT_MEMORY;
        return table;
    }
    newTable->numberOfSegment = table->numberOfSegment * 2;
    newTable->array = calloc(newTable->numberOfSegment, sizeof(List*));
    if (newTable->array == NULL)
    {
        free(newTable);
        *error = INSUFFICIENT_MEMORY;
        return table;
    }
    for (int i = 0; i < newTable->numberOfSegment; i++)
    {
        newTable->array[i] = createList(error);
        if (*error != NOT_ERROR)
        {
            *error = INSUFFICIENT_MEMORY;
            deleteHashTable(newTable);
            break;
        }
    }
    for (int i = 0; i < table->numberOfSegment; i++)
    {
        while (!isEmpty(table->array[i]))
        {
            char* newString = calloc(strlen(getHeadValue(table->array[i])) + 1, sizeof(char));
            if (newString == NULL)
            {
                *error = INSUFFICIENT_MEMORY;
                deleteHashTable(newTable);
                return table;
            }
            strcpy(newString, getHeadValue(table->array[i]));
            add(newTable->array[i], newString, error);
            removeFirstElement(table->array[i], error);
        }
        deleteList(table->array[i]);
    }
    newTable->numberOfElements = table->numberOfElements;
    free(table->array);
    free(table);
    return newTable;
}

void addElement(const char* string, HashTable* table, Error* error)
{
    if (*error != NOT_ERROR)
    {
        return;
    }
    float factor = (float)(table->numberOfElements) / (float)(table->numberOfSegment);
    if (factor > 1.5)
    {
        table = resize(table, error);
        if (*error != NOT_ERROR)
        {
            return;
        }
    }
    add(table->array[hashFunction(string, table)], string, error);
    if (*error == INSUFFICIENT_MEMORY)
    {
        return;
    }
    if (*error != ELEMENT_REPEATS)
    {
        table->numberOfElements++;
        return;
    }
    error = NOT_ERROR;
}

void printValue(HashTable* table)
{
    int maximumListLength = numberOfElements(table->array[0]);
    int numberOf—ompletedBuckets = 0;
    int totalSizeOfAllLists = 0;
    for (int i = 0; i < table->numberOfSegment; i++)
    {
        print(table->array[i]);
        if (!isEmpty(table->array[i]))
        {
            numberOf—ompletedBuckets++;
        }
        int listLength = numberOfElements(table->array[i]);
        totalSizeOfAllLists += listLength;
        if (listLength > maximumListLength)
        {
            maximumListLength = listLength;
        }
    }
    printf("maximum list lenght = %d\n", maximumListLength);
    printf("hash table fill factor = %f\n", (float)(table->numberOfElements) / (float)(table->numberOfSegment));
    printf("average list length = %f\n", (float)(totalSizeOfAllLists) / (float)(numberOf—ompletedBuckets));
}

bool inTable(HashTable* table, char* string)
{
    return inList(table->array[hashFunction(string, table)], string);
}

int countNumberOfDuplicateItemsForSpecificList(char* value, HashTable* table)
{
    return returnNumberOfDuplicateValues(table->array[hashFunction(value, table)], value);
}
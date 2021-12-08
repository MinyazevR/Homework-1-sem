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

HashTable* createTable(Error* error, int numberOfSegment)
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
    table->numberOfSegment = numberOfSegment;
    table->array = calloc(numberOfSegment, sizeof(List*));
    if (table->array == NULL)
    {
        free(table);
        *error = INSUFFICIENT_MEMORY;
        return NULL;
    }
    for (int i = 0; i < numberOfSegment; i++)
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
    return abs(result);
}

HashTable* resize(HashTable* table, Error* error)
{
    if (*error != NOT_ERROR)
    {
        return table;
    }
    HashTable* newTable = createTable(error, table->numberOfSegment * 2);
    int i = 0;
    while (i < table->numberOfSegment)
    {
        while (!isEmpty(table->array[i]))
        {
            add(newTable->array[i], getHeadValue(table->array[i]), error);
            removeFirstElement(table->array[i], error);
        }
        deleteList(table->array[i]);
        i++;
    }
    newTable->numberOfElements = table->numberOfElements;
    free(table->array);
    free(table);
    return newTable;
}

void addElement(const char* string, HashTable** table, Error* error)
{
    if (*error != NOT_ERROR)
    {
        return;
    }
    float factor = (float)((*table)->numberOfElements) / (float)((*table)->numberOfSegment);
    if (factor > 1)
    {
        *table = resize(*table, error);
        if (*error != NOT_ERROR)
        {
            return;
        }
    }
    add((*table)->array[hashFunction(string, *table)], string, error);
    if (*error == INSUFFICIENT_MEMORY)
    {
        return;
    }
    if (*error != ELEMENT_REPEATS)
    {
        (*table)->numberOfElements++;
        return;
    }
    error = NOT_ERROR;
}

void printValue(HashTable* table)
{
    int maximumListLength = numberOfElements(table->array[0]);
    int numberOfCompletedBuckets = 0;
    int totalSizeOfAllLists = 0;
    for (int i = 0; i < table->numberOfSegment; i++)
    {
        print(table->array[i]);
        if (!isEmpty(table->array[i]))
        {
            numberOfCompletedBuckets++;
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
    printf("average list length = %f\n", (float)(totalSizeOfAllLists) / (float)(numberOfCompletedBuckets));
}

bool inTable(HashTable* table, char* string)
{
    return inList(table->array[hashFunction(string, table)], string);
}

int countNumberOfDuplicateItemsForSpecificList(char* value, HashTable* table)
{
    return returnNumberOfDuplicateValues(table->array[hashFunction(value, table)], value);
}
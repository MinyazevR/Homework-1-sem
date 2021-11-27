#include "TestSinglyLinkedListForHashTable.h"
#include "SinglyLinkedListForHashTable.h"
#include <string.h>

// Function to check the function that adds an item to the list
bool testAdd()
{
    Error error = NOT_ERROR;
    List* newList = createList();
    add(newList, "test", &error);
    add(newList, "list", &error);
    if (error == INSUFFICIENT_MEMORY)
    {
        deleteList(newList);
        return false;
    }
    const char* firstValue = getHeadValue(newList);
    Position* position = first(newList, &error);
    if (error == EMPTY_LIST)
    {
        deleteList(newList);
        return false;
    }
    const char* secondValue = getValue(next(position));
    bool result = strcmp(firstValue, "test") == 0 && strcmp(secondValue, "list") == 0;
    deletePosition(position);
    deleteList(newList);
    return result;
}

// Function to check the function that deletes the first item in the list
bool testRemoveHead()
{
    Error error = NOT_ERROR;
    List* newList = createList();
    add(newList, "Hello", &error);
    add(newList, "World", &error);
    add(newList, "Hello", &error);
    removeFirstElement(newList, &error);
    if (error == EMPTY_LIST || error == INSUFFICIENT_MEMORY)
    {
        deleteList(newList);
        return false;
    }
    const char* value = getHeadValue(newList);
    bool result = strcmp(value, "World") == 0;
    deleteList(newList);
    return result;
}

// Function for checking the function counting the number of elements
bool testNumberOfElements()
{
    List* newList = createList();
    Error error = NOT_ERROR;
    add(newList, "Hello", &error);
    add(newList, "Merge", &error);
    add(newList, "test",  &error);
    add(newList, "list",  &error);
    if (error == INSUFFICIENT_MEMORY)
    {
        deleteList(newList);
        return false;
    }
    const int number = numberOfElements(newList);
    deleteList(newList);
    return number == 4;
}

// Function that checks the function that returns the value of the first element
bool testGetValue()
{
    List* newList = createList();
    Error error = NOT_ERROR;
    add(newList, "Hello", &error);
    add(newList, "World", &error);
    if (error == INSUFFICIENT_MEMORY)
    {
        deleteList(newList);
        return false;
    }
    Position* position = first(newList, &error);
    if (error == EMPTY_LIST)
    {
        deleteList(newList);
        return false;
    }
    const char* firstValue = getHeadValue(newList);
    const char* secondValue = getValue(next(position));
    bool result = strcmp(firstValue, "Hello") == 0 && strcmp(secondValue, "World") == 0;
    deleteList(newList);
    deletePosition(position);
    return result;
}

bool allTest()
{
    return testAdd() && testGetValue() && testNumberOfElements() && testRemoveHead();
}
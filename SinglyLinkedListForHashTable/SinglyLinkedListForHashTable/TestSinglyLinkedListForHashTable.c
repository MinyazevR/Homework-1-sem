#include "TestSinglyLinkedListForHashTable.h"
#include "SinglyLinkedListForHashTable.h"
#include <string.h>

// Function to check the function that adds an item to the list
bool testAdd()
{
    Error error = NOT_ERROR;
    List* newList = createList(&error);
    add(newList, "test", &error);
    const char* firstValue = getHeadValue(newList);
    add(newList, "list", &error);
    const char* secondValue = getHeadValue(newList);
    bool result = strcmp(firstValue, "test") == 0 && strcmp(secondValue, "list") == 0;
    deleteList(newList);
    return result;
}

// Function to check the function that deletes the first item in the list
bool testRemoveHead()
{
    Error error = NOT_ERROR;
    List* newList = createList(&error);
    add(newList, "Hello", &error);
    add(newList, "World", &error);
    removeFirstElement(newList, &error);
    if (error == EMPTY_LIST || error == INSUFFICIENT_MEMORY)
    {
        deleteList(newList);
        return false;
    }
    const char* value = getHeadValue(newList);
    bool result = strcmp(value, "Hello") == 0;
    deleteList(newList);
    return result;
}

// Function for checking the function counting the number of elements
bool testNumberOfElements()
{
    Error error = NOT_ERROR;
    List* newList = createList(&error);
    add(newList, "Hello", &error);
    add(newList, "Merge", &error);
    add(newList, "test", &error);
    add(newList, "list", &error);
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
    Error error = NOT_ERROR;
    List* newList = createList(&error);
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
    bool result = strcmp(firstValue, "World") == 0 && strcmp(secondValue, "Hello") == 0;
    deleteList(newList);
    deletePosition(position);
    return result;
}

bool allTest()
{
    return testAdd() && testRemoveHead() && testNumberOfElements() && testGetValue();
}
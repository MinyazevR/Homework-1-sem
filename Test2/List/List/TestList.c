#include "TestList.h"
#include "List.h"
#include <string.h>

// Function to check the function that adds an item to the list
bool testAdd()
{
    Error error = NOT_ERROR;
    List* newList = createList();
    add(newList, 12, &error);
    add(newList, -23, &error);
    if (error == INSUFFICIENT_MEMORY)
    {
        deleteList(newList);
        return false;
    }
    const int firstValue = getHeadValue(newList);
    Position* position = first(newList, &error);
    if (error == EMPTY_LIST)
    {
        deleteList(newList);
        return false;
    }
    next(position);
    const int secondValue = getValue(position);
    bool result = firstValue == 12 && secondValue == -23;
    deletePosition(position);
    deleteList(newList);
    return result;
}

// Function to check the function that deletes the first item in the list
bool testRemoveHead()
{
    Error error = NOT_ERROR;
    List* newList = createList();
    add(newList, 123, &error);
    add(newList, -34, &error);
    removeFirstElement(newList, &error);
    if (error == EMPTY_LIST || error == INSUFFICIENT_MEMORY)
    {
        deleteList(newList);
        return false;
    }
    const int headOfListValue = getHeadValue(newList);
    bool result = headOfListValue == -34;
    deleteList(newList);
    return result;
}

// Function for checking the function counting the number of elements
bool testNumberOfElements()
{
    List* newList = createList();
    Error error = NOT_ERROR;
    add(newList, 123, &error);
    add(newList, -32, &error);
    add(newList, 47, &error);
    add(newList, 24, &error);
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
    add(newList, 123, &error);
    add(newList, -44, &error);
    if (error == INSUFFICIENT_MEMORY)
    {
        deleteList(newList);
        return false;
    }
    const int firstValue = getHeadValue(newList);
    Position* position = first(newList, &error);
    if (error != NOT_ERROR)
    {
        return false;
    }
    const int secondValue = getValue(next(position));
    bool result = firstValue == 123 && secondValue == -44;
    deletePosition(position);
    deleteList(newList);
    return result;
}

bool allTest()
{
    return testAdd() && testGetValue() && testNumberOfElements() && testRemoveHead();
}
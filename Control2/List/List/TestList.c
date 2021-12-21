#include "TestList.h"
#include "List.h"
#include <string.h>

// Function to check the function that adds an item to the list
bool testAdd()
{
    Error error = NOT_ERROR;
    List* newList = createList(&error);
    add(newList, "12", &error);
    add(newList, "wddw", &error);
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
    next(position);
    const char* secondValue = getValue(position);
    bool result = strcmp(firstValue, "12") == 0 && strcmp(secondValue, "wddw") == 0;
    deletePosition(position);
    deleteList(newList);
    return result;
}

// Function to check the function that deletes the first item in the list
bool testRemoveHead()
{
    Error error = NOT_ERROR;
    List* newList = createList(&error);
    add(newList, "qwerty", &error);
    add(newList, "uiop", &error);
    removeFirstElement(newList, &error);
    if (error == EMPTY_LIST || error == INSUFFICIENT_MEMORY)
    {
        deleteList(newList);
        return false;
    }
    const char* headOfListValue = getHeadValue(newList);
    bool result = strcmp(headOfListValue, "uiop") == 0;
    deleteList(newList);
    return result;
}

// Function for checking the function counting the number of elements
bool testNumberOfElements()
{
    Error error = NOT_ERROR;
    List* newList = createList(&error);
    add(newList, "asd", &error);
    add(newList, "xcxz", &error);
    add(newList, "sfsf", &error);
    add(newList, "123", &error);
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
    add(newList, "dg", &error);
    add(newList, "hello", &error);
    if (error == INSUFFICIENT_MEMORY)
    {
        deleteList(newList);
        return false;
    }
    const char* firstValue = getHeadValue(newList);
    Position* position = first(newList, &error);
    if (error != NOT_ERROR)
    {
        return false;
    }
    const char* secondValue = getValue(next(position));
    bool result = strcmp(firstValue, "dg") == 0 && strcmp(secondValue, "hello") == 0;
    deletePosition(position);
    deleteList(newList);
    return result;
}

bool allTest()
{
    return testAdd() && testGetValue() && testNumberOfElements() && testRemoveHead();
}
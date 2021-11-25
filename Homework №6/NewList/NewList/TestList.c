#include "TestList.h"
#include "List.h"
#include <string.h>

// Function to check the function that adds an item to the list
bool testAdd()
{
    int error = 0;
    List* newList = createList();
    add(newList, "test", "¹ 1", &error);
    add(newList, "list", "add", &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    const char* firstStringFirstValue = getHeadFirstValue(newList);
    const char* firstStringSecondValue = getHeadSecondValue(newList);
    Position* position = first(newList, &error);
    next(position);
    const char* secondStringFirstValue = getFirstValue(position);
    const char* secondStringSecondValue = getSecondValue(position);
    bool result = strcmp(firstStringFirstValue, "test") == 0 && strcmp(firstStringSecondValue, "¹ 1") == 0
        && strcmp(secondStringFirstValue, "list") == 0 && strcmp(secondStringSecondValue, "add") == 0;
    deletePosition(position);
    deleteList(newList);
    return result;
}

// Function to check the function that deletes the first item in the list
bool testRemoveHead()
{
    int error = 0;
    List* newList = createList();
    add(newList, "Hello", "World", &error);
    add(newList, "Merge", "Sort", &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    removeFirstElement(newList, &error);
    if (error == 2)
    {
        deleteList(newList);
        return false;
    }
    const char* headOfListFirstValue = getHeadFirstValue(newList);
    const char* headOfListSecondValue = getHeadSecondValue(newList);
    bool result = strcmp(headOfListFirstValue, "Merge") == 0 && strcmp(headOfListSecondValue, "Sort") == 0;
    deleteList(newList);
    return result;
}

// Function for checking the function counting the number of elements
bool testNumberOfElements()
{
    List* newList = createList();
    int error = 0;
    add(newList, "Hello", "World", &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    add(newList, "Merge", "Sort", &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    add(newList, "test", "¹ 1", &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    add(newList, "list", "add", &error);
    if (error == 3)
    {
       deleteList(newList);
        return false;
    }
    const int number = numberOfElements(newList);
    deleteList(newList);
    return number == 4;
}

// Function that checks the function that returns the value of the first element
bool testGetHeadFirstAndSecondValue()
{
    List* newList = createList();
    int error = 0;
    add(newList, "Hello", "World", &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    add(newList, "Merge", "Sort", &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    const char* firstHeadValue = getHeadFirstValue(newList);
    const char* secondHeadValue = getHeadSecondValue(newList);
    bool result = strcmp(firstHeadValue, "Hello") == 0 && strcmp(secondHeadValue, "World") == 0;
    deleteList(newList);
    return result;
}

bool allTest()
{
    return testAdd() && testGetHeadFirstAndSecondValue() && testNumberOfElements() && testRemoveHead();
}
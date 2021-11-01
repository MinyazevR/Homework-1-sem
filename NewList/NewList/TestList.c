#include "TestList.h"
#include "List.h"
#include <string.h>

// Function to check the function that adds an item to the list
bool testAdd()
{
    int error = 0;
    List* newList = createList();
    add(newList, last(newList, &error), (int*)"test", (int*)"¹ 1", & error);
    add(newList, last(newList, &error), (int*)"list", (int*)"add", & error);
    if (error == 3)
    {
        return false;
    }
    const int* firstStringFirstValue = newList->head->firstValue;
    const int* firstStringSecondValue = newList->head->secondValue;
    const int* secondStringFirstValue = newList->head->next->firstValue;
    const int* secondStringSecondValue = newList->head->next->secondValue;
    deleteList(newList);
    return strcmp((char*)firstStringFirstValue, "test") == 0 && strcmp((char*)firstStringSecondValue, "¹ 1") == 0
    && strcmp((char*)secondStringFirstValue, "list") == 0 && strcmp((char*)secondStringSecondValue, "add") == 0;
}

// Function to check the function that deletes the first item in the list
bool testRemoveHead()
{
    int error = 0;
    List* newList = createList();
    add(newList, last(newList, &error), (int*)"Hello", (int*)"World", &error);
    add(newList, last(newList, &error), (int*)"Merge", (int*)"Sort", &error);
    if (error == 3)
    {
        return false;
    }
    removeFirstElement(newList, &error);
    if (error == 2)
    {
        return false;
    }
    const int* headOfListFirstValue = newList->head->firstValue;
    const int* headOfListSecondValue = newList->head->secondValue;
    deleteList(newList);
    return strcmp((char*)headOfListFirstValue, "Merge") == 0 && strcmp((char*)headOfListSecondValue, "Sort") == 0;
}

// Function for checking the function counting the number of elements
bool testNumberOfElements()
{
    List* newList = createList();
    int error = 0;
    add(newList, last(newList, &error), (int*)"Hello", (int*)"World", &error);
    if (error == 3)
    {
        return false;
    }
    add(newList, last(newList, &error), (int*)"Merge", (int*)"Sort", &error);
    if (error == 3)
    {
        return false;
    }
    add(newList, last(newList, &error), (int*)"test", (int*)"¹ 1", &error);
    if (error == 3)
    {
        return false;
    }
    add(newList, last(newList, &error), (int*)"list", (int*)"add", &error);
    if (error == 3)
    {
        return false;
    }
    const int number = numberOfElements(newList, &error);
    if (error == 3)
    {
        return false;
    }
    deleteList(newList);
    return number == 4;
}

// Function that checks the function that returns the value of the first element
bool testGetHeadFirstAndSecondValue()
{
    List* newList = createList();
    int error = 0;
    add(newList, last(newList, &error), (int*)"Hello", (int*)"World", &error);
    if (error == 3)
    {
        return false;
    }
    add(newList, last(newList, &error), (int*)"Merge", (int*)"Sort", &error);
    if (error == 3)
    {
        return false;
    }
    const int* firstHeadValue = getHeadFirstValue(newList);
    const int* secondHeadValue = getHeadSecondValue(newList);
    deleteList(newList);
    return strcmp((char*)firstHeadValue, "Hello") == 0 && strcmp((char*)secondHeadValue, "World") == 0;
}

bool allTest()
{
    return testAdd() && testNumberOfElements() && testRemoveHead() && testGetHeadFirstAndSecondValue();
}
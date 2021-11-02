#include "CyclicList.h"
#include "TestCyclicList.h"

// Function to check the function that adds an item to the list
bool testAdd()
{
    int error = 0;
    List* newList = createList();
    add(newList, 1, &error);
    add(newList, 123, &error);
    add(newList, 34, &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    const int firstNumber = newList->head->value;
    const int secondNumber = newList->head->next->value;
    const int thirdNumber = newList->head->next->next->value;
    deleteList(newList);
    return firstNumber == 1 && secondNumber == 123 && thirdNumber == 34;
}

// Function for checking a function that deletes a list item
bool testRemoveElement()
{
    int error = 0;
    List* newList = createList();
    add(newList, 10, &error);
    add(newList, 20, &error);
    add(newList, 30, &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    Position* position = first(newList, &error);
    next(position);
    removeElement(newList, position, &error);
    if (error == 1)
    {
        deleteList(newList);
        return false;
    }
    const int firstNumber = newList->head->value;
    const int secondNumber = newList->head->next->value;
    deleteList(newList);
    return firstNumber == 10 && secondNumber == 30;
}

bool allTest()
{
    return testRemoveElement() && testAdd();
}
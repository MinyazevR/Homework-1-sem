#include "TestList.h"
#include "List.h"

// Function to check the function that adds an item to the list
bool testAdd()
{
    int error = 0;
    List* newList = createList();
    add(newList, 20, &error);
    add(newList, 30, &error);
    add(newList, 10, &error);
    add(newList, 40, &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    Position* position = first(newList, &error);
    const int firstNumberValue = get(newList, position, &error);
    if (error == 6)
    {
        freePosition(position);
        deleteList(newList);
        return false;
    }
    const int secondNumberValue = get(newList, next(position), &error);
    if (error == 6)
    {
        freePosition(position);
        deleteList(newList);
        return false;
    }
    const int thirdNumberValue = get(newList, next(position), &error);
    if (error == 6)
    {
        freePosition(position);
        deleteList(newList);
        return false;
    }
    const int fourthNumberValue = get(newList, next(position), &error);
    if (error == 6)
    {
        freePosition(position);
        deleteList(newList);
        return false;
    }
    freePosition(position);
    deleteList(newList);
    return firstNumberValue == 10 && secondNumberValue == 20 && thirdNumberValue == 30 && fourthNumberValue == 40;
}

// Function to check the function that deletes the first item in the list
bool testRemoveHead()
{
    int error = 0;
    List* newList = createList();
    add(newList, 10, &error);
    add(newList, 20, &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    removeElement(findPosition(10, newList, &error),newList);
    if (error == 6 || error == 3)
    {
        deleteList(newList);
        return false;
    }
    Position* position = first(newList, &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    const int firstNumberValue = get(newList, position, &error);
    if (error == 6)
    {
        freePosition(position);
        deleteList(newList);
        return false;
    }
    freePosition(position);
    deleteList(newList);
    return firstNumberValue == 20;
}

// Function to check the function that deletes the last item in the list
bool testRemoveTail()
{
    int error = 0;
    List* newList = createList();
    add(newList, 10, &error);
    add(newList, 20, &error);
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    Position* position = first(newList, &error);
    const int firstNumberValue = get(newList, position, &error);
    if (error == 6)
    {
        freePosition(position);
        deleteList(newList);
        return false;
    }
    removeElement(findPosition(20, newList, &error), newList);
    if (error == 6 || error == 3)
    {
        deleteList(newList);
        return false;
    }
    // At this point, error becomes equal to 6, since a non - existent element (it has been deleted)
    const int secondNumberValue = get(newList, next(position), &error);
    freePosition(position);
    deleteList(newList);
    return firstNumberValue == 10 && secondNumberValue == 0 && error == 6;
}

// A function for checking a function that deletes any list item except the first one
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
    removeElement(findPosition(20, newList, &error), newList);
    if (error == 2)
    {
        deleteList(newList);
        return false;
    }
    if (error == 3 || error == 1 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    Position* position = first(newList, &error);
    const int firstNumberValue = get(newList, position, &error);
    if (error == 5)
    {
        freePosition(position);
        deleteList(newList);
        return false;
    }
    const int secondNumberValue = get(newList, next(position), &error);
    if (error == 5)
    {
        freePosition(position);
        deleteList(newList);
        return false;
    }
    freePosition(position);
    deleteList(newList);
    return firstNumberValue == 10 && secondNumberValue == 30;
}

// Function to check the function that finds the positions of the list items
bool testFindPosition()
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
    int firstElementValue = get(newList, findPosition(10, newList, &error), &error);
    if (error == 3 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    int secondElementValue = get(newList, findPosition(20, newList, &error), &error);
    if (error == 3 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    int thirdElementValue = get(newList, findPosition(30, newList, &error), &error);
    if (error == 3 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    deleteList(newList);
    return firstElementValue == 10
        && secondElementValue == 20
        && thirdElementValue == 30;
}

bool allTest()
{
    return testAdd() && testRemoveElement() && testRemoveHead() && testRemoveTail() && testFindPosition();
}
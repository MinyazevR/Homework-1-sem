#include "TestList.h"
#include "List.h"

// Function to check the function that adds an item to the list
bool testAdd()
{
    Error error = NOT_ERROR;
    List* newList = createList();
    add(newList, 20, &error);
    add(newList, 30, &error);
    add(newList, 10, &error);
    add(newList, 40, &error);
    if (error != NOT_ERROR)
    {
        deleteList(newList);
        return false;
    }
    Position* position = first(newList, &error);
    const int firstNumberValue = get(newList, position, &error);
    const int secondNumberValue = get(newList, next(position), &error);
    const int thirdNumberValue = get(newList, next(position), &error);
    const int fourthNumberValue = get(newList, next(position), &error);
    if (error != NOT_ERROR)
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
    Error error = NOT_ERROR;
    List* newList = createList();
    add(newList, 10, &error);
    add(newList, 20, &error);
    if (error != NOT_ERROR)
    {
        deleteList(newList);
        return false;
    }
    removeElement(findPosition(10, newList, &error),newList);
    Position* position = first(newList, &error);
    const int firstNumberValue = get(newList, position, &error);
    if (error != NOT_ERROR)
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
    Error error = NOT_ERROR;
    List* newList = createList();
    add(newList, 10, &error);
    add(newList, 20, &error);
    if (error != NOT_ERROR)
    {
        deleteList(newList);
        return false;
    }
    Position* position = first(newList, &error);
    const int firstNumberValue = get(newList, position, &error);
    removeElement(findPosition(20, newList, &error), newList);
    if (error != NOT_ERROR)
    {
        deleteList(newList);
        return false;
    }
    // At this point, error becomes equal to ELEMENT_IS_MISSING, since a non - existent element (it has been deleted)
    const int secondNumberValue = get(newList, next(position), &error);
    freePosition(position);
    deleteList(newList);
    return firstNumberValue == 10 && secondNumberValue == 0 && error == ELEMENT_IS_MISSING;
}

// A function for checking a function that deletes any list item except the first one
bool testRemoveElement()
{
    Error error = NOT_ERROR;
    List* newList = createList();
    add(newList, 10, &error);
    add(newList, 20, &error);
    add(newList, 30, &error);
    if (error != NOT_ERROR)
    {
        deleteList(newList);
        return false;
    }
    removeElement(findPosition(20, newList, &error), newList);
    Position* position = first(newList, &error);
    const int firstNumberValue = get(newList, position, &error);
    const int secondNumberValue = get(newList, next(position), &error);
    if (error != NOT_ERROR)
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
    Error error = NOT_ERROR;
    List* newList = createList();
    add(newList, 10, &error);
    add(newList, 20, &error);  
    add(newList, 30, &error);
    if (error != NOT_ERROR)
    {
        deleteList(newList);
        return false;
    }
    Position* firstElementPosition = findPosition(10, newList, &error);
    int firstElementValue = get(newList, firstElementPosition, &error);
    if (error != NOT_ERROR)
    {
        freePosition(firstElementPosition);
        deleteList(newList);
        return false;
    }
    freePosition(firstElementPosition);

    Position* secondElementPosition = findPosition(20, newList, &error);
    int secondElementValue = get(newList, secondElementPosition, &error);
    if (error != NOT_ERROR)
    {
        freePosition(secondElementPosition);
        deleteList(newList);
        return false;
    }
    freePosition(secondElementPosition);

    Position* thirdElementPosition = findPosition(30, newList, &error);
    int thirdElementValue = get(newList, thirdElementPosition, &error);
    if (error != NOT_ERROR)
    {
        freePosition(thirdElementPosition);
        deleteList(newList);
        return false;
    }
    freePosition(thirdElementPosition);
    deleteList(newList);
    return firstElementValue == 10
        && secondElementValue == 20
        && thirdElementValue == 30;
}

bool allTest()
{
    return testAdd() && testRemoveElement() && testRemoveHead() && testRemoveTail();
}
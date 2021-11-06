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
    if (error == 3)
    {
        deleteList(newList);
        return false;
    }
    Position* position = first(newList);
    const int firstNumberValue = get(newList, position, &error);
    if (error == 5)
    {
        deleteList(newList);
        return false;
    }
    const int secondNumberValue = get(newList, next(position), &error);
    if (error == 5)
    {
        deleteList(newList);
        return false;
    }
    const int thirdNumberValue = get(newList, next(position), &error);
    if (error == 5)
    {
        deleteList(newList);
        return false;
    }
    deleteList(newList);
    return firstNumberValue == 10 && secondNumberValue == 20 && thirdNumberValue == 30;
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
    removeFirstElement(newList, &error);
    if (error == 2)
    {
        deleteList(newList);
        return false;
    }
    Position* position = first(newList);
    const int firstNumberValue = get(newList, position, &error);
    if (error == 5)
    {
        deleteList(newList);
        return false;
    }
    deleteList(newList);
    return firstNumberValue == 20;
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
    removeElement(findPosition(20, newList, &error), newList, &error);
    if (error == 3 || error == 1 || error == 6)
    {
        deleteList(newList);
        return false;
    }

    Position* position = first(newList);
    const int firstNumberValue = get(newList, position, &error);
    const int secondNumberValue = get(newList, next(position), &error);

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
    Position* firstElementPosition = findPosition(10, newList, &error);
    if (error == 3 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    Position* secondElementPosition = findPosition(20, newList, &error);
    if (error == 3 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    Position* thirdElementPosition = findPosition(30, newList, &error);
    if (error == 3 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    Position* firstPosition = first(newList);
    Position* checkSecondPosition = firstPosition;
    Position* checkFirstPosition = firstPosition;
    Position* checkThirdPosition = next(firstPosition);
    deleteList(newList);
    return checkThirdPosition == thirdElementPosition
        && checkSecondPosition == secondElementPosition
        && checkFirstPosition == firstElementPosition;
}

bool allTest()
{
    return testAdd() &&  testRemoveHead() && testRemoveElement() && testFindPosition();
}
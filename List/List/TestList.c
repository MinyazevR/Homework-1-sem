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
    ListElement* firstElement = first(newList);
    const int firstNumberValue = get(newList, firstElement, &error);
    if (error == 5)
    {
        deleteList(newList);
        return false;
    }
    const int secondNumberValue = get(newList, next(firstElement), &error);
    if (error == 5)
    {
        deleteList(newList);
        return false;
    }
    const int thirdNumberValue = get(newList, next(next(firstElement)), &error);
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
    const int lastFirstOrdinaryNumber = findOrdinalNumberOfElementByValue(newList, 10);
    const int newFirstOrdinaryNumber = findOrdinalNumberOfElementByValue(newList, 20);
    const int firstNumberValue = get(newList, first(newList), &error);
    if (error == 5)
    {
        deleteList(newList);
        return false;
    }
    deleteList(newList);
    return newFirstOrdinaryNumber == 1 && lastFirstOrdinaryNumber == 0 && firstNumberValue == 20;
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
    const int firstOrdinaryNumber = findOrdinalNumberOfElementByValue(newList, 10);
    const int secondOrdinaryNumber = findOrdinalNumberOfElementByValue(newList, 20);
    const int thirdOrdinaryNumber = findOrdinalNumberOfElementByValue(newList, 30);

    ListElement* firstElement = first(newList);
    const int firstNumberValue = get(newList, firstElement, &error);
    const int secondNumberValue = get(newList, next(firstElement), &error);

    deleteList(newList);
    return firstOrdinaryNumber == 1 && thirdOrdinaryNumber == 2 && secondOrdinaryNumber == 0
        && firstNumberValue == 10 && secondNumberValue == 30;
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
    ListElement* firstElementPosition = findPosition(10, newList, &error);
    if (error == 3 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    ListElement* secondElementPosition = findPosition(20, newList, &error);
    if (error == 3 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    ListElement* thirdElementPosition = findPosition(30, newList, &error);
    if (error == 3 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    ListElement* firstPosition = first(newList);
    ListElement* checkThirdPosition = next(firstPosition);
    ListElement* checkSecondPosition = firstPosition;
    ListElement* checkFirstPosition = firstPosition;
    deleteList(newList);
    return checkThirdPosition == thirdElementPosition
        && checkSecondPosition == secondElementPosition
        && checkFirstPosition == firstElementPosition;
}

bool allTest()
{
    return testAdd() && testFindPosition() && testRemoveElement() && testRemoveHead();
}
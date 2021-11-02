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
    const int firstNumber = newList->head->value;
    const int secondNumber = newList->head->next->value;
    const int thirdNumber = newList->head->next->next->value;
    deleteList(newList);
    return firstNumber == 10 && secondNumber == 20 && thirdNumber == 30;
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
    if (error == 3 || error == 1)
    {
        deleteList(newList);
        return false;
    }
    const int headOfList = newList->head->value;
    deleteList(newList);
    return headOfList == 20;
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
    const int firstNumber = newList->head->value ;
    const int secondNumber = newList->head->next->value;
    deleteList(newList);
    return firstNumber == 10 && secondNumber == 30;
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
    ListElement* firstElementPositionPosition = findPosition(10, newList, &error);
    if (error == 3 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    ListElement* secondElementPositionPosition = findPosition(20, newList, &error);
    if (error == 3 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    ListElement* thirdElementPositionPosition = findPosition(30, newList, &error);
    if (error == 3 || error == 6)
    {
        deleteList(newList);
        return false;
    }
    ListElement* checkThirdPosition = newList->head->next;
    ListElement* checkSecondPosition = newList->head;
    ListElement* checkFirstPosition = newList->head;
    deleteList(newList);
    return  checkThirdPosition == thirdElementPositionPosition
    && checkSecondPosition == secondElementPositionPosition
    && checkFirstPosition == firstElementPositionPosition;
}

bool allTest()
{
    return testAdd() && testFindPosition() && testRemoveElement() && testRemoveHead();
}
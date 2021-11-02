#pragma once
#include <stdbool.h>
#include <malloc.h>

// A structure containing a pointer to the head of the list
typedef struct List
{
    struct ListElement* head;
} List;

// A structure containing a pointer to the next list item and a value variable for the list items
typedef struct ListElement
{
    int value;
    struct ListElement* next;
} ListElement;

// A structure containing a pointer to the position of a list item
typedef struct Position
{
    ListElement* position;
} Position;

// Function for creating a list
List* createList();

// Function for deleting a list
void deleteList(List* list);

// Function for deleting a position
void deletePosition(Position* position, int* error);

// Function for adding an item to a list
void add(List* list, int value, int* error);

// Function for the first position
Position* first(List* list, int* error);

// Function to remove an item from the list
void removeElement(ListElement* element, List* list, int* error);

// Function for moving to the next position
Position* next(Position* position);

// Function for finding the location of an item in the list 
// Actually returns the location of the item in front of it, in order for the delete function to work correctly
ListElement* findPosition(int value, List* list, int* error);

// Function for checking an item for being at the end of the list
bool last(Position* position);

// Function for finding an element by position
int get(List* list, Position* position, int* error);

// Function for printing a list
void print(List* list);

// Function for deleting the first element
void removeFirstElement(List* list, int* error);
#pragma once
#include <stdbool.h>
#include <malloc.h>

// A structure containing a pointer to the head of the list
typedef struct List List;

// A structure containing a pointer to the next list item and a value variable for the list items
typedef struct ListElement ListElement;

// Function for creating a list
List* createList();

// Function for deleting a list
void deleteList(List* list);

// Function for adding an item to a list
void add(List* list, int value, int* error);

// Function for the first position
ListElement* first(List* list);

// Function to remove an item from the list
void removeElement(ListElement* element, List* list, int* error);

// Function for moving to the next position
ListElement* next(ListElement* element);

// Function for finding the location of an item in the list 
// Actually returns the location of the item in front of it, in order for the delete function to work correctly
ListElement* findPosition(int value, List* list, int* error);

// Function for checking an item for being at the end of the list
bool last(ListElement* element);

// Function for finding an element by position
int get(List* list, ListElement* element, int* error);

// Function for printing a list
void print(List* list);

// Function for deleting the first element
void removeFirstElement(List* list, int* error);

int findOrdinalNumberOfElementByValue(List* list, int value);
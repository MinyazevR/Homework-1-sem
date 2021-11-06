#pragma once
#include <stdbool.h>
#include <malloc.h>

// Structure that represents cyclic list
typedef struct List List;

typedef struct Position Position;

// Function for creating a list
List* createList();

// Function for deleting a list
void deleteList(List* list);

// Function for adding an item to a list
void add(List* list, int value, int* error);

// Function for the first position
Position* first(List* list);

// Function to remove an item from the list
void removeElement(Position* position, List* list, int* error);

// Function for moving to the next position
Position* next(Position* position);

// Function for finding the location of an item in the list 
// Actually returns the location of the item in front of it, in order for the delete function to work correctly
Position* findPosition(int value, List* list, int* error);

// Function for checking an item for being at the end of the list
bool last(Position* position);

// Function for finding an element by position
int get(List* list, Position* element, int* error);

// Function for printing a list
void print(List* list);

// Function for deleting the first element
void removeFirstElement(List* list, int* error);
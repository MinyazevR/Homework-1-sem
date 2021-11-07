#pragma once

// Structure that represents list
typedef struct List List;

// Structure for implementing list
typedef struct Position Position;

// Function for creating a list
List* createList();

// Function for deleting a list
void deleteList(List* list);

// Function for adding an item to a list
void add(List* list, int value, int* error);

// Function for finding a pointer to the first element
Position* first(List* list, int* error);

// Function to remove an item from the list
void removeElement(Position* position, List* list);

// Function for finding a pointer to the next element
Position* next(Position* position);

// Function for finding a pointer to an element
Position* findPosition(int value, List* list, int* error);

// Function for finding an element
int get(List* list, Position*  position, int* error);

// Function for printing a list
void print(List* list);

// Function for finding a pointer to the previous element
Position* previous(Position* position);

// Function for freeing up memory
void freePosition(Position* position);
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

// Function for finding the position of the first item in the list
Position* first(List* list, int* error);

// Function to remove an item from the list
void removeElement(Position* position, List* list);

// Function to move to the position of the next list item
Position* next(Position* position);

//The function to find the position of an item in the list
Position* findPosition(int value, List* list, int* error);

// Function for finding an element by position
int get(List* list, Position*  position, int* error);

// Function for printing a list
void print(List* list);

//Function to move to the position of the previous list item
Position* previous(Position* position);

// Function for freeing up memory
void freePosition(Position* position);
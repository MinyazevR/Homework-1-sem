#pragma once
#include <stdbool.h>

// Structure for implementing a stack consisting of a value and a pointer to the next element
typedef struct Stack
{
    char value;
    struct Stack* next;
}Stack;

// Function for test empty stack
bool isEmpty(Stack* head);

// Function for adding an element to the top of the stack
void push(Stack** head, char element);

// Function to remove an element from the top of the stack that returns the value of that element
char pop(Stack** head, bool* check);

// Function for deleting all stack elements
void deleteStack(Stack** head);

// Function that returns the value of an element from the top of the stack
char top(Stack* head, bool* check);
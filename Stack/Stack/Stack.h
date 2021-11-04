#pragma once
#include <stdbool.h>

// Structure for implementing a stack consisting of a value and a pointer to the next element
typedef struct Stack
{
    int value;
    struct Stack* next;
} Stack;

// Function for testing if stack is empty. 
bool isEmpty(Stack* head);

// Function for adding an element to the top of the stack
void push(Stack** head, int element, int* error);

// Function to remove an element from the top of the stack that returns the value of that element
int pop(Stack** head, int* error);

// Function for deleting all stack elements
void deleteStack(Stack** head);

// Creating a stack
Stack* createStack();

// Function that returns the value of an element from the top of the stack
int top(Stack** head, int* error);

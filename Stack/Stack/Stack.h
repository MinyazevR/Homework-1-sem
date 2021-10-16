#pragma once

// Structure for implementing a stack consisting of a value and a pointer to the next element
typedef struct Stack
{
    int value;
    struct Stack* next;
}Stack;

// Function that checks the stack for emptiness
bool isEmpty(Stack* head);

// Function for adding an element to the top of the stack
void push(Stack** head, int element);

// Function to remove an element from the top of the stack that returns the value of that element
int pop(Stack** head);

// Function for deleting all stack elements
void deleteStack(Stack** head);
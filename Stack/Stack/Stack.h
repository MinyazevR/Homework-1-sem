#pragma once

typedef struct Stack
{
    int value;
    struct Stack* next;
}Stack;

bool isEmpty(Stack* head);

void push(Stack** head, int element);

int pop(Stack** head);

void deleteStack(Stack** head);
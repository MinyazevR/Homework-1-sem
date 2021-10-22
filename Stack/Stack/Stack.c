#include "Stack.h"
#include <stdio.h>
#include <malloc.h>

bool isEmpty(Stack* head)
{
    return head == NULL;
}

void push(Stack** head, int element)
{
    Stack* newStack = (Stack*)calloc(1, sizeof(Stack));
    if (newStack == NULL)
    {
        return;
    }
    newStack->value = element;
    newStack->next = *head;
    *head = newStack;
}

char pop(Stack** head, bool* err)
{
    if (*head != NULL)
    {
        char element = (*head)->value;
        Stack* temporary = *head;
        *head = (*head)->next;
        free(temporary);
        return element;
    }
    *err = false;
    return 0;
}

void deleteStack(Stack** head)
{
    bool err = true;
    while (!isEmpty(*head))
    {
        pop(head, &err);
    }
}

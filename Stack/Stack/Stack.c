#include "Stack.h"
#include <malloc.h>

bool isEmpty(Stack* head)
{
    return head == NULL;
}

void push(Stack** head, char element)
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

char pop(Stack** head, int* error)
{
    *error = 0;
    if (*head != NULL)
    {
        const char element = (*head)->value;
        Stack* temporary = *head;
        *head = (*head)->next;
        free(temporary);
        return element;
    }
    *error = 1;
    return 0;
}

void deleteStack(Stack** head)
{
    int error = 0;
    while (!isEmpty(*head))
    {
        pop(head, &error);
    }
}

char top(Stack** head, int* error)
{
    *error =  0;
    if (!isEmpty(*head))
    {
        return (*head)->value;
    }
    *error = 1;
    return 0;
}

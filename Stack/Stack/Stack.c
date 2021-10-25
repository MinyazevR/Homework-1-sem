#include "Stack.h"
#include <malloc.h>

bool isEmpty(Stack* head)
{
    return head == NULL;
}

Stack* createStack()
{
    return NULL;
}

void push(Stack** head, int element, int* error)
{
    *error = 0;
    Stack* newStack = (Stack*)calloc(1, sizeof(Stack));
    if (newStack == NULL)
    {
        *error = 2;
        return;
    }
    newStack->value = element;
    newStack->next = *head;
    *head = newStack;
}

int pop(Stack** head, int* error)
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

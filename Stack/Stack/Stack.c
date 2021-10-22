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

int pop(Stack** head, errno_t err)
{
    if (*head != NULL)
    {
        int element = (*head)->value;
        Stack* temporary = *head;
        *head = (*head)->next;
        free(temporary);
        return element;
    }
    errno_t err = 1;
    error(err);
    return 0;
}

void deleteStack(Stack** head)
{
    while (!isEmpty(*head))
    {
        pop(head);
    }
}

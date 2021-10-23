#include "Stack.h"
#include <malloc.h>
#include <errno.h>

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

int pop(Stack** head)
{
    errno = 0;
    if (*head != NULL)
    {
        const int element = (*head)->value;
        Stack* temporary = *head;
        *head = (*head)->next;
        free(temporary);
        return element;
    }
    errno = 1;
    return 0;
}

void deleteStack(Stack** head)
{
    while (!isEmpty(*head))
    {
        pop(head);
    }
}

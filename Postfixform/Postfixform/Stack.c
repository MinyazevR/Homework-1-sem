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

int pop(Stack** head)
{
    int element = (*head) -> value;
    Stack* temporary = *head;
    Stack* help = (*head) -> next;
    free(temporary);
    *head = help;
    return element;
}

void deleteStack(Stack** head)
{
    while (!isEmpty(*head))
    {
        pop(head);
    }
}

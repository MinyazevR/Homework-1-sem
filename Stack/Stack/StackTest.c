#include "StackTest.h"
#include "Stack.h"
#include <stdio.h>

bool pushTest()
{
    Stack* head = NULL;
    push(&head, 12);
    float firstResult = head->value;
    push(&head, 128);
    float secondResult = head->value;
    deleteStack(&head);
    return firstResult == 12 && secondResult == 128;
}

bool popTest()
{
    Stack* head = NULL;
    push(&head, 12);
    push(&head, 128);
    push(&head, 147);
    int error = 0;
    float firstPopResult = pop(&head, &error);
    if (error == 1)
    {
        return false;
    }
    float firstUpperElement = head->value;
    float secondPopResult = pop(&head, &error);
    if (error == 1)
    {
        return false;
    }
    float secondUpperElement = head->value;
    deleteStack(&head);
    return firstPopResult == 147 && firstUpperElement == 128 && secondPopResult == 128 && secondUpperElement == 12;
}

bool deleteStackTest()
{
    Stack* head = NULL;
    push(&head, 12);
    push(&head, 128);
    push(&head, 147);
    deleteStack(&head);
    return head == NULL;
}
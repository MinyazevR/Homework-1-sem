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
    return firstResult == 12 && secondResult == 128;
}

bool popTest()
{
    Stack* head = NULL;
    push(&head, 12);
    push(&head, 128);
    push(&head, 147);
    float firstPopResult = pop(&head);
    float firstUpperElement = head->value;
    float secondPopResult = pop(&head);
    float secondUpperElement = head->value;
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
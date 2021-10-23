#include "StackTest.h"
#include "Stack.h"
#include <stdio.h>

bool pushTest()
{
    Stack* head = NULL;
    push(&head, 12);
    int firstResult = head->value;
    push(&head, 128);
    int secondResult = head->value;
    return firstResult == 12 && secondResult == 128;
}

bool popTest()
{
    Stack* head = NULL;
    push(&head, 12);
    push(&head, 128);
    push(&head, 147);
    int firstPopResult = pop(&head);
    int firstUpperElement = head->value;
    int secondPopResult = pop(&head);
    int secondUpperElement = head->value;
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
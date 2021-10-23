#include "StackTest.h"
#include "Stack.h"
#include <stdio.h>

bool pushTest()
{
    Stack* head = NULL;
    push(&head, '[');
    char firstResult = head->value;
    push(&head, ')');
    char secondResult = head->value;
    return firstResult == '[' && secondResult == ')';
}

bool popTest()
{
    bool err = true;
    Stack* head = NULL;
    push(&head, 'a');
    push(&head, '^');
    push(&head, '1');
    char firstPopResult = pop(&head, &err);
    char firstUpperElement = head->value;
    char secondPopResult = pop(&head, &err);
    char secondUpperElement = head->value;
    return firstPopResult == '1' && firstUpperElement == '^' && secondPopResult == '^' && secondUpperElement == 'a';
}

bool deleteStackTest()
{
    Stack* head = NULL;
    push(&head, 'a');
    push(&head, 'b');
    push(&head, 'c');
    deleteStack(&head);
    return head == NULL;
}
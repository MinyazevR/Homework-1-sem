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
    Stack* head = NULL;
    push(&head, 'a');
    push(&head, '^');
    push(&head, '1');
    char firstPopResult = pop(&head);
    char firstUpperElement = head->value;
    char secondPopResult = pop(&head);
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

bool topTest()
{
    Stack* head = NULL;
    push(&head, 'a');
    char firstTopResult = head->value;
    push(&head, '^');
    char secondTopResult = head->value;
    push(&head, '1');
    char thirdTopResult = head->value;
    return firstTopResult == 'a' && secondTopResult == '^' && thirdTopResult == '1';
}
#include "StackTest.h"
#include "Stack.h"
#include <stdio.h>

bool pushTest()
{
    Stack* head = NULL;
    push(&head, '[');
    const char firstResult = head->value;
    push(&head, ')');
    const char secondResult = head->value;
    deleteStack(&head);
    return firstResult == '[' && secondResult == ')';
}

bool popTest()
{
    Stack* head = NULL;
    push(&head, 'a');
    push(&head, '^');
    push(&head, '1');
    int error = 0;
    const char firstPopResult = pop(&head, &error);
    if (error == 1)
    {
        return false;
    }
    const char firstUpperElement = head->value;
    const char secondPopResult = pop(&head, &error);
    if (error == 1)
    {
        return false;
    }
    const char secondUpperElement = head->value;
    deleteStack(&head);
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
    int error = 0;
    const char firstTopResult = top(&head, &error);
    if (error == 1)
    {
        return false;
    }
    push(&head, '^');
    const char secondTopResult = top(&head, &error);
    if (error == 1)
    {
        return false;
    }
    push(&head, '1');
    const char thirdTopResult = top(&head, &error);
    if (error == 1)
    {
        return false;
    }
    deleteStack(&head);
    return firstTopResult == 'a' && secondTopResult == '^' && thirdTopResult == '1';
}
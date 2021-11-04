#include "StackTest.h"
#include "Stack.h"
#include <stdio.h>

bool pushTest()
{
    Stack* head = createStack();
    int error = 0;
    push(&head, '[', &error);
    if (error == 2)
    {
        deleteStack(&head);
        return false;
    }
    const int firstResult = head->value;
    push(&head, ')', &error);
    if (error == 2)
    {
        deleteStack(&head);
        return false;
    }
    const int secondResult = head->value;
    deleteStack(&head);
    return firstResult == '[' && secondResult == ')';
}

bool popTest()
{
    Stack* head = createStack();
    int error = 0;
    push(&head, 'a', &error);
    if (error == 2)
    {
        deleteStack(&head);
        return false;
    }
    push(&head, '^', &error);
    if (error == 2)
    {
        deleteStack(&head);
        return false;
    }
    push(&head, '1', &error);
    if (error == 2)
    {
        deleteStack(&head);
        return false;
    }
    const int firstPopResult = pop(&head, &error);
    if (error == 1)
    {
        deleteStack(&head);
        return false;
    }
    const int firstUpperElement = head->value;
    const int secondPopResult = pop(&head, &error);
    if (error == 1)
    {
        deleteStack(&head);
        return false;
    }
    const int secondUpperElement = head->value;
    deleteStack(&head);
    return firstPopResult == '1' && firstUpperElement == '^' && secondPopResult == '^' && secondUpperElement == 'a';
}

bool deleteStackTest()
{
    Stack* head = createStack();
    int error = 0;
    push(&head, 'a', &error);
    if (error == 2)
    {
        deleteStack(&head);
        return false;
    }
    push(&head, 'b', &error);
    if (error == 2)
    {
        deleteStack(&head);
        return false;
    }
    push(&head, 'c', &error);
    if (error == 2)
    {
        deleteStack(&head);
        return false;
    }
    deleteStack(&head);
    return head == NULL;
}

bool topTest()
{
    Stack* head = createStack();
    int error = 0;
    push(&head, 'a', &error);
    if (error == 2)
    {
        deleteStack(&head);
        return false;
    }
    const int firstTopResult = top(&head, &error);
    if (error == 1)
    {
        deleteStack(&head);
        return false;
    }
    push(&head, '^', &error);
    if (error == 2)
    {
        deleteStack(&head);
        return false;
    }
    const int secondTopResult = top(&head, &error);
    if (error == 1)
    {
        deleteStack(&head);
        return false;
    }
    push(&head, '1', &error);
    if (error == 2)
    {
        deleteStack(&head);
        return false;
    }
    const int thirdTopResult = top(&head, &error);
    if (error == 1)
    {
        deleteStack(&head);

        return false;
    }
    deleteStack(&head);
    return firstTopResult == 'a' && secondTopResult == '^' && thirdTopResult == '1';
}
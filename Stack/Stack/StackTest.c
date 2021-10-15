#include "StackTest.h"
#include "Stack.h"
#include <stdio.h>

bool pushTest()
{
    Stack* p = NULL;
    push(&p, 12);
    int firstResult = p->value;
    push(&p, 128);
    int secondResult = p->value;
    return firstResult == 12 && secondResult == 128;
}

bool popTest()
{
    Stack* p = NULL;
    push(&p, 12);
    push(&p, 128);
    push(&p, 147);
    int firstPopResult = pop(&p);
    int firstUpperElement = p -> value;
    int secondPopResult = pop(&p);
    int secondUpperElement = p->value;
    return firstPopResult == 147 && firstUpperElement == 128 && secondPopResult == 128 && secondUpperElement == 12;
}

bool deleteStackTest()
{
    Stack* p = NULL;
    push(&p, 12);
    push(&p, 128);
    push(&p, 147);
    deleteStack(&p);
    return p == NULL;
}
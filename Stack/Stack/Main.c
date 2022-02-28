#include "StackTest.h"
#include <stdio.h>

int main()
{
    if (!pushTest() || !popTest() || !deleteStackTest())
    {
        return -1;
    }
}
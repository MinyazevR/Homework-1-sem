#include <stdio.h>
#include "StackTest.h"

int main()
{
    if (!pushTest() || !popTest() || !deleteStackTest())
    {
        return -1;
    }
}
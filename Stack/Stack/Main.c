#include "StackTest.h"
#include <stdio.h>

int main()
{
    if (!pushTest() || !popTest() || !deleteStackTest())
    {
        printf("Test failed");
        return -1;
    }
}
#include "StackTest.h"
#include <stdio.h>

int main()
{
    if (!pushTest() || !popTest() || !deleteStackTest() || !topTest())
    {
        printf("Test failed");
        return -1;
    }
}
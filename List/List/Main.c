#include "TestList.h"
#include <stdio.h>

int main()
{
    if (!allTest())
    {
        printf("Test failed");
        return -1;
    }
    return 0;
}
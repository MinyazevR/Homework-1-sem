#include "TestList.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (!allTest())
    {
        printf("Test failed");
        return -1;
    }
    if (argc != 0)
    {
        return 0;
    }
}
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include "repeatingElements.h"
#include "test.h"

int main()
{
    FILE* file = NULL;
    errno_t err;
    err = fopen_s(&file, "qwerty.txt", "r");
    if (file == NULL || err == 1)
    {
        printf("file not found!");
        return -1;
    }
    fileInput(file);
}
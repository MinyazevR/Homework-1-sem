#include "Comments.h"
#include "testComments.h"
#include <stdio.h>

int main()
{
    if (!testComments())
    {
        printf("Test failed");
        return -1;
    }
    int error = 0;
    const char* data = readBytes("Comments.txt", &error);
    if (error == 1)
    {
        free(data);
        printf("File not found");
        return -1;
    }
    if (error == 2)
    {
        free(data);
        printf("Memory not allocated");
        return -1;
    }
    printf("all comments :");
    int i = 0;
    while (data[i] != '\0')
    {
        if (data[i] == ';')
        {
            printf("\n");
        }
        printf("%c", data[i]);
        i++;
    }
    free(data);
}
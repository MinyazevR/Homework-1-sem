#include "TestWorkWithFile.h"
#include "WorkWithFile.h"
#include "../../List/List/List.h"
#include <stdio.h>

int main()
{
    if (!testWorkWithFile())
    {
        return -1;
    }
    Error error = NOT_ERROR;
    int a = 4;
    int b = 10;
    List* firstList = readFile("File.txt", a, b);
    if (firstList == NULL)
    {
        return -1;
    }
    int writeResult = writeFile("Result.txt", firstList);
    if (writeResult == -2)
    {
        printf("could not open the file");
    }
    deleteList(firstList);
}
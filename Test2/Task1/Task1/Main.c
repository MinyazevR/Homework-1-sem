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
    // as a and b, you can take any numbers, 4 and 10 - just an example
    const int a = 4;
    const int b = 10;
    int check = 0;
    List* firstList = readFile("File.txt", a, b, &check);
    if (check != 0)
    {
        return -1;
    }
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
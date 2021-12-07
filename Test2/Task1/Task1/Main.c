#include "TestWorkWithFile.h"
#include "WorkWithFile.h"
#include "../../List/List/List.h"

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
    int writeResult = writeFile("Result.txt", firstList);
    if (writeResult == -2)
    {
        printf("could not open the file");
    }
    deleteList(firstList);
}
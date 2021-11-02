#include "testComments.h"
#include "Comments.h"

bool testComments()
{
    int error = 0;
    char* data = readBytes("Test.txt", &error);
    int i = 0;
    const char arrayOfSymbol[29] = ";helloworld;helloworld));kek";
    while (data[i] != '\0' && arrayOfSymbol[i] != '\0')
    {
        if (data[i] != arrayOfSymbol[i])
        {
            return false;
        }
        i++;
    }
    return true;
}
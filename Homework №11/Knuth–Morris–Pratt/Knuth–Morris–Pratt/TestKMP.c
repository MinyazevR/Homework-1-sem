#include "TestKMP.h"
#include "ReadFile.h"
#include "KMP.h"
#include <stdlib.h>

bool testKMP()
{
    int error = 0;
    char* string = readFile("Test.txt", &error);
    if (error != 0)
    {
        return false;
    }
    int* firstPrefix = findPrefix("dcdv", &error);
    if (error == 1)
    {
        free(string);
        return false;
    }
    int* secondPrefix = findPrefix("rfre", &error);
    if (error == 1)
    {
        free(firstPrefix);
        free(string);
        return false;
    }
    int* thirdPrefix = findPrefix("eewgeg", &error);
    if (error == 1)
    {
        free(secondPrefix);
        free(firstPrefix);
        free(string);
        return false;
    }
    const int firstResult = algorithmKMP(string, "dcdv", firstPrefix);
    const int secondResult = algorithmKMP(string, "rfre", secondPrefix);
    const int thirdResult = algorithmKMP(string, "eewgeg", thirdPrefix);
    free(thirdPrefix);
    free(secondPrefix);
    free(firstPrefix);
    free(string);
    return firstResult == 10 && secondResult == 289 && thirdResult == -1;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int asdasd(char* postfixEntry)
{
    int counter = 0;
    while (postfixEntry[counter] != '\0')
    {
        if (postfixEntry[counter] >= '0' && postfixEntry[counter] <= '9')
        {
            push()
        }
    }
}

int main()
{
    char postfixEntry[250] = '\0';
    printf("enter the expression in postfix form");
    gets(postfixEntry);
    asdasd(postfixEntry);
}
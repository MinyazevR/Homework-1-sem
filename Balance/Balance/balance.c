#include <stdio.h>

int main()
{
    char stringBrackets[100] = {'\0'};
    gets(stringBrackets);
    int counterBrakets = 0;
    int counterCycle = 0;

    while(counterBrakets >= 0 && stringBrackets[counterCycle] != '\0')
    { 
        // åif the bracket is opening, then we increase the counter value by 1
        if (stringBrackets[counterCycle] == '(')
        {
            counterBrakets++;
        }
        // otherwise, we reduce the counter value by 1
        else if (stringBrackets[counterCycle] == ')')
        {
            counterBrakets--;
        }
        counterCycle++;
    }

    if (counterBrakets == 0)
    {
        printf("The rule of nesting brackets is observed.");
    }
    else
    {
        printf("The rule of nesting brackets is not observed.");
    }
}
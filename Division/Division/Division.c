#include <stdio.h>
#include <stdlib.h>

void printQuotientDivision(int counter)
{
    printf("quotient of division = %d", counter);
}

int main()
{
    int a = 0;
    int b = 0;
    printf("enter dividend \n");
    const int firstScanfResultA = scanf_s("%d", &a);
    if (firstScanfResultA == 0)
    {
        printf("had to enter a number");
        return 0;
    }
    
    printf("enter the divisor\n");
    const int firstScanfResultB = scanf_s("%d", &b);
    if (!firstScanfResultB)
    {
        printf("had to enter a number");
        return 0;
    }
    
    if (b == 0)
    {
        printf("you can't divide by 0");
        return 0;
    }

    if (a == 0 && b!= 0)
    {
        printQuotientDivision(0);
        return 0;
    }

    if (a == b)
    {
        printQuotientDivision(1);
        return 0;
    }

    if (a == -b)
    {
        printQuotientDivision(-1);
        return 0;
    }

    int subtraction—ounter = 0;
    int absoluteValueA = abs(a);
    int absoluteValueB = abs(b);

    while (absoluteValueA - absoluteValueB > 0)
    {
        absoluteValueA -= absoluteValueB;
        subtraction—ounter++;
    }

    if (a > 0 && b < 0)
    {
        printQuotientDivision(-subtraction—ounter);
    }

    if (a < 0 && b > 0)
    {
        printQuotientDivision(-subtraction—ounter - 1);
    }

    if (a > 0 && b > 0)
    {
        printQuotientDivision(subtraction—ounter);
    }

    if (a < 0 && b < 0)
    {
        printQuotientDivision(subtraction—ounter + 1);
    }

    return 0;
}
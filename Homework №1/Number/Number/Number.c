#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    if (argc != 0)
    {
        return 0;
    }
    int number = 0;
    printf("Enter a positive integer\n");
    scanf_s("%d", &number);
    // if the number is non-positive, then it has no divisors
    if (number <= 0)
    {
        printf("It was necessary to enter a positive number");
        return 0;
    }
    // brute force for numbers from 1 to number
    for (int i = 1; i <= number; i++)
    {
        const int rootOfTheNumber = sqrt(i);
        // for each i, we are looking for divisors from 1 to sqrt(i)
        for (int j = 1; j <= rootOfTheNumber; j++)
        {
            // if a number from 1 to number has a divisor j that is not equal to 1, then this number is composite
            if (i % j == 0 && j != 1)
            {
                // since the number is composite, it makes no sense to look for its other divisors, exit the loop
                break;
            }
            // we continue until j is equal to the number floor(sqrt(i)) (in this case, the number is prime)
            if (j == floor(sqrt(i)))
            {
                printf("%d\n", i);
            }
        }
    }
}
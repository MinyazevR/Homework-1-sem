#include <stdio.h>
#include <stdbool.h>

int sequenceFibonacciIteration(int numberOfSequence)
{
    // checking for the correctness of the entered number
    if (numberOfSequence < 0)
    {
        return -1;
    }

    int firstElementSequenceOfFibonacci = 1;
    int secondElementSequenceOfFibonacci = 1;
    int thirdElementSequenceOfFibonacci = 0;

    for (int i = 0; i < numberOfSequence - 2; i++)
    {
        thirdElementSequenceOfFibonacci = firstElementSequenceOfFibonacci + secondElementSequenceOfFibonacci;
        firstElementSequenceOfFibonacci = secondElementSequenceOfFibonacci;
        secondElementSequenceOfFibonacci = thirdElementSequenceOfFibonacci;
    }

    if (numberOfSequence == 0)
    {
        return 0;
    }

    if (numberOfSequence > 0)
    {
        return secondElementSequenceOfFibonacci;
    }
}

int sequenceFibonacciRecursion(int numberOfSequence)
{
    // checking for the correctness of the entered number
    if (numberOfSequence < 0)
    {
        return -1;
    }

    if (numberOfSequence == 1)
    {
        return 1;
    }

    if (numberOfSequence == 0)
    {
        return 0;
    }

    return sequenceFibonacciRecursion(numberOfSequence - 1) + sequenceFibonacciRecursion(numberOfSequence - 2);
}

// function for checking the correctness of the program
bool testCorrectFibonacci()
{
    return sequenceFibonacciIteration(1) == 1 && sequenceFibonacciRecursion(1) == 1
    && sequenceFibonacciIteration(0) == 0 && sequenceFibonacciRecursion(0) == 0
    && sequenceFibonacciIteration(12) == 144 && sequenceFibonacciRecursion(12) == 144
    && sequenceFibonacciIteration(16) == 987
    && sequenceFibonacciRecursion(20) == 6765;
}

int main(int argc, char* argv[])
{
    if (!testCorrectFibonacci())
    {
        printf("Verification failed");
        return -1;
    }
    if (argc != 0)
    {
        return 0;
    }
    printf("Enter the number of the member of the Fibonacci sequence that you want to display on the screen\n");
    int numberOfSequence = 0;
    scanf_s("%d", &numberOfSequence);
    printf("Iterative version : %d\n", sequenceFibonacciIteration(numberOfSequence));
    printf("Recursive version : %d\n", sequenceFibonacciRecursion(numberOfSequence));
}
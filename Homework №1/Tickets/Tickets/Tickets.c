#include <stdio.h>

int main()
{   
    int numberSumsDigits[28] = { 0 };
    int totalAmountTickets = 0;

    // use the for loop to find the sums of digits in the first 3-ex positions 
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {

                // if the sum of digits i + j + k = n, then the number of sums with the value n is increased by one
                ++numberSumsDigits[i + j + k];
            }
        }
    }

    for (int i = 0; i < 28; i++)
    {   
        /* if there are p tickets on the first 3 positions for the sum i + j + k, the same number of tickets for the sum i + j + k
        in the last 3 positions. As a result, for each sum, there are p ^ 2 such tickets */
        numberSumsDigits[i] *= numberSumsDigits[i];
        totalAmountTickets += numberSumsDigits[i];
    }

    printf("number of tickets = %d", totalAmountTickets);
    return 0;
}
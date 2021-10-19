#include "Palindrome.h"
#include "PalindromeTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int palindrom(char* stringToCheckForPalindrome)
{
    int noSpaces—ounter = 0;
    int counter = 0;
    while (stringToCheckForPalindrome[counter] != '\0')
    {
        if (stringToCheckForPalindrome[counter] != ' ')
        {
            noSpaces—ounter++;
        }
        counter++;
    }
    char* arrayForPalindromeWithoutSpaces = (char*)calloc((noSpaces—ounter), sizeof(char));
    if (arrayForPalindromeWithoutSpaces == NULL)
    {
        return -1;
    }
    counter = 0;
    int j = 0;
    while (stringToCheckForPalindrome[counter] != '\0' && j < noSpaces—ounter)
    {
        if (stringToCheckForPalindrome[counter] != ' ')
        {
            arrayForPalindromeWithoutSpaces[j] = stringToCheckForPalindrome[counter];
            j++;
        }
        counter++;
    }
    char* copyArrayForPalindromeWithoutSpaces = (char*)calloc((noSpaces—ounter), sizeof(char));
    if (copyArrayForPalindromeWithoutSpaces == NULL)
    {
        free(arrayForPalindromeWithoutSpaces);
        return -1;
    }
    for (int i = 0; i < noSpaces—ounter; i++)
    {
        copyArrayForPalindromeWithoutSpaces[i] = arrayForPalindromeWithoutSpaces[i];
    }
    for (int i = 0; i < noSpaces—ounter / 2; i++)
    {
        const int temporary = arrayForPalindromeWithoutSpaces[i];
        arrayForPalindromeWithoutSpaces[i] = arrayForPalindromeWithoutSpaces[noSpaces—ounter - 1 - i];
        arrayForPalindromeWithoutSpaces[noSpaces—ounter - 1 - i] = temporary;
    }
    for (int i = 0; i < noSpaces—ounter; i++)
    {
        if (copyArrayForPalindromeWithoutSpaces[i] != arrayForPalindromeWithoutSpaces[i])
        {
            free(arrayForPalindromeWithoutSpaces);
            free(copyArrayForPalindromeWithoutSpaces);
            return 1;
        }
    }
    free(arrayForPalindromeWithoutSpaces);
    free(copyArrayForPalindromeWithoutSpaces);
    return 0;
}

int main()
{
    if (!palindromeTest())
    {
        printf("Test failed");
        return 0;
    }
    printf("enter the line\n");
    char stringToCheckForPalindrome[200] = { '\0' };
    scanf_s("%[^\n]s", stringToCheckForPalindrome, _countof(stringToCheckForPalindrome));
    int result = palindrom(stringToCheckForPalindrome);
    if (result == -1)
    {
        printf("Error");
        return 0;
    }
    else if (result == 1)
    {
        printf("the string is not a palindrome");
        return 0;
    }
    printf("string is a palindrome");
}
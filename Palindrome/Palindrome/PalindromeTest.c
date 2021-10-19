#include "PalindromeTest.h"
#include "Palindrome.h"

bool palindromeTest()
{
    char firstCorrectString[100] = "a roza upala na lapu azora";
    char secondCorrectString[100] = "NaGibAtOr 666 rOtAbiGaN";
    char thirdCorrectString[100] = "palindro m    o rdnilap";
    char firstIncorrectString[100] = "qwertyuiop";
    char secondInorrectString[100] = "Natan";
    char thirdIncorrectString[100] = "aszxxzzxzewf";
    return palindrom(firstCorrectString) == 0
        && palindrom(firstIncorrectString) == 1
        && palindrom(secondCorrectString) == 0
        && palindrom(secondInorrectString) == 1
        && palindrom(thirdCorrectString) == 0
        && palindrom(thirdIncorrectString) == 1;
}
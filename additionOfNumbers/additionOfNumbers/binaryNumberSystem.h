#pragma once

/* function for writing the digits of a number to an array.
The digits are the binary representation of the number numberToWrite is written to the array arrayOfNumber */
void writingDigitsToArray(int* arrayOfNumber, int numberToWrite);

// function for outputting the digits of a number in binary form
void outputtingNumberInBinaryNotation(int* arrayOfNumber);

// function for adding numbers in the binary number system
void additionOfDigitsOfTwoNumbers(int*arrayOfDigitsOfTheFirstNumber, int* arrayOfDigitsOfTheSecondNumber, int* arrayForWritingTheSumOfDigits);

// function to convert a number from binary to decimal
int convertNumberFromBinaryToDecimal(int* arrayForWritingTheSumOfDigits);
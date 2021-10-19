#pragma once

// Reading numbers smaller than a number(numberToCompare) from a file g.txt and writing these numbers to the data array
int readNumbersSmallerSelected(int* data, int numberToCompare, const char* filename);

// Output of numbers less than a given number to a file h.txt
int outputOfNumbers(int* data, int counter, const char* filename);
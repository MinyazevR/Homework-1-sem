#pragma once
#include <stdio.h>
#include <stdbool.h>

//function for sorting an array
void smartQSort(int* arrayOfNumber, int initialElement, int endElement);

//function for checking the sorting of an array
bool sortingCheck(int* arrayOfNumber, int numberOfElements);

// checking sorting operation
bool testCorrectQSort();

// check if binary search works
bool testCorrectBinarySearch();

// binary search function
int binarySearch(int* arrayOfNumber, int numberOfElements, int requiredNumber);


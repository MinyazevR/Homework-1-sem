#pragma once
#include <stdbool.h>

// function for sorting an array
void smartQSort(int* arrayOfNumber, int initialElement, int endElement);

// function for checking the sorting of an array
bool sortingCheck(int* arrayOfNumber, int numberOfElements);

// function for testing sorting QSort
bool testCorrectQSort();

// function for sorting by inserts
void sortByInserts(int* arrayOfNumber, int initialElement, int endElement);


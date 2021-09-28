#pragma once
#include <stdbool.h>
#include <stdio.h>

// function for sorting an array
void smartQSort(int* arrayOfNumber, int initialElement, int endElement);

// function for checking the sorting of an array
bool sortingCheck(int* arrayOfNumber, int numberOfElements);

// checking the sorting operation
bool testCorrectQSort();

// a function for finding the most frequently occurring element in an array
int searchMostCommonElementInArray(int* arrayOfNumber, int numberOfElements);

// function to check the operation of the function searchMostCommonElementInArray
bool testSearchMostCommonElement();

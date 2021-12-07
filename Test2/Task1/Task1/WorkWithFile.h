#pragma once
#include "../../List/List/List.h"

// Function for checking functions for working with a file
List* readFile(const char* filename, int a, int b);

// Function for writing to a file
int writeFile(const char* fileToWrite, List* list);
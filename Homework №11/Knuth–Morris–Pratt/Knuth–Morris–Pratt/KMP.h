#pragma once

// Function for finding the maximum matching suffix and prefix
int* findPrefix(char* substring, int* error);

// Function for searching for a substring in a string
int algorithmKMP(char* string, char* substring, int* prefix);
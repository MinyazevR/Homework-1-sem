#pragma once
#include "../../SinglyLinkedListForHashTable/SinglyLinkedListForHashTable/SinglyLinkedListForHashTable.h"

// Structure representing a hash table
typedef struct HashTable HashTable;

// Function for creating a hash table
HashTable* createTable(Error* error);

// Function for deleting a hash table
void deleteHashTable(HashTable* table);

// Function for adding an element to a hash table
void addElement(const char* string, HashTable* table, Error* error);

// Function for printing values
void printValue(HashTable* table);

// Function for checking the location of an element in the table
bool inTable(HashTable* table, char* string);

// Function for counting the number of duplicate items for a specific list
int countNumberOfDuplicateItemsForSpecificList(char* value, HashTable* table);
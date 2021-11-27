#pragma once
#include "../../SinglyLinkedListForHashTable/SinglyLinkedListForHashTable/SinglyLinkedListForHashTable.h"

typedef struct HashTable HashTable;

HashTable* createTable(Error* error);

void deleteHashTable(HashTable* table);

void addElement(const char* string, HashTable* table, Error* error);

void printValue(HashTable* table);

bool inTable(HashTable* table, char* string);
#pragma once

// Phonebook structure for storing names and phone numbers
typedef struct
{
    char number[20];
    char name[20];
} Phonebook;

// Function for adding an entry to the database of numbers
int addAnEntry(Phonebook* array, int* numberOfRecords, const char* name, const char* phoneNumber);

// Function for finding a name by phone number
char* findNameByNumber(Phonebook* array, const char* number, int numberOfRecords);

// Function for finding a phone number by name
char* findNumberByName(Phonebook* array, const char* name, int numberOfRecords);

// Function for displaying records on the screen
void outputAllEntries(Phonebook* array, int numberOfRecords);

// Function for filling the phone book returns the number of entries minus one(since the count starts from 0)
int readPhonebook(Phonebook* array, const char* fileName);

// Function for saving changes
int saveTheChanges(Phonebook* array, int numberOfRecords);


#pragma once

typedef struct
{
    char number[20];
    char name[20];
}Phonebook;

// Function for adding an entry to the database of numbers
int addAnEntry(Phonebook* array, int* numberOfRecords);

// Function for finding a name by phone number
char* findNameByNumber(Phonebook* array, char* number, int numberOfRecords);

// Function for finding a phone number by name
char* findNumberByName(Phonebook* array, char* name, int numberOfRecords);

// Function for output of records to the console
void outputAllEntries(Phonebook* array, int numberOfRecords);

// Function for counting records
int recordsCounter(Phonebook* array, const char* fileName);

// Function for saving changes
int saveTheChanges(Phonebook* array, int numberOfRecords);


#include <stdio.h>
#include <malloc.h>

char* readFile(const char* filename, int* error)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        *error = 2;
        return NULL;
    }
    int counter = 0;
    char temporary = '\0';
    while (!feof(file))
    {
        if (fscanf(file, "%c", &temporary) != EOF)
        {
            counter++;
        }
    }
    fseek(file, 0L, SEEK_SET);
    char* string = calloc(counter + 1, sizeof(char));
    if (string == NULL)
    {
        *error = 1;
        return NULL;
    }
    int newCounter = 0;
    while (!feof(file) && newCounter < counter)
    {
        if (fscanf(file, "%c", &temporary) != EOF)
        {
                string[newCounter] = temporary;
                newCounter++;
        }
    }
    string[newCounter] = '\0';
    fclose(file);
    return string;
}
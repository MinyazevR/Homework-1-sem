#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include"repeatingElements.h"

void fileInput(FILE* file)
{
    int counter = 0;
    char buffer = 0;
    char array[100] = { '\0' };
    while (!feof(file))
    {
        const int readBytes = fscanf_s(file, "%c", &buffer, 1);
        if (readBytes < 0)
        {
            break;
        }
        array[counter] = buffer;
        counter++;
    }
    fclose(file);
    int k = 0;
    int i = 0;
    while (array[i] != '\0')
    {
        const int temporary = array[i];
        const int temp = i;
        printf("%c", array[i]);
        for (int j = 1; j <= counter - temp; j++)
        {
            if (temporary == array[j + temp])
            {
                i++;
            }
            else
            {
                i++;
                break;
            }
        }
    }
}
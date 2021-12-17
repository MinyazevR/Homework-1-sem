#include "LexicalAnalysis.h"
#include <string.h>

bool isDigit(char symbol)
{
    return symbol <= '9' && symbol >= '0';
}

bool checkExpression(char* string)
{
    const int lenghtString = strlen(string);
    int state = 0;
    for (int i = 0; i < lenghtString + 1; i++)
    {
        switch (state)
        {
        case 0 :
        {
            if (isDigit(string[i]))
            {
                state = 1;
                break;
            }
            return false;
        }
        case 1:
        {
            if (isDigit(string[i]))
            {
                break;
            }
            if (string[i] == '\0')
            {
                return true;
            }
            if (string[i] == '.')
            {
                state = 2;
                break;
            }
            return false;
        }
        case 2:
        {
            if (isDigit(string[i]))
            {
                state = 3;
                break;
            }
            return false;
        }
        case 3:
        {
            if (isDigit(string[i]))
            {
                break;
            }
            if (string[i] == '\0')
            {
                return true;
            }
            if (string[i] == 'E')
            {
                state = 4;
                break;
            }
            return false;
        }
        case 4:
        {
            if(isDigit(string[i]))
            {
                state = 6;
                break;
            }
            if (string[i] == '+' || string[i] == '-')
            {
                state = 5;
                break;
            }
            return false;
        }
        case 5:
        {
            if (isDigit(string[i]))
            {
                state = 6;
                break;
            }
            return false;
        }
        case 6:
        {
            if (isDigit(string[i]))
            {
                break;
            }
            if (string[i] == '\0')
            {
                return true;
            }
            return false;
        }
        }
    }
    return false;
}
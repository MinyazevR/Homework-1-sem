#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(int argc, char* argv[])
{
    if (argc != 0)
    {
        return 0;
    }
    setlocale(LC_ALL, "Rus");
    int matchingSymbolsCount = 0;
    int occurrencesCount = 0;
    char s[100] = {'\0'};
    char s1[100] = {'\0'};
    printf("Введите строку S ");
    gets(s);
    printf("Введите строку S1 ");
    gets(s1);
    // размер строки S
    const int lineLengthS = strlen(s);
    // размер строки S1
    const int lineLengthS1 = strlen(s1);

    // случай когда размер S1 > S
    if (lineLengthS / lineLengthS1 < 1)
    {
        printf("Число вхождений s1 как подстроки = 0");
        return 0;
    }
	
    for (int i = 0; i < lineLengthS - lineLengthS1 + 1; i++)
    {
        // если символ из строки S совпадает с первым символом из S1
        if (s[i] == s1[0])
        {
            // то проверяем на совпадение остальные символы
            for (int l = 0; l <= lineLengthS1 - 1; l++)
            {
                if (s[i + l] == s1[l])
                {
                    // счетчик количества подряд идущих совпавших символов
                    matchingSymbolsCount++;

                    // если количество подряд идущих совпавших символов равняется длинне S1,то количество вхождений увеличивается на 1
                    if (matchingSymbolsCount == lineLengthS1)
                    {
                        occurrencesCount++;
                        matchingSymbolsCount = 0;
                    }
                }
                else
                {
                     break;
                }
            }
        }
    }
    printf("Число вхождений S1 как подстроки = %d", occurrencesCount);
    return 0;
}
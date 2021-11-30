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
    printf("������� ������ S ");
    gets(s);
    printf("������� ������ S1 ");
    gets(s1);
    // ������ ������ S
    const int lineLengthS = strlen(s);
    // ������ ������ S1
    const int lineLengthS1 = strlen(s1);

    // ������ ����� ������ S1 > S
    if (lineLengthS / lineLengthS1 < 1)
    {
        printf("����� ��������� s1 ��� ��������� = 0");
        return 0;
    }
	
    for (int i = 0; i < lineLengthS - lineLengthS1 + 1; i++)
    {
        // ���� ������ �� ������ S ��������� � ������ �������� �� S1
        if (s[i] == s1[0])
        {
            // �� ��������� �� ���������� ��������� �������
            for (int l = 0; l <= lineLengthS1 - 1; l++)
            {
                if (s[i + l] == s1[l])
                {
                    // ������� ���������� ������ ������ ��������� ��������
                    matchingSymbolsCount++;

                    // ���� ���������� ������ ������ ��������� �������� ��������� ������ S1,�� ���������� ��������� ������������� �� 1
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
    printf("����� ��������� S1 ��� ��������� = %d", occurrencesCount);
    return 0;
}
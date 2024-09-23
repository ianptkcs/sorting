#include "sort.h"
#include <string.h>

/* Função para trocar duas strings */
void swapStrings(char *a, char *b)
{
    StringLine temp;
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

/* Algoritmo Bubble Sort */
void bubbleSort(StringLine *lines, int n, int &compareStringsCount)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compareStrings(lines[j], lines[j + 1], compareStringsCount) > 0)
            {
                swapStrings(lines[j], lines[j + 1]);
            }
        }
    }
}
#include "sort.h"
#include <stdio.h>
#include <string.h>

#define MAX 50000000

/* Função principal do Merge Sort */
void mergeSort_static(StringLine *lines, int left, int right, int &compareStringsCount)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort_static(lines, left, middle, compareStringsCount);
        mergeSort_static(lines, middle + 1, right, compareStringsCount);

        merge_static(lines, left, middle, right, compareStringsCount);
    }
}

/* Função para mesclar dois subarrays no Merge Sort */
void merge_static(StringLine *lines, int left, int middle, int right, int &compareStringsCount)
{
    static StringLine temp[MAX]; // Vetor temporário estático

    int i = left;       // Índice para percorrer o subarray da esquerda
    int j = middle + 1; // Índice para percorrer o subarray da direita
    int k = left;       // Índice para o vetor temporário

    // Mesclar os subarrays em temp[]
    while (i <= middle && j <= right)
    {
        if (compareStrings(lines[i], lines[j], compareStringsCount) <= 0)
        {
            strcpy(temp[k], lines[i]);
            i++;
        }
        else
        {
            strcpy(temp[k], lines[j]);
            j++;
        }
        k++;
    }

    // Copiar o restante do subarray da esquerda, se houver
    while (i <= middle)
    {
        strcpy(temp[k], lines[i]);
        i++;
        k++;
    }

    // Copiar o restante do subarray da direita, se houver
    while (j <= right)
    {
        strcpy(temp[k], lines[j]);
        j++;
        k++;
    }

    // Copiar o vetor temporário de volta para o original
    for (i = left; i <= right; i++)
    {
        strcpy(lines[i], temp[i]);
    }
}

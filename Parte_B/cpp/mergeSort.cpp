#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeSort(StringLine *lines, int left, int right, int &compareStringsCount);
void merge(StringLine *lines, int left, int middle, int right, int &compareStringsCount);

void mergeSort(StringLine *lines, int left, int right, int &compareStringsCount)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(lines, left, middle, compareStringsCount);
        mergeSort(lines, middle + 1, right, compareStringsCount);

        merge(lines, left, middle, right, compareStringsCount);
    }
}

/* Função para mesclar dois subarrays no Merge Sort */
void merge(StringLine *lines, int left, int middle, int right, int &compareStringsCount)
{
    int n1 = right - left + 1; // Número total de elementos

    // Aloca dinamicamente o vetor temporário
    StringLine *temp = (StringLine *)malloc(n1 * sizeof(StringLine)); // Vetor temporário local (substitui malloc)
    if (temp == NULL)
    {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    int i = left;       // Índice para percorrer o subarray da esquerda
    int j = middle + 1; // Índice para percorrer o subarray da direita
    int k = 0;          // Índice para o vetor temporário

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
    for (i = left, k = 0; i <= right; i++, k++)
    {
        strcpy(lines[i], temp[k]);
    }

    // Liberar a memória alocada para o vetor temporário
    free(temp);
}
#include "sort.h"
#include <string.h>

void quickSort(StringLine *lines, int low, int high, int &compareStringsCount)
{
    if (low < high)
    {
        /* pi é o índice de partição, lines[pi] está no lugar certo */
        int pi = partition(lines, low, high, compareStringsCount);

        /* Separadamente ordenar os elementos antes e depois da partição */
        quickSort(lines, low, pi - 1, compareStringsCount);
        quickSort(lines, pi + 1, high, compareStringsCount);
    }
}

/* Função para realizar a partição no Quick Sort */
int partition(StringLine *lines, int low, int high, int &compareStringsCount)
{
    StringLine pivot;
    strcpy(pivot, lines[high]); // Elemento pivô

    int i = low - 1; // Índice do menor elemento

    for (int j = low; j <= high - 1; j++)
    {
        // Se o elemento atual é menor ou igual ao pivô
        if (compareStrings(lines[j], pivot, compareStringsCount) <= 0)
        {
            i++; // Incrementa o índice do menor elemento
            swapStrings(lines[i], lines[j]);
        }
    }
    swapStrings(lines[i + 1], lines[high]);
    return (i + 1);
}

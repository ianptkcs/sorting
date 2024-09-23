#include "sort.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *data = fopen("../data/data.txt", "w");
    FILE *max = fopen("../data/max.txt", "w");
    clock_t start, end;
    float delta_t, delta_t_max;
    int n;
    int k;
    int n_max, compareStringsCount_max;
    bool flag;

    if (data == NULL)
    {
        printf("Erro ao abrir o arquivo de dados\n");
        return 1;
    }

    k = 1;
    do
    {
        n = 1000 * k;
        char name[32];
        snprintf(name, sizeof(name), "%d", n); // Atribui um nome ao arquivo
        generateInput(name, n, MAX_LINE_LENGTH - 2);
        k++;
        printf("Gerando arquivo %s\n", name);
    } while (n < 30000);

    k = 1;
    do
    {
        n = 100000 * k;
        char name[32];
        snprintf(name, sizeof(name), "%d", n); // Atribui um nome ao arquivo
        generateInput(name, n, MAX_LINE_LENGTH - 2);
        k++;
        printf("Gerando arquivo %s\n", name);
    } while (n < 10000000);

    // Bubble Sort
    k = 1;
    flag = false;
    printf("Bubble Sort\n");
    do
    {
        n = 1000 * k;
        char name[32];

        StringLine *lines = readInput(name, n);

        int compareStringsCount = 0;
        start = clock();
        bubbleSort(lines, n, compareStringsCount);
        end = clock();

        delta_t = (float)(end - start) / CLOCKS_PER_SEC;

        if (delta_t < 2.0)
        {
            n_max = n;
            compareStringsCount_max = compareStringsCount;
            delta_t_max = delta_t;
        }
        else if (delta_t >= 2.0 && !flag)
        {
            fprintf(max, "Bubble\t%d\t%d\t%f\n", n_max, compareStringsCount_max, delta_t_max);
            flag = true;
        }

        fprintf(data, "Bubble\t%d\t%d\t%f\n", n, compareStringsCount, delta_t);
        printf("Bubble\t%d\t%d\t%f\n", n, compareStringsCount, delta_t);
        free(lines);
        k++;
    } while (n < 30000);

    // Quick Sort
    printf("Quick Sort\n");
    k = 1;
    flag = false;
    do
    {
        n = 100000 * k;
        char name[32];

        StringLine *lines = readInput(name, n);

        int compareStringsCount = 0;
        start = clock();
        quickSort(lines, 0, n - 1, compareStringsCount);
        end = clock();

        delta_t = (float)(end - start) / CLOCKS_PER_SEC;

        if (delta_t < 2.0)
        {
            n_max = n;
            compareStringsCount_max = compareStringsCount;
            delta_t_max = delta_t;
        }
        else if (delta_t >= 2.0 && !flag)
        {
            fprintf(max, "Quick\t%d\t%d\t%f\n", n_max, compareStringsCount_max, delta_t_max);
            flag = true;
        }

        fprintf(data, "Quick\t%d\t%d\t%f\n", n, compareStringsCount, delta_t);
        printf("Quick\t%d\t%d\t%f\n", n, compareStringsCount, delta_t);

        free(lines);
        k++;
    } while (n < 10000000);

    // Merge Sort
    printf("Merge Sort\n");
    k = 1;
    flag = false;
    do
    {
        n = 100000 * k;
        char name[32];

        StringLine *lines = readInput(name, n);

        int compareStringsCount = 0;
        start = clock();
        mergeSort(lines, 0, n - 1, compareStringsCount);
        end = clock();

        delta_t = (float)(end - start) / CLOCKS_PER_SEC;

        if (delta_t < 2.0)
        {
            n_max = n;
            compareStringsCount_max = compareStringsCount;
            delta_t_max = delta_t;
        }
        else if (delta_t >= 2.0 && !flag)
        {
            fprintf(max, "Merge\t%d\t%d\t%f\n", n_max, compareStringsCount_max, delta_t_max);
            flag = true;
        }

        fprintf(data, "Merge\t%d\t%d\t%f\n", n, compareStringsCount, delta_t);
        printf("Merge\t%d\t%d\t%f\n", n, compareStringsCount, delta_t);

        free(lines);
        k++;
    } while (n < 10000000);

    // Merge Sort Static
    printf("Merge Sort Static\n");
    k = 1;
    flag = false;
    do
    {
        n = 100000 * k;
        char name[32];

        StringLine *lines = readInput(name, n);

        int compareStringsCount = 0;
        start = clock();
        mergeSort_static(lines, 0, n - 1, compareStringsCount);
        end = clock();

        delta_t = (float)(end - start) / CLOCKS_PER_SEC;

        if (delta_t < 2.0)
        {
            n_max = n;
            compareStringsCount_max = compareStringsCount;
            delta_t_max = delta_t;
        }
        else if (delta_t >= 2.0 && !flag)
        {
            fprintf(max, "Merge_static\t%d\t%d\t%f\n", n_max, compareStringsCount_max, delta_t_max);
            flag = true;
        }

        fprintf(data, "Merge_static\t%d\t%d\t%f\n", n, compareStringsCount, delta_t);
        printf("Merge_static\t%d\t%d\t%f\n", n, compareStringsCount, delta_t);

        free(lines);
        k++;
    } while (n < 10000000);

    fclose(data);
    return 0;
}

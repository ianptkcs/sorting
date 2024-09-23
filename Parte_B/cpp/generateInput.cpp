#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void generateInput(const char *name, int numberOfLines, int lineLength)
{
    char filename[256];
    snprintf(filename, sizeof(filename), "input/%s.txt", name);

    // Garantir que o diretório exista
    createDirectories("input");

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    srand(time(NULL));

    char nucleotides[] = {'A', 'C', 'G', 'T'};

    for (int i = 0; i < numberOfLines; i++)
    {
        for (int j = 0; j < lineLength; j++)
        {
            fputc(nucleotides[rand() % 4], file);
        }
        fputc('\n', file);
    }

    fclose(file);
}
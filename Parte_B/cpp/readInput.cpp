#include "sort.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

StringLine *readInput(const char *n, int numberOfLines)
{
    char filename[256];
    snprintf(filename, sizeof(filename), "input/%s.txt", n);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Lendo arquivo %s\n", filename);
        exit(1);
    }

    StringLine *lines = (StringLine *)malloc(numberOfLines * sizeof(StringLine));
    for (int i = 0; i < numberOfLines; i++)
    {
        fgets(lines[i], MAX_LINE_LENGTH, file);
    }

    fclose(file);
    return lines;
}
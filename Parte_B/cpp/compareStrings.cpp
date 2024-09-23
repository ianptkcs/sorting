#include "sort.h"
#include <string.h>

int compareStrings(const char *a, const char *b, int &comparisonCount)
{
    comparisonCount++;
    return strcmp(a, b);
}
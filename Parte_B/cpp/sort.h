#define MAX_LINE_LENGTH 52
typedef char StringLine[MAX_LINE_LENGTH];

StringLine *readInput(const char *n, int numberOfLines);
void createDirectories(char const *filename);
void generateInput(const char *n, int numberOfLines, int lineLength);
int compareStrings(const char *a, const char *b, int &comparisonCount);
void merge(StringLine *lines, int left, int middle, int right, int &compareStringsCount);
void mergeSort(StringLine *lines, int left, int right, int &compareStringsCount);
void merge_static(StringLine *lines, int left, int middle, int right, int &compareStringsCount);
void mergeSort_static(StringLine *lines, int left, int right, int &compareStringsCount);
void swapStrings(char *a, char *b);
void bubbleSort(StringLine *lines, int n, int &compareStringsCount);
int partition(StringLine *lines, int low, int high, int &compareStringsCount);
void quickSort(StringLine *lines, int low, int high, int &compareStringsCount);

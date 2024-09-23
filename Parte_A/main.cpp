/* Ian Patrick da Costa Soares                      */
/* Turma 28.1                                       */
/* Exercício 3: Ordenação                           */
/*                                                  */
/* Programa compilado com Visual Studio Code 1.92.2 */

/* Incluir as bibliotecas usadas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Definir constantes e tipos */
#define MAX_LINE_LENGTH 52 // Cada linha terá até 51 caracteres (mais o terminador nulo)
#define MAX 50000000

typedef char StringLine[MAX_LINE_LENGTH]; // Tipo para uma linha de texto

/* Variáveis globais */
int comparisonCount = 0; // Contador para o número de comparações feitas

/* Protótipos das funções */
int compareStrings(const char *a, const char *b);
void swapStrings(char *a, char *b);
void bubbleSort(StringLine *lines, int n);
void mergeSort(StringLine *lines, int left, int right);
void quickSort(StringLine *lines, int low, int high);
void merge(StringLine *lines, int left, int middle, int right);
int partition(StringLine *lines, int low, int high);
void printHeader(FILE *entrada, char *algorithm, int numberOfLines, int comparisonCount, float delta_t);

/*--------------------------------------------------*/

/* Definições das funções */

/* Função para comparar duas strings e incrementar o contador de comparações */
int compareStrings(const char *a, const char *b)
{
    comparisonCount++;
    return strcmp(a, b);
}

/* Função para trocar duas strings */
void swapStrings(char *a, char *b)
{
    StringLine temp;
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

/* Algoritmo Bubble Sort */
void bubbleSort(StringLine *lines, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compareStrings(lines[j], lines[j + 1]) > 0)
            {
                swapStrings(lines[j], lines[j + 1]);
            }
        }
    }
}

/* Função principal do Merge Sort */

/* Função principal do Merge Sort */
void mergeSort(StringLine *lines, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(lines, left, middle);
        mergeSort(lines, middle + 1, right);

        merge(lines, left, middle, right);
    }
}

/* Função para mesclar dois subarrays no Merge Sort */
void merge(StringLine *lines, int left, int middle, int right)
{
    static StringLine temp[MAX]; // Vetor temporário estático

    int i = left;       // Índice para percorrer o subarray da esquerda
    int j = middle + 1; // Índice para percorrer o subarray da direita
    int k = left;       // Índice para o vetor temporário

    // Mesclar os subarrays em temp[]
    while (i <= middle && j <= right)
    {
        if (compareStrings(lines[i], lines[j]) <= 0)
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

/* Algoritmo Quick Sort */
void quickSort(StringLine *lines, int low, int high)
{
    if (low < high)
    {
        /* pi é o índice de partição, lines[pi] está no lugar certo */
        int pi = partition(lines, low, high);

        /* Separadamente ordenar os elementos antes e depois da partição */
        quickSort(lines, low, pi - 1);
        quickSort(lines, pi + 1, high);
    }
}

/* Função para realizar a partição no Quick Sort */
int partition(StringLine *lines, int low, int high)
{
    StringLine pivot;
    strcpy(pivot, lines[high]); // Elemento pivô

    int i = low - 1; // Índice do menor elemento

    for (int j = low; j <= high - 1; j++)
    {
        // Se o elemento atual é menor ou igual ao pivô
        if (compareStrings(lines[j], pivot) <= 0)
        {
            i++; // Incrementa o índice do menor elemento
            swapStrings(lines[i], lines[j]);
        }
    }
    swapStrings(lines[i + 1], lines[high]);
    return (i + 1);
}

/* Função para escrever o cabeçalho da saída */
void printHeader(FILE *entrada, const char *algorithm, int numberOfLines, int comparisonCount, float delta_t)
{
    fprintf(entrada, "Algoritmo: %s-Sort\n", algorithm);
    fprintf(entrada, "\n");
    fprintf(entrada, "Tamanho da entrada: %d\n", numberOfLines);
    fprintf(entrada, "Comparações feitas: %d\n", comparisonCount);
    fprintf(entrada, "Tempo de execução : %.3f segundos\n", delta_t);
    fprintf(entrada, "\n");
    fprintf(entrada, "--------------------------------------------------\n");
}

/*--------------------------------------------------*/

/* Função principal */
int main()
{
    /* Abrir os arquivos de entrada e saída */
    FILE *inputFile = fopen("entrada3.txt", "r");

    if (inputFile == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada\n");
        return 1;
    }

    /* Ler o número de linhas */
    int numberOfLines;
    fscanf(inputFile, "%d", &numberOfLines);

    /* Alocar memória para as linhas */
    StringLine *originalLines = (StringLine *)malloc(numberOfLines * sizeof(StringLine));
    StringLine *linesBubbleSort = (StringLine *)malloc(numberOfLines * sizeof(StringLine));
    StringLine *linesQuickSort = (StringLine *)malloc(numberOfLines * sizeof(StringLine));
    StringLine *linesMergeSort = (StringLine *)malloc(numberOfLines * sizeof(StringLine));

    if (originalLines == NULL || linesBubbleSort == NULL || linesQuickSort == NULL || linesMergeSort == NULL)
    {
        printf("Erro ao alocar memória\n");
        fclose(inputFile);
        return 1;
    }

    /* Ler as linhas do arquivo de entrada */
    for (int i = 0; i < numberOfLines; i++)
    {
        fscanf(inputFile, "%s", originalLines[i]);
        strcpy(linesBubbleSort[i], originalLines[i]);
        strcpy(linesQuickSort[i], originalLines[i]);
        strcpy(linesMergeSort[i], originalLines[i]);
    }

    /* Fechar o arquivo de entrada */
    fclose(inputFile);

    /* Medir o tempo de execução */
    clock_t start, end;
    float delta_t;

    /* Executar Bubble Sort */
    comparisonCount = 0;
    start = clock();
    bubbleSort(linesBubbleSort, numberOfLines);
    end = clock();
    delta_t = ((float)(end - start)) / CLOCKS_PER_SEC;
    FILE *bubble = fopen("Lab3_Ian_Patrick_da_Costa_Soares_bubble.txt", "w");
    printHeader(bubble, "Bubble", numberOfLines, comparisonCount, delta_t);
    for (int i = 0; i < numberOfLines - 1; i++)
    {
        fprintf(bubble, "%s\n", linesBubbleSort[i]);
    }
    fprintf(bubble, "%s", linesBubbleSort[numberOfLines - 1]);
    fclose(bubble);

    /* Executar Merge Sort */
    comparisonCount = 0;
    static StringLine temp[MAX]; // Vetor temporário local (substitui malloc)
    start = clock();
    mergeSort(linesMergeSort, 0, numberOfLines - 1);
    end = clock();
    delta_t = ((float)(end - start)) / CLOCKS_PER_SEC;
    FILE *merge = fopen("Lab3_Ian_Patrick_da_Costa_Soares_merge.txt", "w");
    printHeader(merge, "Merge", numberOfLines, comparisonCount, delta_t);
    for (int i = 0; i < numberOfLines - 1; i++)
    {
        fprintf(merge, "%s\n", linesMergeSort[i]);
    }
    fprintf(merge, "%s", linesMergeSort[numberOfLines - 1]);
    fclose(merge);

    /* Executar Quick Sort */
    comparisonCount = 0;
    start = clock();
    quickSort(linesQuickSort, 0, numberOfLines - 1);
    end = clock();
    delta_t = ((float)(end - start)) / CLOCKS_PER_SEC;
    FILE *quick = fopen("Lab3_Ian_Patrick_da_Costa_Soares_quick.txt", "w");
    printHeader(quick, "Quick", numberOfLines, comparisonCount, delta_t);
    for (int i = 0; i < numberOfLines - 1; i++)
    {
        fprintf(quick, "%s\n", linesQuickSort[i]);
    }
    fprintf(quick, "%s", linesQuickSort[numberOfLines - 1]);
    fclose(quick);

    /* Liberar a memória alocada */
    free(originalLines);
    free(linesBubbleSort);
    free(linesQuickSort);
    free(linesMergeSort);

    return 0;
}

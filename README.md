# Sorting Project

Este projeto implementa diversos algoritmos de ordenação, juntamente com ferramentas para gerar e analisar dados de ordenação. O projeto está organizado em duas partes principais: Parte_A e Parte_B.

## Índice

-   [Estrutura do Projeto](#estrutura-do-projeto)
-   [Parte_A](#parte_a)
-   [Parte_B](#parte_b)
-   [Como Compilar e Executar](#como-compilar-e-executar)
    -   [Pré-requisitos](#pré-requisitos)
    -   [Compilando o Projeto](#compilando-o-projeto)
        -   [Compilando Parte_A](#compilando-parte_a)
        -   [Compilando Parte_B](#compilando-parte_b)
    -   [Executando o Projeto](#executando-o-projeto)
        -   [Executando Parte_A](#executando-parte_a)
        -   [Executando as Utilidades de Parte_B](#executando-as-utilidades-de-parte_b)
    -   [Gerando Dados de Entrada](#gerando-dados-de-entrada)
-   [Licença](#licença)
-   [Autores](#autores)
-   [Agradecimentos](#agradecimentos)

## Estrutura do Projeto

```
├── Parte_A/ │ ├── entrada3.txt │ ├── Lab3_Ian_Patrick_da_Costa_Soares_bubble.txt │ ├── Lab3_Ian_Patrick_da_Costa_Soares_merge.txt │ ├── Lab3_Ian_Patrick_da_Costa_Soares_quick.txt │ └── main.cpp ├── Parte_B/ │ ├── cpp/ │ │ ├── input/ │ │ ├── bubbleSort.cpp │ │ ├── compareStrings.cpp │ │ ├── createDirectories.cpp │ │ ├── generateInput.cpp │ │ ├── main.cpp │ │ ├── mergeSort_static.cpp │ │ ├── mergeSort.cpp │ │ ├── quickSort.cpp │ │ ├── readInput.cpp │ │ └── sort.h │ ├── data/ │ │ ├── data.txt │ │ └── max.txt │ ├── imagens/ │ ├── tabelas_latex/ │ ├── graficos.py │ ├── relas_armando.pdf │ ├── relas.tex │ └── tabelas.py ├── .gitignore ├── LICENSE └── README.md
```

## Parte_A

Parte_A contém a implementação principal dos algoritmos de ordenação, juntamente com seus respectivos casos de teste.

-   **Arquivos:**
    -   **entrada3.txt**: Arquivo de entrada para testes.
    -   **Lab3_Ian_Patrick_da_Costa_Soares_bubble.txt**: Resultados do algoritmo Bubble Sort.
    -   **Lab3_Ian_Patrick_da_Costa_Soares_merge.txt**: Resultados do algoritmo Merge Sort.
    -   **Lab3_Ian_Patrick_da_Costa_Soares_quick.txt**: Resultados do algoritmo Quick Sort.
    -   **main.cpp**: Arquivo de código-fonte principal para executar os algoritmos de ordenação.

## Parte_B

Parte_B inclui utilitários adicionais e scripts para gerar dados de entrada, comparar strings e gerenciar diretórios.

### cpp/

-   **Arquivos:**
    -   **input/**: Diretório para armazenar os dados de entrada gerados.
    -   **bubbleSort.cpp**: Implementação do algoritmo Bubble Sort.
    -   **compareStrings.cpp**: Utilitário para comparar strings.
    -   **createDirectories.cpp**: Utilitário para criar diretórios.
    -   **generateInput.cpp**: Utilitário para gerar dados de entrada.
    -   **main.cpp**: Arquivo de código-fonte principal para executar os utilitários.
    -   **mergeSort_static.cpp**: Implementação estática do algoritmo Merge Sort.
    -   **mergeSort.cpp**: Implementação do algoritmo Merge Sort.
    -   **quickSort.cpp**: Implementação do algoritmo Quick Sort.
    -   **readInput.cpp**: Utilitário para ler dados de entrada.
    -   **sort.h**: Arquivo de cabeçalho com definições comuns.

### data/

-   **Arquivos:**
    -   **data.txt**: Arquivo contendo os dados gerados.
    -   **max.txt**: Arquivo com o valor máximo usado na geração de dados.

### Scripts e Outros Diretórios

-   **graficos.py**: Script Python para gerar gráficos a partir dos dados.
-   **imagens/**: Diretório para armazenar imagens.
-   **tabelas_latex/**: Diretório para armazenar tabelas em LaTeX.
-   **relas.tex**: Arquivo LaTeX para gerar relatórios.
-   **relas_armando.pdf**: PDF do relatório gerado.
-   **tabelas.py**: Script Python para gerar tabelas em LaTeX a partir dos dados.

## Como Compilar e Executar

### Pré-requisitos

Certifique-se de ter os seguintes softwares instalados no seu sistema:

-   **Compilador C++**: [GCC](https://gcc.gnu.org/) (g++) ou qualquer compilador C++ compatível.
-   **Python**: [Python 3.x](https://www.python.org/) para executar scripts.

### Compilando o Projeto

#### Compilando Parte_A

1. Navegue para o diretório Parte_A:

```bash
cd Parte_A
```

2. Compile o código-fonte usando g++:

```bash
g++ -o main main.cpp
```

#### Compilando Parte_B

1. Navegue para o diretório Parte_B/cpp:

```bash
cd ../Parte_B/cpp
```

2. Compile os utilitários usando g++:

```bash
g++ -o main main.cpp
```

### Executando o Projeto

#### Executando Parte_A

Após compilar, execute o executável main para rodar os testes de ordenação:

```bash
./main
```

Isso processará os dados de entrada e gerará os arquivos de saída correspondentes para cada algoritmo de ordenação.

#### Executando as Utilidades de Parte_B

Para utilizar os utilitários adicionais fornecidos em Parte_B, execute o executável main no diretório Parte_B/cpp:

```bash
./main
```

Isso gerará dados de entrada e os armazenará no diretório Parte_B/cpp/input/ e gerará os arquivos .txt que são necessários para a análise dos algoritmos.

Obs.: adapate o arquivo conforme suas necessidades. Ele está configurado para gerar uma pasta input com 24 Gb. Lembre de editar essas partes.

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE). Você é livre para usar, modificar e distribuir este software conforme os termos da licença.

## Autores

-   **Ian Patrick da Costa Soares**

## Agradecimentos

Agradecimentos especiais aos instrutores e colegas que forneceram orientação e suporte durante o desenvolvimento deste projeto.

---

Espero que agora você consiga copiar o README sem problemas. Se precisar de mais alguma ajuda, é só me avisar!

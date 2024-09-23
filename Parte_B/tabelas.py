import pandas as pd
import os

# Diretório onde estão os arquivos .txt
data_directory = "./data"  # Altere para o diretório correto se necessário

# Lista de arquivos e suas configurações
files_info = {
    "max.txt": {
        "caption": "Tamanho Máximo de Entrada em 2 Segundos",
        "label": "tab:tamanho_maximo",
        "columns": [
            "Algoritmo",
            "Tamanho Máximo",
            "Número de Comparações",
            "Tempo de Execução (s)",
        ],
        "formatting": {
            "Tamanho Máximo": "{:.2e}",
            "Número de Comparações": "{:.2e}",
            "Tempo de Execução (s)": "{:.3f}",
        },
    },
    "data.txt": {
        "caption": "Desempenho dos Algoritmos de Ordenação",
        "label": "tab:desempenho_algoritmos",
        "columns": ["Algoritmo", "Tamanho da Entrada", "Comparações", "Tempo (s)"],
        "formatting": {
            "Tamanho da Entrada": "{:.2e}",
            "Comparações": "{:.2e}",
            "Tempo (s)": "{:.3f}",
        },
    },
}


# Função para formatar colunas específicas
def format_columns(df, formatting):
    for column, fmt in formatting.items():
        if column in df.columns:
            # Aplica a formatação apenas se a coluna for numérica
            df[column] = pd.to_numeric(df[column], errors="coerce").apply(
                lambda x: fmt.format(x) if pd.notnull(x) else x
            )
    return df


# Função para gerar tabela LaTeX a partir de um DataFrame
def gerar_tabela_latex(df, caption, label):
    tabela = df.to_latex(
        index=False, caption=caption, label=label, longtable=False, escape=False
    )
    return tabela


# Criar pasta para salvar as tabelas geradas, se não existir
output_directory = "./tabelas_latex"
os.makedirs(output_directory, exist_ok=True)

# Processar cada arquivo
for file_name, info in files_info.items():
    file_path = os.path.join(data_directory, file_name)
    if not os.path.exists(file_path):
        print(f"Arquivo {file_path} não encontrado. Pulando...")
        continue

    # Ler o arquivo .txt como CSV com tabulação como separador
    df = pd.read_csv(file_path, sep="\t", header=None, names=info["columns"])

    # Aplicar formatação nas colunas
    df = format_columns(df, info["formatting"])

    # Gerar a tabela LaTeX
    tabela_latex = gerar_tabela_latex(df, info["caption"], info["label"])

    # Nome do arquivo de saída
    output_file = os.path.join(output_directory, file_name.replace(".txt", ".tex"))

    # Salvar a tabela em um arquivo .tex
    with open(output_file, "w") as f:
        f.write(tabela_latex)

    print(f"Tabela gerada e salva em {output_file}")

# Gerar tabelas individuais para cada algoritmo no detalhado
# Supondo que 'data.txt' contenha todos os algoritmos detalhados
detailed_file = os.path.join(data_directory, "data.txt")
if os.path.exists(detailed_file):
    df_detailed = pd.read_csv(
        detailed_file, sep="\t", header=None, names=files_info["data.txt"]["columns"]
    )
    df_detailed = format_columns(df_detailed, files_info["data.txt"]["formatting"])

    algoritmos = ["Bubble", "Quick", "Merge", "Merge_static"]
    for algo in algoritmos:
        df_algo = df_detailed[
            df_detailed["Algoritmo"].str.contains(algo, case=False, na=False)
        ].copy()
        if df_algo.empty:
            print(f"Sem dados para o algoritmo {algo}.")
            continue
        # Remover a coluna 'Algoritmo' para tabelas individuais
        df_algo = df_algo.drop(columns=["Algoritmo"])
        # Ajustar a legenda e label
        algo_clean = algo.replace("_", "").capitalize()
        caption = f"Desempenho do {algo_clean}Sort"
        label = f"tab:{algo.lower()}sort"
        tabela_latex = gerar_tabela_latex(df_algo, caption, label)
        output_file = os.path.join(output_directory, f"{algo.lower()}sort.tex")
        with open(output_file, "w") as f:
            f.write(tabela_latex)
        print(f"Tabela para {algo}Sort gerada e salva em {output_file}")
else:
    print(
        f"Arquivo {detailed_file} não encontrado. Tabelas detalhadas não foram geradas."
    )

print("Todas as tabelas foram geradas com sucesso!")

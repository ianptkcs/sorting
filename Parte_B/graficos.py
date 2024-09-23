import pandas as pd
import matplotlib.pyplot as plt
import os

# Diretório onde estão os arquivos .txt
data_directory = "./data"  # Altere se necessário

# Diretório para salvar os gráficos
graphics_directory = "./imagens"
os.makedirs(graphics_directory, exist_ok=True)

# Lista de algoritmos e seus respectivos nomes no script
algoritmos = ["Bubble", "Quick", "Merge", "Merge_static"]


# Função para gerar gráficos para cada algoritmo
def gerar_graficos(algoritmo):
    file_path = os.path.join(data_directory, "data.txt")
    if not os.path.exists(file_path):
        print(f"Arquivo {file_path} não encontrado.")
        return

    # Ler os dados detalhados
    try:
        df = pd.read_csv(
            file_path,
            sep="\t",
            header=None,
            names=["Algoritmo", "Tamanho da Entrada", "Comparações", "Tempo (s)"],
            engine="python",
        )
    except Exception as e:
        print(f"Erro ao ler {file_path}: {e}")
        return

    # Filtrar dados para o algoritmo atual
    df_algo = df[df["Algoritmo"] == algoritmo]
    if df_algo.empty:
        print(f"Sem dados para o algoritmo {algoritmo}.")
        return

    # Ordenar os dados pelo tamanho da entrada para garantir a sequência correta nos gráficos
    df_algo = df_algo.sort_values(by="Tamanho da Entrada")

    # Plotar Número de Comparações vs Tamanho da Entrada
    plt.figure(figsize=(10, 6))
    plt.plot(
        df_algo["Tamanho da Entrada"],
        df_algo["Comparações"],
        marker="o",
        linestyle="-",
        label="Comparações",
    )
    plt.title(f"{algoritmo}Sort: Número de Comparações vs Tamanho da Entrada")
    plt.xlabel("Tamanho da Entrada")
    plt.ylabel("Número de Comparações")
    plt.grid(True)
    plt.legend()
    comparacoes_path = os.path.join(
        graphics_directory, f"{algoritmo.lower()}sort_comparacoes.png"
    )
    plt.savefig(comparacoes_path)
    plt.close()
    print(f"Gráfico de comparações salvo em {comparacoes_path}")

    # Plotar Tempo de Execução vs Tamanho da Entrada
    plt.figure(figsize=(10, 6))
    plt.plot(
        df_algo["Tamanho da Entrada"],
        df_algo["Tempo (s)"],
        marker="s",
        linestyle="-",
        color="r",
        label="Tempo de Execução",
    )
    plt.title(f"{algoritmo}Sort: Tempo de Execução vs Tamanho da Entrada")
    plt.xlabel("Tamanho da Entrada")
    plt.ylabel("Tempo de Execução (s)")
    plt.grid(True)
    plt.legend()
    tempo_path = os.path.join(graphics_directory, f"{algoritmo.lower()}sort_tempo.png")
    plt.savefig(tempo_path)
    plt.close()
    print(f"Gráfico de tempo de execução salvo em {tempo_path}")


# Gerar gráficos para cada algoritmo
for algo in algoritmos:
    gerar_graficos(algo)

print("Todos os gráficos foram gerados com sucesso!")

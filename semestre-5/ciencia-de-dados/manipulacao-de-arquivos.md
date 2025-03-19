# Manipulação de arquivos

Podemos abrir arquivos de diversas formas, de maneiras até nativas do Python. Essas maneiras exigem lidar com um ciclo do arquivo, como por exemplo `open`, `read` e `close`.

Arquivos podem se tornar estruturas (Series ou Dataframes) e neste caso são lidados pelo Pandas. Os métodos de estruturas **já lidam automaticamente** com abertura de arquivos, por isso, não encontraremos open ou similares quando trabalhar com essas estruturas.

Se temos uma estrutura em uma variável, isso quer dizer que podemos usar os [métodos](estruturas/series/metodos.md) nela para fazer o que quisermos.

## Arquivo de texto (TXT)

### Abrir arquivo

Ler, escrever ou qualquer ação é possível ser feita **após a abertura** de um arquivo. Utilizar o método `open` retorna um objeto de arquivo, utiliza os argumentos:

* filename: O nome do arquivo, com o formato incluso.
* mode: Modo de abertura.

```python
arq = open("vendas.txt", 'r')
```

### Leitura

Qualquer método de leitura como [`read`](#user-content-fn-1)[^1], [`readline`](#user-content-fn-2)[^2] e [`readlines`](#user-content-fn-3)[^3] é usado para **ler as linhas de um arquivo** e retorná-las como uma <mark style="color:blue;">**lista de strings**</mark> (no caso do readlines). Então são métodos para "reconhecer" o arquivo.

Se temos uma lista de strings como retorno, podemos iterá-las:

```python
linhas = arq.readlines()
for linha in linhas:
    print(linha)
```

### Escrita

```python
arq = open("meu_arquivo.txt","w+")
 
linhasParaOArquivo = ["linha 1","linha 2","linha 3", "linha 4","linha 5"]
 
for l in linhasParaOArquivo:
    arq.write(l)
    arq.write("\n")

arq.close()
```

## JSON

### Abrir arquivo

JSON é um arquivo de chave valor então podemos ler como um dicionário. Contudo, pode ser vantajoso abrí-lo como um Dataframe para trabalhar com estruturas de dados. São duas abordagens válidas.

```python
# Abrir como dicionário
import json
with open('produtos.json') as f:
    produtos = json.load(f)
```

```python
# Abrir como Dataframe, exige pandas
import pandas as pd
df = pd.read_json('https://mdn.github.io/learning-area/javascript/oojs/json/superheroes.json')
```

## CSV/Excel

A partir do momento da abertura, notas passa a ser um Dataframe e podemos usar atributos e métodos para sua manipulação.

```python
# Abrir
notas = pd.read_csv("ratings.csv")
notas = pd.read_excel("ratings.csv", sheet_name="Planilha1")

# Seleções manuais
notas[['usuarioId', 'filmeId']]

# Exemplo de propriedades
notas.columns = ["usuarioId", "filmeId", "nota", "momento"]

# Exemplo de usar métodos
notas.describe()
notas.nota.tail()
```

### Escrevendo

Sem biblioteca pandas.

```python
import csv

# Lista de artistas e links (exemplo similar ao scraping feito no código original)
data = [
    ['Artist 1', 'https://example.com/artist1'],
    ['Artist 2', 'https://example.com/artist2'],
    ['Artist 3', 'https://example.com/artist3']
]

# Abre (ou cria) o arquivo CSV para escrita
with open('artist_names.csv', mode='w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)
    
    # Escreve o cabeçalho
    writer.writerow(['Name', 'Link'])
    
    # Escreve as linhas dos dados
    writer.writerows(data)

print("Arquivo CSV salvo com sucesso.")
```

Com biblioteca pandas.

```python
import pandas as pd

# Lista de artistas e links (exemplo similar ao scraping feito no código original)
data = {
    'Name': ['Artist 1', 'Artist 2', 'Artist 3'],
    'Link': ['https://example.com/artist1', 'https://example.com/artist2', 'https://example.com/artist3']
}

# Cria um DataFrame com os dados
df = pd.DataFrame(data)

# Salva o DataFrame em um arquivo CSV
df.to_csv('artist_names.csv', index=False)

print("Arquivo CSV salvo com sucesso.")
```

Arquivo xlsx

```python
import pandas as pd

# Lista de artistas e links (exemplo similar ao scraping feito no código original)
data = {
    'Name': ['Artist 1', 'Artist 2', 'Artist 3'],
    'Link': ['https://example.com/artist1', 'https://example.com/artist2', 'https://example.com/artist3']
}

# Cria um DataFrame com os dados
df = pd.DataFrame(data)

# Salva o DataFrame em um arquivo Excel
df.to_excel('artist_names.xlsx', index=False)

print("Arquivo Excel salvo com sucesso.")

```

## Criar estruturas a partir de arquivos

Na prática esse é o ideal, normalmente vai ser através de arquivos.

* Se tiver uma coluna apenas vai transformar em **serie**.
* Se tiver mais transforma em **dataframe**.

Substituímos o `Series` por `read_csv`, desta forma:

```python
# Usando a primeira coluna (zero) como índice
pd.read_csv("idades.csv", index_col = 0).squeeze()
```

[^1]: Leitura com uma limitação em bytes definida no parâmetro.

[^2]: Lê apenas a primeira linha.

[^3]: Lê o arquivo inteiro retornando uma lista de strings.

# Estruturas

* <mark style="color:purple;">**Séries**</mark>: Unidimensional, ou seja, um vetor na horizontal ou vertical.
* <mark style="color:purple;">**Dataframes**</mark>: Bidimensional, ou seja, uma matriz/tabela e cada coluna é uma série.

<figure><img src="../../../.gitbook/assets/series e dataframes.png" alt="" width="563"><figcaption></figcaption></figure>

Essas estruturas podem ser criadas a partir de dados que estão em variáveis em um código Python. Então por exemplo, podemos transformar uma lista em uma série ou um vetor de objetos e transformá-lo em um dataframe.

## Métodos e propriedades

Seguir a [documentação do Pandas](https://pandas.pydata.org/pandas-docs/stable/reference/series.html) para usar os métodos e propriedades que queremos, para manipular, buscar ou operacionais series e dataframes.

<figure><img src="../../../.gitbook/assets/utilizar metodos do panda.png" alt=""><figcaption></figcaption></figure>

## Séries

Essas estruturas de dados são <mark style="color:purple;">mutáveis</mark>.

### Criar séries a partir de uma estrutura

Podemos utilizar [estruturas como lista, tupla ou dicionário](../../../semestre-1/algoritmos-de-programacao/pratico/listas.md) para servir como dados da serie. Utilizaremos o método `Series()`.

```python
minha_serie = pd.Series(minha_estrutura)
```

Dicionários de dicionários também funcionam. Isso mostra que o <mark style="color:green;">valor de uma série pode ser algo mais complexo</mark>, como uma outra estrutura de dados.

### Índices

A <mark style="color:green;">grande diferença de uma serie para uma lista é a definição do índice</mark> para acessar os elementos. Por exemplo, o índice pode ser "a", "b", etc. Em series, podemos usar como <mark style="color:blue;">índice qualquer coisa</mark> e mesmo se utilizarmos outro tipo, ainda poderemos acessar através do seu número da posição.

Resgatar dados passa a ser através do índice:

```python
serie[3] # Através da sua posição na serie
serie['Carlos'] # Através do índice
```

#### Usar uma lista como índice dos dados

Se passar duas listas com o <mark style="color:orange;">mesmo tamanho</mark>:

```python
idades = [68, 23, 17, 39, 25, 58]
pessoas = ['Eni', 'Bia', 'Flávio', 'Carlos', 'Dedé', 'Abigail']

s = pd.Series(idades, pessoas)
s = pd.Series(index = idades, data = pessoas) # Possibilidade
```

* A primeira são os dados: `idades`.
* A segunda vira o índice: `pessoas`.

{% hint style="danger" %}
Cuidado que precisamos tomar: Podemos criar series com índices duplicados. Perde a autenticidade, por isso precisa tomar cuidado.
{% endhint %}

#### Dicionários

Como dicionários já são compostos por chaves e valor, ao usar um dicionário para servir como serie, automaticamente as chaves já se transformarão em índices.

## Criar estruturas a partir de arquivos

Na prática esse é o ideal, normalmente vai ser através de arquivos.

* Se tiver uma coluna apenas vai transformar em **serie**.
* Se tiver mais transforma em **dataframe**.

Substituímos o `Series` por `read_csv`, desta forma:

```python
# Usando a primeira coluna (zero) como índice
pd.read_csv("idades.csv", index_col = 0).squeeze()
```

### Squeeze

A função `squeeze` transforma o dataframe em uma série. Esse método é uma pergunta, só transforma se for possível. Se há duas colunas e quiser transformar em serie, o método precisa ser melhor implementado:

```python
pd.read_csv("idades.csv", index_col = 0).squeeze()
```


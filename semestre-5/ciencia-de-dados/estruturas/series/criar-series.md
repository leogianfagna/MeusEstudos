# Criar Series

{% hint style="info" %}
Essas estruturas de dados são <mark style="color:purple;">mutáveis</mark>.
{% endhint %}

## Criar séries a partir de uma estrutura

Podemos utilizar [estruturas como lista, tupla ou dicionário](../../../../semestre-1/algoritmos-de-programacao/pratico/listas.md) para servir como dados da serie. Utilizaremos o método `Series()`.

```python
minha_serie = pd.Series(minha_estrutura)
```

Dicionários de dicionários também funcionam. Isso mostra que o <mark style="color:green;">valor de uma série pode ser algo mais complexo</mark>, como uma outra estrutura de dados.

## Índices

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

## Acessar elementos

O acesso em series é muito comum, utilizando apenas `serie[0]` ou `serie["indice"]` caso o índice seja customizado. Vemos que em dataframes o acesso utiliza o método `loc`, que pode ser utilizado aqui também. Mas como uma serie é uma estrutura unidimensional, <mark style="color:green;">esse método não é necessário</mark>.

## Inserir elementos

```python
s[len(s)] = 40
s["indice"] = 40
```

## Squeeze

A função `squeeze` transforma o dataframe em uma série. Esse método é uma pergunta, só transforma se for possível. Se há duas colunas e quiser transformar em serie, o método precisa ser melhor implementado:

```python
pd.read_csv("idades.csv", index_col = 0).squeeze()
```

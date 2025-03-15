# Métodos

Devemos lembrar que cada coluna de um dataframe é uma serie, portanto, os [métodos disponíveis para series](../series/metodos.md) funcionam da mesma forma.

Se usarmos esses métodos para todo o dataframe `df`, estaremos fazendo isso para todos os dados nele, mas podemos definir colunas específicas.

## Especificar coluna

Supondo o dataframe `df` com a coluna chamada `notas`, são duas formas de especificar a coluna que queremos operar:

```python
media = df.mean()["notas"]
media = df.notas.mean()

# Output exemplo: 3.5343123
```

## Agrupamento

Se quisermos agrupar os resultados com base em outra coluna, por exemplo, exibir a nota por cada aluno em vez de exibir a média geral da coluna, podemos usar `groupby`, que segue uma [lógica parecida de agrupamento e sub query](../../../../semestre-4/banco-de-dados/relacional/operadores/agrupamento-e-sub-query.md).

É muito importante saber que <mark style="color:orange;">isso retorna uma serie</mark>, sendo o índice o que está sendo agrupado e o valor a média neste caso. É importante saber disso pois ela pode ser usada posteriormente, como para incluí-la como uma nova coluna ou usar como filtro.

```python
# Incluir groupby com a coluna de agrupamento "aluno"
# Incluir a coluna a ser calculada "notas"
media = df.groupby("aluno").notas.mean()
                         
# Output exemplo:
#   aluno    notas
#   Aluno 1  3.5
#   Aluno 2  4.9
```

## Formas de exibição

Depois de uma lógica feita, podemos incluir [ordenações](../series/metodos.md#ordenacao) ou limites de exibição. Veja com o exemplo acima com `sort_values` e `head`:

```python
media = df.groupby("aluno").notas.mean().sort_values(ascending=False).head(10)
```

## Indexação booleana (filtrar dados)

Utilizada para <mark style="color:blue;">filtrar dados baseado em condições</mark>. Apenas no Pandas, colocar uma **condição lógica** dentro dos colchetes, aplica essa condição a cada elemento da serie ou dataframe e **mantém apenas os elementos que satisfazem a condição**.

```python
contagem_por_aluno = df.groupby("aluno").notas.count()
nova_serie_filtrada = contagem_por_aluno[contagem_por_aluno >= 10]

# Depois podemos usar o que foi filtrado para servir como filtro em outra query
# Exemplo: Calcular a média de nota apenas de alunos com +10 notas ao todo
media_por_aluno = df.groupby("aluno").notas.mean()
media_por_aluno = df.loc[nova_serie_filtrada.index] # Resgata todos com +10 notas
```

{% hint style="success" %}
#### Essas filtragens permitem:

Múltiplas condições

```python
df_sp_maiores = df[(df['Cidade'] == 'São Paulo') & (df['Idade'] > 20)]
```



Utilizar métodos de elementos ausentes:

```python
df_salario = df[df['Salario'].notna()]
```



Utilizar métodos de strings:

```python
df_paulo = df[df['Cidade'].str.contains('Paulo', na=False)]
```



Utilizar comparadores:

```python
df_idade = df[df['Idade'].between(20, 35)]
```
{% endhint %}

É possível incluir essa indexação booleana em quase todo lugar. Isso <mark style="color:green;">permite criar outras combinações e não somente filtros</mark>, como por exemplo, alterar valores baseado em uma condição.

#### Outra combinação: Alterar dados

Usamos `loc` para acessar dados (como [descrito aqui](../series/metodos.md#indexacao-e-iteracao)), portanto, podemos acessar todos os dados que condizem com o filtro.

```python
# Mudar a cidade de quem tem menos de 18 anos para 'Desconhecido'
df.loc[df['Idade'] < 18, 'Cidade'] = 'Desconhecido'
print(df)
```

## Gerar novo dataframe

Os [métodos do Pandas de merging](https://pandas.pydata.org/docs/user_guide/merging.html) permite <mark style="color:green;">criar novo dataframe com novos dados</mark>. Vamos supor em incluir uma nova coluna (podemos usar o `groupby` que retorna uma serie).

```python
# Crie um novo DataFrame contendo apenas filmes do gênero "Comedy"
# com sua respectiva média de avaliação

# Dataframe com o gênero filtrado
comedy_movies = movies[movies["genres"].str.contains("Comedy", na=False)]

# Serie nova que será incluída como nova coluna
rating_mean = ratings.groupby("movieId")["rating"].mean()

# Manipulação:
# "on" = Exige o índice para incluir
# "how" = Diz se vai usar os valores da direita ou esquerda (igual INNER JOIN)
# "rating_mean" = É a serie a ser incluída, passada como parâmetro obviamente
df_comedy = comedy_movies.merge(rating_mean, on="movieId", how="left")
```

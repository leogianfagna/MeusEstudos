# Dataframes

Existe um método do Pandas `query`, que permite **filtrar** um DataFrame de forma mais compacta e legível, usando expressões dentro de uma **string**. Ele substitui `loc[]` ou outros operadores booleanos.

#### Exemplo de filtro

Filtrar todos os registros cujo o valor é `1` na coluna "nomeColuna", como se fosse um `WHERE` em SQL.

```python
meu_dataframe.query("nomeColuna==1")
```

#### Fazer algo com esse filtro

Calcular a média dos registros da coluna "outraColuna" dos resultados filtrados.

```python
meu_dataframe.query("nomeColuna==1").outraColuna.mean()
```

#### Outros exemplos

```python
medias_por_filme = notas.groupby("filmeId").mean().nota
type(medias_por_filme) # Isso é uma serie
```

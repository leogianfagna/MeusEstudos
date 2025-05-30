# Atributos

<table><thead><tr><th width="120">Atributo</th><th width="478">Descrição</th><th>Exemplo</th></tr></thead><tbody><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.dtype.html">dtype</a></td><td>Retorna o tipo dos dados armazenados em um objeto Series</td><td><code>s.dtype</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.index.html">index</a></td><td>Retorna o índice (rótulos) de um objeto Series</td><td><code>s.index</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.index.html">name</a></td><td>Retorna o nome</td><td><code>s.name</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.nbytes.html">nbytes</a></td><td>Retorna o tamanho em bytes de um objeto Series</td><td><code>s.nbytes</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.ndim.html">ndim</a></td><td>Retorna o número de dimensões de um objeto Series</td><td><code>s.ndim</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.shape.html">shape</a></td><td>Retorna uma tupla com o formato de um objeto Series</td><td><code>s.shape</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.size.html">size</a></td><td>Retorna a quantidade de elementos de um objeto Series</td><td><code>s.size</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.values.html">values</a></td><td>Retorna os elementos de um objeto Series como um <em>ndarray</em></td><td><code>s.values</code></td></tr></tbody></table>

## Checar existência de index

Com esses atributos, podemos checar se um determinado índice existe em uma serie (ou consequentemente também em um dataframe), exemplo:

```python
if "indice_001" in df.index:
    print("Índice existe na serie/dataframe")
```

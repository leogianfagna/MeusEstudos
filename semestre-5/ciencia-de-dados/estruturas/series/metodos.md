# Métodos

## Indexação e iteração

São métodos úteis para <mark style="color:blue;">encontrar os dados de uma serie</mark>.

<table><thead><tr><th width="114">Método</th><th width="333">Descrição</th><th>Exemplo</th></tr></thead><tbody><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.at.html">at()</a></td><td>Acessa o elemento da chave passada por parâmetro</td><td><code>s.iat["chave"]</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.iat.html">iat()</a></td><td>Acessa o elemento no índice passado por parâmetro</td><td><code>s.iat(0)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.get.html#pandas.Series.get">get()</a></td><td>Retorna um valor para a chave passada por parâmetro</td><td><code>s.get(2)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.loc.html">loc()</a></td><td>Acessa os elementos para as chaves passadas por parâmetro</td><td><code>s.loc["chave1", "chave2"]</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.iloc.html">iloc()</a></td><td>Acesso via índice</td><td><code>s.iloc[0]</code> ou <code>s.iloc[[1,3]]</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.keys.html">keys()</a></td><td>Retorna o índice (rótulos) de um objeto Series</td><td><code>s.keys()</code></td></tr></tbody></table>

## Operações matemáticas e estatística

### Uma serie com outra

Métodos chamados de uma serie com outra serie no parâmetro, que **possibilita executar operações de elementos de uma serie por outros elementos de outra** serie que tenham o mesmo índice.

```javascript
// Cada dado da serie_um será somado pelo dado do mesmo índice da serie_dois
serie_somada = serie_um.add(serie_dois)

// Cada dado da serie_um será somado com 3
serie_somada = serie_um.add(3)
```

<table><thead><tr><th width="143">Método</th><th>Descrição</th><th>Exemplo</th></tr></thead><tbody><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.add.html">add()</a></td><td>Retorna a soma com outra Series ou escalar, elemento por elemento</td><td><code>c = a.add(b, fill_value=0)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.sub.html">sub()</a></td><td>Retorna a subtração com outra Series ou escalar, elemento por elemento</td><td><code>c = a.sub(b, fill_value=3)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.mul.html">mul()</a></td><td>Retorna a multiplicação com outra Series ou escalar, elemento por elemento</td><td><code>c = a.mul(b, fill_value=1)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.div.html">div()</a></td><td>Retorna a divisão com outra Series ou escalar, elemento por elemento</td><td><code>c = a.div(b, fill_value=1)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.floordiv.html">floordiv()</a></td><td>Retorna a divisão inteira com outra Series ou escalar, elemento por elemento</td><td><code>c = a.floordiv(b, fill_value=1)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.mod.html">mod()</a></td><td>Retorna o resto da divisão com outra Series ou escalar, elemento por elemento</td><td><code>c = a.mod(b, fill_value=1)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.pow.html">pow()</a></td><td>Retorna a potenciação com outra Series ou escalar, elemento por elemento</td><td><code>c = a.pow(b, fill_value=1)</code></td></tr></tbody></table>

### De todos os elementos de uma mesma serie

Métodos chamados para apenas uma serie que fazem/retornam algo relacionado a todos os elementos daquela serie.

```javascript
// Normalizar cada resultado, uma casa decimal por exemplo
serie_um = serie_um.round(1)

// Retornam algo
serie_um.sum()
serie_um.describe()
serie_um.quatile(0.25)
```

<table><thead><tr><th width="139">Método</th><th width="393">Descrição</th><th>Exemplo</th></tr></thead><tbody><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.round.html">round()</a></td><td>Arredonda os valores de uma Series para uma quantidade determinada de casas decimais</td><td><code>s = a.round(2)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.product.html">product()</a></td><td>Retorna o produto entre todos os elementos de um objeto Series</td><td><code>s.product()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.sum.html">sum()</a></td><td>Retorna a soma entre todos os elementos de um objeto Series</td><td><code>s.sum()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.abs.html">abs()</a></td><td>Retorna valor absoluto de todos os elementos de um objeto Series</td><td><code>s.abs()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.mean.html">mean()</a></td><td>Retorna a média aritmética entre todos os elementos de um objeto Series</td><td><code>s.mean()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.count.html">count()</a></td><td>Retorna a quantidade de elementos não nulos</td><td><code>s.count()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.describe.html">describe()</a></td><td>Gera um relatório com diversas medidas estatísticas como média, percentis, etc...</td><td><code>s.describe()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.max.html">max()</a></td><td>Retorna o maior valor</td><td><code>s.max()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.min.html">min()</a></td><td>Retorna o menor valor</td><td><code>s.min()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.median.html">median()</a></td><td>Retorna a mediana entre todos os elementos</td><td><code>s.median()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.nlargest.html">nlargest()</a></td><td>Retorna os <em>n</em> maiores elementos</td><td><code>s.nlargest(3)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.nsmallest.html">nsmallest()</a></td><td>Retorna os <em>n</em> menores elementos</td><td><code>s.nsmallest(5)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.quantile.html">quantile()</a></td><td>Retorna o valor de determinado quantil passado por parâmetro</td><td><code>s.quantile(0.25)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.std.html">std()</a></td><td>Retorna o desvio padrão</td><td><code>s.std()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.unique.html">unique()</a></td><td>Retorna valores únicos</td><td><code>s.unique()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.nunique.html">nunique()</a></td><td>Retorna a quantidade de elementos únicos</td><td><code>s.nunique()</code></td></tr></tbody></table>

## Comparações estatísticas

Pode ser aplicada para cada elemento entre duas series.

```javascript
// Retorna true/false para cada valor comparado entre as series
print(serie_um.lt(serie_dois).values)
```

<table><thead><tr><th width="102">Método</th><th width="331">Descrição</th><th>Exemplo</th></tr></thead><tbody><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.lt.html">lt()</a></td><td>Retorna o resultado da comparação <em>menor que</em>, aplicada elemento por elemento, entre duas Series</td><td><code>c = a.lt(b, fill_value=0)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.gt.html">gt()</a></td><td>Retorna o resultado da comparação <em>maior que</em>, aplicada elemento por elemento, entre duas Series</td><td><code>c = a.gt(b, fill_value=0)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.le.html">le()</a></td><td>Retorna o resultado da comparação <em>menor ou igual</em>, aplicada elemento por elemento, entre duas Series</td><td><code>c = a.le(b, fill_value=0)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.ge.html">ge()</a></td><td>Retorna o resultado da comparação <em>maior ou igual</em>, aplicada elemento por elemento, entre duas Series</td><td><code>c = a.ge(b, fill_value=0)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.ne.html">ne()</a></td><td>Retorna o resultado da comparação <em>não igual a</em>, aplicada elemento por elemento, entre duas Series</td><td><code>c = a.ne(b, fill_value=0)</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.eq.html">eq()</a></td><td>Retorna o resultado da comparação <em>igual a</em>, aplicada elemento por elemento, entre duas Series</td><td><code>c = a.eq(b, fill_value=0)</code></td></tr></tbody></table>

## Manipulação e seleção

Manipular elementos ou até toda a serie usando métodos.

{% hint style="success" %}
A seleção de resultados pode ser combinado com o método `dropna()` (explicado na seleção de métodos ausentes). Basicamente, basta chamar o método depois de aplicar qualquer tipo de filtro ou seleção, que isso vai retornar um resultado mais limpo.

```javascript
// Cria o filtro com where, depois exibe apenas esses resultados
serie.where(s > 50).dropna()
```
{% endhint %}

```javascript
// Substitui todos os valores "zero" por "um"
nova_serie = uma_serie.replace(0, 1)

// O "ignore_index" faz com que leve em consideração a ordem dos elementos.
// O primeiro elemento será índice 0 e assim por diante, vai ignorar caso a
// serie tenha índices personalizados ou com números diferentes
nova_serie = serie_base.append(outra_serie, ignore_index=True)

// Troca valores por 10 se?
//   where: a condição for falsa
//   mask: a condição for true
nova_serie = serie.where(serie > 3, 10)
nova_serie = serie.mask(serie <= 3, 10)
```

| Método                                                                                                          | Descrição                                                                                                             | Exemplo                |
| --------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------- | ---------------------- |
| [copy()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.copy.html#pandas.Series.copy) | Retorna uma cópia de um objetos Series                                                                                | `s.copy()`             |
| [append()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.append.html)                | Concatena duas ou mais Series                                                                                         | `s = a.append(b)`      |
| [replace()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.replace.html)              | Substitui valor da Series por outro passado por parâmetro                                                             | `s = a.replace(-1, 0)` |
| [update()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.update.html)                | Modifica uma série por valores de outra série passada por parâmetro                                                   | `a.update(b)`          |
| [head()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.head.html)                    | Retorna as _n_ primeiras linhas                                                                                       | `s.head(3)`            |
| [tail()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.tail.html)                    | Retorna as _n_ últimas linhas                                                                                         | `s.tail(4)`            |
| [sample()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.sample.html)                | Retorna uma amostra                                                                                                   | `s.sample()`           |
| [where()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.where.html)                  | Retorna uma Series onde valores para os quais a condição é **False** são substituídos por outro passado por parâmetro | `s.where(s <= 0, 5)`   |
| [mask()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.mask.html)                    | Retorna uma Series onde valores para os quais a condição é **True** são substituídos por outro passado por parâmetro  | `s.mask(s > 0, 5)`     |

### Com elementos ausentes

Esse caso manipula dados ausentes, que são considerados `NaN` ou `None`. O retorno desses dados são dados como verdadeiro (para dado presente) ou falso (para dado ausente).

Existem parâmetros como `inplace` e `method` que esses métodos recebem. Veja a documentação de cada método para saber o que preencher.

```javascript
// Preenche com o elemento posterior ao NaN, por causa do method 'bfill'
nova_serie = serie.fillna(method='bfill')

serie_sem_elementos_vazios.dropna(inplace=True)
```

| Método                                                                                           | Descrição                                                                   | Exemplo       |
| ------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------------- | ------------- |
| [isna()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.isna.html)     | Retorna quais valores estão ausentes                                        | `s.isna()`    |
| [notna()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.notna.html)   | Retorna quais valores estão presentes                                       | `s.notna()`   |
| [dropna()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.dropna.html) | Retorna uma nova Series com valores ausentes removidos                      | `s.dropna()`  |
| [fillna()](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.fillna.html) | Substitui valores ausentes por um valor ou usando um método de substituição | `s.fillna(0)` |

## Ordenação

Retorna baseado na ordem dos elementos.

```javascript
ordenado_id = idadescsv3.sort_values()
ordenado_nome = ordenado_id.sort_index()
```

<table><thead><tr><th width="148">Método</th><th width="393">Descrição</th><th>Exemplo</th></tr></thead><tbody><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.sort_values.html">sort_values()</a></td><td>Retorna uma Series ordenada pelos valores</td><td><code>s.sort_values()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.sort_index.html">sort_index()</a></td><td>Retorna uma Series ordenada pelos rótulos</td><td><code>s.sort_index()</code></td></tr></tbody></table>

## Manipulação de strings

Ao usar qualquer método aqui, todos os elementos da serie serão afetados e suas strings modificadas.

```javascript
// Está apenas retornando e não modificando
serie_de_strings.str.capitalize()
```

<table><thead><tr><th width="156">Método</th><th width="369">Descrição</th><th>Exemplo</th></tr></thead><tbody><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.str.capitalize.html">str.capitalize()</a></td><td>Retorna uma Series com os Strings convertidos para a forma <em>capitalizada</em>: primeiro caractere maiúsculo e caracteres restantes em minúsculo</td><td><code>s.str.capitalize()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.str.lower.html">str.lower()</a></td><td>Retorna uma Series com os Strings convertidos para letras minúsculas</td><td><code>s.str.lower()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.str.upper.html">str.upper()</a></td><td>Retorna uma Series com os Strings convertidos para letras maiúsculas</td><td><code>s.str.upper()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.str.title.html">str.title()</a></td><td>Retorna uma Series com os Strings convertidos para o formato de título: primeira letra de cada palavra convertida para maiúscula</td><td><code>s.str.title()</code></td></tr></tbody></table>

## Plotando gráficos

Plotar gráfico significa criar uma representação visual deles. Esses métodos são simples e basta chamá-los. Vale a pena lembrar que eles criam conforme os elementos definidos, então pode ser útil querer ordenar ou manipular antes dos gráficos.

```javascript
serie.plot.line()
```

<table><thead><tr><th width="165">Método</th><th width="375">Descrição</th><th>Exemplo</th></tr></thead><tbody><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.plot.area.html">plot.area()</a></td><td>Plota o gráfico de área</td><td><code>s.plot.area()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.plot.bar.html">plot.bar()</a></td><td>Plota o gráfico de barras</td><td><code>s.plot.bar()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.plot.box.html">plot.box()</a></td><td>Plota o Boxplot</td><td><code>s.plot.box()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.plot.hist.html">plot.hist()</a></td><td>Plota o histograma</td><td><code>s.plot.hist()</code></td></tr><tr><td><a href="https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.plot.line.html">plot.line()</a></td><td>Plota o gráfico de linhas</td><td><code>s.plot.line()</code></td></tr></tbody></table>

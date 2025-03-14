# Métodos

## Como fazer manipulações de dataframes

Devemos lembrar que cada coluna de um dataframe é uma serie, portanto, os [métodos disponíveis para series](../series/metodos.md) funcionam da mesma forma.

Se usarmos esses métodos para todo o dataframe `df`, estaremos fazendo isso para todos os dados nele, mas podemos definir colunas específicas.

### Especificar coluna

Supondo o dataframe `df` com a coluna chamada `notas`, são duas formas de especificar a coluna que queremos operar:

```python
media = df.mean()["notas"]
media = df.notas.mean()

# Output exemplo: 3.5343123
```

### Agrupamento

Se quisermos agrupar os resultados com base em outra coluna, por exemplo, exibir a nota por cada aluno em vez de exibir a média geral da coluna, podemos usar `groupby`, que segue uma [lógica parecida de agrupamento e sub query](../../../../semestre-4/banco-de-dados/relacional/operadores/agrupamento-e-sub-query.md).

```python
# Incluir groupby com a coluna de agrupamento "aluno"
# Incluir a coluna a ser calculada "notas"
media = df.groupby("aluno").notas.mean()
                         
# Output exemplo:
#   aluno    notas
#   Aluno 1  3.5
#   Aluno 2  4.9
```

### Formas de exibição

Depois de uma lógica feita, podemos incluir [ordenações](../series/metodos.md#ordenacao) ou limites de exibição. Veja com o exemplo acima:

```python
media = df.groupby("aluno").notas.mean().sort_values(ascending=False).head(10)
```

> Parei no 9

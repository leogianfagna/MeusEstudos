# Pré processamento dos dados

## Redução de dimensionalidade

O **PCA** (Análise de Componentes Principais) serve para <mark style="color:blue;">reduzir o número de variáveis</mark> ao transformar os dados originais em novas variáveis chamadas componentes principais, fazendo com que reduzimos o valor da dimensão[^1] que temos.

Portanto, é um <mark style="color:orange;">processo separado e posterior da normalização dos dados</mark>. Primeiro os dados são normalizados (exemplo acima com StandardScaler) e depois esses mesmos dados normalizados passam pela redução de dimensionalidade.

Veja que na normalização é resultado em um dataframe `X_base_scaled` com as variáveis. Esse dataframe será o parâmetro do método do PCA:

```python
pca = PCA(n_components=2)
X_pca = pca.fit_transform(X_base_scaled)
```

Isso vai criar um objeto PCA composto por dois componentes e transforma seus dados originais em novas variáveis. Dois componentes significa que é um <mark style="color:blue;">dataframe composto por duas colunas</mark>: cada componente principal é uma nova variável gerada pela combinação linear das variáveis originais, que explica uma parte da variância total dos dados. Dois componentes costumam explicar quase toda a variância quando há alta correlação entre as variáveis.

### Exemplo com duas vertentes

Usando o mesmo exemplo dos dados diferentes acima (temos diferentes dados, alguns podem se juntar em uma única razão com PCA e outros não), analisamos como seria o resultado final:

```python
# Faz o PCA da forma tradicional com os dados que podem virar uma só razão
pca = PCA(n_components=2)
X_pca = pca.fit_transform(X_base_scaled)

# Sendo X_vol_scaled o dataframe com uma outra coluna de dados única, não há porque
# criar um PCA em uma única variável.
# Essa linha concatena o PCA calculado X_pca com a outra coluna
X_final = np.hstack([X_pca, X_vol_scaled])
```

[^1]: Lembrando que uma variável em uma base de dados equivale a uma dimensão.

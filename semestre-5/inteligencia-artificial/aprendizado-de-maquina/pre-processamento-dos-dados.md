# Pré processamento dos dados

## Normalização dos dados

A normalização dos dados podem ser usadas em diversos contextos. Em treinamento de modelos de aprendizagem de máquina, é muito importante normalizar dados antes de aplicar quaiquer técnicas para uma melhor eficiencia.

A normalização é recomendada <mark style="color:blue;">quando os dados não seguem a mesma magnitude</mark> e amplitude. Se uma coluna for um valor em porcentagem e a outra em número inteiro, isso pode pesar muito no algoritmo de distância. Manter os dados na mesma escala vai deixar cálculos mais precisos e não fazer com que uma coluna pese mais que a outra.

Para normalizar, usamos os métodos do **NumPy**, passando como parâmetro um dataframe `df` com as nossas variáveis:

```python
scaler = StandardScaler()             # Cria o objeto para normalização
df_scaled = scaler.fit_transform(df)  # Normaliza os dados
```

Essa normalização dos dados calcula a média e o desvio padrão de cada coluna (com `fit`) e depois aplica a fórmula de normalização (com `transform`).

<figure><img src="../../../.gitbook/assets/antes e depois da normalização.png" alt=""><figcaption></figcaption></figure>

### Exemplo prático com dados diferentes

Vamos supor que nossa base de dados possua colunas de diferentes tipos, como dados financeiros e dados numéricos. Para normalizar, temos que separá-las em diferentes dataframes por conta de terem uma magnitude diferente.

```python
# Separando criando um novo dataframe
X_base = df[['Open', 'High', 'Low']]
X_volume = df[['Volume']]
```

Depois de separado, fazemos o mesmo processo acima. Mas agora como temos dois dataframes, separamos o resultado normalizado:

```python
# Aqui para as primeiras variáveis em X_base, resultando em X_base_scaled
scaler_base = StandardScaler()
X_base_scaled = scaler_base.fit_transform(X_base)

# Aqui para as segundas variáveis em X_volume, resultando em X_vol_scaled
scaler_vol = StandardScaler()
X_vol_scaled = scaler_vol.fit_transform(X_volume)
```

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

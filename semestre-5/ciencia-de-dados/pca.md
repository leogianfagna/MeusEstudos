# PCA

Tem como objetivo <mark style="color:blue;">reduzir a dimensionalidade</mark> dos nossos dados. Pense em um gráfico 3D, onde temos pontos muito próximos e sobrepostos, o PCA é sobre encontrar o ângulo correto para visualizar os dados da melhor maneira.

Ele permite que possamos reduzir os dados a ponto que fique em duas dimensões. Isso implica que os eixos (nossas variáveis) deixem de ser as nossas colunas conhecidas e se tornem <mark style="color:purple;">componentes</mark> `PC1`, `PC2` e assim por diante. Essas novas dimensões tem a melhor <mark style="color:green;">variância total explicada</mark>, e cada componente tem a sua contribuição na explicação dos dados. Ou seja, o PCA encontra a importância de cada coluna.

Veja o resultado do PCA: em laranja são os dados explicados pelos componentes criados. Perceba que as informações ao longo do eixo são removidas pois elas de fato são menos importantes para a explicação do conjunto de dados.

<figure><img src="../../.gitbook/assets/pca explicado em gráfico.png" alt=""><figcaption></figcaption></figure>

{% hint style="info" %}
Como temos essa informação da contribuição, sabemos qual coluna é mais importante na nossa base e podemos usar ela individualmente dependendo da necessidade.

```python
import seaborn as sns
sns.heatmap(
    pca.components_, # PCA treinado
    fmt='.2f',
    annot=True,
    xticklabels=df.columns, # Nossa base de dados
    yticklabels=range(1, d+1) # Sendo d o número de componentes escolhido
)
```
{% endhint %}

## Maldição da dimensionalidade

O grande objetivo do PCA é corrigir esse termo. Quanto mais dimensões, mais nossos pontos ficam dispersos no gráfico, ou seja, mais difícil é para fazer cálculos de distância e então afetando os algoritmos.

Não apenas isso mas também o peso computacional de guardar e processar várias dimensões.

## Olhar matemático

O PCA vai resultar em uma matriz de coeficientes e cada linha é um componente. Na matemática, podemos ver esses componentes como vetores, onde o componente define a direção e a variância explicada define o comprimento quadrático, desta forma:

<figure><img src="../../.gitbook/assets/comprimento quadratico componentes.png" alt=""><figcaption></figcaption></figure>

### Resultado dos componentes na matriz

Como dito acima, cada linha da matriz representa um componente e as linhas possuem as importâncias de cada coluna. Por exemplo, podemos ter esse resultado:

<figure><img src="../../.gitbook/assets/grafico de calor para componentes pca.png" alt=""><figcaption></figcaption></figure>

Isso quer dizer que o primeiro componente (primeira linha) é composto de 0.19 de length + 0.16 de diamater e assim por diante.&#x20;

## Explicação de cada componente

O objetivo é sempre explicar os dados e por isso precisamos descobrir para treinar o algoritmo o melhor número total de componentes, tomando como objetivo <mark style="color:green;">explicar 95% da base de dados</mark>. Quando não conseguimos atingir este número, implica em que os dados estão dispersos de forma muito próxima e pouco explicativa em um gráfico, ficando difícil a compreensão para fazer um agrupamento.

<figure><img src="../../.gitbook/assets/dispersao ruim pca.png" alt=""><figcaption></figcaption></figure>

Esse é um exemplo com apenas dois componentes principais, em uma base de dados com 64 dimensões. Repare que alguns dados estão conseguindo ser explicados mas outros não.

### Encontrar o número ideal de componentes

O método `fit` sempre é usado para treinar algo, sendo responsável por aprender os componentes e descobrir a variância explicada neste caso. Usar o objeto PCA **sem informar o número de componentes** vai fazer o modelo <mark style="color:green;">calcular todos os componentes possíveis</mark>. Depois temos a propriedade que mostra a importância de cada componente com `explained_variance_ratio_`.

```python
from sklearn.decomposition import PCA
import numpy as np

# Modelo base: calcular todos os componentes possíveis
pca = PCA().fit(data)

print(pca.explained_variance_ratio_)            # [0.50, 0.30, 0.15, 0.05]
print(np.cumsum(pca.explained_variance_ratio_)) # [0.50, 0.80, 0.95, 1.00]

# Alternativa: Mostrar graficamente
plt.plot(np.cumsum(pca.explained_variance_ratio_))
plt.xlabel('number of components')
plt.ylabel('cumulative explained variance');
```

Então no exemplo acima, vimos que os 95% são explicados até o terceiro componente, de todos os 4 da base original. Então, de forma inteligente podemos definir `d=3` para treinar nosso PCA.

{% hint style="success" %}
A propriedade `explained_variance_ratio_` pode ser usada em modelos já definidos o número de componentes, assim, podemos ver a importância de cada um deles que definimos.
{% endhint %}

## Uso prático

Normalmente, o PCA é utilizado usando bases de treino e teste.

```python
X = dados_colunas
y = nosso_rotulo

# Separar os dados acima em treino e teste
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# Uso do PCA. Precisamos definir "n_components"
pca = PCA(n_components=n_components)
X_train_pca = pca.fit_transform(X_train)
X_test_pca = pca.transform(X_test)
```

Com o PCA treinado, podemos usá-lo em modelos de IA como [KNN](../inteligencia-artificial/aprendizado-de-maquina/supervisao/algoritmos/knn.md) ou [Regressão linear](../inteligencia-artificial/aprendizado-de-maquina/supervisao/algoritmos/regressao-linear.md).

## Padronização

O PCA é sensível à escala das variáveis, aquele assunto tratado em normalização onde temos colunas com diferentes magnitudes. Aquela variável com a maior escala vai dominar a análise e influenciar no treino do PCA.

Por isso, é recomendado fazer a padronização dos dados de entrada antes com [StandardScaler](normalizacao-e-padronizacao.md#standardscaler).

## Tópicos para abordar

* Como o PCA transforma as variáveis originais em componentes principais?
* O que é a variância explicada em PCA?
* Por que é recomendável padronizar os dados antes de aplicar o PCA?
* O que acontece com a interpretabilidade dos dados após a aplicação do PCA?
* Quais outras estratégias, além do PCA, podem ser utilizadas para reduzir a  \
  dimensionalidade de um conjunto de dados?
* O que fazer antes do PCA (drop de colunas, etc)

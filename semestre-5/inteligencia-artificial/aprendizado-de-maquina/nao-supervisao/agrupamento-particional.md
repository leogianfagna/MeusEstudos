# Agrupamento particional

{% hint style="success" %}
Veja na prática como é feito [aqui](https://github.com/leogianfagna/MachineLearning/tree/main/Machine%20Learning/Agrupamento%20Particional).
{% endhint %}

Esse agrupamento tem o objetivo de encontrar <mark style="color:blue;">grupos relacionados mas distintos</mark>, onde cada amostra precisa ser **obrigatoriamente atribuída a apenas um grupo**. Essa atribuição se chama <mark style="color:purple;">particionamento</mark>.

Então, aqui as amostras não possuem hierarquias entre elas. Por exemplo, dividir estilos de músicas mas não usar sub grupos. O uso de sub grupos é sobre [agrupamento hierárquico](agrupamento-hierarquico.md).

## Formação de grupos

Para nós humanos, quando os grupos estão sendo mostrados visualmente em um gráfico ou coisa do tipo, identificar padrões e formar grupos pode ser fácil e intuitivo (pois estamos vendo aquilo), mas para os algoritmos não é simples. Algumas dificuldades incluem:

* Como **definir** os grupos de forma matemática?
* Como lidar com **outliers** que podem distorcer os resultados?
* Como lidar com dados que possuem **mais de** [**duas dimensões**](#user-content-fn-1)[^1]?

### **Algoritmo do K-Means**

Tem como objetivo <mark style="color:blue;">ajustar centroides repetidamente</mark> para posições centrais de grupos e minizar o erro. Um <mark style="color:purple;">centroide</mark> representa o <mark style="color:blue;">ponto médio de um grupo dentro de um conjunto de dados</mark>, ou seja, neste algoritmo cada grupo possui um centroide (também chamado de cluster).

Ele inicia fazendo um posicionamento de `k` centroides de forma aleatória e depois ir ajustando eles para próximos a cada iteração. Para descobrir quantos centroides são (ou seja, o número de k), utiliza-se a <mark style="color:purple;">**técnica do joelho**</mark>.

<figure><img src="../../../../.gitbook/assets/Algoritmo do K-Means.png" alt="" width="357"><figcaption></figcaption></figure>

#### Técnica do cotovelo

Utilizado para saber quantos centroides terão, cria-se um gráfico sendo `X` o número de K e `Y` a variância. Vamos simulando a variância para cada número de K.

Conforme o número de K aumenta, o gráfico vai mudando (pois a variância diminui) podendo criar **uma** curva mais impactante. Essa curva é chamada da **cotovelo**.

Como nem toda mudança de K cria um cotovelo, é possível ver que o gráfico não tem tanta variação assim a partir de um certo ponto, virando quase uma linha contínua. Precisamos analisar o gráfico e encontrar o <mark style="color:blue;">melhor ponto que simboliza o cotovelo</mark>. Veja o exemplo:

<figure><img src="../../../../.gitbook/assets/metodo do cotovelo.png" alt="" width="563"><figcaption></figcaption></figure>

<mark style="color:green;">A quantidade de centroides que a amostra terá será a posição do eixo x que se encontra o cotovelo</mark>. Nesse exemplo, a melhor opção foi circulada e ela se encontra no `eixo x = 3`. Portanto, nessa amostra de dados, devemos ter 3 centroides.

Na prática, simulamos a dispersão de dados 10 vezes, uma com cada quantidade de clusters. Armazemos o erro quadrático (explicado abaixo) em um vetor para conseguir criar esse gráfico acima:

<figure><img src="../../../../.gitbook/assets/treinar modelo do kmeans.png" alt=""><figcaption></figcaption></figure>

<details>

<summary>Plotar o gráfico do cotovelo</summary>

Usando o exemplo acima, teremos:

```python
X = iris.data
sse = []

for k in range(1, 11):
    kmeans = KMeans(n_clusters=k, random_state=42, n_init=10)
    kmeans.fit(X)
    sse.append(kmeans.inertia_)

plt.figure(figsize=(8, 5))
plt.plot(range(1, 11), sse, marker='o')
plt.title('Método do Joelho')
plt.xlabel('Número de Clusters')
plt.ylabel('Soma dos Quadrados das Distâncias (Inércia)')
plt.show()
```

</details>

### **Erro Quadrático**

O erro quadrático é uma forma de medir a <mark style="color:blue;">qualidade do agrupamento</mark>. Ele é calculado somando **a distância de cada ponto ao seu centróide** e elevando esse valor [ao quadrado](#user-content-fn-2)[^2].

Se o erro quadrático for zero, significa que todos os pontos do cluster estão exatamente no mesmo local (caso raro na prática). Quanto **menor** o erro quadrático, melhor o agrupamento.

Veja abaixo na prática qual o agrupamento é o melhor (aquele com menor distância quadrática):

<figure><img src="../../../../.gitbook/assets/agrupamento de centroides.png" alt="" width="563"><figcaption></figcaption></figure>

## Clusterização na prática

Com dados organizados e não nulos, [preparados desta forma](definicao.md#como-os-dados-estao), e ao encontrar o número de clusters com a técnica do cotovelo visto acima, a clusterização vai separar a base de dados em grupos. Precisamos saber que:

<table><thead><tr><th width="217">Método ou propriedade</th><th>O que faz</th><th>Retorna</th></tr></thead><tbody><tr><td><code>KMeans(...)</code></td><td>Prepara um modelo do que será feito. Então veja que ele é atribuído a uma variável, como <code>kmeans</code>.</td><td>O modelo a ser treinado.</td></tr><tr><td><code>fit(data)</code></td><td>Treina o modelo (encontra os centróides).</td><td>None.</td></tr><tr><td><code>predict(X)</code></td><td>Atribui cada ponto a um cluster (então exige encontrar os centróides previamente).</td><td>Retorna os rótulos.</td></tr><tr><td><code>fit_predict(X)</code></td><td>Faz os dois de uma vez (fit + predict).</td><td>Retorna os rótulos.</td></tr><tr><td><code>cluster_centers_</code> (propriedade do kmeans)</td><td>Acessar os centróides <strong>finais</strong> dos clusters (então já exige estar treinado).</td><td>Retorna uma matriz de coordenadas de cada centróide.</td></tr></tbody></table>

### Os rótulos

Veja acima ao dizer que retorna os rótulos. Isso é um vetor que indica onde cada dado pertence, exemplo:

<figure><img src="../../../../.gitbook/assets/como os rotulos estão na ordem.png" alt="" width="375"><figcaption></figcaption></figure>

```python
# Obter rótulos
kmeans = KMeans(n_clusters=3, random_state=42, n_init=10)
y_kmeans = kmeans.fit_predict(X)
centroids = kmeans.cluster_centers_

# Exibição gráfica (dados e centróides)
plt.scatter(X[:, 0], X[:, 1], c=y_kmeans, cmap='viridis')
plt.scatter(centroids[:, 0], centroids[:, 1], marker='X', s=200, color='red')
plt.xlabel('Sepal length (cm)')
plt.ylabel('Sepal width (cm)')
plt.title('K-Means Clustering com dados da base Iris')
plt.show()

# Adicionar os rótulos aos clusters
iris_df = pd.DataFrame(X, columns=iris.feature_names)
iris_df['Cluster'] = y_kmeans
print(df_iris.head())
```

### Normalização de dados

Em técnicas como KMeans, pode ser recomendado normalizar os dados antes de aplicar a clusterização. A normalização também é recomendada <mark style="color:blue;">quando os dados não seguem a mesma magnitude</mark> e amplitude.

Se uma coluna for um valor em porcentagem e a outra em número inteiro, isso pode pesar muito no algoritmo de distância. Manter os dados na mesma escala vai deixar cálculos mais precisos e não fazer com que uma coluna pese mais que a outra.

Para normalizar, usamos os métodos do _NumPy_:

```python
scaler = StandardScaler()             # Cria o objeto para normalização
df_scaled = scaler.fit_transform(df)  # Normaliza os dados
```

Essa normalização dos dados Calcula a média e o desvio padrão de cada coluna (com `fit`) e depois aplica a fórmula de normalização (com `transform`).

<figure><img src="../../../../.gitbook/assets/antes e depois da normalização.png" alt=""><figcaption></figcaption></figure>

[^1]: Cada aspecto deste dado é uma <mark style="color:purple;">dimensão</mark>, como nome, idade, salário, etc. Se temos mais de dois aspectos, isso quer dizer que é mais do que bidimensional, o que implica que não pode ser mais representado em um plano cartesiano.



    Os agrupamentos precisam levar todas as dimensões em consideração.

[^2]: Elevar ao quadrado enfatiza os erros maiores, garantindo que pequenas mudanças na posição dos centroides tenham um impacto significativo.

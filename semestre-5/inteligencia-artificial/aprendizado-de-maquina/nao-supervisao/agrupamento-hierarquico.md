# Agrupamento hierárquico

{% hint style="success" %}
Veja na prática como é feito [aqui](https://github.com/leogianfagna/MachineLearning/tree/main/Machine%20Learning/Agrupamento%20Hier%C3%A1rquico).
{% endhint %}

Enquanto o agrupamento particional quebra os dados em grupos diretamente, o hierárquico cria uma estrutura em árvore para visualizar agrupamento em vários níveis.

Exemplo disso poderia ser divisão de estilos de música, onde um grupo chamado Rock possui vários subgrupos como Rock Clássico, Hard Rock, Punk, etc. Cada música pertence a apenas uma categoria dessas.

Tem como <mark style="color:green;">vantagem</mark> não precisar conhecer a quantidade de grupos e também detectar facilmente outliers.

#### Aglomerativo versus decisivo

São duas maneiras de fazer o agrupamento:

* Aglomerativo: ou bottom-up, onde começamos com um grupo para cada amostra  &#x20;e vamos juntando grupos até termos um único grupo.
* Divisivo: ou top-down, onde começamos com um único grupo com todas as  &#x20;amostras e vamos dividindo esse grupo até termos grupos unitários (ou  &#x20;singletons).

## Matriz distância

É uma ferramenta usada para <mark style="color:blue;">determinar como os dados serão agrupados</mark>. Além dos agrupamentos, ela também mede **quão próximos ou distantes** os pontos estão uns dos outros.

Montar uma matriz que recebe a distância dos pontos para conseguir montar o agrupamento de dados. Primeiro vamos <mark style="color:blue;">preencher toda a matriz com a distância</mark> que os dados se encontram, baseado neste exemplo:

<figure><img src="../../../../.gitbook/assets/agrup ia - matriz distancia.png" alt=""><figcaption></figcaption></figure>

Teremos uma matriz completamente preenchida desta forma:

<figure><img src="../../../../.gitbook/assets/agrup ia - matriz distancia completa.png" alt=""><figcaption></figcaption></figure>

Para formar um agrupamento, usamos algum [método de Linkage](agrupamento-hierarquico.md#metodos-de-linkage) (que será nosso critério de ligação). Podemos escolher alguma dessas metologias para montar os grupos, neste caso, vamos escolher o Single Linkage que é baseado no ponto mais próximo.

Vamos iniciar pegando o ponto mais próximo, equivalente ao menor valor que existe na tabela. Esse valor está vinculando dois dados, então esses valores formarão um novo grupo (que já podemos desenhar a hierarquia no plano).

<figure><img src="../../../../.gitbook/assets/agrup ia - achar menor ligação.png" alt=""><figcaption></figcaption></figure>

Depois de um novo grupo, a matriz precisa ser refeita. As conexões entre os pontos sem relação com o novo grupo mantem a mesma coisa. Já os outros valores que fazem relação com esse grupo são atualizados com a maior distância dele mesmo com o novo grupo.

Para isso, basta com quem do novo grupo o ponto se conecta. Escolher o maior número, desta forma (exemplo para o ponto `C`):

<figure><img src="../../../../.gitbook/assets/agrup ia - atualizar matriz com nova distancia.png" alt=""><figcaption></figcaption></figure>

Então preenchendo com a maior distância temos a matriz atualizada:

<figure><img src="../../../../.gitbook/assets/agrup ia - como achar nova distancia.png" alt=""><figcaption></figcaption></figure>

E depois todo o processo recomeça aqui. Com a nova matriz atualizada, voltamos para a primeira etapa de resgatar o ponto mais próximo e formar um grupo. Porém agora, ao resgatar a menor distância:

* Se for 2 pontos: cria um novo grupo (separado) na hierarquia.
* Se for um ponto com um grupo: cria uma hierarquia maior.

<figure><img src="../../../../.gitbook/assets/agrup ia - grupo que forma nova hierarquia.png" alt=""><figcaption></figcaption></figure>

E apenas repetindo o processo repetidamente...

<figure><img src="../../../../.gitbook/assets/agrup ia - dois grupos separados no plano.png" alt=""><figcaption></figcaption></figure>

Nesse último caso, onde é a distância de um grupo para outro, o raciocínio segue o mesmo: o ponto mais distante de um dado deste grupo até outro dado do outro grupo, que equivale `(DE)` sendo `43`.

<figure><img src="../../../../.gitbook/assets/agrup ia - finalização do agrupamento.png" alt=""><figcaption></figcaption></figure>

## Métodos de Linkage

Será o método escolhido para fazer o agrupamento de dados na abordagem hierarquica, é uma família de algoritmos.&#x20;

Essa família de algoritmos <mark style="color:green;">não precisa da informação da distribuição&#x20;dos pontos</mark> (como o k-means precisava), mas opera apenas com as distâncias relativas entre as amostras.

<table><thead><tr><th width="167">Método</th><th width="155">Premissa</th><th width="182">Resultado</th><th>Desvantagem</th></tr></thead><tbody><tr><td>Single Linkage (usado no exemplo)</td><td>Une com base na <strong>menor distância.</strong></td><td><strong>Clusters mais alongados</strong> e pode formar "cadeias" de pontos.</td><td>Sensível a outliers.</td></tr><tr><td>Complete Linkage</td><td>Une com base na <strong>maior distância.</strong></td><td>Produz <strong>clusters mais compactos e arredondados</strong>.</td><td>Menos sensível a outliers, mas pode quebrar clusters naturais se houver muita variação interna.</td></tr><tr><td>Average Linkage</td><td>Une com base no cálculo da média da distância.</td><td>Agrupamentos geralmente mais naturais.</td><td></td></tr></tbody></table>

A analise de um agrupamento hierárquico depende de plotar o gráfico, desta forma:

```python
# Base de dados
iris = load_iris()
X = iris.data

linkage_data = linkage(X, method='average', metric='euclidean')
plt.figure(figsize=(10, 7))
plt.title("Dendrograma da Iris")
dendrogram(linkage_data, truncate_mode='level', p=5)
plt.xlabel("Índice das amostras")
plt.ylabel("Distância entre clusters")
plt.show()
```

<figure><img src="../../../../.gitbook/assets/resultado de linkages.png" alt=""><figcaption></figcaption></figure>

{% hint style="info" %}
Métrica usada foi distância **euclidiana**, muito comentado ao longo do aprendizado e usada como **padrão**. Mas poderia ser diferente, como `manhattan`.
{% endhint %}

#### Divisão dos grupos

Então veja no gráfico acima a formação de 3 grupos (amarelo, vermelho e laranja), parecido com a clusterização do KMeans. O <mark style="color:orange;">algoritmo mostrado acima não dividiu os grupos</mark> e apenas representou o agrupamento.

Para de fato rotulá-los, definimos em quantos grupos queremos dividir. Nossa escolha pode ser cortar mais embaixo e conseguir mais grupos, ou dividir apenas em 3 como mostra nas cores. Utilizamos o método `fcluster` que recebe o `linkage_data` gerado acima:

```python
rótulos_hierarquicos = fcluster(linkage_data, t=3, criterion='maxclust')
df_iris['Cluster'] = rótulos_hierarquicos
```

### Bisecting K-Means

O K-Means possui algumas limitações significativas que devem ser consideradas ao aplicá-lo. Um dos principais problemas é a maneira como os centroides são inicialmente selecionados, o que pode impactar consideravelmente o resultado final da análise. Além disso, o algoritmo requer as posições específicas das amostras, o que pode não ser viável em todos os casos. Outra limitação é a tendência do K-Means em formar grupos em formato de globo, o que pode não representar adequadamente a distribuição real dos dados.

Por outro lado, o Bisecting K-Means é uma variação que busca resolver alguns dos problemas associados ao K-Means tradicional. Ele não sofre do "chainning effect", uma situação em que dados que formam uma cadeia ou sequência podem resultar em clusters inadequados.

O metodo bisecting K-Means funciona iterativamente, iniciando com todos os dados agrupados e <mark style="color:blue;">divide o conjunto de dados em partes menores até que o número desejado de clusters seja alcançado</mark>. Isso pode levar a melhores resultados em termos de qualidade dos clusters e pode ser uma abordagem mais robusta em muitos cenários.

<figure><img src="../../../../.gitbook/assets/Bisecting K-Means.png" alt="" width="375"><figcaption></figcaption></figure>

## Medir abordagem

Para medir a qualidade de um particionamento podemos seguir duas abordagens.

### Critérios externos

Esse critério funciona <mark style="color:orange;">apenas com dados rotulados</mark> e, como possuímos esses rótulos, podemos encontrar um <mark style="color:purple;">padrão-ouro</mark>, que é uma representação do melhor agrupamento possível que pode ser feito.

Então pegamos o nosso agrupamento e comparamos com esse padrão, para ver se o nosso agrupamento acertou ou errou. Isso é feito dado por dado, por exemplo, conferir se `X` e `Y` formam uma dupla.

Nisso, juntamos nossos resultados em uma <mark style="color:purple;">matriz de confusão</mark>, que leva algumas variáveis:

* Mesmo grupo no algoritmo e no padrão-ouro: ✅ **True Positive** `TP`
* Grupos diferentes no algoritmo e no padrão-ouro: ✅ **True Negative** `TN`
* Mesmo grupo no algoritmo, grupos diferentes no padrão-ouro: ❌ **False Positive** `FP`
* Grupos diferentes no algoritmo, mesmo grupo no padrão-ouro: ❌ **False Negative** `FN`

A cada ocasião, vai somando para cada variável. Então, se nosso algoritmo acertou a formação de uma dupla, soma +1 para `TP` e assim vai. E então, montamos a nossa matriz:

<figure><img src="../../../../.gitbook/assets/matriz confusão.png" alt="" width="563"><figcaption></figcaption></figure>

Com esses dados prontos, podemos incluir em uma fórmula que melhor se encaixa na nossa situação (existem ainda outras mais complexas):

<table><thead><tr><th width="154">Nome</th><th width="383">Utilização</th><th>Fórmula</th></tr></thead><tbody><tr><td>Precisão</td><td>Mede a relação entre acerto e erro, considerando todos os pares</td><td>a / a + b</td></tr><tr><td>Acurácia</td><td>Mede a relação entre acerto e erro, considerando todos os pares.</td><td>a + d / a + d + b + c</td></tr><tr><td>Sensibilidade</td><td>Mede a capacidade do modelo de identificar corretamente as amostras <a data-footnote-ref href="#user-content-fn-1">positivas</a>.</td><td>a / a + c</td></tr><tr><td>Especificidade</td><td>Mede a capacidade do modelo de identificar corretamente as amostras <a data-footnote-ref href="#user-content-fn-2">negativas</a></td><td>d / d + b</td></tr><tr><td>F1-score</td><td>Média <a data-footnote-ref href="#user-content-fn-3">harmônica</a> entre precisão e sensibilidade</td><td>2 * a / 2 * a + b + c</td></tr></tbody></table>

### Critérios internos/relativo

Os critérios internos avaliam a qualidade dos clusters sem usar rótulos reais (sem padrão-ouro). Eles analisam apenas a estrutura dos dados e os agrupamentos gerados. Os conceitos chaves são:

* Compactação: Quão próximo os elementos estão de outro, dentro de um grupo. Portanto, uma melhor qualidade seria <mark style="color:green;">elementos mais próximos</mark>.
* Separabilidade: Quão distante grupos estão de outros. Portanto, uma melhor qualidade seria <mark style="color:green;">grupos mais distantes</mark>.

Um bom particionamento seria ter alta compactação e alta separabilidade. Nisso, já podemos pensar no <mark style="color:purple;">índice da silhueta</mark> que junta esses conceitos <mark style="color:blue;">avaliando cada ponto</mark> comparando:

* **a**: distância média para os pontos do **mesmo cluster** (coesão)
* **b**: menor distância média para pontos de **outro cluster** (separação)

<figure><img src="../../../../.gitbook/assets/fórmula da silhueta.png" alt=""><figcaption></figcaption></figure>

O índice `s(i)` vai resultar em um valor de -1 até 1, sendo mal agrupado ou perfeitamente agrupado respectivamente. O valor zero indica estar na fronteira do cluster. Repare a necessidade de ter mais de um elemento em um cluster para não haver divisão por zero.

Existe a forma <mark style="color:purple;">Xie-Beni</mark> (outra métrica), que também mede isso. Quanto mais próximo a zero melhor é, pois indica que os grupos estão mais próximos. Ela não tem disponibilidade no sklearn e deve ser implementada manualmente.

[^1]: Útil em problemas onde é mais crítico detectar a classe positiva, como diagnóstico    \
    médico.

[^2]: Essencial quando um falso positivo pode ser problemático (ex: alarme falso de    \
    fraude bancária).

[^3]: É útil quando há um desequilíbrio entre as classes e não queremos favorecer uma    \
    métrica sobre a outra.

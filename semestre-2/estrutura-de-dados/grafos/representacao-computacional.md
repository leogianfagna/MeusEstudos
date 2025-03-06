# Representação computacional

Como um grafo é representado em um código? Ele é feito através de matrízes ou vetores. Como toda estrutura de dados, essa matriz ou lista pode ser representada visualmente. Veja um exemplo de como essas duas estruturas são representadas para um mesmo exemplo:

<figure><img src="../../../.gitbook/assets/representacao computacional de grafo.png" alt=""><figcaption></figcaption></figure>

## Com matriz

É gerado uma matriz de tamanho `n`, sendo ele o total de vértices do grafo. <mark style="color:blue;">A posição da matriz</mark> que tem alguma conexão, torna-se o número `1` (ou outro valor, depende da representação).

<figure><img src="../../../.gitbook/assets/represent grafo nao direcionado.png" alt="" width="563"><figcaption></figcaption></figure>

Como no exemplo é um grafo não direcionado, ambas as posições vão receber o valor `1`, chamamos isso de <mark style="color:purple;">simetria</mark>. Contudo, se a aresta possuir uma direção, ele será marcado <mark style="color:orange;">apenas da posição origem até destino</mark>. Veja abaixo o exemplo:

<figure><img src="../../../.gitbook/assets/represent grafo direcionado.png" alt="" width="455"><figcaption></figcaption></figure>

Não apenas com zeros e um, mas em <mark style="color:purple;">multigrafos</mark> é permitido mais de uma conexão entre os <mark style="color:orange;">mesmos vértices</mark>. Esse caso é representado pelo número do grau dele, desta forma:

<figure><img src="../../../.gitbook/assets/represent multigrafo.png" alt="" width="452"><figcaption></figcaption></figure>

## Com vetores

É gerado um <mark style="color:blue;">objeto</mark> para representar o grafo, que cada <mark style="color:blue;">campo do objeto representa o vértice</mark> e o <mark style="color:blue;">dado deste campo é um vetor/array com suas conexões</mark>. Veja o exemplo:

<figure><img src="../../../.gitbook/assets/represent objeto grafo.png" alt="" width="546"><figcaption></figcaption></figure>

Portanto, os vértices devem mostrar no vetor <mark style="color:green;">com quem eles se conectam</mark>. Podem existir vetores mais complexos para exibir mais informações, como o multigrafo, por exemplo:

```python
# Aqui informamos quantas arestas estão conectadas a partir daquele vértice
grafo = {
    1: {3: 2},   # 1 -> 3 (duas arestas)
    2: {4: 1},   # 2 -> 4 (uma aresta)
    3: {2: 4, 4: 3},  # 3 -> 2 (peso 4), 3 -> 4 (peso 3)
    4: {}
}
```

Isso quer dizer que o mesmo representado pelas matrizes <mark style="color:green;">também pode ser representados com os vetores</mark>, embora talvez seja mais difícil.

{% hint style="info" %}
Existem outros tipos de valores que podem ser usados, diferente do zero, um, grau, etc. Precisamos sempre saber que esse número tem relação com a conexão entre dois vértices e é influenciado se ele é direcionado ou não.
{% endhint %}

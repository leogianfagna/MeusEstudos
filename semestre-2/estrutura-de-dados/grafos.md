# Grafos

Conjunto de vértices[^1] (V) e arestas[^2] (E) que são usados para representar [situação reais](#user-content-fn-3)[^3] em um diagrama, estabelecendo conectividade entre informações.

Surgiu para resolver problemas do tipo: é possível passar por todas as regiões sem repetir pontes? O problema é <mark style="color:blue;">substituído por um grafo morfologicamente correspondente</mark> ou podemos chamar de <mark style="color:blue;">simplificação matemática</mark>.

{% hint style="info" %}
Toda [árvore](arvores.md) é um grafo, mas nem todo grafo é uma árvore.
{% endhint %}

## Arestas

Elas podem ser ou não ser direcionadas. Isso implica se o caminho só pode seguir uma direção apenas. Essas direções são utilizadas depois para medir [grau de um vértice](grafos.md#grau-de-um-vertice).

<figure><img src="../../.gitbook/assets/direção de arestas.png" alt="" width="359"><figcaption></figcaption></figure>

## Vértices

Com um grafo formado junto com as arestas, podemos percorrê-lo. O espaço percorrido denominamos:

* <mark style="color:purple;">**Caminho**</mark>: Sequência de um vértice a outro, sem repetir vértices e arestas por onde passou.
* <mark style="color:purple;">**Trilha**</mark>: Sequência de um vértice a outro, sem repetir arestas por onde pasou mas pode repetir os vértices.

### Grau de um vértice

É o resultado de medir a quantidade de entradas saídas.

<figure><img src="../../.gitbook/assets/graus de vertices.png" alt="" width="563"><figcaption></figcaption></figure>

## Representação computacional

Como um grafo é representado em um código? Ele é feito através de matrízes ou vetores. Como toda estrutura de dados, essa matriz ou lista pode ser representada visualmente. Veja um exemplo de como essas duas estruturas são representadas para um mesmo exemplo:

<figure><img src="../../.gitbook/assets/representacao computacional de grafo.png" alt=""><figcaption></figcaption></figure>

### Com matriz

É gerado uma matriz de tamanho `n`, sendo ele o total de vértices do grafo. <mark style="color:blue;">A posição da matriz</mark> que tem alguma conexão, torna-se o número `1` (ou outro valor, depende da representação).

<figure><img src="../../.gitbook/assets/represent grafo nao direcionado.png" alt="" width="563"><figcaption></figcaption></figure>

Como no exemplo é um grafo não direcionado, ambas as posições vão receber o valor `1`, chamamos isso de <mark style="color:purple;">simetria</mark>. Contudo, se a aresta possuir uma direção, ele será marcado <mark style="color:orange;">apenas da posição origem até destino</mark>. Veja abaixo o exemplo:

<figure><img src="../../.gitbook/assets/represent grafo direcionado.png" alt="" width="455"><figcaption></figcaption></figure>

Não apenas com zeros e um, mas em <mark style="color:purple;">multigrafos</mark> é permitido mais de uma conexão entre os <mark style="color:orange;">mesmos vértices</mark>. Esse caso é representado pelo número do grau dele, desta forma:

<figure><img src="../../.gitbook/assets/represent multigrafo.png" alt="" width="452"><figcaption></figcaption></figure>

### Com vetores

É gerado um <mark style="color:blue;">objeto</mark> para representar o grafo, que cada <mark style="color:blue;">campo do objeto representa o vértice</mark> e o <mark style="color:blue;">dado deste campo é um vetor/array com suas conexões</mark>. Veja o exemplo:

<figure><img src="../../.gitbook/assets/represent objeto grafo.png" alt="" width="546"><figcaption></figcaption></figure>

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

[^1]: Conteúdo: `V = {A, B, C}`.

    Em inglês chamado de vertice, `V`.

[^2]: Conexões: `A = {(A,B), (B,C)}`.

    Em inglês chamado de edge, `E`.

[^3]: Rede de metrô, rede de computador, cidades, conexões e até **Inteligência Artificial**.

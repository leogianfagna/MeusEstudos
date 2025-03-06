# Definição

Conjunto de vértices[^1] (V) e arestas[^2] (E) que são usados para representar [situação reais](#user-content-fn-3)[^3] em um diagrama, estabelecendo conectividade entre informações.

Surgiu para resolver problemas do tipo: é possível passar por todas as regiões sem repetir pontes? O problema é <mark style="color:blue;">substituído por um grafo morfologicamente correspondente</mark> ou podemos chamar de <mark style="color:blue;">simplificação matemática</mark>.

{% hint style="info" %}
Toda [árvore](../arvores.md) é um grafo, mas nem todo grafo é uma árvore.
{% endhint %}

## Arestas

Elas podem ser ou não ser direcionadas. Isso implica se o caminho só pode seguir uma direção apenas. Essas direções são utilizadas depois para medir [grau de um vértice](definicao.md#grau-de-um-vertice).

<figure><img src="../../../.gitbook/assets/direção de arestas.png" alt="" width="359"><figcaption></figcaption></figure>

## Vértices

Com um grafo formado junto com as arestas, podemos percorrê-lo. O espaço percorrido denominamos:

* <mark style="color:purple;">**Caminho**</mark>: Sequência de um vértice a outro, sem repetir vértices e arestas por onde passou.
* <mark style="color:purple;">**Trilha**</mark>: Sequência de um vértice a outro, sem repetir arestas por onde pasou mas pode repetir os vértices.

### Grau de um vértice

É o resultado de medir a quantidade de entradas saídas.

<figure><img src="../../../.gitbook/assets/graus de vertices.png" alt="" width="563"><figcaption></figcaption></figure>

[^1]: Conteúdo: `V = {A, B, C}`.

    Em inglês chamado de vertice, `V`.

[^2]: Conexões: `A = {(A,B), (B,C)}`.

    Em inglês chamado de edge, `E`.

[^3]: Rede de metrô, rede de computador, cidades, conexões e até **Inteligência Artificial**.

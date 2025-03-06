# Busca

Busca na verdade significa **percorrer**, define como um algoritmo percorre um grafo. Chamamos de busca caso queremos um vértice específico e queremos retorná-lo, sem percorrer os demais após isso.

Existem dois tipos de busca. Ambos se iniciam através de um **vértice qualquer**, normalmente, o primeiro que foi inserido.

## Busca em profundidade

Consiste em visitar um [vértice adjacente](#user-content-fn-1)[^1] que não tenha sido visitado ainda, criando um caminho e visitando todos. Quando há mais de um vértice adjacente, é visitado [aquele que veio primeiro](#user-content-fn-2)[^2].

Percorrendo o grafo, quando não existem vértices adjacentes novos para visitar, usa como método o <mark style="color:purple;">**backtracinkg**</mark>, que consistem em retroceder pelo mesmo caminho até que encontre um vértice não adjancente e seguir para ele. Repete o processo até que todos os vértices sejam visitados.

<figure><img src="../../../.gitbook/assets/primeiro passo - busca profundidade.png" alt="" width="526"><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/segundo passo - busca profundidade.png" alt="" width="563"><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/terceiro passo - busca profundidade.png" alt="" width="497"><figcaption></figcaption></figure>

A mesma lógica se aplica quando temos inúmeros vértices. Caso abaixo de `2` tivesse muitos outros vértices, o backtracking ia ser longo até voltar ao `1` novamente e visitar o `3`.

Nessa representação, também foi visto a ordem de prioridade, visitando o `2` antes do `3`. Se tivéssemos 10 vértices adjacentes, a lógica é a mesma, visitando um por um na ordem de prioridade.

Lembrando que a visita é apenas para os que não foram visitados ainda. Se chegasse no vértice `3` por outro caminho, ele não ia ser visitado novamente após voltar para o `1`.

## Busca em largura

Consiste em percorrer vértices [através de uma fila](../fila.md), para que visite os vértices **em níveis** (como se fosse uma árvore).

<figure><img src="../../../.gitbook/assets/exemplo de niveis em grafo.png" alt="" width="305"><figcaption></figcaption></figure>

A fila inicia com um elemento, um **vértice inicial**.

Visita o primeiro elemento da fila e confere os vértices adjacentes à ele (aqui podemos chamar de descendentes). Todos esses vértices são adicionados ao final da fila (baseado na ordem de prioridade, vista acima).

Depois disso, a primeira posição é liberada e a fila anda. E assim, repete exatamente o mesmo processo acima, <mark style="color:blue;">adicionado na fila os vértices descendentes àquele que está na primeira posição</mark>. Lembrando que, se um vértice já foi visitado, ele não é incluído na fila. O processo continua até que a fila fique vazia.

<figure><img src="../../../.gitbook/assets/busca em largura.png" alt=""><figcaption></figcaption></figure>

Então perceba que sempre é usado a fila como base para saber quem percorrer e o grafo é apenas utilizado para saber quem é adjancente à quem, para saber quem incluir na fila.

## Grafos desconexo

Supondo que a gente tenha um vértice desconexo, isto é, há "dois grafos" que não estão sendo ligados por nenhuma aresta. Nesse caso, deve terminar de percorrer o grafo atual e depois inicia em algum vértice desse outro grafo.

## Gerando uma árvore

Em qualquer um dos métodos acima, se depois de percorrer todo o grafo retirarmos as arestas que não foram usadas, a estrutura vai se tornar uma [árvore](../arvores.md), ou árvore de busca em profundidade ou árvore de busca em largura. Elas não são necessariamente árvores binárias.

Caso exista a presença de um grafo desconexo, essa estrutura vai se chamar de <mark style="color:purple;">**floresta**</mark>.

[^1]: Um outro vértice que faz conexão com  ele através de uma aresta.

[^2]: Vulgo o vértice que foi colocado primeiro na estrutura de dados grafo. Em outras palavras, segue uma ordem de prioridade do mais antigo para o mais novo.

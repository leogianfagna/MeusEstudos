# Ordenação topológica

É uma ordenação direcionada do grafo, colocando os vértices em uma linha deixando claro que para chegar em um, precisa passar por outro. Ela só é possível ser realizada em grafos direcionados acíclicos.

Para montar ordenação, podemos usar os tipos de [busca em largura ou profundidade](busca.md). Tem como resultado final essa representação:

<figure><img src="../../../.gitbook/assets/ordenação topológica de grafos.png" alt=""><figcaption><p><a href="https://professor.ufop.br/sites/default/files/george/files/a08_ordenacao_topologica_0.pdf">https://professor.ufop.br/sites/default/files/george/files/a08_ordenacao_topologica_0.pdf</a></p></figcaption></figure>

## **Usando DFS (Busca em Profundidade)**

Utiliza o mesmo método da busca em profundidade, ou seja, caminhando pelos vértices vizinhos.

1. Criar uma pilha para ordenar.
2. Caminhar pelos vértices até chegar em um que não tenha mais opções de visita, aquele que necessita fazer o backtracking. Adicionar esse vértice na pilha.
3. Após visitar todos os nós, desempilhe os elementos para obter a ordenação.

## **Usando BFS (Algoritmo de Kahn)**

Este método usa o [grau de um vértice](definicao.md#grau-de-um-vertice) para determinar a ordem.

1. Fazer uma tabela com todos os vértices e o grau de cada um ao lado.
2. Começar a colocar em uma fila todos os vértices de grau zero. Quando há mais de um, pode escolher qualquer.
3. Ao colocar esse vértice na fila, "remova" ele do grafo. Isso é, [atualize o grau dos seus vizinhos](#user-content-fn-1)[^1]. Isso vai diminuindo os graus até que fiquem zero e ai o processo vai se repetindo.

[^1]: Se você colocou um vértice X na fila e removeu ele do grafo, agora todo mundo que se conectava reduziu 1 grau, pois ele não existe mais.

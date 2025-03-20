# Caminho mínimo

Um algoritmo de busca que tem como objetivo <mark style="color:blue;">encontrar o menor custo</mark> (construindo uma árvore de caminho mínimo), similar à busca em largura mas com uma fila de prioridade. Esse algoritmo é chamado de <mark style="color:purple;">**Algoritmo de Dijkstra**</mark>.

Para isso, as arestas passam a ter pesos. Quem é o peso? Ele é relativo para o contexto, podendo ser a distância, tempo, preço, depende do que queremos economizar.

## Como funciona

<mark style="color:purple;">Travar vértices</mark> significa que aquela célula está em seu estado final e bloqueia qualquer outro preenchimento em outra célula abaixo dela.

#### Inicialização da iteração zero

1. Utilizar uma tabela auxiliar onde cada coluna é um vértice. Cada célula vai representar o custo. A representação é `(vertice de origem, custo acumulado)`.
2. Inicia o vértice inicial com custo `zero` e o restante com `infinito`.
3. Travar o vértice inicial.

#### Iterações

1. Avance uma linha de iteração na tabela (desça uma linha).
2. Copiar todas as informações da linha anterior, exceto a célula correspondente ao **vértice que acabou de ser travado**
3. Atualização das distâncias dos **vizinhos** do último vértice travado:
   1. <mark style="color:orange;">Para cada vértice vizinho do vértice recém-travado</mark>, anotar a distância/custo.
   2. Possivelmente, talvez já tenha algum vértice ali. <mark style="color:green;">Se a nova distância for menor</mark>, atualize-a.
4. Travar o vértice com a menor distância acumulada. Veja na última linha quem tem o menor número e trave ela. No caso de empate, pode-se escolher livremente qual travar. Recomece o processo.

Essa distância é <mark style="color:red;">acumulada</mark>. Isso quer dizer que, ao marcar a distância do vértice B -> C, não é simplesmente qual é o custo da aresta (B,C) mas esse **valor somado** com a distância que já havia necessitado para chegar em B.

Então, se o custo da aresta (B,C) é `10`, mas para chegar em B é `3`, então a distância que precisa ser colocada na tabela equivale a `13`.

Mas qual era a distância até chegar em B? Bom, se queremos encontrar B -> C é porque acabamos de travar o B. Se ele foi travado, vai ter uma representação nele, por exemplo: (I,3). Então a acumulada pega essa distância 3 como base. Veja um exemplo disso:

<figure><img src="../../../.gitbook/assets/custo acumulado dijkstra.png" alt=""><figcaption></figcaption></figure>

#### Exemplo de &#xD;&#xD;Dijkstra completo

<figure><img src="../../../.gitbook/assets/Exemplo de Dijkstra completo.png" alt=""><figcaption></figcaption></figure>

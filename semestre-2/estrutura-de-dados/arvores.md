# Árvores

Uma árvore é uma estrutura de dados <mark style="color:blue;">não linear</mark> caracterizada por ter uma raiz, com dois ou mais ponteiros para derivações (nós). É usada por sua rapidez de busca por eliminar possibilidades em grandes quantidades (divide por 2).

## Terminologia

* Raíz: Topo da hierarquia.
* Nós: São as derivações da árvore. Pode ser [pai, filho ou irmão](#user-content-fn-1)[^1].
  * Nomeação de nós:
    * Nó interno: Um nó que tem um filho ao menos
    * Nó externo: Nós que não possuem filhos.
  * Conjunto de nós:
    * Ancestrais: Da raíz até o pai.
    * Descententes: Todos os nós a partir do filho.
    * Sub-árvore: Toda a árvore a partir dele mesmo.
  * Características:
    * Profundidade: Quantos níveis o nó desceu. A raíz é nível zero. Pode ser usado também para medir a [profundidade da árvore](#user-content-fn-2)[^2].
    * Grau: Corresponde a quantidade de filhos que o nó possui. Pode ser usado também para medir o [grau da árvore](#user-content-fn-3)[^3].
* Árvore binária: Quando há apenas duas derivações da raíz.
* Árvore estritamente binária: Todos os nós tem dois ou nenhum filho. Usada para expressões aritméticas onde nós internos são operadores e o externos são os números/operandos.
* Árvore binária cheia: É uma árvore estritamente binária mas que todos os nós se encerram na mesma profundidade.

<figure><img src="../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

## Funcionamento

<mark style="color:blue;">Elementos adicionados</mark> são comparados com a raíz. Se a árvore for uma struct de clientes, a comparação pode ser usado o número de CPF, mas precisa comparar alguma coisa. Pressupõe que não há dados repetidos.

* Se o nó inserido for <mark style="color:blue;">maior</mark> que o nó comparado: Vai para a <mark style="color:blue;">direita</mark> ->
* Se o nó inserido for <mark style="color:blue;">menor</mark> que o nó comparado: Vai para a <mark style="color:blue;">esquerda</mark> <-

Ás árvores não se re-organizam então pode ter números bem maiores lá em baixo, o que pode ficar esquisito mas é pela ordem de inserção e continua funcionando normal. A busca também é feito com comparações seguindo o mesmo caminho direita/esquerda dependendo do resultado.

A árvore permite <mark style="color:blue;">remover qualquer nó</mark> dela. Se o nó removido tiver filhos, um nó irá assumir o lugar do pai, [esse nó será](#user-content-fn-4)[^4] o menor número do caminho da direita ou o próprio filho caso seja filho único.

<figure><img src="../../.gitbook/assets/remoção de elementos de árvores.png" alt=""><figcaption></figcaption></figure>

## Parte estrutural da árvore

Assim como pilhas e filas, são dois ponteiros:

* **Ponteiro que representa um nó da árvore**: Composto por três dados, a informação, o ponteiro da esquerda e o ponteiro da direita.
* **Ponteiro que representa a árvore**: Comporto por um dado, o ponteiro da raíz.

```c
struct no {
    int info;
    struct no *esq;
    struct no *dir;
};

struct arvore {
    struct no *raiz;
};
```

## Operações



O struct da árvore é um nó apenas para a raiz. Os demais são cada nó da árvore do jeito que falamos.

Vai ter dois struct: árvore e nó.

Cada nó guarda o dado e esquerdo e direito.

A inserção consiste ficar procurando se o nó está nulo (se é um espaço livre para ele conseguir preencher). Se não for nulo, segue seguindo entre direita e esquerda do nó existente.

Usa recursividade para ficar conferindo, já que é um looping com condições iguais sempre.

[^1]: É igual uma árvore genealógica. Não é só pegar elementos na mesma linha e sim de fato elementos que tem o mesmo pai.

[^2]: "A árvore tem nível 3 de profundidade".

[^3]: "A árvore tem grau 2", que é o nó com mais filhos que tem. Nesse caso, não há nenhum nó com mais de dois filhos.

[^4]: Existem outros métodos de fazer isso.

# Fila de prioridade

A fila de prioridade é uma fila normal mas os elementos são <mark style="color:blue;">organizados por uma prioridade</mark> associada.  Para conseguir utilizá-las, usamos um algoritmo chamado <mark style="color:purple;">heap</mark>.

O heap é uma estrutura de dados baseadas em **árvores binárias**. A ideia é que a inserção na fila não é no final, e sim baseado <mark style="color:blue;">na posição que ela deve estar de acordo com a sua prioridade</mark>. Então, um resultado final seria mais ou menos assim:

<figure><img src="../../.gitbook/assets/inserção na árvore de fila de prioridade.png" alt="" width="563"><figcaption></figcaption></figure>

> (Tem o max e min heap, mas a diferença entre eles é basicamente um compara com o menor e o outro com maior, não é necessário ficar definindo tanto)

## Algoritmo do Heap

Esse algoritmo é usado tanto para inserir ou remover os elementos.

#### Inserção de novos elementos

Os nós são representados pela sua **prioridade**. Eles são <mark style="color:orange;">inseridos na árvore do jeito clássico</mark>. Depois de inserir, esse nó é passado por um <mark style="color:blue;">rearranjo</mark>, que esse elemento passa a subir na árvore (troca de lugar com o seu pai) se a prioridade for maior. Vai subindo na árvore até que não seja mais possível (pai seja maior que ele ou ele esteja na raiz). Isso vai fazer com que a <mark style="color:green;">raiz sempre seja a de maior prioridade</mark>.

<figure><img src="../../.gitbook/assets/algoritmo do heap.png" alt=""><figcaption></figcaption></figure>

#### Remoção de elementos

Como funciona a remoção (quando o primeiro elemento da fila é usado)? O [nó mais à direita do último nível](#user-content-fn-1)[^1] <mark style="color:blue;">vai para a raíz</mark>.

<figure><img src="../../.gitbook/assets/substituir raiz por um nó.png" alt=""><figcaption></figcaption></figure>

Depois disso, precisa <mark style="color:orange;">perguntar aos filhos dessa nova raiz</mark> se eles são maiores que ele. Se são maiores, precisam trocar de lugar recursivamente até que se encaixem na ordem certa. Basicamente do mesmo jeito da inserção, mas na ordem contrária.

<figure><img src="../../.gitbook/assets/substituição de nós.png" alt=""><figcaption></figcaption></figure>

### Representação por vetor

Toda essa abordagem pode ser representada por um vetor. Esse vetor é uma <mark style="color:blue;">representação fiel</mark> da árvore gerada, onde os elementos do vetor são os elementos da árvore de cima para baixo (nível por nível).

<figure><img src="../../.gitbook/assets/ultimo nivel da arvore.png" alt="" width="375"><figcaption></figcaption></figure>

Mas como saber quem é filho de quem e onde inserir? É possível encontrar o pai e filhos através de uma fórmula que utiliza o <mark style="color:blue;">índice do vetor</mark> como base, recebendo o resultado em um tipo `int`, isso significa que os valores sempre serão **inteiros** e **arredondados** para baixo:

* Pai: `(i-1) / 2`, lembrando que raíz não tem pai.
* Filho esquerdo: `2i + 1`.
* Filho direito: `2i + 2`.

<figure><img src="../../.gitbook/assets/arvores em vetores descobrir pai.png" alt="" width="563"><figcaption></figcaption></figure>

#### Remanejamento usando vetores

A inserção sempre será no último índice disponível. Então um novo elemento entra no final do vetor, mas depois, ele <mark style="color:orange;">precisa ser remanejado</mark>.

O remanejamento com vetor é a mesma forma (tanto remoção quanto inserção). Vai fazer as comparações necessárias com o pai ou com o filho, descobrindo quem são eles através da fórmula.

<figure><img src="../../.gitbook/assets/exemplo pratico de prioridade com vetores.png" alt=""><figcaption></figcaption></figure>

{% hint style="success" %}
O exemplo prático acima é sobre inserção, onde o novo elemento entra no final do vetor. Para o algoritmo de remoção, o elemento em questão está no `vetor[0]`, que passa a ser vazio. Depois, aplicar as regras de substituição, procurando pelos **filhos**.
{% endhint %}

[^1]: Ou seja, vai **lá em baixo** da árvore e resgata o **maior número** que encontrar ali. Pega esse nó e coloca na raiz.

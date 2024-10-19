# Lista ligada

Um [vetor](vetores-e-matrizes.md), toda vez que insere ou remove posições tem que copiar todos os demais elementos para uma posição acima ou abaixo, tornando-o muito custoso. Por isso, surgiu as listas ligadas que são uma [struct](struct.md). Suas vantagens são:

* Memória usada equivale ao que usa de fato, não precisa declarar tamanho antecipadamente assim como vetor.
* Não sequenciado: não precisa mexer em todos elementos ao adicionar ou remover um novo nó.

Uma struct sendo uma estrutura de elementos, a lista ligada funciona com cada desse elemento possuindo um <mark style="color:blue;">ponteiro que aponta para o próximo elemento</mark>, sendo o <mark style="color:blue;">último um ponteiro nulo</mark>. Isso torna algo não sequenciado, o que significa que podemos adicionar elementos em qualquer posição e apenas mudar o ponteiro da posição anterior, sem necessariamente mudar todo o restante. A remoção acontece da mesma forma, removendo um elemento e mudando o ponteiro do anterior para apontar para o próximo.

<figure><img src="../../.gitbook/assets/modelo de lista ligada.png" alt=""><figcaption></figcaption></figure>

Esse exemplo acima mostra como elas não necessariamente estão organizadas sequencialmente dentro da memória. Como o uso de memória acontece de forma dinâmica, esses detalhes e usos são essenciais:

* `malloc` é necessário para adicionar um elemento
* `free` é necessário ao remover um elemento
* `sizeOf` com o parâmetro o tamanho da struct é usado para ver a quantidade de memória alocada.

## Acesso à elementos

Por conta que listas ligadas não possuem índices como vetores, não é possível acessar diretamente um elemento em uma posição específica da lista, por exemplo, `vetor[3]`. Lembrando que, elas não possuem índices pois os elementos (nós) estão <mark style="color:blue;">espalhados na memória</mark> e cada nó contém um ponteiro para o próximo nó.

O <mark style="color:purple;">primeiro elemento é chamado de cabeça</mark> (ou head). Acessar um elemento precisa caminhar por todos começando a partir do primeiro elemento.

## Como usar

### 1 - Estrutura de um nó

Cada elemento da lista se chama nó e possui a estrutura comentada acima:

* Dado: é o que aquele nó vai armazenar.
* Ponteiro para o próximo nó:
  * Ponteiros possuem o tipo do elemento que eles apontam.
  * O tipo de um elemento de uma struct é sempre `struct` + `o nome da Struct`.
  * Por isso, em caso de dúvidas ler [esse tópico](struct.md).

```c
struct Node {
    int data;
    struct Node *next;
};
```

### 2 - Cabeça da lista

Também conhecido como head, é o primeiro elemento da lista ligada que vai fazer nossa lista nascer. A partir deste ponto, estaremos acessando dados de uma struct através de ponteiros, o que começa a ser necessário usar o operador `->` que é explicado em [ponteiros em struct](struct.md#ponteiros-em-struct).

* Acessar membros da struct pode ser feito usando o ponto, por exemplo minhaStruct.data.
* Agora, quando a variável é um pontiero que aponta para uma struct, acessar **os mesmos dados** passa a ser o operador de seta.

Portanto, esse passo consiste em declarar o head (que precisa fazer o malloc como dito acima) e definir os dados da struct. O primeiro dado "data" é como a gente quiser mas o ponteiro para a próxima struct sempre é iniciada como `NULL`, pois ainda não há uma ligação para outro elemento. Como a cabeça head é um ponteiro, os elementos da struct são acessados com as setas.

```c
int main() {
    struct Node *head = (struct Node*)malloc(sizeOf(struct Node));
    head->data = 10;
    head->next = NULL;

    return 0;
}
```

### 3 - Inserir novo nó no final

A inserção de novos elementos na lista é mais comum no final. A criação desse novo elemento segue o mesmo padrão que a criação do cabeçalho, a diferença é que vamos precisar mudar o ponteiro do elemento anterior para que aponte para o novo elemento.

```c
int main() {
    // Código anterior

    struct Node *second = (struct Node*)malloc(sizeOf(struct Node));
    second->data = 15;
    second->next = NULL;

    head->next = second; // Aponta o cabeçalho para o novo ponteiro

    // Código posterior
}
```







## Como usar v2

Tecnicamente falando, para começar a usar uma lista, é necessário realizar esses seguintes passos:

1. Declarar a estrutura do nó: vai conter o dado e o ponteiro para a próxima posição.
2. Função para inicializar: podemos inicializar o primeiro elemento da lista como nulo, isso porque, ele não tem para onde apontar, portanto inicializar ele dessa forma e sem dados está correto.
3. Função para inserir: vai criar uma alocação dinâmica de memória que equivale a um novo elemento e depois retorna o endereço de memória (um ponteiro) referente a esse elemento. Esse retorno vai ser necessário para o próximo elemento inserido usá-lo para apontar para ele, ligando os dois.
4. Função para percorrer:&#x20;


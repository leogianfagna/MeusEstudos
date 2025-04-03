# Lista ligada

Um [vetor](linguagem-c/vetores-e-matrizes.md), toda vez que insere ou remove posições tem que copiar todos os demais elementos para uma posição acima ou abaixo, tornando-o muito custoso. Por isso, surgiu as listas ligadas que são uma [struct](linguagem-c/struct.md). Suas vantagens são:

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

## Como funciona a criação

A lista ligada pode ser feito inserindo os elementos no **final** da lista ou no **início**:

* Início: A main vai conter um ponteiro chamado "lista" que deve SEMPRE possuir o <mark style="color:green;">endereço de memória da posição zero</mark>. Por isso, usar `inserir()` ou `inserirPos()` deve <mark style="color:orange;">**retornar**</mark> esse endereço. Não podemos só chamar a função pois precisamos ter esse ponteiro atualizado.

<figure><img src="../../.gitbook/assets/ponteiros de lista retornando.png" alt=""><figcaption></figcaption></figure>

* Final: Usar um ponteiro extra, chamado "pri" que tem a primeira posição da lista e consegue percorrer todo o restante.

Essa escolha vai influenciar se o próximo elemento vai apontar para a cabeça ou se a cabeça vai apontar para o próximo elemento. <mark style="color:blue;">Ambos os casos</mark>, sempre vai ser necessário <mark style="color:blue;">possuir um ponteiro que indica a primeira posição da lista</mark>. No caso de estudos a seguir, utilizamos a técnica de inserir no início, onde a forma estrutural pode ser vista [visualmente aqui](broken-reference).

O caso de inserir em uma posição específica vai precisar ter um if/else dentro da função para garantir que vai retornar o endereço certo. Se inserir na posição zero, retorna o novo elemento. Se inserir em qualquer outra posição, retorna o que já tinha (o que foi passado pelo parâmetro).

## Como usar lista ligada

### 1 - Estrutura de um nó

Cada elemento da lista se chama nó e possui a estrutura comentada acima:

* Dado: é o que aquele nó vai armazenar.
* Ponteiro para o próximo nó:
  * Ponteiros possuem o tipo do elemento que eles apontam.
  * O tipo de um elemento de uma struct é sempre `struct` + `o nome da Struct`.
  * Por isso, em caso de dúvidas ler [esse tópico](linguagem-c/struct.md).

```c
struct No {
    int dado;
    struct No *proximo;
};
```

### 2 - Cabeça da lista

Também conhecido como head, é o primeiro elemento da lista ligada que vai fazer nossa lista nascer. A partir deste ponto, estaremos acessando dados de uma struct através de ponteiros, o que começa a ser necessário usar o operador `->` que é explicado em [ponteiros em struct](linguagem-c/struct.md#ponteiros-em-struct).

* Acessar membros da struct pode ser feito usando o ponto, por exemplo minhaStruct.data.
* Agora, quando a variável é um ponteiro que aponta para uma struct, acessar **os mesmos dados** passa a ser o operador de seta.

Inicializar a cabeça da lista pode ser feita através de uma função que na main vai ser atribuída ao primeiro elemento da lista. O primeiro ponteiro sempre será iniciado com NULL pois ainda não há uma ligação para outro elemento:

```c
struct No* incializar() {
    return NULL;
}

int main() {
    struct No* lista = inicializar();
    ...
}
```

### 3 - Inserir novo nó no início

Usaremos uma função que vai criar uma <mark style="color:green;">alocação dinâmica</mark> de memória que equivale a um novo elemento e, <mark style="color:blue;">como agora ele é o primeiro elemento</mark>, vamos retornar o ponteiro dele.

```c
struct No* inserir(struct No* lista, int valor) {
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->dado = valor;
    novo->proximo = lista;
    
    return novo;
}

int main() {
    ...
    
    lista = inserir(lista, 10);
    lista = inserir(lista, 20);
    lista = inserir(lista, 30);
}
```

A função inserir recebe como parâmetro o ponteiro "lista", pois ele sempre será a primeira posição. Portanto, ele é necessário para saber para quem o "novo" irá apontar.

<figure><img src="../../.gitbook/assets/inserir na lista ligada.png" alt="" width="375"><figcaption></figcaption></figure>

> Lembrança: o ponteiro "lista" (primeiro elemento) sempre vai apontar para o próximo elemento, então <mark style="color:orange;">não precisamos</mark> se preocupar em mudar nada dele, apenas usar ele para ser apontado.

### 4 - Inserir em posição específica

Assim como o inserir no início, deve retornar a primeira posição da lista, mas agora a primeira posição não necessariamente vai mudar:

* Se a posição específica for zero, tem que retornar o novo ponteiro.
* Se a posição específica não for zero, retorna o mesmo ponteiro de antes (que foi passado no parâmetro).

Essa função temos que fazer duas lógicas diferentes, pois se não for a posição zero, terá que percorrer a lista inteira até achar a posição que quer, usando dois ponteiros auxiliares. A ideia é criar o ponteiro `atual` e ponteiro `anterior` para armazenar duas posições seguidas, pois assim, ao encontrar a posição que queremos, podemos colocar o <mark style="color:blue;">novo elemento no meio dos dois</mark>.

```c
struct No* inserirPos(struct No* lista, int valor, int pos) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    novo->dado = valor;
    
    if (pos == 0) {
        novo->proximo = lista;
        return novo;
    }
    
    int counter = 0;
    struct No* atual = lista;
    struct No* anterior = NULL;
    
    // Avançando as posições com nós auxiliares
    while (counter != pos) {
        anterior = atual;
        atual = atual->proximo;
        counter++;
    }
    
    // Encaixar na fila
    if (atual == NULL) {
        printf("Posição maior que lista");
    } else {
        novo->proximo = atual;
        anterior->proximo = novo;
    }
    
    return lista; // "novo" não é posição zero, portanto retornar lista
}

int main() {
    ...
    lista = inserirPos(lista, 40, 2);
}
```

#### Percorrendo até chegar na posição desejada

<figure><img src="../../.gitbook/assets/iteração de ponteiros auxiliares em lista c.png" alt=""><figcaption></figcaption></figure>

#### Chegou na posição, agora inserir no meio

<figure><img src="../../.gitbook/assets/inserir ponteiro no meio de dois ponteiros.png" alt=""><figcaption></figcaption></figure>

### 5 - Percorrer os elementos

Como sempre armazenamos o primeiro nó é uma função muito simples de iteração. O segredo é que precisamos criar um nó auxiliar que recebe lista, pois não podemos percorrer os elementos de "lista", esse ponteiro é sagrado e não pode ser alterado. Portanto, fazemos isso com um ponteiro auxiliar que vai receber lista.

```c
void percorrer(struct No* lista) {
    if (lista == NULL) {
        printf("Lista nula.");
    }
    
    struct No *aux = lista;
    while (aux->prox != NULL) {
        printf("Valor %d", aux->dado);
        aux = aux->proximo;
    }
}
```

### 6 - Buscar elementos

Consiste em percorrer com um ponteiro auxiliar todos os elementos da lista, até que o dado seja o valor procurado. Precisa de uma condição `while (atual != null)` para percorrer o tamanho total da lista, pois imagine que nunca encontre o elemento, se não tiver esse while, percorreria para sempre.

Ele retorna um novo ponteiro, mas esse novo ponteiro não pode ser atribuído à variável que guarda a primeira posição (no nosso caso "lista"). Portanto, na main ele é atribuído a um novo, que assim pode fazer o que quiser com ele.

```c
int main() {
    ...
    struct No* buscarElemento = buscar(lista, 40);
}

struct No* buscar(struct No* lista, valor) {
    struct No *aux = lista;
    
    while (aux != NULL) {
        
        if (aux->dado == valor) return aux;
        aux = aux->proximo;
    
    }
    
    return NULL; // Nada encontrado
}
```

### 7 - Remover elementos

Vai percorrer os dados usando dois ponteiros (igual ao buscarPos) pois ao encontrar o elemento para remover, vai precisar ajeitar os ponteiros ligados à posição removida. No caso de remover, usamos o método `free()`.

Possui a lógica de percorrer semelhante aos demais e vai conferindo se `atual->dado` é o elemento certo para remover. Se ele for, existem duas possibilidades:

#### 1) Elemento a ser removido está na primeira posição

* Retorno: Isso vai mudar o que será retornado. Já que sempre temos que retornar o primeiro da lista, se o primeiro for removido precisamos retornar o próximo dele, que vai ser `atual->proximo`.
* Checagem: Conferimos se é o primeiro elemento se satisfazer a condição `if (anterior == NULL)` pois iniciamos o ponteiro "anterior" como NULL, então se ele for nulo significa que o ponteiro não saiu do lugar pois encontrou direto na primeira posição.
* O que fazer: Definir novo primeiro elemento. A nova "lista" será `atual->proximo`, que é o elemento seguinte daquele que foi removido.

#### 2) Elemento a ser removido está no meio da lista

* Retorno: Neste caso retornamos o próprio "lista" passado pelos parâmetros, ele vai continuar sendo o primeiro elemento.
* Checagem: Basicamente o else da condição acima, caso o ponteiro "anterior" não for nulo.
* O que fazer: o ponteiro "atual" é o ponteiro a ser removido, então será `free(atual)`. Já que ele vai ser removido, precisa ajeitar o ponteiro "anterior" que antes apontava para ele. Encontramos a posição seguinte com `anterior->proximo = atual->proximo`. Como mostra o desenho abaixo.

<figure><img src="../../.gitbook/assets/remover pos em lista ligada.png" alt=""><figcaption></figcaption></figure>

A função é construída com um while percorrendo todos os elementos até encontrar, em vez de criar condições encadeadas.

```c
struct No* remover(struct No* lista, int valor) {

    struct No* anterior = NULL;
    struct No* atual = lista;
    
    // Percorrer
    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL) {
        printf("Elemento não encontrado");
        return lista;
    }
    
    if (anterior == NULL) {
        lista = atual->proximo; // É o primeiro elemento
    } else {
        anterior->proximo = atual->proximo; // Está no meio da lista
    }
    
    free(atual);
    return lista;
}
```

### 8 - Liberar a lista (memória)

Consiste em percorrer todos os nós e liberando um por um usando free(). Para isso é necessário dois ponteiros pois já salva o próximo nó em um ponteiro e apaga o atual. Ainda sim é criado o ponteiro "atual" para preservar o "lista" apenas por comodidade pois teoricamente não seria necessário.

```c
void liberarLista(struct No* lista) {
    
    struct No* atual = lista;

    while (atual != NULL) {
    
        struct No* temp = atual;
        atual = atual->proximo;
        free(temp);
        
    }
}
```



## Detalhe importante de funcionamento

Quando precisamos de um ponteiro auxiliar, do tipo aux, a gente faz ele receber a lista de parâmetro, por exemplo:

```c
void exemplo(struct No* lista)
{
    struct No *aux = lista;
    aux = aux->proximo;
}
```

Mas a dúvida que fica é, já que "aux" recebe "lista", alterar "aux" não alteraria a "lista" por se tratarem de ponteiros? Na verdade, não pois quando fazemos `*aux = lista` estamos fazendo eles <mark style="color:red;">apontarem para o mesmo lugar, mas não serem o mesmo ponteiro</mark>. Então `aux->proximo` vai alterar apenas o ponteiro "aux", deixando "lista" intacto.

Eles podem apontar para a mesma coisa inicialmente, mas são ponteiros diferentes e cada um possui seu próprio endereço de memória.

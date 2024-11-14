# Pilha

Filas, pilhas e árvores são listas ligadas, só que possuem formas estruturais e filosofias diferentes:

* Filosofia da pilha: O primeiro a entrar é o primeiro a sair
* Estrutura: Novo struct que guarda um <mark style="color:blue;">ponteiro do topo</mark> para ter fácil acesso.

A forma estudada será que o elemento topo aponta para o elemento abaixo e o primeiro da pilha aponta para NULL.

## Operações necessárias

* Inicializar estrutura (ou não, pode inicializar na main como nulo)
* Inserir elemento no topo
* Retirar elemento do topo
* Imprimir
* Liberar

As pilhas ganham a nomenclatura de push e pop para inserir e remover elementos. Vemos também que são menos operações já que não temos a possibilidade de escolher uma posição para retirar ou inserir, sendo assim, operações a menos.

## Como usar pilhas

<figure><img src="../../.gitbook/assets/esquema estrutural das operações da pilha.png" alt=""><figcaption></figcaption></figure>

### 1 - Estrutura dos nós

Como dito acima, a pilha utiliza duas structs. A struct nó não será passada como parâmetro nas operações de remoção, etc. Isso porque o primeiro elemento pode ser acessada através da struct pilha, que guarda o ponteiro para o topo.

<figure><img src="../../.gitbook/assets/ordenação de pilha.png" alt=""><figcaption></figcaption></figure>

A struct que guarda o dado seria passada como parâmetro em caso de editar os dados ali dentro (int, char, etc), de resto o importante é a <mark style="color:blue;">struct que guarda o ponteiro do topo</mark>.

```c
struct no {
    int dado;
    struct no *prox;
};

struct pilha {
    struct no *topo;
};
```

### 2 - Inicialização

Ambos os ponteiros nascem vazios. A struct nó só nasce dentro das funções inserir quando chamadas.

```c
int main() {
    struct pilha* f = (struct pilha*)malloc(sizeof(struct pilha));
    p->top = NULL;
    ...
}
```

### 3 - Inserir (push) um elemento

A inserção de um elemento, de forma simplificada, vai consistir em:

* Atribuir o dado, usando `novo->dado = valor`.
* Atribuir o ponteiro, usando `novo->next = p->top`. Como esse novo elemento é o novo topo, o nó "next" precisa ser o antigo topo, para formar a estrutura.
* Atualizar o ponteiro do novo topo `p->top = novo`. A struct pilha precisa guardar o novo topo atualizado.

A forma completa acrescenta uma checagem para ver se ainda existe memória disponível. Ficando como exemplo final:

```c
void push(struct pilha* p, int valor) {
    struct cliente* novo= (struct cliente*)malloc(sizeof(struct cliente));
    
    novo->dado = valor;
    novo->next = p->top;
    p->top = novo;
}

int main() {
    ...
    struct pilha* f = (struct pilha*)malloc(sizeof(struct pilha));
    ...
    push(10);
    push(20);
}
```

### 4 - Remover (pop) um elemento

Será removido necessariamente o topo. Nesse caso:

* Salvar o topo em um ponteiro auxiliar com `struct no *temp = p->top`. Salvar também o dado que vai ser impresso para depois com `valor = temp->data`;
* Atualizar o topo que agora será a segunda posição usando `p->top = p->top->next`.
* Liberar memória do nó removido, atribuindo o nó a uma struct temporária e usando `free(temp)`.

```c
void removerPrimeiro(struct pilha* p) {
    if (p == NULL) {
        printf("Pilha vazia!");
        return;
    }
    
    struct no *temp = p->top;
    int valor = temp->dado;
    
    p->top = p->top->next;
    
    printf("Elemento atendido: %d", valor);    
    free(temp);
    
    return valor;
}

int main() {
    ...
    removerPrimeiro(p);
    ...
}
```

### 5 - Imprimir

Consiste com um ponteiro auxiliar percorrer toda a pilha [<mark style="color:blue;">partindo o primeiro elemento</mark>](#user-content-fn-1)[^1], até que esse ponteiro seja nulo.

```c
void imprimir(struct pilha *p) {
  struct no *atual = p->top;

  if (atual == NULL) {
    printf("Pilha vazia");
    return;
  }

  while (atual != NULL) {
    printf("- %d", atual->dado);
    atual = atual->next;
  }
}
```

### 6 - Liberar

Mesma lógica de percorrer todos os elementos acima, contudo agora liberando a memória deles. Para isso é necessário de mais um ponteiro para receber a posição atual e usar um free nela, mesma lógica das listas ligadas.

Contudo, agora é necessário anular os ponteiros da struct pilha, já que não vai mais existir primeiro e nem último elemento.

```c
void liberar(struct pilha *p) {
  struct no *atual = p->top;

  while (atual != NULL) {
    struct no *temp = atual;

    atual = atual->next;
    free(temp);
  }

  p->top = NULL;
}

int main() {
    ...
    liberar(f); // Libera a memória
    free(f);    // Libera o ponteiro
    
    return 0;
}
```

[^1]: Pois é o primeiro elemento que aponta para os demais.

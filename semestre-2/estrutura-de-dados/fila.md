# Fila

Filas, pilhas e árvores são listas ligadas, só que possuem formas estruturais e filosofias diferentes:

* Filosofia da fila: Implica que o primeiro a entrar é o primeiro a sair. Só pode inserir no final e retirar do começo.
* Estrutura: Novo struct que guarda um <mark style="color:blue;">ponteiro do primeiro e do último elemento</mark> para ter fácil acesso.

A forma estudada será que o primeiro elemento aponta para o segundo e o último aponta para null, seguindo a ordem inversa.

## Operações necessárias

* Inicializar estrutura (ou não, pode inicializar na main como nulo)
* Inserir elemento (sempre no final)
* Retirar elemento (sempre no início)
* Imprimir
* Liberar

Vemos que são menos operações já que não temos a possibilidade de escolher uma posição para retirar ou inserir, sendo assim, operações a menos.

## Como usar filas

### 1 - Estrutura dos nós

Como dito acima, a fila utiliza duas structs. A struct cliente[^1] não será passada como parâmetro nas operações de remoção, etc. Isso porque o primeiro elemento pode ser acessada através da struct fila, que guarda o ponteiro para ela.

<figure><img src="../../.gitbook/assets/representacao de fila em estruturas.png" alt=""><figcaption></figcaption></figure>

Então a struct cliente não será necessário já que o elemento importante dela pode ser acessada através da outra struct. A struct que guarda o dado seria passada como parâmetro em caso de editar os dados ali dentro (int, char, etc).

### 2 - Inicialização

Ambos os ponteiros nascem vazios. A struct cliente só nasce dentro das funções inserir quando chamadas.

```c
int main() {
    struct fila* f = (struct fila*)malloc(sizeof(struct fila));
    f->first = NULL;
    f->last = NULL;
    ...
}
```

### 3 - Inserir um elemento

A inserção de um elemento, de forma simplificada, vai consistir em:

* Atribuir o dado, usando `novo->dado = valor`.
* Atribuir o ponteiro, usando `novo->next = NULL`. Agora ele será o último elemento, que sempre aponta para NULL.
* Atualizar o ponteiro do penúltimo nó usando `f->last->next = novo`. Até então ele era o último e apontava para NULL, agora ele não é mais o último e deve apontar para o novo.
* Atualizar na struct fila quem é o novo último usando `f->last = novo`.
* Caso a fila estava vazia, precisa atualizar na struct fila quem é o primeiro usando `f->first = novo`. Se estava vazia, o novo será tanto o último quanto o primeiro.

A forma completa acrescenta uma checagem para ver se ainda existe memória disponível. Ficando como exemplo final:

```c
void inserirCliente(struct fila* f, int id, const char* nome) {
    struct cliente* novo= (struct cliente*)malloc(sizeof(struct cliente));
    
    novo->id = id;
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->next = NULL;
    
    if (f->last == NULL) {
        f->first = novo;
    } else {
        // Precisa estar no else pois se tiver vazia, vai tentar trocar o ponteiro
        // de um elemento que não existe. 
        f->last->next = novo;
    }
    
    f->last = novo;
    printf("Cliente adicionado na fila");
}

int main() {
    ...
    struct fila* f = (struct fila*)malloc(sizeof(struct fila));
    ...
    int id = 1;
    char nome[50];
    
    inserirCliente(f, id, nome);
}
```

### 4 - Remover um elemento

Será removido o primeiro elemento por se tratar de fila. Nesse caso:

* Atualizar o ponteiro da primeira posição usando `f->first = f->first->next`. Depois de alterado é necessário conferir se `f->first` não é nulo, pois talvez podia haver um único elemento na lista e agora ela está vazia. Se ela está vazia, precisa atualizar o `f->last` para nulo.
* Liberar memória do nó removido, atribuindo o nó a uma struct temporária e usando `free(temp)`.

```c
void removerPrimeiro(struct fila* f) {
    if (f == NULL) {
        printf("Fila vazia!");
        return;
    }
    
    struct cliente *temp = f->first;
    printf("Elemento atendido: %d %s", temp->id, temp->nome);
    
    f->first = f->first->next;
    if (f->first == NULL) {
        f->last = NULL;
    }
    
    free(temp);
}

int main() {
    ...
    removerPrimeiro(f);
    ...
}
```

### 5 - Imprimir

Consiste com um ponteiro auxiliar percorrer toda a fila [<mark style="color:blue;">partindo o primeiro elemento</mark>](#user-content-fn-2)[^2], até que esse ponteiro seja nulo.

```c
void imprimir(struct fila* f) {
    struct cliente *aux = f->first;
    
    if (aux == NULL) {
        printf("Não há lista para imprimir");
        return;
    }
    
    while (aux != NULL) {
        printf("Nome do cliente: %s.", aux->nome);
        aux = aux->next;
    }
}
```

### 6 - Liberar

Mesma lógica de percorrer todos os elementos acima, contudo agora liberando a memória deles. Para isso é necessário de mais um ponteiro para receber a posição atual e usar um free nela, mesma lógica das listas ligadas.

Contudo, agora é necessário anular os ponteiros da struct fila, já que não vai mais existir primeiro e nem último elemento.

```c
void liberar(struct fila *f) {
    struct cliente *aux = f->first;
    
    while (aux != NULL) {
        struct cliente *temp = aux;
        aux = aux->next;
        free(temp);
    }
    
    f->first = NULL;
    f->last = NULL;
    printf("Lista liberada da memória.");
}

int main() {
    ...
    liberar(f);
    free(f);
    
    return 0;
}
```

[^1]: Será referida pela struct que guarda os dados mais o nó para o próximo.

[^2]: Pois é o primeiro elemento que aponta para os demais.

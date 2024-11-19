#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado;
    struct no *prox;
};

struct no* inicializar() {
    return NULL;
}

// Inserir no início e retornar o mesmo. Nenhuma verificação
struct no* inserir(struct no *lista, int valor) {
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    
    novo->dado = valor;
    novo->prox = lista;
    return novo;
}

// Conferir se inseriu no início para saber se vai retornar o novo nó ou o mesmo nó de antes
// Caso seja no meio, precisa percorrer usando ponteiros auxiliares até que atinja a contagem.
// Percorrer tudo e depois fora do while fazer o necessário. Lembrar desse caso quando há necessidade
// de ajeitar ponteiros depois. Verificação se atual == NULL apenas
struct no* inserirPos(struct no *lista, int valor, int pos) {
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    novo->dado = valor;
    
    if (pos == 0) {
        novo->prox = lista;
        return novo;
    }
    
    struct no *atual = lista;
    struct no *anterior = NULL;
    int counter = 0;
    
    while (counter != pos) {
        anterior = atual;
        atual = atual->prox;
        counter++;
    }
    
    if (atual == NULL) {
        printf("Posição maior que a lista.");
    } else {
        novo->prox = atual;
        anterior->prox = novo;
    }
    
    return lista;
}

// Percorre tudo até o final da lista com nó auxiliar. Verifica se lista é nula
void percorrer(struct no* lista) {
    
    if (lista == NULL) {
        printf("Lista nula!");
    }
    
    struct no *aux = lista;
    while (aux != NULL) {
        printf("Dado: %d\n", aux->dado);
        aux = aux->prox;
    }
}

// Percorre tudo até o final da lista com nó auxiliar. Checa se achou dentro do while
struct no* buscar(struct no* lista, int valor) {
    struct no *aux = lista;
    
    while (aux != NULL) {
        
        if (aux->dado == valor) return aux;
        aux = aux->prox;
    }
    
    return NULL;
}

// Percorre elementos usando dois ponteiros ENQUANTO NÃO ENCONTRA O DADO ou lista é nula. Sabemos se está na
// primeira posição caso o ponteiro "anterior" continue sendo NULO.
struct no* remover(struct no* lista, int valor) {
    struct no* atual = lista;
    struct no* anterior = NULL;
    
    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }
    
    if (atual == NULL) {
        printf("Não encontrado");
        return lista;
    }
    
    if (anterior == NULL) {
        lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    
    free(atual);
    return lista;
}

// Percorrer tudo, precisa de dois nós: um serve para o free e o outro continua percorrendo toda a lista
void liberarLista(struct no* lista) {
    struct no *aux = lista;
    
    while (aux != NULL) {
        struct no *temp = aux;
        aux = aux->prox;
        free(temp);
    }
}

int main()
{
    struct no* lista = inicializar();
    
    lista = inserir(lista, 10);
    lista = inserir(lista, 20);
    lista = inserir(lista, 30);
    lista = inserirPos(lista, 45, 2);
    percorrer(lista);
    
    // Buscar valores
    struct no *busca = buscar(lista, 30);
    if (busca != NULL) {
        printf("Elemento encontrado!\n\n");
    }
    
    lista = remover(lista, 30);
    percorrer(lista);
    
    struct no *busca2 = buscar(lista, 30);
    if (busca2 != NULL) {
        printf("Elemento encontrado!\n\n");
    } else {
        printf("Elemento não encontrado!\n\n");
    }
    
    liberarLista(lista);

    return 0;
}

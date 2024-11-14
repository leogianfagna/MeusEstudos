// Fazer um programa que faz a leitura de uma lista X com N inteiros (N
// deve ser lido tb). Multiplique cada elemento de X por um inteiro K
// (K também deverá ser lido). Imprimir a lista lida, o valor da variável K
// e a lista multiplicada por K.

#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado;
    struct no *prox;
};

struct no* inicializar() {
    return NULL;
}

// Sempre inserir no início e retornar o mesmo
struct no* inserir(struct no *lista, int valor) {
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    
    novo->dado = valor;
    novo->prox = lista;
    return novo;
}

// Conferir se inseriu no início para saber se vai retornar o novo nó ou o mesmo nó de antes
// Caso seja no meio, precisa percorrer usando ponteiros auxiliares até que atinja a contagem.
// Lembrar desse caso quando há necessidade de ajeitar ponteiros depois
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

// Percorre tudo até o final da lista com nó auxiliar
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

// Percorre tudo até o final da lista com nó auxiliar
struct no* buscar(struct no* lista, int valor) {
    struct no *aux = lista;
    
    while (aux != NULL) {
        
        if (aux->dado == valor) return aux;
        aux = aux->prox;
    }
    
    return NULL;
}

// Percorre elementos usando dois ponteiros ENQUANTO NÃO ENCONTRA O DADO. Sabemos se está na primeira posição
// caso o ponteiro "anterior" continue sendo NULO.
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

void multiplicarValores(struct no* lista) {
    struct no *aux = lista;
    int multiplicador;

    while (aux != NULL) {
        printf("Valor a ser multiplicado: ");
        scanf("%d", &multiplicador);

        aux->dado = aux->dado * multiplicador;
        aux = aux->prox;
    }
}

int main()
{
    int totalElementos = 0;
    int elemento;
    
    struct no *lista = inicializar();
    
    printf("Insira o total de elementos que a lista terá: ");
    scanf("%d", &totalElementos);
    
    for (int i = 0; i < totalElementos; i++) {
        printf("Posição %d da lista: ", (i+1));
        scanf("%d", &elemento);

        lista = inserir(lista, elemento);
    }
    
    printf("\nLista Atual:\n");
    percorrer(lista);

    multiplicarValores(lista);

    printf("\nLista Multiplicada:\n");
    percorrer(lista);

    return 0;
}

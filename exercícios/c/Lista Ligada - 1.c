// Fazer um programa que faz a leitura de duas listas X e Y, ambas com
// N reais (N deve ser lido tb). Efetue a multiplicação dos respectivos
// pares de elementos de X por Y, gerando uma terceira lista Z.
// Imprima as listas X, Y e Z.

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

struct no* multiplicarListas(struct no* listaX, struct no* listaY, struct no* listaZ) {
    struct no *auxX = listaX;
    struct no *auxY = listaY;
    
    while (auxX != NULL && auxY != NULL) {
        int multiplicacao = auxX->dado * auxY->dado;
        listaZ = inserir(listaZ, multiplicacao);
        
        auxX = auxX->prox;
        auxY = auxY->prox;
    }
    
    return listaZ;
}

int main()
{
    int totalElementos = 0;
    int counter = 0;
    int elemento;
    
    struct no *listaX = inicializar();
    struct no *listaY = inicializar();
    struct no *listaZ = inicializar();
    
    printf("Insira o total de elementos que a lista terá: ");
    scanf("%d", &totalElementos);
    
    while (counter != totalElementos) {
        printf("Elemento %d da lista X: ", counter);
        scanf("%d", &elemento);
        listaX = inserir(listaX, elemento);
        
        printf("Elemento %d da lista Y: ", counter);
        scanf("%d", &elemento);
        listaY = inserir(listaY, elemento);
        
        counter++;
    }
    
    listaZ = multiplicarListas(listaX, listaY, listaZ);
    
    printf("\nLista X:\n");
    percorrer(listaX);
    
    printf("\nLista Y:\n");
    percorrer(listaY);
    
    printf("\nLista Z:\n");
    percorrer(listaZ);

    return 0;
}

// Elabore uma função que dado uma fila, transforme-a
// em duas filas uma com os números pares e outra com
// os ímpares.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
    int id;
    struct no *prox;
};

struct fila {
    struct no *last;
    struct no *first;
};

void inserirFila(struct fila *f, int id) {
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    
    if (novo == NULL) {
        printf("Sem espaço na memória");
    }
    
    novo->id = id;
    novo->prox = NULL;
    
    // Conferir se a fila havia algum elemento antes
    if (f->last == NULL) {
        f->first = novo;
    } else {
        f->last->prox = novo;
    }
    
    f->last = novo;
}

void atenderFila(struct fila *f) {
    if (f == NULL) {
        printf("Fila vazia.");
        return;
    }
    
    struct no *temp = f->first;
    printf("Elemento atendido: %d", temp->id);
    f->first = f->first->prox;

    // Fila passou a estar vazia? Se sim, precisa atualizar o ponteiro last também
    if (f->first == NULL) {
        f->last == NULL;
    }
    
    free(temp);
}

void printLista(struct fila *f) {
    struct no *aux = f->first;
    
    if (aux == NULL) {
        printf("Fila vazia");
    }
    
    while (aux != NULL) {
        printf("Elemento %d.\n", aux->id);
        aux = aux->prox;
    }
}

void liberarFila(struct fila *f) {
    struct no *aux = f->first;
    
    while (aux != NULL) {
        struct no *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    
    f->first = NULL;
    f->last = NULL;
    printf("Fila liberada");
}

void construirFila(struct fila *f, struct fila *pares, struct fila *impares) {
    struct no *atual = f->first;
    
    while (atual != NULL) {
        
        if (atual->id%2 == 0) {
            inserirFila(pares, atual->id);
        } else {
            inserirFila(impares, atual->id);
        }
        
        atual = atual->prox;
    }
}


int main()
{
    struct fila *f = (struct fila*)malloc(sizeof(struct fila));
    struct fila *pares = (struct fila*)malloc(sizeof(struct fila));
    struct fila *impares = (struct fila*)malloc(sizeof(struct fila));
    
    f->first = NULL;
    f->last = NULL;
    pares->first = NULL;
    pares->last = NULL;
    impares->first = NULL;
    impares->last = NULL;
    
    inserirFila(f, 1);
    inserirFila(f, 3);
    inserirFila(f, 5);
    inserirFila(f, 7);
    inserirFila(f, 9);
    inserirFila(f, 12);
    inserirFila(f, 14);
    inserirFila(f, 16);
    inserirFila(f, 17);
    inserirFila(f, 22);
    inserirFila(f, 25);
    inserirFila(f, 28);
    inserirFila(f, 33);
    inserirFila(f, 38);
    inserirFila(f, 43);
    inserirFila(f, 67);
    
    construirFila(f, pares, impares);
    
    printf("Lista dos pares:\n");
    printLista(pares);
    
    printf("Lista dos ímpares:\n");
    printLista(impares);
    
    // Liberar a fila e o ponteiro
    liberarFila(f);
    liberarFila(pares);
    liberarFila(impares);
    free(f);
    free(pares);
    free(impares);

    return 0;
}

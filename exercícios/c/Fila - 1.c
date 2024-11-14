// Elabore uma função que conte quantos números
// pares possui uma fila e retorne esta quantidade.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
    int dado;
    struct no *prox;
};

struct fila {
    struct no *last;
    struct no *first;
};

void inserirFila(struct fila *f, int dado) {
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    
    if (novo == NULL) {
        printf("Sem espaço na memória");
    }
    
    novo->dado = dado;
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
    printf("Elemento atendido: %d", temp->dado);
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
        printf("Elemento %d", aux->dado);
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

int getCountNumerosPares(struct fila *f) {
    struct no *aux = f->first;
    int valorResgatado, qtdNumerosPares = 0;
    
    while (aux != NULL) {
        valorResgatado = aux->dado;
        
        if (valorResgatado%2 == 0) {
            qtdNumerosPares++;
        }
        
        aux = aux->prox;
    }
    
    return qtdNumerosPares;
}


int main()
{
    struct fila *f = (struct fila*)malloc(sizeof(struct fila));
    f->first = NULL;
    f->last = NULL;
    
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
    
    printf("Números pares na lista: %d.", getCountNumerosPares(f));
    
    // Liberar a fila e o ponteiro
    liberarFila(f);
    free(f);

    return 0;
}

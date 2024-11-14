// Elabore uma função que inverta uma fila

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
        return;
    }
    
    novo->dado = dado;
    novo->prox = NULL;
    
    if (f->last == NULL) {
        f->first = novo;
    } else {
        f->last->prox = novo;
    }
    
    f->last = novo;
}

void atenderFila(struct fila *f) {
    if (f->first == NULL) {
        printf("Fila vazia.");
        return;
    }
    
    struct no *temp = f->first;
    printf("Elemento atendido: %d\n", temp->dado);
    f->first = f->first->prox;

    if (f->first == NULL) {
        f->last = NULL;
    }
    
    free(temp);
}

void printLista(struct fila *f) {
    struct no *aux = f->first;
    
    if (aux == NULL) {
        printf("Fila vazia\n");
        return;
    }
    
    while (aux != NULL) {
        printf("Elemento %d\n", aux->dado);
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
    printf("Fila liberada\n");
}

// Função para inverter a fila
struct fila* inverterFila(struct fila *f) {
    struct fila *invertida = (struct fila*)malloc(sizeof(struct fila));
    invertida->first = NULL;
    invertida->last = NULL;
    struct no *temp = f->first;

    // Usando uma pilha para inverter a fila
    struct no *pilha = NULL;

    while (temp != NULL) {
        struct no *novo = (struct no*)malloc(sizeof(struct no));
        novo->dado = temp->dado;
        novo->prox = pilha;
        pilha = novo;
        temp = temp->prox;
    }

    // Inserindo elementos da pilha na nova fila invertida
    while (pilha != NULL) {
        inserirFila(invertida, pilha->dado);
        struct no *tempPilha = pilha;
        pilha = pilha->prox;
        free(tempPilha);
    }

    return invertida;
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
    
    printf("Fila original:\n");
    printLista(f);

    // Invertendo a fila
    struct fila *resultado = inverterFila(f);
    printf("\nFila invertida:\n");
    printLista(resultado);

    liberarFila(f);
    liberarFila(resultado);
    free(f);
    free(resultado);

    return 0;
}

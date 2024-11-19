#include <stdio.h>
#include <stdlib.h>

// Pilhas consistem em apenas guardar o topo, que aponta para os demais elementos. Novos elementos
// vão apontar sempre para o topo e o primeiro elemento para NULL
struct no {
    int dado;
    struct no *prox;
};

struct pilha {
    struct no *topo;
};

// Simples e ajustar o ponteiro da struct pilha
void push(struct pilha *p, int valor) {
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

// Retorna o dado retirado, se não houver nada na pilha não pode retornar algo nulo.
// Toda alteração na estrutura da pilha precisa ajustar os ponteiros.
int pop(struct pilha *p) {  

    if (p->top == NULL) {
        printf("Pilha vazia.");
        return -1;
    }

    struct no *temp = p->topo;
    int dadoRetirado = temp->dado;

    p->topo = p->topo->prox;
    free(temp);

    return dadoRetirado;
}

// Sempre conferir o topo/first elemento se está vazio e não o ponteiro passado como parâmetro
void percorrerPilha(struct pilha *p) {
    struct no *atual = p->topo;
    
    if (p->top == NULL) {
        printf("Pilha vazia");
        return;
    }
    
    while (atual != NULL) {
        printf("Elemento pilha: %d.\n", atual->dado);
        atual = atual->prox;
    }
}

// Em estruturas que possuem sua própria struct (como pilhas), precisa apontar os ponteiros para NULL
void liberarPilha(struct pilha *p) {
    struct no *atual = p->topo;
    
    while (atual != NULL) {
        struct no *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    p->top = NULL;
}

// Necessário criar o ponteiro da pilha e lembrar de apontar sua primeira estrutura para NULL
int main() {
    struct pilha *p = (struct pilha*)malloc(sizeof(struct pilha));
    p->topo = NULL;
    
    push(p, 10);
    push(p, 20);
    push(p, 30);
    push(p, 40);
    pop(p);
    
    percorrerPilha(p);
    
    pop(p);
    push(p, 33);
    
    percorrerPilha(p);
    liberarPilha(p);
    free(p);

    return 0;
}

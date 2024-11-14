#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente {
    int id;
    char nome[50];
    struct cliente *prox;
};

struct fila {
    struct cliente *last;
    struct cliente *first;
};

void inserirCliente(struct fila *f, int id, const char *nome) {
    struct cliente *novo = (struct cliente*)malloc(sizeof(struct cliente));
    
    if (novo == NULL) {
        printf("Sem espaço na memória");
    }
    
    novo->id = id;
    novo->prox = NULL;
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    
    // Conferir se a fila havia algum elemento antes
    if (f->last == NULL) {
        f->first = novo;
    } else {
        f->last->prox = novo;
    }
    
    f->last = novo;
    printf("Cliente inserido.");
}

void atenderCliente(struct fila *f) {
    if (f == NULL) {
        printf("Fila vazia.");
        return;
    }
    
    struct cliente *temp = f->first;
    printf("Elemento atendido: %s", temp->nome);
    f->first = f->first->prox;

    // Fila passou a estar vazia? Se sim, precisa atualizar o ponteiro last também
    if (f->first == NULL) {
        f->last == NULL;
    }
    
    free(temp);
}

void printLista(struct fila *f) {
    struct cliente *aux = f->first;
    
    if (aux == NULL) {
        printf("Fila vazia");
    }
    
    while (aux != NULL) {
        printf("Elemento %d: %s", aux->id, aux->nome);
        aux = aux->prox;
    }
}

void liberarFila(struct fila *f) {
    struct cliente *aux = f->first;
    
    while (aux != NULL) {
        struct cliente *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    
    f->first = NULL;
    f->last = NULL;
    printf("Fila liberada");
}


int main()
{
    struct fila *f = (struct fila*)malloc(sizeof(struct fila));
    f->first = NULL;
    f->last = NULL;
    
    int opcao, id;
    char nome[50];
    
    do {
        printf("\nBem-vindo ao Sistema de Atendimento!\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Atender Cliente\n");
        printf("3. Exibir Fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o ID do cliente: ");
                scanf("%d", &id);
                printf("Digite o nome do cliente: ");
                scanf("%s", nome);
                inserirCliente(f, id, nome);
                break;
            case 2:
                atenderCliente(f);
                break;
            case 3:
                printLista(f);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);
    
    // Liberar a fila e o ponteiro
    liberarFila(f);
    free(f);

    return 0;
}

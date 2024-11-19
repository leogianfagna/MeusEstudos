#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inserindo no final da fila, guarda os ponteiros first e last para ter fácil acesso onde inserir e onde retirar
struct cliente {
    int id;
    char nome[50];
    struct cliente *prox;
};

struct fila {
    struct cliente *last;
    struct cliente *first;
};

// Necessário atualizar dois ponteiros nessa situação pelo fato de inserir no final da fila:
//   1 - O ponteiro last consequentemente passa a ser outro
//   2 - O último elemento agora deve apontar para o novo último (igual na fila mas de forma diferente).
//       Precisa conferir se a fila estava vazia, pois caso contrário, não vai existir o antigo último
void inserirCliente(struct fila *f, int id, const char *nome) {
    struct cliente *novo = (struct cliente*)malloc(sizeof(struct cliente));
    
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

// A remoção de elementos ocorre através do first. Toda alteração na fila precisa atualizar os ponteiros.
// Checagem para ver se a fila passou a ser vazia para atualizar ambos os ponteiros
void atenderCliente(struct fila *f) {
    if (f->first == NULL) {
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

// Sempre conferir o topo/first elemento se está vazio e não o ponteiro passado como parâmetro
void printLista(struct fila *f) {
    struct cliente *aux = f->first;
    
    if (aux == NULL) {
        printf("Fila vazia");
        return;
    }
    
    while (aux != NULL) {
        printf("Elemento %d: %s", aux->id, aux->nome);
        aux = aux->prox;
    }
}

// Em estruturas que possuem sua própria struct (como filas), precisa apontar os ponteiros para NULL
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

// Necessário criar o ponteiro da fila e lembrar de apontar sua primeira estrutura para NULL
int main() {
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

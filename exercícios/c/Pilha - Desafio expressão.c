/*
Escreva um programa que leia uma expressão matemática contendo parênteses (),
colchetes [] e chaves {} e use uma pilha para verificar se esses delimitadores estão
balanceados. Se a expressão estiver corretamente balanceada, o programa deve
exibir "Expressão válida", caso contrário, deve exibir "Expressão inválida".
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct no {
    char dado;
    struct no *prox;
};

struct pilha {
    struct no *topo;
};

struct pilha *createPilha() {
    struct pilha *p = (struct pilha*)malloc(sizeof(struct pilha));
    p->topo = NULL;
    return p;
}

void push(struct pilha *p, char valor) {
    struct no *novo = (struct no*)malloc(sizeof(struct no));
    
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

char pop(struct pilha *p) {
    
    if (p->topo == NULL) {
        return '\0';
    }
    
    struct no *temp = p->topo;
    char caractere = temp->dado;
    
    p->topo = p->topo->prox;
    free(temp);

    return caractere;
}

void liberarPilha(struct pilha *p) {
    struct no *atual = p->topo;
    
    while (atual != NULL) {
        struct no *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    
    p->topo = NULL;
    free(p);
}

bool checarExpressao(char expr[]) {
    struct pilha *pi = createPilha();
    int pos = 0;

    while (expr[pos] != '\0') {
        char caractereAtual = expr[pos];

        switch (caractereAtual) {
            case '(':
                push(pi, '(');
                break;
            
            case '[':
                push(pi, '[');
                break;
            
            case '{':
                push(pi, '{');
                break;
            
            case ')':
                
                if (pop(pi) != '(') {
                    liberarPilha(pi);
                    return false;
                } break;
                
            case ']':
                
                if (pop(pi) != '[') {
                    liberarPilha(pi);
                    return false;
                } break;
                
            case '}':
                
                if (pop(pi) != '{') {
                    liberarPilha(pi);
                    return false;
                } break;
            
            default:
                break;
        }
        
        pos++;
    }
    
    bool ok = (pi->topo == NULL);
    liberarPilha(pi);
    return ok;
}

int main()
{
    char expressao[50] = "{(50+3/2[*5)}";
    
    if (checarExpressao(expressao)) {
        printf("Expressão válida");
    } else {
        printf("Expressão não válida");
    }
    
    return 0;
}

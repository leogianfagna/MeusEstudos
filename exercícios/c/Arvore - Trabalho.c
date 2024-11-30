// Leonardo Ferraro Gianfagna
// 18174490

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para um contato
struct Contato {
	char nome[50];
	char celular[15];
	struct Contato* esquerda;
	struct Contato* direita;
};

// Nos slides são usados funções void para atribuir às variáveis recursivamente mas aqui será feito na própria main

// Assim como nas listas ligadas, retorna o elemento que pertence à raíz pois ela será armazenada na main
// Então se for a nova raíz (raiz == NULL), retorna o novo struct, se não, retorna o antigo struct
// Usar o nome como critério de comparação. Não poderá ser o número de celular pois nas funções futuras (buscar/remover)
// vai ser fornecido apenas o nome para nevegar entre os nós
struct Contato* inserir(struct Contato* raiz, struct Contato* novo) {
	if (raiz == NULL) {
		return novo;
	}

	if (strcmp(novo->nome, raiz->nome) < 0) {
		raiz->esquerda = inserir(raiz->esquerda, novo);
	} else {
		raiz->direita = inserir(raiz->direita, novo);
	}

	return raiz;
}

// Chama recursivamente até que a primeira condição satisfaça, que significa se encontrou o dado
// ou a árvore chegou ao fim sem resultado (raiz == NULL). Busca é feita pelo nome, strcmp retorna zero se strings forem iguais
// Fonte: https://www.freecodecamp.org/news/strcmp-in-c-how-to-compare-strings-in-c/
struct Contato* buscar(struct Contato* raiz, const char* nome) {
	if (raiz == NULL || strcmp(nome, raiz->nome) == 0) {
		return raiz;
	}

	if (strcmp(nome, raiz->nome) < 0) {
		return buscar(raiz->esquerda, nome);
	} else {
		return buscar(raiz->direita, nome);
	}
}

// Precisa retornar o elemento raíz. Se a raíz mudar, precisa atualizá-la.
// Depois de navegar para encontrar o nome fornecido, precisa conferir a quantidade de filhos que o nó tem
// pois é preciso substituir o pai e da maneira necessária (um filho apenas substituir e dois filhos precisa procurar
// o menor nó da sub-árvore da direta)
//
// Se for apenas um filho e ele tiver vários outros filhos, ó substituto (o filho) mantém todos os seus nós descendentes
// intactos ao ser promovido para o lugar do nó removido.
//
// Se for dois filhos, quando encontrar o menor, precisa liberar a memória dele depois.
struct Contato* remover(struct Contato* raiz, const char* nome) {
	if (raiz == NULL) {
		return NULL;
	}

	// Navegar recursivamente (para direita ou esquerda) até encontrar
	if (strcmp(nome, raiz->nome) < 0) {
        raiz->esquerda = remover(raiz->esquerda, nome);
    } else if (strcmp(nome, raiz->nome) > 0) {
        raiz->direita = remover(raiz->direita, nome);
    } else {

		// Significa que o nó foi encontrado pois (raiz->celular == novo->celular).
		// O pai precisa ser assumido. As duas checagens abaixo confere se o pai não tem
		// exatamente dois filhos. Caso falte um (por exemplo a esquerda), retorna a direita
		// pois é fato que um nó ali existe.
		if (raiz->esquerda == NULL) {
            struct Contato* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct Contato* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        
		// Chegar aqui significa que há dois filhos e precisa encontrar o menor elemento da sub-árvore
		// da direita
		struct Contato* temp = raiz->direita;
        while (temp && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }
        
        // Após encontrado o elemento
        strcpy(raiz->nome, temp->nome);
        strcpy(raiz->celular, temp->celular);
        raiz->direita = remover(raiz->direita, temp->nome);
	}
	
	return raiz;
}

// Percorre a árvore em ordem crescente, visita a sub-árvore esquerda para imprimir
// o nó atual e depois visitando a sub-árvore direita.
void listar(struct Contato* raiz) {
	if (raiz != NULL) {
		listar(raiz->esquerda);
		printf("Nome: %s, Celular: %s\n", raiz->nome, raiz->celular);
		listar(raiz->direita);
	}
}


void menu() {
	printf("\nMenu:\n");
	printf("1. Adicionar contato\n");
	printf("2. Buscar contato\n");
	printf("3. Remover contato\n");
	printf("4. Listar contatos\n");
	printf("5. Sair\n");
	printf("Escolha uma opção: ");
}

int main() {
	struct Contato* raiz = NULL;
	int opcao;
	
	do {
		menu();
		scanf("%d", &opcao);
		
		switch (opcao) {
		    case 1: {
                // Adicionar contato
    			struct Contato* novo = (struct Contato*)malloc(sizeof(struct Contato));
    			printf("Nome: ");
    			scanf("%s", novo->nome);
    			printf("Celular: ");
    			scanf("%s", novo->celular);
    			novo->esquerda = NULL;
    			novo->direita = NULL;
    			raiz = inserir(raiz, novo);
    			break;
    		}
    		case 2: {
                // Buscar contato
    			char nome[50];
    			printf("Nome para buscar: ");
    			scanf("%s", nome);
    			struct Contato* encontrado = buscar(raiz, nome);
    			if (encontrado) {
    				printf("Contato encontrado: %s, Celular: %s\n", encontrado->nome, encontrado->celular);
    			} else {
    				printf("Contato não encontrado.\n");
    			}
    			break;
    		}
    		case 3: {
                // Remover contato
    			char nome[50];
    			printf("Nome para remover: ");
    			scanf("%s", nome);
    			raiz = remover(raiz, nome);
    			break;
    		}
    		case 4: {
                // Listar contatos
    			printf("Contatos:\n");
    			listar(raiz);
    			break;
    		}
    		case 5:
    			printf("Saindo...\n");
    			break;
    		default:
    			printf("Opção inválida! Tente novamente.\n");
		}
	} while (opcao != 5);
	
	return 0;
}


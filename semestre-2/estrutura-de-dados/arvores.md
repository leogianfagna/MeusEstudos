# Árvores

Uma árvore é uma estrutura de dados <mark style="color:blue;">não linear</mark> caracterizada por ter uma raiz, com dois ou mais ponteiros para derivações (nós). É usada por sua rapidez de busca por eliminar possibilidades em grandes quantidades (divide por 2).

## Terminologia

* <mark style="color:purple;">Raíz</mark>: Topo da hierarquia.
* <mark style="color:purple;">Nós</mark>: São as derivações da árvore. Pode ser [pai, filho ou irmão](#user-content-fn-1)[^1].
  * Nomeação de nós:
    * <mark style="color:purple;">Nó interno</mark>: Um nó que tem um filho ao menos
    * <mark style="color:purple;">Nó externo</mark>: Nós que não possuem filhos.
  * Conjunto de nós:
    * <mark style="color:purple;">Ancestrais</mark>: Da raíz até o pai.
    * <mark style="color:purple;">Descententes</mark>: Todos os nós a partir do filho.
    * <mark style="color:purple;">Sub-árvore</mark>: Toda a árvore a partir dele mesmo.
  * Características:
    * <mark style="color:purple;">Profundidade</mark>: Quantos níveis o nó desceu. A raíz é nível zero. Pode ser usado também para medir a [profundidade da árvore](#user-content-fn-2)[^2].
    * <mark style="color:purple;">Grau</mark>: Corresponde a quantidade de filhos que o nó possui. Pode ser usado também para medir o [grau da árvore](#user-content-fn-3)[^3].
* <mark style="color:purple;">Árvore binária</mark>: Quando há apenas duas derivações da raíz.
* <mark style="color:purple;">Árvore estritamente binária</mark>: Todos os nós tem dois ou nenhum filho. Usada para expressões aritméticas onde nós internos são operadores e o externos são os números/operandos.
* <mark style="color:purple;">Árvore binária cheia</mark>: É uma árvore estritamente binária mas que todos os nós se encerram na mesma profundidade.

<figure><img src="../../.gitbook/assets/termologias em arvores binarias.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/tipos de arvores binarias.png" alt=""><figcaption></figcaption></figure>

## Funcionamento

<mark style="color:blue;">Elementos adicionados</mark> são comparados com a raíz. Se a árvore for uma struct de clientes, a comparação pode ser usado o número de CPF, mas precisa comparar alguma coisa. Pressupõe que não há dados repetidos.

* Se o nó inserido for <mark style="color:blue;">maior</mark> que o nó comparado: Vai para a <mark style="color:blue;">direita</mark> ->
* Se o nó inserido for <mark style="color:blue;">menor</mark> que o nó comparado: Vai para a <mark style="color:blue;">esquerda</mark> <-

Ás árvores não se re-organizam então pode ter números bem maiores lá em baixo, o que pode ficar esquisito mas é pela ordem de inserção e continua funcionando normal. A busca também é feito com comparações seguindo o mesmo caminho direita/esquerda dependendo do resultado.

A árvore permite <mark style="color:blue;">remover qualquer nó</mark> dela. Se o nó removido tiver filhos, um nó irá assumir o lugar do pai, [esse nó será](#user-content-fn-4)[^4] o menor número do caminho da direita ou o próprio filho caso seja filho único.

<figure><img src="../../.gitbook/assets/remoção de elementos de árvores.png" alt=""><figcaption></figcaption></figure>

## Parte estrutural da árvore

Assim como pilhas e filas, são dois ponteiros:

* **Ponteiro que representa um nó da árvore**: Composto por três dados, a informação, o ponteiro da esquerda e o ponteiro da direita.
* **Ponteiro que representa a árvore**: Comporto por um dado, o ponteiro da raíz.

```c
struct no {
    int info;
    struct no *esq;
    struct no *dir;
};

struct arvore {
    struct no *raiz;
};
```

## Operações

As operações a seguir serão consideradas que um <mark style="color:orange;">ponteiro na main</mark> guarda o endereço de memória da raíz, sem a utilização da `struct arvore`.

As operações usam [recursividade](recursao.md). Seu objetivo é ficar repetindo a mesma operação até chegar no destino.

### Inserir

Assim como nas listas ligadas, será necessário retornar o elemento que equivale à raíz pois ela será armazenada na main. Então:

* Se o elemento inserido for a nova raíz (pode ser checado se a raíz do parâmetro é nula), retorna o novo struct.
* Se não, retorna o antigo struct.

Precisa usar um critério de comparação, o exemplo abaixo usou o nome do contato.&#x20;

```c
int main() {
	struct Contato* novo = (struct Contato*)malloc(sizeof(struct Contato));
	novo->esquerda = NULL;
	novo->direita = NULL;
	raiz = inserir(raiz, novo);
}

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
```

### Buscar

Chama recursivamente até que a primeira condição satisfaça, que significa se encontrou o dado ou a árvore chegou ao fim sem resultado (se raíz é nula). Busca é feita pelo nome.

```c
int main() {
    char nome[50];
    scanf("%s", nome);
    struct Contato *encontrado = buscar(raiz, nome);
}

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
```

### Remover

Também precisa retornar o elemento raíz para atualizar se a raíz mudar. Primeiro é preciso navegar para encontrar o nome fornecido.

A remoção de um nó necessita conferir a quantidade de filhos que o nó tem, pois o nó pai terá que ser substituído da maneira correta. Essa maneira depende dessa quantidade, mostrado [visualmente aqui](arvores.md#funcionamento):

* Nenhum filho: O pai não será substituído e apenas removido.
* Um filho: O pai será substituído por esse filho.
  * Detalhe: É possível que esse filho tenha vários outros filhos e uma grande árvore abaixo. Isso não é uma preocupação pois o substituto (o filho) mantém todos os seus nós descendentes intactos ao ser promovido para o lugar do nó removido. Basicamente como se estivesse subindo todos juntos.
  * Conferir se algum dos lados é NULL (esquerda ou direita), podemos descobrir se há apenas dois filhos. Se nós sabemos que existe um filho, se a esquerda for NULL isso significa que tem o filho para direita.
* Dois filhos: O menor nó da sub-árvore da direita irá assumir a posição do pai. Então é necessário caminhar até encontrar esse nó, liberá-lo e fazê-lo assumir a sua posição.

```c
int main() {
    char nome[50];
    scanf("%s", nome);
    raiz = remover(raiz, nome);
}

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
    
        // Aqui significa que o nó foi encontrado pois
        if (raiz->esquerda == NULL) {
            struct Contato* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct Contato* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        
        // Chegar aqui significa que há dois filhos
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
```

### Listar

A função `listar` realiza uma **traversal in-order (em ordem)** em uma árvore binária de busca. Isso significa que os nós da árvore são visitados em ordem crescente, com base na organização dos valores armazenados (neste caso, `nome`).

A traversal in-order segue esta sequência:

* Visita o **subárvore esquerda** (nós menores).
* Processa o **nó atual** (imprime ou executa alguma operação no nó).
* Visita o **subárvore direita** (nós maiores).

Isso é implementado de maneira recursiva:

* A função chama a si mesma para processar primeiro os nós da subárvore esquerda.
* Depois imprime o nó atual.
* Por fim, chama a si mesma para processar os nós da subárvore direita.

```c
int main() {
    listar(raiz);
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
```

[^1]: É igual uma árvore genealógica. Não é só pegar elementos na mesma linha e sim de fato elementos que tem o mesmo pai.

[^2]: "A árvore tem nível 3 de profundidade".

[^3]: "A árvore tem grau 2", que é o nó com mais filhos que tem. Nesse caso, não há nenhum nó com mais de dois filhos.

[^4]: Existem outros métodos de fazer isso.

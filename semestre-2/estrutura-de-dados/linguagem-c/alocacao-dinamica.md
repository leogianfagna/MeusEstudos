# Alocação dinâmica

Visto até então, o tamanho da memória para variáveis ou vetores é definido no momento da compilação. Porém não sabemos previamente quanto espaço será necessário durante a execução do programa e por isso usamos a alocação dinâmica de memória que permite alocar e liberar memória enquanto o programa está sendo executado.

## Funções de alocações

Incluir as bibliotecas `#include <stdlib.h>`

### malloc

É usada para alocar um <mark style="color:blue;">bloco contínuo de memória</mark>. Ela <mark style="color:green;">retorna um ponteiro</mark> para o primeiro byte do bloco alocado.

* Parâmetro: Número de bytes para ser alocado.
* Retorno: Um ponteiro do tipo void para o bloco alocado.Se a alocação falhar (por exemplo, se não houver memória suficiente), `malloc` retorna NULL.
  * Por conta que retorna esse ponteiro do tipo void, é necessário fazer um casting para transformá-lo em int, ou do mesmo tipo da variável que vai receber.

```c
// Sintaxe:
// void* malloc(size_t size);

int *ptr = (int*)malloc(5 * sizeof(int));  // Aloca memória para 5 inteiros

if (ptr == NULL) {
    printf("Erro na alocação de memória\n");
    return 1;
}
```

Vimos o `(int*)` representando o casting para que o malloc retorne um ponteiro do tipo int. Curiosamente, o asterisco vem depois do nome int, o que é apenas uma representação da linguagem C onde quando queremos um ponteiro para o tipo primitivo, o asterisco vem depois e não antes como é com as variáveis.

### calloc

O malloc é usado quando você precisa alocar memória rapidamente e não se importa com os valores iniciais na memória. Os valores iniciados podem conter lixo e são aleatórios. Já o calloc é usado quando você precisa de memória já inicializada com zeros, o que pode evitar comportamentos indesejados devido a valores residuais. Basicamente, quando você não pode ter aqueles lixos.

```c
// Sintaxe
// void* calloc(size_t num, size_t size);

int *ptr = (int*)calloc(5, sizeof(int));  // Aloca e inicializa com zero um array de 5 inteiros

if (ptr == NULL) {
    printf("Erro na alocação de memória\n");
    return 1;
}
```

### realloc

Quando precisamos realocar um bloco previamente alocado com malloc ou calloc, ai utilizamos o realloc mantendo o conteúdo original.

* Parâmetros:&#x20;
  * ptr: ponteiro para o bloco de memória previamente alocado.
  * size: o novo tamanho em bytes para a memória.
* Retorno: Um ponteiro do tipo void para o **novo bloco** de memória realocado, ou NULL se falhar.

```c
// Sintaxe:
// void* realloc(void* ptr, size_t size);


ptr = (int*)realloc(ptr, 10 * sizeof(int));  // Redimensiona o array para 10 inteiros

if (ptr == NULL) {
    printf("Erro na realocação de memória\n");
    return 1;
}
```

### free

Usada para liberar um bloco de memória alocado dinamicamente. Isso devolve a memória ao sistema, evitando vazamento de memória. Usamos como parâmetro um ponteiro para o bloco de memória a ser liberado.

```c
// Sintaxe
// void free(void* ptr);

free(ptr);
ptr = NULL;
```

## Exemplo prático

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    // Aloca memória para n inteiros
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro na alocação de memória\n");
        return 1;
    }

    // Preenche o array com valores e imprime
    for (i = 0; i < n; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Libera a memória
    free(arr);

    return 0;
}
```

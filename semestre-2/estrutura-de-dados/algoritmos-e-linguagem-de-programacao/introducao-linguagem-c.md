# Introdução linguagem C

Todo programa em C começa com uma função chamada `main()`, que é o ponto de entrada do programa. Os códigos começam com inclusão/importação de bibliotecas, como é muito comum vermos a biblioteca `#include <stdio.h>`, responsável por imprimir dados na tela e outras coisas básicas.

A função main() é do tipo inteiro, ou seja, ela sempre deve retornar algo desse tipo. Retornar zero simboliza que o código foi bem sucedido.

## Código englobando o básico

Esse código vai englobar os seguintes conceitos para entendermos como funciona nessa linguagem:

* Importação de bibliotecas: feito com hashtag no início.
* Tipos primitivos: no caso int e float.
* Uso do `%d` que simboliza o espaço de uma variável dentro das aspas, tanto para imprimir um dado quando para ler com scanf.
  * Na hora de escanear, colocamos um `&` antes do nome da variável.
* Chamada de funções, onde precisa declarar as funções inicialmente, diferente de outras linguagens.
  * A declaração de uma função informa ao compilador sobre o nome da função, o tipo de retorno e os parâmetros que ela aceita.
* O restante é basicamente o mesmo.

```c
#include <stdio.h>

// Declara as funções
int encontrarMaior(int a, int b, int c);
float calcularMedia(int a, int b, int c);

int main() {
    int num1, num2, num3, maiorNumero;
    float media;
    
    printf("Insira 3 números inteiros");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    maiorNumero = encontrarMaior(num1, num2, num3);
    media = calcularMedia(num1, num2, num3);
    
    printf("O maior número é %d\n", maiorNumero);
    printf("A média dos números é %.2f", media);
    
    return 0;
}

int encontrarMaior(int a, int b, int c) {
    int maiorEncontrado = a;
    
    if (b > maiorEncontrado) maiorEncontrado = b;
    if (c > maiorEncontrado) maiorEncontrado = c;
    
    return maiorEncontrado;
}

float calcularMedia(int a, int b, int c) {
    return mediaCalculada = (a + b + c) / 3.0;
}
```

## Vetores (array)

Um array é uma coleção de elementos do mesmo tipo, armazenados em posições contíguas de memória, igual às outras linguagens. Os vetores são simbolizados por `[colchetes]` que indicam seu índice e a declaração pode ser feita usando `{chaves}`.

O acesso de um elemento é através do índice:

```c
int numeros[12];
int primos[3] = {1, 3, 5};

primos[2] = 7;

printf("O vetor completo é:\n");
for (int i = 0; i < 3; i++) {
    printf("Posição %d: %d", i, primos[i]);
}
```

Aqui podemos ver a declaração informando o tamanho total, uma declaração já com os elementos, manipulação e impressão de elemento por elemento.

## Matrizes

Matrizes são vetores de mais de uma dimensão, basicamente é uma estrutura de dados do tipo vetor com duas ou mais dimensões. Na prática, as matrizes formam tabelas na memória.

Sua declaração consiste em linhas e colunas, que formam uma tabela, isto é: dois índices. Ler todos os elementos pode ser feito <mark style="color:blue;">percorrendo todas as linhas com</mark> <mark style="color:blue;"></mark><mark style="color:blue;">`i`</mark> e depois percorrendo dentro de cada linha <mark style="color:blue;">todas as colunas com</mark> <mark style="color:blue;"></mark><mark style="color:blue;">`j`</mark>, desta forma:

```c
float matriz[3][3];

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        scanf("%f", matriz[i][j]);
    }
}
```

## Ponteiros

Um ponteiro é uma variável que armazena o endereço de memória de outra variável. Ponteiros são usados para armazenar e gerenciar os endereços das variáveis, permitindo manipulação indireta de valores e eficiência na passagem de dados para funções. Eles permitem funções que modificam os dados originais, manipulação dinâmica de memória, e são essenciais para estruturas de dados complexas como listas ligadas e árvores.

### Tipo de um ponteiro

O tipo de um ponteiro deve corresponder ao tipo de dado da variável cujo endereço ele armazena para <mark style="color:blue;">garantir quantidade de memória adequada</mark>, também chamada de **aritmética de ponteiros**. Basicamente:

* Tipos possuem espaços diferentes, um int ou float ocupa 4 bytes por exemplo e outros tipos podem ocupar diferentes espaços de memória. O tipo do ponteiro vai informar quantos bytes devem ser lidos, por isso os tipos devem corresponder.
* Quando você incrementa/decrementa/modifica um ponteiro, o tipo do ponteiro determina como interpretar os bytes daquele endereço. A interpretação de 4 bytes como `int` ou `float` resulta em certos valores, o que seria completamente diferentes se fosse outro tipo, devido às diferenças nas representações binárias de inteiros e números de ponto flutuante.
* Cada tipo é representado na memória de forma muito diferente. Isso é bem complexo mas fácil de entender porquê. Se eles são representados de forma muito diferente, com certeza não podemos declarar um ponteiro com um tipo diferente.

Então, o uso incorreto dos tipos dos ponteiros causaria compormamentos indefinidos e erros na manipulação da memória e segurança do código.

### Uso

Existem dois operadores (símbolos) utilizados com diferentes funcionalidades para analisar:

| Operador | Função                                                     |
| -------- | ---------------------------------------------------------- |
| &        | Serve para indicar o endereço de memória                   |
| \*       | Serve para indicar o valor que está no endereço de memória |

Portanto, esses operadores acabam sendo fundamentais já que um ponteiro vai utilizar o endereço de memória e depois na hora da manipulação vamos querer o valor que está lá.

```c
int main() {
    int *ptr; // Declaração de um ponteiro
    int var = 10;
    
    // O ponteiro recebe endereço de memória
    ptr = &var;
    printf("Valor que está no endereço: %d", *ptr); // CONSOLE: 10
    
    // Asterisco na frente simboliza valor, podemos alterar o valor assim
    *ptr = 20;
    printf("Valor que está no endereço: %d", *ptr); // CONSOLE: 20

    return 0;
}
```

Então neste caso criamos um ponteiro e depois atribuímos a ele o endereço de memória da variável "var". Se esse ponteiro tem esse endereço de memória, podemos encontrar o valor que está neste endereço usando o asterisco para chegar até ele.

## Ponteiros com vetores

Ponteiros e vetores estão muito relacionados. Não foi dito acima mas um vetor é um bloco de memória sequencial onde o nome do vetor (aquele que é declarado) <mark style="color:orange;">é um ponteiro</mark> e esse ponteiro <mark style="color:blue;">aponta para o primeiro elemento</mark> do vetor.

#### Exemplo

```c
int nums[5] = {1, 2, 3, 4, 5};
printf("%d\n", *nums); // CONSOLE: 1
printf("%d\n", *(nums + 1)); // CONSOLE: 1
```

A variável nums equivale à `&nums[0]`, o que simboliza o endereço de memória da primeira posiçãodo vetor.

## Ponteiros para ponteiros

Um ponteiro que armazena o endereço de outro ponteiro. Isso permite vários níveis de indireção. A declaração dessa situação implica no uso de dois asteriscos.

O que precisamos saber é que um ponteiro é também uma variável e portanto ele <mark style="color:green;">**possui o seu endereço de memória**</mark>. Portanto, um ponteiro para um ponteiro vai resgatar o endereço de memória desse ponteiro. Se ele vai resgatar o endereço de memória de um ponteiro, <mark style="color:orange;">devemos</mark> usar `&` na frente do nome dele.

Um ponteiro para ponteiro é presentado por **mais um asterisco**, ficando desta forma:

```c
int var = 10;
int *ptr = &var;  // Ponteiro para var
int **pptr = &ptr;  // Ponteiro para ponteiro (pptr aponta para ptr)

printf("Valor de var: %d\n", **pptr);  // Acessa o valor de 'var' através do
                                       // ponteiro para ponteiro
```

Se tivessemos mais um ponteiro apontando para o pptr, isso simbolizaria mais um asterisco no início e por ai vai.&#x20;

Para entender um pouco de conceito, se fizessemos `int **pptr = ptr` sem o e-comercial na frente, estaríamos atribuindo ao ponteiro `pptr` o valor que `ptr` assume e não o endereço de memória dele. Só que lembrando, <mark style="color:blue;">um ponteiro guarda um endereço de memória</mark>, portanto, qual o sentido de não pegar o endereço de memória do segundo ponteiro? Por isso que o `&` na frente é necessário, apesar de alguns testes fazendo sem ainda funcionasse.

## Alocação dinâmica

Visto até então, o tamanho da memória para variáveis ou vetores é definido no momento da compilação. Porém não sabemos previamente quanto espaço será necessário durante a execução do programa e por isso usamos a alocação dinâmica de memória que permite alocar e liberar memória enquanto o programa está sendo executado.

### Funções de alocações

Incluir as bibliotecas `#include <stdlib.h>`

#### malloc

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

#### calloc

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

#### realloc

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

#### free

Usada para liberar um bloco de memória alocado dinamicamente. Isso devolve a memória ao sistema, evitando vazamento de memória. Usamos como parâmetro um ponteiro para o bloco de memória a ser liberado.

```c
// Sintaxe
// void free(void* ptr);

free(ptr);
ptr = NULL;
```

### Exemplo prático

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

## Struct

Uma struct é apenas um tipo próprio que você cria para agrupar diferentes tipos de dados (relacionados a um conceito em comum) sob um único nome. Depois de criar uma estrutura, você pode criar variáveis do tipo struct que conterão cópias dos dados que possui dentro dela.

```c
#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    struct Pessoa pessoa1;
    struct Pessoa pessoaDeclarada = {"Matheus", 20, 1.80};

    // Atribuição de valores aos membros da struct
    pessoa1.idade = 25;
    pessoa1.altura = 1.75;
    snprintf(pessoa1.nome, sizeof(pessoa1.nome), "Bruno");

    // Acesso aos membros
    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d\n", pessoa1.idade);
    printf("Altura: %.2f\n", pessoa1.altura);

    return 0;
}
```

Podemos ver aqui que podemos atribuir os valores à uma struct através da notação de pontos, que também serve para resgatar os valores caso necessário, como se fosse um objeto em Java. Também vimos que podemos declarar os dados da struct logo depois de criar a variável `pessoaDeclarada`, sem a necessidade depois de atribuir um por um.

### Ponteiros em struct

Podemos criar um ponteiro para uma struct (do tipo da struct) permitindo <mark style="color:blue;">acessar membros da estrutura indiretamente através dele</mark>. Em outras palavras, usamos o ponteiro criado para resgatar os valores da struct e não o nome da struct diretamente.

Fazer dessa forma muda algumas coisas, como o uso do operador -> para acessar os membros pelo ponteiro e para funcionar o ponteiro precisa receber o endereço de memória de uma struct declarada, veja:

```c
#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    struct Pessoa pessoa1 = {"Matheus", 20, 1.80};
    struct Pessoa *ptrPessoa;

    ptrPessoa = &pessoa1;  // O ponteiro aponta para pessoa1

    // Acesso aos membros da struct usando o ponteiro (com o operador ->)
    printf("Nome: %s\n", ptrPessoa->nome);
    printf("Idade: %d\n", ptrPessoa->idade);
    printf("Altura: %.2f\n", ptrPessoa->altura);

    return 0;
}
```

### Passando struct em funções

As structs são declaradas fora da main, sendo assim, uma variável global. Se utilizarmos exatamente da forma que vimos acima dentro de uma função vai funcionar. Contudo, podemos passar elas por parâmetros em funções, podendo escolher entre duas formas que possam alterar ou não os valores originais dela.

Podemos passar a struct por funções através do valor ou referência:

* Valor: Basicamente declaramos uma variável do tipo struct na main e usamos ela como parâmetro em uma função. Essa função recebe esse parâmetro e consequentemente pode usá-la como quiser. Parâmetros recebidos em funções são uma cópia, portanto, manipulações feitas dentro da função <mark style="color:green;">não alterarão a estrutura original da struct</mark>.
* Referência: Igual acima mas em vez de passar a variável do tipo struct, passamos o endereço de memória dela (fazemos isso incluindo & antes). Se estamos passando o endereço da memória, isso significa que <mark style="color:red;">alterações vão afetar a estrutura original da struct</mark>.

<pre class="language-c"><code class="lang-c">struct Pessoa pessoa1 = {"Leonardo", 25, 1.75};

alteraIdade(pessoa1, 30); // Chamar função por valor
alteraIdade(&#x26;pessoa1, 30); // Chamar função por referência

<strong>printf("Idade alterada: %d\n", pessoa1.idade);
</strong></code></pre>

```c
// Função para receber valor
void alteraIdade(struct Pessoa p, int novaIdade) {
    p.idade = novaIdade;
}

// Função para receber referência
void alteraIdade(struct Pessoa *p, int novaIdade) {
    p->idade = novaIdade;
}
```

Portando vimos as diferenças entre elas, onde se ela passa referência, a função também precisa receber em forma de referência (ponteiro). Agora, em questão de resultado, esse print vai retornar para cada um dos casos:

* Se chamar por valor: Retorna "25", pois vai alterar a idade da struct `p` que é só uma cópia passada por parâmetro.
* Se chamar por referência: Retorna "30", pois altera a estrutura original da struct que é declarada fora da main ou qualquer função.

### Typedef para tipos definidos

Funciona como uma espécie de um apelido para não haver necessidade de ficar declarando struct toda linha de codificação em declarações. Basicamente, mudamos a sintaxe para que "Pessoa" já seja o apelido, fazendo com que:

<figure><img src="../../../.gitbook/assets/diferenças do uso typedef struct em c.png" alt=""><figcaption></figcaption></figure>

### Structs alinhadas

Basicamente é a criação de estruturas dentro de estrutudas. Apesar de parecer, não assimilamos com o termo de herança pois isso está relacionado com compartilhamento de comportamento como em linguagens orientadas a objetos em classes.

```c
#include <stdio.h>

typedef struct {
    char cidade[50];
    char estado[3];
} Endereco;

typedef struct {
    char nome[50];
    int idade;
    float altura;
    Endereco endereco;
} Pessoa;

int main() {
    Pessoa pessoa1 = {"Miguelito", 30, 1.83, {"São Paulo", "SP"}};
    
    printf("Nome: %s\n", pessoa1.nome);
    printf("Cidade: %s, Estado: %s\n", pessoa1.endereco.cidade, pessoa1.endereco.estado);
    
    return 0;
}
```

Vimos aqui que todos os dados da estrutura alinhada foram declarados. Como a estrutura `Endereco` está dentro da estrutura `Pessoa`, os atributos de `Pessoa` são declarados <mark style="color:blue;">primeiros</mark> e `Endereco` depois entre chaves.

O acesso é através dos pontos, onde quando precisamos acessar algo que está em `Pessoa`, que é a estrutura principal e a declarada (repare que não declaramos em nenhum momento a estrutura `Endereco` na main) usamos apenas um ponto e algo que está na estrutura seguinte usamos um ponto usando o nome da variável dada para aquela outra estrutura. Exemplo:

* `pessoa1.nome`
  * pessoa1 é o nome da variável do tipo `Pessoa` criada na main.
  * nome é o membro da struct.
* `pessoa1.endereco.cidade`
  * pessoa1 é o nome da variável do tipo `Pessoa` criada na main.
  * endereco é o nome da variável do tipo `Endereco` criada dentro da estrutura `Pessoa`.
  * cudade é o membro da segunda struct.

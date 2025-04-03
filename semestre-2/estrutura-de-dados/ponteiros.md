# Ponteiros

## O que são ponteiros

Um ponteiro é uma variável que armazena o endereço de memória de outra variável. Ponteiros são usados para <mark style="color:blue;">armazenar e gerenciar os endereços das variáveis</mark>, <mark style="color:green;">permitindo manipulação indireta</mark> de valores e eficiência na passagem de dados para funções. Eles permitem funções que modificam os dados originais, manipulação dinâmica de memória e são essenciais para estruturas de dados complexas como listas ligadas e árvores.

### Como funcionam

Para não confundir, um ponteiro também <mark style="color:orange;">tem o seu endereço de memória</mark>. Então vendo o esquema abaixo, temos dois ponteiros (`b` e `c`) onde cada um aponta para um endereço diferente de memória. Isso porque o ponteiro c foi declarado recebendo um valor e não um endereço.

Em outras palavras, `*c = *b` significa a mesma coisa que `*c = 4`, ou seja, esse número quatro não significa nada, nenhum endereço de memória e apenas um valor para ser apontado. Por conta disso, isto acontece:

<figure><img src="../../.gitbook/assets/valor de ponteiro recebe valor de ponteiro.png" alt=""><figcaption></figcaption></figure>

Agora, se falarmos que o ponteiro c recebe o ponteiro b, ele terá as suas mesmas características, portanto, vão apontar para o mesmo endereço de memória. Ainda sim, cada ponteiro terá o seu próprio endereço de memória pois é assim que variáveis funcionam (repare que o conteúdo que estava abaixo foi liberado).

<figure><img src="../../.gitbook/assets/ponteiro recebe ponteiro.png" alt=""><figcaption></figcaption></figure>

### Motivos de usar ponteiros

Quando temos alguma função que recebe um parâmetro, o parâmetro recebido na função é uma <mark style="color:blue;">cópia do parâmetro</mark> original passado, e não o verdadeiro. Isso é para tudo, se passarmos uma [struct](struct.md) como parâmetro em um função, a função vai copiar elemento por elemento da struct criando uma completamente nova para <mark style="color:blue;">usar temporariamente naquela função</mark>.

Agora, quando passamos um ponteiro, esse ponteiro possui o endereço de memória de uma variável. Portanto, manipular um ponteiro é manipular de fato a variável/objeto original. Assim, ponteiros podem ser utilizados quando queremos manipular os valores reais ao invés de cópias.

#### Observação

Para isso funcionar bem, lembrar do **brinquedo de criança**. Temos sempre que entregar o que a função pede (no brinquedo de criança, se pede círculo entrega círculo, quadrado entrega quadrado e assim vai). Se a função pedir um ponteiro como parâmetro, precisamos passar um ponteiro OU a referência da variável usando `&` que vai funcionar. Se a função espera um valor, tem que passar diretamente a variável OU o valor do ponteiro usando `*`.

### Entendendo um problema comum

Para <mark style="color:purple;">mudar o valor que um ponteiro</mark> possui, podemos fazer uma atribuição simples de `*ptr = 4`, por exemplo, mas isso pode não funcionar. O motivo disso é que o ponteiro `ptr` <mark style="color:orange;">não foi inicializado para apontar para uma área válida</mark> de memória antes de tentar atribuir o valor `4` a ele.

Para corrigir isso, inicializamos o ponteiro dessa forma `int *ptr = &variavel` sendo a variável qualquer valor definido previamente. Depois disso, podemos atribuir o valor como fizemos acima.

## Tipo de um ponteiro

O tipo de um ponteiro deve corresponder ao tipo de dado da variável cujo endereço ele armazena para <mark style="color:blue;">garantir quantidade de memória adequada</mark>, também chamada de **aritmética de ponteiros**. Quando fazemos `int a`, o programa aloca memória correspondente ao int. Basicamente:

* Tipos possuem espaços diferentes, um int ou float ocupa 4 bytes por exemplo e outros tipos podem ocupar diferentes espaços de memória. O tipo do ponteiro vai informar quantos bytes devem ser lidos, por isso os tipos devem corresponder.
* Quando você incrementa/decrementa/modifica um ponteiro, o tipo do ponteiro determina como interpretar os bytes daquele endereço. A interpretação de 4 bytes como `int` ou `float` resulta em certos valores, o que seria completamente diferentes se fosse outro tipo, devido às diferenças nas representações binárias de inteiros e números de ponto flutuante.
* Cada tipo é representado na memória de forma muito diferente. Isso é bem complexo mas fácil de entender porquê. Se eles são representados de forma muito diferente, com certeza não podemos declarar um ponteiro com um tipo diferente.

Então, o uso incorreto dos tipos dos ponteiros causaria compormamentos indefinidos e erros na manipulação da memória e segurança do código.

## Uso

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

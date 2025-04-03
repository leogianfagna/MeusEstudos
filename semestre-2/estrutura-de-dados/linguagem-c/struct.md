# Struct

Uma struct é apenas um <mark style="color:blue;">tipo próprio que você cria para agrupar</mark> diferentes tipos de dados (relacionados a um conceito em comum) sob um único nome. Depois de criar uma estrutura, você pode criar variáveis do tipo struct que conterão cópias dos dados que possui dentro dela.

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



:warning: **Detalhes para uso de elementos da struct**

Apesar de idade ser um `int`, a declaração dele na main para usar e manipular essa variável nunca citou o tipo `int`. Isso porque usar uma struct tem obrigatoriamente essa estrutura:&#x20;

```c
struct NomeDaStruct nomeQueEuEscolho;
nomeQueEuEscolho.idade = 30;
```

Portanto, usar um elemento da struct criada sempre vai seguir o padrão inicial de `struct NomeDaStruct` e isso é muito importante saber para não confundir, principalmente pois será usado na declaração de listas ligadas.

## Ponteiros em struct

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

## Passando struct em funções

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

## Typedef para tipos definidos

Funciona como uma espécie de um apelido para não haver necessidade de ficar declarando struct toda linha de codificação em declarações. Basicamente, mudamos a sintaxe para que "Pessoa" já seja o apelido, fazendo com que:

<figure><img src="../../../.gitbook/assets/diferenças do uso typedef struct em c.png" alt=""><figcaption></figcaption></figure>

## Structs alinhadas

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

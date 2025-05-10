# Hashing

É uma estrutura de dados usada para busca eficiente e rápida utilizando o conceito de <mark style="color:blue;">chave valor</mark>, como se fosse um dicionário em Python ou objeto em Javascript. As chaves normalmente são strings ou valores numéricos, mas as funções de hash convertem isso.

## Funções de hash

Uma função hashing é um algoritmo que <mark style="color:blue;">transforma aritmeticamente uma chave</mark> em um índice numérico fixo, que representa a posição onde o valor associado&#x20;àquela chave será armazenado em uma estrutura de dados.

Tem como principal objetivo distribuir as chaves na tabela de maneira uniforme, fazendo com que evite as **colisões**. Portanto, se queremos fazer uma boa distribuição, essa função não é aleatória. Podemos pensar como um porteiro de um restaurante, que aloca as pessoas em mesas de forma eficiente e não deixa que seus convidados fiquem aglomerados na mesma mesa ou de pé.

Tanto metaforicamente quanto computacionalmente, então teremos como objetivo do porteiro e da função hash:

* Distribuição dos dados.
* Evita aglomerações.
* Mantém ambiente fluído e sem filas.
* Independência dos dados (não julga nenhum dado de entrada).

### Tipos de funções

Não entrando em muitos detalhes, as funções normalmente são convencionais, levando como `m` o tamanho da tabela desejada:

* Operador módulo: `h(k) = k % m`.
* Strings: Usa uma fórmula que resgata o valor numérico de cada letra da tabela ASCII, faz ponderações e multiplicações com constantes e outras variáveis, retornando o valor do índice.

## Colisões

É quando duas <mark style="color:blue;">chaves diferentes geram o mesmo índice</mark>, basicamente, um dado foi escolhido para ser guardado em um lugar mas já está ocupado. Quando isso acontece, existem duas abordagens para tratar:

### Encadeamento aberto

Consiste em <mark style="color:blue;">procurar uma nova posição</mark> para esse dado, tal método chamado de <mark style="color:purple;">sondagem</mark>. Isso é interessante quanto temos algo em torno de <mark style="color:orange;">70% da ocupação</mark> da tabela, pois se estiver muito cheia, isso significa ficar procurando muito um novo lugar. É necessário perceber que é uma boa técnica, mas esse encadeamento ainda não se livra de colisões pois a tabela tem o seu limite.

A procura de uma nova posição pode ser através da <mark style="color:purple;">sondagem linear</mark>, que procura próxima posição vazia de forma simples. Isso pode criar o clustering primario, que é uma aglomeração de dados. Claramente, em uma certa parte da tabela, os espaços vão estar ocupado sucessivamente.

Como alternativa à essa sondagem, temos a <mark style="color:purple;">sondagem quadrática</mark> que segue [progressão quadrática](#user-content-fn-1)[^1] em vez de um slot por vez. Isso deixa os dados mais espalhados, o que evitam colisões no futuro.

### Encadeamento separado

Não procura uma nova posição e guarda o dado naquele campo mesmo. Só que para isso, cria uma lista ligada naquele campo e <mark style="color:blue;">armazena os dois dados encadeados</mark>. Infelizmente, isso pode causa um <mark style="color:orange;">overhead de memória</mark>, pois exige muito mais memória. Acessar ponteiros também deixam cache na memória.

Pelo lado benéfico, isso pode ser <mark style="color:green;">muito útil para tabelas mais cheias</mark> que não podem haver colisões. Uma flexibilidade no armazenamento dos dados muito alta e resolvendo problemas de limitações.

<figure><img src="../../.gitbook/assets/tabela hashing com lista ligada.png" alt=""><figcaption></figcaption></figure>

#### Uso de vetores ou lista ligadas

Vamos comparar o tamanho computacional usado para cada estrutura:

* Cada índice de um vetor ocupa 4B.
* Lista ligada usa 4B para o dado e 8B para o ponteiro, isso é, 12B por posição.

Podemos dizer que, em um vetor e uma lista ligada de 100 posições teremos o uso de 400B e 1200B de uso para cada. Faz parecer que o vetor é menor. Contudo, a lista ligada não necessariamente vai ter 100 elementos, assim como o vetor que precisa ser declarado com esse tamanho.

As vezes temos 10 posições apenas sendo ocupadas, e nesse caso teremos:

* 400B para o vetor (já que ele foi declarado assim).
* 120B para a lista ligada (o total ocupado para cada posição).

Portanto, <mark style="color:blue;">temos que analisar qual o melhor caso a ser usado</mark>. O vetor ainda pode ser uma melhor opção já que <mark style="color:orange;">listas ligadas espalham nós pela memória</mark>, quebrando localidade do cache.

[^1]: Volta no primeiro slot e segue uma progressão quadrática:&#x20;

    1. checa slot  i + 1^2.
    2. checa slot  i + 2^2.
    3. checa slot  i + 3^2.
    4. Assim sucessivamente.

# Medidas de posição

## Tipos de medidas

### Moda

É o valor que aparece mais vezes no conjunto de dados. Representado por `Mo` ou `mo`.

* Quando há apenas um único valor que aparece mais vezes, chamamos de <mark style="color:purple;">unimodal</mark>. Esse é o padrão.
* Quando todos os valores aparecem a mesma quantidade de vezes, chamamos de <mark style="color:purple;">amodal</mark>.
* Chamamos de <mark style="color:purple;">bimodal</mark> ou <mark style="color:purple;">multimodal</mark> quando temos 2 ou mais modas presentes.

### Média aritmética

É a [média padrão](#user-content-fn-1)[^1] do conjunto de dados usando duas casas decimais caso o valor seja quebrado. Representado por `M`.

### Média ponderada

Mesma ideia da média mas quando tem pesos, como a média final de uma disciplina (onde P1 vale 30% ou peso 1, P2 vale 40% ou peso 2 e assim vai).

### Média geométrica

Envolve radical (raíz) e produtos (valores multiplicados). Então por exemplo, extrair a raíz `n` da multiplicação de `n` produtos.

### Mediana

Encontrar o <mark style="color:blue;">dado do meio</mark> em um ROL. Ou seja, precisa organizar o conjunto de dados em um rol e contar qual dado está na posição central dele. É uma boa alternativa usar em vez da média quando os dados extrapolam. Representado por `Md` ou `md`.

Se a quantidade de valores for par, isso significa que teremos dois dados medianos. Então a mediana final será a média entre eles.

<figure><img src="../../.gitbook/assets/medidas de posição.png" alt="" width="286"><figcaption></figcaption></figure>

## Medidas de dados agrupados

Como fazer os cálculos de medidas quanto temos dados agrupados ([classes](distribuicao-de-frequencia.md#classes)) em vez dos dados originais, apenas tendo o intervalo e a frequência do mesmo.

### Média de dados agrupados

Para calcular a média de dados agrupados, seguir a <mark style="color:blue;">fórmula em azul</mark>, que consiste em multiplicar a frequência e o ponto médio de cada classe, somar tudo e dividir por `n`, o número conhecido que é o total de dados.

<figure><img src="../../.gitbook/assets/media de dados agrupados.png" alt=""><figcaption></figcaption></figure>

### Mediana de dados agrupados

Para calcular a mediana de dados agrupados, precisamos seguir esta fórmula:

<figure><img src="../../.gitbook/assets/formula mediana de dados agrupados.png" alt=""><figcaption></figcaption></figure>

Essa classe `Md` que estamos falando se refere a <mark style="color:blue;">classe mediana referente às classes disponíveis</mark> na tabela. Precisamos descobrir qual é ela. Para isso, fazemos `n/2` e encontramos até qual intervalo de frequência está esse valor, por exemplo:

<figure><img src="../../.gitbook/assets/como achar a classe mediana.png" alt=""><figcaption></figcaption></figure>

### Moda de dados agrupados

Assim como foi encontrado a classe mediana acima, para a moda precisamos encontrar a <mark style="color:blue;">classe modal</mark> do intervalo. Essa classe será a que possui a maior **frequência absoluta**. Veja:

<figure><img src="../../.gitbook/assets/como achar classe modal.png" alt=""><figcaption></figcaption></figure>

Como `23` é a maior frequência, `40 |- 60` passa a ser a classe modal. Depois disso, basta seguir a fórmula abaixo:

<figure><img src="../../.gitbook/assets/moda de dados agrupados.png" alt=""><figcaption></figcaption></figure>

[^1]: Somatória de todos os valores divido por `n`, sendo a quantidade de valores.

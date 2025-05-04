# Naive Bayes

O teorema de Bayes define um rótulo baseado em uma estatística usando os dados que dispõe. Para isso, existe uma fórmula:

<figure><img src="../../../../../.gitbook/assets/teorema de bayes.png" alt=""><figcaption></figcaption></figure>

A probabilidade de um evento A ocorrer dado um evento B é igual a razão entre,&#x20;a probabilidade de B acontecer dado A multiplicado pela&#x20;probabilidade de A, e a probabilidade de B.

Para funcionar, isso tem que levar em consideração que as variáveis <mark style="color:orange;">são independentes</mark>, o que é algo muitas vezes falso, por exemplo: a quantidade de quartos de uma casa normalmente está correlacionada ao tamanho daquela casa. Mas vamos assumir isso mesmo assim.

## Resolvendo usando tabela a priori

Vamos supor que temos um registro de treinos de um atleta e queremos saber o que vai acontecer em determinadas condições:

<figure><img src="../../../../../.gitbook/assets/atleta histórico.png" alt=""><figcaption></figcaption></figure>

Nosso rótulo é o **Play**, que pode ser `Yes` ou `No`. Agora, queremos saber qual será o rótulo em uma determinada situação, como rainy, cool, high e TRUE. Vamos montar uma tabela a priori, que vai contar quantas vezes esses dados apareceram:

<figure><img src="../../../../../.gitbook/assets/tabela a priori 1.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../../../.gitbook/assets/tabela a priori 2.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../../../.gitbook/assets/tabela a priori 3.png" alt=""><figcaption></figcaption></figure>

Então, dada as condições, conseguimos a <mark style="color:blue;">probabilidade do retorno de cada rótulo</mark>. Por fim, rotulamos esse resultado final baseado no maior número que no exemplo é `0,02`. Então, nessas condições, o rótulo será `NO`.

## Suavização de laplace

Vamos supor que algum desses números de ocorrências a cima seja zero. Por se tratar de multiplicação, um simples zero iria zerar a conta toda:

<figure><img src="../../../../../.gitbook/assets/problema com ocorrências zero.png" alt=""><figcaption></figcaption></figure>

Veja que pode ocorrer em todas ocasiões, retornando zero em tudo e não sabendo o que devemos rotular. Essa suavização previne resultados zerados mudando um pouco a fórmula.

<figure><img src="../../../../../.gitbook/assets/suavização de laplace.png" alt="" width="563"><figcaption></figcaption></figure>

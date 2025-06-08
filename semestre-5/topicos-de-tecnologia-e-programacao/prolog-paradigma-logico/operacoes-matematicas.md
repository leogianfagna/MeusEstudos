# Operações matemáticas

Utiliza-se a palavra `is` para atribuir um valor para uma variável:

```prolog
soma(X, Y, T) :- T is X + Y.
```

```prolog
% Query
soma(15, 10, Quanto) % Soma = 25
```

## Variáveis

Podemos criar uma variável temporária que recebe um valor. O intuito de criar uma variável é poder usá-la em algum cálculo e depois passar como parâmetro em algum predicado.

```prolog
fatorial(X, F) :- X2 is X - 1, fatorial(X2, F2), F is X * F2.
```

Veja a ideia que `X2` é uma nova variável e ela é passada como parâmetro para a recursividade fatorial.

## Recursividade para contas

São exemplos calcular fatorial ou descobrir o tamanho de uma lista. Tem como objetivo armazenar o total parcial em uma variável e utilizá-la novamente, acumulando os cálculos.

O comportamento de passar uma variável para um predicado funciona da mesma forma que em uma linguagem orientada à objetos: passa uma cópia. Então veja abaixo que criamos uma variável chamada `TR`, e toda vez que usamos ela recursivamente estamos numerando-a como `TR1`, `TR2` e assim sucessivamente, para diferenciar e mostrar que são **diferentes**.

O valor de `T` no predicado "tamanho" é o retorno da consulta. Ele é composto por `T is TR + 1`, mas `TR` é composto por `TR2 + 1` e assim vai. Ou seja, <mark style="color:orange;">nenhuma dessas contas pode ser concluída até que o último</mark> <mark style="color:orange;"></mark><mark style="color:orange;">`TR`</mark> <mark style="color:orange;"></mark><mark style="color:orange;">seja resolvido</mark> (que no caso é o `TR3`).

Assim que o `TR3` é resolvido (que é zero), ele vai subindo e resolvendo os outros `TR` até chegar no `T`, a resposta final. Esse é o <mark style="color:green;">comportamento normal da recursividade</mark> em qualquer paradigma de programação.

Veja um banco de conhecimento composto desta forma:

```prolog
tamanho([], 0).
tamanho([_|R], T) :- tamanho(R, TR), T is TR + 1.
```

Uma resolução irá acontecer desta forma:

<figure><img src="../../../.gitbook/assets/is em prolog recursao.png" alt=""><figcaption></figcaption></figure>

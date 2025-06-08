# Listas

## Listas constantes

As listas constantes são usadas para fazer perguntas:

```prolog
[] % Lista vazia
[uva] % Lista com elementos específicos
```

## Padrões de listas

São padrões usados na hora de programar:

```prolog
[] % Lista vazia
L  % Lista qualquer, pode ser qualquer letra
[P] % Lista com elemento qualquer
[P|R] % Ao menos um elemento qualquer
[P,S|R] % Ao menos dois elementos
[P,S,T] % Exatamente 3 elementos
```

Usar uma `|` na lista simboliza que, o que está depois da barra é uma lista que contém tudo o que sobrar. Essa variável `R` pega todo o restante após a primeira e única variável `P`.

## Exemplo prático

Um exemplo que resgate quem é o último elemento de uma lista na pergunta, obtendo as seguintes respostas:

```prolog
?- ultimo([2,3,5,7], QUAL)    % QUAL = 7
?- ultimo([2], QUAL)          % QUAL = 2
?- ultimo([], QUAL)           % false
```

A ideia seria usar uma [recursão](regras-avancadas/recursao.md) para manipular a lista sem o primeiro elemento, mantendo apenas o resto `R`, até que ela tenha apenas um elemento e seja retornada (garantimos isso na primeira regra).

<figure><img src="../../../.gitbook/assets/listas em prolog.png" alt=""><figcaption></figcaption></figure>

A segunda linha especifica um predicado verdadeiro se houver no mínimo um **segundo elemento** `S`, e o primeiro elemento `_` não importa quem seja. Isso é feito para garantir que a recursão não seja chamada quando a lista esteja apenas com um elemento (pode entrar em ciclo infinito).

### Explicação de ultimo(\[P], P)

O processo de <mark style="color:green;">unificação das variáveis</mark> (utilizar a mesma variável dos dois lados/parâmetros) permite esse resultado. Como podemos ler essa regra?

<figure><img src="../../../.gitbook/assets/ler regra com duas variáveis iguais.png" alt="" width="563"><figcaption></figcaption></figure>

Então repare que a <mark style="color:red;">pergunta</mark> não colocou a mesma variável dos dois lados. Mas como QUAL é uma variável genérica, pela regra que declaramos em `ultimo`, ela assume o valor do elemento da lista.

Se tivermos apenas essa cláusula no banco, essas seriam as possíveis respostas:

```prolog
?- ultimo([uva], uva)          % true
?- ultimo([uva], QUAL)         % QUAL = uva
?- ultimo([uva], abacate)      % false, compara uva = abacate que resulta false
?- ultimo([uva, melao], QUAL)  % false, [uva, melao] não bate com o padrão [P]
```

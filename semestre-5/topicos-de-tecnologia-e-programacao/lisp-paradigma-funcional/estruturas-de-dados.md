# Estruturas de dados

## Par pontuado

Lisp é monolítico e não possui partes, portanto, não existem strings e essa simbolização é feita através de símbolos que simbolizam algo do mundo real. Por isso, temos a estrutura de par pontuado (também chamados de cons cells), que lembra duas posições de um vetor: `[0,1]` ou `(_ . _)`.

```lisp
(cons a b) ; → (a . b)
```

## Lista

Não existem tipos de listas, as "listas" são um <mark style="color:blue;">conjunto de par pontuados</mark> onde o segundo elemento do par, é um outro par e assim sucessivamente.

A lista complicada é a forma como o Lisp trabalha na prática. Contudo, sempre responde com lista simplificada e até aceita usá-las em qualquer ocasião. O último elemento de uma lista sempre será o nil, mesmo que na lista simples esse elemento seja omitido visualmente (ele existe).

* Lista complicada: `(1ºe . (2ºe . (nºe . nil )))`
  * Exemplo: `(1 . (2 . (3 . nil )))`
  * Se for vazia será `'nil`
* Lista simples: `(1ºe 2ºe 3ºe nºe)`
  * Se for vazia será `'()`

O conjunto das listas possuem uma intersecção no conjunto dos átomos, que são as listas vazias `'nil` ou `'()`.

## Árvores

O nil da extrema direita não é considerado um elemento. Não existem árvores vazias, mas existem aqueles com um átomo apenas.

<figure><img src="../../../.gitbook/assets/lisp arvores.png" alt=""><figcaption></figcaption></figure>

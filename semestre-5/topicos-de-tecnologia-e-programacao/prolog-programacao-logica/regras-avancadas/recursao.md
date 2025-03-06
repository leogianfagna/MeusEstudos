# Recursão

Em um exemplo que queremos encontrar todos os ancestrais de uma tal pessoa, é necessário usar recursão para ficar percorrendo gerações até que não encontre mais resultados, assim como de fato funciona uma [recursão](../../../../semestre-2/estrutura-de-dados/recursao.md).

#### Exemplo completo do uso de recursão

```prolog
progenitor(X,Y) :- pai(X, Y); mae(X, Y).

ancestral(X, Y) :- progenitor(X, Y).
ancestral(X, Y) :- progenitor(X, Alguem), ancestral(Alguem, Y).
```

#### Lógica recursiva

<figure><img src="../../../../.gitbook/assets/recursão em prolog.png" alt=""><figcaption></figcaption></figure>

A recursão fica repetidamente procurando quem é o pai/mãe (progenitor) de `X` e usando esse argumento novamente no ancestral, até que encontre o progenitor direto.

Em Prolog, a recursão da regra `ancestral(X, Y)` tenta **percorrer a árvore genealógica**, verificando se `X` é um ancestral de `Y`. Isso significa que:

1. `X` **é um ancestral de Y** se `X` for **pai/mãe diretamente de Y** → **(caso base)**.
2. `X` **pode ser um ancestral de Y** se `X` for progenitor de `Alguém`, e esse `Alguém` for ancestral de `Y` → **(caso recursivo)**.

Se, ao longo desse processo, `X` não levar até `Y`, então `X` **não é ancestral de Y**, mesmo que seja progenitor de alguém.

#### Primeira regra

{% hint style="info" %}
Vimos como funciona a criação de [mais de uma regra aqui](repetir-predicado.md).
{% endhint %}

Acima, vimos que a recursão chega na checagem de `ancestral(Alguem, Y)`, essa primeira regra serve para conferir se essa lógica é verdadeira, tendo como objetivo <mark style="color:orange;">encerrar a recursão</mark>. Ela vai conferir se já é um **progenitor direto**.

Em outras palavras, por ser recursividade, `ancestral(Alguem, Y)` fica sendo chamado **diversas vezes** até que a primeira regra seja verdadeira, encerrando aquele ciclo.

# Exercícios

## Concatenação

```prolog
concatena([], L, L).
concatena([X|R1], L2, [X|R3]) :- concatena(R1, L2, R3).
```

Os elementos da primeira lista [vão indo para o resultado R3](#user-content-fn-1)[^1] até que R3 se torne a segunda lista inteira (isso vai acontecer por causa do critério de parada). E então, a volta da recursividade vai juntando cada elemento da primeira lista deixado nas iterações.

<figure><img src="../../../.gitbook/assets/concatenacao prolog.png" alt=""><figcaption></figcaption></figure>



[^1]: Repare que o `R3` na chamada recursiva é o `[X|R3]` na declaração do predicado. Ou seja, a cada chamada, um novo elemento da primeira lista é mantido ali.

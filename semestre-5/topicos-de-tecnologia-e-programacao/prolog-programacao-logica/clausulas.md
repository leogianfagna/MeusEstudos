# Cláusulas

<figure><img src="../../../.gitbook/assets/clausula prolog.png" alt=""><figcaption></figcaption></figure>

Sentido :arrow\_right: (usar SE): Aluno passou `SE` nota for maior que 5 e frequência maior que 75.

Sentido :arrow\_left: (usar IMPLICA): Nota maior que 5 e frequência maior que 75 `IMPLICA` em aluno passar.

## Cláusulas de HORN

Combinações de predicado (visto acima) são apenas aceitas se formem cláusulas de Horn. São modelos, segue os tipos:

#### 1) FATO

Declara que algo É alguma coisa. Exemplo, a mesa É móvel.

```prolog
predicado(p1, ..., pn)

% Exemplo
movel(mesa) % mesa é um móvel e sempre será
```

#### 2) REGRA

Quando combinamos apenas um predicado e condições `E`.

```prolog
% Seja EX uma expressão relacional
predicado(p1, ..., pn) :- EX1, EX2, ..., EXn
```

#### 3) OBJETIVO OU PERGUNTA

É igual ao fato mas pode ter mais de um predicado. Quando houver apenas um predicado, ele precisa ser identificado pelo <mark style="color:blue;">contexto</mark>.

```prolog
predicado1(params), predicado2(params)
```

#### 4) SUCESSO

É vazio, sem nada. Ao longo das lógicas e processamentos, queremos chegar no sucesso.

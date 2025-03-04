# Repetir predicado

Uma grande regra pode ser dividida em duas. Isso pode ajudar evitar implementar lógicas muito complexas. Se tivermos mais de uma regra com o mesmo predicado, o Prolog vai passar uma por uma.

Por exemplo, se a primeira regra retornar verdadeiro, ele encerra ali e dá a resposta. Caso seja falsa, ele segue para a segunda, veja esse exemplo:

```prolog
% Antes
primo(I,X) :- (
                (
                  avoMat(MesmoAvoMat,I), avoMat(MesmoAvoMat,X)
                ); (
                  avoPat(MesmoAvoPat,I), avoPat(MesmoAvoPat,X)
                )
               ), I\==X.

% Depois
primo(I,X) :- I \== X, avoPat(MesmoAvo,I),avoPat(MesmoAvo,X).
primo(I,X) :- I \== X, avoMat(MesmoAvo,I),avoMat(MesmoAvo,X).
```

Ambos os jeitos possuem o **mesmo resultado**, mas o segundo é muito mais organizado.&#x20;

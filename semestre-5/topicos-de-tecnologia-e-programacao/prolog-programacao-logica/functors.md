# Functors

Representam um <mark style="color:purple;">parâmetro</mark> de um predicado.

* Podem ser assimiladas com structs em C.
* Não precisam manter o padrão de parâmetros (assim como os predicados devem manter)

<figure><img src="../../../.gitbook/assets/functor prolog.png" alt="" width="487"><figcaption></figcaption></figure>

Perguntas e consultas poderão retornar <mark style="color:green;">todo o functor ou um dado específico</mark> dele, isso depende de como implementamos a nossa sentença:

```prolog
?- pagou(jose,Oque). % Oque = comida(giovaneti, 100.00)
?- pagou(jose, comida(giovaneti, Quanto)). % Quanto = 100.00
```

<figure><img src="../../../.gitbook/assets/resgate de functors.png" alt="" width="563"><figcaption></figcaption></figure>

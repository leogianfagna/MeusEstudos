# Tipo de dados

## Booleano ou vazio

* True: T
* False: nil

O nil também pode ser a representação de uma lista vazia, como `nil` ou `'()`.

## Elementos

Um dado literal é representado pelo quote `'`. Um dado literal é o valor bruto dele, como se fosse um elemento. Um dado literal <mark style="color:green;">não é resolvido</mark> pelo código. Isso quer dizer que, quando representamos algo pelo quote, queremos aquilo de forma sólida sem se alterar.

```lisp
(+ 2 3) ;; Isso retorna 5
'(+ 2 3) ;; Isso é uma estrutura de dados, nada acontece
```

Por isso as vezes o T de true exibe um quote, se queremos que ele seja representado de maneira bruta. Sem ser representado dessa maneira `'T`, em algumas ocasiões, o interpretador pode tentar resolver esse T.

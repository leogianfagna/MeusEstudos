# Page 1

Se baseia nos conceitos matemáticos de função.

## Características

* Símbolos ao invés de strings que simbolizam algo do mundo real. Não possui partes. Monolítico.
* Estrutura <mark style="color:purple;">par pontuado</mark>, que lembra duas posições de um vetor: `[0,1]` ou `(_ . _)`.

## Lista

Não existem tipos de listas, as "listas" são um conjunto de par pontuados, onde o segundo elemento do par, é um outro par e assim sucessivamente.

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

### Métodos

Assim como em Prolog, podemos resgatar o primeiro elemento e o resto de uma lista:

* CDR: Também lido como coulder, retorna o lado direito da árvore, o que seria a lista sem o primeiro elemento.
* CAR: Retorna a sub árvore da esquerda, o que seria o primeiro elemento da lista.
* Comparando com Prolog, temos: `[P | R]` -> `[car | cdr]`.

<figure><img src="../../../.gitbook/assets/lisp cdr car.png" alt=""><figcaption></figcaption></figure>

Em `cdr` ou `car`, podemos acrescentar mais "a" ou "d" até 4 vezes. Essas são apenas letras para simbolizar se queremos a esquerda ou a direita, podendo também misturar as letras como: `caddar`.

<figure><img src="../../../.gitbook/assets/lisp caar com dois a.png" alt=""><figcaption></figcaption></figure>

## Eq

Serve para comparar átomos:

* (eq 10 10) T
* (eq 'puc 10) nil
* (eq '(2 3) '(2 3)) nil

## Soma e subtração simples

Existem os métodos +1 e -1. Não existem outros números ou outras operações matemáticas no Lisp puro, mas existe extensões podendo executar operações matemáticas.

* Lisp puro:
  * `(1+ 6)` 7
  * `(1- 5)` 4
* Além do Lisp puro:
  * `+ - / *` usando como prefixo.
  * `(+ 4 5)` 9

## Chamada e declaração de funções

Sendo `pf` os parâmetros funcionais, aqueles usados durante uma declaração e os `pr` os parâmetros reais, aqueles que substituirão os funcionais no uso da função.

<figure><img src="../../../.gitbook/assets/lisp funções.png" alt=""><figcaption></figcaption></figure>

## Condições

Para fazer condições, podemos criar uma lógica parecida com operador ternário ou switch case. A lógica é usar o operador cond que analisa uma condição. Se a condição for verdadeira, resulta o que foi declarado.

Se passar como false, teria que resultar em outro valor. Mas essa condição (que seria um else) não existe em Lisp. Portanto, essa segunda condição declara como 'T (true). Ou seja, sempre irá entrar fazendo com que na prática seja um else se não entrar na primeira.

<figure><img src="../../../.gitbook/assets/lisp cond.png" alt=""><figcaption></figcaption></figure>

Veja então que a linha do `T'` vira exatamente o else de um if. Isso quer dizer que também podemos colocar várias condições como se fosse um switch e definir o "default" no final:

```lisp
(defum negativo (X)
    (cond ((eq X 0) 'nil)
    ('T (ehNeg X X))))
    
;; Lógica por trás é: 
;; - se A chegar em zero, é porque ele era negativo.
;; - se D chegar em zero, é porque ele era positivo.
(defum ehNeg (A D)
    (cond ((eq A 0) 'T)
          ((eq D 0) 'nil)
          ('T (ehNeg (1+ A) (1- D)))))
```

```lisp
(defum somaLista (L)
    (cond ((atom L) 0)
          ('T (soma (car L)
                    (somaLista (cdr L))))))
                    
(defum somaArvore (A)
    (cond ((atom A) A)
          ('T (soma (somaArvore (car A))
                    (somaArvore (cdr A))))))
                    
defum eqArvore(A1 A2)
    (cond ((atom A1) (cond ((atom A2) (eq A1 A2)                      ;; 1
                           ('T 'nil))
          ((atom A2) 'nil)                                            ;; 2
          ((eqArvore (car A1)(carA2)) (eqArvore (cdr A1)(cdr A2))     ;; 3
          ('T 'nil)))                                                 ;; 4
          
;; 1: Se atom A1, conferir se A2 também é com outro cond, pois se ambos forem átomos,
;;    podemos compará-los com eq.
;; 2: Se !atom A1, podemos chegar se A2 é atomo pois se for, consequentemente, as
;;    árvores serão diferentes.
;; 3: Confere se a direita de ambas são iguais. Se sim, entra em recursão para checar
;;    o outro lado.
;; 4: Por fim, não são iguais.
```

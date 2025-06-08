# Métodos e funções

No Lisp puro, existem apenas 7 funções base: `car`, `cdr`, `cons`, `atom`, `eq`, `+1` e `-1`. Isso não quer dizer que para usar outros métodos precise importar algo, pois não precisa. Mas essas são as funções que podemos usar sem ter algo já pronto, como outras operações matemáticas ou conferir números por exemplo.

## CONS

Método para se criar um par pontuado. Ele não é necessário para sua declaração, podemos simplesmente usar `(a . b)` sem a chamada de método. A mesma coisa funciona para criações de listas encadeadas: `(a . (b . nil))`.

## ATOM

Verifica se o valor é um átomo, ótimo para comparar listas ou árvores (pois essas duas estruturas <mark style="color:orange;">não são átomos</mark> e usando recursão, vamos tirando elemento por elemento e se ambas são átomos fica mais fácil comparar).&#x20;

```lisp
(atom 42) ;; → T
(atom 'hello) ;; → T
(atom '(1 2 3)) ;; → nil
```

## CDR e CAR

São métodos para recuperar um elemento da posição do par pontuado, o esquerdo ou o direito. Como pares pontuados são feitos para formar strings e árvores, consequentemente, essa função pode servir para recuperar uma sub árvore inteira.

* CDR: Também lido como coulder, retorna o lado direito da árvore, o que seria a lista sem o primeiro elemento.
* CAR: Retorna a sub árvore da esquerda, o que seria o primeiro elemento da lista.
* Comparando com Prolog, temos: `[P | R]` -> `[car | cdr]`.

<figure><img src="../../../.gitbook/assets/lisp cdr car.png" alt=""><figcaption></figcaption></figure>

Em `cdr` ou `car`, podemos acrescentar mais "a" ou "d" até 4 vezes. Essas são apenas letras para simbolizar se queremos a esquerda ou a direita, podendo também misturar as letras como: `caddar`.

<figure><img src="../../../.gitbook/assets/lisp caar com dois a.png" alt=""><figcaption></figcaption></figure>

## EQ

Serve para comparar átomos:

* (eq 10 10) T
* (eq 'puc 10) nil
* (eq '(2 3) '(2 3)) nil

## Operações matemáticas

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

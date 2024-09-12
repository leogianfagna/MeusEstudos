---
description: Aprende o conceito de boxing e unboxing.
---

# Classes Wrapper

Cada tipo primitivo tem o espaço de memória em byte que ocuparão. Por conta disso, é necessário pensar que tipo a variável será, principalmente em programas que estarão em hardwares com pouca memória. Exemplo prático:

| Tipo   | Espaço de ocupação |
| ------ | ------------------ |
| byte   | 1 byte             |
| short  | 2 bytes            |
| int    | 4 bytes            |
| long   | 8 bytes            |
| float  | 4 bytes            |
| double | 8 bytes            |

A classe wrapper tem como <mark style="color:blue;">atributo um tipo primitivo</mark>. O nome da classe wrapper condiz com o nome do tipo começando com a letra maíscula, por exemplo: `Byte`, `Short`, etc. Exceto para int e char, que possui os nomes `Integer` e `Character`.

Essas classes "<mark style="color:blue;">embrulham</mark>" um tipo primitivo (wrapper em inglês significa embrulho). Ou seja, dentro de um objeto instanciado da classe Float, tem um atributo do tipo float e assim sucessivamente com todas. De forma simples de entender, um <mark style="color:green;">objeto Character embrulha um char</mark>.

Uma variável tipo char, sem estar na classe wrapper, é chamada de <mark style="color:purple;">unboxed</mark> pois ela não está embrulhada.

```java
int media, a = 3, b = 7;       -> VARIÁVEIS
Integer media, a = 3, b = 7;   -> OBJETOS
```

Por conta de Integer ser uma classe, as variáveis `a`, `b` e `media` <mark style="color:blue;">passam a ser objetos</mark>. Quando temos um objeto e vamos atribuir algo a ele, normalmente criamos uma instância com "new". Mas o Java permite escrever a = 3, isso representa:

<figure><img src="../../.gitbook/assets/comodidade Java em classes wrapper.png" alt=""><figcaption></figcaption></figure>

Tudo isso é **comodidade** que o Java fornece, faz automático. Isso também acontece até no `println(a)`, que não é necessário chamar o método `a.intValue()`.

## Quando usar atributos boxed ou unboxed

Objetos precisam de instâncias e elas alocam memória para funcionar, por isso, tipos <mark style="color:blue;">primitivos são mais leves</mark> e rápidos. Contudo, a classe wrapper possui diversos métodos disponíveis para uso. Se, ao fazer um programa, se deparar com a <mark style="color:orange;">necessidade de tais métodos</mark> (como transformar em string, binário, etc), é melhor optar pela classe. Caso contrário, utilizar tipos primitivos.

## Detalhe sobre automatização de objetos

Vimos anteriormente que o Java já automatiza a criação dos objetos, contudo:

#### Instânciando cada um usando new

Neste exemplo abaixo, criamos 3 instâncias e cada uma delas vai possuir seu endereço de memória diferente, obviamente por conta que um "new" aloca memória para isso. Lembrando que quando fizemos comparação entre objetos (no caso `a` e `b`), estaremos comparando seus endereços de memória. Por conta disso, a comparação vai retornar false.

```java
Integer a = new Integer(7);
Integer b = new Integer(7);
Integer c = new Integer(7);

(a == b) // false
```

#### Usando a comodidade que o Java permite

Dito acima que o Java oferece uma comodidade que podemos atribur logo o valor que será a mesma coisa que criar uma nova instância. Contudo, este caso <mark style="color:red;">tem uma pequena e sutil diferença</mark> que o próprio Java faz para gente.

Neste caso, na segunda linha, verifica que já existe um integer valendo 7 e por conta disso, o Java <mark style="color:orange;">não cria outro e usa o endereço</mark> guardado em "a" e guarda em "b". Resultando em que o objeto a terá o mesmo endereço de memória que b.

```java
Integer a = 7;
Integer b = 7;
Integer c = 7;

(a == b) // true
```

Neste exemplo, **apenas a primeira linha cria uma nova instância**.

#### Conclusão

Esse detalhe e raciocínio servem para todas as classes wrapper e classe String (que não é uma). Lembrando que, no exemplo dois, só a primeira linha cria uma instância nova. Isso também significa que o exemplo dois usa menos memória por ter menos instâncias, já que cada nova instância aloca memória.

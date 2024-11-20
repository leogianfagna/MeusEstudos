# Classe Object

Toda herança acontece pois uma classe não te atende perfeitamente pois, caso atendesse, usaríamos esta classe. A classe Object é uma classe onde todas as classes criadas em um projeto Java herdam, diretamente ou indiretamente. Uma classe só pode herdar de uma:

<figure><img src="../../../.gitbook/assets/herança direta ou indireta java.png" alt=""><figcaption></figcaption></figure>

Esta classe possui vários métodos, mas existem 5 específicos que não funcionam corretamente na classe herdada, portanto, precisam ser re-implementados na própria classe criada. Um método implementado novamente precisa receber a notação `@Override`. São eles:

* [toString()](tostring.md)
* [equals()](equals.md)
* [hashCode()](hashcode.md)
* [compareTo()](compareto.md)
* [clone()](clone.md)

> Java permite métodos com o mesmo nome mas seus parâmetros devem ser diferentes, caso contrário, ocorre o termo <mark style="color:orange;">sobrecarga</mark>.

Os três primeiros métodos, `toString()`, `equals()` e `hashCode()` são quase obrigatórios em todas as classes. Contudo, eles <mark style="color:red;">não devem</mark> ser reimplementados quando:

* A classe é <mark style="color:blue;">100% estática</mark> que não faz alteração em nenhum atributo.
* Eles estão em uma classe que herda de outra e a classe pai implementa esses métodos e satisfaz corretamente todos eles.

O método `compareTo()` deve ser implementado sempre que houver um critério de comparação, mas esse critério deve ser [puramente na linguagem de programação](#user-content-fn-1)[^1]. Esse método precisa retornar a mesma coisa que `equals()` retorne, assim também podemos visualizar melhor se existe um critério de comparação.

O método `clone()` precisa ser implementado toda vez que existe métodos que alteram atributos não estáticos.

[^1]: Uma classe sobre forças vetoriais, o que faria sentido comparar na vida real, não faz sentido comparar em Java.

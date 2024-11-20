# Classes de dados

Classes que são estruturas de dados guardam coisas. Essas coisas possuem um tipo, então essas classes combinam para ser [genéricas](classes-genericas.md). Elas não possuem `compareTo` e a implementação dos demais métodos levam a mesma lógica de sempre.

Um tipo `X` que ainda não existe não pode ser instanciado ou virar um vetor. A solução disso é criar como for um Object mas podendo receber apenas do tipo `X`. Ele vai guardar objetos desse tipo mas estão sendo vistos como Object, resolver isso podemos usar a [revelação](conversao-e-revelacao.md).

```java
return (X) this.elem[pos];
```

## Polimorfismo em classes de dados

Essas classes guardam coisas que não sabemos o que são e de que tipo que são. Por isso, implementamos métodos que lidam com esses dados independentemente do que eles são, fazendo com que funcionem independentemente do que são.&#x20;

Podemos empregar um método `toString` personalizado, que retorna uma representação em string apropriada do objeto armazenado.

```java
@Override
public String toString() {
    String ret = "{";
    
    if (this.qtd > 1)
        ret += this.elem[0];
    
    for (int i = 1; i < this.qtd; i++) {
        ret += "," + this.elem[i];
    }
    
    return ret + "}";
}
```

## Implementação

> [Aqui está um exemplo](../../exerc%C3%ADcios/java/exemplos/Conjunto%20de%20dados.java) de uma classe conjunto completa.

Os dados podem ser guardados em vetores normais em Java, onde cada posição equivale a um elemento do tipo X. Como `X` é indefinido durante a escrita do código, não podemos tratar o tipo dos dados [sendo do tipo `X`](#user-content-fn-1)[^1]. Por conta disso, precisamos tratar o tipo dos elementos desta classe como `Object`.

```java
public class Conjunto<X> {
    private Object[] elem;

    public Conjunto(int capInicial) throws Exception {
        this.elem = new Object[capInicial];
    }
}
```

#### Métodos básicos

* `redimensioneSe`: Método importante pois vetores em Java possuem tamanhos fixos. Se a inserção de dados ultrapassar esse limite, cria um novo vetor com o tamanho do antigo dobrado.
* `ondeEsta`: Retorna se o elemento informado existe e em qual posição está.
* `inclua`: Método que recebe um elemento e inclua-o de forma simples, fazendo as checagens necessárias.
* `getElemento`: Método que resgata o elemento baseado na posição.

Os métodos `equals` e `hashCode` precisam se adaptar para todos os elementos do vetor. Além disso, classes genéricas não levam `compareTo`.&#x20;

#### Uso na main

O uso de uma classe genérica basta criar uma instância informando o tipo de dado que será parametrizado, depois utilizar os métodos cabíveis:

```java
Conjunto<String> conj = new Conjunto<String>();
conj.inclua("Alguma coisa");
conj.inclua("Outra coisa");
```

[^1]: Por exemplo: `new X[capInicial]`. O compilador daria erro.

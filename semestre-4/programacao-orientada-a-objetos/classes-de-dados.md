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

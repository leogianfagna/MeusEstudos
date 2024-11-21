# hashCode

O método hashCode não é usado pelo usuário. Ao guardar algo (tabela, arquivo, etc), a busca pode ser sequencial, binária, etc. A tabela de hash é muito rápida e não exige busca e comparações, ela calcula através de uma função o que quer ser resgatado. Ela tem uma rapidez máxima mas usa muita memória, portanto, usamos quando precisamos priorizar a rapidez como programas críticos (avião, carro, etc).

Um objeto guardado na tabela de hash terá um hashCode para ser utilizado na busca. Por conta disso, esse método será usado pelas estruturas do sistema.

```java
@Override
public int hashCode() {
    int ret = 1;
    
    // se "atr" fosse um atributo não estático
    // que fosse um objeto de alguma classe
    if (atr != null)
        ret = ret * 7 + atr.hashCode();
    
    // Fazer isso para cada atributo não estático
    ret = ret * 2 + Byte.valueOf(this.meuAtributoTipoByte).hashCode();
    ret = ret * 11 + ((Short)this.meuAtributoTipoShort).hashCode();
    
    if (ret < 0) ret = -ret;
    
    return ret;
}
```

> Vemos acima que criamos uma condição para `atr != null`. Nesse caso, se o atributo for um objeto, precisa conferir se é **nulo**. Não é necessário com tipos primitivos.

As multiplicações que vemos tipo `* 7`, `* 2` ou `* 11` são números primos quaisquer. Esse método foi testado para melhor desempenho (impírico) portanto devemos fazer desta forma.

Outra anotação é que chamamos o método .hashCode() dentro dele mesmo. Neste caso, isso não é o uso de recursão (será visto mais para frente) e sim um método que vem da classe Byte ou Short, portanto, pode ser chamado daquela classe.

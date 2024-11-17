# toString

O uso deste método é <mark style="color:orange;">padronizado</mark> em Java. Quando printamos alguma coisa na tela, o interpretador rodaria isso como se fosse a chamada de função toString sem mesmo a necessidade de chamá-la, por exemplo:

```java
System.out.println(algumaVariavel) -> toString(algumaVariavel)
```

Por conta disso, é muito importante a reimplementar este método pois assim todo print estaria comprometido se não funcionar corretamente. E lembrando que, depois de implementar este método, os prints utilizarão ele automaticamente.

Como estamos fazendo um método do zero e ainda utilizando as mesmas variáveis disponíveis na classe, podemos criá-lo para printar algo do jeito que queremos. Por exemplo, um toString() em uma classe que mostra datas pode ser implementado retornando uma data formatada. Para implementá-lo novamente, podemos fazer algo desta forma:

```java
@Override
public String toString() {
    return this.dia + "/" + this.mes + "/" + this.ano;
}

// Exemplo mais complexo usando operador ternário ([condição] ? [se sim] : [se não])
@Override
public String toString() {
    return (this.dia < 10 ? "0" : "") + this.dia + "/" +
           (this.mes < 10 ? "0" : "") + this.mes + "/" +
           (this.ano < 0 ? (-this.ano + "ac") : this.ano);
}
```

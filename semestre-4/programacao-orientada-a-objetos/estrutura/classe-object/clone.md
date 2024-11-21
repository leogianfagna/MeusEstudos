# clone

## Conceituação de cópias

As vezes precisamos de uma variável que é cópia de outra, podendo ser um tipo primitivo ou um objeto, mas precisamos que essa cópia <mark style="color:blue;">mantenha-se o valor de origem</mark>, sem ser alterada ao longo da execução do programa.

Para fins de entender melhor, veja os exemplos:

<figure><img src="../../../../.gitbook/assets/conceituação de cópias de instâncias.png" alt=""><figcaption></figcaption></figure>

Podemos concluir que, como são objetos, eles são ponteiros e apontam para um endereço de memória, portanto, se não instanciarmos um novo, teremos apenas um endereço de memória e aí o mesmo valor vai valer para os dois (não pode). Isso causaria problema no encapsulamento, que é [descrito detalhamente aqui](../../pilares/encapsulamento.md).

Portanto, uma cópia vai se manter estável caso a cópia ou o objeto original <mark style="color:blue;">fazer uma nova instanciação</mark> (exemplos 1 e 2). Sem uma nova instância, os valores serão compartilhados.&#x20;

## Quando deve conter

O método clone precisa estar presente quando a classe <mark style="color:orange;">**possui métodos que alteram atributos não estáticos**</mark>. Exemplo desse método:

```java
public void setSaldo(double saldo) {
    this.saldo = saldo;
}
```

## Construtor de cópia

O <mark style="color:purple;">**construtor de cópia**</mark> é um construtor que recebe como parâmetro (e único) um <mark style="color:blue;">objeto da própria classe</mark>, tem como objetivo inicializar o novo objeto duplicando os valores dos atributos do objeto original, garantindo que ambos os objetos tenham estados idênticos, mas sejam instâncias separadas. Ele é necessário para o funcionamento do método `clone()`.

```java
public Data (Data modelo) throws Exception {
    if (modelo == null)
        throw new Exception("Modelo ausente.");
    
    this.dia = modelo.dia;
    this.mes = modelo.mes;
    this.ano = modelo.ano;
}
```

## Implementar método clone

A implementação desse método é obrigatório mencionar a "carteirinha", dizendo que ele implementa esse tipo de método, deixando na declaração da classe dessa forma:

```java
public class Data implements Cloneable {
    ...
    
    public Object clone() {
        Data ret = null;
        
        try {
            ret = new Data(this);
        } catch (Exception erro) {}
        
        return ret
    }
}
```

Vemos então que ele basicamente chama o construtor de cópia passando "this" como parâmetro, que é a própria instância chamante, fazendo com que crie uma completamente igual. Vemos também que há uma exceção vazia, isso porque esse novo construtor dá uma exceção caso a instância modelo for nula, mas neste caso, sabemos que não vai ser pois "this" nunca é nulo.

Além disso, um método clone tem que retornar obrigatoriamente um Object, como está no caso acima. Por conta desse retorno, chamar um `clone()` usa um type cast para o tipo da classe que quer, por exemplo:

```java
Data copia = (Data) data.clone();
```

### Exemplo com classe genérico e vetor

Se temos um vetor armazenador de dados, o construtor de cópia também precisa copiar todos os [<mark style="color:orange;">dados válidos</mark>](#user-content-fn-1)[^1] dentro do vetor.

* Os parâmetros e instanciações são o tipo da classe com o tipo genérico `<X>` junto.
* O novo vetor precisa ser instanciado (como Object) com o tamanho do vetor modelo.

```java
public Conjunto(Conjunto<X> modelo) throws Exception {
    if (modelo == null)
        throw new Exception("Modelo ausente.");

    this.qtd = modelo.qtd;
    this.capacidadeInicial = modelo.capacidadeInicial;
    this.elem = new Object[modelo.elem.length];

    for (int i = 0; i < this.qtd; i++)
        this.elem[i] = modelo.elem[i];
}

@Override
public Object clone() {
    Conjunto<X> ret = null;

    try {
        ret = new Conjunto<X>(this);
    } catch (Exception e) {}

    return ret;
}
```

[^1]: O tamanho alocado do vetor pode ser visto como `vetor.lenght`. Não necessariamente todo esse espaço está sendo ocupado por elementos. Portanto,  o `for` que copia os elementos tem como critério de parada um atributo que simboliza a quantidade de elementos **adicionados efetivamente** no vetor. No caso, simbolizado como `qtd`.

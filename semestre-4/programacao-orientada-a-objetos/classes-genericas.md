---
description: >-
  Como criar uma classe genérica, como um conjunto de dados, é mostrado na
  página de "Classes de dados".
---

# Classes genéricas

Podemos ter um parâmetro em classes para influenciar/direcionar no modo de funcionamento:

<figure><img src="../../.gitbook/assets/parametros em classes java.png" alt="" width="375"><figcaption></figcaption></figure>

Neste caso, indicamos que o vetor `v` guardará datas. O parâmetro de uma classe <mark style="color:orange;">deve ser uma outra classe</mark>. Já que muitas classes Java são parametrizadas, as **classes Wrapper** servem para esse intuito. Veja um exemplo na main:

```java
public static void main(String[] args) {
    Conjunto<String> linguagens;
    Conjunto<Integer> primos;
    Conjunto<Data> feriados;
    Conjunto<Conjunto<String>> conjuntos;
}
```

Quando uma classe tem parâmetro, ela é chamada de <mark style="color:blue;">genérica</mark>. A classe genérica permite uma única implementação, não precisa criar várias para cada tipo de parâmetro/tipo:

<figure><img src="../../.gitbook/assets/parâmetros em classes java na pratica.png" alt=""><figcaption></figcaption></figure>

Aqui vemos a criação de uma instância da classe **Conjunto** parametrizando uma String. Essa classe conjunto deixa a parametrização como `X`, o que significa que, esse X vai assumir o tipo inserido na hora da instanciação, ou seja, **String**. Então, se o conjunto foi criado com o tipo X sendo uma String, não aceitará (resultará erro) outro tipo, que é o exemplo da linha 3.

## Conjuntos heterogênios

O que foi mostrado acima é classificado como conjunto <mark style="color:blue;">homogênio</mark>. Um conjunto <mark style="color:blue;">heterogênio é quando ele aceita qualquer tipo de dado</mark>. Por exemplo:

```java
Conjunto<Object> tudo = new Conjunto<Object>();
```

Sabemos que Object simboliza tudo, então qualquer tipo pode ser guardado, o que define o conjunto heterogênio. Isso não é tão vantajoso pois a funcionalidade das classes parametrizadas é criar uma segurança nos tipos e ao fazer isso com Object é desvantagem pois pega algo que não sabemos o que é.

## Classes que são conjunto de dados

Classes que são estruturas de dados guardam coisas. Essas coisas possuem um tipo, então essas classes combinam para ser [genéricas](classes-genericas.md).

### Lidando com tipos

Um tipo `X` que ainda não existe <mark style="color:red;">não pode ser instanciado ou virar um vetor</mark>. A solução disso é criar como for um Object mas podendo receber apenas do tipo `X`. Ele vai guardar objetos desse tipo mas estão sendo vistos como Object, resolver isso podemos usar a [revelação](conversao-e-revelacao.md).

```java
// Definir vetor
private Object[] elem;

// Retorno de métodos
public X getElemento() {}

// Criar um novo vetor
Object[] novo = new Object[novaCapacidade];

// Retornar um elemento do vetor
return (X) this.elem[pos];

// Para método equals, fazer enxergar como conjunto pois é recebido como Object
Conjunto<X> conjunto = (Conjunto<X>) obj;
Object[] resultadoBusca = ondeEsta((X) conjunto.elem[i]);

// Onde é um object que armazena { boolean, int }
Object[] onde = this.ondeEsta(x);
boolean elementoJaExiste = (Boolean) onde[0];
```

<mark style="color:purple;">Em resumo</mark>, precisamos revelar com `(X)` toda vez pois os vetores estão declarados como sendo Object no começo da classe, <mark style="color:red;">mesmo se</mark> ele já é do tipo `Conjunto<X>` e é preciso lembrar que devemos sempre criar vetores do tipo Object[^1].

### Métodos padrões

Elas não possuem `compareTo` e a implementação dos demais métodos levam a mesma lógica de sempre.

### Implementação

> [Aqui está um exemplo](../../exerc%C3%ADcios/java/exemplos/Conjunto%20de%20dados.java) de uma classe conjunto completa.

Os dados podem ser guardados em vetores normais em Java, onde cada posição equivale a um elemento do tipo X. Como `X` é indefinido durante a escrita do código, não podemos tratar o tipo dos dados [sendo do tipo `X`](#user-content-fn-2)[^2]. Por conta disso, precisamos tratar o tipo dos elementos desta classe como `Object`.

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

[^1]: Um vetor é criado com:

    `int vet = new int[5]`.



    Com Object é a mesma coisa.

[^2]: Por exemplo: `new X[capInicial]`. O compilador daria erro.

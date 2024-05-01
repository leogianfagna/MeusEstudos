---
description: >-
  Termologias e estudos feitos em sala de aula para entender conceitos de forma
  mais avançada e com mais detalhes.
---

# Conceitos de Orientação à Objetos

## Empilhamento de strings

Quando você concatena strings em linguagens de programação como Kotlin, cada vez que você usa o operador de concatenação (por exemplo, `+`), uma nova string é criada na memória para armazenar o resultado da concatenação. Isso ocorre porque strings são imutáveis em Kotlin e em muitas outras linguagens de programação.

Portanto, cada concatenação cria mais um espaço na memória para armazenar a nova string criada. A solução disso ocorre utilizando a interpolação. A interpolação de strings permite incorporar expressões diretamente em uma string, sem a necessidade de concatenação explícita. Ela possui esse formato:

```kotlin
val nome = "Alice"
val idade = 30
val mensagem = "Olá, meu nome é $nome e tenho $idade anos"

println(mensagem)
```

Assim, é criado uma única string na memória que <mark style="color:green;">**faz referência**</mark> às demais strings utilizadas.



## Mutabilidade

Quando cria uma variável imutável (com <mark style="color:purple;">`val`</mark>), o correto a se dizer é que não é possível <mark style="color:orange;">**alterar a referência**</mark> dela. Já adicionar, substituir ou alterar elementos desse <mark style="color:blue;">**objeto**</mark> é sim possível.

No caso da criação de uma lista, podemos criar ela como uma variável `val`, isso vai fazer com que ela se mantenha no <mark style="color:orange;">**mesmo espaço de memória**</mark>. Sendo assim, essa lista pode ser criada com a função `multableListOf()` caso ela não seja apenas leitura, isso vai fazer com que os objetos dentro dela possam ser alterados.

```kotlin
val minhaLista = multableListOf("Elemento 1", "Elemento 2")

print(minhaLista)
```



## Classes e objetos

As classes e os objetos são “coisas” que necessitam ser representadas em um programa. Em um exemplo de um software de universidade, há de se representar o aluno, portanto, ele será um objeto.

Porém, esse mesmo objeto ele pode ser diferente baseado no ambiente, em outras palavras, o mesmo objeto nem sempre nem sempre tem o mesmo significado em sistemas diferentes. O nome disso é <mark style="color:blue;">**nível de abstração**</mark>.

Para especificar usando cenários diferentes, vamos supor um relógio para uma empresa de comércio. Esse relógio possui diversas propriedades como marca, modelo, valor e outros. Mas, esse exato mesmo relógio para a empresa que o fabricou vai ter muito mais propriedades do que o exemplo anterior, como por exemplo: diâmetro, material da pulseira, entre tantos outros.



## Instâncias

Elas são as realizações das classes. Então por exemplo, se temos a classe forma, cada item fabricado por essa forma é uma instância. Em exemplos mais práticos, em uma classe chamada “produto”, cada item a ser vendido é uma instância.

Para criar uma instância de uma classe já recebendo algumas novas propriedades, segue desta forma:

<figure><img src="../../.gitbook/assets/construtor de uma classe.png" alt=""><figcaption></figcaption></figure>

```kotlin
class Produto(val marca: String, val modelo: String)

fun main() {
    val normal = "String normal"
    val instanciaDaClasse = Produto("String em uma instância", "Galaxy")
    
    println("Aqui está a string $normal") // Exemplo normal
    println("Aqui está uma ${instanciaDaClasse.marca}") // Exemplo com instância
}
```

É possível invocar funções através de instâncias caso elas sejam do tipo de alguma classe. Veja no exemplo abaixo onde a instância chamada <mark style="color:purple;">**`locacaoInstancia`**</mark> é uma <mark style="color:blue;">**instância da classe locação**</mark>, cuja classe possui uma função dentro dela de imprimir. Por conta disso, essa função pode ser chamada através dessa variável, dessa forma a seguir:

```kotlin
data class Locacao(val dataRetirada: String, val dataDevolucao: String) {
    fun imprimir() {
        print("Retirada: $dataRetirada - Devolução: $dataDevolucao")
    }
}

val locacaoInstancia = Locacao("01/03/2024", "09/03/2024", empresa, veiculo)

locacaoInstancia.imprimir()
```

<mark style="color:red;">**Data class**</mark> são classes que funcionam apenas para leitura e não haver operações dentro delas, portanto declaradas como “data class”.



## Classes de dados

Elas são as utilizadas para fazer armazenamento de dados. A diferença de declarar uma classe de dados de uma classe normal é que a de dados irá <mark style="color:blue;">**receber automaticamente funções**</mark> disponíveis pelo Kotlin, poupando assim a necessidade de perder tempo criando funções. São exemplo dessas funções:

* toString()
* equals()
* copy()

Isso quer dizer que não é necessário a invocação dessas funções para atingir o seu propósito. Isso significa que elas são invocadas automaticamente pelo interpretador nas situações em que elas deveriam ser exigidas, por exemplo:

<figure><img src="../../.gitbook/assets/instanciacao de classe.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/metodo equals (1).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/métodos herdados de data class.png" alt=""><figcaption></figcaption></figure>

No caso do COPY, é sugerido copiar ao invés de alterar a instância original para não afetar o resto do código que possa estar usando aquela instância. Também lembrando que na terceira linha declarou o “id” ao invés de somente colocar o valor, isso porque ele está na segunda posição das propriedades da classe.



## Herança de classes

Podemos criar uma classe que possui todas as características de uma outra classe mais outras características criadas. Basicamente, herda da classe pai.

```kotlin
class Pessoa(...)

class Estudante : Pessoa {
    val ...
}
```

Em uma leitura do exemplo acima, a classe estudante herda a classe pessoa. Podemos dizer que “Estudante” é “Pessoa”.



## Construtores

Vamos lembrar que toda classe criada ela vem com um construtor. Nos exemplos vistos, o construtor foi declarado com as propriedades da classe, mas, caso ele não tenha sido, a classe automaticamente cria um construtor que chamamos de padrão sem argumentos.

Para isso devemos ver que existem três tipos de construtores:

1. Primário
2. Secundário
3. Padrão

O primário é aquele construtor que nós declaramos após a classe com as variáveis. Ele é obrigatório em caso de classes de dados.



## Composição

Composição significa que uma classe <mark style="color:blue;">**possui instâncias de outras classes**</mark> como parte de sua estrutura interna, ou também um objeto é composto por outros objetos.

<figure><img src="../../.gitbook/assets/heranças de classes.png" alt=""><figcaption></figcaption></figure>

Repare que na classe “Locação” existem (é composta por) dois objetos, que são objetos das classes Empresa e Veículo. Como a classe Locação possui instâncias de outras classes em sua estrutura, ela pode receber valores em uma declaração de uma instância durante uma função, por exemplo:

<figure><img src="../../.gitbook/assets/instanciação com herança de classes.png" alt=""><figcaption></figcaption></figure>

Um conceito extremamente importante usado em classes. Em resumo, composição é uma forma de construir classes onde elas contêm objetos de outras classes como parte de sua estrutura interna, permitindo criar relacionamentos complexos entre objetos.

Uma observação importante para desempenho de um sistema como um todo: quanto mais genérico a classe é, melhor será. Tem que tomar cuidado com o nível de abstração, você não pode criar uma classe errada para um tipo de objetivo. Por exemplo, não faz sentido ter uma classe relógio no Mercado Livre, e sim a classe Produto.

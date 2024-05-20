# Documentação básica

## Tipos básicos

Toda variável e dados possui um tipo, obrigatoriamente. A linguagem Kotlin possui a habilidade de inferir o tipo de dado, isto é, na declaração de uma variável quando se atribui um valor a ela, o Kotlin já decide qual é o tipo daquela variável por inferência. Por exemplo:

```kotlin
fun main() {
    val PI = 3.1415
    val r = 20
    val c = 0
    
    // PROBLEMA! C foi iniciado como inteiro e resultou em outro tipo
    c = 2 * PI * r
    print(c)
}
```

Neste exemplo acima, todas as variáveis foram iniciadas por inferência. A variável <mark style="color:purple;">**`c`**</mark> foi iniciada como inteiro, pois zero é um número inteiro. Por conta disso, no último cálculo temos um problema, já que vai atribuir um valor que não é inteiro para <mark style="color:purple;">**`c`**</mark>. Para corrigir esse problema, essa variável poderia ter sido iniciada no valor de `0,0`, que simbolizaria em um <mark style="color:red;">**float**</mark>.

As variáveis também podem receber <mark style="color:blue;">**atribuição posterior**</mark>. Isto é, ao longo do código recebem o valor dela. Neste caso, na declaração, é preciso declarar o tipo dela. Um código exemplo disto fica:

```kotlin
// Declaração e atribuição posterior
val p2Nome: String
val p2Idade: Int
val p2AlturaEmCm: Int

p2Nome = "Nina"
p2Idade = 20
p2AlturaEmCm = 160
```

Este exemplo não é muito performático pois <mark style="color:red;">**escreve mais e acumula espaço**</mark>. Veja abaixo um exemplo completo do que seria a melhor programação:

```kotlin
// Declaração e inicialização por inferência
val p1Nome = "Diogo"
val p1Idade = 21
val p1AlturaEmCm = 170

p2Nome = "Nina"
p2Idade = 20
p2AlturaEmCm = 160

// Atribuição posterior
val p2Nome: String
val p2Idade: Int
val p2AlturaEmCm: Int

p2Nome = "Nina"
p2Idade = 20
p2AlturaEmCm = 160

// Exemplo mais performático: não gasta processamento do computador para decidir
// o tipo de variável
val p3Nome : String = "Léo"
val p3Idade : Int = 24
val p3AlturaEmCm : Int = 180
```

A inferência em tipos primitivos é rápida e otimizada, portanto, não é necessária ficar declarando o tipo por questões de processamento. Por exemplo, quando se trata de varáveis do tipo inteiro, números naturais, reais, strings e outros. Qualquer outro tipo que não seja primitivo é recomendado fazer a declaração.

#### Assim sendo, todos os tipos mais usados e comuns na linguagem são:

| Inteiros                   | Byte, Short, Int, Long     |
| -------------------------- | -------------------------- |
| Inteiros não assinados     | UByte, UShort, UInt, ULong |
| Números de ponto flutuante | Float, Double              |
| Booleanos                  | Boolean                    |
| Caracteres                 | Char                       |
| Strings                    | String                     |



## Coleções (listas)

As coleções são necessárias para <mark style="color:blue;">**agrupar dados em estruturas**</mark>. Existem as listas, conjuntos e mapas. As listas guardam itens na ordem em que são adicionadas, podendo repetir dados. Elas podem ser alteradas ou não.

```kotlin
val listaApenasLeitura = listOf("algo", "outro", "algum")
val listaMutavel = mutableListOf("algo", "outro", "algum")
```

Em Kotlin, o uso da variável <mark style="color:red;">`val`</mark> ou <mark style="color:red;">`var`</mark> diz a respeito da <mark style="color:blue;">**mutabilidade do objeto**</mark> em si e não dos itens contidos nele, por conta disso, é declarado mesmo assim com <mark style="color:red;">`val`</mark>, já ela vai se manter como o mesmo tipo (uma lista) e também pois esse tipo de variável é preferível.

O Kotlin através da inferência vai descobrir o tipo dessa lista através das variáveis declaradas dentro dela. Por conta disso, é possível declarar uma lista especificando o tipo com essa sintaxe:

```kotlin
// Pode declarar o tipo da lista com:
val minhaListaDeFormatos : MutableList<String> = mutableListOf("triângulo", "quadrado", "circulo")
```

<mark style="color:purple;">**Casting**</mark> é o processo de converter um valor de um tipo de dados para outro tipo de dados relacionado. Isso geralmente ocorre quando você deseja tratar um objeto de uma classe como se fosse um objeto de outra classe, ou quando você precisa converter um tipo primitivo em outro tipo primitivo compatível. Eles podem ser usados na lista:

<figure><img src="../../../.gitbook/assets/tipos de listas.png" alt=""><figcaption></figcaption></figure>

Neste caso, a lista travada está recebendo a outra lista, que já possui alguns valores. Apesar da lista “shapes” ser mutável, a lista travada não será e não poderá ser alterada pois foi iniciada com o tipo “List” ao invés do tipo “MutableList”.



### Funções nas listas

Existem funções nas listas que podem ser usadas para alterar ou resgatar dados. Veja abaixo:

| Código       | Funcionalidade                      |
| ------------ | ----------------------------------- |
| .\[0]        | Resgata o valor na posição inserida |
| .first()     | Resgata o primeiro valor            |
| .last()      | Resgata o último valor              |
| .count()     | Retornar total itens na lista       |
| .add(“ ”)    | Adicionar um item na lista          |
| .remove(“ ”) | Remover um item da lista            |

Ainda existem operadores como o <mark style="color:red;">`in`</mark>, que pode servir para conferir se existe esse elemento na lista:

```kotlin
val listaFormatos = listOf("triângulo", "quadrado", "circulo")
println("quadrado" in listaFormatos)

// Retorna: true
```



## Coleções (Sets e maps)

Fazendo também parte das coleções, as listas, conjuntos e mapas possuem funcionalidades semelhantes, mas com propósitos diferentes. Conjuntos (sets) e listas (list) são muito parecido e usam das mesmas funções.

A diferença é que os conjuntos não possuem uma ordem (ou podemos falar índice) dos elementos, então não se pode buscar elementos na posição 1, por exemplo. Além disso, não pode repetir dados em um conjunto. Usa-se conjunto quando você precisa garantir que os elementos são únicos.

Já os mapas são baseados em chave valor onde cada chave possui um valor. Podem ter itens iguais, mas não chaves iguais. Os mapas possuem uma diferença em sua semântica (além de usar <mark style="color:red;">`PUT`</mark> ao invés de <mark style="color:red;">`ADD`</mark>), mas o funcionamento é o mesmo:

```kotlin
val cardapioDeSuco = mapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
cardapioDeSuco.put("coconut", 150)

println("O valor para o suco de maçã é ${cardapioDeSuco["apple"]}")
```

Todos eles possuem quase a mesma forma de declaração.

* <mark style="color:purple;">`listOf()`</mark> para listas
* <mark style="color:purple;">`setOf()`</mark> para sets
* <mark style="color:purple;">`mapOf()`</mark> para mapas



## Condições

Assim como qualquer linguagem, o Kotlin também possui a estrutura <mark style="color:orange;">**IF/ELSE**</mark> no mesmo padrão e sintaxe. A diferença é que essa estrutura pode ser usada como uma expressão para retornar resultados diretamente, por exemplo:

```kotlin
val a = 1
val b = 2

// Usa uma expressão ao invés da estrutura clássica
println(if (a > b) a else b)

// Retorna: 2
```

No caso do <mark style="color:orange;">**SWITCH CASE**</mark>, é substituído por <mark style="color:purple;">**WHEN**</mark> (usando <mark style="color:purple;">**ELSE**</mark> no lugar do <mark style="color:orange;">**DEFAULT**</mark>). Contudo, nessa linguagem ele é muito mais poderoso pois pode receber expressões e condições complexas, como por exemplo:

```kotlin
val x = 5

val resultado = when (x) {
    1 -> "Um"
    2, 3 -> "Dois ou três"
    in 4..10 -> "Entre quatro e dez"
    is String -> "É uma string"
    else -> "Outro caso"
}

print(resultado)
```

Quando mais ações ou resultados são necessários dentro de cada caso, abre-se colchetes, desta forma:

```kotlin
val x = "1"
var teste: Int
var testeDois: Int

when (x) {
    "1" -> {
        teste = 1
        testeDois = 2
    }
    
    "2" -> {
        teste = 3
        testeDois = 4
    }
    
    else -> {
        teste = 5
        testeDois = 6
    }
}
```

### Múltiplas condições

Nestes casos fica muito parecido ás linguagens comuns como Javascript. Usar os operadores **`&&`** e **`||`**, assim como o **`!`** para não.

```kotlin
val a = 5
val b = 10
val c = 15

if ((a < b && b < c) || (a + b > c)) {
    println("Condições complexas satisfeitas.")
} else {
    println("Condições complexas não satisfeitas.")
}
```

## Alcance (range)

Criar tipos de alcances é muito utilizado dentro de construtores como no caso de loopings. Existem vários tipos, o mais comum sendo a reticências de dois pontos. Veja abaixo alguns exemplos:

| Operador   | Exemplo     | Resultado          |
| ---------- | ----------- | ------------------ |
| ..         | 1..4        | 1, 2, 3, 4         |
| ..<        | 1..<4       | 1, 2, 3            |
| downTo     | 4 downTo 1  |  4, 3, 2, 1        |
| step       | 1..5 step 2 | 1, 3, 5            |
| 'x' .. 'x' | 'a' .. 'd'  | 'a', 'b', 'c', 'd' |

O último exemplo segue na mesma lógica dos demais, ele serve apenas para mostrar que tudo também pode seguir com letras.



## Loops

Assim como as demais linguagens, os loops mais comuns são o <mark style="color:purple;">**FOR**</mark> e o <mark style="color:purple;">**WHILE**</mark>, possuindo a mesma característica.

No FOR (usado para percorrer uma sequência de elementos), a variável que representa/assume cada elemento (normalmente o “i”) é declarada <mark style="color:blue;">**implicitamente**</mark>, ou seja, não é necessário declarara-la anteriormente. Assim sendo, temos:

<figure><img src="../../../.gitbook/assets/range em kotlin.png" alt=""><figcaption></figcaption></figure>

Além disso, utilizando-se quase da mesma sintaxe acima, se usarmos <mark style="color:purple;">`in <LISTA>`</mark> criaremos uma condição que executa para cada item daquela lista, então por exemplo:

```kotlin
fun main() {
    
    val bolos = listOf("cenoura", "queijo", "chocolate")
    
    // tipoDoBolo (declarado implicitamente) vai assumir o valor atual da lista
    for (tipoDoBolo in bolos) {
        println("É um bolo de $tipoDoBolo")
    }
}

/* Retorna:
    É um bolo de cenoura
    É um bolo de queijo
    É um bolo de chocolate
*/
```

No WHILE usamos da mesma forma das demais línguas, para executar instruções enquanto a condição for verdadeira ou também para executar o bloco de instruções ao menos uma vez e depois checar a condição, com DO-WHILE (assim como é nas demais linguagens).

```kotlin
fun main() {
    var bolosComidos = 0
    var bolosAssados = 0
    
    // While comum, com uma condição antes
    while (bolosComidos < 3) {
        println("Coma um bolo")
        bolosComidos++
    }
    
    // Bloco que será executado obrigatoriamente
    do {
        println("Asse um bolo")
        bolosAssados++
    } while (bolosAssados < bolosComidos) // Condição para se repetir
}
```



## Funções

As funções em Kotlin podem retornar ou não um valor. Quando um valor será retornado, deve especificar o tipo do valor, assim como deve especificar o tipo das variáveis que foram inseridas como argumentos.

No exemplo abaixo, um exemplo de função de soma que foi inserido dois argumentos e ambos especificados do tipo.

```kotlin
fun soma(x: Int, y: Int) : Int {
    return x + y
}

fun main() {
    println(soma(1,2))
    
    // Retorna: 3
}
```



### Argumentos nomeados

São aqueles argumentos que são passados como <mark style="color:blue;">**parâmetros**</mark> em funções, eles não precisam ter um nome, mas é uma boa prática fazê-los desta forma. Usando-os desta maneira, isso vai permitir que eles sejam usados fora de ordem.

```kotlin
fun mensagemComPrefixo(mensagem: String, prefixo: String) {
    println("$prefix = $message")
}

fun main() {
    // Aqui estão os argumentos nomeados
    mensagemComPrefixo(prefixo = "Log", mensagem = "Olá")
    
    // Alternativa sem argumentos nomeados:
    mensagemComPrefixo("Olá", "Log")
    
    // Retorno: Log = Olá
}
```



### Parâmetros padrões

Também é possível já declarar o valor do parâmetro na declaração da função, fazendo com que, caso ele não seja declarado quando chamado, vai usar o valor padrão utilizado:

```kotlin
// Função com um parâmetro padrão "prefixo"
fun mensagemComPrefixo(mensagem: String, prefixo: String = "Info") {
    println("$prefix = $message")
}

fun main() {
    mensagemComPrefixo(prefixo = "Log", mensagem = "Olá")
    // Retorno: Log = Olá
    
    mensagemComPrefixo("Olá", "Log")
    // Retorno: Log = Olá
    
    mensagemComPrefixo("Olá") // Não declara o segundo argumento
    // Retorno: Info = Olá
}
```

Quando há esses parâmetros com valores padrões, você pode apenas pulá-los quando chamar a função. Contudo, todas as variáveis após essa variável omitida devem ser declaradas na chamada de função.



## Funções sem retorno

Funções que possuem apenas uma linha entre as chaves que declaram alguma expressão ou algo do tipo pode ser declarada usando apenas uma única linha para deixar um código mais limpo. Por exemplo:

<figure><img src="../../../.gitbook/assets/funcoes com retornos.png" alt=""><figcaption></figcaption></figure>

Alguns detalhes muito importantes neste caso:

1. Vemos que do exemplo antigo para o novo deixou de declarar o tipo do retorno. Isso é possível apenas neste caso OU quando a função não possui um retorno, o que não é o caso.
2. Chamamos o que fica entre as chaves de corpo, portanto, podemos dizer que essa segunda função não possui um corpo



## Expressões Lambda

As funções Lambda podem ser usadas em qualquer lugar onde o código é escrito, entregando uma maior flexibilidade de código. Elas são utilizadas principalmente para criação de funções de ordem superior, que são <mark style="color:blue;">**funções que recebem outras funções como parâmetros**</mark> ou retornam funções como resultado.

<figure><img src="../../../.gitbook/assets/chamada de funcoes em uma linha.png" alt=""><figcaption></figcaption></figure>

Neste exemplo, temos uma função `println` que usa uma expressão Lambda, utiliza o “hello” para invocar a função com essa string. Em outras várias ocasiões essas funções podem ser utilizadas.



### Atribuir a uma variável

Atribua uma função Lambda inteira a uma variável, por exemplo:

```kotlin
val upperCaseString = { string: String -> string.uppercase() }

println(upperCaseString("olá"))
```

Muito detalhe aqui pois vemos que a string “Hello” não foi usada logo após a definição para chamar a função, e sim depois no uso do println.



### Passar para outra função

No exemplo abaixo, após a função <mark style="color:purple;">`FILTER`</mark>, chama uma expressão Lambda com o parâmetro “x” sendo um inteiro, com o corpo da função é conseguir todo x que seja maior ou menor que zero (há dois casos, para os positivos ou negativos).

```kotlin
fun main() {
    val numeros = listOf(1, -2, 3, -4, 5, -6)
    
    val positivos = numeros.filter { x -> x > 0 }
    val negativos = numeros.filter { x -> x < 0 }
    
    println(positivos)
    println(negativos)
}
```



## Tipos de funções

Assim como variáveis, funções também possuem tipos e que também são inferidos pelo próprio Kotlin. Contudo, as vezes é preciso definir o tipo daquela função para o programa entender o que é e o que não é permitido naquela função. Um tipo de função descreve os tipos que ela recebe e os tipos que retorna/produz.

Portanto, embora em muitos casos o Kotlin possa inferir o tipo da função automaticamente, explicitamente especificá-lo pode ser útil para melhorar a legibilidade, evitar ambiguidades e garantir compatibilidade com outras partes do código ou APIs externas.

<figure><img src="../../../.gitbook/assets/expressoes lambda.png" alt=""><figcaption></figcaption></figure>

Neste caso, <mark style="color:purple;">`upperCaseString`</mark> é uma variável que <mark style="color:blue;">**armazena uma função Lambda**</mark> que será invocada posteriormente, na função “main”. Essa função já recebeu o seu tipo na sintaxe `(String) -> String`, ou seja, entra e saí uma String.



## Classes

Como Kotlin é baseado em orientação a objetos, classes permitem que você declare uma série de características para um objeto. Elas possuem propriedades e são declaradas desta forma:


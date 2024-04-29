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

...

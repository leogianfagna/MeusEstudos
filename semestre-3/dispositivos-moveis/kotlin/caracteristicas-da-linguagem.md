# Características da linguagem

## Nulo seguro

A linguagem Kotlin permite você ter o valor nulo, que é diferente de indefinido. Contudo, o Kotlin tem uma proteção contra nulos que detecta possíveis problemas antes de ser compilado. Basicamente, essa linguagem “Null Safety” possui os seguintes recursos:

1. Declarar quando nulos são permitidos no programa
2. Checar todos os nulos
3. Usar chamadas seguras para propriedades ou funções quando podem conter nulos
4. Declarar ações caso uma propriedade nula for encontrada

Por padrão, a declaração de um nulo não é permitida a uma propriedade. Contudo, adicionando uma interrogação na declaração vai permitir essa abordagem. Veja o exemplo:

```kotlin
val nuncaNulo: String = "Isso não pode ser nulo"
nuncaNulo = null
// Retorna: Erro

val podeSerNulo: String? = "Isso pode virar nulo"
podeSerNulo = null
// Isso é aceitável
```

Portanto, basta adicionar a interrogação logo após o tipo. A declaração do valor não é necessária logo no início, como foi feito no exemplo.

Neste exemplo abaixo, acontece uma verificação para ver se uma string é nula ou não. Para isso é muito simples, foi criado uma função que recebe uma string (que pode ser nula ou não, foi adicionada uma interrogação) e usando condições IF/ELSE baseado no tamanho ou no valor da string, tem se o resultado:

```kotlin
fun descreverString(talvezString : String?): String {
    if (talvezString != null && talvezString.length > 0) {
        return "String de tamanho ${talvezString.length}"
    } else {
        return "String nula ou vazia"
    }
}

fun main() {
    var stringNula: String? = null
    
    println(descreverString(stringNula))
    // Retorno: String nula ou vazia
}
```



## Safe calls

Se estamos acessando dados que <mark style="color:orange;">**possivelmente podem ser nulos**</mark>, devemos fazer chamadas seguras para evitar erros. Usando também interrogação como operador, a operação segura vai retornar nulo caso o dado também o seja. Valores nulos podem disparar muitos problemas na compilação.

```kotlin
fun tamanhoString(talvezString: String?): Int? = talvezString?.length

fun main() {
    var stringNula: String? = null
    
    println(tamanhoString(stringNula))
    // Retorna: null
}
```

Neste exemplo, portanto, foi adicionado o operador logo após a declaração dos tipos e no nome das variáveis. Esse operador também pode ser “acorrentado”, para ir conferindo se todas as variáveis são diferentes de nulas, por exemplo:

```kotlin
pessoa.companhia?.endereco?.pais
```



## Operador Elvis

Esse operador tem o objetivo de definir um valor caso seja encontrado como nulo. Portanto, se uma variável for nula, usando o operador Elvis será atribuído o valor que foi colocado no código.

<mark style="color:orange;">**Ainda é necessário**</mark> colocar todos os operadores (interrogação) nas variáveis para conferir se é nulo para o código funcionar. Veja o exemplo abaixo:

<figure><img src="../../../.gitbook/assets/operador Elvis.png" alt=""><figcaption></figcaption></figure>

No projeto, pude substituir uma lógica que ficava repetidamente verificando se o resultado é nulo. Se fosse e eu substituísse por zero, a lógica funcionaria normal. Para isso, pude usar esse operador. Veja como fiz:

#### Lógica antiga: conferindo se totalDeArmarios era nulo

```kotlin
// Resgata um valor desconhecido do banco de dados Firebase
val totalDeArmarios = document.getDouble("totalArmarios")?.toInt()
var armarioEncontrado : String = "nenhum"
var posicaoArmario : String = "String"
var statusArmarioAtual : Boolean?

// Verificar armário por armário qual está vazio
if (totalDeArmarios != null) {
    for (i in 0 until totalDeArmarios) { // Usa a variável totalDeArmarios
        posicaoArmario = "A$i"
        statusArmarioAtual = document.getBoolean(posicaoArmario)

        if (statusArmarioAtual == false) {
            armarioEncontrado = posicaoArmario
            break
        }
    }
} else {
    Log.d(TAG, "Nenhum valor encontrado")
}
```

#### Nova lógica: atribui o valor zero caso seja nulo

```kotlin
// Resgata um valor desconhecido do banco de dados Firebase
val totalDeArmarios = document.getDouble("totalArmarios")?.toInt() ?: 0 // Elvis
var armarioEncontrado : String = "nenhum"
var posicaoArmario : String = "String"
var statusArmarioAtual : Boolean?

// Verificar armário por armário qual está vazio
for (i in 0 until totalDeArmarios) { // Usa a variável totalDeArmarios
    posicaoArmario = "A$i"
    statusArmarioAtual = document.getBoolean(posicaoArmario)

    if (statusArmarioAtual == false) {
        armarioEncontrado = posicaoArmario
        break
    }
}
```

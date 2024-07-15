# Firebase

## Encontrar um documento e resgatar valores

Podemos saber ou não qual documento queremos procurar

### Procurar usando condições (whereEqualTo)

Baseado que está em uma chave dentro de um documento. Nesse caso, vai resgatar <mark style="color:orange;">**todo o documento**</mark> cuja a chave <mark style="color:red;">`nomeDaChave`</mark> tenha o <mark style="color:blue;">**valor igual**</mark> da variável <mark style="color:red;">`valorDaChaveProcurada`</mark>. Basicamente é uma varredura até encontrar.

Então lembrar de definir a coleção que vamos entrar, o nome da chave e o valor dessa chave procurada. O retorno será o documento inteiro e podemos usar qualquer dado desse documento.

```kotlin
val nomeDaColecao = Firebase.firestore.collection("minhaColecao")
val valorDaChaveProcurada = "Procurar por isso"

nomeDaColecao
    .whereEqualTo("nomeDaChave", valorDaChaveProcurada)
    .get()
    .addOnSuccessListener { documents ->
        for (document in documents) {
            val dadosDoFirebase = document.data
            val valorEncontrado = dadosDoFirebase["armario"].toString()
            Log.i("Firebase", "Documento encontrado! ${document.id}")
        }
    }
    .addOnFailureListener {
        Log.e("Firebase", "Nenhum documento encontrado.")
    }
```

### Sabemos exatamente o documento

Nesse caso, não precisamos de uma condição para encontrar o documento e podemos ir direto, fazendo:

```kotlin
private val db = Firebase.firestore

val docRef = db.collection("minhaColecao").document("esseDoc")

docRef.get()
    .addOnSuccessListener { document ->
        // Podemos usar as condições document != null && document.exists()
        val dadosDoFirebase = document.data
        val valorEncontrado = dadosDoFirebase["armario"].toString()
        Log.i("Firebase", "Documento encontrado! ${document.id}")
    }
    .addOnFailureListener {
        Log.e("Firebase", "Nenhum documento encontrado.")
    }
```

## Alterar dados de documento

Primeiro definimos os campos e as mudanças de cada chave/valor em uma variável, no caso citada como <mark style="color:red;">**updates**</mark>. Depois usamos o método <mark style="color:purple;">`set()`</mark> e está pronto. Os Listeners são algo a mais e não necessários.

Aqui precisamos definir exatamente o que estamos alterando, ou seja, o documento e em qual coleção ele está.

```kotlin
// Define as mudanças no campo do Firebase
val updates = hashMapOf<String, Any>(
    "chaveParaAlterar" to true
)

val docRef = db.collection("minhaColecao").document("meuDocumento")
docRef.set(updates, SetOptions.merge())
    .addOnSuccessListener {
        // Fazer algo a mais (ou não) se sucesso
    }
    .addOnFailureListener { exception ->
        // Fazer algo (ou não) se falha
    }
```

## Criar novo documento

Primeiro definimos os campos e as mudanças de cada chave/valor em uma variável, no caso citada como <mark style="color:red;">**updates**</mark>. Depois usamos o método <mark style="color:purple;">`add()`</mark> e está pronto. Os Listeners são algo a mais e não necessários.

Aqui um documento com um nome aleatório será adicionado em <mark style="color:blue;">**minhaColecao**</mark>. O nome não é bom ser alterado por nós.

```kotlin
// Praticamente preparando um documento. Na direita, são variáveis que
// foram definidas anteriormente
val dadosLocacao = hashMapOf<String, Any>(
    "unidade" to nomeUnidadePascoalCase,
    "armario" to 15,
    "tempoUso" to itemSelecionadoNoSpinner,
    "nomeCliente" to nomeUsuario,
    "inicioLocacao" to dataInicio,
    "fimLocacao" to dataFim,
    "status" to "pendente"
)

db.collection("minhaColecao").add(dadosLocacao)
```

## Documento de um usuário autenticado

Usando essa linha de código temos o ID do usuário:

```kotlin
val userId = FirebaseAuth.getInstance().currentUser!!.uid
```

Assim, podemos usar a variável userId nos códigos para procurar documentos:

```kotlin
db.collection("locação").document(userId)
    .get()
    .addOnSuccessListener { document ->
        // Aqui estamos dentro do documento do usuário
        val nomeCliente = document.getString("nomeCliente")!!
    }
```

Como estamos dentro do documento do usuário, podemos resgatar o que quiser (que esteja salvo lá), como seu nome, idade, etc.

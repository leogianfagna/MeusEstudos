# Firebase

## Usar o Firebase Firestorm

No site do Firebase, existe a categoria do banco de dados, que é o Firebase Firestorm. Por lá, você pode provisionar um banco de dados e escolher a localização dele. O caminho para o site está [aqui](https://console.firebase.google.com/u/4/project/estudodirigidocontas-5a6a9/firestore/databases/-default-/data/\~2F).

Para utilizá-lo, é necessário ajustar os provedores do Authentication (serviço que fornece uma maneira simples e fácil de adicionar autenticação em seus aplicativos móveis e da web). No caso de estudos, foi adicionado dois tipos de provedores:

<figure><img src="../../.gitbook/assets/provedores do firebase.png" alt=""><figcaption><p>Adicionado provedor por e-mail/senha e outro por modo anônimo</p></figcaption></figure>



## Adicionar o Firebase Firestore e Auth no projeto

A utilização do Firebase Firestorm começa com esses passos:

1. Criar um projeto no Firebase
2. Registrar um aplicativo no projeto: irá adicionar um aplicativo informando o pacote do projeto
   1. Ir na engrenagem do projeto ![](<../../.gitbook/assets/botao Firebase visao geral.png>)
   2. Clique em configurações do projeto
   3. Finalmente, mais abaixo, encontrará a opção para adicionar aplicativo ![](<../../.gitbook/assets/botao Firebase adicionar app.png>)
3. Adicionar o arquivo de configuração
   1. Baixá-lo na mesma página anterior, onde adicionou o app. O download estará logo abaixo ![](<../../.gitbook/assets/botao Firebase baixar google services.png>)
   2. Mover esse arquivo para o diretório raíz do projeto no Android Studio ![](<../../.gitbook/assets/locao instalação google services.png>)
4. Permitir que os SDKs do Firebase acessem os valores no seu arquivo de configuração
   1. Adicionar a dependência do google na lista de plugins no arquivo build.gradle.kt (nível raíz, esse arquivo está no primeiro diretório do projeto)
   2. Adicionar o plugin de serviços no arquivo Gradle, mas agora, o que está no módulo app (diretório do projeto\app)
   3. Adicionar as dependências dos produtos do Firebase também no Gradle do nível raíz

```kotlin
// Todas as linhas dentro das chaves quer dizer que devem ser adicionadas

// Gradle do nível raíz
plugins {
  id("com.google.gms.google-services") version "4.3.15" apply false
}

// Gradle do nível do app
plugins {
  id("com.google.gms.google-services")
}

dependencies {
  implementation(platform("com.google.firebase:firebase-bom:32.3.1"))
  implementation("com.google.firebase:firebase-analytics-ktx")
  implementation("com.google.firebase:firebase-auth-ktx")
  implementation("com.google.firebase:firebase-firestore-ktx")
}
```

5. Depois basta sincronizar que uma build será feita e todas as dependências instaladas

<mark style="color:green;">Em resumo</mark>, a implementação no projeto ocorre por adicionar o arquivo de configuração que faz sincronia com o projeto e database criado no site da Google e as dependências para que tudo funcione.



## Guardar documentos no Firebase

No código, para acessar o Firebase Firestorm é necessária uma instância que representa o banco. Vamos criar duas instâncias:

* <mark style="color:purple;">FireAuth</mark>: usado para operações de autenticação de usuários
* <mark style="color:purple;">Firestore</mark>: usada para interagir com o banco de dados Firestore

Abaixo vemos os exemplos, em que as instâncias foram criadas e já receberam seu tipo, assim herdando classes para usos. As instâncias devem ser preparadas em uma função para serem de fato usadas, que é o terceiro caso.

A implementação ocorre dessa forma:

#### Passo 1: Importando as dependências

```kotlin
import com.google.android.material.snackbar.Snackbar
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.ktx.auth
import com.google.firebase.firestore.FirebaseFirestore
import com.google.firebase.firestore.ktx.firestore
import com.google.firebase.ktx.Firebase
```

#### Passo 2: Instanciar com referência para o banco

Isso é feito na classe principal da activity, mas antes do método <mark style="color:purple;">`onCreate()`</mark>, assim tornando uma variável global (para todos os métodos).

```kotlin
private lateinit var fireAuth: FirebaseAuth
private lateinit var firestore: FirebaseFirestore
```

#### Passo 3: Preparar as instâncias (invocar)

As instâncias recebem valores dos serviços do Firebase. Podem estar em uma função ou não. Aqui, já estamos usando-as dentro do método <mark style="color:purple;">`onCreate()`</mark>.&#x20;

```kotlin
private fun instantiateFirebaseObjects(){
    fireAuth = firebase.auth
    firestore = firebase.firestore
}
```

#### Passo 4: Inserir dados no banco de dados

```kotlin
var account = ...

firestore.collection("users").add(account)
    .addOnSuccessListener {
        // Operações se sucesso
    }
    .addOnFailureListener {
        // Operações se falha
    }
```

Usando o método “add” nesse exemplo, será enviado ao banco de dados informações em uma coleção chamada “users”, no caso, o objeto ou o valor que pertence à variável “account”.

O banco de dados Firestore é um banco NoSQL. Portanto, é baseado em coleções e documentos. Os identificadores dos documentos inseridos no banco de dados são feitos pelo próprio banco usando critérios performáticos, eles “ids” não são feitos para mudar (em apenas casos especiais).



## Resgatar documentos do Firebase

Dependendo da funcionalidade que procura, você pode resgatar apenas um documento ou uma coleção. Vejas nas duas possibilidades abaixo.

### Resgatar um documento em específico

Nesse exemplo, estaremos resgatando um documento chamado <mark style="color:blue;">campinas</mark> que está na coleção chamada <mark style="color:blue;">cidades</mark>.

```kotlin
val docRef = db.collection("cidades").document("campinas")

docRef.get()
    .addOnSuccessListener { document ->
        // Os dados serão recebidos em uma variável que pode ser acessada com
        // >>> document.data <<<
        
        // Aqui, uma lógica de confirmar se o documento resgatado é nulo é válida
        // Por exemplo:
        if (document != null) {
            Log.d(TAG, "DocumentSnapshot data: ${document.data}")
        } else {
            Log.d(TAG, "Documento inexistente")
        }
    }
    .addOnFailureListener { exception ->
        Log.d(TAG, "get failed with ", exception)
    }
```



### Resgatar todos os documentos de uma coleção

A diferença aqui é que temos apenas uma coleção e vários documentos, portanto, é implementado uma lógica for para passar entre os documentos e resgatá-los. Nessa forma, podemos tanto resgatar todos os documentos de uma coleção quando criar um filtro e resgatar somente aqueles condizentes, por exemplo:

```kotlin
db.collection("Cidades")
    .WhereEqualTo("capital", true) // Caso queira implementar um filtro
    .get()
    .addOnSuccesListener { documents ->
        // Lógica For para cada documento
        for (document in documents) {
            Log.d(TAG, "${document.id} => ${document.data}")
        }
            
    }
    .addOnFailureListener {
        Log.w(TAG, "Error getting documents: ", exception)
    }
```

{% hint style="info" %}
Lembrando que <mark style="color:red;">`->`</mark> simboliza uma expressão Lambda (blocos de código que podem ser passados como argumentos para funções de ordem superior. Sua sintaxe é:



`{ argumentos -> corpo da expressão }`
{% endhint %}

## Firebase Auth

Firebase Authentication fornece serviços de back-end, SDKs fáceis de usar e bibliotecas de IU prontas para autenticar usuários no seu aplicativo. Ele funciona coletando credenciais e passando-as para o SDK do Firebase Authentication. Os serviços de back-end verificarão essas credenciais e retornarão uma resposta ao cliente.

A utilização se inicia da mesma forma que o Firebase: importar bibliotecas, instanciar uma nova variável do tipo FirebaseAuth e preparar as instâncias, além de incluir no **Gradle** os serviços do Google e as dependências para o projeto. Portanto, ao usar o Firebase, tanto uma quanto outra opção, deverá fazer o mesmo processo descrito aqui.

### Verificar estado atual da autenticação

A verificação ocorre durante o método onStart(), diferentemente no método que era usado para tudo até então. A verificação ocorre dessa forma:

```kotlin
public override fun onStart() {
    super.onStart()
    
    // Confere se está nulo
    val currentUser = auth.currentUser
    if (currentUser != null) {
        reload() // Atualiza a página
    }
}
```

### Criar novos usuários

Usando um método chamado <mark style="color:purple;">`createAccount`</mark> que inclua um e-mail e senha. Para usá-lo, basta criar um input para receber os dados de email e senha do usuário e depois de preenchido, chamar esse método quando o documento for enviado.

```kotlin
auth.createUserWithEmailAndPassword(email, password)
    .addOnCompleteListener(this) { task ->
        if (task.isSuccesful) {
            // Atualiza a UI com as informações do usuário
            Log.d(TAG, "createUserWithEmail:success")
            val user = auth.currentUser
            updateUI(user)
        } else {
            // Exibir mensagem
            Log.w(TAG, "createUserWithEmail:failure", task.exception)
            Toast.makeText(
                baseContext,
                "Authentication failed.",
                Toast.LENGTH_SHORT,
            ).show()
            updateUI(null)
        }
    }
```

#### <mark style="color:orange;">Importante</mark>: novos métodos addOnCompleteListener e addOnFailureListener

É um método especial para lidar com operações e falhas. A grande vantagem desse método é que ele possui um objeto do tipo <mark style="color:blue;">task</mark> que é passado como parâmetro onde foi possível verificar se a operação foi bem sucedida com o método <mark style="color:purple;">isSuccesful</mark>.&#x20;

O método do Failure é a mesma lógica, usando-o para conseguir manipular linhas de código em caso de falha. Anteriormente vimos <mark style="color:purple;">addOnSuccessListener</mark> para implementações no banco de dados, o que é parecido. Neste caso, não usamos esse método pois ele não fornece o parâmetro task. Sendo assim, suas manipulações de falha ou sucesso eram feitas de formas diferentes.

### Logar usuários

Usando um método chamado <mark style="color:purple;">`signIn`</mark>que inclua um e-mail e senha. Para usá-lo, basta criar um input para receber os dados de email e senha do usuário e depois de preenchido, chamar esse método quando o documento for enviado.

```kotlin
auth.signInWithEmailAndPassword(email, password)
    .addOnCompleteListener(this) { task ->
        if (task.isSuccesful) {
            // Atualizar página com dados do usuário autenticado
            Log.d(TAG, "signInWithEmail:success")
            val user = auth.currentUser
            updateUI(user)
        } else {
            // Mostrar mensagem
            Log.w(TAG, "signInWithEmail:failure", task.exception)
            Toast.makeText(
                baseContext,
                "Authentication failed.",
                Toast.LENGTH_SHORT,
            ).show()
            updateUI(null)
        }
    }
```

### Resgatar dados de usuários

Isso é possível se um usuário já estiver feito login. O método getCurrentUser permite resgatar dados a qualquer momento.

```kotlin
val user = Firebase.auth.currentUser
user?.let {
    val name = it.displayName
    val email = it.email
    val photoUrl = it.photoUrl

    // Checar se o email é verificado
    val emailVerified = it.isEmailVerified
}
```

## Email autenticado no Firebase Auth

Requerir um email autenticado simboliza enviar uma mensagem na caixa de correio do email do usuário para ele verificar e concluir seu cadastro por ali. Por exemplo, o famoso: "confirmar seu email na caixa de entrada".

Isso é feito pelo próprio Firebase Auth e serve para princípios de segurança, evitar abusos e até recuperação de senha, onde por lá mesmo é enviado o email para recuperar.

## Provedores do Firebase Auth

Os provedores do Firebase Authentication são serviços externos que você pode usar para permitir que os usuários autentiquem em seu aplicativo usando identidades fornecidas por esses serviços. O Firebase Authentication oferece suporte a vários provedores de identidade, que incluem celular, email e senha, plataformas (como Google, Github...).

A especificação de quais tipos de provedores podem ser utilizados acontece no painel do banco de dados. Ainda também há o provedor **anônimo**, que é usado em casos que a pessoa pode navegar em partes do aplicativo sem se logar.

<figure><img src="../../.gitbook/assets/provedores do Firebase.png" alt=""><figcaption></figcaption></figure>

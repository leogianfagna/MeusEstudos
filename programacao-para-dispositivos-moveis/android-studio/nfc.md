---
description: 'Near Field Communication: Comunicação por campo de proximidade.'
---

# NFC

## O que é?

É uma tecnologia que serve para transmissão de dados sem fio entre dispositivos próximos por meio de radiofrequência (uso em destaque para pagamentos, abrir catraca, entre outros). Como as ondas são de curto alcance, é necessário que os dispositivos estejam bem próximos.

* NFC Ativo: o dispositivo pode <mark style="color:green;">**enviar e receber dados**</mark> e tem fonte de alimentação própria
  * Celulares, tablets e máquinas de cartão
* NFC Passivo: o dispositivo não tem alimentação elétrica própria, mas conta com um chip que <mark style="color:green;">**transmite dados**</mark> apenas com o NFC ativo
  * Cartões de crédito, Cartões de transporte e tags NFC.

## Qual é a diferença entre NFC e RFID? <a href="#h-qual-e-a-diferenca-entre-nfc-e-rfid" id="h-qual-e-a-diferenca-entre-nfc-e-rfid"></a>

O NFC é um sub produto do RFID (Rádio Frequency Identitication). Ambas usam radiofrequência, mas o RFID permite que dois dispositivos se comuniquem com até 100 metros de distância, a exemplo dos sistemas de pedágio que conseguem identificar um veículo por meio de uma tag no para-brisa. Além disso, NFC é bidirecional onde pode receber e enviar dados e RFID só pode enviar.



## O que é NDEF (NFC Data Exchange Format)?

É uma estrutura leve usando um formato baseado em registros que permite a troca de dados entre dois dispositivos utilizando a tecnologia NFC. Essa estrutura é necessária para que ambos os dispositivos possam se entender.

Registros são unidade de informação independente que pode ser armazenada em um dispositivo NFC. Quando vários registros são armazenados juntos, eles formam uma mensagem NDEF. Uma mensagem NDEF pode ser considerada como um contêiner para um ou mais registros.

Ele pode armazenar qualquer tipo de dado, independente da complexidade. Isso também engloba o armazenamento de vários documentos. Os tipos registros em uma mensagem NDEF são:

* **Cabeçalho:** O cabeçalho contém informações sobre o tipo e o comprimento do registro.
* **Tipo:** O campo tipo indica o tipo de dados armazenados no registro.
* **ID:** O campo ID é usado para identificar um registro específico dentro de uma Mensagem NDEF.
* **Carga útil (único obrigatório):** O campo de carga útil contém os dados reais armazenados no registro.

Para levar como conceito, o formato NDEF não é obrigatório para ser usado. Contudo, se uma tag não possui dados formatados nesse padrão, o código precisa ter seu próprio algorítimo e lógica para conseguir lidar com os dados recebidos. Portanto, pode-se considerar que seu uso deve ser quase obrigatório.



## Funcionamento

A leitura dos de uma tag NFC (através dos registros NDEF visto acima) é processada com o <mark style="color:blue;">**sistema de expedição de etiquetas**</mark> (explicado a seguir), que analisa tags NFC encontradas, categoriza os dados de forma adequada e inicia uma activity interessada nos dados categorizados. Um aplicativo que queira processar a tag NFC lida pode <mark style="color:blue;">**declarar um filtro de intent**</mark> e solicitar o processamento dos dados.

O recurso <mark style="color:red;">**Android BeamTM**</mark> permite que um dispositivo envie uma mensagem NDEF para outro, tocando fisicamente os dispositivos juntos. Essa interação oferece uma maneira mais fácil de enviar dados do que outras tecnologias sem fio pois não é necessário parear os dispositivos. A conexão será iniciada automaticamente quando dois dispositivos entrarem ao alcance.

O Android Beam está disponível por meio de um conjunto de APIs NFC, de modo que qualquer app pode transmitir informações entre dispositivos (vários aplicativos como contatos, navegador e YouTube usam o Android Beam para compartilhar informações entre dispositivos).



## Implementação

Passo a passo de como implementar em um projeto.



### 1. Solicitar acesso a NFC no projeto

Um aplicativo possui suas permissões e para esse recurso funcionar, precisamos uma permissão e um recurso para utilizá-lo. Isso é feito no arquivo de manifesto.

Adicione essas linhas antes da tag \<application> e dentro da tag \<manifest>:

```xml
<uses-permission android:name="android.permission.NFC" />
<uses-feature android:name="android.hardware.nfc" android:required="true" />
```

### 2. Declarar as intenções de usar NFC

Ao criar uma nova activity, ela será declarada no arquivo de manifesto. As activitys podem receber um campo no manifesto que é o <mark style="color:orange;">`<intent_filter>`</mark>. Quando a activity é a principal/launcher, por padrão, já vem esse campo sinalizando essa característica.

Precisamos acrescentar os filtros desejados das intenções que queremos com a NFC nessa activity. Nesse caso em especial, vamos usar apenas a **TAG\_DISCOVERED**. Para isso, adicionar essa linha:

```xml
<intent-filter>
    <action android:name="android.intent.action.MAIN" />
    <category android:name="android.intent.category.LAUNCHER" />
    
    <!-- Adicionar essa linha -->
    <action android:name="android.nfc.action.TAG_DISCOVERED" />
</intent-filter>
```

### 3. Receber as informações dos intents

Agora vamos para o código em Kotlin. <mark style="color:purple;">**NfcAdapter**</mark> <mark style="color:blue;">**é uma classe**</mark> necessária para detectar tags NFC e realizar operações de escrita e leitura de dados. Ele atua como uma interface entre hardware NFC. Ele é necessário pois ele habilita/desabilita a comunicação NFC, registra os filtros e notificações.

Essa classe possui o método <mark style="color:purple;">**getDefaultAdapter()**</mark> que é usado para obter acesso do adaptador do dispositivo e interagir. Usar <mark style="color:blue;">`NfcAdapter.getDefaultAdapter(this)`</mark> verifica se o dispositivo suporta NFC e se está atividado, <mark style="color:orange;">**retornando uma instância associada ao dispositivo**</mark>. Então, criamos uma variável qualquer para receber essa instância e assim usar os dados recebidos nela.

Nesse caso, vamos criar uma instância chamada nfcAdapter (letra "n" em minúsculo) que recebe esse valor. Importante saber que pode receber nulo caso o dispositivo não está ativado e esse nulo deve ser verificado.

Para isso, no ciclo de vida onCreate() vamos obter essa referência, desta forma:

```kotlin
private var nfcAdapter: NfcAdapter? = null

override fun onCreate(savedInstanceState: Bundle?) {
    // ...
    
    nfcAdapter = NfcAdapter.getDefaultAdapter(this)
}
```

### 4. Identificar quando a tag é descoberta e enviar intents

Um <mark style="color:purple;">**PendingIntent**</mark>** **<mark style="color:blue;">**é uma classe**</mark> que suas instâncias <mark style="color:blue;">**retornam a intenção e o alvo**</mark> da ação para executar. As instâncias podem ser criadas utilizando qualquer um [desses métodos](https://developer.android.com/reference/android/app/PendingIntent) que retornam um objeto com as descrições das execuções, que essas execuções podem ser feitas por outras aplicações.

Seu objetivo principal é identificar quando uma tag é descoberta e iniciar a atividade correspondente.

```kotlin
private var pendingIntent: PendingIntent? = null

override fun onCreate(savedInstanceState: Bundle?) {
    // ...
    
    pendingIntent = PendingIntent.getActivity(
        this, 
        0, 
        Intent(this, javaClass).addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP),
        PendingIntent.FLAG_IMMUTABLE
    )
}

// Esse método possui essa estrutura: getActivity(Context, int, Intent, int)
```



### 5. Filtrar as intenções relacionadas à descoberta anterior

Registrar os filtros é uma prática comum para informar o aplicativo/sistema quais tipos de ações nossa activity vai lidar e ter mais controle. Esse registro acontece usando alguns tipos de eventos:

* ACTION\_NDEF\_DISCOVERED: É o mais seguro para se utilizar. Verificar apenas se a tag foi descoberta pode ser muito abrangente. Esse tipo de intent vai servir já para verificar se há documentos no tipo NDEF, facilitando muito as coisas e deixando mais seguro.
* ACTION\_TECH\_DISCOVERED
* ACTION\_TAG\_DISCOVERED

Essas constantes são definidas dentro da classe <mark style="color:purple;">**NfcAdapter**</mark>, portanto, nós chamamos elas através dessa classe, por exemplo (<mark style="color:orange;">`NfcAdapter.ACTION_TAG_DISCOVERED`</mark>).

Acima falamos dos intent-filters na linguagem XML, mas em Kotlin, temos a <mark style="color:blue;">**classe**</mark> chamada <mark style="color:purple;">**IntentFilter**</mark>. Essa classe por si só define os critérios que uma intenção deve atender, então, ela será usada para <mark style="color:green;">**filtrar as intenções**</mark>.

Fazendo na prática, criaremos uma variável ndefFilter que é do tipo IntentFilter que vai receber os filtros e intenções, desta forma:

```kotlin
private var ndefFilter: IntentFilter? = null

override fun onCreate(savedInstanceState: Bundle?) {
    // ...
    
    ndefFilter = IntentFilter(NfcAdapter.ACTION_NDEF_DISCOVERED)
}

// Lembrando que NfcAdapter recebeu o valor recebido da tag NFC (dispositivo)
```



### 6. Registrar os filtros da etapa anterior

Registrar os filtros servem para <mark style="color:green;">**configurar as condições**</mark> nas quais o método <mark style="color:purple;">`onNewIntent()`</mark> será chamado. Esse método é chamado pelo sistema na detecção de uma nova intenção, o que será usado no próximo passo para manipular os dados. Para isso, logo abaixo vamos fazer da seguinte maneira:

```kotlin
val filtros = arrayOf(ndefFilter)
val techLists = arrayOf(arrayOf(Ndef::class.java.name))

nfcAdapter?.enableForegroundDispatch(this, pendingIntent, filters, techLists)
```

A variável no exemplo anterior <mark style="color:purple;">**ndefFilter**</mark> recebeu as inteções das tags NDEF que agora passou em forma de array para a variável <mark style="color:purple;">**filtros**</mark>. A variável techLists é criada dessa forma para simbolizar que queremos trabalhar com tags de tecnologia NDEF.

Com isso, podemos fazer a linha a seguir, que possui um método muito importante. A chamada <mark style="color:purple;">`enableForegroundDispatch()`</mark> é usada para <mark style="color:blue;">**registrar os filtros de intenção e o PendinIntent**</mark> utilizando a variável <mark style="color:orange;">**nfcAdapter**</mark>, permitindo que a atividade intercepte intenções de tags NFC descobertas enquanto está em primeiro plano. Em outras palavras, configurando as condições conforme foi dito acima.

### 7. Lidar com as tags encontradas

Isso ocorre através da chamada do passo anterior onNewIntent(). A obtenção de dados da tag pode ser feito da seguinte forma:

```kotlin
intent.getParcelableArrayExtra(NfcAdapter.EXTRA_NDEF_MESSAGES)
```

Essa função por inteiro podemos definir em nosso código da seguinte forma:

```kotlin
override fun onNewIntent(intent: Intent?) {
    super.onNewIntent(intent)

    if (NfcAdapter.ACTION_NDEF_DISCOVERED == intent?.action) {
        intent.getParcelableArrayExtra(NfcAdapter.EXTRA_NDEF_MESSAGES)?.also { rawMessages ->
            val dadosMensagens: List<NdefMessage> = rawMessages.map { it as NdefMessage }

            // Finalmente: Manipulação de dados!
            var i: List<NdefMessage> = dadosMensagens
        }
    }
}
```

Vemos dentro dessa função que é passado uma variável <mark style="color:purple;">**intent**</mark> que é utilizada várias vezes e é essencial para resgatar as informações. Ela vem através dos registros que foram feitos anteriormente com <mark style="color:purple;">`enableForegroundDispatch()`</mark>. Como dito anteriormente, preparou-se as configurações nos registros.



### 8. Desresgistrar os filtros

Esses filtros registrados no passo 6 devem ser desregistrados em algum ciclo de vida de encerramento  (pause ou destroy). Para isso, é só usar o método contrário, funcionando desta forma:

```kotlin
override fun onPause() {
    super.onPause()
    nfcAdapter?.disableForegroundDispatch(this)
}
```


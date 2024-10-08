# Bluetooth

## Explicação

Nada mais é que um hardware de comunicação por radio frequência. Toda placa física de comunicação tem um endereço MAC, que esse endereço é único no mundo.

Procurar dispositivos com Bluetooth usam o SCANNER, que ele faz um processo chamado Broadcast, que é uma comunicação pública onde manda um sinal de rápido para ser captado e respondido por todos os dispositivos próximos para saber quem está presente.

Quando uma conexão é estabelecida com um hardware, o processo de scan é interrompido. Uma vez conectado, existem os módulos de troca de informação entre os hardwares. São exemplos de métodos de comunicação:

* Unilateral: um fone de ouvido, só recebe os dados para reproduzir música
* Bilateral: um headset, recebe os dados de som e envia o som captado pelo microfone

O bluetooth está ligado a um conversor digital no hardware que está instalado. Quando um bluetooth recebe um sinal digital, esse conversor converte para um sinal analógico. Uma curiosidade é que esse processo de conversão e até o sinal analógico mesmo perde alguns dados, então por engenharia é impossível algo que utilize bluetooth ser melhor que fio pois a perda de sinal é inevitável.

<figure><img src="../../../.gitbook/assets/comunicacoes bluetooth android.png" alt=""><figcaption></figcaption></figure>

## Bluetooth Manager

Uma aplicação não pode ligar/desligar bluetooth por motivos de segurança, apenas o próprio usuário pode fazer isso. Cada activity do Android possui e pode invocar o método <mark style="color:purple;">`getSystemServices()`</mark> passando uma constante chamada <mark style="color:red;">`BLUETOOTH.SERVICES`</mark> que responderá com uma instância da classe BluetoothManager.

Por meio dessa instância da classe BluetoothManager, teremos acesso a uma propriedade da instância <mark style="color:red;">**bm.adapter**</mark> que vai responder com o hardware de Bluetooth do celular que possui funções para escanear outros dispositivos.

Parear dispositivos tecnicamente falando, traduzimos para "mandei meu adapter se conectar com um BluetoothDevice".

Os devices possuem canais de áudio que são os caminhos de onde estão vindo os áudios, por exemplo, do aplicativo A, B, da rádio, etc. A existência do Mixer serve para controlar esses canais, por exemplo, em alguns dispositivos quando estamos ouvindo uma música e começamos a ouvir um áudio no Whatsapp, o mixer diminui o volume da música e aumenta do áudio. A inexistência de canais ou de mixer vai fazer com que um interrompa o outro.

## Permissões

O uso do Bluetooth requer que uma quantia de permissões seja declarada no arquivo de manifesto para funcionar:

```xml
<!-- Permite que aplicativos descubram e emparelhem dispositivos Bluetooth -->
<uses-permission android:name="android.permission.BLUETOOTH_ADMIN" />

<!-- Permite que aplicativos se conectem a dispositivos Bluetooth emparelhados -->
<uses-permission android:name="android.permission.BLUETOOTH" />
<uses-permission android:name="android.permission.FOREGROUND_SERVICE" />

<!--
    Essa permissão é necessária para escanear dispositivos próximos nas versões
    Android entre N e R
-->
<uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" />

<uses-permission android:name="android.permission.BLUETOOTH_ADVERTISE" />
<uses-permission android:name="android.permission.BLUETOOTH_CONNECT" />
<uses-permission android:name="android.permission.BLUETOOTH_SCAN" />
```

## Classes

Todas as classes estão disponíveis no pacote android.bluetooth.

### BluetoothAdapter

<mark style="color:blue;">**Nosso dispositivo é representado**</mark> por essa classe. Essa classe é o ponto de entrada para qualquer interação bluetooth:

* Descobrir dispositivos
* Consultar dispositivos pareados
* Instanciar um `BluetoothDevice` usando um endereço MAC
* Criar um BluetoothServerSocket para ouvir comunicações de outros dispositivos

### BluetoothDevice

Essa classe <mark style="color:blue;">**representa um dispositivo remoto**</mark>, portanto, ela deve ser utilizada para fazer qualquer conexão com esse dispositivo (não é o nosso). Essa conexão pode ser consultar informações sobre o dispositivo ou solicitar uma conexão, o que vai exigir a classe BluetoothSocket.

### BluetoothSocket

Socket (ou soquete, que pode ser traduzido para um ponto de comunicação), é um canal de comunicação que dispõe de entrada e saída. Podemos imaginar como um cano conectado entre os dispositivos emparelhados onde, dentro desse cano possui outros dois canos: o INPUT e o OUTPUT. Um dispositivo fornece dados no OUTPUT que o outro dispositivo receberá no INPUT e vice-versa, trocando informações.

Em termos de código, representa a <mark style="color:blue;">**interface de um soquete Bluetooth**</mark>, como já foi dito acima, com InputStream (o que recebe) e OutputStream (o que envia). É ele que permite a troca de dados entre dispositivos.

<figure><img src="../../../.gitbook/assets/bluetooth socket 1.png" alt=""><figcaption></figcaption></figure>

### BluetoothServerSocket

Para conectar dois dispositivos, um deles precisa <mark style="color:blue;">**abrir um soquete de servidor com essa classe**</mark>. Quando um dispositivo remoto Bluetooth faz uma solicitação de conexão, ele aceita a conexão e retorna um objeto do tipo <mark style="color:red;">**BluetoothSocket**</mark> conectado.

### BluetoothClass

É usada para <mark style="color:blue;">**descrever as características**</mark> de um dispositivo Bluetooth remoto.&#x20;

```kotlin
return when (bluetoothClass.deviceClass) {
    BluetoothClass.Device.PHONE_SMART -> "Smartphone"
    BluetoothClass.Device.COMPUTER_LAPTOP -> "Laptop"
    BluetoothClass.Device.AUDIO_VIDEO_HEADPHONES -> "Headphones"
    BluetoothClass.Device.WEARABLE_WRIST_WATCH -> "Wrist Watch"
    else -> "Unknown"
}
```

### Outras classes

* **BluetoothProfile**: É usada para representar um perfil Bluetooth específico, como o perfil A2DP, HFP ou HID. Esses perfis representam diferentes tipos de funcionalidades que os dispositivos Bluetooth podem suportar
* **BluetoothHeadset**: Oferece suporte para fones de ouvido via Bluetooth
* **BluetoothA2dp**: Define como fazer streaming de áudio de alta qualidade de um dispositivo para outro por uma conexão Bluetooth usando o **BluetoothProfile** A2DP (significa distribuição de áudio avançada)
* **BluetoothHealth**: Representa um proxy do perfil do Health Device que controla o serviço do Bluetooth
* **BluetoothHealthCallBack**: É uma classe usada para extender a classe **BluetoothHealth** e conseguir obter callbacks, que serão atualizações sobre mudanças no estado de registro do app e no estado do canal Bluetooth
* **BluetoothHealthAppConfiguration**: Representa uma configuração de app que o app de saúde do Bluetooth registra para se comunicar com um dispositivo de saúde remoto do Bluetooth
* **BluetoothProfile.ServerListener**: Uma interface que notifica os clientes de comunicação entre processos da classe **BluetoothProfile** quando eles são conectados ou desconectados do serviço interno que executa um perfil específico.

## Código

### RequireContext

Os fragmentos não possuem os elementos de uma activity, por isso que dentro de um fragmento não podemos utilizar:

```kotlin
val i = Intent(this, LoginActivity::class.java)
// Resultado = erro
```

Irá resultar erro pois o <mark style="color:red;">**this**</mark> não é um elemento que simboliza uma activity no fragmento. Por conta disso, utilizamos o método <mark style="color:purple;">`requireContext()`</mark> para executar algo na activity a partir de um fragmento.

### Inicialize

Essa função prepara os objetos para o broadcast. Ele usa um RecyclerView para mostrar todos os objetos encontrados com Bluetooth. Um callback é uma resposta.

### BluetoothLeScanner

Possui a referência do Bluetooth do dispositivo atual, o celular em que está o aplicativo.

### Handler

É um objeto que executa um outro bloco de código de forma agendada em uma outra thread segura, que não é a principal (UI).


# Bluetooth

Nada mais é que um hardware de comunicação por radio frequência. Toda placa física de comunicação tem um endereço MAC, que esse endereço é único no mundo.

Procurar dispositivos com Bluetooth usam o SCANNER, que ele faz um processo chamado Broadcast, que é uma comunicação pública onde manda um sinal de rápido para ser captado e respondido por todos os dispositivos próximos para saber quem está presente.

Quando uma conexão é estabelecida com um hardware, o processo de scan é interrompido. Uma vez conectado, existem os módulos de troca de informação entre os hardwares. São exemplos de métodos de comunicação:

* Unilateral: um fone de ouvido, só recebe os dados para reproduzir música
* Bilateral: um headset, recebe os dados de som e envia o som captado pelo microfone

O bluetooth está ligado a um conversor digital no hardware que está instalado. Quando um bluetooth recebe um sinal digital, esse conversor converte para um sinal analógico. Uma curiosidade é que esse processo de conversão e até o sinal analógico mesmo perde alguns dados, então por engenharia é impossível algo que utilize bluetooth ser melhor que fio pois a perda de sinal é inevitável.

<figure><img src="../../../.gitbook/assets/image (15).png" alt=""><figcaption></figcaption></figure>

## Bluetooth Manager

Uma aplicação não pode ligar/desligar bluetooth por motivos de segurança, apenas o próprio usuário pode fazer isso. Cada activity do Android possui e pode invocar o método <mark style="color:purple;">`getSystemServices()`</mark> passando uma constante chamada <mark style="color:red;">`BLUETOOTH.SERVICES`</mark> que responderá com uma instância da classe BluetoothManager.

Por meio dessa instância da classe BluetoothManager, teremos acesso a uma propriedade da instância <mark style="color:red;">**bm.adapter**</mark> que vai responder com o hardware de Bluetooth do celular que possui funções para escanear outros dispositivos.

Parear dispositivos tecnicamente falando, traduzimos para "mandei meu adapter se conectar com um BluetoothDevice".

Os devices possuem canais de áudio que são os caminhos de onde estão vindo os áudios, por exemplo, do aplicativo A, B, da rádio, etc. A existência do Mixer serve para controlar esses canais, por exemplo, em alguns dispositivos quando estamos ouvindo uma música e começamos a ouvir um áudio no Whatsapp, o mixer diminui o volume da música e aumenta do áudio. A inexistência de canais ou de mixer vai fazer com que um interrompa o outro.

### Socket

É um canal de comunicação que dispõe de entrada e saída. Podemos imaginar como um cano conectado entre os dispositivos emparelhados onde, dentro desse cano possui outros dois canos: o INPUT e o OUTPUT. Um dispositivo fornece dados no OUTPUT que o outro dispositivo receberá no INPUT e vice-versa, trocando informações.



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



## Prova

<mark style="background-color:red;">o que ler para a prova: Bluetooth Overview, vai ter as classes chaves, que viemos em aula. Exemplo: a classe BluetoothDevice representa um dispositivo remoto e o seu dispositivo é representado pelo BluetoohAdapter )</mark>


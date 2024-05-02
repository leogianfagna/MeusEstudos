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



< parei em "[Como etiquetas NFC são mapeadas em tipos MIME e URIs](https://developer.android.com/develop/connectivity/nfc/nfc?hl=pt-br#tag-dispatch)">&#x20;




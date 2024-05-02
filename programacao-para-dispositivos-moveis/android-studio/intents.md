---
description: >-
  Documentação:
  https://developer.android.com/guide/components/intents-filters?hl=pt-br#kotlin
---

# Intents

## Definição

É um <mark style="color:blue;">**objeto de mensagens assíncronas**</mark> que pode ser usado para solicitar uma ação de outro componente (são activitys, serviços, provedores, etc). As intents facilitam a comunicação entre componentes de várias maneiras, mas existem três casos de uso fundamentais:

#### Iniciando activitys

Nesse caso, um <mark style="color:purple;">**Intent vai descrever a activity**</mark> a ser iniciada e carrega os dados necessários. Por exemplo:

```kotlin
val i = Intent(this, LoginActivity::class.java)

startActivity(i)
```

#### Iniciando serviços

Os serviços executam ações em segundo plano sem uma interface de usuário. Assim como foi dito nas activitys, o Intent nesse caso <mark style="color:green;">**vai descrever o serviço**</mark> a ser iniciado e seus dados necessários. A Intent que é um objeto de mensagens, também poderá ser usado para transmitir um serviço de um outro componente, isso porquê o componente poderá <mark style="color:purple;">**transmitir o objeto intent**</mark> usando métodos, no caso, <mark style="color:purple;">`bindService()`</mark>.

#### Transmitir uma transmissão

Elas são mensagens que qualquer aplicativo pode receber. Assim como as demais, o Intent pode servir para transmitir as mensagens para outras aplicações em formato de parâmetro. Neste caso específico, utilizando <mark style="color:purple;">`sendBroadcast()`</mark>.



## Tipos de intents

* Explícito: especificam um componente de qual aplicativo vai satisfazer a intent
* Implícito: não nomeiam um componente específico, mas declaram uma ação geral a ser executada que isso permite que um componente de um outro aplicativo possa processar (exemplo: mostrar um lugar no mapa, onde o Waze pode fazer isso). O uso desse caso faz com que o Android mesmo busque o componente adequado usando o <mark style="color:green;">**filtro de intents**</mark>

Os <mark style="color:green;">**Filtros de Intents**</mark> são expressão que estão nos outros aplicativos declarados no Manifest que simbolizam quais os tipos de intents que o aplicativo pode receber. Quando são executados, o sistema irá executar entregando o objeto Intent. Se o sistema encontrar mais de um que possa fazer, uma janela perguntando qual executar aparecerá para o usuário.

#### Exemplo de intent explícito

```kotlin
val downloadIntent = Intent(this, DownloadService::class.java).apply {
    data = Uri.parse(fileUrl)
}
startService(downloadIntent)
```

#### Exemplo de um intent implícito:

```kotlin
// Cria uma mensagem de texto a partir da string
val sendIntent = Intent().apply {
    action = Intent.ACTION_SEND
    putExtra(Intent.EXTRA_TEXT, textMessage)
    type = "text/plain"
}

// Tentativa de invocar o intent
try {
    startActivity(sendIntent)
} catch (e: ActivityNotFoundException) {
    // Algo caso não dê certo
}
```

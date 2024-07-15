---
description: https://developer.android.com/reference/android/Manifest.permission
---

# Permissões importantes

Adicionar permissões ocorre dentro do arquivo **AndroidManifest.xm**l. Para isso, basta adicionar as linhas de <mark style="color:orange;">`<uses-permissions>`</mark> dentro da tag <mark style="color:orange;">`<manifest>`</mark>, dessa forma:

```xml
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools">

    <!-- Adicionar permissões -->
    <uses-permission android:name="android.permission.INTERNET" />
    <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
    
    <!-- 
        ....
     -->
</manifest>
```

## ACCESS\_NETWORK\_STATE <a href="#access_network_state" id="access_network_state"></a>

Permissão feita para acessar o resultado da conexão da internet. Depois de declarado no manifest, podemos criar uma função que retornar true/false para testar o resultado do estado à internet:

```kotlin
private fun isNetworkAvailable(): Boolean {
    // Obter instância do serviço ConnectivityManager
    val connectivityManager = getSystemService(CONNECTIVITY_SERVICE) as ConnectivityManager
    
    // Obter a rede atualmente ativa no dispositivo, retorna um objeto do tipo Network
    val network = connectivityManager.activeNetwork
    
    // Retorna as capacidades da rede ativa, como a capacidade de acessar a internet
    val networkCapabilities = connectivityManager.getNetworkCapabilities(network)
    
    // Retorna true se networkCapabilities for diferente de nulo e a segunda parte for igual a TRUE (pode ser true ou false)
    return networkCapabilities != null && networkCapabilities.hasCapability(NetworkCapabilities.NET_CAPABILITY_INTERNET)
}
```

<mark style="color:purple;">`getSystemService`</mark> é uma função da classe Context do Android que é a principal classe de <mark style="color:blue;">**acesso a recursos e serviços**</mark> no Android, então ela está nativamente disponível. Alguns dos serviços disponíveis são: ConnectivityManager (usaremos agora), LocationManager, WindowManager. Usaremos essa função para obter uma instância do serviço ConnectivityManager.&#x20;

A função `isNetworkAvailable()` checa se o dispositivo está conectado à internet da seguinte forma: obtém o `ConnectivityManager`, verifica a rede ativa, obtém as capacidades dessa rede e verifica se a rede pode acessar a internet. A permissão `ACCESS_NETWORK_STATE` é necessária para que a aplicação possa acessar o estado das redes no dispositivo.

Lembrando que ela retorna TRUE ou FALSE, portanto, basta apenas usar o retorno dessa função para usar em uma activity, por exemplo:

```kotlin
btnTestar.setOnClickListener {
    
    if (isNetworkAvailable()) {
        Toast.makeText(this, "SIM!", Toast.LENGTH_LONG).show()
    }
}
```

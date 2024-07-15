# Fragments

Eles são componentes, parte de uma interface ou um comportamento que devem ser relacionados a uma activity. Eles são dependentes e não podem estar sozinhos. Os fragments são projetados para serem modulares e reutilizáveis, permitindo que a activity componha uma interface complexa a partir de várias partes menores.

Como um fragmento deve ser incorporado por uma activity, isso se dá através do <mark style="color:red;">**FragmentManager**</mark> da própria activity. Ele é a classe responsável por executar ações nos fragmentos do app, por exemplo, adicionar, remover ou substituir e adicioná-los à backstack.

Sobre o ciclo de vida, ele será afetado simultaneamente baseado no ciclo de vida da activity. Por exemplo, ao entrar no ciclo onCreate(), o fragment também passa pelos seus estados correspondentes (que pode variar e não são todos iguais).

Os fragmentos podem:

* Dividir a interface da activity em partes menores
* Serem reutilizados várias vezes ou em diferentes activitys
* Terem suas proporções de layouts facilmente ajustadas em diferentes tamanhos
* Navegação mais fácil através das transações de fragmentos



## Utilização

O fragmento precisa ser adicionado ao <mark style="color:red;">**FragmentManager**</mark> da activity para que ele possa participar do ciclo de vida dela. Todas as activitys possuem uma propriedade que é usada para gerenciar os fragmentos que é <mark style="color:orange;">**supportFragmentManager**</mark>.&#x20;

O método <mark style="color:purple;">`beginTransaction()`</mark> inicia uma transação de fragmento que é um conjunto de mudanças para aplicar à sua interface de usuário. Mesmo que os fragmentos não tenham nenhum impacto visual (não possuem um layout), ainda sim é necessário fazer isso para associá-los ao ciclo de vida e comunicar-se com a activity e assim poder funcionar.

```kotlin
val fragTransaction = supportFragmentManager.beginTransaction()
```

Essa variável vai guardar a referência à transação de fragmento em andamento. Depois de declará-la, praticamente já temos pronto o uso dos fragmentos.

Podemos preparar os fragmentos que vamos usar através dela e depois usar um método commit() que finaliza a transação e aplica todas as mudanças feitas. Veja em um exemplo completo onde vamos chamar na activity dois fragmentos: [AdvertiserFragment.kt](https://github.com/android/connectivity-samples/blob/main/BluetoothAdvertisementsKotlin/app/src/main/java/com/example/bluetoothadvertisements/AdvertiserFragment.kt) e [ScannerFragment.kt](https://github.com/android/connectivity-samples/blob/main/BluetoothAdvertisementsKotlin/app/src/main/java/com/example/bluetoothadvertisements/ScannerFragment.kt)

```kotlin
/**
 * Setup two Fragments in the Activity: one shows the list of nearby devices; one shows the
 * switch for advertising to nearby devices.
 */
private fun setupFragments() {
    // Obtém uma instância de FragmentTransaction a partir do FragmentManager da Activity
    val fragTransaction = supportFragmentManager.beginTransaction()
    
    // Substitui o fragmento no contêiner com o ID 'scanner_fragment_container' por uma nova instância de ScannerFragment
    fragTransaction.replace(R.id.scanner_fragment_container, ScannerFragment())
    
    // Substitui o fragmento no contêiner com o ID 'advertiser_fragment_container' por uma nova instância de AdvertiserFragment
    fragTransaction.replace(R.id.advertiser_fragment_container, AdvertiserFragment())
    
    // Confirma a transação, aplicando as mudanças
    fragTransaction.commit()
}
```

Esse é um exemplo no [código de Bluetooth](https://github.com/android/connectivity-samples/blob/main/BluetoothAdvertisementsKotlin/app/src/main/java/com/example/bluetoothadvertisements/MainActivity.kt).&#x20;

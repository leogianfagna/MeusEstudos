# Activitys

Representa uma <mark style="color:blue;">jornada funcional</mark>, um grande processo e uma tarefa que o usuário vai realizar. Essa activity será <mark style="color:green;">uma tela</mark> e ela possui duas partes/arquivos (podemos chamar de fragmentos): o código Kotlin e o layout em XML.

Uma Launch Activity quer dizer que ela é a primeira a ser executada. Isso quer dizer que ao criar uma Activity nessa opção, ela será executada logo ao abrir o aplicativo. Pode se usar um exemplo como o “login” para ser, em caso de aplicativos que o login é obrigatório.

Os fragmentos são partes dessa jornada, ou seja, um dos passos para realizar a atividade final. Eles possuem a lógica, ou seja, o arquivo com o código que escreve a comportamento. Já a parte visual fica em um arquivo de layout, encontrado em um diretório chamado “resources” (também podendo estar como “res”).

Esses arquivos layout estão em arquivos do tipo XML, que é uma linguagem de marcação, vindo do HTML. No exemplo da sala, para mudar o botão, ele faz uma referência a uma string que no caso está em outro arquivo. Isso porque ele se referência a uma string e você pode ter a mesma string em diferentes línguas. Assim, com vários arquivos strings você pode traduzir para diferentes línguas.



## Ciclo de vida da activity

Muitas coisas podem ocorrer durante um ciclo de vida da activity que, até algumas delas, não eram originalmente programadas para ocorrer, como receber uma ligação durante o uso do aplicativo. Os callbacks são métodos que podem ser utilizados para manipular as estações das activitys, podendo fornecer mais otimização no uso de memória, inibir um mal funcionamento e evitar falhas ou perdas de dados.

As navegações entre os estágios do ciclo de vida ocorrem através dos callbacks. Dependendo da complexidade do aplicativo e do objetivo, não é necessário implementar todos os callbacks e sim implementar aqueles necessários para seu aplicativo comporte-se da forma desejada.

<figure><img src="../../.gitbook/assets/image (7).png" alt=""><figcaption></figcaption></figure>



### Os métodos do ciclo de vida

* `onCreate()`: Este método é chamado quando a activity está sendo criada. É aqui que você normalmente configura a interface do usuário e realiza inicializações básicas, como a ligação de variáveis a elementos de interface do usuário. Ele executa a lógica básica da activity e é obrigatório sua implementação.
  *   Esse método recebe um parâmetro chamado `savedInstanceState`, que é um objeto do tipo Bundle que contém o estado salvo anteriormente da atividade

      <figure><img src="../../.gitbook/assets/image (1) (1) (1).png" alt=""><figcaption></figcaption></figure>
  * `setContentView` é a transmissão do XML para a activity
* `onStart()`: Este método é chamado quando a activity está prestes a se tornar visível para o usuário. Neste ponto, a activity ainda não está interativa para o usuário, mas em breve será. Ela dura pouco e já invoca o método de retornado.
* `onResume()`: Este método é chamado quando a activity está prestes a começar a interagir com o usuário, isso significa que ela veio para o primeiro plano. Esse estado se mantém até o usuário sair do aplicativo ou navegar para outra activity. Esse método interage de forma frequente com onPause(), já que ao parar a activity é esse método chamado e ao retomar, é do método pausado para o retomado que activity navega.
* `onPause()`: Este método é chamado quando a activity está prestes a entrar no <mark style="color:blue;">segundo plano</mark>. Isso pode acontecer, por exemplo, quando outra activity é iniciada ou quando a tela do dispositivo é desligada. Ela nem sempre quer dizer que essa activity será destruída. Ao entrar nesse método, você deve realizar operações de pausa, como <mark style="color:blue;">pausar animações</mark> ou <mark style="color:blue;">liberar recursos</mark> que não são mais necessários.
* `onStop()`: Este método é chamado quando a activity não está mais visível para o usuário. Ainda sim, a memória continua sendo armazenada. Esse método é excelente para incluir funções de salvamentos de dados que não puderam ser feitas em outros momentos. Lembrando que daqui, a inda pode seguir para uma reinicialização e prosseguir ao onResume().
* `onDestroy()`: Este método é chamado quando a activity está prestes a ser destruída e encerrada completamente. Isso pode acontecer quando o sistema está prestes a liberar recursos para outras aplicações ou quando a activity é finalizada explicitamente (muitas vezes ao chamar o método `fisish()`). Ela também pode ser chamada por motivos de mudanças de configurações no aparelho.&#x20;
  * Em vez de colocar lógica na activity para determinar por que ela está sendo destruída, use um objeto [`ViewModel`](https://developer.android.com/reference/androidx/lifecycle/ViewModel?hl=pt-br) para conter os dados de visualização relevantes para ela. Se a activity for recriada devido a uma mudança de configuração, a **ViewModel** não precisará fazer nada, já que será preservada e fornecida à próxima instância da activity. Se a activity não for recriada, a **ViewModel** terá o método [`onCleared()`](https://developer.android.com/reference/androidx/lifecycle/ViewModel?hl=pt-br#onCleared\(\)) chamado, em que pode limpar todos os dados necessários antes de ser destruídos. É possível distinguir entre esses dois cenários com o método [`isFinishing()`](https://developer.android.com/reference/android/app/Activity?hl=pt-br#isFinishing\(\)).

Se o sistema precisar liberar memória, ele usa esses métodos como ordem de prioridade para encontrar memória para liberar, sendo `onDestroy()` o mais prioritário.



## Dados salvos com instâncias

Se o sistema destruir a activity devido as restrições dele, como uma mudança de configuração ou pressão de memória, embora a instância `"Activity"` real tenha se perdido, o sistema vai lembrar que ela existia. Se o usuário tentar navegar de volta para a atividade, o sistema criará uma nova instância dela usando um conjunto de dados salvos que descrevem o estado da atividade quando ela foi destruída.

Os dados salvos que o sistema usa para restaurar o estado anterior são chamados de <mark style="color:blue;">estado da instância</mark>. Ele é uma coleção de pares de chave-valor armazenados em um objeto [`Bundle`](https://developer.android.com/reference/android/os/Bundle?hl=pt-br). Por padrão, o sistema usa o estado da instância **Bundle** para salvar informações sobre cada view no layout da atividade. Um exemplo de salvamento, é o valor inserido em um EditText.



## Iniciando uma activity a partir de outra

Sabendo que cada activity é uma tela, a troca de tela simboliza a troca de activity. A inicialização de uma nova a partir da outra se dá através do método <mark style="color:purple;">`startActivity()`</mark> passando um objeto **Intent**, que especifica a atividade ou a ação para iniciar. Esse objeto até pode conter uma série de informações necessárias para iniciar a nova activity.

Assim, o código ficaria desta forma:

```kotlin
val intent = Intent(this, SignInActivity::class.java)
startActivity(intent)
```

O método <mark style="color:purple;">`startActivityForResult()`</mark> é utilizado quando você precisa receber um resultado da finalização da activity para iniciar a outra.

{% hint style="info" %}
Depois ler mais sobre coordenação em [https://developer.android.com/guide/components/activities/activity-lifecycle?hl=pt-br#asem](https://developer.android.com/guide/components/activities/activity-lifecycle?hl=pt-br#asem)
{% endhint %}

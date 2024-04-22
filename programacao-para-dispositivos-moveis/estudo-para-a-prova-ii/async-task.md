# Async Task

O meu aplicativo é um processo e um processo possui uma série de threads (é uma linha de execução ou uma sequência de instruções que faz parte de um processo). Se um componente de um aplicativo for iniciado mas outro já está em operação, esse novo componente utilizará da mesma linha de execução.

Por padrão, todos os processos criados por você irão ser executados na mesma thread, mas você pode  definir diferentes thread através do <mark style="color:orange;">**manifesto**</mark>.&#x20;

## Como funciona a thread principal

O sistema operacional Android é multi threads. O Android possui uma thread principal chamada <mark style="color:blue;">UI thread</mark>. Quando um aplicativo é iniciado, o sistema operacional cria uma thread para ele. Essa thread principal que normalmente é a que interage com as views de layout, por isso chamaram de UI thread.

Essa thread só morre se, e somente se, encerrar o aplicativo da memória! Quem manda nessa thread é o sistema operacional e não o aplicativo, diferentemente como é nas demais. O sistema operacional mandar nessa thread significa que ele lança os [<mark style="color:purple;">**Intents**</mark> ](#user-content-fn-1)[^1]relacionada a essa thread.

A thread principal, como dito acima, precisa ficar mantendo a tela. Isso quer dizer que ela não pode parar para a tela não travar. Isso implica que, nessa thread, não podemos fazer: requisições de rede, leitura/escrita de arquivos ou acesso a banco de dados local diretamente. Outras ações como clicar em botões e esperar alguma resposta pode ainda deixar não otimizado.

Não podemos fazer isso pois, quando a linha de execução é bloqueada (esperando uma resposta), nenhum evento pode ser enviado, incluindo eventos de desenho. Para isso, esses processos devem estar em threads separadas.

## As threads safes

As APIs do Firebase do Android são <mark style="color:blue;">**thread safe**</mark>. Isso quer dizer que ele não interfere na thread de UI, ou seja, ele cria uma nova separada para não parar a principal. Imagina uma requisição, a thread principal não pode ficar esperando essa requisição concluir.

Uma classe criada como <mark style="color:purple;">**async task**</mark>, isso significa que ela é uma thread safe. Toda async task DEVE ser uma <mark style="color:purple;">**inner class**</mark>, pois a instância criada será gerada pela thread da sua activity. Imagina criar um processamento na tela principal e não é em uma classe dessa e quer trocar de tela. O que acontece? Isso gera falhas.&#x20;



## Kotlin Coroutines

Tanto Async Task quanto Kotlin Coroutines são mecanimos que permitem <mark style="color:purple;">**performar tarefas de forma assíncrona**</mark> no Android. Contudo, <mark style="color:blue;">**Async Task segue um modo de paralelismo**</mark> onde múltiplas tarefas são executadas em diferentes threads de forma simultânea gerando perda de potencial e recurso. Já <mark style="color:blue;">**Kotlin Coroutines permite que várias tarefas sejam executadas na mesma thread**</mark> usando um mecanimos leve e que não bloqueia o funcionamento esperando por resposta.

Basicamente, a execução usando Kotlin Coroutines funciona na <mark style="color:blue;">**forma suspendida**</mark> para que, caso uma thread seja atrasada, essa thread é feita para trabalhar nas demais tarefas. A suspenção resulta em não bloqueio e pode concluir a tarefa mais tarde.

Async Tasks e Handlers não estão desatualizados mas em termos de performance usando tarefas em segundo plano, existem opções muito superiores: thread pools e loaders.

Veja ambas definições para uma comparação final:

#### Definição de Async Task: <mark style="color:green;">tarefas em segundo plano</mark>

É um framework (conjunto de bibliotecas) do próprio Android que permite desenvolvedores executarem o código em segundo plano e atualizar a UI thread com os resultados.

#### Definição de Kotlin Courotines: <mark style="color:green;">processamento assíncrono</mark>

É uma biblioteca que lidera uma forma mais perfomática e poderosa de realizar tarefas de forma assíncrona executando na mesma thread ou em diferentes.



[^1]: Eles servem para mandar ordens para o sistema realizar cada activity. Traduzindo, como o nome mesmo diz, são intenções de realizar uma operação.

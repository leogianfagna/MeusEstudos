# Exercícios prova 1

#### 7) Um shell é uma aplicação de modo usuário utilizada para iniciar a execução, interativamente, de outros programas conforme solicitado pelo usuário. Para isso, o shell cria um novo processo e executa o novo programa dentro dele. Utilizando as chamadas de sistema e os padrões de chamada Linux estudados em aula, esboce um código em C para fazer a tarefa do shell de iniciar um novo programa. Você pode assumir que existe uma função de biblioteca GetPgmInfo() que devolve todas as informações necessárias sobre o programa solicitado pelo usuário já no formato necessário exigido pela chamada de sistema adequada.

> Código em C para criação de novos processos

* Usar exec(): jogar tudo no lixo e começar a carregar outro do zero, nada escrito depois dele vai servir.
* Usar wait(): o pai deve esperar pelo filho terminar.

```c
pid = fork();

if (pid == 0) { // Filho
    exec(GetPgmInfo());
} else {
    wait(null);
}
```

#### 9) Um processo com PID=2600 cria um novo processo utilizando o código a seguir. O processo criado recebeu, do Sistema Operacional, o PID=2603. Suponha que exista uma função getpid() que devolve o valor do PID do processo que a chamou. Dê duas possíveis saídas impressas no terminal para a execução do programa.

<figure><img src="../../.gitbook/assets/retorno de variáveis pid em c.png" alt=""><figcaption></figcaption></figure>

Quando uma variável recebe a função `fork()`, o valor dela será zero caso esteja no processo filho e será o valor verdadeiro do pid caso esteja no processo pai. Portanto, sempre ao estar no processo filho, será zero. Sendo assim, teremos em cada print:

```c
...
else if (pid == 0) {
    pid1 = getpid();
    printf("child: pid = %d\n", pid);   // 0
    printf("child: pid1 = %d\n", pid1); // 2603
} else {
    pid1 = getpid();
    printf("parent: pid = %d\n", pid);   // 2600
    printf("parent: pid1 = %d\n", pid1); // 2600
    wait(NULL);
}
```

Mas a questão pede sobre saída no terminal. Pelo fato de termos a presença do wait(null), sabemos que os 4 prints estarão ali. Contudo, a ordem que eles serão impressos não sabemos pois quem decide isso será o escalonador. Portanto, como resposta final, é que a ordem final pode ser trocada.

#### 10) Analisando o código abaixo, o que você pode afirmar sobre o número de vezes que a mensagem “Hello world!” será escrita na tela, de acordo com o valor de N?

<figure><img src="../../.gitbook/assets/print em c com fork.png" alt=""><figcaption></figcaption></figure>

Um processo filho criado continua a partir da linha do `fork()`, mas se ele está dentro de uma iteração, ele vai continuá-la do ponto que estão atualmente (com o mesmo valor de `i` quando entrou).

Por conta disso, supostamente teriamos `2^n` processos imprimindo printf, mas como não temos um wait(), não há garantia pois o pai pode encerrar e matar todos os outros. Portanto, podemos afirmar que pode-se imprimir de 1 até no máximo 2^n vezes.

#### 18) Um sistema tem três recursos compartilhados, R1, R2 e R3, cada um com uma instância, e executa três processos, P1, P2 e P3. A tabela a seguir mostra uma sequência de chamadas em que um processo solicita um determinado recurso, na ordem em que essas chamadas devem acontecer.

<figure><img src="../../.gitbook/assets/chamadas em exercício de deadlock.png" alt=""><figcaption></figcaption></figure>

#### a) Assumindo que o sistema não implemente mecanismo para impedir deadlocks, desenhe o grafo de alocação de recursos para o sistema. O sistema entra em deadlock? Quais das chamadas são efetivamente executadas e atendidas?

Pare resolver, seguimos chamada por chamada formando as arestas. Traça uma linha de <mark style="color:blue;">solicitação</mark> e caso o recurso não esteja alocado à ninguém, tranforma aquela linha em <mark style="color:orange;">atribuição</mark>. Vamos lembrar que:

* Um processo não pode solicitar enquanto está esperando outra solicitação.
* Um processo é livre para solicitar um recurso que já está em uso.
* Deadlock só se forma em espera circular.

<figure><img src="../../.gitbook/assets/resposta deadlock a.png" alt=""><figcaption></figcaption></figure>

Sendo esse o resultado final, temos um deadlock pois está em espera circular.

#### (b) Assumindo que o sistema implemente mecanismo para impedir deadlocks e que, ao início, todos os processos declaram que podem utilizar todos os recursos, desenhe o grafo de alocação de recursos para o sistema. O sistema entra em deadlock? Quais das chamadas são efetivamente executadas e atendidas?

Essa descrição é o método de [impedir um deadlock](aula-5.md#impedir) que utiliza arestas de declarações para detectar um estado inseguro. Então esse grafo vai ter uma aresta a mais, a tracejada. <mark style="color:orange;">Para fazer</mark>, vamos ver a tabela e tracejar uma linha de todos os processos para todos os recursos solicitados.

Depois disso, temos que pensar:

1. Solicitar
2. Tem alguém usando?
3. Vai fazer um ciclo no grafo?
4. Então, atende.

Basicamente, como P1 é o primeiro processo e ele tem intenção de todos os outros recursos, isso acaba travando muito os processos por causa de causar ciclos. A parte azul é a solicitação mas de fato, na possível formação de ciclo, as chamadas não são atendidas. Portanto, apenas as chamadas 1, 5 e 8 foram atendidas.

<figure><img src="../../.gitbook/assets/resposta deadlock b.png" alt=""><figcaption></figcaption></figure>

Como é um recurso de previnir deadlock, não teremos deadlock e essa é a imagem final.

# Exercícios prova 1

#### 1) Cite quais são as principais funções de um Sistema Operacional.

As principais funções do sistema operacional, mas não as únicas, é a alocação, gerenciamento e execução de recursos, como a alocação de memória e tarefas de escalonamento de processos. Um sistema operacional pode ser definido como uma interface que traduz o que está acontecendo.

#### 2) Uma Chamada de Sistema é um dos pontos de entrada para que o Sistema Operacional atenda a uma requisição da aplicação de usuário. Explique o papel de uma Troca de Contexto para possibilitar isso.

Quando um programa faz uma Chamada de Sistema, o sistema operacional assume para executar a tarefa em modo kernel. A troca de contexto neste caso é sobre o modo de execução, onde troca o contexto entre usuário e kernel pois o modo usuário não tem permissão de fazer muita coisa e precisa de ajuda do modo kernel (diferente contexto) para realizar outras operações. Não confundir com contexto de processos.

#### 3) Dê exemplos de atividades que podem ser executadas em modo de execução de usuário ou devem ser executadas em modo núcleo (modo kernel ou modo máquina). O que há de diferente entre os dois modos que determinadas atividades podem estar em um, enquanto outras devem estar em outro?

O modo kernel é privilegiado e não possui limitações de acesso, enquanto o modo usuário possui o direito de fazer operações matemáticas e executar lógicas do tipo for, while, if, etc. O que há de diferente é a proposta onde o modo usuário é muito limitado e sem permissões para garantir segurança e estabilidade, já o modo kernel passa a ser mais sensível/crítico pelo acesso ilimitado.

#### 4) Um sistema tem uma CPU com apenas um core. Nesse sistema, queremos executar três processos, P0, P1 e P2, com tempos de execução em modo usuário de 5 ms, 10 ms e 20 ms. Na média, cada processo executa uma chamada de sistema a cada 1 ms. O escalonador do Sistema Operacional atua a cada 10 μs. O tempo médio de uma troca de contexto é de 1 μs. O tempo de tratamento de uma chamada de sistema específica é desprezível. Quanto é o tempo relógio total para execução dos três processos nesse sistema? Mostre como você chegou até a resposta.

<figure><img src="../../.gitbook/assets/resolução ex4 so.jpeg" alt=""><figcaption></figcaption></figure>

#### 5) Um processo é uma abstração interna do Sistema Operacional que encapsula diversas informações sobre um programa em execução. Dê exemplos de informações que o Sistema Operacional guarda sobre cada processo em execução.

Exemplos de informações são os estados dos processos, endereços das instruções, registradores da CPU, informações de escalonamento, gerenciamento de memória, estatísticas e informações de I/O.

#### 6) Quando um processo é dividido em várias threads, algumas das informações armazenadas sobre o processo são compartilhadas entre todas as threads, e outras são replicadas e armazenadas para cada uma das threads do processo. Dê exemplos de informações para os dois casos.

As informações compartilhadas entre todas as threads são: memória, arquivos e o código do processamento em vigor.

As informações replicadas para cada thread são: registradores da CPU, contador de código e ponteiro de pilha.&#x20;

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

#### 8) Seria viável e aconselhável implementar a aplicação do shell, do exercício anterior, utilizando criação de novas threads ao invés de novos processos? Por quê?

Não seria aconselhável a implementação de threads pois elas compartilham a mesma memória, ambiente e recursos com os processos. Portanto, existe a chance da thread falhar ou tudo falhar por conta do compartilhamento de variáveis e isso poderia prejudicaria de forma geral o shell e não seria interessante por esse motivo.

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

#### 11) Explique a diferença de escalonamento preemptivo e não-preemptivo.

Um escalonamento não preemptivo só pode escolher os processos para entrarem em execução caso não há processos em execução no momento. Já um escalonamento preemptivo possui o poder de encerrar um processo imediatamente, independente o processo está para encerrar ou não para iniciar outro.

Isso dá a chance de criar diferentes tipos de escalonamento como RR, que usa a sua preempção para encerrar processos e entregar unidades de tempo iguais para todos.

#### 12) Suponha que os processos da tabela a seguir cheguem para execução nos tempos indicados. Cada processo executará pelo tempo da sua duração de pico.

<figure><img src="../../.gitbook/assets/enunciado ex12 so.png" alt=""><figcaption></figcaption></figure>

#### a) Desenhe um esquema do escalonamento desses processos considerando escalonamento FCFS (first come, first served). Qual é o tempo médio de espera para os três processos?

O escalonamento FCFS basta colocar quem chega primeiro e executa até a finalização dele. Portanto teremos:

<figure><img src="../../.gitbook/assets/resolucao ex 12a so.png" alt=""><figcaption></figcaption></figure>

* Tempo médio P1: Início do P1 - Chegada do P1 -> `0 - 0 = 0`
* Tempo médio P2: Início do P2 - Chegada do P2 -> `8 - 3 = 5`
* Tempo médio P3: Início do P3 - Chegada do P3 -> `12 - 10 = 2`
* Tempo médio de espera: (TM(P1) + TM(P2) + TM(P3)) / 3 -> `(0 + 5 + 2) / 3 = 2,3`

#### b) Desenhe um esquema do escalonamento desses processos considerando escalonamento SRTF (shortest remaining time first, versão preemptiva de shortest job first). Qual é o tempo médio de espera para os três processos?

Esse escalonamento prioriza o processo com menor tempo e sua versão preemptiva confere a cada unidade de tempo se existe um processo com menos tempo para trocar. Assim, o esquema fica da seguinte maneira:

<figure><img src="../../.gitbook/assets/resolucao ex12b so.png" alt=""><figcaption></figcaption></figure>

A média de tempo é somar cada unidade de tempo esperado por cada processo. P2 e P3 iniciam imediatamente ao chegar e terminam seus processos, portanto, o tempo médio deles é zero. Já P1 inicia imediatamente, mas depois espera 4 unidades de tempo até P2 terminar e depois mais 1 unidade de tempo até P3 terminar, portanto: `0 + 4 + 1 = 5`.

O tempo médio total é `(5 + 0 + 0) / 3 = 1,6u`.

#### c) Desenhe um esquema do escalonamento desses processos considerando escalonamento RR (round robin) com quantum de 2 unidades de tempo, em que todos os três processos têm o mesmo nível de prioridade.

Esse escalonamento apenas deixa 2 unidades de tempo para cada processo e vai trocando eles. Como não há prioridade, é só ficar trocando e vendo o tempo restante de cada um. Assim, o escalonamento final será:

<figure><img src="../../.gitbook/assets/resolucao ex12c so.png" alt=""><figcaption></figcaption></figure>

#### 13) Explique o conceito de condição de corrida e como ele se relaciona com o conceito de seção crítica.

Condição de corrida pode ser definido quando processos que são executados de forma concorrente e utilizam dos mesmos recursos, ao serem escalonados podem gerar dados inconsistentes. Esse dado inconsistente pode ser uma variável que está presente em ambos os processos.

Ele se relaciona com seção crítica pois, a área de código que pode gerar um dado inconsistente (por exemplo essa variável) é chamada de seção crítica.

#### 14) Quais são as três características de uma solução do problema da seção crítica, e o que elas significam?

Para solucionar um problema de seção crítica, as 3 características são:

* Exclusão mútua: quando um processo está na parte crítica, mais nenhum outro processo pode entrar
* Progresso: o processamento não pode ficar parado e algum processo precisa iniciar imediatamente
* Espera limitada: um processo não vai esperar para sempre para ser executado, limitando a quantia de vezes que outros processos podem executar antes dele (depois de solicitar)

#### 15) Um programa qualquer precisa gerar um arquivo de log relatando todas as operações que foram feitas. O nome e caminho desse arquivo de log está escrito diretamente no código da aplicação e é sempre o mesmo, não importando quantas vezes o usuário executa o programa. Para criar uma mensagem de log, o programa utiliza uma função `void log(char* msg)`. Suponha que exista uma segunda função `void writeToLogFile(char* msg)` que abre o arquivo de log em modo de escrita, escreve a mensagem `msg` e fecha o arquivo, apenas. Suponha, também, que o Sistema Operacional permite que vários processos separados mantenham um mesmo arquivo aberto ao mesmo tempo, sem nenhuma restrição. Esboce o código da função log(...) de modo a garantir que as mensagens sejam escritas de maneira legível para um usuário humano.

Como estamos falando de todos abrirem o mesmo arquivo e escrever, se o escalonador começar a trocar processos durante isso vai ficar tudo errado, portanto, estamos falando de uma seção crítica.  Então, precisamos escolher alguma forma de solução de solução crítica, como o Locks Mutex.

```c
void log(char * msg) {
    acquire(&lock);
    writeLogToFile(msg);
    release(&lock);
}
```

Lembrando que este caso deixa apenas um acessar por vez. Caso pudesse mais de um, deveríamos usar o semáforo.

#### 16) Em um sistema produtor-consumidor, um processo (ou thread) gera (produz) dados que serão utilizados (consumidos) por outro processo (ou thread) para continuar o processamento da aplicação. Esses dados são armazenados em uma região de memória compartilhada que pode armazenar uma estrutura de dados em fila, por exemplo. Você possui uma biblioteca que armazena uma estrutura de dados em fila em memória compartilhada que expõe as seguintes funções:

<figure><img src="../../.gitbook/assets/enunciado ex16 so.png" alt=""><figcaption></figcaption></figure>

#### Utilizando as funções da biblioteca acima, esboce trechos de código para os programas produtor e consumidor, de modo de minimizar o tempo de CPU em espera em ação (busy wait) na sua aplicação. Note que o sistema pode ter vários processos produtores e vários consumidores, todos eles executam os mesmos códigos, todos eles operam sobre a mesma fila compartilhada, a produção e o consumo de um dado levam tempos arbitrários e não previsíveis, e nenhum desses fatores deveria influenciar na sua implementação de uma solução.

A lógica nesse código é basicamente usar apenas os métodos de semáforos ensinados e não de fato aplicá-los de forma que funcione. Usando `wait(&s)` e `signal(&s)` podemos indicar onde é a seção crítica e assim fazer a linha de raciocínio dentro dela.

Para o consumidor, criar uma variável do tipo item que recebe um ponteiro do _item\_retirado_ foi o jeito entendido da questão para usar o método `desenfileira()` que foi mostrado no enunciado.

Esse mesmo exercício foi feito em um PDF de uma universidade, [neste link](https://www.ece.ufrgs.br/\~fetter/ele213/sem.pdf). Ele aplica o semáforo do jeito verdadeiro mas usa um buffer que não vi ainda.

```c
void *produtor(void *ptr)
{
    while (true) {
        wait(&s);
        enfileira(x);
        signal(&s);
    }
}

void *consumidor(void *ptr)
{
    item *item_retirado;
    
    while (true) {
        wait(&s);
        item_retirado = desenfileira();
        
        if (item_retirado == null) {
            printf("Nulo"); 
        } else {
            ...
        }
        
        signal(&s);
    }
}
```

#### 17) Quais são as quatro condições necessárias para que um deadlock aconteça e o que elas significam?

* Exclusão mútua: só pode ter apenas um processo sendo executado (por causa de seção crítica).
* Retensão e espera: um processo espera pelo outro e não executa enquanto isso.
* Sem preempção: pois com a possibilidade de encerrar um processo de imediato, isso poderia liberar recursos.
* Espera circular: conceito que um processo espera pelo outro formando um ciclo que não há como sair.

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

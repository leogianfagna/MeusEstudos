# Aula 4

Pelo motivo de que processos podem ser interrompidos a qualquer momento e que eles também podem ser executados de forma concorrente, isso pode implicar em inconsistência, já que os <mark style="color:orange;">dados compartilhados terão acessos concorrentes</mark>. Isso exige tentar manter uma consistência ao acesso aos dados para que a integridade dos programas funcione melhor.

## Condição de corrida

Em um exemplo prático e fácil, vamos supor que temos o processo P0 em execução que estava usando uma variável temporária chamada saldo, mas o escalonador o interrompe e inicia o P1. Esse P1 que foi criado a partir de um fork também usa essa variável, e agora ele mexeu no valor dela. Ao voltar ao P0, deu um problema nos cálculos matemáticos pois a lógica foi completamente comprometida. O nome dado para este problema se chama condição de corrida.

Em resumo, consiste em múltiplos processos usando um recurso compartilhado que gera um dado inconsistente: exemplo uma variável compartilhada, um recurso escrito ou tantos outros exemplos. A <mark style="color:blue;">parte de código que usa esses recursos compartilhados</mark> que podem dar problemas são chamados de <mark style="color:blue;">**seção crítica**</mark>.

## Seção crítica

Para uma seção crítica funcionar corretamente, é necessário garantir pelo menos três coisas:

* Exclusão mútua: ninguém pode executar uma parte de código de seção crítica enquanto outro processo já estiver fazendo isso.
* Progresso: uma escolha imediata de quem entra na seção crítica, não pode ficar esperando.
* Espera limitada: limite no número de vezes que outros processos entram nessa seção depois que um outro processo pede para entrar, então ao pedir, vai ter um tempo limite de espera máximo determinado.

Todos esses requisitos devem trabalhar juntos para solucionar esse problema pois apenas um não será suficiente. Existem soluções diferentes propostas para trabalhar neste caso.

| Solução             | O que resolve                                                                | Problema restante                                                                          |
| ------------------- | ---------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------ |
| Solução de Peterson | Confere se o outro processo está em seção crítica                            | Funciona apenas para dois processos, lento, busy waiting, liveness                         |
| Locks Mutex         | Chave de porta, tranca ao entrar em seção crítica                            | Trava demais processos que poderiam estar executando sem problemas, busy waiting, liveness |
| Semáforos           | Não trava processos que poderiam estar sendo executados sem causar problemas | Busy waiting, liveness                                                                     |

### Solução de Peterson

Essa solução acaba ficando apenas na teoria pelo fato de que é algo proposto para dois processos não se encontrarem nessa seção. Ela funciona basicamente dos dois processos compartilharem a variável `turn` (indica a vez de quem) e `flag[2]` (indica se um processo está pronto),&#x20;

```c
// P1
flag[i] = true;
turn = j;

while(flag[j] && turn == j); // Espere, há seção crítica

// Começa seção crítica
flag[i] = false;
codificação...


// P2
flag[i] = true;
turn = i;

while (flag[i] && turn == i); // Espere, há seção crítica

// Começa seção crítica
flag[j] = false;
codificação...
```

### Locks Mutex

Uma solução fornecida pelo sistema operacional que oferece exclusão mútua com uma forma simples de marcar entrada e saída da seção crítica, usandos os métodos `acquire()` para proteger uma seção crítica e `release()` para destrancar, como se fosse uma chave para uma porta. O **mutex lock** é uma variável booleana que indica se uma "chave" está disponível para trancar.

```c
while (lock == 1);

acquire(&lock);
// Seção crítica
// ...

release(&lock); // "lock" passa a ser zero
```

O problema dessa solução é que tudo é travado, inclusive processos que poderiam estar sendo executados por não terem a chance de serem prejudiciais para inconsistências.

### Semáforos

De forma simples de explicar, o semáforo começa com um contador que é um número inteiro, esse número simboliza quantas threads poderão acessar os recursos. Cada vez que uma thread quer acessar o recurso protegido, ela tem que verificar se há vagas restantes, se uma thread acessa esse recurso, ela diminuir em um o valor.

Basicamente a ideia de "cabines restantes", cada vez que alguém entra em uma cabine tem -1 disponível, ao sair vai ter +1 disponível e se tiver zero, pessoas estarão esperando na fila até que alguém saia. Na nossa prática, uma thread vai acessar o recurso com o método `wait()` e sair usando `signal()`.

No exemplo anterior, vimos que trancar algo pode ser fatal pelo fato de que outros processos poderiam estar sendo executados ao mesmo tempo sem dar problema. Um exemplo disso pode ser a função de imprimir de um hardware de impressora, onde esse hardware permite que até 5 impressoras estajam imprimindo simultaneamente. Neste caso, um semáforo é criado com o contador `5`, chamado de <mark style="color:purple;">semáforo de contagem</mark>.

Mas vamos supor que o processo consiste na manipulação da variável global "saldo". Talvez esses processos podem estar implementados de forma que vários podem estar usando ela sem problemas, mas se for algo mais crítico, é criado um semáforo com contador `1`, onde apenas uma thread poderá estar processando. Isso é chamado de <mark style="color:purple;">semáforo binário</mark>, que funciona basicamente da mesma forma que o Locks Mutex.

<figure><img src="../../.gitbook/assets/semáforo binário.png" alt=""><figcaption></figcaption></figure>

## Problemas não resolvidos

Observando as três soluções propostas, de resumo, todas apresentam como problemas o busy waiting e o liveness. Processos podem ter que esperar indefinidamente pela sua vez <mark style="color:red;">violando</mark> o Liveness, que é um conjunto de propriedades que um sistema precisa ter para garantir seu progresso e a espera limitada é um deles.

Um termo que pode acontecer se chama deadlock, onde dois ou mais processos estão esperando por um evento que só pode ser causado por um processo em espera. Veja abaixo onde um processo espera o `signal()` do outro, só que pela ordem que eles estão, isso nunca vai acontecer fazendo um <mark style="color:blue;">esperar o outro infinitamente</mark>. Por conta disso, chamamos que eles estão em <mark style="color:purple;">**deadlock**</mark>.

<figure><img src="../../.gitbook/assets/representação de deadlock.png" alt=""><figcaption></figcaption></figure>

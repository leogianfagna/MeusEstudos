# Aula 2

## Explicando processos

Recapitulando, processos são o <mark style="color:blue;">princípio ativo</mark> de um programa. As instruções são enviadas a um endereço de memória e dessa memória é jogada a um terminal pois eles são <mark style="color:green;">executados via linhas de comandos</mark>. A memória acaba ficando deste formato:

<figure><img src="../../.gitbook/assets/memoria de um processo.png" alt=""><figcaption></figcaption></figure>

Cada parte da execução de um processo (código) utiliza uma parte da memória específica:

* Variáveis globais são dados -> armazenados em data
* Variáveis locais (temporários) vão para os registradores, absurdamente rápidos e simbolizam a atividade atual. Como em cada registrador cabe apenas uma palavra, o que não couber vai para a pilha
* Ponteiros (simbolizados no código como "values") ficam na pilha e o conteúdo ao qual ele aponta está na heap, pois são alocados dinamicamente

<figure><img src="../../.gitbook/assets/exemplo real com código de uso de memória.png" alt=""><figcaption></figcaption></figure>

## Estado de um processo

Um processo vai conter um estado que simboliza o momento em que ele se encontra atualmente. Esse estado sempre vai ficar em torno do pronto (que significa READY para ser executado), em execução e espera (que está esperando o resultado de algo para continuar e ficar pronto novamente).

<figure><img src="../../.gitbook/assets/estados de um processo.png" alt=""><figcaption></figcaption></figure>

## Bloco de controle

Metaforicamente, pode ser visto como uma <mark style="color:blue;">caixinha de ferramentas</mark> que possui tudo o que o processo dele precisa para ser executado, isso também é conhecido como PCB. Essa caixinha, tecnicamente, vai possuir muita coisa como informações, os estados do processo, endereço das instruções, registradores da CPU, informações de escalonamento, gerenciamento de memória, estatísticas e informações de I/O (define os dispositivos alocados).

### Escalonamento de processo

Vimos que um processo não ocorre de forma simultânea a outra e quem decide isso é o sistema operacional. O escalonamento é a definição de decidir <mark style="color:blue;">quem é o próximo</mark>, uma tarefa <mark style="color:orange;">muito importante</mark> pois isso acontece a todo momento.

Lembrando que isso tem muita relação com um estado de um processo pois são escolhidos para a fila apenas aqueles que estão em estado de "prontos". A troca de contexto de um processo consequentemente vai mudar o seu estado.

## Criação de um processo

Um <mark style="color:blue;">processo pode criar processos filhos</mark>, que são totalmente dependentes e ao longo do tempo de execução vai se criando uma árvore de processos. Esse processo agora é chamado de processo pai, que é "responsável" pelo filho pois, ao processo pai finalizar, o filho _morre_ junto.

Esses processos não compartilham dados entre si, mas sim memória onde o processo pai pode dar um pedaço da memória que estava usando para o filho. Isso é uma possibilidade, também existe a  opção de alocar mais memória mas quem decide isso é apenas o sistema operacional baseado nas suas condições.

### Criação do processo filho

O processo pai decidir ter um processo filho é através metaforicamente de uma <mark style="color:blue;">mitose</mark>, onde o processo gerado é exatamente igual ao outro. Dentro do código, isso acontece através de uma chamada de sistema chamada <mark style="color:green;">`fork()`</mark>.

Criar processos **exatamentes** iguais aos outros, em muitos casos não parece ser tão útil. Por isso, também temos uma chamada de sistema <mark style="color:green;">`exec()`</mark>, que é como se ela pegasse aquela caixinha de ferramentas e processos e jogasse tudo no lixo, pronta para executar algo diferente do pai.

Como dito acima, o processo pai precisa <mark style="color:blue;">esperar o filho terminar</mark> pois se ele terminar antes o filho é encerrado, mesmo se ainda estiver em execução. Para isso, existe a chamada de sistema <mark style="color:green;">`wait()`</mark> que recebe um ponteiro e serve exatamente para isso.

```c
int main() {
    pid_+ pid;
    pid = fork(); // Aqui faz a mitose
    
    // Processo filho
    if (pid == 0) {
        exec(...);
    }
    // Processo pai
    else {
        wait(null);
    }
    
    return 0;
}
```

Como vemos acima, os processos são definidos por um PID e quando usamos o `fork()` precisamos <mark style="color:blue;">definir quem é o processo pai e o filho dentro do código</mark>, pois como eles são iguais, terão o mesmo algoritmo.

#### Exemplo de encerramento

Veja abaixo esse exemplo básico, ele ajuda muito a entender os processos de mitose e o que vai acontecer. Primeiramente temos apenas um processo até chegar no primeiro fork, o que torna dois. A partir disso, cada novo fork vai criar o processo de mitose com todos já existentes, resultando em 8 processos no final.

```c
int main() {

    fork(); // 1 * 2 = 2 processos
    
    fork(); // 2 * 2 = 4 processos
    
    fork(); // 4 * 2 = 8 processos

    printf("Imprimindo algo");
    return 0;
}
```

Agora a parte importante. **Quantas vezes a mensagem será exibida na tela?** O que podemos afirmar é que pelo menos uma, ou apenas uma mesmo. Isso porque, dentre esses 8 processos, 1 é o pai e os outros 7 são filhos. Como não temos a chamada de sistema `wait()`, isso quer dizer que quando o processo pai finalizar, todos os demais processos morrerão.

Então, não é garantido que os demais processos vão conseguir chegar até a sua execução final antes do processo pai finalizar.

### Encerramento de processos

De forma muito simples, as chamadas de sistemas <mark style="color:green;">`exit()`</mark> ou `return 0` são responsáveis por encerrar um processo. Temos ainda a opção do método <mark style="color:green;">`abort()`</mark> que é usado para encerrar algum processo filho. Ao encerrar o processo pai, chamamos de <mark style="color:blue;">encerramento em cascata</mark>.

A partir disso temos dois conceitos:

* Se não há pai esperando (pai não chamou wait() ) o processo é um <mark style="color:purple;">**zumbi**</mark>
* Se o pai terminou se chamar wait() , processo é <mark style="color:purple;">**órfão**</mark>

## Threads

Elas são subdivisões dentro do processo que podem ser escalonadas junto com eles. Elas aplicam os conceitos de <mark style="color:blue;">responsividade</mark> (permite continuar executando se parte do processo está bloqueado), <mark style="color:blue;">compartilhamento de recursos</mark>, <mark style="color:blue;">economia</mark> e <mark style="color:blue;">escalabilidade</mark> (threads podem ser executadas em paralelo).

Tarefas diversas podem ser rodadas em outras threads para não interromper algo, como atualizar tela, buscar dados, corrigir ortografia, entre muitas outras. Nesse curso, não vamos precisar entrar afundo nelas, apenas saber que elas existem.

### Dados compartilhados

Quando um processo é dividido em várias threads, algumas das informações armazenadas sobre o processo são <mark style="color:blue;">compartilhadas entre todas as threads</mark> e outras são <mark style="color:blue;">replicadas e armazenadas para cada uma</mark> das threads do processo.&#x20;

Abaixo podemos ver o esquema que vai nos dar o exemplo dos tipos de dados compartilhados para todas e os replicados, visto na horizontal e vertical respectivamente:

* Compartilhada entre todas:
  * Código (instruções): O código que está sendo executado pelo processo é compartilhado entre todas as threads. Cada thread pode executar partes diferentes do mesmo código ao mesmo tempo.
  * Memória: Todas as threads de um processo compartilham o mesmo espaço de endereçamento, o que significa que elas podem acessar as mesmas variáveis globais e heap de memória.
  * Arquivos: Se uma thread ou o próprio processo abre um arquivo, todas as threads têm acesso a ele.
* Replicadas:
  * Registradores da CPU: Cada thread tem seu próprio conjunto de registradores, que guardam o estado atual de execução, como os dados temporários e o valor do contador de programa.
  * Ponteiro de pilha: Cada thread tem sua própria pilha (stack), que armazena variáveis locais, chamadas de funções, e o contexto de execução da thread. Isso permite que cada thread execute independentemente e mantenha o seu próprio estado local.
  * Contador de programa: O contador de programa, que aponta para a próxima instrução a ser executada, é exclusivo para cada thread. Cada thread pode estar executando uma parte diferente do código, então cada uma precisa do seu próprio PC.

<figure><img src="../../.gitbook/assets/compartilhamento de dados de threads.png" alt=""><figcaption></figcaption></figure>

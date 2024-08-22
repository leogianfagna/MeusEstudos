# Aula 3

Recordando que o escalonamento da CPU é a escolha de novos processos para assumir, o uso da CPU pode ser representada desta forma:

<figure><img src="../../.gitbook/assets/cpu burst esquema.png" alt=""><figcaption></figcaption></figure>

* `CPU BURST`: Ponto alto/pico da CPU pois ela atualmente está em uso. Isso significa que algum processo está no estado "<mark style="color:blue;">em execução</mark>"
* `I/O BURST`: Ponto baixo/pico de I/O pois não está sendo usada já que um processo está esperando por algo para continuar, ou seja, o processo está no estado "<mark style="color:blue;">em espera</mark>"

Portanto, basicamente os processos usarão a CPU durante alguns pontos e outros não pois eles estarão esperando o resultado de alguma outra coisa para continuar, um exemplo de muitos é uma entrada do usuário.

Esses <mark style="color:blue;">picos de CPU são feitos pelo escalonador</mark>, que é um <mark style="color:green;">componente do sistema operacional</mark> cujo trabalho é unicamente tomar a decisão de quem é o próximo. O trabalho de enviar/colocar os processos em execução é responsabilidade do <mark style="color:purple;">**dispatcher**</mark>, então o escalonador escolhe os processos para ele e o dispatcher coloca eles em execução e também troca o contexto dos processos.

## Políticas de escalonamento

A política adotada é baseada se o escalonador pode ou não escolher um processo naquele exato momento dada algumas condições. Elas são importantes para entender um conceito mais avançado:

* Não preemptivo: um processo só poderá ser colocado em execução ou escolhido a partir do momento que <mark style="color:green;">não houver nenhum processo</mark> no estado de "em execução". Ou seja, entra um processo apenas quando sai outro.
* Preemptivo: dá o poder de iniciar um processo quando o <mark style="color:green;">sistema bem quiser</mark>, interrompendo um processo que estava em execução para iniciar outro.

## Critérios e tipos de escalonamento

Ao passar da evolução dos computadores, a forma em que o escalonamento era feito foi mudando e veremos os tipos de cada um a seguir. Todos tem como um critério principal o maior uso possível da CPU. Conforme um novo tipo de escalonamento chega, um novo critério é adotado para conseguir que ele seja mais eficiente que o anterior.

Sempre lembrar o conceito **Throughput** que simboliza o tempo coletivo de todos os processos terminarem. Eles são muito importantes pois entram em conflito com a vontade individual de cada processo finalizar.

### Escalonamento FCFS (First- Come, First-Served)

Os processos são colocados para executar na CPU baseado na ordem de chegada que o escalonador enviou. Então, se chegaram os processos P1, P2 e P3 nesta ordem, assim eles serão executados.

<figure><img src="../../.gitbook/assets/diagrama escalonamento FCFS.png" alt=""><figcaption></figcaption></figure>

<mark style="color:red;">**Problema:**</mark> se P1 possui 24 unidades de tempo e os demais possuem 3, fazendo uma média de espera temos:

$$
tempoEsperaMedia = (TM(P1) +TM(P2) +TM(P3))/3
$$

$$
tempoEsperaMedia = (0 + 24 + 27) / 3 =17
$$

Isso significa que o tempo de espera média são de 17 unidades de tempo, mas seria muito mais otimizado se começassemos com o P2 e P3, diminuindo este tempo de espera e deixando processos menos ociosos. Por isso, tivemos o processo SJF.

### Escalonamento SJF (Shortest-Job-First)

Esse tipo de escalonamento resolve o problema acima de um tempo médio muito longo, onde os processos são colocados para executar na CPU baseado em seu menor tempo. Com o mesmo exemplo acima, teremos o novo tempo médio de:

$$
tempoEsperaMedia = (0 + 3 + 6) / 3 =3
$$

<figure><img src="../../.gitbook/assets/diagrama escalonamento SJF.png" alt=""><figcaption></figcaption></figure>

<mark style="color:red;">**Problema:**</mark> assim como o outro, esse tipo também possui um problema pois a máquina não consegue definir ou estimar esses tempos de picos. Na teoria parece ser muito bom, mas na prática não tem como fazer uma escolha precisa se não sabemos quando tempo de pico vai demorar. Outro problema é que os processos nunca chegam juntos e sim aos poucos, de forma nada organizada.

Resolver o problema da chegada de novos processos e o tempo de pico usaram o SRTF, que é um método **preemptivo** do SJF (isso significa que, diferentemente do outro, ele poderá encerrar processos para começar um novo).

### Escalonamento SRTF (Shortest Remaining Time First)

Ele tem como base o mesmo do anterior em processar primeiro os mais rápidos, iniciando com os processos disponíveis no momento (aqueles que estão na fila em estado "pronto"). Com a <mark style="color:purple;">chegada de novos processos</mark> e a cada <mark style="color:purple;">unidade de tempo percorrida</mark>, esse escalonador faz uma <mark style="color:orange;">nova decisão</mark> de qual processo assumir.

Um processo que está em execução, a cada unidade de tempo, precisa deduzir do tempo total dele para contabilizar na nova decisão. Em um exemplo prático, vejamos:

<table><thead><tr><th width="143">Processo</th><th>Unidade de tempo de chegada</th><th>Tempo de pico</th></tr></thead><tbody><tr><td>P1</td><td>0</td><td>8</td></tr><tr><td>P2</td><td>1</td><td>4</td></tr><tr><td>P3</td><td>2</td><td>9</td></tr><tr><td>P4</td><td>3</td><td>5</td></tr></tbody></table>

O primeiro processo a ser iniciado será o P1 por ser o único disponível no momento. Depois disso, a cada unidade de tempo, "pode tacar o facão" e assumir um novo processo para assumir, já que ele é preemptivo. Basicamente, ele faz isso até todos os processos chegarem, depois disso, ele se comporta igualmente ao escalonamento SJF. Portanto, o uso do processador será:

<figure><img src="../../.gitbook/assets/diagrama gant escalonamento SRTF.png" alt=""><figcaption></figcaption></figure>

* A flecha indica quais processos estão disponíveis naquela unidade de tempo
* Inicia com P1 já que é o único disponível naquele momento
* Unidade de tempo 1: o processo P2 chega e ele é mais vantajoso (menor) que P1, por isso ele assume
* O restante das unidades de tempo os outros processos vão chegando, mas ninguém é mais vantajoso que o P2 que está assumido no momento

Assim, o cálculo da média é represetando por:

<figure><img src="../../.gitbook/assets/media de escalonamento SRTF.png" alt=""><figcaption></figcaption></figure>

<mark style="color:red;">**Problema:**</mark> ainda assim não sabemos quanto um processo vai durar. Então, optamos por um outro tipo de escalonamento.

### Escalonamento Round Robin (RR)

Esse escalonamento é baseado em unidades de tempo pré definidas para cada processo. Cada processo ganha uma unidade de tempo chamada _<mark style="color:blue;">quantum</mark>_ e depois disso há preempção do processo, isto é, ele sai de execução e fica em pronto para a entrada de um outro processo.

Veja um exemplo abaixo com os processos P1 (24 de pico), P2 (3 de pico) e P3 (3 de pico).

<figure><img src="../../.gitbook/assets/escalonamento RR.png" alt=""><figcaption></figcaption></figure>

### Escalonamento por prioridade

Esse escalonamento é baseado em prioridade definidas para cada processo. Cada processo recebe um número (pelo próprio sistema) de prioridade e quanto menor o número, mais prioridade ele tem. Então os processos formam uma fila baseada nesse número.

Existe um conceito chamado <mark style="color:red;">starvation</mark> que consiste que processos com prioridades baixas nunca serão executados já que sempre chegam processos com prioridades maiores (esse conceito também acontece no SJF se pensarmos que sempre chega processos menores e nunca vai deixar os maiores serem executados). O problema é que, mesmo que esse processo tenha uma prioridade baixa, ele é necessário para o funcionamento de alguma coisa.

Portanto, criou-se uma solução chamada _<mark style="color:green;">aging</mark>_ que o sistema vai acrescentando prioridade para esses processos de grau menor, certificando-se que uma hora ele terá a prioridade necessária para ser executada. O diagrama desse tipo de escalonamento é muito simples, apenas seguindo dos processos com mais prioridades para os com menos prioridade.

### Escalonamento Round Robin com prioridade

Esse é o modelo que seguimos atualmente aproximadamente. Esse escalonamento é baseado em prioridade e unidades de tempo pré definidas para cada processo, juntando as formas de escalonamento RR e prioridade.

Ao final de cada unidade de tempo quantum (estilo escalonamento RR), a escolha do novo processo é baseada na prioridade (estilo escalonamento prioridade). Vendo um exemplo de diagrama final, para 2 unidades de tempo definidas de quantum, temos:

<figure><img src="../../.gitbook/assets/escalonamento RR com prioridade.png" alt=""><figcaption></figcaption></figure>

Se na troca de processos, o processo atual tem a maior prioridade da fila, não ocorre a troca de processos. Se eles tem a mesma prioridade, os processos são trocados.

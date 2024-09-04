# Aula 5

Recursos (como a CPU, disco, basicamente tudo) são algo que o processo precisa para fazer alguma coisa. Esses recursos possuem instâncias, exemplo uma CPU com 4 cores, onde significa que esse recurso possui 4 instâncias e tanto faz qual usar. Os processos usam os recursos da seguinte maneira:

> request -> use -> release

## Características de um deadlock

Um deadlock precisa ter, **necessariamente**, essas 4 características para conseguir ser formado. Elas são muito importantes pois vão ajudar a entender soluções.

* Exclusão mútua
* Retensão e espera
* Sem preempção (sem o "facão" para liberar o recurso significa que pode ficar travado para sempre)
* Espera circular (conceito de um processo esperar pelo outro mas ninguém consegue seguir)



## Grafo de alocações de recursos

Antes, relembrando o que é um grafo, um diagrama composto por um conjunto de:&#x20;

* **Vértices (nós)**
  * <mark style="color:purple;">Círculos</mark>: são os processos
  * <mark style="color:purple;">Retângulos</mark>: são os recursos
    * Dentro de cada retângulo pode haver uma bolinha para representar a quantidade de instâncias do recurso, lembrando que qualquer uma delas funcionam e pode usar.



* **Arestas (conexões)**
  * Aresta de <mark style="color:purple;">solicitação</mark>: aponta de um processo para um recurso que indica que o processo pediu para usar o recurso
  * Aresta de <mark style="color:purple;">atribuição</mark>: aponta de um recurso para um processo, onde o recurso foi travado para um processo após solicitação.
  * Revisão conceitos sobre grafos:
    * Não direcionadas: nenhuma seta, indicando que tanto faz se é um pra outro ou contrário
    * Direcionadas: quando possui uma seta, informando a direção que vai
      * Quando temos <mark style="color:blue;">apenas direcionadas</mark>, o gráfico possui um <mark style="color:purple;">**ciclo**</mark>. A dificuldade de encontrar um ciclo é `numNós ^ 2`

Quando há a existência de um ciclo no grafo, isso significa que podemos ter um deadlock, mas não necessariamente vai acontecer. Se não existisse nenhum ciclo, pode-se descartar essa possibilidade. Outro fator muito marcante é que, se houver um ciclo e tiver apenas uma instância nos recursos, definitivamente terá um deadlock.

### Exemplo prático

No caso abaixo temos um ciclo completo marcado em roxo. O recurso R2 fornece para os processos P1 e P2 e o P3 solicita dele, formando um ciclo e instâncias insuficientes, por isso cria-se um deadlock. Caso algum processo terminasse, o sentido das setas mudaria e o sistema seria liberado, mas como P3 está esperando infinitamente, isso não vai acontecer.

<figure><img src="../../.gitbook/assets/grafos para representar deadlock.png" alt=""><figcaption></figcaption></figure>

Quando um processo pede um recurso (seta azul), o recurso antigo usado <mark style="color:orange;">ainda estará direcionado</mark> para ele, por exemplo, veja o R2 apontando para P1 mesmo ele solicitando o R1. É por conta disso que, mesmo P1 solicitando por outro recurso o R2 ainda fica apontado para ele, causando esse problema.

## Formas de lidar

Temos 4 formas de lidar quando acontece um deadlock:

1. Previnir
2. Impedir
3. Deixar entrar e depois recuperar
4. Ignorar e seguir em frente

### Previnir

Como sabemos as quatro condições citadas acima para um deadlock acontecer, se resolvermos alguma delas já temos uma solução por completo. Contudo, cada um dos quatro elementos fazem parte das lógicas e leis de programação e processamento. A solução mais possível seria alocar os recursos em ordem correta (que seria resolver a espera circular), mas isso depende exclusivamente dos programadores, então seria quase impossível.

### Impedir

Existe uma <mark style="color:green;">solução real</mark> para impedir isso, ela funciona da seguinte forma:

1. Cria uma nova aresta chamada declaração (claim em inglês).
2. Usa essa aresta no começo de tudo, onde cada processo aponta com essa seta para os recursos que querem usar.
3. Por conta disso, o sistema agora sabe quem quer usar o quê.
4. Com essa informação extra, pode-se gerar um diagrama hipotético e isso pode encontrar a iminência de acontecer um deadlock. Essa informação se chama <mark style="color:purple;">**estado inseguro**</mark>.
5. Com a presença de um estado inseguro, o sistema impede a formação de arestas que formariam um ciclo.
6. Durante o processamento, após o uso de uma aresta que era atribuição ela volta a ser declaração, e ai ocorre uma nova busca por possíveis problemas.

Essa solução funciona mas tem alguns problemas. Como dito acima, inicialmente e a cada vez que um processo pede por recurso há a necessidade de calcular ciclos e estados inseguros causando demora. Por conta disso, essa solução é usada <mark style="color:blue;">apenas em processos muitos críticos</mark>.

### Recuperar após ocorrência

Segue um pouco da filosofia acima em procurar ciclos para sair desligando processos até que a linha volte a fluir. Os processos são desligados baseados em uma ordem de prioridade, são vários atributos para ver quem é o primeiro a ser desligado.

### Ignorar

Lidar com deadlock é algo muito difícil e crítico, portanto, esta metodologia será <mark style="color:blue;">usada na maioria esmagadora dos casos</mark>, que é o usuário apenas reiniciar o que travou. Ela só não poderá ser levada em consideração em casos críticos e para isso usamos o [impedir](aula-5.md#impedir).

## Algorítmo de banqueiro

E se houver mais recursos de um mesmo tipo? Neste caso, usa-se o termo do algorítmo de banqueiro, que não foi estudado ainda e será visto apenas no futuro da disciplina.

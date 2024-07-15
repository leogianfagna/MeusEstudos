# Scrum

O modelo e fases de vida do Scrum é composto dessa forma:

<figure><img src="../../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

Quem realiza as tarefas do scrum é uma equipe, composta por:&#x20;

* Dono do produto: escolhe os requisitos (cliente)&#x20;
* Scrum Master: líder da equipe, organiza tudo&#x20;
* Equipe: programadores ou membros treinados e multifuncionais&#x20;

## Sprint Backlog

É um quadro que recebe as tarefas dos requisitos. Cada requisito possui uma série de tarefas para serem realizadas, para aquele requisito ser concluído. Essas tarefas são adicionadas nesse quadro em colunas categorizadas como “a fazer”, “em progresso” e “feitos” (assim como é no GitHub).&#x20;

Esse quadro é montado para cada sprint que temos. Um exemplo é:&#x20;

<figure><img src="../../.gitbook/assets/image (2) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

## A divisão dos estados do scrum

Em um Scrum, o sprint é uma unidade de tempo fixa a qual um conjunto de trabalhos específicos deve ser concluído e entregue, que seriam elas, as tarefas definidas no backlog. &#x20;

O <mark style="color:blue;">**primeiro estado**</mark> consiste no <mark style="color:green;">**planejamento do sprint**</mark>, que é feito uma estimativa de esforço dos requisitos a serem cumpridos. O esforço é medido com a dinâmica Planning Poker, onde cada membro da equipe concede uma nota de dificuldade para a tarefa baseado nos números de Fibonacci e explica o porquê daquela nota. Assim, com diferentes opiniões e explicações, se faz um consenso entre todos e definindo o esforço final.&#x20;

O <mark style="color:blue;">**segundo estado**</mark> é a <mark style="color:green;">**definição e adição das funcionalidades**</mark>. Em uma tabela com os requisitos, é marcado em qual sprint cada requisito será realizado.&#x20;

O <mark style="color:blue;">**terceiro estado**</mark> é o sprint por si só. Essa fase consiste na <mark style="color:green;">**implementação**</mark> e realização do requisito. &#x20;

E o <mark style="color:blue;">**quarto estado**</mark> consiste em uma <mark style="color:green;">**reunião diária**</mark>. Todos os dias (a cada 24 horas), reuniões de no máximo 15 minutos para apontamento de questões relevantes.&#x20;



## Exemplos de sprints já planejados

Abaixo uma tabela com o sprint planejado, com as prioridades, esforços e o sprint definido ao qual será realizado. Esse planejamento consiste em **velocidade 20**.

<figure><img src="../../.gitbook/assets/image (3) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

### Medindo a velocidade no produto backlog (pergunta de prova)

A velocidade é a <mark style="color:blue;">**soma do esforço**</mark>, que é o número de horas que serão gastas para fazer determinada tarefa em um scrum. Então, considerando o sprint 1, a velocidade é 20 já que é a soma de todo o esforço (8 + 3 + 3 + 3 + 3 = 20).

Com o cálculo da velocidade, também se planeja em quantos sprints o projeto ficará pronto. Vamos supor que temos um total de 47 na soma dos esforços e uma velocidade estimada em 13 unidades, o prazo será o valor <mark style="color:blue;">**total de esforço dividido pela velocidade**</mark>. Arredondando para cima, temos ao todo 4 sprints para concluir usando esse exemplo.

Pode ocorrer recálculos na velocidade calculada de um sprint, isso pode ocorrer dependendo de como ocorre os esforços durante a execução daquele sprint. Se no primeiro sprint somou 13 horas e no final não deu tempo para concluir, então todos os outros sprints devem ser recalculados para 13, se estiverem acima desse número.

Também relacionado a isso, quando temos requisitos que são muito complexos, eles são abertos em tarefas menores. Todos os grandes requisitos possuem várias tarefas. No visual da tabela, o requisito 9 é dividido em 9.1, 9.2 e assim vai.

Relacionado a isso temos dois termos usados para alguns requisitos:&#x20;

* **Épico**: é quando há uma história de usuário que não pode ser completada em um único sprint. São aquelas grandes funcionalidades que precisam ser divididas em menores (grandes metas ou requisitos de alto nível)&#x20;
* **Saga**: é uma sequência de histórias que são todas relacionadas e quando completadas, impactam com um valor muito significativo. É basicamente um conjunto de várias histórias relacionadas, divergindo do épico, que é apenas uma grande.&#x20;



## Planejamento das sprints

O Sprint Planning é uma cerimônia do Scrum que marca o início de um novo sprint. Durante o Sprint Planning, a equipe Scrum se reúne para definir quais tarefas ou histórias de usuário do Product Backlog serão trabalhadas durante o sprint atual e como elas serão entregues.



### Gráfico de burndown

Este gráfico mostra a quantidade de trabalho restante no Sprint Backlog ao longo do tempo. Idealmente, a linha de burndown diminui progressivamente à medida que a equipe completa tarefas. O Sprint Planning ajuda a definir o escopo do sprint, e o Gráfico de Burndown é uma ferramenta que a equipe usa para acompanhar seu progresso em direção à conclusão das tarefas.

<figure><img src="../../.gitbook/assets/image (4) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

### Gráfico de burnup

O Gráfico de Burnup mostra a quantidade de trabalho concluída ao longo do tempo, bem como a evolução do escopo do sprint. O Sprint Planning ajuda a definir a meta de sprint e o escopo inicial, e o Gráfico de Burnup permite que a equipe acompanhe o progresso em relação a essa meta e visualize qualquer mudança no escopo ao longo do sprint.

<figure><img src="../../.gitbook/assets/image (5) (1) (1).png" alt=""><figcaption></figcaption></figure>

### Indicadores

Durante o Sprint Planning, a equipe pode usar indicadores como a Velocidade (quantidade média de story points completados por sprint) para ajudar na estimativa do esforço e na definição da meta de sprint. Durante o sprint, a equipe também pode monitorar indicadores como o progresso diário, impedimentos e taxas de conclusão de tarefas para avaliar o desempenho e fazer ajustes conforme necessário.

<figure><img src="../../.gitbook/assets/image (6) (1).png" alt=""><figcaption></figcaption></figure>

## Diferença entre escopos

* Escopo aberto se não entregar alguma funcionalidade no tempo é só passar para o próximo sprint refazendo o cálculo do esforço
* O escopo fechado não tem um contrato em si especificando cada entrega de cada funcionalidade. &#x20;

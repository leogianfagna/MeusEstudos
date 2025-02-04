# Fundamentos

## Banco de dados relacionais x não relacionais

Esses bancos de dados possuem finalidades diferentes. Não podemos comparar puramente pois eles são estruturas diferentes com propósitos também diferentes.

O banco relacional foi feito para organizar o [pensamento analítico do projetista](#user-content-fn-1)[^1]. Ele trabalha com <mark style="color:blue;">tabelas estabelecendo relacionamento forte entre elas</mark>. Consiste em uma estrutura organizada que <mark style="color:green;">foca na integridade dos dados</mark>, com estrutura de dados definida (relações claras entre as entidades), consultas complexas (podendo usar dados de diferentes tabelas), segurança, entre outros&#x20;

O banco não relacional foi feito para [performance nas buscas](#user-content-fn-2)[^2]. Já o não relacional <mark style="color:blue;">pode possuir diferentes estruturas</mark> (grafos, chave-valor, documentos, etc) permitindo e <mark style="color:green;">focando em uma maior flexibilidade e alta escalabilidade</mark>.

## Conceitos práticos entre bancos relacionais e não relacionais

Banco relacional não é repetição e sim orientado a organização. O não relacional desorganiza para ter desempenho. Isso quer dizer que você pode ter redundância de dados em um banco não relacional.&#x20;

Mesmo os dados não tendo padrão de organização, existe uma semântica/taxinomia necessária. Não colocar documento de tal assunto em uma coleção que não lhe compete, para otimizar as buscas e não acontecer certos problemas.

MongoDB é manter alta disponibilidade. Deve ser construído pelo design da solução/arquitetura que adotar. Para garantir, criar pelo menos mais uma cópia dos dados, chamado de Réplica Sets.&#x20;

Replica Sets (ou conjunto replicado) é um grupo de pelo menos 3 instâncias (também chamados de node, o que seria um computador).&#x20;

<figure><img src="../../../.gitbook/assets/esquema de replica set.png" alt=""><figcaption></figcaption></figure>

Cluster na prática é uma sala cheia de computadores conectados, em algum desses computadores está rodando o nó primário do cluster, no nosso caso, o N0 (banco de dados).&#x20;

Na prática, ao executar um SET, segue para o primário. O nó primário grava o dado e salva no disco (pode tá no próprio computador ou em qualquer lugar, pois é um armazenamento não volátil, persistente).&#x20;

No MongoDB, o equivalente a tabela é coleção de documentos. Ao invés de linhas, temos documentos em uma coleção. A dica é não comparar relacional com não relacional para entender a teoria melhor.&#x20;

## Arquitetura e distribuição de dados “dbs”

90% das empresas brasileiras usam banco de dados operacionais para as operações (aqueles para operar o negócio). Por que não mudar para bancos não relacionais? &#x20;

Esses bancos de dados foram inicialmente criados em relacionais devido a tecnologia que existia no momento. Por isso, existem milhares de processos já salvos no banco de dados. Se houver algum problema em algum processo, isso vai dar prejuízo. Além de que, uma transferência disso custo absurdamente caro.&#x20;

Portanto, deve-se saber como arquitetar, trabalhar com o banco antigo e usar projetos bons com mongo. A emissão de cupons fiscais eletrônicos (SAT), é um sistema padronizado no Brasil que só consegue ser lido usando banco de dados relacional. Portanto, em um sistema novo criado, as vezes vai ter a limitação de precisar de um banco de dados relacional, caso a empresa seja do ramo financeiro.&#x20;

## O que são e como funcionam clusters do tipo Réplica Set

Os clusters (conjunto de servidores) do tipo Réplica Set tem como objetivo promover a alta disponibilidade dos serviços de um banco de dados não relacional. Eles são um conjunto de nodes (3 ou mais) contendo um nó primário e um secundário, onde o nó primário recebe as informações, grava e copia elas para os demais nós, no objetivo de ter os dados repetidos como se fosse um backup.&#x20;

Os nós secundários funcionam apenas como modo leitura e estão lá para permitir falhas no nó primário, já que, se isso ocorrer, alguma máquina do nó secundário assume a posição de primário. A forma de assumir essa posição acontece através de uma “eleição”, em que a máquina com mais saúde (isso significa, geralmente, a com menos requisição) passa assumir o nó primário e fazer as mesmas funções (sai apenas do modo leitura).&#x20;

Aquele antigo nó primário é reinserido no cluster, mas agora como nó secundário e no modo leitura. Essas alterações são bem frequentes para promover a alta disponibilidade e desempenho dos dados.&#x20;

## Cluster M200 (níveis de cluster)&#x20;

Ao criar um projeto, você precisa fazer a instalação (deployment) de um banco de dados em um cluster. Ele fica em um servidor e você deve escolher qual as especificações dele. &#x20;

Três dados básicos para o cluster é a velocidade de leitura, tamanho da memória de processamento e armazenamento. O M0 é o cluster básico onde essas características são mínimas, é utilizado para estudos e testes. Esse cluster é compartilhado entre vários usuários, portanto, ele vai possuir diversas variações nas buscas e no desempenho por causa desse compartilhamento e limitação de recursos.&#x20;

Já o M200, é um cluster de alto desempenho. Ele é dedicado, ou seja, não compartilhado entre outros usuários. Isso torna-o extremamente poderoso, possui níveis de processamento e velocidade de leitura muito superior aos demais, o que o torna também mais caro. &#x20;

[^1]: Modelagem de acordo com a sua cabeça de quem projetou e não como o computador trabalha.

[^2]: Isso pode causar repetição de dados o que pode gerar um ar de bagunça.

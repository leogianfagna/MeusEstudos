# Memória

Todas as instruções, endereços e os dados necessários para executá-la precisam estar na memória RAM, que é carregado do disco. A memória conversa diretamente com a CPU, responsável por executar. As instruções precisam estar na memória RAM pois a CPU não conversa diretamente com o disco. Além do que, o acesso à memória é lento.

## Endereçamento físico e lógico

É preciso proteger o acesso à memória. Um processo só pode acessar a memória que pertence à ele. Por isso existem os endereços lógicos (ou virtuais) e os endereços físicos, pois um processo acredita que está sozinho na memória.

Exemplo de endereço virtual/lógico: compilar dois códigos ao mesmo tempo e imprimir o endereço de uma variável primitiva vai resultar em endereços iguais. Isso é possível pois na verdade esse endereço impresso é o virtual e não o verdadeiro (o físico). Esse endereço é gerado pela CPU sendo que o físico está na RAM.

### MMU (Memory-Management Unit)

É um disposito que está entre a CPU e a memória que faz a tradução de um endereço virtual para o físico. Por ser um tradutor, ele faz com que a CPU nunca saiba de qual endereço de fato veio a instrução.

<figure><img src="../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

O MMU engloba os registradores, como pode ser visto acima. É nos registradores que ficam armazenados a base e o limite de onde estão os processos, que esses dados serão usados para fazer o mapeamento.

<figure><img src="../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

## Memória compartilhada

A **memória principal** do sistema precisa ser compartilhada entre os processos do **sistema operacional** e os **processos de usuários**. Como os **recursos de memória são limitados**, é essencial que essa memória seja **alocada de maneira eficiente** para garantir o bom funcionamento do sistema.

### Alocação contígua

A **alocação contígua** é uma forma de organizar a memória de forma que cada processo receba um A **alocação contígua de memória** é uma técnica onde a memória é dividida em partições, uma para o sistema operacional e outra para os processos de usuários, com cada processo recebendo uma área contínua de memória.

Essa alocação é gerenciada de forma segura usando **registradores de realocação**, que delimitam o espaço de cada processo. O objetivo é garantir a **eficiência no uso da memória** e a **segurança** entre os processos. Essa foto acima de base e limite é armazenado pelo registrador base e pelo registrador limite.

### Partições variáveis

Processos encerrando liberam a partição tornando-a livre e o sistema operacional mantém informação sobre quais partições estão alocadas e quais estão livres (as livres chamadas de <mark style="color:purple;">hole</mark>). Existem três tipos de alocações:

* first-fit: aloca no primeiro espaço que achar.
* best-fit: achar o espaço que tem mais ou menos o mesmo tamanho.&#x20;
* worst-fit: alocar onde mais tem espaço pois vai que precisa alocar mais.

Todas são uma escolha ruim pois, ou vão causar perda de espaço que poderia estar sendo usado para outros processos ou vão precisar de mais memória e não tem espaço lá. Esses problemas são chamados de <mark style="color:purple;">fragmentação</mark>.

### Fragmentação

* Interna: Há espaço para colocar um processo lá, mas depois de colocar vai sobrar um espaço que não vai servir para nada pois nada cabe lá.
* Externa: Somando os espaços livres, há memória suficiente mas não há um espaço contíguo suficiente para alocar.

<figure><img src="../../.gitbook/assets/image (2).png" alt=""><figcaption></figcaption></figure>

### Swapping

O **swapping** é uma técnica de gerenciamento de memória para **expandir a capacidade de memória disponível** de forma eficaz. Quando a memória física (RAM) de um sistema está cheia e o sistema precisa executar mais processos do que a memória pode suportar, o **swapping** permite que o sistema continue funcionando sem problemas.

Isso pois o sistema operacional reserva uma parte do disco sendo a área de swap e move os processos ociosos da memória RAM para lá quando a memória está cheia. O problema é que o disco é muito lento e fazer a memória RAM acessá-lo pode prejudicar o desempenho.&#x20;

Se um processo a ser escalonado estiver no disco, existe uma troca de contexto que pode ser muito grande. Em um exemplo prático onde processo com 100 MB de memória alocada, disco de 50 MB/s:

* 2 segundos para tirar um processo de 100 MB e mandar pro disco.
* 2 segundos para trazer um processo de 100 MB do disco.
* 4 segundos da troca de contexto só para swap.

## Paginação

Para evitar a <mark style="color:purple;">fragmentação</mark> e a necessidade de usar blocos de memória contíguos, usamos a paginação. Consiste em:

* <mark style="color:blue;">Dividir a memória virtual em páginas</mark> (igual caderno, com tamanho fixo e previsível).
* Dividir a memória física em quadros, também com todos do mesmo tamanho.
* Cada quadro pode armazenar uma página daquele caderno virtual. Então para N páginas temos N quadros.

> O endereço virtual aponta para um dado de uma página que está em um quadro.

Qualquer página da CPU pode estar em qualquer quadro da RAM. A tabela de páginas faz a tradução das páginas para os quadros, sendo basicamente um sumário de onde está cada página. Esse sumário fica em algum lugar da memória.

### Tradução de endereços

O número lógico é dividido em:

* Número da página (índice para o sumário)
* Deslocamento: combinado com o endereço base para definir o endereço físico enviado para a MMU. Significa o quanto está dentro de uma página

<figure><img src="../../.gitbook/assets/image (3).png" alt=""><figcaption></figcaption></figure>

A paginação começa definindo os espaços entre páginas e quadros, precisa ter o mesmo espaço em um e depois em outro.

<figure><img src="../../.gitbook/assets/image (4).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/image (5).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/image (6).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/image (7).png" alt=""><figcaption></figcaption></figure>

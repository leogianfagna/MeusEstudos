# Memória

Todas as instruções, endereços e os dados necessários para executá-la precisam estar na memória RAM, que é carregado do disco. A memória conversa diretamente com a CPU, responsável por executar. As instruções precisam estar na memória RAM pois a CPU não conversa diretamente com o disco. Além do que, o acesso à memória é lento.

## Endereçamento físico e lógico

<mark style="color:purple;">Memória física</mark> é uma dimensão com vários endereços gerados pela CPU. Já a <mark style="color:purple;">memória virtual</mark> é inventada e não existe, é apenas uma abstração para que os processos funcionem pois os processos acham que estão sozinhos na memória. Essa memória é <mark style="color:blue;">traduzida e dividida em páginas</mark>, feito pela MMU explicado a seguir.

O endereçamento físico e lógico é composto pelo número da página[^1] ou quadro[^2] e o deslocamento. O deslocamento significa o quão está dentro, ou seja, ele é limitado pelo tamanho da página/quadro.

#### Cálculo do endereçamento

A página ou o quadro vai precisar informar quantas palavras cabem dentro, por exemplo: 1024 palavras. Tendo em vista que cada palavra ocupa 4KB, podemos fazer a seguinte conta:

<figure><img src="../../../.gitbook/assets/calculo de enderecamento.png" alt=""><figcaption></figcaption></figure>

> Exemplo de endereço virtual/lógico: compilar dois códigos ao mesmo tempo e imprimir o endereço de uma variável primitiva vai resultar em endereços iguais. Isso é possível pois na verdade esse endereço impresso é o virtual e não o verdadeiro (o físico). Esse endereço é gerado pela CPU sendo que o físico está na RAM.

### MMU (Memory-Management Unit)

É um disposito que está entre a CPU e a memória que faz a <mark style="color:blue;">tradução de um endereço virtual para o físico</mark> usando a [<mark style="color:purple;">TLB</mark>](#user-content-fn-3)[^3]. Por ser um tradutor, ele faz com que a CPU nunca saiba de qual endereço de fato veio a instrução.

<figure><img src="../../../.gitbook/assets/image (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

O MMU engloba os registradores, como pode ser visto acima. É nos registradores que ficam armazenados a base e o limite de onde estão os processos, que esses dados serão usados para fazer o mapeamento.

<figure><img src="../../../.gitbook/assets/image (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

## Memória compartilhada

A **memória principal** do sistema precisa ser compartilhada entre os processos do **sistema operacional** e os **processos de usuários**. Como os **recursos de memória são limitados**, é essencial que essa memória seja **alocada de maneira eficiente** para garantir o bom funcionamento do sistema.

### Alocação contígua

A **alocação contígua de memória** é uma técnica onde a memória é dividida em partições, uma para o sistema operacional e outra para os processos de usuários, com cada processo recebendo uma área contínua de memória.

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

<figure><img src="../../../.gitbook/assets/image (2) (1) (1).png" alt=""><figcaption></figcaption></figure>

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

É por conta disso que o dois processos separados podem compartilhar um espaço de memória em comum. Apesar dos dois processos estarem compartilhando a mesma memória física, na memória virtual, eles estão identificados em páginas virtuais diferentes. Exemplo:

* **Processo A**: Página virtual 3 mapeada para o quadro físico 5.
* **Processo B**: Página virtual 7 mapeada para o mesmo quadro físico 5.

### Tradução de endereços

O número lógico é dividido em:

* Número da página (índice para o sumário)
* Deslocamento: combinado com o endereço base para definir o endereço físico enviado para a MMU. Significa o quanto está dentro de uma página

<figure><img src="../../../.gitbook/assets/image (3) (1).png" alt=""><figcaption></figcaption></figure>

A paginação começa definindo os espaços entre páginas e quadros, precisa ter o mesmo espaço em um e depois em outro.

<figure><img src="../../../.gitbook/assets/image (4) (1).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/image (5) (1).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/image (6).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/image (7).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/tradução de endereços na paginação.png" alt=""><figcaption></figcaption></figure>

### Implementação tabela de páginas

Veja nessa página abaixo detalhadamente como fazer a implementação da tabela de páginas, também utilizada no [exercício 11 da lista](../exercicios-prova-2.md#id-11-as-tabelas-a-seguir-mostram-o-estado-atual-de-um-sistema-de-memoria-virtual-em-que-o-tamanho-de-u).

{% content-ref url="implementacao-tabela-de-paginas.md" %}
[implementacao-tabela-de-paginas.md](implementacao-tabela-de-paginas.md)
{% endcontent-ref %}

Teoricamente, agora existe um problema pois o sumário está na RAM, então a CPU precisa acessar a memória duas vezes (uma vez pro dado e outra pra resgatar a tabela). Como acessar duas vezes é um problema e a tabela sempre mantém **razoavelmente** fixa, podemos resolver isso utilizando cache.

Basicamente, resgatamos uma parte dessa tabela que são as páginas mais acessadas e colocamos em um cache dentro da MMU. Esse cache de tabela de páginas se chama <mark style="color:purple;">**TLB**</mark> (Translation Look-Aside Buffer). Fisicamente, ficaria assim:

<figure><img src="../../../.gitbook/assets/TLB fisicamente.png" alt="" width="375"><figcaption></figcaption></figure>

E agora que sabemos como fica, podemos visualizar o hardware final:

<figure><img src="../../../.gitbook/assets/hardware com tlb.png" alt=""><figcaption></figcaption></figure>

A TLB é bem pequena então não cabe todos os dados. Por conta disso existe uma <mark style="color:purple;">política de substituíção</mark> para que novos dados possam entrar.

### Paginação sob demanda

Não é necessário carregar todo o código na memória e precisa apenas a linha de código que está sendo executada. Além disso, existem funções e tratamentos de erros que podem nunca ser executadas (exceptions, funções não chamadas, etc). Isso quer dizer que existe uma grande parte da aplicação que você não precisa <mark style="color:red;">agora</mark>.

Se não precisa agora não precisa carregar na memória. Assim entra o conceito de paginação sob demanda que consiste <mark style="color:blue;">não trazer se não necessário</mark>. Quem cuida disso é o sistema operacional.

Esse conceito só funciona por causa da **memória virtual**, pois ela é capaz de apontar para uma página que existe mas não está na memória, e consegue trazer quando precisa. Outro fator da memória virtual que torna isso capaz é o fato dela poder ser maior que a memória física:

<figure><img src="../../../.gitbook/assets/tamanho memória virtual.png" alt="" width="444"><figcaption></figcaption></figure>

#### Bit de validade

A trocação de páginas entre memória e disco leva algumas operações:

* Fazer referência: ao precisar de uma página.
* Abortar: caso a página seja inválida.
* Trazer para a memória: caso a página não esteja lá.

Para conseguir distinguir, cada página que entra na memória tem um bit de validade (`v` para válida se estiver na memória e `i` para inválida caso não esteja), iniciando todas com `i`. Quando a MMU está fazendo a tradução, se ela encontra o bit `i`, isso simboliza um <mark style="color:purple;">**page fault**</mark>.

### Page fault

Simboliza quando a <mark style="color:blue;">página não está na memória</mark> e é preciso lidar com isso. A ideia é fazer o máximo possível enquanto está em uma página antes de precisar pular para uma próxima.

#### Lidar com o page fault

<figure><img src="../../../.gitbook/assets/lidar com page fault.png" alt=""><figcaption></figcaption></figure>

Isso não considerou se não houver espaço na memória. Caso aconteça, vai requerer substituição de páginas: escolhe uma página que não é modificada e não vai precisar em um futuro próximo. Mas não é possível prever o futuro. Portanto, esse problema será trabalhado em <mark style="color:purple;">substituição de páginas</mark>.

### Substituição de páginas

A substituição de páginas acontece quando não tem mais espaço na <mark style="color:orange;">memória física</mark> para receber uma página. Isso não implica em memória completamente cheia mas sim em espaço insuficiente para a página de um determinado processo.

O algoritmo de substituição de página faz apenas a escolha da página que vai embora. Essa página se chama <mark style="color:purple;">vítima</mark>. Se ela vai conceder seu espaço, é necessário reescrevê-la no disco, o que é algo lento e por isso esse algoritmo precisa escolher corretamente.

O pensamento de como esse algoritmo vai funcionar pode ser feito de algumas maneiras, tendo em vista a presença das páginas no disco (números em cima) e a forma que vamos substituir as páginas na memória (números em colunas em baixo):

#### FIFO (formato fila)

A primeira página a ter chego na memória será a primeira a sair. Vemos em <mark style="color:red;">vermelho</mark> o número que sai, começando pelo 7 pois ele foi o primeiro a chegar, em seguida do zero e assim sucessivamente. A barra reta significa que não houve mudança na memória, vemos que o zero foi solicitado mas ele já está na memória, então nada a ser feito.



<figure><img src="../../../.gitbook/assets/substituição de páginas fifo.png" alt=""><figcaption></figcaption></figure>

A contagem de page fault equivale ao número de vezes que precisou colocar uma página do disco para a memória, ou seja, basta contar as <mark style="color:blue;">colunas que não são barras verticais</mark>. Neste caso, temos 8 pages fault.

#### O modelo ótimo

Se pegarmos o modelo acima e colocar 4 páginas ao invés de três, o page fault subiria de 9 para 10. O que deveria melhorar acabou piorando e isso é chamado de <mark style="color:purple;">Anomalia de Belady</mark>. Isso mostra que o FIFO não é uma boa ideia. Isso acontece porque, ele substitui páginas que vão ser usadas logo em seguidas.

A solução ótima seria substituir as páginas que estão mais distantes de serem utilizadas. Teoricamente, analisaria as páginas alocadas atualmente e identifica a que vai demorar mais para ser solicitada novamente. Essa página seria escolhida para substituir (vítima).

<figure><img src="../../../.gitbook/assets/substituição de páginas ótimo.png" alt=""><figcaption></figcaption></figure>

No primeiro exemplo, o momento que vai precisar ser substituído é na "terceira casa". Então, neste momento é necessário avaliar quem será a vítima. Como o 7 está o mais distante de ser usado, ele será o escolhido. Fazer isso para cada vez que precisa ter uma troca.

Para ter noção, esse mesmo exemplo com FIFO daria 15 page faults enquanto esse resulta em 9 page faults. Contudo, mesmo com essa otimização, o algoritmo ótimo é <mark style="color:red;">impossível de ser implementado</mark> pois essa sequência de páginas não existe (futuro, não sabe quando vai usar tal página).

Já que ele não é possível implementar, ele pode ser usado após que esse processo finalizou para calcular e analisar como poderia ter sido melhor, servindo apenas como um <mark style="color:blue;">**parâmetro de comparação**</mark>.

#### LRU (Menos recente utilizado)

Se não podemos olhar para o futuro, vamos olhar para o passado. Vamos pensar em substituir aqueles que faz mais tempo que utilizamos pois uma probabilidade diz que, quanto mais tempo faz que usamos uma página, mais distante ela estará de ser utilizada novamente.

<figure><img src="../../../.gitbook/assets/substituição de páginas lru.png" alt=""><figcaption></figcaption></figure>

Este exemplo final mostra que:

* Horrível com 15 page fault.
* Ótimo com 9 page fault.
* LRU com 12 page fault.

#### Aproximações do LRU (algoritmo da Segunda Chance)

Apesar da implementação do LRU ser possível, é um algoritmo complicado pois exige ficar salvando o tempo em que cada página foi utilizada, exigindo um hardware especial.

Então temos essa outra alternativa usando <mark style="color:purple;">bit de referência</mark>. Seu objetivo é <mark style="color:blue;">não mover uma página que foi acessada recentemente</mark>, dando a ideia de "segunda chance de se manter na memória". Basicamente ele funciona dessa forma:

* Todas as páginas iniciam com o bit zero.
* Uma página acessada tem seu bit alterado para 1.
* Se a página já está escalonada e aparece novamente na solicitação, volta para zero.
* Substitui as páginas cujo bit é igual a zero.

<figure><img src="../../../.gitbook/assets/substituição de páginas com bit validade.png" alt=""><figcaption></figcaption></figure>

#### Segunda chance melhorado

Esse algoritmo inclui um segundo bit para não mover uma página que foi modificada. Assim, tem dois bits e um conjunto de quatro possibilidades:

1. (0, 0) nem usado, nem modificado – melhor página para substituir.
2. (0, 1) não usado, mas modificado – não tão bom, precisa primeiro escrever no disco.
3. (1, 0) usado recentemente mas não modificado – deve ser usado de novo logo.
4. (1, 1) usado e modificado – pior candidato.

Esse algoritmo entrega ainda melhores candidatos de páginas vítimas. Contudo, esse algoritmo <mark style="color:red;">não é possível escrever na prática</mark>, portanto, não precisamos se importar muito com ele.

[^1]: A lógica/virtual é dividida em páginas.

[^2]: A física é dividida em quadros.

[^3]: Guarda uma parte da <mark style="color:purple;">tabela de páginas</mark>. A tabela de páginas é um mapeamento presente na memória RAM que será visto a seguir. Não existe nenhuma relação matemática entre as duas memórias.

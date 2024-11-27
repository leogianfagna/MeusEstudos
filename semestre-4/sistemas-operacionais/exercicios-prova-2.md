# Exercícios prova 2

## Gerenciamento de arquivos

#### 1) Defina e diferencie formatação física, particionamento e formatação lógica.

Formatação física é aquela feita pelo fabricante do disco, dividindo o conjunto de cilindros em trilhas e setores fisicamente. Todo esse conjunto faz parte da memória do disco e o particionamento é a divisão dela em partes específicas para que o sistema operacional guarde suas próprias estruturas. A formatação lógica é a que prepara cada particionamento feito organizando os dados.

#### 2) Explique a diferença entre estruturas de diretório em um único nível, em árvore e em grafo. Apenas a estrutura em grafo permite links. Que tipo de considerações adicionais de implementação os links podem trazer?

Estruturas de diretório são uma coleção de dados sobre arquivos que diz como que eles estão salvos e organizados.

* Único nível: mantém todos os arquivos em um único diretório.
* Árvore: permite diversos sub-diretórios organizados hierarquicamente.
* Grafo: segue a lógica da árvore mas permite múltiplos caminhos para o mesmo diretório.

Uma consideração adicional para links é que o mesmo diretório pode estar presente em vários outros. Eles podem causar loops e devem se manter sincronizados com os outros.

#### 3) Um sistema Linux possui quatro usuários humanos: alan, bruna, celso e deise. Para cada usuário, existe um grupo de mesmo nome do qual apenas o respectivo usuário faz parte. Além desses grupos, alan e deise são membros de um grupo chamado professores, e bruna e celso fazem parte do grupo alunos. A tabela abaixo indica o resultado da listagem de um diretório qualquer dentro desse sistema, informando as entradas e seus respectivos proprietários, grupos e permissões de acesso em formato octal.

<figure><img src="../../.gitbook/assets/ex prova de permissoes.png" alt=""><figcaption></figcaption></figure>

Cada um dos quatro usuários tentou executar a lista de comandos a seguir dentro do diretório listado. Indique, para cada comando e cada usuário, quais foram executados com sucesso e quais falharam por falta de permissão de acesso. Para os que falharam, indique também qual foi o tipo de acesso que falhou (leitura, escrita ou execução).

* a) `mkdir pasta`: Escrever diretório.
* b) `./script.sh`: Executar script.
* c) `rm slides_proj.pptx`: Escrever diretório.
* d) `cat notas.csv > teste.txt`: Ler notas + escrever teste.
* e) `cp trabalho.pdf trab2.pdf`: Escrever diretório.

<table><thead><tr><th width="256">Comando</th><th>Alan</th><th>Bruna</th><th>Celso</th><th>Deise</th></tr></thead><tbody><tr><td>mkdir pasta</td><td><span data-gb-custom-inline data-tag="emoji" data-code="2705">✅</span></td><td>W</td><td>W</td><td><span data-gb-custom-inline data-tag="emoji" data-code="2705">✅</span></td></tr><tr><td>./script.sh</td><td>X</td><td>X</td><td>X</td><td>X</td></tr><tr><td>rm slides_proj.pptx</td><td><span data-gb-custom-inline data-tag="emoji" data-code="2705">✅</span></td><td>W</td><td>W</td><td><span data-gb-custom-inline data-tag="emoji" data-code="2705">✅</span></td></tr><tr><td>cat notas.csv > teste.txt</td><td>W</td><td>R</td><td>R</td><td><span data-gb-custom-inline data-tag="emoji" data-code="2705">✅</span></td></tr><tr><td>cp trabalho.pdf trab2.pdf</td><td><span data-gb-custom-inline data-tag="emoji" data-code="2705">✅</span></td><td>W</td><td>W</td><td><span data-gb-custom-inline data-tag="emoji" data-code="2705">✅</span></td></tr></tbody></table>

#### 4) Explique e diferencie os modos de acesso de Entrada/Saída programada, Entrada/Saída guiada por interrupção e Acesso Direto à Memória (DMA).

São formas como o sistema operacional interage com os dispositivos de entrada e saída, onde na programada ele fica checando constantemente o sinal de entrada (polling, que barra outras tarefas), a guiada por interrupção o dispositivo envia um sinal quando pronto, mas pode interromper um processo atual e a DMA é quando um sistema E/S é detectado, a sua instrução é movida para a memória para ser executada na fila quando o processador estiver disponível, não interrompendo nada.

#### 5) Explique e diferencie as funções de Buffering, Caching e Spooling do subsistema de Entrada/Saída.

Subsistemas de E/S refere-se a parte do sistema operacional que lida com esses dispositivos, sendo o buffering armazenar dados que estão sendo transferidos e processados na memória RAM, o caching guardar cópia de dados em armazenamentos mais rápidos como cache ou RAM e o spooling guardar tarefas futuras em uma fila para ser escalonado sem causar sobrecarga se o dispositivo só aceitar uma tarefa por vez.

#### 6) O espaço de endereçamento lógico de um sistema tem 64 páginas de 1024 palavras. O tamanho da palavra é de 32 bits, e um endereço de memória único referencia um byte. A memória lógica é mapeada para uma memória física com capacidade de 32 frames. Qual é o tamanho, em bits, dos endereços lógico e físico para esse sistema? Mostre a divisão de cada endereço em número da página, número do frame, deslocamento dentro da página e deslocamento dentro do frame, conforme cada caso.

<figure><img src="../../.gitbook/assets/resolucao ex enderecamento.png" alt=""><figcaption></figcaption></figure>

#### 7) Explique o que é swapping e por que ele é um fator limitante importante no desempenho de sistemas de memória. Se swapping atrapalha o desempenho, então por que ele é extensivamente utilizado?

Swapping é extensivamente utilizado pois ele pode resolver problemas de memória RAM cheia, extendendo seu tamanho utilizando o disco para armazenar processos ociosos. Algo muito importante que vai deixar o programa sempre funcional. Mas é limitante pelo fato do disco ser muito lento e o acesso para armazenar e resgatar processos do disco pode ser excessivamente lento.

#### 8) Descreva como dois processos separados podem compartilhar um espaço de memória em comum utilizando paginação simples.

Eles podem compartilhar o mesmo espaço de memória pois a paginação cria uma memória virtual que é separada em páginas. Os processos que podem estar no mesmo pedaço de memória física, estão entendidos como separados por causa da memória lógica. Na memória física eles estão no mesmo quadro mas na memória lógica estão em quadro diferentes, resolvendo aquele problema dos processos acharem que estão sozinhos na memória.

#### 9) Um sistema de gerência de memória utiliza para alocação uma técnica de alocação de partições em memória física. Em um determinado momento, o sistema possui áreas livres com os seguintes tamanhos, nessa ordem: 10 KB, 4 KB, 20 KB, 19 KB, 27 KB, 9 KB, 12 KB, 13 KB e 15 KB. Um novo processo deve carregar 12 KB de dados em memória. (a) Em qual das partições o processo será alocado considerando as estratégias de first-fit, best-fit e worst-fit? Justifique, definindo cada uma das estratégias. (b) Dê motivos e/ou exemplos de situações em que cada uma das três estratégias de first-fit, best-fit e worst-fit poderia ser vantajosa.

a) Best-fit seria alocado em 12KB por ser exatamente o mesmo tamanho. First-fit seria alocado em 20KB por ser o primeiro armazenamento que ele pode caber e o Worst-fit seria nos 27KB, por ser maior e ter a filosofia de que o processo vai crescer e vai exigir mais espaço depois.

b) Best-fit é vantajoso em casos que é possível saber que o processo não vai expandir de tamanho. Worst-fit é vantajoso em modo geral pois geralmente os processos tendem a crescerem e exigirem mais espaços. First-fit é vantajoso em casos que precisam de muita rapidez pois ele não analisa o restante e faz comparações.

#### 10) Explique o que é um Page Fault e como esse tipo de exceção é tratado pelo Sistema Operacional.

Page-fault é quando a MMU não encontra a página para resgatar instruções da memória lógica na TLB ou na tabela de páginas na memória RAM, resultando possivelmente que ela esteja no disco e precisa passar para a TLB.

A página deve estar pelo menos na tabela de páginas indicando sua existência. Se o bit for inválido e der page fault, deve procurar no disco pela página, trazer para a TLB alocando memória e é necessário atualizar o número do quadro referência áquela página, pois agora foi alocado um novo e é preciso atualizar.

#### 11) As tabelas a seguir mostram o estado atual de um sistema de memória virtual em que o tamanho de uma página é 4 KB. A TLB armazena 4 entradas, com substituição LRU. A coluna V na Tabela de Páginas é o bit de validade, em que 1 indica que a página é válida. Entradas que não aparecem na tabela acima têm bit de validade 0. A partir desse estado, o processador acoplado ao sistema requisita a seguinte sequência de endereços virtuais:&#x20;

```
23572 – 20000 – 13002 – 30000 – 5302 – 3504 – 28888 – 1500 – 37500 – 24000
```

#### Indique quais acessos são resolvidos diretamente pela MMU, quais necessitam de auxílio do Sistema Operacional e quais resultam em Page Fault. Mostre o estado final da TLB e Tabela de Páginas após a sequência de acessos. Ao trazer páginas do disco para a memória principal, aloque-as consecutivamente a partir do frame 16.

<figure><img src="../../.gitbook/assets/relosucao ex memoria virtual.png" alt=""><figcaption></figcaption></figure>

#### 12) Considerando a sequência de acessos a páginas 1 – 2 – 3 – 4 – 2 – 1 – 5 – 6 – 2 – 1 – 2 – 3 – 7 – 6 – 3 – 2 – 1 – 2 – 3 – 6 em uma memória inicialmente vazia. Mostre o resultado final de substituição de páginas e o número de Page Faults utilizando os algoritmos de FIFO e LRU supondo que a memória física comporte 3, 4 e 5 quadros

<figure><img src="../../.gitbook/assets/resolucao fifo.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/resolucao lru.png" alt=""><figcaption></figcaption></figure>

#### 13) Explique o funcionamento e a necessidade do Algoritmo da Segunda Chance para substituição de páginas.

Esse algoritmo vira uma necessidade pois o FIFO não é tão eficiente pela grande quantidade de page faults e o LRU exige uma enorme implementação por traz e desempenho, por ficar sempre comparando o histório de uso de quadros e atualizando quem foi usado recentemente.

Esse novo algoritmo funciona através de um bit de referência para cada página, alterando esse bit toda vez que uma página entrar. Seu objetivo é não substituir uma página recém acessada, dando uma "segunda chance" dessa página se manter. Então, páginas com o bit de referência `um` não são substituídas e a substituição segue a filosofia do LRU.

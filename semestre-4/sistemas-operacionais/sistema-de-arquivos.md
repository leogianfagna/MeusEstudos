---
description: Exercícios 1 a 3 do exercícios de prova são sobre esse assunto.
---

# Sistema de arquivos

O disco rídigo é uma parte redonda com vários empilhados em cima dos outros formando um cilindro. Cada cilindro possui [trilhas e setores](#user-content-fn-1)[^1] com cada setor possuindo geralmente 512K de dados. Essa estrutura descrita, que é feita pelo fabricante, é denominada de <mark style="color:purple;">formatação de baixo nível ou formatação física</mark>.

Para usar o disco, o sistema operacional precisa guardar suas próprias estruturas. Para isso, o disco é dividido pelo processo de <mark style="color:purple;">particionamento</mark>, que vai dividí-lo em [seções específicas](#user-content-fn-2)[^2] para permitir que diferentes sistemas de arquivos coexistam.

Cada partição gerada é configurada pela <mark style="color:purple;">formatação lógica</mark>, onde o sistema operacional organiza o sistema de arquivos de uma partição para tornar cada partição utilizável.

> O disco realmente fica girando como se fosse um vinil, o que faz ele se tornar lento. O SSD não repete esse mesmo comportamento.

## Arquivos

É um vetor grande de dados e o formato do arquivo, junto com vários outros [<mark style="color:purple;">atributos</mark>](#user-content-fn-3)[^3], indicam como esse vetor será lido e esses atributos são mantidos na <mark style="color:purple;">estrutura de diretórios.</mark>

A estrutura de diretórios está presente no disco. Ela é uma <mark style="color:blue;">coleção de dados</mark> com informações sobre outros arquivos, servindo como uma espécie de sumário de tradução. A estrutura de diretório é uma organização de como os arquivos estão salvos e pode ser organizada de diferentes formas:

> Os nomes dados em cada bloco podem ter sido renomeados pelo usuário ou automaticamente pela compilação de algum programa.

### Estrutura de diretórios de um nível

Todos arquivos estão contidos no mesmo diretório. Pode dar problema caso tenha mais de um usuário, colisão de nome e busca pouco eficiente.

<figure><img src="../../.gitbook/assets/estrutura de diretórios de um nível.png" alt=""><figcaption></figcaption></figure>

### Estrutura de diretórios de dois níveis

Cada usuário tem seu diretório pessoal, resolvendo apenas um dos problemas.

<figure><img src="../../.gitbook/assets/estrutura de diretórios de dois níveis.png" alt=""><figcaption></figcaption></figure>

### Estrutura de diretórios em árvores

Generaliza a estrutura de dois níveis onde os usuários podem criar sub-diretórios aumentando a organização e a árvore tem um diretório raiz. Isso faz com que, excluir um diretório vai fazer com que tudo o que está abaixo dele seja excluído também.

<figure><img src="../../.gitbook/assets/estrutura de diretórios em árvores.png" alt=""><figcaption></figcaption></figure>

### Estrutura de diretórios em grafos acíclicos

Permite [<mark style="color:purple;">links</mark>](#user-content-fn-4)[^4] de arquivos e/ou diretórios, tornando possível que o <mark style="color:blue;">mesmo diretório ou arquivo esteja presente em diferentes diretórios</mark>. Tem como seu maior problema não permitir ciclos, o que é necessário em alguns sistemas, por exemplo:

* O programa do diretório A necessita da biblioteca do diretório B criando uma dependência entre os dois.
* Em um sistema, depois de percorrer uma certa distância de diretórios, é necessário retroceder posições.

<figure><img src="../../.gitbook/assets/estrutura de diretórios em grafos acíclicos.png" alt=""><figcaption></figcaption></figure>

### Estrutura de diretórios em grafos gerais

É o sistema usado atualmente que permite os ciclos citados acima. O problema é que a presença de ciclos podem causar anomalias de busca exigindo algoritmos muito complexos e o conhecido Garbagge Collector.&#x20;

<figure><img src="../../.gitbook/assets/estrutura de diretórios em grafos gerais.png" alt=""><figcaption></figcaption></figure>

## Proteção

Existem atributos de proteção que falam quem pode mexer (ler, escrever, excutar e outros tipos de acesso) em um determinado arquivo. O Linux possui muitos usuários que podem estar sozinhos ou dentro de grupos e assim as permissões de arquivos <mark style="color:blue;">são configuradas para o dono, grupo e público</mark>. As permissões concedidas claramente podem ser diferentes para cada.

> Arquivos também podem pertencer a grupos.

### Modos de Acesso

Os **modos de acesso** referem-se aos <mark style="color:blue;">tipos de operações</mark> que um usuário pode realizar em um arquivo ou diretório que foram mencionados acima. Além dos 3 principais também há exclusão, listagem e acréscimo. Das 3 principais, vai ser condido os números `zero` ou `um` que significa se aquela pessoa/grupo tem ou não tem aquele modo de acesso.

### As permissões

Os modos de acesso foram definidos como `R` (read), `W` (write) e `X` (execute) e definido `zero` e `um` para cada modo e cada grupo. Vendo a imagem abaixo, podemos ver:

* O proprietário tem todas as permissões, resultando em `111`.
* Quem pertence ao grupo recebe o direito de ler e escrever, então foi colocado `110`.
* O público recebeu só de executar, então `001`.

<figure><img src="../../.gitbook/assets/permissões para grupos linux.png" alt=""><figcaption></figcaption></figure>

Depois de definido, converte os números binários em decimais. Binário `111` em decimal é `7`, `110` em decimal é `6` e `001` em decimal é `1`. É daí que surge os números 7, 6 e 1 de cada grupo. Se as permissões fossem diferentes, os números também seriam.

Por isso, se formou a sequência `761`. As permissões de arquivos são <mark style="color:blue;">representadas por um número composto de três dígitos</mark>, cada um para cada grupo. O comando `chmod 761 game` ajusta as permissões do arquivo ou diretório chamado "game".

> Veja no [exercício 3](exercicios-prova-2.md#id-3) um exemplo prático de permissões.

#### Resumo:

* As permissões de arquivos em Unix/Linux são configuradas para o dono, grupo e público.
* Cada classe (dono, grupo, público) pode ter permissões de leitura, escrita e execução.
* As permissões são representadas por números (ex: 761), e esses números controlam o que cada classe pode fazer com o arquivo ou diretório.

[^1]: Como foi visto na matéria de organização e arquitetura de computadores.

[^2]: Serão chamadas de partições, fisicamente é um grupo de cilindros.

[^3]: Nome, identificador, tipo, tamanho, localização, permissões e outras coisas.

[^4]: Pode se dizer compartilhamento.

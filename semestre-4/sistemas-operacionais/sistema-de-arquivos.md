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

Todos arquivos estão <mark style="color:blue;">contidos no mesmo diretório</mark>. Pode dar problema caso tenha mais de um usuário, colisão de nome e busca pouco eficiente.

<figure><img src="../../.gitbook/assets/estrutura de diretórios de um nível.png" alt=""><figcaption></figcaption></figure>

### Estrutura de diretórios de dois níveis

Cada <mark style="color:blue;">usuário tem seu diretório pessoal</mark>, resolvendo apenas um dos problemas.

<figure><img src="../../.gitbook/assets/estrutura de diretórios de dois níveis.png" alt=""><figcaption></figcaption></figure>

### Estrutura de diretórios em árvores

Existência de <mark style="color:blue;">sub-diretórios com organização hierarquica</mark> aumentando a organização e a árvore tem um diretório raiz. Isso faz com que, excluir um diretório vai fazer com que tudo o que está abaixo dele seja excluído também.

<figure><img src="../../.gitbook/assets/estrutura de diretórios em árvores.png" alt=""><figcaption></figcaption></figure>

### Estrutura de diretórios em grafos acíclicos

Lógica da árvore porém permite [<mark style="color:purple;">links</mark>](#user-content-fn-4)[^4] de arquivos e/ou diretórios, tornando possível que o <mark style="color:blue;">mesmo diretório ou arquivo esteja presente em diferentes diretórios</mark>. Tem como seu maior problema não permitir ciclos, o que é necessário em alguns sistemas, por exemplo:

* O programa do diretório A necessita da biblioteca do diretório B criando uma dependência entre os dois.
* Em um sistema, depois de percorrer uma certa distância de diretórios, é necessário retroceder posições.

<figure><img src="../../.gitbook/assets/estrutura de diretórios em grafos acíclicos.png" alt=""><figcaption></figcaption></figure>

### Estrutura de diretórios em grafos gerais

É o sistema usado atualmente que permite os ciclos citados acima. O problema é que a presença de ciclos podem causar anomalias de busca exigindo algoritmos muito complexos e o conhecido Garbagge Collector.&#x20;

<figure><img src="../../.gitbook/assets/estrutura de diretórios em grafos gerais.png" alt=""><figcaption></figcaption></figure>

## Proteção

Os atributos de proteção indicam o <mark style="color:purple;">modo de acesso</mark>, que diz quem pode `ler`, `escrever` e `executar` um determinado arquivo ou diretório. Esses atributos são configurados para três categorias de usuários: <mark style="color:blue;">dono do arquivo, um grupo específico e o público geral</mark>.&#x20;

### As permissões

Uma permissão é um número binário composto de três dígitos. Cada [<mark style="color:purple;">categoria de usuário</mark>](#user-content-fn-5)[^5] vai receber um número de zero à sete. Esse número recebido, convertido em binário e mantendo três casas, vai indicar qual modo de acesso a pessoa tem. Veja abaixo um exemplo disso:

<figure><img src="../../.gitbook/assets/convertendo permissões.png" alt="" width="563"><figcaption></figcaption></figure>

* O proprietário `111`: Tem todas as permissões pois todos são `1`.
* Quem pertence ao grupo `110`: Tem o direito de ler e escrever, mas não executar.
* O público `001`: Só há `1` no executar então só pode executar e mais nada.

Pode haver situações de fazer o caminho inverso, recebendo o número binário e querendo o número de permissão. Basta converter cada categoria de usuário e depois colocar na ordem os números convertidos. Podemos ver isso na prática com `chmod 761 game`, que são os números `7`, `6` e `1` convertidos e juntados.

### Conjunto de permissões

Se um arquivo como `notas.csv` recebe um número de permissão `760`, você precisa converter cada número individualmente para binário, gerando o resultado para cada categoria de usuário, assim:

* `script.sh` tem a permissão `760`, então:
  * `7` -> Dono do arquivo: O dono do arquivo pode fazer tudo pois resulta em `1 1 1`.
  * `6` -> Grupo: Membros do grupo só não poderão executar pois resulta em `1 1 0`.
  * `0` -> Público: Usuários não vão receber nada de permissão pois resulta em `0 0 0`.
* Portanto, isso significa que:
  * `Read`: Proprietário + grupo.
  * `Write`: Proprietário + grupo.
  * `Execute`: Proprietário.

<figure><img src="../../.gitbook/assets/conjunto de permissões.png" alt=""><figcaption></figcaption></figure>

> Veja no [exercício 3](exercicios-prova-2.md#id-3) um exemplo prático de permissões.

### Permissões necessárias

As permissões começam a ser solicitadas a partir da execução de comandos usando os arquivos em questão:

<table><thead><tr><th width="280">Comando</th><th>Descrição</th><th>Permissão</th></tr></thead><tbody><tr><td><code>mkdir pasta</code></td><td>Criar diretório.</td><td><code>write</code> no diretório.</td></tr><tr><td><code>./arquivo</code></td><td>Executar algo.</td><td><code>execute</code> no arquivo.</td></tr><tr><td><code>rm arquivo</code></td><td>Remover algo.</td><td><code>write</code> no diretório.</td></tr><tr><td><code>cat arquivo1 > arquivo2</code></td><td>Copia conteúdo de um arquivo para outro.</td><td><code>read</code> no arquivo1 e <code>write</code> no arquivo2.</td></tr><tr><td><code>cp arquivo arquivo</code></td><td>Copia o arquivo.</td><td><code>write</code> no diretório.</td></tr></tbody></table>

> **Extras:**
>
> 1. Arquivos também podem pertencer a grupos.
> 2. Além de leitura, escrita e execução, também existem `exclusão`, `listagem` e `acréscimo`.

[^1]: Como foi visto na matéria de organização e arquitetura de computadores.

[^2]: Serão chamadas de partições, fisicamente é um grupo de cilindros.

[^3]: Nome, identificador, tipo, tamanho, localização, permissões e outras coisas.

[^4]: Pode se dizer compartilhamento.

[^5]: * Um número para o dono do arquivo.
    * Outro número para o grupo.
    * Outro número para o público geral.

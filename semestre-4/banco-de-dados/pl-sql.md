---
description: Procedural Language SQL Based
---

# PL/SQL

Por que usar esta linguagem? Contextualizando, hoje em dia, banco de dados devem armazenar e recuperar dados e nenhuma lógica de negócios deve estar dentro do banco. Com essa linguagem, podemos escrever programas no Oracle. &#x20;

Essa linguagem é organizada em um bloco PL/SQL, que são um grupo de instruções tratados como uma unidade lógica. Eles são frequentemente usados para procedures, functions, cursors, etc. Eles possuem essa estrutura:&#x20;

* DECLARE: declaração de variáveis&#x20;
* BEGIN: onde vai o código&#x20;
* END: termina com ponto e vírgula&#x20;

<figure><img src="../../.gitbook/assets/estrutura do plsql.png" alt=""><figcaption></figcaption></figure>

> O DBMS Output (Database Management System Output) É um gerenciador de saída de dados do gerenciar do banco, como um log. É necessário habilitá-lo no SQL DEVELOPER, na opção View.

## Variáveis

Variáveis são objetos que armazenam e manipulam valores temporários durante a execução de um bloco. A seção DECLARE de um bloco PL/SQL tem como o objetivo declarar as variáveis.

A declaração da variável tem que ser o mais específico possível. Quando se trata de uma variável local, utiliza-se o prefixo “l\_” e quando se trata de uma global o prefixo “g\_”, por exemplo, “**l\_total\_sales**”. Também deve especificar o tipo de dado que recebe a variável.

<figure><img src="../../.gitbook/assets/variaveis em plsql.png" alt=""><figcaption></figcaption></figure>

Para atribuir um valor à ela, utiliza-se o operador “:=” ou também é possível fazer isso com o operador DEFAULT.

<figure><img src="../../.gitbook/assets/atribuicao de variaveis plsql.png" alt=""><figcaption></figcaption></figure>

É possível impor para a variável a declaração de NOT NULL, mas, neste caso, você deve atribuir um valor a variável logo na declaração dela.

<figure><img src="../../.gitbook/assets/not null variaveis plsql.png" alt=""><figcaption></figcaption></figure>

### Declarações ancoradas:

As variáveis normalmente têm o seu valor entregue baseado na consulta de uma tabela. Se o tipo de dado dessa tabela se altera, há a necessidade de alterar o código (tipo de valor da variável). Por conta disso, pode-se atribuir a essa variável logo de cara o mesmo tipo de dado da coluna da tabela.

Para isso, ao invés de declarar o tipo como anteriormente, utiliza-se o padrão: <mark style="color:orange;">`tabela.coluna%TYPE`</mark>. Um exemplo abaixo:

<figure><img src="../../.gitbook/assets/declaracoes ancoradas plsql.png" alt=""><figcaption></figcaption></figure>

## Procedimentos (procedures):

São criações de estruturas de códigos reutilizáveis. Podem ser muito simples como a criação de uma procedure que execute um INSERT na tabela. Além disso, as procedures são apenas chamadas em comandos e não retornam um valor.

Contém um cabeçalho para definir o nome e o tipo (parâmetro) de procedure que é. Os tipos de parâmetros são IN, OUT, INOUT.

O código de uma procedure é estruturado em:

1. Declaração (Diferentemente dos demais blocos, não começa com a estrutura **DECLARE** e sim com **IS**)
2. Parte executável
3. Exceções

<figure><img src="../../.gitbook/assets/procedures plsql.png" alt=""><figcaption></figcaption></figure>

### Cabeçalho da procedure:

Elas são especificadas para identificar se um parâmetro poderá ser lido ou gravado durante sua execução.

* `IN`: Parâmetro de entrada, a procedure pode utilizar o valor de entrada, mas não pode modifica-lo
* `OUT`: Parâmetro de saída, a procedure cria esse parâmetro para manipular e utilizar como saída
* `INOUT`: Parâmetro de entrada e saída, a procedure pode modificar o valor entrado e as alterações serão refletidas na saída

Como as procedures são criadas para executar uma tarefa, esses parâmetros são utilizados apenas para identificar como serão utilizadas as variáveis durante a execução dela. Por exemplo, supondo que uma procedure criada necessite receber um parâmetro na hora de execução pois o objetivo dela é sempre executar um SELECT na condição desse parâmetro recebido.

Neste caso, utiliza-se o parâmetro IN pois só vai receber a variável e encaixar na busca, desta forma:

<figure><img src="../../.gitbook/assets/cabeçalho procedure com in plsql.png" alt=""><figcaption></figcaption></figure>

Agora supondo que esse procedure utilize um SELECT INTO e vai usar essa variável em outros lugares dessa mesma procedure. Um SELECT INTO salva a busca em um nome de uma variável escolhida e, neste caso, pode passar como parâmetro o nome dessa variável usando o OUT. Por exemplo:

<figure><img src="../../.gitbook/assets/cabeçalho procedure com out plsql.png" alt=""><figcaption></figcaption></figure>

E no último caso, pode usar uma variável na procedure que tanto recebe um dado e pode ser alterada no meio da execução quanto ela mesmo pode fornecer um valor essencial para a procedure. Então por exemplo, ao chamar a procedure utiliza-se um parâmetro (variável) mas essa mesma variável vai ser alterada no meio do caminho, portanto, a procedure na hora da criação deve usar o INOUT. Por exemplo:

<figure><img src="../../.gitbook/assets/cabeçalho procedure com inout plsql.png" alt=""><figcaption></figcaption></figure>

## Funções

Funções são blocos de código que realizam uma tarefa específica e retornam um valor. Elas usam a mesma estrutura de código de uma procedure, mas neste caso, devem obrigatoriamente retornar um valor com RETURN.

Funções podem ser declaradas dentro de um bloco PL/SQL ou fora dele. Dentro de um bloco, você pode chamar funções para realizar tarefas específicas e retornar valores que podem ser utilizados no restante do bloco.

<figure><img src="../../.gitbook/assets/declaracao função plsql.png" alt=""><figcaption></figcaption></figure>

Algo notável é que durante a construção das funções, utiliza-se muito SELECT INTO para o resultado de uma certa busca ser usada como valor em uma variável escolhida.

## Bloco anônimo&#x20;

É um conjunto de instruções PL/SQL, mas que não possui um nome associado, assim como é nos cursores, funções, etc. Também possui a estrutura de DECLARE, BEGIN e END, mas só é executado uma vez quando invocado e não pode ser chamado novamente.&#x20;

<figure><img src="../../.gitbook/assets/image (11).png" alt=""><figcaption></figcaption></figure>

## IF-ELSE:

Estrutura condicional que permite executar diferentes blocos de código com base em uma condição. Sua formatação básica (fora de bloco) é:

```plsql
IF condition THEN
    statements
END IF;
```

O THEN significa o que irá ser executado caso o IF seja verdadeiro. Um exemplo básico seria:

<figure><img src="../../.gitbook/assets/ifelse plsql.png" alt=""><figcaption></figcaption></figure>

Todas as lógicas de código usados em uma outra linguagem que envolvam formatações condicionais também podem ser replicadas aqui. Isto é, operadores IF em cadeia, IF dentro de IF e também operadores para estabelecer duas condições, como condição\_1 e condição\_2 usando AND. Além disso, o ELSE IF padrão torna-se ELSIF na linguagem PL/SQL. Por exemplo:

<figure><img src="../../.gitbook/assets/elsif plsql.png" alt=""><figcaption></figcaption></figure>

## CASE-WHEN:

Estrutura condicional que é usada para controle condicional dentro de um bloco, permitindo avaliação de várias condições. Basicamente, pega o valor de uma variável e entre em uma série de condições que serão executadas caso seja verdadeiro.

Quando o SQL encontra sua primeira condição WHEN verdadeira, ele para de verificar as demais, assim como acontece em outras linguagens de programação. Essa estrutura também suporta o operador <mark style="color:red;">**ELSE**</mark>, para caso nenhuma tenha sido avaliada, igual ao “default” nas lógicas “switch case” de outras linguagens. Por exemplo:

<figure><img src="../../.gitbook/assets/case when plsql.png" alt=""><figcaption></figcaption></figure>

Também existe a opção de nada acontecer no ELSE, simbolizando que a estrutura CASE-WHEN não foi encontrada nenhum valor verdadeiro. Para isso:

```plsql
ELSE
    RAISE CASE_NOT_FOUND;
```

O WHEN se trata de uma condição, então também dupla condição para satisfazer como verdadeiro.

```plsql
WHEN n_sales >= 100000 AND n_sales < 200000 THEN
    n_comission := 0.15;
```

## LOOP-ENDLOOP:

Estrutura de loop que executa um bloco de código repetidamente até que uma condição seja atendida. Essa condição pode ser verificada com a estrutura IF-ELSE (e utilizando o operador EXIT) ou com uma nova sintaxe do loop EXIT WHEN. Por exemplo:

<figure><img src="../../.gitbook/assets/loop plsql 1.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/loop plsql 2.png" alt=""><figcaption></figcaption></figure>

Um detalhe muito importante é que normalmente utiliza-se o EXIT WHEN logo nas linhas de cima, ao abrir o LOOP. Contudo, as linhas após o EXIT WHEN fazem parte do código do loop. Neste exemplo acima, “Inside loop” faz parte da operação do loop e será executado repetidamente até que o loop termine.

## SELECT INTO:

A cláusula SELECT INTO é usada dentro de um bloco para armazenar o resultado de uma consulta em uma variável, permitindo o acesso e manipulação desses dados no restante do bloco como a forma da variável.

<figure><img src="../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

O tipo de retorno deve condizer com o tipo da variável, por exemplo, se a busca na tabela vai retornar várias linhas, a variável declarada para receber este valor deve ser do mesmo tipo. Para funcionar corretamente, há maneiras de já declarar automaticamente com o tipo que será retornado, por exemplo:

<figure><img src="../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

Lembrando que também é possível selecionar múltiplos dados pois, em uma busca no banco de dados, logo depois do operador SELECT é possível colocar mais de uma coluna na busca, como por exemplo SELECT NOME, ENDEREÇO, IDADE e assim é possível assimilar essas buscas em diferentes variáveis. Por exemplo:

<figure><img src="../../.gitbook/assets/image (2).png" alt=""><figcaption></figcaption></figure>

## Cursores (FETCH, OPEN, CLOSE):

Cursores são frequentemente declarados na seção DECLARE de um bloco. Eles são uma estrutura utilizada para percorrer conjuntos de resultados e processar dados linha por linha dentro do bloco. Lembrar da ideia de varrer resultados. A vida útil de um cursor consiste em OPEN, FETCH e CLOSE, seguindo o seguinte caminho:

<figure><img src="../../.gitbook/assets/ciclo de vida cursor plsql.png" alt=""><figcaption></figcaption></figure>

O cursor é criado em DECLARE e em seguida definindo o tipo de busca com a palavra-chave IS.

```plsql
CURSOR cursor_name IS query;
```

Abrir um cursor com OPEN significa o SQL executar a busca que está associado. A ação seguida de abertura do cursor é o FETCH, que significa atribuir os resultados da busca em uma variável (ou variáveis).

```plsql
FETCH cursor_name INTO variable_list;
```

Esse `variable_list` é declarado logo na seção DECLARE do código onde é atribuído a ele o mesmo tipo da coluna (ou não, depende do objetivo do código). Portanto, ele pode assumir a mesma forma da busca do cursor (por exemplo, <mark style="color:purple;">`%ROWTYPE`</mark>).

Em cada FETCH (lembrando que ele está em LOOP), o `variable_list` assume um NOVO VALOR. Ou seja, ele não é uma tabela ou algo do tipo e sim o valor retornado da busca declarada do cursor. Então, como que em cada LOOP um novo valor é atribuído a ele, deve-se criar as linhas de código do que se fazer com esse valor atribuído ainda no LOOP. Explicitado no último exemplo.

E por fim, fechar o cursor com CLOSE que significa liberar a memória alocada do sistema. Cursores declarados dentro de funções, blocos ou procedures irão fechar automaticamente após o final da execução da lógica.

### Atributos de cursores explícitos:

São 4 atributos que podem ser referenciados a um cursor, eles são usados para fazer tratamento de dados, por exemplo, quando o cursor terminou e é hora de sair do LOOP:

* `%ISOPEN`: TRUE ou FALSE, se o cursor está aberto ou não
* `%FOUND` ou `%NOTFOUND`: Isso pode retornar...
  * **NULL**: não foi aberto ainda (mas existe)
  * **TRUE**: se algo já foi buscado
  * **FALSE**: se nenhuma busca foi feita ainda
  * **INVALID\_CURSOR**: cursor inexistente
* `%ROWCOUNT`: número de linhas buscadas

Exemplo completo de cursores, explicação: na seção DECLARE é declarado um cursor com a sua busca no SQL. Logo após é declarado as variáveis que serão usadas sendo uma grande importante a **r\_sales**. Essa variável vai receber o mesmo formato do retorno do cursor, já que ela foi “tipada” como tal <mark style="color:purple;">`usando c_sales%ROWTYPE`</mark>.

Em BEGIN começa a estrutura do código onde a linha de crédito dos funcionários foi zerada para receber o novo crédito. Abrindo o cursor, o primeiro a se fazer é criar um LOOP dando FETCH do resultado do cursor na variável criada (r\_sales). Foi estabelecido a condição de saída do LOOP, que é quando o cursor não foi encontrado, ou seja, está vazio.

Depois disso criou-se um comando em SQL com o objetivo de atualizar os dados da coluna “credit\_limit” para o novo bônus. Em SET, o valor de “credit\_limit” ficou vazio pois ele será preenchido com o resultado do CASE WHEN que confere se a coluna “credit” da vez é maior que o número 1000000 (declarado na variável “l\_budget”).

Depois, completando o comando SQL, adicionou uma condição para a atualização para atualizar o funcionário correto. A variável r\_sales já possuía o ID do funcionário então pode-se utilizar <mark style="color:blue;">**r\_sales.customer\_id**</mark>. Com isso, o comando SQL já está completamente executado e pode sair do LOOP e fechar o cursor.

Depois existe um novo EXIT WHEN que foi criado em caso que o orçamento foi zerado. Vendo o código, temos dois EXIT WHEN mas ambos são para sair do mesmo LOOP. São dois por conta que são duas condições diferentes, mas eles poderiam estar em um mesmo comando utilizando uma condição OU para satisfazer um ou outro resultado (ou cursor vazio ou orçamento zerado).

<figure><img src="../../.gitbook/assets/image (3).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/image (5).png" alt=""><figcaption></figcaption></figure>

## Triggers

São um tipo de estrutura de blocos em PL/SQL chamados de triggers. São executados automaticamente quando um evento ocorre.

* DML (“Data manipulation language”): INSERT, UPDATE, DELETE
* DDL (“Data definition language”): CREATE, ALTER
* Eventos de sistema como reiniciar e ligar
* Eventos de usuário como log-in e log-ou.

A criação de um trigger consiste em um HEAD e um BODY onde o corpo BODY tem a mesma estrutura que um bloco anônimo. Ele é criado com a declaração CREATE TRIGGER.

As definições de quando um trigger é lançado ficam definidas no HEAD enquanto os disparos que o trigger irá realizar (ações e execuções) são definidas no campo BODY (no bloco). Uma estrutura pronta da criação de um novo trigger pode ser representada pelo seguinte exemplo:

<figure><img src="../../.gitbook/assets/image (6).png" alt=""><figcaption></figcaption></figure>

Lendo um trigger passo a passo, vamos supor o seguinte trigger criado:

<figure><img src="../../.gitbook/assets/triggers em plsql.png" alt=""><figcaption></figcaption></figure>

1. Cria o novo trigger com o nome inserido
2. Define quando esse trigger será disparado (BEFORE ou AFTER), no caso, depois de inserir ou deletar qualquer tipo de linha na tabela de clientes
   1. Nesse caso, fica claro que é um trigger criado para auditoria
   2. Pode se usar a barra vertical | para criar identificar um OU outro, ou seja, tanto antes ou quanto depois
3. Declara que o trigger será disparado para cada linha alterada, para auditar cada alteração
4. Cria um CASE-WHEN que vai definir a variável “l\_transaction” para um texto de acordo com o tipo de alteração que foi feito na tabela clientes
5. Executa o comando SQL que vai inserir uma nova linha na tabela com valores:
   1. Como é em uma tabela geral de auditoria, define manualmente o nome da tabela com aspas simples
   2. Usa a variável “l\_transaction” que mostra qual é o tipo de ação
   3. USER e SYSDATE são variáveis do próprio sistema

É possível especificar em qual coluna deve ser feito a modificação para o trigger ser disparado dessa forma:

<figure><img src="../../.gitbook/assets/image (7).png" alt=""><figcaption></figcaption></figure>

### Triggers em nível de instrução

O parâmetro FOR EACH ROW vai definir se o trigger será disparado para cada linha alterada, mas, se ele não for definido (é uma cláusula opcional) o gatilho será disparado apenas uma vez pela instrução executada.

Ele pode ser utilizado para várias funcionalidades, mas, uma ideia é para gerar exceções. Por exemplo, em um banco de dados de venda, o administrador quer bloquear qualquer tipo de alteração no banco durante os dias 28 e 31 do mês para fazer o fechamento. Para isso, é possível criar um trigger que, caso satisfaça as condições, retorne um erro ao usuário. Por exemplo:

<figure><img src="../../.gitbook/assets/image (8).png" alt=""><figcaption></figcaption></figure>

Nesse exemplo acima, utilizou a procedure RAISE\_APPLICATION\_ERROR para retornar um erro ao usuário e não fazer a alteração no banco de dados. Por isso, é importante saber que os triggers eles nem sempre são relacionados a modificações no banco e podem ser usados com outros propósitos, principalmente no modo de nível de instrução, onde não é executado para cada linha.

### Triggers em nível de linhas

Para aqueles triggers que são disparados linha por linha, é possível resgatar o valor antigo e novo dessa linha usando a sintaxe :OLD e :NEW seguido pelo nome da coluna. Por exemplo:

<figure><img src="../../.gitbook/assets/image (9).png" alt=""><figcaption></figcaption></figure>

Vale lembrar que há de se pensar se existe o valor antigo e o novo em determinadas situações, por exemplo, não terá o valor NEW depois de uma ação de DELETE ou o valor OLD em uma ação de INSERT. Como essas sintaxes são referenciadas externamente, necessita dos dois pontos na frente para utiliza-las.

Os triggers em FOR EACH ROW serão disparados várias vezes, dependendo do número de alterações. Por exemplo, se 1000 linhas foi alterada ele irá disparar mil vezes. Para aprimorar isso, podemos adicionar a condição WHEN para disparar somente nas ocorrências que queremos:

<figure><img src="../../.gitbook/assets/image (10).png" alt=""><figcaption></figcaption></figure>

Neste caso (dentro da condição), não são necessários os dois pontos. Lembrando que essa formatação está referenciando ao valor daquela coluna em específico, ou seja, um valor somente. Mas é possível conseguir fazer isso para a linha inteira, referenciando o valor antigo da linha e o novo. Para isso, utiliza-se REFERENCING e NEW. Neste exemplo:

<figure><img src="../../.gitbook/assets/referecing e new em triggers plsql.png" alt=""><figcaption></figcaption></figure>

Neste caso, está recebendo o valor da LINHA inteira antiga como OLD\_ROW e da nova após a modificação como NEW\_ROW e está utilizando esses valores para inserir a linha inteira na auditoria.

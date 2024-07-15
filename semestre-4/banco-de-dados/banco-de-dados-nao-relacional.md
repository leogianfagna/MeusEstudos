# Banco de dados não relacional

## Introdução ao MongoDB – primeira aula e conceitos

Um cluster consiste em computadores fracamente ou fortemente ligados que trabalham em conjunto, de modo que, em muitos aspectos, podem ser considerados como um único sistema.

<figure><img src="../../.gitbook/assets/cluster esquema.png" alt=""><figcaption></figcaption></figure>

Como no esquema, os dados chegam no primeiro que faz a cópia para os demais. Se esse computador dá problema, um secundário com mais saúde assume o lugar do primário. Quando o primeiro volta, ele volta como secundário pois está desatualizado. O primário sempre fica trocando em uma espécie de “eleição” em que a regra é baseada na saúde (menos requisição) do computador. &#x20;

Um nó de processamento é um conjunto de CPUs.&#x20;

## O que faz o Mongo Compass?&#x20;

O Mongo Compass é uma plataforma cliente. Ele tem a funcionalidade de fornecer ao usuário com uma interface gráfica amigável o acesso ao banco de dados criado através de uma string de conexão.&#x20;

Ele permite a execução de comandos, criação de coleções, inserção de dados, indexes e muitas outras funcionalidades para o desenvolvimento, controle e consulta dentro do banco de dados.&#x20;

Um ponto muito forte dessa interface é que ele consegue monitorar facilmente o desempenho das buscas, mostrando resultados detalhados como COLLSCAN e também a estrutura do banco, com o SCHEMA. &#x20;

## O que é o Mongo Atlas?&#x20;

Ele é um serviço de banco de dados fornecido pela MongoDB para hospedar os bancos de dados em um cluster, oferecendo uma string de conexão para acessar este banco.&#x20;

## Como carregar dados de exemplos no mongo atlas?&#x20;

Basta você acessar o seu banco de dados no Atlas dentro da organização criada. Uma vez acessado, ele terá opções como conexão, monitoramento, configurações e outras. Uma delas é o “load sample dataset”, onde diversas coleções para exemplos e estudos serão instaladas no banco de dados.&#x20;

## Criação do banco de dados no MongoDB

Ao criar o banco de dados, deve-se definir onde está localizado. Criar no mesmo país não é somente questão de latência. Tem a questão da legislação, sobre possuir informações de outros países (lei geral de progressão de dados). Caso, em um sistema complicado, use dados de diferentes países, deve-se criar cluster nas localizações de cada país.&#x20;

No site do Mongo, criamos uma organização chamada OLX e dentro dela um projeto chamado WEBSITE. O nome do cluster é o nome do banco, criamos o cluster M0 (grátis e para aprendizado).&#x20;

<figure><img src="../../.gitbook/assets/criar organização no mongo.png" alt=""><figcaption><p>Organização criada</p></figcaption></figure>

<figure><img src="../../.gitbook/assets/criar projeto no mongo.png" alt=""><figcaption><p>Criando projeto</p></figcaption></figure>

<figure><img src="../../.gitbook/assets/criar cluster.png" alt=""><figcaption><p>Criação do Cluster M0, o cluster tem o mesmo nome do projeto, por questão de facilidade</p></figcaption></figure>

Agora, para conectar-se, precisa usar uma string de conexão na plataforma MondoDB Compass. Nessa string, insere a senha do banco. Dentro desse programa, em “info”, é possível ver os clusters. Através dos endereços, é possível ver qual pertence ao nível primário, por ser o primeiro número.

## Infraestrutura do MongoDB&#x20;

Todo documento tem um object ID. Quando ver um $ em um documento significa algum comando específico do mongo, não do json.&#x20;

<figure><img src="../../.gitbook/assets/documento mongodb.png" alt=""><figcaption></figcaption></figure>

Mais de um cluster é necessário quando há produtos de diferentes países, já que dados de um país não pode se misturar com outro.

<figure><img src="../../.gitbook/assets/cluster nodes.png" alt=""><figcaption></figcaption></figure>

Em coleção, pode-se colocar qualquer tipo de arquivos de banco de dados. Isso pode ser problema caso coloque um arquivo que não é da mesma coleção. Para isso, criar uma validação para que um documento fora do lugar não possa ser adicionado.&#x20;

Os bancos “local” e “admin” são padrões e não devem ser mexidos, pois eles são chamados de instâncias (administração). A coleção local guarda um banco de logs.

<figure><img src="../../.gitbook/assets/estrutura de arquivos mongodb.png" alt=""><figcaption></figcaption></figure>

## Query documents no MongoDB – Operadores e consultas

Documentação [aqui ](https://www.mongodb.com/docs/manual/tutorial/query-documents/)para todos os tipos de consultas.

```mongodb
// Definição de caracteres
[] -> array
{} -> documento
```

### Operadores básicos

Os operadores podem ser vistos como um filtro para as consultas.

<table data-header-hidden><thead><tr><th width="116">Símbolo</th><th>Consulta</th></tr></thead><tbody><tr><td><a href="https://www.mongodb.com/pt-br/docs/manual/reference/operator/query/eq/#mongodb-query-op.-eq"><code>$eq</code></a></td><td>Corresponde aos valores que são iguais a um valor especificado.</td></tr><tr><td><a href="https://www.mongodb.com/pt-br/docs/manual/reference/operator/query/gt/#mongodb-query-op.-gt"><code>$gt</code></a></td><td>Corresponde aos valores que são maiores que um valor especificado.</td></tr><tr><td><a href="https://www.mongodb.com/pt-br/docs/manual/reference/operator/query/gte/#mongodb-query-op.-gte"><code>$gte</code></a></td><td>Corresponde aos valores que são maiores ou iguais a um valor especificado.</td></tr><tr><td><a href="https://www.mongodb.com/pt-br/docs/manual/reference/operator/query/in/#mongodb-query-op.-in"><code>$in</code></a></td><td>Corresponde a qualquer um dos valores especificados em uma array.</td></tr><tr><td><a href="https://www.mongodb.com/pt-br/docs/manual/reference/operator/query/lt/#mongodb-query-op.-lt"><code>$lt</code></a></td><td>Corresponde a valores que são menores do que um valor especificado.</td></tr><tr><td><a href="https://www.mongodb.com/pt-br/docs/manual/reference/operator/query/lte/#mongodb-query-op.-lte"><code>$lte</code></a></td><td>Corresponde a valores menores ou iguais a um valor especificado.</td></tr><tr><td><a href="https://www.mongodb.com/pt-br/docs/manual/reference/operator/query/ne/#mongodb-query-op.-ne"><code>$ne</code></a></td><td>Corresponde a todos os valores que não são iguais a um valor especificado.</td></tr><tr><td><a href="https://www.mongodb.com/pt-br/docs/manual/reference/operator/query/nin/#mongodb-query-op.-nin"><code>$nin</code></a></td><td>Não corresponde a nenhum dos valores especificados em uma array.</td></tr></tbody></table>

O operador <mark style="color:purple;">`$in`</mark> geralmente é usado para obter resultados do tipo OU em condições de array, ou seja, estão no mesmo campo e podem assumir vários valores. Já o $or, será usado para qualquer informação do documento (fora do array), indicando que pode ter várias condições.

<figure><img src="../../.gitbook/assets/operador $in mongodb.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/operador $or mongodb.png" alt=""><figcaption></figcaption></figure>

Condições do tipo AND por enquanto estão sendo trabalhadas sem operadores, sendo feito diretamente na busca. Por exemplo:

```mongodb
{ status: "A", qty: { $lt: 30 } }
```

### Consultas básicas&#x20;

Lembrar da precedência de importância. No exemplo seguinte, o status tem que ser A e o OR vem depois.&#x20;

<figure><img src="../../.gitbook/assets/primeiras consultas com mongodb.png" alt=""><figcaption><p>Primeiras consultas com Mongo.</p></figcaption></figure>

#### Corresponder com embedded documents

Neste caso, é uma fórmula que corresponde com o resultado. Deve estar na mesma ordem e com os mesmos resultados. É diferente de realizar uma consulta.

<figure><img src="../../.gitbook/assets/query embedded documents mongo.png" alt=""><figcaption></figcaption></figure>

#### Consultar dentro de um array (embedded documents)

Já aqui, consulta por resultados. Para procurar em campos específicos, utiliza-se da notação com ponto. Quando se trabalha com esse tipo de notação, o calmo e o embed document devem estar todos entre aspas.

```mongodb
{ "size.uom": "in" }
```

Operadores e lógicas de buscam também funcionam aqui, como as condições abaixo:

```mongodb
{ "size.h": { $lt: 15 } }
```

<figure><img src="../../.gitbook/assets/query array mongodb.png" alt=""><figcaption></figcaption></figure>

#### Consultar com options&#x20;

Uma ferramenta para você definir como ver os dados buscados, para uma maior facilidade. Em um exercício, quer consultar o preço de um determinado intervalo, mas que apareça somente os preços na consulta e oculte as demais informações.&#x20;

Para isso, ir ao campo Options e usar o número “1” para nas opções que deseja aparecer, ou “zero” para ocultar da busca. O “\_ID” sempre aparece nas buscas também, então para ocultá-lo é possível acrescentar <mark style="color:red;">`_id: 0`</mark>.&#x20;

<figure><img src="../../.gitbook/assets/filtros mongo 1.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/filtros mongo 2.png" alt=""><figcaption></figcaption></figure>

## Índices&#x20;

Qualquer banco de dados pode ter problemas de performance. Em uma análise, a primeira visão que se deve usar é se há um cluster de qualidade. Se a resposta for sim, há uma necessidade de performar as buscas.&#x20;

Índices são atalhos, aplicados para obter performance para mostrar onde está a informação. Na criação do banco de dados, essa coleção nasce com um índice de unicidade (ID) com o propósito de organizar os documentos em uma ordem (indexá-los).&#x20;

### Entendendo como eles funcionam&#x20;

Os dados que chegam são armazenados nos índices criados, fazendo com que uma consulta possa utilizar do índice e ao invés de analisar todos os documentos daquele banco, analise somente uma quantia que o índice guarda, poupando tempo.&#x20;

<figure><img src="../../.gitbook/assets/esquema indice banco de dados.png" alt=""><figcaption></figcaption></figure>

Ou seja, toda vez que tiver inserção de dados, os índices devem ser atualizados. Isso faz com que não seja uma boa prática ter vários índices. Criando um índice equivocado, o resultado pode ser no tempo de retorno já que retorna muitos documentos ou o banco pode ficar lento na hora de inserir o dado.&#x20;

Um bom exemplo de índice é aquele que se repetem bastante, por exemplo, restaurantes guardados em cidades pois o índice de cidade sempre vai estar lá presente. Agora, campos imprevisíveis como médias ou não repetidos como nome próprio não devem ser utilizados como índices.&#x20;

E pode ir mais profundamente para ter ainda menos documentos. Em certos casos, você pode criar um índice da cidade e vendas acima de uma certa quantia. A questão de projeto é: o que eu terei que consultar no banco? Assim pode-se pensar melhor em quais índices serem criados.&#x20;

### Entendendo como melhorar a busca (prática)

Identificando através do plano de execução da query (consulta).&#x20;

<figure><img src="../../.gitbook/assets/melhor performance mongodb.png" alt=""><figcaption></figcaption></figure>

Essa opção “Explain” cria uma consulta qualquer e executa para analisar o desempenho daquela consulta no banco. Aqui mora a maioria dos problemas de desempenho. Todo banco de dados traça uma estratégia de busca em uma consulta, mas nem sempre ela é a melhor. &#x20;

> COLLSCAN: collection scan&#x20;

Quando você vê isso, está com problema. Essa ferramenta mostra quanto tempo está demorando para realizar a busca. Se não houver índice disponível naquela consulta, o banco traça sua própria estratégia de busca. No COLLSCAN, ele mostrou que precisou de 5ms para ler todos os arquivos. Já na busca, mostrou que demorou 38ms para achar os documentos. &#x20;

Abaixo, vamos criar o índice cuisine com o identificador 1 (crescente).

<figure><img src="../../.gitbook/assets/criar indice mongodb.png" alt=""><figcaption></figcaption></figure>

Depois disso, realizar uma nova busca e ver os resultados. Foi possível enxergar a aparição do <mark style="color:green;">**FEFTCH**</mark> e <mark style="color:green;">**IXSCAN**</mark>, que significam que a busca está boa e otimizada.

<figure><img src="../../.gitbook/assets/resultado otimizado mongodb.png" alt=""><figcaption></figcaption></figure>

## Agregações em MongoDB&#x20;

Agregações são retorno de múltiplos valores de vários documentos em um agregado só. Agregações por pipeline consistem em um ou mais etapas. Elas são feitas em um array, inserindo um passo a passo dentro dela.&#x20;

No comando da array, utiliza-se <mark style="color:purple;">`db.[nome da coleção].aggregate`</mark>. Qualquer tipo de consulta sempre inicia com as condições, se tiver.

<figure><img src="../../.gitbook/assets/agregacoes em mongodb.png" alt=""><figcaption></figcaption></figure>

## Traduzindo um comando SQL para Mongo&#x20;

Abaixo será utilizado uma função de agregação em SQL e logo traduzido para o MongoDB.&#x20;

<figure><img src="../../.gitbook/assets/exemplo de query sql.png" alt=""><figcaption></figcaption></figure>

O <mark style="color:red;">`AS`</mark> é necessário para quando você está fazendo um agregado de resultados. Tem que ser declarado para conseguir ordenar todos os resultados e manipular os resultados. Uma observação é que nem todas as linguagens de banco de dados relacionais utilizam essa nomenclatura.&#x20;

Traduzindo este comando para Mongo, temos:&#x20;

```mongodb
db.produtos.aggregate ([
    { // Utiliza o ID para o campo identificador do agrupamento
        $group: {_id: "$vendedor", precoMinimo: { $min: "$precoVenda" }}
    }
])
```

O símbolo cifrão serve para identificar um comando, contudo, quando está dentro de aspas, ele identifica qual é o nome do campo. Se não utilizar o cifrão dentro das aspas, vai identificar que o que está inserido ali dentro é um valor qualquer.

## Views para resolver granularidade de dados&#x20;

O MongoDB foi criado no objetivo de performance lidando muito bem com agrupamentos, então, os dados muitas vezes ficam próximos (em uma mesma coleção). Chamamos de granularidade quando o nível dos dados do banco está muito separado e não acoplado.&#x20;

Um exemplo disso é a criação de duas coleções, funcionários e departamentos, no qual o correto seria ter apenas uma coleção e os dados de funcionários ficariam dentro de um array dos departamentos.&#x20;

Neste caso, para visualizar os dados de diferentes coleções, deve-se criar uma VIEW. É um comando de busca que você possa reutilizar. No banco relacional, isso também existe. Ao querer juntar duas tabelas, isso vai gerar um grande comando “select”, portanto, é possível criar uma view para isso e reutilizar quando quiser, usando select nesta view.&#x20;

Outro exemplo de uso de view é para empresa com dados sigilosos, por exemplo, um funcionário de banco de dados só poderá consultar dados na “view”, que é uma visualização que não contém a coluna salário.&#x20;

Já em não relacional, é criado a view e depois chamá-la. &#x20;

### Como utilizar

Usa-se o operador <mark style="color:red;">`$lookup`</mark> para criar uma visualização entre duas coleções e rodar operações nela. O comando para criar essas visualizações é <mark style="color:purple;">`db.createView()`</mark>.

<figure><img src="../../.gitbook/assets/views em mongodb.png" alt=""><figcaption></figcaption></figure>

Nas duas coleções, sempre identificar qual é o lado N. No exemplo, “orders” é o lado N, pois são tantos diferentes pedidos para “inventory”, que é o estoque. Portanto, na criação da VIEW, inicia-se com o nome dela e depois com a coleção que pertence ao lado N.&#x20;

Nesse caso, a forma mais otimizada seria ter apenas uma coleção inventory e criar um array de orders dentro dela, por isso descobrimos facilmente qual seria o lado N.&#x20;

No operador <mark style="color:red;">`$lookup`</mark>, declara de onde vem os dados do outro lado.&#x20;

## Redis

> (Curiosidade: Red = vermelho + is de instância em memória)&#x20;

Ele não é um banco de dados e sim um armazenamento de dados. Não deve ser usado como banco de dados principal. Tudo nele é chave valor, registra uma chave e guarda um valor.

ACID (atomicity, constincy, integrity, durability) = princípio do átomo, uma transação não é divisível. Não perder indexidade e durabilidade, um dado inserido nunca mais volta ao estado anterior (rollback). Esses são os conceitos de um banco de dados, e o redis não tem nada disso.

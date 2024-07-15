---
description: https://www.sqlite.org/index.html, https://sqlitebrowser.org/dl/
---

# Banco de dados relacional

Banco de dados é separado em duas caixas: os dados e as estruturas lógicas. Dentro de um banco, podemos encontrar:

* Tabelas = armazenam os dados;&#x20;
* Índices = encontram dados, separando em tabelas de índices (guarda um atalho). Servem para buscar mais rapidamente, criando índices e resolvendo a lentidão;&#x20;
* Views = somente visualização de dados. Monta uma tabela na hora usando um SELECT na view, enxergando partes da tabela;&#x20;
* Triggers = gatilhos. Um exemplo é remover saldo quando é feito um saque no banco. Programa no próprio banco mesmo ao invés de criar um algoritmo para isso.&#x20;

## Tabelas e views

As tabelas são estruturas de dados que acomodam os registros. Cada tabela tem um padrão de colunas fixo (são estáticas). Já as views são visualizações de tabelas para restringir o que pode ser exibido em uma determinada consulta.&#x20;

Elas são compiladas e guardadas dentro do disco, pois o interpretador SQL faz a interpretação na criação da VIEW e depois apenas verifica se os objetos existem antes de executar. Portanto, por não passar pela etapa de interpretação, visualizar a view passa a ser mais rápido do que a pesquisa na própria tabela.&#x20;

```sql
CREATE VIEW VIEW_PARCERIA_SANTANDER
AS
    SELECT NOME, RG
    FROM FUNCIONARIOS_PUC;
```

## Uso de VARCHAR e CHAR&#x20;

O VARCHAR é um variable char, isso significa que não se sabe do tamanho dele. Para a sigla de pais que sempre são dois carácteres, você pode usar CHAR(2), já que tem o tamanho que será inserido na tabela.&#x20;

## Chaves estrangeiras&#x20;

A chave estrangeira mostra o dado de uma chave principal de outra tabela. Então por exemplo, uma coluna pode ser uma chave estrangeira, que é um dado (normalmente código) que está sendo referenciado em outra tabela.&#x20;

Existem algumas ideias sobre integridade relacional: na hora de declarar a chave estrangeira, não se usa ou declara o DELETE CASCADE, que seria deletar todas as linhas que utilizam um código que foi apagado da outra tabela. Mas ao mesmo tempo declara que ele será NOT NULL. &#x20;

Para criar uma chave estrangeira, faça:&#x20;

```sql
    ID_Filho NUMBER PRIMARY KEY,
    OutrosCampos VARCHAR(50),
    ID_Pai NUMBER,
    CONSTRAINT fk_Tabela_Pai FOREIGN KEY (ID_Pai) REFERENCES TabelaPai(Id_Pai)
```

## Inner join

O INNER JOIN é uma junção interna, ou seja, entre correlações entre duas tabelas, ou seja, registros relacionados. Aqueles dados que sobram podem ser tratados com LEFT e isto é feito através de uma chave estrangeira.&#x20;

Para utilizar o INNER JOIN, deve-se pensar no lado 1 e o lado N. O lado um é o principal e o N é aquele que vai retornar diversos resultados. Então, um exemplo para juntar um produto com o nome da categoria que ele pertence, através do ID dele é:

```sql
SELECT cat.nome, p.nome
FROM categorias cat
INNER JOIN produtos p
ON cat.codigo = p.categoria
ORDER BY cat.nome, p.nome
```

A forma mais fácil de fazer a montagem é pensar nos lados e iniciar o comando pelo FROM.

## Cálculos matemáticos no retorno de resultados&#x20;

Quando você quer manipular um valor a aparecer no SELECT, você pode fazer cálculos matemáticos simples na própria operação de forma fácil. Entre parênteses você pode realizar a operação e apelidar ele logo após com um espaço, exemplo:&#x20;

```plsql
SELECT cat.nome, p.nome, (p.custo_uni * 1.01) p.revisao_campo
```

Esses cálculos matemáticos podem utilizar também operadores, como o SUM para soma. Vamos supor a soma de todo o valor do inventário de uma empresa.

```sql
SELECT SUM (
    
    p.custo_uni * p.qnt_estoque

) custo_total_capital

FROM produtos p;
```

## Proteção contra-ataques ao banco de dados&#x20;

Uma observação muito importante é que auditoria não pode sumir, então elas são armazenadas em outra instância, inclusive o backup. Em um caso de um ataque, deve ser feito:&#x20;

1. Parar o servidor de banco de dados no SO;&#x20;
2. Parar a(s) interface(s) de rede dos servidores. Se tem um cluster, tem que parar de todo o cluster;&#x20;
3. Levantar o serviço do Oracle em modo emergência (/oradb start - - only=system);&#x20;

Existem várias formas de assegurar da confiabilidade dos dados. Por exemplo, criar triggers que registram em tabelas de auditoria todas as modificações feitas em senhas, contas, entre outros.&#x20;

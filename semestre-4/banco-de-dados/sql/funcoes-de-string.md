# Funções de string

> Para reorganização do caderno, dá pra fazer uma página só de funções. Todas as funções (data, número e strings aqui: [https://www.w3schools.com/sql/sql\_ref\_mysql.asp](https://www.w3schools.com/sql/sql_ref_mysql.asp) e para sql aqui > [https://www.w3schools.com/sql/sql\_ref\_sqlserver.asp](https://www.w3schools.com/sql/sql_ref_sqlserver.asp))

{% hint style="success" %}
Acrescentar em funções: Qualquer função pode ser utilizada em qualquer contexto (SELECT, INSERT, WHERE, etc). Elas não são restritas para consultas e nem lugares específicos.

As funções vão aparecer apenas em SELECT aqui mas são apenas por exemplo.
{% endhint %}

Existem diversa funções de strings que são utilizadas para transformar dados do banco. Elas tem como algumas vantagens:

* Quando há regras de negócios específicas no banco de dados.
* Deixar consultas visivelmente mais bonitas.
* Exigir menos do backend:
  * Processar dados antes de enviá-los, como processar o nome completo.
  * Diminuir a quantidade de dado enviado já criando regras com as strings e mandando o necessário.

(adições professor: manter códigos sql em aplicações não é recomendado, é mais utilizado para trabalhar com relatórios e não aplicações).

## Funções disponíveis

Existem diversas funções que podem ser encontradas em [documentações](https://learn.microsoft.com/en-us/sql/t-sql/functions/string-functions-transact-sql?view=sql-server-ver16).

## Utilização e exemplos

Funções recebem podem receber diversos tipos de parâmetros, entre o principal o <mark style="color:blue;">nome da coluna</mark>.

```sql
SELECT UPPER(nome) -- Nome da tabela
SELECT UPPER('Leonardo') -- Valor literal
SELECT UPPER(LEFT(nome, 3)) -- Resultado de outra função
SELECT LOWER(@sql_variable) -- Variáveis SQL
SELECT CONCAT(nome, ' - ', YEAR(data_nascimento)) -- Expressões e cálculos
SELECT UPPER((SELECT nome FROM clientes WHERE id = 1)) -- Uma sub query
```

#### Exemplo real

```sql
-- Juntar as colunas de nome e sobrenome em uma única coluna renomeada
-- como Nome Completo
SELECT CONCAT(first_name, " ", last_name) AS "Nome Completo" FROM actor;
```

## Funções interessantes

* `CONCAT`: Concatenar strings e afins.
* `CONCAT-WS`: Concatenar mas com um separador em comum, podendo enviar ao back-end dados separados por vírgulas e serem resgatados de uma forma mais simples ali.
*

# Funções

## O que são funções

São blocos de códigos reaproveitados. Isso quer dizer que também podemos programar nossas próprias funções para serem usadas.

O resultado dessas funções teoricamente também podem ser alcançadas apenas com uma escrita de consulta. Contudo, o uso das funções é mais recomendado e deixa mais limpo devido o uso indevido de grandes quantidades de consultas, veja o exemplo:

<figure><img src="../../../.gitbook/assets/diferenca de usar função em sql.png" alt=""><figcaption></figcaption></figure>

## Todas as funções

* Funções [SQL](https://www.w3schools.com/sql/sql_ref_sqlserver.asp) ou [aqui](https://learn.microsoft.com/en-us/sql/t-sql/functions/string-functions-transact-sql?view=sql-server-ver16).
* Funções [MySQL](https://www.w3schools.com/sql/sql_ref_mysql.asp) (algumas mudam sintaxe).

## Usando funções

Funções podem ser <mark style="color:green;">chamadas e utilizadas em qualquer contexto</mark> (SELECT, INSERT, WHERE, etc). Elas não são restritas para consultas e nem lugares específicos.

Funções recebem podem receber diversos tipos de parâmetros, entre o principal o <mark style="color:blue;">nome da coluna</mark>.

```sql
FUNCAO(nome_coluna)

-- Exemplo
SELECT UPPER(nome) -- Nome da tabela
SELECT UPPER('Leonardo') -- Valor literal
SELECT UPPER(LEFT(nome, 3)) -- Resultado de outra função
SELECT LOWER(@sql_variable) -- Variáveis SQL
SELECT CONCAT(nome, ' - ', YEAR(data_nascimento)) -- Expressões e cálculos
SELECT UPPER((SELECT nome FROM clientes WHERE id = 1)) -- Uma sub query

-- Exemplo real
SELECT CONCAT(first_name, " ", last_name) AS nome_completo FROM actor;
```

## Funções de string

Existem diversa funções de strings que são utilizadas para transformar dados do banco. Elas tem como algumas vantagens:

* Quando há regras de negócios específicas no banco de dados.
* Deixar consultas visivelmente mais bonitas.
* Exigir menos do backend:
  * Processar dados antes de enviá-los, como processar o nome completo.
  * Diminuir a quantidade de dado enviado já criando regras com as strings e mandando o necessário.

{% hint style="info" %}
Manter códigos SQL em aplicações não é recomendado, é mais utilizado para trabalhar com relatórios e não aplicações.
{% endhint %}

### Funções interessantes

* `CONCAT`: Concatenar strings e afins.
* `CONCAT-WS`: Concatenar mas com um separador em comum, podendo enviar ao back-end dados separados por vírgulas e serem resgatados de uma forma mais simples ali.

## Funções com números

Principais funções numéricas:

<table><thead><tr><th width="206">Função</th><th>Descrição</th></tr></thead><tbody><tr><td>MIN e MAX</td><td>Valor limite de um filtro.</td></tr><tr><td>CEIL e FLOOR</td><td>Arredonda um número para cima ou baixo.</td></tr><tr><td>AVG</td><td>Média de valores de um filtro</td></tr><tr><td>COUNT</td><td>Conta o número de registros da condição. Recebe * como parâmetro.</td></tr><tr><td>SUM</td><td>Soma todos os valores de um filtro.</td></tr><tr><td>FORMAT</td><td>Formata uma numeração (casas decimais).</td></tr></tbody></table>

# Select avançado

Em uma perspectiva de aplicação, a maioria esmagadora das operações são de consulta.

{% hint style="info" %}
Todas essas instruções podem ser combinadas juntas e criar algo bem complexo.
{% endhint %}

## Operadores

Ele aceita operadores para selecionar dados mais específicos.

* **Comparação**: Operadores iguais que são em linguagens de programação como `>`, `>=` ou `=`.
* **BEETWEEN**: Intervalo.
* **LIKE**: Padrão.
* **IN**: Conjunto de valores.

### Comparação

```sql
SELECT * FROM nome_tabela WHERE nome_coluna >= 101676;
```

### Distinct

Mostra todas as opções que aparecem em uma determinada coluna:

```sql
SELECT DISTINCT gender FROM nome_tabela;

# Resultado:
#  M
#  F
```

### Operadores lógicos

Usar para criar combinações nas querys: `AND`, `OR` e `NOT` (podemos usar `&&` e `||`). Podem ser usados em sequência diversos operadores, criando quantas condições quiser.

```sql
# NOT
SELECT * FROM employees WHERE NOT gender = 'M'
SELECT * FROM employees WHERE NOT gender = 'M' AND NOT title = "Enginner"

# OR
SELECT * FROM salaries WHERE salary > 150000 OR salary < 40000

# AND
SELECT * FROM salaries WHERE salary > 150000 AND role = "Senior"
```

Essas operações podem estar em conjuntas com outras criando condições mais complexas:

```sql
SELECT * FROM employees.titles
WHERE (title = "Staff" AND emp_no = 10002) OR emp_no = 10003;
```

## Ordenação

A ordenação é baseada em uma coluna. A ordenação padrão é ascendente, então declarar ASC é redundante.

```sql
SELECT * FROM salaries
ORDER BY salary DESC;
```

## Limite de busca

Criar uma limitação de resultados de uma consulta. Excelente ideia quando queremos os 10 melhores posicionados, o vencedor, boas vindas para os mais novos ou algo do tipo.

```sql
SELECT * FROM salaries
ORDER BY salary DESC
LIMIT 10;
```

## Funções

São blocos de códigos reaproveitados. Isso quer dizer que também podemos programar nossas próprias funções para serem usadas.

O resultado dessas funções teoricamente também podem ser alcançadas apenas com uma escrita de consulta. Contudo, o uso das funções é mais recomendado e deixa mais limpo devido o uso indevido de grandes quantidades de consultas.

<figure><img src="../../../.gitbook/assets/diferenca de usar função em sql.png" alt=""><figcaption></figcaption></figure>

### Utilização

As funções usadas no SELECT impõe que vão retornar um número baseado nos valores fornecidos na consulta.

Espera-se no <mark style="color:blue;">parâmetro da função</mark> uma coluna específica onde todos os registros dela serão iterados. Com uma exceção, a função COUNT pode não usar esse parâmetro (e utilizar `*`) e também pode contar valores únicos com `DISTINCT`.

{% hint style="danger" %}
Algumas funções numéricas não suportam o operador LIMIT, para por exemplo, somar as 5 primeiras aparições de maior salário.
{% endhint %}

#### Exemplos

```sql
SELECT MIN(salario) FROM funcionarios;
SELECT SUM(salario) FROM funcionarios WHERE salario > 20000;
SELECT COUNT(*) FROM funcionarios WHERE bonus > 1000;
SELECT COUNT(DISTINCT cargos) FROM funcionarios;
```

### Principais funções

<table><thead><tr><th width="206">Função</th><th>Descrição</th></tr></thead><tbody><tr><td>MIN</td><td>Valor mínimo de um filtro.</td></tr><tr><td>MAX</td><td>Valor máximo de um filtro.</td></tr><tr><td>AVG</td><td>Média de valores de um filtro</td></tr><tr><td>COUNT</td><td>Conta o número de registros da condição.</td></tr><tr><td>SUM</td><td>Soma todos os valores de um filtro.</td></tr></tbody></table>

## LIKE

(É um operador também?) Usado para buscar um padrão, podendo usar um "coringa" `%`. Ele é como se fosse um operador de condição:

* `%valor`: O que estiver antes não importa.
* `valor%`: O que estiver depois não importa.
* `%valor%`: Contenha em qualquer lugar.

```sql
SELECT first_name FROM employees WHERE first_name LIKE "%Geo";
```

## IN

(é um operador) para buscar um conjunto de valores, uma lista declarada por abertura e fechamento de parênteses.

```sql
SELECT * FROM employees WHERE first_name IN ("Parto", "Sumant")
```

## Faixa de valores BETWEEN

Um operador que declara um intervalo para os registros utilizando também o operador `AND` como auxiliar:

```sql
SELECT * FROM salaries WHERE salary BETWEEN 60000 AND 65000;
```

## Alias - Renomeação de coluna

A palavra `AS` é a abreviação de alias e é a palavra utilizada para isso. Renomear coluna com um nome não objetivo.&#x20;

O AS vem acompanhado após o nome da coluna e o SELECT, com isso podendo renomear várias colunas dessa forma:

```sql
# Antes
SELECT col1, col2 FROM tabela;

# Depois
SELECT col1 AS "Coluna 1", col2 AS "Coluna 2" FROM TABELA;
```

```sql
SELECT SUM(salary) AS "Soma do Salário" FROM salaries;
```

## Renomear coluna

```sql
SELECT MAX(salary) AS salario FROM salaries;

SELECT COUNT(*) AS super_salarios
FROM salaries WHERE salary > 100000;
```

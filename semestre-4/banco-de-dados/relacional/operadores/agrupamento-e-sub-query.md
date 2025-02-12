# Agrupamento e sub query

## Operador UNION

Resgatar dados de duas colunas <mark style="color:orange;">com o mesmo nome</mark> de tabelas diferentes sem repetir dados.

```sql
SELECT coluna_1 FROM nome_tabela
UNION SELECT coluna_1 FROM outra_tabela
```

## Operador UNION ALL

Esse caso vai repetir os dados caso eles apareçam mais de uma vez.

```sql
SELECT coluna_1 FROM nome_tabela
UNION ALL SELECT coluna_1 FROM outra_tabela
```

## Operador GROUP BY

Agrupamento de resultados, por exemplo: quantos pessoas por cargo existem no banco de dados? Resultando isso:

<figure><img src="../../../../.gitbook/assets/group by em sql.png" alt=""><figcaption></figcaption></figure>

```sql
SELECT cargo, COUNT(*) AS "Quantidade no cargo"
FROM funcionarios
GROUP BY cargo;
```

## Operador HAVING

Sempre que estamos usando funções de agregação, o `WHERE` não pode ser utilizado e teremos que usar o `HAVING`. Veja neste caso, onde a condição é feita com HAVING pois existe uma aggregate function `GROUP BY`.

<figure><img src="../../../../.gitbook/assets/sql having.png" alt=""><figcaption></figcaption></figure>

## Sub Query

É uma consulta dentro de outra que se assemelha com um JOIN, mas ela é feita pois as vezes necessitamos de casos muito específicos.&#x20;

```sql
SELECT coluna, ( Uma sub-query aqui ) FROM tabela
```

```sql
SELECT first_name, (
	SELECT SUM(salary)
	FROM salaries
	WHERE employees.emp_no = salaries.emp_no # Esse seria o "join"
) AS soma_salario
FROM employees
ORDER BY soma_salario DESC;
```

### Operador EXISTS

Criar uma <mark style="color:blue;">condição para a sub-query</mark>, podendo ser a existência de um dado ou uma condição com um operador.&#x20;

```sql
SELECT first_name, (
	SELECT SUM(salary)
	FROM salaries
	WHERE employees.emp_no = salaries.emp_no
) AS soma_salario
FROM employees
# Novas linhas
WHERE EXISTS (
	# A mesma sub query acima
	SELECT salary
	FROM salaries
	WHERE employees.emp_no = salaries.emp_no
	HAVING SUM(salary) > 100000 # Estamos em agregação então tem que ser o HAVING
);
```

### Operador ANY

```sql
SELECT first_name
FROM employees
WHERE emp_no = ANY (
	SELECT emp_no
	FROM salaries
	WHERE salary > 10000
);
```

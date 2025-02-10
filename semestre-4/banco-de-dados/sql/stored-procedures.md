# Stored Procedures

São querys atreladas a um banco de dados que podem ser reutilizáveis.

{% hint style="info" %}
Recurso fundamental para criar é alterar o delimitador:

```sql
DELIMITER $ -- Alterar delimitador para sifrão

------------------------
SELECT * FROM tabela
WHERE coluna = 'Exemplo'$
```
{% endhint %}

## Comandos

```sql
-- Chamar
CALL nomeProcedure();

-- Listar
SHOW PROCEDURE STATUS;

-- Removendo
DROP PROCEDURE nomeProcedure;

-- Dados mais completo de uma procedure (qual é a query)
SHOW CREATE PROCEDURE nomeProcedure;
```

## Estrutura

Possui um&#x20;

```sql
-- Criar
DELIMITER $
CREATE PROCEDURE fullName()
BEGIN
    SELECT CONCAT(first_name, " ", last_name) AS nome_completo
    FROM employees;
END$
```

```sql
-- Chamar
CALL fullName()
```

## Com parâmetros

Precisa definir o tipo do parâmetro, deixando as <mark style="color:blue;">procedures dinâmicas</mark>.&#x20;

```sql
CREATE PROCEDURE nomeProcedure(
    IN variavel TIPO_VARIAVEL,
    IN outra_var TIPO_VARIAVEL
)
```

```sql
DELIMITER $
CREATE PROCEDURE funcionariosMaioresSalarios(
    IN highSalary INT
)
BEGIN
    SELECT employees.first_name, salaries.salary FROM employees
    JOIN salaries ON employees.emp_no = salaries.emp_no
    WHERE salaries.salary > highSalary
    ORDER BY salaries.salary DESC;
END$

CALL funcionariosMaioresSalarios(110000);
```

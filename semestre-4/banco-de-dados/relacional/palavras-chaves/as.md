# AS

AS é a abreviação de ALIAS que serve para nomear ou criar apelidos. Pode ser usado em diversas ocasições como `SELECT`, `VIEW`, `WITH` e muitas outras.

```sql
SELECT nome AS NomeCompleto, email AS EmailUsuario FROM usuarios;
```

Uma vez que o elemento for renomeado, ele pode ser usado novamente com aquele apelido, veja:

```sql
SELECT nome AS nome_completo
WHERE nome_completo = "Algum nome"; -- A coluna nome foi usada como "nome_completo"
```

O AS vem acompanhado após o nome da coluna, com isso podendo renomear várias colunas dessa forma:

```sql
# Antes
SELECT col1, col2 FROM tabela;

# Depois
SELECT col1 AS "Coluna 1", col2 AS "Coluna 2" FROM TABELA;
```

```sql
SELECT SUM(salary) AS "Soma do Salário" FROM salaries;
```

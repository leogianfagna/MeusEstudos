# Índices

Usado para aumentar a performance quando uma consulta começa a ficar muito lenta. Quando uma coluna tiver um índice cadastrado, ela será jogada na frente das outras.

Ele cria <mark style="color:purple;">ponteiros</mark> para dados dizendo onde estão e acelerando a busca, por isso, exige um pouco mais de processamento.

```sql
# Consulta 1: 109ms
SELECT * FROM employees WHERE first_name = "Georgi";
```

```sql
# Consulta 2: 31ms
CREATE INDEX index_nome
ON employees(first_name);

SELECT * FROM employees WHERE first_name = "Georgi";
```

Existem [prós e contras de se usar índices](https://www.alura.com.br/artigos/indices-no-postgresql), portanto, sempre ver a melhor alternativa. Ele precisa ser muito estudado para verificar onde deve existir um índice.

### Remover um índice

```sql
DROP INDEX index_nome ON employees
```

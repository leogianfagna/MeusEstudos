# Operadores de comparação

Ele aceita operadores para selecionar dados mais específicos.

* **Comparação**: Operadores iguais que são em linguagens de programação como `>`, `>=` ou `=`.
* **BEETWEEN**: Intervalo.
* **LIKE**: Padrão.
* **IN**: Conjunto de valores.

## Comparação

```sql
SELECT * FROM nome_tabela WHERE nome_coluna >= 101676;
```

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

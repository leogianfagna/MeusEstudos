---
description: >-
  Em uma perspectiva de aplicação, a maioria esmagadora das operações são de
  consulta.
---

# SELECT

## Select com colunas específicas

Trocar o `*` (que simboliza todas as colunas) pelo nome das colunas que queremos (separada por vírgulas):

```sql
SELECT * FROM pessoas;

SELECT nome, rg FROM pessoas;
```

## DISTINCT

Mostra todas as opções que aparecem em uma determinada coluna:

```sql
SELECT DISTINCT gender FROM nome_tabela;

# Resultado:
#  M
#  F
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

## Utilização das [funções](../funcoes.md)

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

## Outros atributos para consultas mais avançadas

O que está disponível nessa documentação, como operadores, palavras chaves, etc, podem ser juntados e agregados em uma consulta para criar consultas mais avançadas, como por exemplo:

* Renomear colunas com [ALIAS](../palavras-chaves/as.md).
* Regras de consulta com [operadores](../operadores/).
* As próprias [funções](../funcoes.md) vistas acima.

```sql
-- Exemplo usando funções, alias, operadores e condição
SELECT COUNT(DISTINCT cargos) AS "Quantidade de cargos"
FROM funcionarios
WHERE salario (BETWEEN 60000 AND 65000) OR cargos LIKE '%Senior%';
```

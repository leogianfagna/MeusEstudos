# Operadores matemáticos

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

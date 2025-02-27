# Unindo tabelas

`JOIN` é a possibilidade de unir consultas com diferentes tabelas (pode ser mais de duas), não necessariamente se elas fazem relação entre si.

Por utilizar duas tabelas, usamos a notação de ponto para simbolizar qual tabelas vamos utilizar, desta forma:

```sql
SELECT nome_tabela.nome_coluna, outra_tabela.nome_coluna
```

## Entendendo a relação

A coluna `emp_no` está presente nas duas tabelas. Ela será a coluna que utilizaremos para fazer a relação no JOIN.

## Tipos de JOIN

<figure><img src="../../../.gitbook/assets/sql joins.png" alt=""><figcaption></figcaption></figure>

### INNER JOIN

<figure><img src="../../../.gitbook/assets/image (1) (1).png" alt=""><figcaption></figcaption></figure>

Resulta nas colunas que <mark style="color:purple;">fazem relação</mark> entre as tabelas. Utilizamos a instrução `ON` para determinar as colunas que precisam ser iguais.

### LEFT E RIGHT JOIN

Usado para trazer os registros que fazem relação (igual INNER JOIN) e depois acrescenta <mark style="color:orange;">**TODOS**</mark> os outros registros da tabela (do lado escolhido) que não encontraram relação, preenchendo as colunas como `NULL`. A sacada é que teremos dados excedentes que não tem relação com a outra tabela.

<figure><img src="../../../.gitbook/assets/resultado e diferenças de usar left join.png" alt=""><figcaption></figcaption></figure>

Este caso foi feito com `LEFT JOIN`, então todos os registros da tabela da esquerda aparecerão. Se apenas trocarmos para `RIGHT JOIN`, quem passa a receber todos os lados é a tabela da direita (pedidos). Portanto, teríamos a aparição de todos os produtos. Exemplo:

<figure><img src="../../../.gitbook/assets/resultado de right join.png" alt=""><figcaption></figcaption></figure>

{% hint style="info" %}
É convencional manter apenas o uso do LEFT JOIN e então trocar a ordem da query em vez de utilizar o RIGHT.
{% endhint %}

### Outros tipos

Normalmente o objetivo é sempre unir tabelas com relacionamentos, então o INNER JOIN sempre atinge os resultados desejados. Em casos muito específicos existem outros JOINS, menos comuns.

## Mais de duas tabelas

Se quisermos fazer de mais de uma tabela, basta <mark style="color:blue;">acrescentar um outro</mark> <mark style="color:blue;"></mark><mark style="color:blue;">`JOIN`</mark> em seguida:

```sql
SELECT tabela_1.nome, tabela_2.endereco, tabela_3.cargo
FROM tabela_1
INNER JOIN tabela_2 # Unindo tabela 2
ON tabela_1.id = tabela_2.id
INNER JOIN tabela_3 # Unindo outra tabela
ON tabela_1.id = tabela_3.id
```

Utilizar um INNER JOIN exige mais processamento, colocar dois pode exigir bastante. Tomar cuidado.

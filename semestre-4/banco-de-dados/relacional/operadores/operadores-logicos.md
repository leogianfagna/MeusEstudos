# Operadores lógicos

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

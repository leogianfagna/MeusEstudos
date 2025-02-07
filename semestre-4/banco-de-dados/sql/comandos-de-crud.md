# Comandos de CRUD

São operações de dados: Create|read|update|delete

## Select com colunas específicas

Trocar o `*` (que simboliza todas as colunas) pelo nome das colunas que queremos (separada por vírgulas):

```sql
SELECT * FROM pessoas;

SELECT nome, rg FROM pessoas;
```

## Cláusula WHERE

Sem ele, a açõa CRUD será aplicada para todos os registros.

## Update

No update se o WHERE não está usando uma chave única como condição, isso poderá travar a execução se o MySQL estiver no safe mode. Exemplo:

```sql
UPDATE nome_tabela SET nome_coluna = 50, outra_coluna = true
WHERE nome_coluna = 10;
```

Para tirar do safe mode, podemos usar:

```sql
SET SQL_SAFE_UPDATES = 0;
```

## Deletar registros da tabela

O DELETE vai deletar todos os registros que o `WHERE` condizer.

```sql
DELETE FROM nome_tabela WHERE nome_coluna = "Usuário5";
```

As condições não são limitadas à valores iguais e podem ser operações matemáticas:

```sql
DELETE FROM contas WHERE saldo > 5000;
```

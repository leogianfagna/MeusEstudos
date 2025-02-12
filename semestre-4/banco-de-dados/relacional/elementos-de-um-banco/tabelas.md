# Tabelas

A tabela é a entidade responsável por organizar os dados em colunas (são como categorias que possuem tipos de dados e atributos). Os atributos são não nulo, chave primária e outros.

## Criação

Para criação, precisamos saber sobre os [tipos de dados](../dados/tipos-de-dados.md).

```sql
CREATE TABLE nome_tabela (
    nome_coluna VARCHAR(200),
    outra_coluna CHAR(5),
    ...
);
```

## Deletar

Isso vai apagar todo um database, isto é, todas as colunas e dados.

```sql
DROP TABLE nome_tabela;
```

### Remoção quando há chave estrangeira

Vamos supor que a tabela `referencia_tabela` tenha uma coluna que é uma [chave estrangeira](../constraints.md#chave-estrangeira) referente a essa tabela que queremos deletar. O SQL não vai permitir isso. Para resolver isso temos:

```sql
-- Opção 1) Deletar manualmente a outra tabela
DROP TABLE referencia_tabela;
DROP TABLE nome_tabela;

-- Opção 2) Usar palavra CASCADE
DROP TABLE usuarios CASCADE;
```

Aqui conhecemos a palavra CASCADE que remove automaticamente as tabelas dependentes (aquelas que têm `FOREIGN KEY` para `nome_tabela`).

## Alterar tabelas

Comandos de alteração usa o prefixo `ALTER TABLE`.

### Adicionar coluna

```sql
ALTER TABLE nome_tabela ADD COLUMN nome_coluna VARCHAR(100);
```

### Remover coluna

Por via das dúvidas, sempre se mantém os dados do sistema pois não se sabe se vai usar em um futuro. Então remover colunas não é algo feito com frequência.

```sql
ALTER TABLE nome_tabela DROP COLUMN nome_coluna
```

### Altera coluna

```sql
ALTER TABLE nome_tabela ALTER TABLE nome_coluna INT
```

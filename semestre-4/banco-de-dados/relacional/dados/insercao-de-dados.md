# Inserção de dados

A inserção precisa seguir a ordem das colunas igual está no banco ou especificar cada coluna respectivamente depois do INSERT INTO.

```sql
INSERT INTO produtos (nome, sku, informacoes) # Especifica as colunas, redundante
VALUES ("PlayStation", "PS5", "Video Game");

INSERT INTO produtos # Não especifica as colunas, precisa inserir o ID
VALUES (1001, "PlayStation", "PS5", "Video Game");
```

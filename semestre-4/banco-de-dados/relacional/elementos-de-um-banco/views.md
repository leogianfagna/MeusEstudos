# Views

As tabelas são estruturas de dados que acomodam os registros. Cada tabela tem um padrão de colunas fixo (são estáticas). Já as views são visualizações de tabelas para restringir o que pode ser exibido em uma determinada consulta.&#x20;

Elas são compiladas e guardadas dentro do disco, pois o interpretador SQL faz a interpretação na criação da VIEW e depois apenas verifica se os objetos existem antes de executar. Portanto, por não passar pela etapa de interpretação, visualizar a view passa a ser mais rápido do que a pesquisa na própria tabela.&#x20;

```sql
CREATE VIEW VIEW_PARCERIA_SANTANDER
AS
    SELECT NOME, RG
    FROM FUNCIONARIOS_PUC;
```

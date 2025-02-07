# Gerenciando tabelas

A tabela é a entidade responsável por organizar os dados em colunas (são como categorias que possuem tipos de dados e atributos). Os atributos são não nulo, chave primária e outros.

## Criação

```sql
CREATE TABLE nome_tabela (nome_coluna VARCHAR(200), ...)
```

## Deletar

```sql
DROP TABLE nome_tabela
```

> COMO FUNCIONA QUANDO SE TEM CHAVES ESTRANGEIRAS?

## Tipos de dados

A **regra básica para seleção do tipo** quando eles podem ser confundidos é para que vai usá-los. Números representam quantidades. CPF ou CNPJ são quantidades? Não, são identificadores que podem até mesmo mudar, que podem um dia ter letras. Por outro lado, um saldo bancário será usado para receber operações matemáticas, portanto, precisam ser números.

Números que não são usados para operações, como número de um imóvel, não há necessidade de serem declarados como números. Optamos sempre por `varchar` em qualquer dado até que encontre um motivo para escolher outro tipo.

### Principais tipos de dados usados

* `INT` para valores inteiros.
* `DOUBLE` para valores não inteiros.
* `DECIMAL(10,2)` para números decimais extremamente precisos (total de dígitos, casas decimais).
* `VARCHAR(N)` para armezenar texto, palavras ou caracteres. Aceitam caracteres especiais.
* `TEXT` para um bloco grande de texto.
* `DATE` e variados para datas.
* `BOOLEAN` ou `TINYINT(1)` para valores booleanos.

Para uma [lista completa dos possíveis tipos de dados](https://www.ibm.com/docs/pt-br/db2/11.1?topic=plsql-data-types). Nem sempre se preocupado com a otimização extrema dos dados, de usar SMALLINT ao invés de INT para poupar espaço.

<details>

<summary>Data</summary>

O padrão de data é YYYY-MM-DD que é o padrão americano.&#x20;

* DATE: Usa ano, mês e dia.
* DATETIME: Também tem horas e segundos.
* TIMESTAMP: Existe um intervalo específico que pode ser utilizado. Conferir as regras antes de usar esse tipo.

As datas são inseridas entre aspas, então `VALUES ("1999-01-25")`.

</details>

## Inserir dados

A inserção precisa seguir a ordem das colunas igual está no banco ou especificar cada coluna respectivamente depois do INSERT INTO.

```sql
INSERT INTO produtos (nome, sku, informacoes) # Especifica as colunas, redundante
VALUES ("PlayStation", "PS5", "Video Game");

INSERT INTO produtos # Não especifica as colunas, precisa inserir o ID
VALUES (1001, "PlayStation", "PS5", "Video Game");
```

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

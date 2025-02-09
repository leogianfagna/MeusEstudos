# Constraints

Chaves primárias.

Elas moldam como a tabela/coluna vai funcionar, definindo uma <mark style="color:blue;">propriedade ou característica em colunas</mark> que determinam como os campos são preenchidos.

## Definir uma constraint

Elas são adicionados na criação da tabela e definida para cada coluna:

```sql
CREATE TABLE pessoas(
    nome VARCHAR(100) <CONSTRAINT_AQUI>,
    idade INT
);
```

### Principais constraints

<table><thead><tr><th width="195">Constraint</th><th>Descrição</th></tr></thead><tbody><tr><td>PRIMARY KEY</td><td>Identificador único de um registro da tabela (normalmente chamado de <code>id</code>). É feito de forma diferente para tornar-se uma <a href="constraints.md#chave-primaria">chave primária</a>.</td></tr><tr><td>UNIQUE</td><td>Garante que todos os valores de uma coluna são únicos e não podem ser repetidos.</td></tr><tr><td>NOT NULL</td><td>Força que a coluna não pode ser <a data-footnote-ref href="#user-content-fn-1">nula</a>.</td></tr></tbody></table>

## Chave primária

Também tem como premissa uma chave única, não podendo repetir o dado em toda a coluna. Ela define o valor de uma coluna como essa chave, podendo ser simples ou composta. Veja exemplo de simples:

```sql
CREATE TABLE produtos(
    id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    nome VARCHAR(100),
    valor DOUBLE,
);

INSERT INTO produtos (nome, valor)
VALUES ("Batedeira", 50);
```

A palavra `AUTO_INCREMENT` permite omitir definir o ID na hora da inserção da tabela e faz o trabalho de sempre criar um ID único para cada registro.

{% hint style="info" %}
Colunas com chaves primárias ganham um índice automaticamente, uma característica padrão das tabelas com chave primária.
{% endhint %}

## Chave estrangeira

É sobre relacionamento entre tabelas que é referenciado pela chave primária, que pode ser consultado usando [JOIN](unindo-tabelas.md). Um exemplo seria criar uma tabela de endereços que é [<mark style="color:purple;">**relacionada**</mark>](#user-content-fn-2)[^2] com usuários.

```sql
FOREIGN KEY (nome_da_coluna_tabela_atual)
REFERENCES nome_da_outra_tabela(nome_coluna_tabela_estrangeira)
```

```sql
# Tabela normal
CREATE TABLE pessoas(
    id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    nome VARCHAR(100),
    idade INT
);

# Tabela que terá a relação
CREATE TABLE enderecos(
    id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    rua VARCHAR(100),
    numero VARCHAR(10),
    pessoa_id INT NOT NULL,
    FOREIGN KEY (pessoa_id) REFERENCES pessoas(id) # Relacionamento
);

# Inserção de dados
INSERT pessoas (nome, idade)
VALUES ("Leo", 25);

INSERT enderecos (rua, numero, pessoa_id)
VALUES ("Rua R", "55", 1); # Relacionamento com id 1 de "pessoas"
```

#### Remoção de tabelas

Se uma coluna é uma chave estrangeira, existe uma proteção de remoção. Não podemos remover esse dado ligado pois ele está como chave estrangeira ali, primeiro precisamos remover o dado que faz a ligação e depois remover o outro.

```sql
# Isso não seria possível pois "enderecos" possui uma coluna que é relacionada
# com "pessoas"
DROP TABLE pessoas;

DROP TABLE enderecos; # OK, ou remover os dados referenciados
```

## Índice

Usado para aumentar a performance quando uma consulta começa a ficar muito lenta. Quando uma coluna tiver um índice cadastrado, ela será jogada na frente das outras.

Ele cria <mark style="color:purple;">ponteiros</mark> para dados dizendo onde estão e acelerando a busca, por isso, exige um pouco mais de processamento.

```sql
# Consulta 1: 109ms
SELECT * FROM employees WHERE first_name = "Georgi";
```

```sql
# Consulta 2: 31ms
CREATE INDEX index_nome
ON employees(first_name);

SELECT * FROM employees WHERE first_name = "Georgi";
```

Existem [prós e contras de se usar índices](https://www.alura.com.br/artigos/indices-no-postgresql), portanto, sempre ver a melhor alternativa. Ele precisa ser muito estudado para verificar onde deve existir um índice.

### Remover um índice

```sql
DROP INDEX index_nome ON employees
```

[^1]: Especificamente, não pode ser mandado o dado `NULL` no insert, isso faz com que haja necessidade da aplicação back-end mandar o dado `NULL` ao invés de não mandar nada.

[^2]: Endereços que se relaciona com usuários. Não há nenhuma coluna extra na tabela de usuários para receber tal relação.

# Tipos de dados

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

## Uso de VARCHAR e CHAR&#x20;

O VARCHAR é um <mark style="color:purple;">variable char</mark>, isso significa que não se sabe do tamanho dele. Quando sabemos o exato tamanho (tipo sigla de país), podemos usar `CHAR(2)`, já que tem o tamanho que será inserido na tabela.&#x20;

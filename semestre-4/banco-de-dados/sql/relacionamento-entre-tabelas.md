# Relacionamento entre tabelas

Está no próprio nome de banco de dados relacionais que tabelas, em projetos reais, possuem relacionamentos e separação de responsabilidade.

## Tipos de relacionamento

As querys que executamos elas são baseadas em cima dessa teoria (um para um, um para muitos, muitos para muitos). Isso foi descrito [aqui sobre MER](../estrutura-e-conceituacao/modelagem.md#mer-modelo-entidade-relacionamento).

A criação de uma tabela <mark style="color:orange;">não especifica qual tipo de relação será</mark> e sim a forma em que os dados estão sendo preenchidos.

As relações são estabelecidas na prática com <mark style="color:purple;">chaves estrangeiras</mark>.

### Um para um

<figure><img src="../../../.gitbook/assets/sql 1-1.png" alt=""><figcaption></figcaption></figure>

### Um para muitos

<figure><img src="../../../.gitbook/assets/sql 1-n.png" alt=""><figcaption></figcaption></figure>

### Muitos para muitos

Essa relação exige uma tabela a mais, normalmente chamada de <mark style="color:purple;">pivot table</mark>, que serve para conter as relações entre si e usá-la para fazer o JOIN. Normalmente essa tabela tem o nome das duas entidades e no singular, exemplo `estudante_materia`.

<figure><img src="../../../.gitbook/assets/sql n-n.png" alt=""><figcaption></figcaption></figure>

#### Exemplo de uso muitos para muitos

```sql
-- Criar tabela
CREATE TABLE estudante_materia (
  estudante_id INT NOT NULL,
  materia_id INT NOT NULL,
  FOREIGN KEY (estudante_id) REFERENCES estudantes(id),
  FOREIGN KEY (estudante_id) REFERENCES estudantes(id)
)

-- Buscar dados
SELECT * FROM estudantes
JOIN estudante_materia ON estudante_materia.id = estudantes.id;
```

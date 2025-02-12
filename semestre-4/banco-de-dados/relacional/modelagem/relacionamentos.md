# Relacionamentos

Está no próprio nome de banco de dados relacionais que tabelas, em projetos reais, possuem relacionamentos e separação de responsabilidade.

## Leitura de diagramas

O número mais próximo ao elemento, significa a quantia de vezes que o OUTRO ELEMENTO está associado à ele.

<figure><img src="../../../../.gitbook/assets/relacionamento em der.png" alt=""><figcaption></figcaption></figure>

### Leitura no MySQL

É possível modelar usando o **SGDB** MySQ&#x4C;**.** Ao entrar, ele já tem a opção de modelagem (bem completa e com bastante recursos).

Essa modelagem utiliza as seguintes setas para relacionamentos:

<figure><img src="../../../../.gitbook/assets/setas de relacionamento workbench.png" alt="" width="342"><figcaption></figcaption></figure>

<figure><img src="../../../../.gitbook/assets/ex relacionamento no mysql.png" alt=""><figcaption></figcaption></figure>

## Como são feitos relacionamentos

As relações são laçadas na prática com <mark style="color:purple;">chaves estrangeiras</mark>, onde uma chave de uma tabela está presente na outra. Chaves estrangeiras geram necessidade de usar `JOIN` nas buscas.

As querys que executamos são baseadas em cima dessa teoria (um para um, um para muitos, muitos para muitos). Isso foi descrito [aqui sobre MER](./#mer-modelo-entidade-relacionamento).

A criação de uma tabela <mark style="color:orange;">não especifica qual tipo de relação será</mark> e sim a forma em que os dados estão sendo preenchidos.

## Relação um para um

<details>

<summary>Caso de uso e definição</summary>

Cada registro em uma tabela corresponde a exatamente um registro em outra tabela. Cada cliente pode estar em apenas um registro do endereço de cobrança por conta da palavra `UNIQUE`.

```sql
CREATE TABLE clientes (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100)
);

CREATE TABLE endereco_cobranca (
    id INT PRIMARY KEY AUTO_INCREMENT,
    cliente_id INT UNIQUE, -- Isso torna UM para UM
    endereco VARCHAR(255),
    FOREIGN KEY (cliente_id) REFERENCES clientes(id)
);
```

</details>

<figure><img src="../../../../.gitbook/assets/sql 1-1.png" alt=""><figcaption></figcaption></figure>

## Relação um para muitos

<details>

<summary>Caso de uso e definição</summary>

Um registro em uma tabela pode estar relacionado a vários registros em outra tabela. É o mesmo exemplo sem a presença da chave única.

```sql
CREATE TABLE clientes (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100)
);

CREATE TABLE pedidos (
    id INT PRIMARY KEY AUTO_INCREMENT,
    cliente_id INT, -- Pode ter quantos quiser
    data DATE,
    valor DECIMAL(10,2),
    FOREIGN KEY (cliente_id) REFERENCES clientes(id)
);
```

</details>

<figure><img src="../../../../.gitbook/assets/sql 1-n.png" alt=""><figcaption></figcaption></figure>

## Relação muitos para muitos

<details>

<summary>Caso de uso e definições</summary>

Essa relação exige uma tabela a mais, normalmente chamada de <mark style="color:purple;">pivot table</mark>, que serve para conter as relações entre si e usá-la para fazer o JOIN. Normalmente essa tabela tem o nome das duas entidades e no singular, exemplo `estudante_materia`.

É possível que utilize dois `JOIN` em uma busca de muitos para muitos.

```sql
CREATE TABLE materias(
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100)
);

CREATE TABLE estudantes(
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100),
    turma CHAR(2)
);

-- Tabela intermediária
CREATE TABLE estudante_materia(
    estudante_id INT NOT NULL,
    materia_id INT NOT NULL,
    FOREIGN KEY (estudante_id) REFERENCES estudantes(id),
    FOREIGN KEY (estudante_id) REFERENCES estudantes(id)
);

-- Consulta
SELECT * FROM estudantes
JOIN estudante_materia ON estudante_materia.id = estudantes.id
JOIN materias ON estudante_materia.materia_id = materias.id;
```

</details>

<figure><img src="../../../../.gitbook/assets/sql n-n.png" alt=""><figcaption></figcaption></figure>

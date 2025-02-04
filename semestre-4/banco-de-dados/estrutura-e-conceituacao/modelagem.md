# Modelagem

A **modelagem de dados** é uma etapa inicial em um projeto de banco de dados. Esse processo envolve a **criação de um modelo de dados** que orienta como o software armazenará informações no banco. Para isso utilizamos o `MER` e o `DER`.

## MER (Modelo Entidade-Relacionamento)

Utilizado para <mark style="color:green;">descrever</mark> os **objetos** do mundo real em forma de <mark style="color:blue;">entidades</mark>, que possuem <mark style="color:blue;">atributos</mark> que as descrevem (como nome, idade, etc). Essas entidades podem ter <mark style="color:blue;">relacionamento</mark> entre si, normalmente representada por verbos[^1].

<details>

<summary>Tipos de atributos</summary>

* **Simples**: São indivisíveis, como o CPF de uma pessoa.
* **Composto**: Aquele que possui ou pode ser dividido por outros atributos, como Endereço possui Cidade, Estado, CEP, etc.
* **Multivalorado**: Possui N valores associados, como telefone.
* **Derivado**: Dependem de outro para existir, como Idade depende de Data de Nascimento.

***

**Atributo chave**: É utilizado para identificar de forma única uma entidade. Podemos usar o CPF que é único ou ter uma outra chave de nossa escolha.

</details>

<details>

<summary>Tipos de relacionamento</summary>

* **UM PARA UM (1:1)**: Pessoa `Jonas` se associa unicamente a um `Endereço de Cobrança`.
* **UM PARA MUITOS (1:N)**: Cliente `Jhow` se associa a vários `Pedidos`, porém, cada um desses pedidos só estão relacionados a ele.
* **MUITOS PARA MUITOS (N:N)**: Um `Pedido` pode conter vários `Produtos`. Um `Produto` pode estar em vários `Pedidos`.

</details>

## DER (Diagrama Entidade-Relacionamento)

Utilizado para <mark style="color:green;">desenhar</mark> de forma gráfica o que foi descrito no MER. Este é um <mark style="color:blue;">modelo conceitual</mark>, por isso, sua representação é simples e é associadas através de <mark style="color:purple;">verbos</mark> com losangos.

<figure><img src="../../../.gitbook/assets/exemplo der.png" alt=""><figcaption></figcaption></figure>

#### Identificação dos relacionamentos

O número mais próximo ao elemento, significa a quantia de vezes que o OUTRO ELEMENTO está associado à ele.

<figure><img src="../../../.gitbook/assets/relacionamento em der.png" alt=""><figcaption></figcaption></figure>

## Relacionamentos na prática

Na maioria dos casos os relacionamentos são sobre registros na tabela. Esses relacionamentos são laçados com `FOREIGN KEY`, onde uma chave de uma tabela está presente na outra. Chaves estrangeiras geram necessidade de usar `JOIN` nas buscas.

### 1 PARA 1

Cada registro em uma tabela corresponde a exatamente um registro em outra tabela. Cada cliente pode estar em apenas um registro do endereço de cobrança por conta da palavra `UNIQUE`.

```sql
CREATE TABLE clientes (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100)
);

CREATE TABLE endereco_cobranca (
    id INT PRIMARY KEY AUTO_INCREMENT,
    cliente_id INT UNIQUE, # Isso torna UM para UM
    endereco VARCHAR(255),
    FOREIGN KEY (cliente_id) REFERENCES clientes(id)
);
```

### 1 PARA MUITOS

Um registro em uma tabela pode estar relacionado a vários registros em outra tabela. É o mesmo exemplo sem a presença da chave única.

```sql
CREATE TABLE clientes (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100)
);

CREATE TABLE pedidos (
    id INT PRIMARY KEY AUTO_INCREMENT,
    cliente_id INT, # Pode ter quantos quiser
    data DATE,
    valor DECIMAL(10,2),
    FOREIGN KEY (cliente_id) REFERENCES clientes(id)
);
```

### MUITOS PARA MUITOS

Esse relacionamento **NÃO pode ser representado diretamente**. Criamos **uma tabela intermediária** para resolver isso.

```sql
CREATE TABLE pedidos (
    id INT PRIMARY KEY AUTO_INCREMENT,
    data DATE
);

CREATE TABLE produtos (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100),
    preco DECIMAL(10,2)
);

# Tabela intermediária
CREATE TABLE pedido_produto (
    pedido_id INT,
    produto_id INT,
    quantidade INT,
    PRIMARY KEY (pedido_id, produto_id),
    FOREIGN KEY (pedido_id) REFERENCES pedidos(id),
    FOREIGN KEY (produto_id) REFERENCES produtos(id)
);

# Inserção de dados
INSERT INTO pedidos (data) VALUES ('2024-02-04');
INSERT INTO produtos (nome, preco) VALUES ('Mouse Gamer', 150.00), ('Teclado Mecânico', 300.00);
INSERT INTO pedido_produto (pedido_id, produto_id, quantidade) VALUES (1, 1, 2), (1, 2, 1);


# Consulta
SELECT pedidos.id AS Pedido, produtos.nome AS Produto, pedido_produto.quantidade
FROM pedidos
JOIN pedido_produto ON pedidos.id = pedido_produto.pedido_id
JOIN produtos ON pedido_produto.produto_id = produtos.id;

```

[^1]: Pessoa X **trabalha** para a empresa Y.

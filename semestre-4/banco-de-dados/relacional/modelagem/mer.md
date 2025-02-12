# MER

<mark style="color:purple;">**MER = Modelo Entidade-Relacionamento.**</mark>

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
* **MUITOS PARA MUITOS (N:N)**: Um `Pedido` pode conter vários `Produtos`. Um `Produto` pode estar em vários `Pedidos`. Só pode ser feitas através de uma tabela intermediária.

Descrito com detalhes em [relacionamentos entre tabelas](relacionamentos.md).

</details>

[^1]: Pessoa X **trabalha** para a empresa Y.

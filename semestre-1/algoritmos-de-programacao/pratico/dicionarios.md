# Dicionários

Um dicionário é uma espécie de uma coleção de dados baseado em <mark style="color:blue;">chave valor</mark> com elementos armazenados de forma não ordenada. Tanto os valores quanto as chaves (que funcionam como índices) aceitam qualquer tipo de entrada. Dicionários são declarados com chaves, que são <mark style="color:orange;">**únicas e imutáveis**</mark>:

```python
# Dois jeitos iguais, dois elementos
tabela_preco = {'cadeira' : 235.20 , 'mesa' : 400}
tabela_preco = dict(cadeira=235.20, mesa=400)
```

## Resgate de itens

Dentro de um dicionário podemos resgatar qualquer dos três elementos que ele possui, seja seus itens (composto por uma chave e um valor), apenas a chave ou apenas o valor. Podemos procurar por algo específico ou retornar tudo que foi encontrado.

> A função len(dicionario) também funciona para resgatar o tamanho do dicionário criado.

### Retornar o valor

Existem diversas formas de resgatar itens.

* Atribuindo a chave do dicionário a uma variável:
  * `valor = dicionario["chave"]`
* Usando o método get():
  * `valor = dicionario.get("chave")`
  * `valor = dicionario.get("chave", "valor se não encontrado")`
* Resgatar tudo o que é possível:
  * `dicionario.items()` = vai mostrar todos os itens do dicionário
  * `dicionario.keys()` = vai mostrar todas, e apenas, as chaves do dicionário
  * `dicionario.values()` = vai mostrar todos, e apenas, os valores de cada chave do dicionário

### Listas dentro de dicionários

O dicionário permite a inserção de qualquer tipo de dado, isto é, também é permitido que uma chave <mark style="color:blue;">armazenene uma lista</mark>. Ao adicionar uma lista em uma chave de dicionário, sua representação fica similar a isto:

<figure><img src="../../../.gitbook/assets/lista dentro de dicionários em python.png" alt=""><figcaption></figcaption></figure>

Como listas não possui chaves e sim índices, o acesso de cada elemento da lista vai ser como se fosse um vetor dentro de vetor, especificando <mark style="color:purple;">primeiro a chave e depois o índice</mark>, desta forma:

* Primeiro elemento: `Estoque['cadeira'][0]`
* Segundo elemento: `Estoque['cadeira'][1]`

### Verificação se a chave existe

Com um dicionário criado, podemos verificar se uma chave existe. Ela pode ser útil para criar condições e lógicas baseadas nestas condições, veja por exemplo um código que imprime o valor da chave, apenas se ela existe:

```python
dicionario = dict(primeiro=1, segundo=2, terceiro=3)

if 'primeiro' in dicionario:
    print("Foi adicionado a primeira posição.")

    # Se primeiro existe, vamos resgatar seu valor
    valor_primeiro = dicionario["primeiro"]
    print(valor_primeiro)

if 'segundo' not in dicionario:
    print("A segunda posição está faltando!")
```

## Criação e manipulação

Vimos acima que o dicionário pode ser declarado com os seus itens dentro de chaves ou com a função `dict()`. Veja como manipular ou criar mais dados.

### Manipular valor que está na chave (ou criar)

Para mudar o valor que está dentro de uma chave, podemos apenas usar o método de atribuição. Neste caso, <mark style="color:orange;">se a chave não existir será criado</mark> uma com o valor colocado, por exemplo:

```python
dicionario["quantidade"] = 3000
```

Se a chave "quantidade" já existir no dicionário, o valor dela será alterado para 3000. Caso ela não exista, será criado uma no final do dicionário com esse valor.

### Exclusão de elementos

* Se queremos apenas remover uma chave específica, usamos:
  * `del dicionario["chave"]`
* Se queremos remover a chave e saber qual foi o valor removido, podemos usar o método pop(), o mesmo utilizado em listas:
  * `valor_removido = dicionario.pop["chave"]`

### Criar dicionário usando listas/dicionários

Podemos usar os elementos de um outro dicionário ou uma lista para <mark style="color:purple;">servir como chaves</mark> para um novo dicionário. Veja por exemplo:

#### A partir de outro dicionário

```python
seq = {'pos_um': 1,'pos_dois': 2,'pos_tres': 3,'pos_quatro': 4}
novo = {}
novo = novo.fromkeys(seq)
# {pos_um: None, pos_dois: None, pos_tres: None, pos_quatro: None}

novo = novo.fromkeys(seq, 10)
# {pos_um: 10, pos_dois: 10, pos_tres: 10, pos_quatro: 10}
```

#### A partir de listas

```python
lista_moveis = ['mesa', 'sofá', 'cadeira', 'lustre']
est = {}

# As chaves serão cada elemento da lista, os valores são uma OUTRA lista que contém
# dois valores: zero e zero
est = Est.fromkeys(Lista, [0,0])
# Est = {'mesa': [0,0], 'sofá': [0,0], 'cadeira': [0,0], 'lustre': [0,0]}


# Modificar elementos
est['mesa'][0] = [200]
est['mesa'][1] = [85]
# Est = {'mesa': [200,85], 'sofá': [0,0], 'cadeira': [0,0], 'lustre': [0,0]}
```

### Adicionar elementos pelo setDefault(key)

Em vez da atribuição, podemos usar o método `dicionario.setdefault('poltrona')` que vai adicionar um novo elemento no dicionário com chave igual a "poltrona" e o valor _None_.

```python
# Pegando o dicionário anterior
est = {
    'mesa': [200,85],
    'sofá': [0,0],
    'cadeira': [0,0],
    'lustre': [0,0],
    'poltrona': None # Novo
}
```

## Percorrer elementos

Como vistos em [repetições](repeticoes.md), a variável que percorre a sequência em um `for` assume o valor atual dela. Como visto acima, quando usamos os métodos `keys()` ou `values()` ou `items()` estamos resgatando uma sequência com todos os valores possíveis. Portanto, usando um for nesta sequência, conseguimos percorrer todos os elementos que queremos.

```python
for produto in dicionario.keys():
    print(f"Produto: {produto}")
    # Aqui vai imprimir/percorres as chaves = keys()
    
for preco in dicionario.values():
    print(f"Produto: {preco}")
    # Aqui vai imprimir/percorrer o valor de cada chave = values()
    
# produto vai assumir a chave
# preco vai assumir o valor
for produto, preco in dicionario.items():
    print(f"Produto: {produto} e Preço: {preco}")
    # Aqui vai imprimir/percorrer os dois = items()
    # 
    # Produto: pos_um e Preço: 1
    # Produto: pos_dois e Preço: 2
    # Produto: pos_tres e Preço: 3
    # Produto: pos_quatro e Preço: 4
```

## Operações com dois dicionários

Para implementar um dicionário ao final do outro, podemos usar isoladamente `dicionario1.update(dicionario2)`, sendo o dicionário 2 sendo acrescentado ao final do 1.

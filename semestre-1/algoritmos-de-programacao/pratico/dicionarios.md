# Dicionários

Um dicionário é uma espécie de uma coleção de dados baseado em <mark style="color:blue;">chave valor</mark> com elementos armazenados de forma não ordenada. Tanto os valores quanto as chaves (que funcionam como índices) aceitam qualquer tipo de entrada. Dicionários são declarados com chaves:

```python
# Dois jeitos iguais, dois elementos
tabela_preco = {'cadeira' : 235.20 , 'mesa' : 400}
tabela_preco = dict(cadeira=235.20, mesa=400)
```

As chaves são únicas e imutáveis.

## Acessar os itens

Esse acesso aos itens funciona tanto na hora de <mark style="color:green;">manipular os dados</mark> quanto <mark style="color:green;">resgatar</mark>, pode usar os mesmos métodos para ambas funções. Vamos na linha `5` em que podemos adicionar itens ao dicionário desta forma simples caso a chave não exista ainda. O dicionário permite a inserção de qualquer tipo de dado, isto é, também é permitido que uma chave <mark style="color:blue;">armazenene uma lista</mark>.

<pre class="language-python"><code class="lang-python"># Pela chave
valor = dicionario["chave"]     # Forma 1
valor = dicionario.get("chave") # Forma 2 (retorna none se não existir)

<strong>dicionario["chave"] = 3000 # Aqui, se essa chave ainda não existe, isso será
</strong><strong>                           # adicionado ao dicionário
</strong>
# Mostrar tudo
dicionario.items()  # Mostra todos os itens
dicionario.keys()   # Mostra todas as chaves
dicionario.values() # Mostra todos os valores

# Método get()
valor = dicionario.get("chave", "Não existe") # Mostra a string "Não existe" se o
                                              # valor não foi encontrado
</code></pre>

> A função len(dicionario) também funciona para resgatar o tamanho do dicionário criado.

#### Listas em uma chave dicionário

Ao adicionar uma lista em uma chave de dicionário, sua representação fica similar a isto:

<figure><img src="../../../.gitbook/assets/lista dentro de dicionários em python.png" alt=""><figcaption></figcaption></figure>

Como listas não possui chaves e sim índices, o acesso de cada elemento da lista vai ser como se fosse um vetor dentro de vetor, especificando primeiro a chave e depois o índice, desta forma:

* Primeiro elemento: `Estoque['cadeira'][0]`
* Segundo elemento: `Estoque['cadeira'][1]`

## Excluir elementos

del dicionario\["chave"]

valor\_removido = dicionario.pop\["chave"]



## Percorrer elementos

```python
for produto in dicionario.keys():
    print(f"Produto: {produto}")
    # Aqui vai imprimir/percorres as chaves = keys()
    
for preco in dicionario.values():
    print(f"Produto: {preco}")
    # Aqui vai imprimir/percorrer o valor de cada chave = values()
    
for produto, preco in dicionario.items():
    print(f"Produto: {preco} e Preço: {preco}")
    # Aqui vai imprimir/percorrer os dois = items()
```

## Unir dicionários

dicionario1.update(dicionario2) - coloca o dicionario 2 no final do 1

## Verificação se há chave

dicionario = {...}

'sofa' in dicionario

'sofa' not in dicionario

## Criar dicionário usando listas/dicionários

A partir de outro dicionário

```python
seq = {1,2,3,4,5}
novo = {}
novo = novo.fromkeys(seq)
# {1: None, 2: None, 3: None, 4: None, 5: None}

novo = novo.fromkeys(seq, 10)
# {1: 10, 2: 10, 3: 10, 4: 10, 5: 10}
```

a partir de listas

```python
Lista = ['mesa', 'sofá', 'cadeira', 'lustre']
Est = {}

# As chaves serão cada elemento da lista, os valores são uma OUTRA lista que contém
# dois valores: zero e zero
Est = Est.fromkeys(Lista, [0,0])
# Est = {'mesa': [0,0], 'sofá': [0,0], 'cadeira': [0,0], 'lustre': [0,0]}


# Modificar elementos
Est['mesa'][0] = [200]
Est['mesa'][1] = [85]
# Est = {'mesa': [200,85], 'sofá': [0,0], 'cadeira': [0,0], 'lustre': [0,0]}
```

## Adicionar elementos pelo setDefault(key)

`dicionario.setdefault('poltrona')` vai adicionar um novo elemento no dicionário com chave igual a "poltrona" e o valor None.

```
Est = {
    'mesa': [200,85],
    'sofá': [0,0],
    'cadeira': [0,0],
    'lustre': [0,0],
    'poltrona': None # Novo
}
```

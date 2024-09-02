# Dicionários

Um dicionário é uma espécie de uma coleção de dados baseado em <mark style="color:blue;">chave valor</mark> com elementos armazenados de forma não ordenada. Tanto os valores quanto as chaves (que funcionam como índices) aceitam qualquer tipo de entrada. Dicionários são declarados com chaves:

```python
# Dois jeitos iguais, dois elementos
tabela_preco = {'cadeira' : 235.20 , 'mesa' : 400}
tabela_preco = dict(cadeira=235.20, mesa=400)
```

As chaves são únicas e imutáveis.

## Acessar os itens

Esse acesso aos itens funciona tanto na hora de <mark style="color:green;">manipular os dados</mark> quanto resgatar, pode usar os mesmos métodos para ambas funções.

```python
# Pela chave
valor = dicionario["chave"]
dicionario["chave"] = 3000 # Aqui, se essa chave ainda não existe, isso será
                           # adicionado ao dicionário

# Mostrar tudo
dicionario.items()  # Mostra todos os itens
dicionario.keys()   # Mostra todas as chaves
dicionario.values() # Mostra todos os valores
```



## Excluir elementos

del dicionario\["chave"]

valor\_removido = dicionario.pop\["chave"]


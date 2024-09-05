# Funções

É um trecho de código que possui uma responsabilidade específica, possuem um nome definido (usando o [padrão](../caracteristicas-do-python/#padrao-de-escrita) snake\_case) e que são executados apenas quando chamados. Eles são importantes para estruturar programas e maximizar o reuso.

A criação de uma função utiliza-se a palavra `def` que simboliza definir uma função, usando essa sintaxe com dois pontos no final:

```python
def nome_funcao(arg1, arg2, ..., argN): #
    total = arg1 + arg2
    return total
    
print(nome_funcao())
```

Se a função não retorna nada, o valor de retorno dela será considerado como None, caso atribuído a alguma variável. O restante, as funções funcionam como em todas as outras linguagens de programação, a respeito do uso de suas variáveis nos parâmetros, forma de execução, retornos, necessita passar todos os parâmetros exigidos no construtor (exceto default), etc.

## Parâmetro default

Na definição de uma função que possui parâmetros, é possível atribuir a eles um valor padrão que será assumido se não for passado durante a chamada de uma função pelo construtor, por exemplo:

```python
def saudacao(nome, mensagem="Olá"):
    print(f"{mensagem}, {nome}!")
    
saudacao("terráqueos")
# -> Olá, terráqueos!

saudacao("Brasil", "Bom dia")
# -> Bom dia, Brasil!
```

* Caso 1: Como o valor da "mensagem" não foi passada na hora de chamar a função `saudacao`, ele assumiu seu valor padrão definido na primeira linha.
* Caso 2: Foi fornecido os dois então o valor default não será usado e sim o parâmetro passado, "Bom dia".

#### Possível erro

Quando temos mais casos em parâmetros, devemos estabelecer a ordem correta deles. A ideia é sempre deixar os parâmetros default por último pois se eles ficarem em primeiro lugar, teoricamente, serão obrigatórios serem chamados.

```python
# Correto
def func(a, b=2, c=3):
    pass
    
# Errado
def func(a=1, b, c=3):
    pass
    
# Errado
def func(a=1, b, c):
    pass
```

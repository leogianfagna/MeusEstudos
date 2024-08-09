# Números e operadores

## Características de operadores

#### Retornar resultado inteiro em divisão

O símbolo `/`, que representa a operação de divisão, embora o dividendo e divisor sejam inteiros e múltiplos, produz um resultado real. Para produzir um resultado inteiro, mesmo que eles não sejam múltiplos, é preciso usar duas barras `//`.

```python
# Comandos em um console

6 / 2 # Retorna 3.0
6 // 2 # Retorna 3
```

#### Potência

Muito comum usar métodos para realizar potências em outras linguagens como `Math.pow()`, em Python usaremos o operador `**`.

```python
lado = 5
area = lado ** 2
```

#### Operações com strings

Definidas como `str`, o Python tem algumas facilidades para trabalhar com strings com métodos nativos. O conceito de string em Python é o mesmo que conhecemos em outras linguagens, também suportando concatenação: `string1 + string2`

| Operador | Funcionalidade                                                   |
| -------- | ---------------------------------------------------------------- |
| \*       | Duplicar a string                                                |
| len()    | Retornar o tamanho da string                                     |
| in       | Conferir se uma string está contida em outra (true ou false)     |
| not      | Conferir se uma string não está contida em outra (true ou false) |

```python
minhaString = "Testando qualquer coisa"
segundaString = "Testando"

stringDuplicada = segundaString * 3
tamanhoString = len(minhaString)
resultadoContem = segundaString in minhaString
resultadoNaoContem = segundaString not in minhaString

print(stringDuplicada) # TestandoTestandoTestando
print(tamanhoString) # 23
print(resultadoContem) # True
print(resultadoNaoContem) # False
```

## Números

#### Complexos

É possível trabalhar com números complexos e fazer contas com eles, por exemplo:

```python
2 + 3j # Rertorna (2+3j)
```

```python
(2 + 3j) + (2.5 + 5j)  # Retorna (4.5+8j)
(2 + 3j) - (5 + 5j)    # Retorna (-3-2j)
```

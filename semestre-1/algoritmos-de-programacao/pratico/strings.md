# Strings

Strings são uma cadeia/conjunto de caracteres separadas entre aspas, simples ou dupla. A impressão de aspas dentro de uma string acontece usando uma aspas diferente da que abre e fecha na definição, por exemplo:

```python
string = "Olá! Aqui vai uma 'palavra' entre aspas"
string = 'Olá! Aqui vai uma "palavra" entre aspas'
```

## Índices

Uma string possui um formato semelhante a um vetor em que <mark style="color:blue;">cada caractere tem um índice</mark>. Por exemplo:

```python
string = "Bom dia!"
print(string[1])
```

### Tamanho do índice/string

Assim como todas as linguagens possuem, da sua maneira, aqui temos a função `len()` para descobrir o tamanho total de uma string, da seguinte forma:

```python
string = "Um pequeno texto"
tamanhoString = len(string)
```

### Fatia de um índice

Podemos pegar uma determinada cadeira de cadeia de caracteres da string, por exemplo da posição X até Y, pensando em uma fatia. Utilizamos os caracteres `[]` para definir o índice normalmente e, neste caso, também utilizaremos os colchetes com uma indentação da seguinte maneira:

```python
string = "Um pequeno texto"

fatia = string[2:6] # Inclue a 2 mas não inclue a 6
fatiaSemUltimosCaracteres = string[0:len(string) - 4]
fatiaPartirDoInicio = string[:7]
fatiaDoMeioAteOFinal = string[7:]
```

## Características

### Imutabilidade

<mark style="color:orange;">Strings são imutáveis</mark>, portanto, não podemos trocar um determinado valor do índice por outro através de atribuição, por exemplo `string[3] = "K"`. Contudo, <mark style="color:orange;">listas podem ser mutáveis</mark> então essa alteração pode ser facilmente operada convertendo a string para uma lista, desta forma:

```python
# String original
minha_string = "Olá Mundo"

# Converter a string para uma lista
lista_caracteres = list(minha_string)

# Modificar o caractere na posição desejada
lista_caracteres[4] = 'm'

# Converter a lista de volta para uma string
minha_string_modificada = ''.join(lista_caracteres)

print(minha_string_modificada)
```

Lembrando que as listas são conjuntos de dados e não de caracteres. Portanto, é necessário a conversão para string novamente para conseguir funcionar corretamente.



## Operações

### Contar aparições

Podemos contar quantas vezes tal caractere aparece na string usando os mesmos conceitos de outras linguagens de programação, percorrendo cada índice:

```python
i = 0
string = "!!!!!aaaaaaa!!"
contagem = 0

while i < len(string):
    
    # Quantas vezes aparece o exclamação?
    if string[i] == "!":
        contagem+=1

    i+=1

print(contagem)
```

### Concatenar ou repetir

<table><thead><tr><th width="152">Função</th><th width="121">Operador</th><th width="309">Resultado</th><th>Uso</th></tr></thead><tbody><tr><td>Concatenar</td><td>+</td><td>Junta str1 e str2 em uma única string</td><td><code>str1 + str2</code></td></tr><tr><td>Repetir</td><td>*</td><td>Repete n vezes a string</td><td><code>3 * str1</code></td></tr></tbody></table>

### String aparece em outra

Um <mark style="color:purple;">operador</mark> `in` que vai retornar um boolean, que normalmente será utilizado em lógicas de condições. Usando de forma bem simples, funciona assim:

```python
str1 = "a menina é bonita"
str2 = "menina"

checar = str2 in str1
```

### Encontrar posição

Um <mark style="color:purple;">método</mark> `find()` que vai retornar em que posição do índice uma substring se inicia na outra. Poderíamos fazer uma lógica repetitiva para encontrar algum caractere, mas esse método vai ajudar a encontrar strings dentro de outras.

```python
str1 = "a menina é bonita"
str2 = "menina"

checar = str1.find("bonita") # ou str2
print(checar) # RETORNA 11
```

Teria o retorno `-1` caso não encontrasse, podendo também substituir o método anterior desta forma, onde a lógica condicional confere se o resultado do método é diferente de `-1`.

### Ocorrências em uma string

Um <mark style="color:purple;">método</mark> `count()` que vai retornar quantas vezes uma string se repete em outra. De forma muito simples e similar a anterior, podemos usar `str1.count("abc")`.

### Substituir

Um <mark style="color:purple;">método</mark> `replace()` que substituir todas as ocorrências desejadas por uma outra string. Bem comum e utilizada, esse método recebe dois parâmetros: o que encontrar e o que substituir, da seguinte forma:

```python
str1 = "a menina é bonita"
caractereSubstituicao = "-"

# Substitui espaços por -
novaString = str1.replace(" ", caractereSubstituicao)
```

### Outros métodos

A lista de métodos é muito grande com diversos métodos, eles estão documentados no site oficial[https://docs.python.org/3/library/stdtypes.html](https://docs.python.org/3/library/stdtypes.html) na seção "String Methods", ou nessa documentação em portugues [https://docs.python.org/pt-br/3.6/library/stdtypes.html#text-sequence-type-str](https://docs.python.org/pt-br/3.6/library/stdtypes.html#text-sequence-type-str).

## Percorrer

O `for` usado em strings significa percorrê-la usando o seu **índice**. Um exemplo básico disto está abaixo, demonstrando e printando cada elemento usando essa sequência repetitiva.

```python
string = "Alguma string qualquer"

for i in range(len(string)):
    print(string[i])
```

Dentro dessa linha de raciocínio, podemos incluir condições usando os índices, criando o famoso exemplo de substituir todo caractere "a" por um asterisco ou algo do tipo:

```python
for k in range(len(frase)):
    if frase[k] != 'a':
        print({frase[k]}) # Printa o caractere verdadeiro
    else:
        print("*") # Printa um asterisco no lugar
```

## Exercícios

Exercícios básicos usando lógicas repetitivas e métodos foram feitos [aqui](https://github.com/leogianfagna/MeusEstudos/blob/main/arquivos/semestre-1/python/exercicios/strings-basico.py).

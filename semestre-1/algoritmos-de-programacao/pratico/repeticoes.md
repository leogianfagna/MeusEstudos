# Repetições

Uma estrutura de repetição é utilizada quando um trecho de um algoritmo precisa ser executado diversas vezes, mais conhecido como `while` e `for`.

## While

Executa sempre em que a condição seguida por ele for verdadeira.&#x20;

```python
x = 1

while x <= 5:
    print(x)
    x = x + 1 
```

Depois da execução do while, é possível acrescentar uma camada <mark style="color:green;">`else`</mark> que executa logo após a saída da condição:

```python
x = 1

while x <= 5:
    print(x)
    x = x + 1 
else:
    print(f"A variável x agora vale {x}") # 6

print("Fim do programa. X ainda vale 6")
```

### Do-while

Em Python, a estrutura de loop `do while` que existe em outras linguagens não é suportada diretamente. No entanto, podemos criar um comportamento semelhante usando um loop `while` com uma condição que sempre seja verdadeira na primeira iteração, dessa forma:

```python
while True: # Sempre será verdadeiro
    print("Executando o loop")
    
    # Condição para sair do loop
    if not some_condition:
        break
```

Em um exemplo prático, temos:

```python
x = 10

while True:
    x = x + 1
    print(x)

    if x > 5:
        break
```

Nesse exemplo, vai entrar pelo menos uma vez nesse while por ele já ser declarado como true, então a variável que valia 10 agora vale 11. O comando `break` em Python serve para <mark style="color:red;">sair do loop mais interno</mark> em que ele está localizado, por isso, podemos utilizá-lo para fazer essa condição e sair do while.

## For

Sequência imutável de números inteiros de um valor inicial até um número final (não incluído), com passo variado. Basicamente, funciona da mesma forma que conhecemos em outras linguagens. Segue essa sinxate:

> `for elemento in lista/range`
>
> * Elemento é o contador
> * Lista é os valores que serão percorridos
> * Range é a faixa de dados suportada

### Range

A faixa de dados através do método range(), que é flexível e customizado (o final nunca é incluído):

| Uso           | Descrição                                         | Resultado                    |
| ------------- | ------------------------------------------------- | ---------------------------- |
| range(10)     | Representa o **FINAL** iniciando em zero          | 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 |
| range(5, 10)  | representa o **INÍCIO** e **FINAL**               | 5, 6, 7, 8, 9                |
| range(0,10,2) | representa o **INÍCIO** e **FINAL** e o **PASSO** | 0, 2, 4, 6, 8                |

Em baixo, temos um exemplo básico de range onde o valor máximo é decidido através de uma variável chamada `rangeMaxima`. No segundo for, podemos ver que qualquer outro método é permitido dentro e no caso fizemos uma conta matemática para demonstrar que vai começar apenas 20 unidades abaixo da range máxima.

```python
x = 0
rangeMaxima = int(input("Até qual número? "))

for x in range(rangeMaxima):
    print(x)
    
for x in range((rangeMaxima - 20), rangeMaxima):
    print(x)
```

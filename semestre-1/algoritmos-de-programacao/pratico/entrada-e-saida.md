# Entrada e saída

## Saída

É o que aparece na tela.

### Print

Saída são representadas por qualquer exibição na tela, dentre a mais comum e famosa, a função <mark style="color:red;">`print()`</mark>. Existem <mark style="color:green;">várias formas</mark> de usar este método, porém o mais padrão e comum é através das _<mark style="color:blue;">f-strings</mark>_ quando queremos inserir variáveis juntos, que são muito flexisíveis e bem mais otimizadas do que alguma que utilize concatenação. Eis o seu uso:

```python
ingredienteUm = "feijão"
ingredienteDois = "farofa"

print(f"arroz com {ingredienteUm} e {ingredienteDois}")

numeroInteiro = 31
numeroQuebrado = 5.490192
numeroPorcentagem = 0.11

print(f"Ambos inteiros {numeroInteiro} e {numeroQuebrado:.0f}")
print(f"Numero em porcentagem {numeroPorcentagem:.2%}")
```

Isso mostra que existem diversas opções de formatação de números (assim como também tem nos outros tipos de print), mas que vai muito além de apenas formatar casas decimais, como porcentagem, separar por milhares, zeros à esquerda, etc.

O método <mark style="color:red;">`print()`</mark> possui dois parâmetros que podem ser adicionados dentro dele: o `sep` e o `end`. Eles indicam, respecitivamente, o que estará entre as variáveis colocadas e o que estará no final do print. No caso do end, <mark style="color:orange;">por padrão desse método</mark>, ele é adicionado um `\n` para pular uma linha. Portanto, se especificarmos o nosso end, podemos colocar de outra forma para ele não pular, por exemplo:

```python
string = "Algo legal"

print(f"String: {string}", end = '!!!\n')
print(f"String sem pular linha depois: {string}", end = '')
print(f". Continuando...")

# String: Algo legal!!!
# String sem pular linha depois: Algo legal. Continuando...
```

#### Largura mínima

Quando depararmos na hora de printar uma variável e encontrarmos esse exemplo `{variavel:20}`, estamos falando de <mark style="color:blue;">largura mínima</mark>. Basicamente, define uma largura mínima na hora de mostrar o conteúdo dessa variável. Supondo que `A` seja uma string e tenha menos de 20 caracteres, isso vai fazer que os caracteres que faltam serão <mark style="color:green;">preenchidos com espaços vazios</mark> à esquerda.

#### Outras formas de print são:

```python
ingredienteUm = "feijão"
ingredienteDois = "farofa"

print("arroz com " + ingredienteUm + " e " + ingredienteDois)
print("arroz com", ingredienteUm, "e", ingredienteDois)
print(f"arroz com {ingredienteUm} e {ingredienteDois}")
print("arroz com {} e {}".format(ingredienteUm, ingredienteDois))
```

A concatenação é válida apenas para strings, portanto, neste caso de saída precisamos usar o método <mark style="color:red;">`str()`</mark> para transformar um outro tipo que não seja em string e conseguir sair corretamente sem erros, exemplo:

```python
numero = 20

print("O número é:", numero) # Não é concatenação
print("O número é: " + str(numero))
```

## Entrada

Os comandos de entrada são representados por uma <mark style="color:green;">inserção de dados</mark>, o que pode vir de forma externa, como um teclado.

### Input

É um comando de entrada que espera uma resposta do cliente final usando seu teclado e uma resposta.&#x20;

```python
print("Esperando dados:\n")

receberString = input("Digite uma string: ")
receberNumero = float(input("Digite um número: ")) + 10
# Processo de Casting para receber o número em float
# Todo imput é recebido em STRING
# Tentar operar com esse resultado sem usar casting retorna erro

print(f"String recebida: {receberString}")
print(f"Número recebido e somado: {receberNumero}")
```


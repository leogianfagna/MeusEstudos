# Listas

Listas são arranjos sequenciais (ou coleção) de informações, servem para armazenar várias informações de forma simplificada. Essas são organizadas de <mark style="color:blue;">forma linear</mark> e possuem um <mark style="color:blue;">identificador</mark> único.

Como dito em [strings](strings.md), as listas são <mark style="color:green;">mutáveis</mark> e também acessadas através de um índice (por isso a técnica de transformar strings em listas na hora de alterar um índice específico). Por conta dessa mutabilidade, podem inserir e retirar itens de forma fácil.

<figure><img src="../../../.gitbook/assets/lista python.png" alt=""><figcaption></figcaption></figure>

Uma lista é muito parecido com o <mark style="color:orange;">vetor</mark>, mas ainda possui diferenças. Elas são mais flexíveis já que vetores <mark style="color:blue;">não possuem tamanho fixo</mark> e podem guardar <mark style="color:blue;">dados de diferentes tipos</mark>, diferentemente dos vetores. Sua sintaxe é a mesma, usando colchetes para simbolizar a posição do índice. Veja a possibilidade de possuir <mark style="color:purple;">uma lista dentro de outra</mark>.

```python
listaMaluca = ["Ferrari", 20, 10.5, 0, ["Valor1", "Valor2"], "mercado"]
listaVazia = []

elementoDois = listaMaluca[1]
soma = listaMaluca[3] + 20
```

## Verificação

Encontrar ou verificar dados de uma lista.

<table><thead><tr><th>Objetivo</th><th width="205">Método</th><th>Uso</th></tr></thead><tbody><tr><td>Quantidade de elementos presentes em uma lista</td><td>len(lista)</td><td><code>for in range(len(lista))</code></td></tr><tr><td>Contar quantas vezes um certo elemento aparece dentro de uma lista</td><td>lista.count("elemento")</td><td><code>quantidadeProntos = lista.count("pronto")</code></td></tr><tr><td>Retorna o índice da primeira ocorrência de "elemento"</td><td>lista.index("elemento")</td><td><code>pos = lista.index("pronto")</code></td></tr></tbody></table>

## Manipulação

A manipulação de dados de uma lista acontece de forma simples.

### Alteração de um valor

Baseado na posição de um índice, basta atribuir o valor como se fosse uma variável, desta forma:

```python
lista = ["esperando", "execução", "parado", "finalizado"]
lista[3] = "pronto"
```

### Adição de itens

Usando o método `append()` podemos adicionar um novo item ao **final** da lista e `insert()` podemos definir a posição em que o novo item vai entrar:

```python
lista = ["esperando", "execução", "parado", "finalizado"]

lista.append("atrasado")
lista.insert(2, "falho")
```

### Cópia identica de uma lista

Usando o método `copy()`, pode-se criar uma lista idêntica a outra. Se não utilizarmos este método e ao invés disso tentar atribuir a outra variável, teremos apenas a nova variável apontando ao mesmo objeto, mas não duas listas:

```python
lista = ["esperando", "execução", "parado", "finalizado"]
outraLista = lista.copy()

tentativaLista = lista # Não vai criar uma nova lista e apenas apontar
```

### Ligar duas listas

Usando o método `extend()` junto com o nome de uma outra lista como parâmetro, inserimos esta outra lista no final da primeira, concatenando duas listas em uma só:

```python
listaUm = [10, 20]
listaDois = [5, 15]

listaUm.extend(listaDois) # Lista dois irá para o final
```

### Limpar uma lista

Usando o método `clear()` limpamos a lista por completo, contudo, por facilidade você também pode atribuir uma lista vazia que o resultado será o mesmo:

```python
lista = ["esperando", "execução", "parado", "finalizado"]

lista.clear()
lista = []
```

### Remover elementos

Usando o método `remove()` podemos remover um elemento no índice indicado. Com mais recursos, podemos usar o método `pop()` onde ele retorna qual foi o elemento removido, portanto, podemos combinar ele com uma variável para printar o que foi removido:

```python
lista = ["esperando", "execução", "parado", "finalizado"]

lista.remove(1)

itemRemovido = lista.pop(1)
print(itemRemovido)
```

## Reorganizar

Podemos reorganizar as listas de uma forma diferente, de dois jeitos:

* Ordenar os elementos da lista usando `lista.sort()`
* Inverter a ordem dos elementos usando `list.reverse()`

## Listas dentro de listas

Como apareceu acima, podemos colocar listas dentro de listas sem limitações. Se uma lista pode estar dentro de outra, isso significa também que pode haver uma terceira lista dentro de todas e assim infinitamente.

Vamos criar um exemplo de um cadastro de pessoas, onde possui vários dados e vamos supor que todas as pessoas devem estar em uma única lista. Para organizar isso de forma clara, cada indivíduo será um elemento novo da lista principal. Basicamente:

* Temos uma lista principal onde cada elemento é uma pessoa
* Cada pessoa (elemento) também será uma lista, isso significa que pessoa\[0], pessoa\[1] e pessoa\[n] é uma lista com as informações da pessoa
  * Cada dado da lista da pessoa é um novo elemento desta lista
  * Dentro de cada lista individual, teremos ainda uma lista que informa a idade de cada filho

<figure><img src="../../../.gitbook/assets/esquema de listas dentro de listas.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/tutorial lista 1.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/tutorial lista 2.png" alt=""><figcaption></figcaption></figure>

Para isso funcionar, primeiro coletamos os dados (não há verificação de dado correto neste código). Depois disso:

1. Formamos a lista <mark style="color:purple;">filhos</mark> com `append()` em cada filho fornecido
2. Formamos a lista <mark style="color:purple;">dados</mark> com `append()` em cada variável fornecida e depois `append()` da lista filhos para incluí-la
3. Inserimos cada lista dados criada com `append()` na lista <mark style="color:purple;">pessoas</mark>. Isso está dentro da repetição, portanto, quando usamos `dados = []` no início, esvaziamos esta lista.

### Impressão de dados inferiores

Para imprimir um dado de uma lista que está dentro de uma lista, basta apenas seguir essa sintaxe:

```python
print(listaPai[1][3])
```

Veja que foi usado **números aleatórios** para identificar este índice. Se precisa imprimir algo que está na terceira lista, basta acrescentar mais um vetor e assim sucessivamente.&#x20;

Se as listas são mutáveis e podemos fazer essa indentação para procurar dados em listas dentro de listas, também podemos fazer a mesma estratégia para manipular dados se queremos.
